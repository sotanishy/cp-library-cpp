#include <bits/stdc++.h>

/*
 * @brief Prime Factor
 * @docs docs/math/prime_factor.md
 */
std::map<std::int64_t, int> prime_factor(std::int64_t n) {
    std::map<std::int64_t, int> ret;
    if (n % 2 == 0) {
        int cnt = 0;
        while (n % 2 == 0) {
            ++cnt;
            n /= 2;
        }
        ret[2] = cnt;
    }
    for (std::int64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            ret[i] = cnt;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}