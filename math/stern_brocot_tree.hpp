#pragma once
#include <utility>

/**
 * @brief Stern Brocot Tree
 */
template <typename F>
std::pair<std::pair<long long, long long>, std::pair<long long, long long>>
stern_brocot_tree_search(long long n, F cond) {
    long long a = 0, b = 1, c = 1, d = 0;
    while (true) {
        long long num = a + c, den = b + d;
        if (num > n || den > n) break;
        if (cond(num, den)) {
            long long k = 2;
            while ((num = a + c * k) <= n && (den = b + d * k) <= n &&
                   cond(num, den))
                k *= 2;
            k /= 2;
            a += c * k;
            b += d * k;
        } else {
            long long k = 2;
            while ((num = a * k + c) <= n && (den = b * k + d) <= n &&
                   !cond(num, den))
                k *= 2;
            k /= 2;
            c += a * k;
            d += b * k;
        }
    }
    return {{a, b}, {c, d}};
}