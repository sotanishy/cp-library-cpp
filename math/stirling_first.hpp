#pragma once
#include "polynomial.cpp"

template <typename T>
Polynomial<T> stirling_first_table(int n) {
    if (n == 0) return {1};
    Polynomial<T> ret = stirling_first_table<T>(n / 2);
    ret *= ret.taylor_shift(-(n / 2));
    if (n % 2) ret = (ret << 1) + ret * (-(n - 1));  // ret *= (x - (n - 1))
    return ret;
}