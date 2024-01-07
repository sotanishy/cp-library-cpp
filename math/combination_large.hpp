#pragma once
#include <vector>

#include "../data-structure/disjoint_sparse_table.hpp"

/**
 * @brief Combination (Large)
 */
template <typename mint>
class CombinationLarge {
   public:
    CombinationLarge() = default;
    CombinationLarge(int N, long long M)
        : N(N), M(M), fact_(N + 1), fact_inv_(N + 1) {
        fact_[0] = 1;
        for (int i = 1; i <= N; ++i) fact_[i] = fact_[i - 1] * i;
        fact_inv_[N] = fact_[N].inv();
        for (int i = N; i > 0; --i) fact_inv_[i - 1] = fact_inv_[i] * i;

        std::vector<mint> num(N + 1);
        for (int i = 0; i <= N; ++i) {
            num[i] = M - i;
        }
        st = DisjointSparseTable<MulMonoid>(num);
    }

    mint perm(long long n, int k) const {
        assert(M - N + k - 1 <= n && n <= M);
        if (k < 0 || n < k) return 0;
        return st.fold(M - n, M - n + k);
    }

    mint comb(long long n, int k) const {
        assert(M - N + k - 1 <= n && n <= M);
        if (k < 0 || n < k) return 0;
        return st.fold(M - n, M - n + k) * fact_inv_[k];
    }

    mint fact(int n) const { return fact_[n]; }
    mint fact_inv(int n) const { return fact_inv_[n]; }

   private:
    struct MulMonoid {
        using T = mint;
        static T id() { return 1; }
        static T op(T a, T b) { return a * b; }
    };

    int N;
    long long M;
    std::vector<mint> fact_, fact_inv_;
    DisjointSparseTable<MulMonoid> st;
};