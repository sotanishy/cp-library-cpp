#pragma once
#include <vector>

#include "polynomial.cpp"

template <typename mint>
std::vector<mint> count_subset_sum(const std::vector<int>& val, int V) {
    std::vector<mint> a(V + 1);
    for (auto x : val) {
        a[x] += 1;
    }

    std::vector<mint> inv(V + 1);
    for (int i = 1; i <= V; ++i) inv[i] = mint(1) / i;

    Polynomial<mint> f(V + 1);
    for (int k = 1; k <= V; ++k) {
        if (a[k] == 0) continue;
        for (int i = 1; k * i <= V; ++i) {
            f[k * i] += mint(i % 2 == 0 ? -1 : 1) * a[k] * inv[i];
        }
    }
    return f.exp();
}
