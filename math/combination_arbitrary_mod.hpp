#pragma once
#include <vector>

#include "number-theory/prime.hpp"

template <typename mint>
std::vector<mint> combination_arbitrary_modint(int n) {
    if (n == 0) return {1};
    const int m = mint::mod();

    // preprocess prime
    auto is_prime = prime_table(n);
    std::vector<int> prime;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
        }
    }

    int l = 0;
    std::vector<int> maxfact(n + 1, -1);
    std::vector<int> ps;
    for (int p : prime) {
        if (m % p == 0) {
            ps.push_back(p);
            for (int i = p; i <= n; i += p) {
                maxfact[i] = l;
            }
            ++l;
        }
    }

    std::vector<std::vector<mint>> pow(l);
    for (int i = 0; i < l; ++i) {
        pow[i].resize(n / (ps[i] - 1) + 1);
        pow[i][0] = 1;
        for (int j = 1; j < (int)pow[i].size(); ++j) {
            pow[i][j] = pow[i][j - 1] * ps[i];
        }
    }

    // calculate comb
    std::vector<mint> comb(n + 1);
    comb[0] = 1;
    mint s = 1;
    std::vector<int> t(l);
    for (int k = 1; k <= n; ++k) {
        int den = k;
        while (maxfact[den] != -1) {
            --t[maxfact[den]];
            den /= ps[maxfact[den]];
        }
        int num = n - k + 1;
        while (maxfact[num] != -1) {
            ++t[maxfact[num]];
            num /= ps[maxfact[num]];
        }
        s = s / den * num;
        comb[k] = s;
        for (int i = 0; i < l; ++i) {
            comb[k] *= pow[i][t[i]];
        }
    }

    return comb;
}