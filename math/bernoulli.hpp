#pragma once
#include <vector>

#include "polynomial.cpp"

template <typename mint>
std::vector<mint> bernoulli_number_table(int n) {
    std::vector<mint> fact(n + 2), fact_inv(n + 2);
    fact[0] = 1;
    for (int i = 1; i <= n + 1; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[n + 1] = fact[n + 1].inv();
    for (int i = n + 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;
    Polynomial<mint> den(n + 1);
    for (int k = 0; k <= n; ++k) den[k] = fact_inv[k + 1];
    auto res = den.inv();
    std::vector<mint> ret(n + 1);
    for (int k = 0; k <= n; ++k) {
        ret[k] = k < (int)res.size() ? res[k] * fact[k] : 0;
    }
    return ret;
}

template <typename mint>
mint sum_of_powers(long long n, int p) {
    if (p == 0) return n;

    std::vector<mint> fact(p + 2), fact_inv(p + 2);
    fact[0] = 1;
    for (int i = 1; i <= p + 1; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[p + 1] = fact[p + 1].inv();
    for (int i = p + 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;

    auto bern = bernoulli_number_table<mint>(p);
    mint res = 0;
    mint pown = n;
    for (int j = p; j >= 0; --j) {
        auto term = fact_inv[p + 1 - j] * fact_inv[j] * bern[j] * pown;
        res += j % 2 == 0 ? term : -term;
        pown *= n;
    }
    res *= fact[p];
    return res;
}

template <typename mint>
std::vector<mint> sum_of_powers_table(long long n, int p) {
    std::vector<mint> fact(p + 2), fact_inv(p + 2);
    fact[0] = 1;
    for (int i = 1; i <= p + 1; ++i) fact[i] = fact[i - 1] * i;
    fact_inv[p + 1] = fact[p + 1].inv();
    for (int i = p + 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;

    auto bern = bernoulli_number_table<mint>(p + 1);
    std::vector<mint> f(p + 2), g(p + 2);
    mint pown = 1;
    for (int k = 0; k <= p + 1; ++k) {
        f[k] = mint(k % 2 == 0 ? 1 : -1) * bern[k] * fact_inv[k];
        g[k] = pown * fact_inv[k];
        pown *= n;
    }
    auto h = atcoder::convolution(f, g);

    std::vector<mint> res(p + 1);
    res[0] = n;
    for (int k = 1; k <= p; ++k) {
        res[k] = fact[k] * (h[k + 1] - f[k + 1]);
    }
    return res;
}

