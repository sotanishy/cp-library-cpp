#pragma once
#include <algorithm>
#include <deque>
#include <utility>
#include <vector>
#include "geometry.hpp"
#include "intersection.hpp"

T area(const Polygon& poly) {
    const int n = poly.size();
    T res = 0;
    for (int i = 0; i < n; ++i) {
        res += cross(poly[i], poly[(i + 1) % n]);
    }
    return std::abs(res) / T(2);
}

bool is_convex(const Polygon& poly) {
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        if (lt(cross(poly[(i+1)%n] - poly[i], poly[(i+2)%n] - poly[(i+1)%n]), 0)) {
            return false;
        }
    }
    return true;
}

Polygon convex_cut(const Polygon& poly, const Line& l) {
    const int n = poly.size();
    Polygon res;
    for (int i = 0; i < n; ++i) {
        auto p = poly[i], q = poly[(i+1)%n];
        if (ccw(l.p1, l.p2, p) != -1) {
            if (res.empty() || !eq(res.back(), p)) {
                res.push_back(p);
            }
        }
        if (ccw(l.p1, l.p2, p) * ccw(l.p1, l.p2, q) < 0) {
            auto c = intersection(Line(p, q), l);
            if (res.empty() || !eq(res.back(), c)) {
                res.push_back(c);
            }
        }
    }
    return res;
}

Polygon halfplane_intersection(std::vector<std::pair<Vec, Vec>> hps) {
    using Hp = std::pair<Vec, Vec>;  // (normal vector, a point on the border)

    auto intersection = [&](const Hp& l1, const Hp& l2) -> Vec {
        auto d = l2.second - l1.second;
        Vec e(-l1.first.imag(), l1.first.real());
        return l1.second + (dot(d, l2.first) / cross(l1.first, l2.first)) * e;
    };

    // check if the halfplane h contains the point p
    auto contains = [&](const Hp& h, const Vec& p) -> bool {
        return dot(p - h.second, h.first) > 0;
    };

    constexpr T INF = 1e15;
    hps.emplace_back(Vec(1, 0), Vec(-INF, 0));  // -INF <= x
    hps.emplace_back(Vec(-1, 0), Vec(INF, 0));  // x <= INF
    hps.emplace_back(Vec(0, 1), Vec(0, -INF));  // -INF <= y
    hps.emplace_back(Vec(0, -1), Vec(0, INF));  // y <= INF

    std::sort(hps.begin(), hps.end(), [&](const auto& h1, const auto& h2) {
        return std::arg(h1.first) < std::arg(h2.first);
    });

    std::deque<Hp> dq;
    int len = 0;
    for (auto& hp : hps) {
        while (len > 1 && !contains(hp, intersection(dq[len-1], dq[len-2]))) {
            dq.pop_back();
            --len;
        }

        while (len > 1 && !contains(hp, intersection(dq[0], dq[1]))) {
            dq.pop_front();
            --len;
        }

        // parallel
        if (len > 0 && eq(cross(dq[len-1].first, hp.first), 0)) {
            // opposite
            if (lt(dot(dq[len-1].first, hp.first), 0)) {
                return {};
            }
            // same
            if (!contains(hp, dq[len-1].second)) {
                dq.pop_back();
                --len;
            } else continue;
        }

        dq.push_back(hp);
        ++len;
    }

    while (len > 2 && !contains(dq[0], intersection(dq[len-1], dq[len-2]))) {
        dq.pop_back();
        --len;
    }

    while (len > 2 && !contains(dq[len-1], intersection(dq[0], dq[1]))) {
        dq.pop_front();
        --len;
    }

    if (len < 3) return {};

    std::vector<Vec> poly(len);
    for (int i = 0; i < len - 1; ++i) {
        poly[i] = intersection(dq[i], dq[i+1]);
    }
    poly[len-1] = intersection(dq[len-1], dq[0]);
    return poly;
}
