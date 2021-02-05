#pragma once
#include <algorithm>
#include <utility>

std::pair<long long, long long> extgcd(long long a, long long b) {
    long long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;
    while (t) {
        long long q = s / t;
        std::swap(s -= t * q, t);
        std::swap(sx -= tx * q, tx);
        std::swap(sy -= ty * q, ty);
    }
    return {sx, sy};
}

long long mod_inv(long long a, long long mod) {
    long long inv = extgcd(a, mod).first;
    return (inv % mod + mod) % mod;
}