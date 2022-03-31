#pragma once
#include <vector>

template <typename T>
T kitamasa(const std::vector<T>& a, const std::vector<T>& c, long long n) {
    const int d = a.size();
    if (n < d) {
        return a[n];
    }

    auto dfs = [&](const auto& dfs, long long n) -> std::vector<T> {
        if (n == d) {
            return c;
        }
        std::vector<T> res(d);
        if (n & 1 || n < 2 * d) {
            auto x = dfs(dfs, n - 1);
            for (int j = 0; j < d; ++j) {
                res[j] = c[j] * x[d - 1];
                if (j > 0) {
                    res[j] += x[j - 1];
                }
            }
        } else {
            std::vector x(d, std::vector<T>(d));
            x[0] = dfs(dfs, n / 2);
            for (int i = 1; i < d; ++i) {
                for (int j = 0; j < d; ++j) {
                    x[i][j] = c[j] * x[i - 1][d - 1];
                    if (j > 0) {
                        x[i][j] += x[i - 1][j - 1];
                    }
                }
            }
            for (int i = 0; i < d; ++i) {
                for (int j = 0; j < d; ++j) {
                    res[j] += x[0][i] * x[i][j];
                }
            }
        }
        return res;
    };

    auto x = dfs(dfs, n);
    T ans = 0;
    for (int i = 0; i < d; ++i) {
        ans += x[i] * a[i];
    }
    return ans;
}