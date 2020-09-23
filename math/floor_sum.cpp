#include <bits/stdc++.h>

/*
 * @brief Floor Sum
 * @docs docs/math/floor_sum.md
 */
std::int64_t floor_sum(std::int64_t n, std::int64_t m, std::int64_t a, std::int64_t b) {
    std::int64_t sum = 0;
    if (a >= m) {
        sum += (a / m) * n * (n - 1) / 2;
        a %= m;
    }
    if (b >= m) {
        sum += (b / m) * n;
        b %= m;
    }
    std::int64_t y = (a * n + b) / m;
    if (y == 0) return sum;
    std::int64_t x = (m * y - b + a - 1) / a;
    sum += (n - x) * y + floor_sum(y, a, m, a * x - m * y + b);
    return sum;
}