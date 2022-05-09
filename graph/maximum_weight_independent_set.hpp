#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

template <typename T>
T maximum_weight_independent_set(const std::vector<std::vector<int>>& G, const std::vector<T>& w) {
    const int n = G.size();
    const int n1 = n / 2;
    const int n2 = n - n1;
    std::vector<T> neighbors11(n1), neighbors12(n1), neighbors22(n2);
    for (int i = 0; i < n; ++i) {
        for (int j : G[i]) {
            if (i < n1 && j < n1) neighbors11[i] |= 1 << j;
            if (i < n1 && j >= n1) neighbors12[i] |= 1 << (j - n1);
            if (i >= n1 && j >= n1) neighbors22[i - n1] |= 1 << (j - n1);
        }
    }
    std::vector<int> dp(1 << n2);
    for (int S = 0; S < 1 << n2; ++S) {
        T s = 0;
        int neighbor = 0;
        for (int i = 0; i < n2; ++i) {
            if (S >> i & 1) {
                s += w[n1 + i];
                neighbor |= neighbors22[i];
            }
        }
        if (!(neighbor & S)) {
            dp[S] = std::max(dp[S], s);
        }
        for (int i = 0; i < n2; ++i) {
            if (!(S >> i & 1)) {
                dp[S | (1 << i)] = std::max(dp[S | (1 << i)], dp[S]);
            }
        }
    }
    T ans = 0;
    for (int S = 0; S < 1 << n1; ++S) {
        if (!(S & 1)) continue;
        int s = 0;
        int neighbor1 = 0;
        int neighbor2 = 0;
        for (int i = 0; i < n1; ++i) {
            if (S >> i & 1) {
                s += w[i];
                neighbor1 |= neighbors11[i];
                neighbor2 |= neighbors12[i];
            }
        }
        if (!(neighbor1 & S)) {
            ans = std::max(ans, s + dp[neighbor2 ^ ((1 << n2) - 1)]);
        }
    }
    return ans;
}
