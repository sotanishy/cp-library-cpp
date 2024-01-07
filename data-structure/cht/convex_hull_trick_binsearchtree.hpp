#pragma once
#include <cassert>
#include <limits>
#include <set>
#include <utility>

template <typename T>
class ConvexHullTrick {
   public:
    void add(T a, T b) {
        a = -a, b = -b;
        auto m = lines.insert({a, b, 0});
        auto l = m, r = m;
        ++r;
        while (update(m, r)) {
            r = lines.erase(r);
        }
        if (l != lines.begin() && update(--l, m)) {
            m = lines.erase(m);
            update(l, m);
        }
        m = l;
        while (l != lines.begin() && (--l)->p >= m->p) {
            update(l, lines.erase(m));
            m = l;
        }
    }

    T get(T x) const {
        assert(!lines.empty());
        auto it = *lines.lower_bound(x);
        return -(it.a * x + it.b);
    }

   private:
    struct Line {
        mutable T a, b;    // ax + b
        mutable double p;  // intersection point with the next line
        bool operator<(const Line& o) const { return a < o.a; }
        bool operator<(T x) const { return p < x; }
    };

    using iterator = typename std::multiset<Line, std::less<>>::iterator;
    static constexpr double INF = std::numeric_limits<double>::max() / 2;

    std::multiset<Line, std::less<>> lines;

    bool update(iterator x, iterator y) const {
        if (y == lines.end()) {
            x->p = INF;
            return false;
        }
        if (x->a == y->a) {
            x->p = (x->b > y->b ? INF : -INF);
        } else {
            x->p = 1.0 * (y->b - x->b) / (x->a - y->a);
        }
        return x->p >= y->p;
    }
};
