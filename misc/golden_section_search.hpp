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
    double v1 = f(m1), v2 = f(m2);
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