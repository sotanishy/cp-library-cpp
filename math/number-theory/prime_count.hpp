#pragma once
#include <cmath>
#include <vector>

long long prime_count(long long n) {
    int s = (int)std::sqrt(n);
    std::vector<long long> small(n / s + 1), large(s + 1);
    for (int i = 1; i <= n / s; ++i) small[i] = i - 1;
    for (int i = 1; i <= s; ++i) large[i] = n / i - 1;
    for (long long i = 2; i <= s; ++i) {
        if (small[i - 1] == small[i]) continue;  // i is not prime
        long long pi = small[i - 1];
        for (long long j = 1; j <= s && n / j >= i * i; ++j) {
            long long x = i * j <= s ? large[i * j] : small[n / (i * j)];
            if (j <= s) {
                large[j] -= x - pi;
            }
            if (n / j <= n / s) {
                small[n / j] -= x - pi;
            }
        }
        for (long long j = n / s - 1; j >= i * i; --j) {
            small[j] -= small[j / i] - pi;
        }
    }
    return large[1];
}