#pragma once
#include "combination.cpp"

/*
 * @brief Stirling Number of the Second Kind
 */
template <typename T>
T stirling_second(int n, int k) {
    Combination<T> comb(n);
    T res = 0;
    for (int i = 0; i <= k; ++i) {
        T tmp = comb.comb(k, i) * T(i).pow(n);
        if ((k - i) & 1) res -= tmp;
        else res += tmp;
    }
    for (int i = 1; i <= k; ++i) res /= i;
    return res;
}