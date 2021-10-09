#include <bits/stdc++.h>

template <typename T>
class DynamicConvexHullTrick {
public:
    static DynamicConvexHullTrick merge(DynamicConvexHullTrick& a, DynamicConvexHullTrick& b) {
        if (a.lines.size() > b.lines.size()) std::swap(a, b);
        for (auto& l : b.lines) {
            a.add(l.a, l.b);
        }
        return a;
    }

    void add(T a, T b) {
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
        auto it = *lines.lower_bound(x);
        return it.a * x + it.b;
    }

private:
    struct Line {
        T a, b, p;  // ax + b, intersection point with the next line
        bool operator<(const Line& o) const { return a < o.a; }
        bool operator<(T x) const { return p < x; }
    };

    using iterator = std::multiset<Line>::iterator;

    std::multiset<Line> lines;
    constexpr T INF = std::numeric_limits<T>::max() / 2;

    bool update(iterator x, iterator y) const {
        if (y == lines.end()) return false;
        if (x->a == y->a) {
            x->p = (x->b > y->b ? INF : -INF);
        } else {
            x->p = floor_div(y->b - x->b, x->a - y->a);
        }
        return x->p >= y->p;
    }

    inline T floor_div(T a, T b) const { return a / b - ((a^b) < 0 && a % b); }
};