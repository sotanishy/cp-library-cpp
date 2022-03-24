#pragma once
#include <vector>

template <typename T>
void fzt(std::vector<T>& a, bool subset) {
    int k = 31 - __builtin_clz(a.size());
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if ((j >> i & 1) == subset) a[j] += a[j ^ (1 << i)];
        }
    }
}

template <typename T>
void fmt(std::vector<T>& a, bool subset) {
    int k = 31 - __builtin_clz(a.size());
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if ((j >> i & 1) == subset) a[j] -= a[j ^ (1 << i)];
        }
    }
}

template <typename T>
std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {
    int size = std::max(a.size(), b.size());
    int n = 1;
    while (n < size) n <<= 1;
    a.resize(n);
    b.resize(n);
    fzt(a, true);
    fzt(b, true);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    fmt(a, true);
    return a;
}

template <typename T>
std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {
    int size = std::max(a.size(), b.size());
    int n = 1;
    while (n < size) n <<= 1;
    a.resize(n);
    b.resize(n);
    fzt(a, false);
    fzt(b, false);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    fmt(a, false);
    return a;
}