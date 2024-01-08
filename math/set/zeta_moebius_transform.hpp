#pragma once
#include <bit>
#include <cassert>
#include <vector>

template <typename T>
void superset_fzt(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    const int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; ++j) {
            if (!(j & i)) a[j] += a[j | i];
        }
    }
}

template <typename T>
void superset_fmt(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    const int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; ++j) {
            if (!(j & i)) a[j] -= a[j | i];
        }
    }
}

template <typename T>
void subset_fzt(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    const int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; ++j) {
            if (!(j & i)) a[j | i] += a[j];
        }
    }
}

template <typename T>
void subset_fmt(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    const int n = a.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; ++j) {
            if (!(j & i)) a[j | i] -= a[j];
        }
    }
}
