#pragma once
#include <algorithm>
#include <cassert>
#include <limits>

#include "cht/convex_hull_trick_binsearchtree.hpp"

/**
 * @brief Inner-Product Search
 */
template <typename T>
class InnerProductSearch {
   public:
    void add(T a, T b) {
        ++n;
        a_min = std::min(a_min, a);
        a_max = std::max(a_max, a);
        cht_pos.add(a, b);
        cht_neg.add(-a, -b);
    }

    T query(T x, T y) const {
        assert(n > 0);
        if (y == 0) {
            return (x > 0 ? a_min : a_max) * x;
        } else if (y > 0) {
            return cht_pos.get(x / y) * y;
        } else {
            return -cht_neg.get(x / y) * y;
        }
    }

    int size() const { return n; }

   private:
    static constexpr T INF = std::numeric_limits<T>::max();

    int n = 0;
    T a_min = INF, a_max = -INF;
    ConvexHullTrick<T> cht_0, cht_pos, cht_neg;
};
