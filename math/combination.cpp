#pragma once
#include <bits/stdc++.h>

/*
 * @brief Combination
 * @docs docs/math/combination.md
 */
template <typename T>
class Combination {
    static T comb(int n, int r) {
        T num = 1, den = 1;
        for (int i = 1; i <= r; ++i) {
            num = num * (n - i + 1);
            den = den * i;
        }
        return num / den;
    }

    Combination() = default;
    Combination(int n) : fact(n + 1), fact_inv(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        fact_inv[n] = 1 / fact[n];
        for (int i = n; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    }

    T fact(int n) const {
        return fact[n];
    }

    T fact_inv(int n) const {
        return fact_inv[n];
    }

    T perm(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact[n] * fact_inv[n - r];
    }

    T comb(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact[n] * fact_inv[r] * fact_inv[n - r];
    }

private:
    std::vector<T> fact, fact_inv;
};