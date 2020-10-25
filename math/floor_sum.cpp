#pragma once

/*
 * @brief Floor Sum
 * @docs docs/math/floor_sum.md
 */
long long floor_sum(long long n, long long m, long long a, long long b) {
    long long sum = 0;
    if (a >= m) {
        sum += (a / m) * n * (n - 1) / 2;
        a %= m;
    }
    if (b >= m) {
        sum += (b / m) * n;
        b %= m;
    }
    long long y = (a * n + b) / m;
    if (y == 0) return sum;
    long long x = (m * y - b + a - 1) / a;
    sum += (n - x) * y + floor_sum(y, a, m, a * x - m * y + b);
    return sum;
}