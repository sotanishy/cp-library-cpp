#include <bits/stdc++.h>

/*
 * @brief Extended Euclidean Algorithm
 * @docs docs/math/extgcd.md
 */
std::pair<std::int64_t, std::int64_t> extgcd(std::int64_t a, std::int64_t b) {
    std::int64_t s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;
    while (t) {
        std::int64_t q = s / t;
        std::swap(s -= t * q, t);
        std::swap(sx -= tx * q, tx);
        std::swap(sy -= ty * q, ty);
    }
    return {sx, sy};
}

std::int64_t mod_inv(std::int64_t a, std::int64_t mod) {
    std::int64_t inv = extgcd(a, mod).first;
    return (inv % mod + mod) % mod;
}