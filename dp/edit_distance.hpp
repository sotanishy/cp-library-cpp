#pragma once
#include <algorithm>
#include <string>
#include <vector>

/**
 * @brief Edit Distance
 */
int edit_distance(const std::string& s, const std::string& t) {
    const int n = s.size(), m = t.size();
    std::vector dp(n + 1, std::vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) dp[i][0] = i;
    for (int j = 1; j <= m; ++j) dp[0][j] = j;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = std::min({
                dp[i - 1][j] + 1,                          // insert
                dp[i][j - 1] + 1,                          // delete
                dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])  // replace
            });
        }
    }
    return dp[n][m];
}