#pragma once
#include <vector>

template <typename T>
T kitamasa(const std::vector<T>& a, const std::vector<T>& d, int n) {
    const int k = a.size();
    if (n < k) {
        return a[n];
    }

    auto dfs = [&](const auto& dfs, int n) -> std::vector<T> {
        if (n == k) {
            return d;
        }
        std::vector<T> res(k);
        if (n & 1 || n < 2 * k) {
            auto x = dfs(dfs, n - 1);
            for (int j = 0; j < k; ++j) {
                res[j] = d[j] * x[k - 1];
                if (j > 0) {
                    res[j] += x[j - 1];
                }
            }
        } else {
            std::vector x(k, std::vector<T>(k));
            x[0] = dfs(dfs, n / 2);
            for (int i = 1; i < k; ++i) {
                for (int j = 0; j < k; ++j) {
                    x[i][j] = d[j] * x[i - 1][k - 1];
                    if (j > 0) {
                        x[i][j] += x[i - 1][j - 1];
                    }
                }
            }
            for (int i = 0; i < k; ++i) {
                for (int j = 0; j < k; ++j) {
                    res[j] += x[0][i] * x[i][j];
                }
            }
        }
        return res;
    };

    auto x = dfs(dfs, n);
    T ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += x[i] * a[i];
    }
    return ans;
}