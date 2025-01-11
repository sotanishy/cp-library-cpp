#pragma once
#include <numeric>
#include <ranges>
#include <vector>

#include "geometry.hpp"

/**
 * @brief Closest Pair
 */
std::tuple<T, int, int> closest_pair(const std::vector<Vec>& pts_) {
    std::vector<std::pair<Vec, int>> pts;
    for (int i = 0; i < (int)pts_.size(); ++i) pts.emplace_back(pts_[i], i);
    std::ranges::sort(pts, {}, [](const auto& v) { return v.first.real(); });

    auto rec = [&](const auto& rec, int l, int r) -> std::tuple<T, int, int> {
        if (r - l <= 1) return {std::numeric_limits<T>::max(), -1, -1};
        int m = std::midpoint(l, r);
        T x = pts[m].first.real();
        auto closest = std::min(rec(rec, l, m), rec(rec, m, r));
        std::ranges::inplace_merge(
            pts.begin() + l, pts.begin() + m, pts.begin() + r, {},
            [](const auto& v) { return v.first.imag(); });
        std::vector<std::pair<Vec, int>> b;
        for (int i = l; i < r; ++i) {
            if (leq(std::get<0>(closest), std::abs(pts[i].first.real() - x)))
                continue;
            for (auto& p : b | std::views::reverse) {
                if (leq(std::get<0>(closest),
                        std::abs(pts[i].first.imag() - p.first.imag())))
                    break;
                closest = std::min(closest, {std::abs(pts[i].first - p.first),
                                             pts[i].second, p.second});
            }
            b.push_back(pts[i]);
        }
        return closest;
    };

    return rec(rec, 0, pts.size());
}