#include <bits/stdc++.h>

/*
 * @brief Euler's Totient Function
 * @docs docs/math/euler_totient.md
 */
std::int64_t euler_totient(std::int64_t n) {
    std::int64_t ret = n;
    if (n % 2 == 0) {
        ret -= ret / 2;
        while (n % 2 == 0) n /= 2;
    }
    for (std::int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            ret -= ret / i;
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) ret -= ret / n;
    return ret;
}