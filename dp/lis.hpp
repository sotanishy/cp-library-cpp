#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

/**
 * @brief Longest Increasing Subsequence
 */
template <typename T>
int longest_increasing_subsequence(const std::vector<T>& v, bool strict) {
    constexpr T INF = std::numeric_limits<T>::max();
    std::vector<T> dp(v.size() + 1, INF);
    dp[0] = -INF;
    for (auto& x : v) {
        int k;
        if (strict) {
            k = std::lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        } else {
            k = std::upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        }
        dp[k] = x;
    }
    return std::lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}