#pragma once
#include <bit>
#include <cassert>
#include <vector>

template <typename T>
void superset_fzt(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    int k = std::bit_width(a.size());
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if (!(j >> i & 1)) a[j] += a[j ^ (1 << i)];
        }
    }
}

template <typename T>
void superset_fmt(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    int k = std::bit_width(a.size());
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if (!(j >> i & 1)) a[j] -= a[j ^ (1 << i)];
        }
    }
}

template <typename T>
void subset_fzt(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    int k = std::bit_width(a.size());
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if (j >> i & 1) a[j] += a[j ^ (1 << i)];
        }
    }
}

template <typename T>
void subset_fmt(std::vector<T>& a) {
    assert(std::has_single_bit(a.size()));
    int k = std::bit_width(a.size());
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if (j >> i & 1) a[j] -= a[j ^ (1 << i)];
        }
    }
}
