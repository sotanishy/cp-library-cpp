#pragma once
#include <numbers>

/**
 * @brief Golden-Section Search
 */
template <typename F>
double golden_section_search(F f, double lb, double ub, int iter = 100) {
    constexpr auto phi = std::numbers::phi;
    double m1 = ub - (ub - lb) / phi;
    double m2 = lb + (ub - lb) / phi;
    auto v1 = f(m1), v2 = f(m2);
    for (int i = 0; i < iter; ++i) {
        if (v1 < v2) {
            ub = m2;
            m2 = m1;
            v2 = v1;
            m1 = ub - (ub - lb) / phi;
            v1 = f(m1);
        } else {
            lb = m1;
            m1 = m2;
            v1 = v2;
            m2 = lb + (ub - lb) / phi;
            v2 = f(m2);
        }
    }
    return lb;
}

// [lb, ub] (inclusive)
template <typename F>
long long golden_section_search(F f, long long lb, long long ub) {
    // t-s, s, t are consecutive fibonacci numbers
    long long s = 1, t = 2;
    while (t < ub - lb + 2) std::swap(s += t, t);
    long long l = lb - 1, m1 = l + t - s, m2 = l + s;
    auto v1 = f(m1), v2 = f(m2);
    while (m1 != m2) {
        std::swap(s, t -= s);
        if (ub < m2 || v1 <= v2) {
            m2 = m1;
            v2 = v1;
            m1 = l + t - s;
            v1 = f(m1);
        } else {
            l = m1;
            m1 = m2;
            v1 = v2;
            m2 = l + s;
            v2 = m2 <= ub ? f(m2) : v1;
        }
    }
    return m1;
}
