#pragma once
#include <vector>

template <typename T>
void fwht(std::vector<T>& a) {
    int n = a.size();
    for (int h = 1; h < n; h <<= 1) {
        for (int i = 0; i < n; i += h << 1) {
            for (int j = i; j < i + h; ++j) {
                T x = a[j];
                T y = a[j | h];
                a[j] = x + y;
                a[j | h] = x - y;
            }
        }
    }
}

template <typename T>
void ifwht(std::vector<T>& a) {
    int n = a.size();
    for (int h = 1; h < n; h <<= 1) {
        for (int i = 0; i < n; i += h << 1) {
            for (int j = i; j < i + h; ++j) {
                T x = a[j];
                T y = a[j | h];
                a[j] = (x + y) / 2;
                a[j | h] = (x - y) / 2;
            }
        }
    }
}

template <typename T>
static std::vector<double> xor_convolution(std::vector<T> a, std::vector<T> b) {
    int size = std::max(a.size(), b.size());
    int n = 1;
    while (n < size) n <<= 1;
    a.resize(n);
    b.resize(n);
    fwht(a);
    fwht(b);
    for (int i = 0; i < n; ++i) a[i] *= b[i];
    ifwht(a);
    return a;
}