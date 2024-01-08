#pragma once

/**
 * @brief Integer Square Root
 */
unsigned long long isqrt(unsigned long long n) {
    unsigned long long x0 = n / 2;
    if (x0 == 0) return n;
    unsigned long long x1 = (x0 + n / x0) / 2;
    while (x1 < x0) {
        x0 = x1;
        x1 = (x0 + n / x0) / 2;
    }
    return x0;
}