#pragma once
#include <utility>

/**
 * @brief Stern Brocot Tree
 */
template <typename F>
std::pair<std::pair<long long, long long>, std::pair<long long, long long>> stern_brocot_tree(long long n, F cond) {
    long long a = 0, b = 1, c = 1, d = 0;
    while (true) {
        long long num = a + c, den = b + d;
        if (num > n || den > n) break;
        if (cond(num, den)) {
            a = num, b = den;
        } else {
            c = num, d = den;
        }
    }
    return {{a, b}, {c, d}};
}
