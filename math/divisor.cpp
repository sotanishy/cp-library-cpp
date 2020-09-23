#include <bits/stdc++.h>

/*
 * @brief Divisors
 * @docs docs/math/divisor.md
 */
std::vector<std::int64_t> divisor(std::int64_t n) {
    std::vector<std::int64_t> ret1, ret2;
    for (std::int64_t i = 1; i * i <= n; ++i) {
        if (i * i == n) {
            ret1.push_back(i);
        } else if (n % i == 0) {
            ret1.push_back(i);
            ret2.push_back(n / i);
        }
    }
    ret1.insert(ret1.end(), ret2.rbegin(), ret2.rend());
    return ret1;
}