#pragma once
#include <vector>

template <typename T>
class Combination {
public:
    Combination() = default;
    Combination(int n) : fact_(n + 1), fact_inv_(n + 1) {
        fact_[0] = 1;
        for (int i = 1; i <= n; ++i) fact_[i] = fact_[i - 1] * i;
        fact_inv_[n] = T(1) / fact_[n];
        for (int i = n; i > 0; --i) fact_inv_[i - 1] = fact_inv_[i] * i;
    }

    T perm(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact_[n] * fact_inv_[n - r];
    }

    T comb(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact_[n] * fact_inv_[r] * fact_inv_[n - r];
    }

    T fact(int n) const { return fact_[n]; }
    T fact_inv(int n) const { return fact_inv_[n]; }

private:
    std::vector<T> fact_, fact_inv_;
};

template <typename T>
T comb(int n, int r) {
    if (r < 0 || n < r) return 0;
    T num = 1, den = 1;
    for (int i = 1; i <= r; ++i) {
        num = num * (n - i + 1);
        den = den * i;
    }
    return num / den;
}