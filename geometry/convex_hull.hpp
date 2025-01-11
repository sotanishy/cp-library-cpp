#pragma once
#include <vector>

#include "geometry.hpp"

std::vector<Vec> convex_hull(std::vector<Vec> pts, bool strict = true) {
    std::ranges::sort(pts, {}, [](const Vec& v) {
        return std::make_pair(v.imag(), v.real());
    });
    pts.erase(std::ranges::unique(pts).begin(), pts.end());
    const int n = pts.size();
    if (n <= 1) return pts;
    int k = 0;  // the number of vertices in the convex hull
    std::vector<Vec> ch(2 * n);
    // right
    for (int i = 0; i < n; ++i) {
        if (strict) {
            while (k > 1 &&
                   leq(cross(ch[k - 1] - ch[k - 2], pts[i] - ch[k - 1]), 0))
                --k;
        } else {
            while (k > 1 &&
                   lt(cross(ch[k - 1] - ch[k - 2], pts[i] - ch[k - 1]), 0))
                --k;
        }
        ch[k++] = pts[i];
    }
    int t = k;
    // left
    for (int i = n - 2; i >= 0; --i) {
        while (k > t &&
               leq(cross(ch[k - 1] - ch[k - 2], pts[i] - ch[k - 1]), 0))
            --k;
        ch[k++] = pts[i];
    }
    ch.resize(k - 1);
    return ch;
}
