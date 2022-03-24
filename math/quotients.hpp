#pragma once
#include <vector>

/**
 * @brief Quotient Ranges
 */
template <typename T>
std::vector<std::pair<T, T>> quotient_ranges(T n) {
    std::vector<std::pair<T, T>> ret;
    T i = 1;
    while (i <= n) {
        T q = n / i;
        T j = n / q + 1;
        ret.emplace_back(i, j);
        i = j;
    }
    return ret;
}
