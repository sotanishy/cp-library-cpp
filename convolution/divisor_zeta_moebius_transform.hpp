#pragma once
#include <vector>

template <typename T>
void divisor_fzt(std::vector<T>& a) {
    const int n = a.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        for (int k = 1; k * p < n; ++k) {
            sieve[k * p] = false;
            a[k * p] += a[k];
        }
    }
}

template <typename T>
void divisor_fmt(std::vector<T>& a) {
    const int n = a.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        for (int k = (n - 1) / p; k > 0; --k) {
            sieve[k * p] = false;
            a[k * p] -= a[k];
        }
    }
}

template <typename T>
void multiple_fzt(std::vector<T>& a) {
    const int n = a.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        for (int k = (n - 1) / p; k > 0; --k) {
            sieve[k * p] = false;
            a[k] += a[k * p];
        }
    }
}

template <typename T>
void multiple_fmt(std::vector<T>& a) {
    const int n = a.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        for (int k = 1; k * p < n; ++k) {
            sieve[k * p] = false;
            a[k] -= a[k * p];
        }
    }
}
