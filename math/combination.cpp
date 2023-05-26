#pragma once
#include <vector>

template <typename mint>
class Combination {
   public:
    Combination() = default;
    Combination(int n) : fact_(n + 1), fact_inv_(n + 1) {
        fact_[0] = 1;
        for (int i = 1; i <= n; ++i) fact_[i] = fact_[i - 1] * i;
        fact_inv_[n]=fact_[n].inv();
        for (int i = n; i > 0; --i) fact_inv_[i - 1] = fact_inv_[i] * i;
    }

    mint perm(int n, int k) const {
        if (k < 0 || n < k) return 0;
        return fact_[n] * fact_inv_[n - k];
    }

    mint comb(int n, int k) const {
        if (k < 0 || n < k) return 0;
        return fact_[n] * fact_inv_[k] * fact_inv_[n - k];
    }

    mint fact(int n) const { return fact_[n]; }
    mint fact_inv(int n) const { return fact_inv_[n]; }

   private:
    std::vector<mint> fact_, fact_inv_;
};

template <typename T>
T comb(long long n, int k) {
    if (k < 0 || n < k) return 0;
    T num = 1, den = 1;
    for (int i = 1; i <= k; ++i) {
        num = num * (n - i + 1);
        den = den * i;
    }
    return num / den;
}