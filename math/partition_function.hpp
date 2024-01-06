#pragma once
#include "polynomial.cpp"

template <typename T>
Polynomial<T> partition_function_table(int n) {
    Polynomial<T> den(n + 1);
    den[0] = 1;
    for (int k = 1; k * (3 * k - 1) / 2 <= n; ++k) {
        T b = k % 2 == 0 ? 1 : -1;
        den[k * (3 * k - 1) / 2] = b;
        if (k * (3 * k + 1) / 2 <= n) {
            den[k * (3 * k + 1) / 2] = b;
        }
    }
    return den.inv();
}