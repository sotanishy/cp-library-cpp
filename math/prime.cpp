#pragma once
#include <map>
#include <numeric>
#include <vector>

/*
 * Primality Test
 */
bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    if (n < 9) return true;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

/*
 * Prime Table
 */
std::vector<bool> prime_table(int n) {
    std::vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int j = 4; j <= n; j += 2) prime[j] = false;
    for (int i = 3; i * i <= n; i += 2) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= n; j += 2 * i) prime[j] = false;
    }
    return prime;
}

/*
 * Table of Minimum Prime Factors
 */
std::vector<int> min_factor_table(int n) {
    std::vector<int> factor(n + 1);
    std::iota(factor.begin(), factor.end(), 0);
    for (int i = 2; i * i <= n; ++i) {
        if (factor[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (factor[j] == j) {
                    factor[j] = i;
                }
            }
        }
    }
    return factor;
}

/*
 * Prime Factorization
 */
std::map<long long, int> prime_factor(long long n) {
    std::map<long long, int> ret;
    if (n % 2 == 0) {
        int cnt = 0;
        while (n % 2 == 0) {
            ++cnt;
            n /= 2;
        }
        ret[2] = cnt;
    }
    for (long long i = 3; i * i <= n; i += 2) {
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