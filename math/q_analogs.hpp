#pragma once
#include <cassert>
#include <vector>

template <typename mint>
class qAnalogs {
   public:
    qAnalogs() = default;
    explicit qAnalogs(mint q, int n)
        : q(q), num(n + 1), fact_(n + 1), fact_inv_(n + 1) {
        for (int k = 1; k <= n; ++k) {
            num[k] = num[k - 1] * q + 1;
        }
        fact_[0] = 1;
        for (int k = 1; k <= n; ++k) {
            fact_[k] = fact_[k - 1] * num[k];
        }
        fact_inv_[n] = mint(1) / fact_[n];
        for (int k = n; k > 0; --k) {
            fact_inv_[k - 1] = fact_inv_[k] * num[k];
        }
    }

    mint number(int n) {
        assert(0 <= n && n < (int)num.size());
        return num[n];
    }

    mint fact(int n) {
        assert(0 <= n && n < (int)fact_.size());
        return fact_[n];
    }

    mint fact_inv(int n) {
        assert(0 <= n && n < (int)fact_inv_.size());
        return fact_inv_[n];
    }

    mint binom(int n, int k) {
        assert(0 <= n && n < (int)fact_.size());
        if (k < 0 || n < k) return 0;
        return fact_[n] * fact_inv_[k] * fact_inv_[n - k];
    }

   private:
    const mint q;
    std::vector<mint> num, fact_, fact_inv_;
};
