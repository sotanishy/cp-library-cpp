#pragma once
#include <bit>
#include <vector>

/**
 * @brief Bitwise XOR Convolution
 */

template <typename T>
std::vector<T> xor_convolution(std::vector<T> a, std::vector<T> b) {
    const int n = std::bit_ceil(std::max(a.size(), b.size()));
    a.resize(n);
    b.resize(n);
    fwht(a);
    fwht(b);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    ifwht(a);
    return a;
}