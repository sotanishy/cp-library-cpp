#pragma once
#include <limits>
#include <vector>
#include "../dp/monotone_minima.hpp"

// b is convex
template <typename T>
std::vector<T> convex_min_plus_convolution(const std::vector<T>& a,
                                           const std::vector<T>& b) {
    int len = a.size() + b.size() - 1;

    auto f = [&](int i, int j) {
        if (i - j < 0 || (int)b.size() <= i - j)
            return std::numeric_limits<T>::max();
        return a[j] + b[i - j];
    };

    auto idx = monotone_minima(len, a.size(), f);
    std::vector<T> res(len);
    for (int i = 0; i < len; ++i) res[i] = f(i, idx[i]);
    return res;
}

// b is concave
template <typename T>
std::vector<T> concave_max_plus_convolution(std::vector<T> a,
                                            std::vector<T> b) {
    for (auto& x : a) x = -x;
    for (auto& x : b) x = -x;
    auto c = convex_min_plus_convolution(a, b);
    for (auto& x : c) x = -x;
    return c;
}
