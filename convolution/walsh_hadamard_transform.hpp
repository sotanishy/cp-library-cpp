#pragma once
#include <bit>
#include <cassert>
#include <vector>

template <typename T>
void fwht(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    const int n = a.size();
    for (int h = 1; h < n; h <<= 1) {
        for (int i = 0; i < n; i += h << 1) {
            for (int j = i; j < i + h; ++j) {
                T x = a[j], y = a[j | h];
                a[j] = x + y;
                a[j | h] = x - y;
            }
        }
    }
}

template <typename T>
void ifwht(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    const int n = a.size();
    const T inv2 = T(1) / 2;
    for (int h = 1; h < n; h <<= 1) {
        for (int i = 0; i < n; i += h << 1) {
            for (int j = i; j < i + h; ++j) {
                T x = a[j], y = a[j | h];
                a[j] = (x + y) * inv2;
                a[j | h] = (x - y) * inv2;
            }
        }
    }
}
