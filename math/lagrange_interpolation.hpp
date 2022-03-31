#pragma once
#include <vector>

template <typename T>
T lagrange_interpolation(const std::vector<T>& f, long long n) {
    const int d = f.size() - 1;
    std::vector<T> fact(d + 1, 1), fact_inv(d + 1, 1);
    for (int i = 1; i <= d; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[d] = T(1) / fact[d];
    for (int i = d; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;

    std::vector<T> num(d + 1, 1);
    T a = 1;
    for (int i = 0; i <= d; ++i) {
        num[i] *= a;
        a *= n - i;
    }
    a = 1;
    for (int i = d; i >= 0; --i) {
        num[i] *= a;
        a *= n - i;
    }
    T ans = 0;
    for (int i = 0; i <= d; ++i) {
        ans += ((i + d) & 1 ? -1 : 1) * f[i] * num[i] * fact_inv[i] * fact_inv[d - i];
    }
    return ans;
}