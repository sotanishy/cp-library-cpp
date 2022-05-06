#pragma once
#include <queue>
#include <set>
#include <utility>
#include <vector>
#include "geometry.hpp"

std::vector<std::pair<int, int>> delaunay_diagram(std::vector<Vec> pts) {
    const int n = pts.size();
    constexpr T INF = 1e20;
    // stores delaunay edges
    std::vector<std::pair<int, int>> edges;
    // the sweep line moves from left to right
    // x coordinate of the sweepline
    static T sweepx;

    // check if all points are collinear
    bool ok = false;
    for (int i = 2; i < n; ++i) {
        if (ccw(pts[0], pts[1], pts[i]) != 0) {
            ok = true;
            break;
        }
    }
    // handle degenerate cases
    if (!ok) {
        // connect all points by a path
        std::vector<std::pair<Vec, int>> pi(n);
        for (int i = 0; i < n; ++i) pi[i] = {pts[i], i};
        std::sort(pi.begin(), pi.end(), [&](auto& p, auto& q) {
            return std::make_pair(p.first.real(), p.first.imag()) < std::make_pair(q.first.real(), q.first.imag());
        });
        for (int k = 0; k < n - 1; ++k) {
            edges.emplace_back(pi[k].second, pi[k + 1].second);
        }
        return edges;
    }

    // represents a parabola given by the focus p
    // and the focus q of the next parabola
    struct Parabola {
        Vec p;
        mutable Vec q;
        int i;
        mutable int id = 0;
        Parabola(const Vec& p, const Vec& q, int i) : p(p), q(q), i(i) {}

        T gety(T x) const {
            if (q.imag() == INF) return INF;
            x += eps;
            Vec m = (p + q) / T(2);
            Vec dir = rot(p - m, PI/2);
            T D = (x-p.real()) * (x-q.real());
            return m.imag() + ((m.real() - x) * dir.real() + std::sqrt(D) * std::abs(dir)) / dir.imag();
        }
        bool operator<(T y) const { return gety(sweepx) < y; }
        bool operator<(const Parabola& o) const { return gety(sweepx) < o.gety(sweepx); }
    };

    // maintains a list of parabola
    std::multiset<Parabola, std::less<>> beach;
    using iterator = decltype(beach)::iterator;

    // represents an event
    // id >= 0: point event
    // id < 0: vertex event
    struct Event {
        T x;
        int id;
        iterator it;
        Event(T x, int id, iterator it) : x(x), id(id), it(it) {}
        bool operator>(const Event& e) const { return x > e.x; }
    };

    // maintains a list of events
    std::priority_queue<Event, std::vector<Event>, std::greater<>> pq;
    // true if the i-th vertex event is still valid
    std::vector<bool> valid(1);

    int k = 1; // next id

    // create vertex events
    auto update = [&](const iterator& it) {
        if (it->i <= -1 || it == beach.begin()) return; // sentinels
        valid[it->id] = false;
        auto a = std::prev(it);
        // handle a vertex event that occurs
        // when 3 parabolas at (a->p, it->p, it->q) coincide
        if (eq(ccw(a->p, it->p, it->q), 0)) return;  // never coincide when collinear
        //create a new event
        it->id = k++;
        valid.push_back(true);
        Vec c = circumcenter(a->p, it->p, it->q);
        // coordinate of the vertex event
        T x = c.real() + std::abs(c - it->p);
        if (leq(sweepx, x) && leq(it->gety(x), a->gety(x))) {
            pq.emplace(x, -it->id, it);
        }
    };

    auto add_edge = [&](int i, int j) {
        if (i != -1 && j != -1) edges.emplace_back(i, j);
    };

    // rotate all points by a radian
    // so that x coordinates are distinct
    for (auto& p : pts) p = rot(p, 1);

    // sentinel
    beach.emplace(Vec(-INF, INF), Vec(-INF*2, INF), -1);

    // add all point events
    for (int i = 0; i < n; ++i) {
        pq.emplace(pts[i].real(), i, beach.end());
    }

    while (!pq.empty()) {
        auto e = pq.top(); pq.pop();
        sweepx = e.x;
        if (e.id >= 0) {
            // point event
            int i = e.id;
            auto p = pts[i];
            // (c) -> (c, p, c)
            auto c = beach.lower_bound(p.imag());
            auto b = beach.insert(c, Parabola(p, c->p, i));
            auto a = beach.insert(b, Parabola(c->p, p, c->i));
            add_edge(i, c->i);
            update(a); update(b); update(c);
        } else if (valid[-e.id]) {
            // vertex event
            // (a, e, b) -> (a, b)
            auto a = std::prev(e.it);
            auto b = std::next(e.it);
            beach.erase(e.it);
            a->q = b->p;
            add_edge(a->i, b->i);
            update(a); update(b);
        }
    }

    return edges;
}
