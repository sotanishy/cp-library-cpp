#pragma once
#include <algorithm>
#include <deque>
#include <utility>

template <typename T, typename F, T (*eval)(F, T)>
class NonlinearConvexHullTrick {
   public:
    NonlinearConvexHullTrick(T lb, T ub) : lb(lb), ub(ub) {}

    void add(const F& f) {
        T x = lb;
        while (funcs.size() >= 2 &&
               funcs.back().second >=
                   (x = intersection(funcs.back().first, f))) {
            funcs.pop_back();
        }
        if (funcs.size() == 1) x = intersection(funcs.back().first, f);
        funcs.push_back({f, x});
    }

    T get(T x) {
        while (funcs.size() >= 2 &&
               eval(funcs.front().first, x) > eval(funcs[1].first, x)) {
            funcs.pop_front();
        }
        funcs.front().second = lb;
        return eval(funcs.front().first, x);
    }

   private:
    // pair (function, intersection with the previous function)
    std::deque<std::pair<F, T>> funcs;
    T lb, ub;

    // smallest x s.t. f1(x) >= f2(x)
    T intersection(const F& f1, const F& f2) {
        T l = lb - 1, r = ub + 1;
        while (r - l > 1) {
            T m = std::midpoint(l, r);
            if (eval(f1, m) < eval(f2, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
};
