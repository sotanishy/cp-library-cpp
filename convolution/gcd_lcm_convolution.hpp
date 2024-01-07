#pragma once
#include <vector>

#include "divisor_zeta_moebius_transform.hpp"

/**
 * @brief GCD/LCM Convolution
 */

template <typename T>
std::vector<T> gcd_convolution(std::vector<T> a, std::vector<T> b) {
    const int n = std::max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    multiple_fzt(a);
    multiple_fzt(b);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    multiple_fmt(a);
    return a;
}

template <typename T>
std::vector<T> lcm_convolution(std::vector<T> a, std::vector<T> b) {
    const int n = std::max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    divisor_fzt(a);
    divisor_fzt(b);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    divisor_fmt(a);
    return a;
}