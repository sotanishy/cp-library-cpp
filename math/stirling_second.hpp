#pragma once
#include <vector>
#include "../convolution/ntt.hpp"
#include "combination.cpp"

template <typename T>
std::vector<T> stirling_second_table(int n) {
    T f = 1;
    for (int i = 1; i <= n; ++i) f *= i;
    f = T(1) / f;
    std::vector<T> a(n + 1), b(n + 1);
    for (int i = n; i >= 0; --i) {
        a[i] = f * (i % 2 ? -1 : 1);
        b[i] = f * T(i).pow(n);
        f *= i;
    }
    auto c = convolution(a, b);
    return std::vector(c.begin(), c.begin() + n + 1);
}

template <typename T>
T stirling_second(int n, int k) {
    Combination<T> comb(n);
    T res = 0;
    for (int i = 0; i <= k; ++i) {
        T tmp = comb.comb(k, i) * T(i).pow(n);
        if ((k - i) & 1) res -= tmp;
        else res += tmp;
    }
    res /= comb.fact(k);
    return res;
}