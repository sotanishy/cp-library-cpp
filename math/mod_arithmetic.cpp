#pragma once
#include <cmath>
#include <numeric>
#include <unordered_map>
#include "euler_totient.cpp"

/*
 * Modular Exponentiation
 */
long long mod_pow(long long a, long long e, int mod) {
    long long ret = 1;
    while (e > 0) {
        if (e & 1) ret = ret * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return ret;
}

long long mod_inv(long long a, int mod) {
    return mod_pow(a, mod - 2, mod);
}

/*
 * Discrete Logarithm
 */
int mod_log(long long a, long long b, int mod) {
    // make a and mod coprime
    a %= mod;
    b %= mod;
    long long k = 1, add = 0, g;
    while ((g = std::gcd(a, mod)) > 1) {
        if (b == k) return add;
        if (b % g) return -1;
        b /= g;
        mod /= g;
        ++add;
        k = k * a / g % mod;
    }

    // baby-step
    const int m = sqrt(mod) + 1;
    std::unordered_map<long long, int> baby_index;
    long long baby = b;
    for (int i = 0; i <= m; ++i) {
        baby_index[baby] = i;
        baby = baby * a % mod;
    }

    // giant-step
    long long am = 1;
    for (int i = 0; i < m; ++i) am = am * a % mod;
    long long giant = k;
    for (int i = 1; i <= m; ++i) {
        giant = giant * am % mod;
        if (baby_index.count(giant)) {
            return i * m - baby_index[giant] + add;
        }
    }
    return -1;
}

/*
 * Quadratic Residue
 */
long long mod_sqrt(long long n, int mod) {
    if (n == 0) return 0;
    if (mod == 2) return 1;
    if (std::gcd(n, mod) != 1) return -1;
    if (mod_pow(n, (mod - 1) / 2, mod) == mod - 1) return -1;

    int Q = mod - 1, S = 0;
    while (!(Q & 1)) Q >>= 1, ++S;
    long long z = 2;
    while (true) {
        if (mod_pow(z, (mod - 1) / 2, mod) == mod - 1) break;
        ++z;
    }
    int M = S;
    long long c = mod_pow(z, Q, mod);
    long long t = mod_pow(n, Q, mod);
    long long R = mod_pow(n, (Q + 1) / 2, mod);
    while (t != 1) {
        int i = 0;
        long long s = t;
        while (s != 1) {
            s = s * s % mod;
            ++i;
        }
        long long b = mod_pow(c, 1 << (M - i - 1), mod);
        M = i;
        c = b * b % mod;
        t = t * c % mod;
        R = R * b % mod;
    }
    return R;
}

/**
 * Modular Tetration
 */
long long mod_tetration(long long a, long long b, int mod) {
    if (mod == 1) return 0;
    if (a == 0) return 1 - (b % 2);
    if (a == 1 || b == 0) return 1;

    auto pow = [&](long long a, long long e, int mod) {
        if (a >= mod) a = a % mod + mod;
        long long ret = 1;
        while (e > 0) {
            if (e & 1) {
                ret = ret * a;
                if (ret >= mod) ret = ret % mod + mod;
            }
            a = a * a;
            if (a >= mod) a = a % mod + mod;
            e >>= 1;
        }
        return ret;
    };

    auto rec = [&](auto& rec, long long b, int mod) -> long long {
        if (b == 1) return a;
        if (mod == 1) return 1;
        return pow(a, rec(rec, b - 1, euler_totient(mod)), mod);
    };

    return rec(rec, b, mod) % mod;
}

/**
 * Table of Modular Inverses
 */
std::vector<int> mod_inv_table(int n, int mod) {
    std::vector<int> inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        inv[i] = mod - 1LL * inv[mod % i] * (mod / i) % mod;
    }
    return inv;
}