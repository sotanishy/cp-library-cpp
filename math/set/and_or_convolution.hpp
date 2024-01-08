#pragma once
#include <bit>
#include <vector>

#include "zeta_moebius_transform.hpp"

/**
 * @brief Bitwise AND/OR Convolution
 */

template <typename T>
std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {
    const int n = std::bit_ceil(std::max(a.size(), b.size()));
    a.resize(n);
    b.resize(n);
    superset_fzt(a);
    superset_fzt(b);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    superset_fmt(a);
    return a;
}

template <typename T>
std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {
    const int n = std::bit_ceil(std::max(a.size(), b.size()));
    a.resize(n);
    b.resize(n);
    subset_fzt(a);
    subset_fzt(b);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    subset_fmt(a);
    return a;
}
