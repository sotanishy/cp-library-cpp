#pragma once
#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template <typename T>
T minimum_steiner_tree(std::vector<std::vector<std::pair<int, T>>>& G,
                       std::vector<int>& terminals) {
    const int n = G.size();
    const int t = terminals.size();
    constexpr T INF = std::numeric_limits<T>::max() / 2;
    using P = std::pair<T, int>;

    std::vector<std::vector<T>> dp(1 << t, std::vector<T>(n, INF));
    for (int i = 0; i < t; ++i) dp[1 << i][terminals[i]] = 0;

    for (int S = 1; S < (1 << t); ++S) {
        for (int i = 0; i < n; ++i) {
            for (int U = S; U > 0; U = (U - 1) & S) {
                dp[S][i] = std::min(dp[S][i], dp[S ^ U][i] + dp[U][i]);
            }
        }
        if (S == (1 << t) - 1) continue;
        std::priority_queue<P, std::vector<P>, std::greater<>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(dp[S][i], i);
        }
        while (!pq.empty()) {
            auto [d, v] = pq.top();
            pq.pop();
            if (dp[S][v] < d) continue;
            for (auto [u, w] : G[v]) {
                if (dp[S][u] > d + w) {
                    dp[S][u] = d + w;
                    pq.emplace(dp[S][u], u);
                }
            }
        }
    }

    return dp.back()[terminals[0]];
}
