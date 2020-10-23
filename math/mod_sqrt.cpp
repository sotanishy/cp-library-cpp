#pragma once
#include <numeric>
#include "mod_pow.cpp"

/*
 * @brief Quadratic Residue
 */
long long mod_sqrt(long long n, long long p) {
    if (n == 0) return 0;
    if (p == 2) return 1;
    if (std::gcd(n, p) != 1) return -1;
    if (mod_pow(n, (p - 1) / 2, p) == p - 1) return -1;
    int Q = p - 1, S = 0;
    while (!(Q & 1)) Q >>= 1, ++S;
    long long z = 2;
    while (true) {
        if (mod_pow(z, (p - 1) / 2, p) == p - 1) break;
        ++z;
    }
    int M = S;
    long long c = mod_pow(z, Q, p);
    long long t = mod_pow(n, Q, p);
    long long R = mod_pow(n, (Q + 1) / 2, p);
    while (t != 1) {
        int i = 0;
        long long s = t;
        while (s != 1) {
            s = s * s % p;
            ++i;
        }
        long long b = mod_pow(c, 1 << (M - i - 1), p);
        M = i;
        c = b * b % p;
        t = t * c % p;
        R = R * b % p;
    }
    return R;
}