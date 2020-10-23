#pragma once

/*
 * @brief Mod Exponentiation
 * @docs docs/math/mod_pow.md
 */
long long mod_pow(long long a, long long p, long long mod) {
    long long ret = 1;
    while (p > 0) {
        if (p & 1) ret = ret * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return ret;
}

long long mod_inv(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}