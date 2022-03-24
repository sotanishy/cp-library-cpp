#pragma once
#include <vector>

template <typename T>
void divisor_fzt(std::vector<T>& a, bool subset) {
    int n = a.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        if (subset) {
            for (int k = 1; k * p < n; ++k) {
                sieve[k * p] = false;
                a[k * p] += a[k];
            }
        } else {
            for (int k = (n - 1) / p; k > 0; --k) {
                sieve[k * p] = false;
                a[k] += a[k * p];
            }
        }
    }
}

template <typename T>
void divisor_fmt(std::vector<T>& a, bool subset) {
    int n = a.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        if (subset) {
            for (int k = (n - 1) / p; k > 0; --k) {
                sieve[k * p] = false;
                a[k * p] -= a[k];
            }
        } else {
            for (int k = 1; k * p < n; ++k) {
                sieve[k * p] = false;
                a[k] -= a[k * p];
            }
        }
    }
}

template <typename T>
std::vector<T> gcd_convolution(std::vector<T> a, std::vector<T> b) {
    int n = std::max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    divisor_fzt(a, false);
    divisor_fzt(b, false);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    divisor_fmt(a, false);
    return a;
}

template <typename T>
std::vector<T> lcm_convolution(std::vector<T> a, std::vector<T> b) {
    int n = std::max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    divisor_fzt(a, true);
    divisor_fzt(b, true);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    divisor_fmt(a, true);
    return a;
}