#pragma once
#include <algorithm>
#include <limits>
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

template <typename T>
std::pair<int, std::vector<int>> longest_increasing_subsequence_with_index(const std::vector<T>& v, bool strict) {
    constexpr T INF = std::numeric_limits<T>::max();
    const int n = v.size();
    std::vector<T> dp(n + 1, INF);
    std::vector<int> len(n);
    dp[0] = -INF;
    for (int i = 0; i < n; ++i) {
        T x = v[i];
        int k;
        if (strict) {
            k = std::lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        } else {
            k = std::upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        }
        dp[k] = x;
        len[i] = k;
    }

    int res = *max_element(len.begin(), len.end());
    int k = res;
    std::vector<int> idx;
    for (int i = n - 1; i >= 0; --i) {
        if (len[i] == k) {
            idx.push_back(i);
            --k;
        }
    }
    std::reverse(idx.begin(), idx.end());
    return {res, idx};
}