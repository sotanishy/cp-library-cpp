#pragma once
#include <algorithm>
#include <utility>
#include <vector>

#include "convex_hull.hpp"
#include "geometry.hpp"

/**
 * @brief Furthest Pair
 */
std::tuple<T, int, int> furthest_pair(const std::vector<Vec>& pts) {
    assert(pts.size() >= 2);
    auto conv = convex_hull(pts);
    const int n = conv.size();
    if (n <= 1) {
        return {0, 0, 1};
    }
    std::tuple<T, int, int> furthest;
    if (n == 2) {
        furthest = {std::abs(conv[0] - conv[1]), 0, 1};
    } else {
        int si = 0, sj = 0;
        for (int k = 0; k < n; ++k) {
            if (lt(conv[k].real(), conv[si].real())) si = k;
            if (lt(conv[sj].real(), conv[k].real())) sj = k;
        }
        for (int i = si, j = sj; i != sj || j != si;) {
            furthest = std::max(furthest, {std::abs(conv[i] - conv[j]), i, j});
            if (lt(cross(conv[(i + 1) % n] - conv[i],
                         conv[(j + 1) % n] - conv[j]),
                   0)) {
                i = (i + 1) % n;
            } else {
                j = (j + 1) % n;
            }
        }
    }
    auto [d, i0, j0] = furthest;
    int i1 = -1, j1 = -1;
    for (int k = 0; k < (int)pts.size(); ++k) {
        if (i1 == -1 && pts[k] == conv[i0]) i1 = k;
        if (j1 == -1 && pts[k] == conv[j0]) j1 = k;
    }
    return {d, i1, j1};
}