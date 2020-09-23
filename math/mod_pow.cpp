#include <bits/stdc++.h>

/*
 * @brief Mod Exponentiation
 * @docs docs/math/mod_pow.md
 */
std::int64_t mod_pow(std::int64_t a, std::int64_t p, std::int64_t mod) {
    std::int64_t ret = 1;
    while (p > 0) {
        if (p & 1) ret = ret * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return ret;
}

std::int64_t mod_inv(std::int64_t a, std::int64_t mod) {
    return mod_pow(a, mod - 2, mod);
}