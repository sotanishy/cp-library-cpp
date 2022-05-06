#pragma once
#include <numeric>
#include <vector>
#include "geometry.hpp"

/**
 * @brief Closest Pair
 */
T closest_pair(std::vector<Vec>& pts) {
    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const Vec& v2) {
        return v1.real() < v2.real();
    });

    auto rec = [&](const auto& rec, int l, int r) -> T {
        if (r - l <= 1) return std::numeric_limits<T>::max();
        int m = (l + r) / 2;
        T x = pts[m].real();
        T d = std::min(rec(rec, l, m), rec(rec, m, r));
        std::inplace_merge(pts.begin() + l, pts.begin() + m, pts.begin() + r, [&](const Vec& v1, const Vec& v2) {
            return v1.imag() < v2.imag();
        });
        std::vector<Vec> b;
        for (int i = l; i < r; ++i) {
            if (leq(d, std::abs(pts[i].real() - x))) continue;
            for (int j = (int) b.size() - 1; j >= 0; --j) {
                if (leq(d, std::abs(pts[i].imag() - b[j].imag()))) break;
                d = std::min(d, std::abs(pts[i] - b[j]));
            }
            b.push_back(pts[i]);
        }
        return d;
    };

    return rec(rec, 0, pts.size());
}
