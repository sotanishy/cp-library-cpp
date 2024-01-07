#pragma once
#include <array>
#include <vector>

#include "zeta_moebius_transform.hpp"

template <typename T, std::size_t N>
std::array<T, N>& operator+=(std::array<T, N>& lhs,
                             const std::array<T, N>& rhs) {
    for (int i = 0; i < (int)N; ++i) lhs[i] += rhs[i];
    return lhs;
}

template <typename T, std::size_t N>
std::array<T, N>& operator-=(std::array<T, N>& lhs,
                             const std::array<T, N>& rhs) {
    for (int i = 0; i < (int)N; ++i) lhs[i] -= rhs[i];
    return lhs;
}

template <typename T, int N>
std::vector<T> subset_convolution(const std::vector<T>& a,
                                  const std::vector<T>& b) {
    using Poly = std::array<T, N + 1>;
    const int n = std::bit_ceil(std::max(a.size(), b.size()));

    // convert to polynomials
    std::vector<Poly> pa(n), pb(n);
    for (int i = 0; i < (int)a.size(); ++i) {
        pa[i][std::popcount(i)] = a[i];
    }
    for (int i = 0; i < (int)b.size(); ++i) {
        pb[i][std::popcount(i)] = b[i];
    }

    // bitwise or convolution
    subset_fzt(pa);
    subset_fzt(pb);
    for (int i = 0; i < n; ++i) {
        Poly pc;
        for (int j = 0; j <= N; ++j) {
            for (int k = 0; k <= N - j; ++k) {
                pc[j + k] += pa[i][j] * pb[i][k];
            }
        }
        pa[i].swap(pc);
    }
    subset_fmt(pa);

    // convert back
    std::vector<T> ret(n);
    for (int i = 0; i < n; ++i) {
        ret[i] = pa[i][std::popcount(i)];
    }
    return ret;
}
