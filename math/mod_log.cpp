#include <bits/stdc++.h>
#include "mod_pow.cpp"

/*
 * @brief Discrete Logarithm
 * @docs docs/math/mod_log.md
 */
int mod_log(std::int64_t a, std::int64_t b, std::int64_t p) {
    int m = sqrt(p) + 1;
    std::vector<std::int64_t> baby(m);
    std::unordered_map<std::int64_t, int> baby_index;
    std::int64_t x = 1;
    for (int i = 0; i < m; ++i) {
        baby[i] = x;
        baby_index[x] = i;
        x = x * a % p;
    }

    std::vector<std::int64_t> giant(m);
    std::int64_t c = mod_inv(mod_pow(a, m, p), p);
    x = 1;
    for (int i = 0; i < m; ++i) {
        giant[i] = x;
        x = x * c % p;
    }

    for (int i = 0; i < m; ++i) {
        std::int64_t y = b * giant[i] % p;
        if (baby_index.count(y) > 0) {
            return i * m + baby_index[y];
        }
    }
    return -1;
}