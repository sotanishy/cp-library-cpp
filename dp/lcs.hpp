#pragma once
#include <algorithm>
#include <string>
#include <vector>

/**
 * @brief Longest Common Subsequence
 */
int longest_common_subsequence(const std::string& s, const std::string& t) {
    const int n = s.size(), m = t.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == t[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return dp[n][m];
}

