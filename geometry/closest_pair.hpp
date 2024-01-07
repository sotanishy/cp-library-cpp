#pragma once
#include <numeric>
#include <ranges>
#include <vector>

#include "geometry.hpp"

/**
 * @brief Closest Pair
 */
T closest_pair(std::vector<Vec>& pts) {
    std::ranges::sort(pts, {}, [](const Vec& v) { return v.real(); });

    auto rec = [&](const auto& rec, int l, int r) -> T {
        if (r - l <= 1) return std::numeric_limits<T>::max();
        int m = std::midpoint(l, r);
        T x = pts[m].real();
        T d = std::min(rec(rec, l, m), rec(rec, m, r));
        std::ranges::inplace_merge(pts.begin() + l, pts.begin() + m,
                                   pts.begin() + r, {},
                                   [](const Vec& v) { return v.imag(); });
        std::vector<Vec> b;
        for (int i = l; i < r; ++i) {
            if (leq(d, std::abs(pts[i].real() - x))) continue;
            for (auto& p : b | std::views::reverse) {
                if (leq(d, std::abs(pts[i].imag() - p.imag()))) break;
                d = std::min(d, std::abs(pts[i] - p));
            }
            b.push_back(pts[i]);
        }
        return d;
    };

    return rec(rec, 0, pts.size());
}
