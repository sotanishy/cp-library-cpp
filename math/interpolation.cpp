#pragma once
#include <vector>
#include "polynomial.cpp"

template <typename T>
Polynomial<T> interpolate(const std::vector<T>& x, const std::vector<T>& y) {
    assert(x.size() == y.size());
    int n = x.size();
    std::vector<T> prod(n + 1);
    prod[0] = 1;
    for (int i = 0; i < n; ++i) {
        std::vector<T> nxt(n + 1);
        for (int j = 0; j < n; ++j) {
            nxt[j + 1] = prod[j];
            nxt[j] -= x[i] * prod[j];
        }
        prod = std::move(nxt);
    }

    Polynomial<T> poly(n);
    for (int i = 0; i < n; ++i) {
        T q = 1;
        for (int j = 0; j < n; ++j) {
            if (i != j) q *= x[i] - x[j];
        }
        q = y[i] / q;

        auto tmp = prod;
        for (int j = n - 1; j >= 0; --j) {
            poly[j] += q * tmp[j + 1];
            tmp[j] += tmp[j + 1] * x[i];
        }
    }
    return poly;
}

/*
O(n^2 log(n)) version
might be faster than O(n^2) algorithm


template <typename T>
Polynomial<T> interpolate(const std::vector<T>& x, const std::vector<T>& y) {
    assert(x.size() == y.size());
    int n = 1;
    while (n < (int) x.size()) n <<= 1;
    std::vector<Polynomial<T>> prod(2 * n, {1});
    for (int i = 0; i < (int) x.size(); ++i) prod[n + i] = {-x[i], 1};
    for (int i = n - 1; i > 0; --i) prod[i] = prod[2 * i] * prod[2 * i + 1];
    auto f = prod[1].diff();
    std::vector<Polynomial<T>> poly(2 * n, {0});
    for (int i = 0; i < (int) x.size(); ++i) poly[n + i] = {y[i] / f(x[i])};
    for (int i = n - 1; i > 0; --i) poly[i] = poly[2 * i] * prod[2 * i + 1] + poly[2 * i + 1] * prod[2 * i];
    return poly[1];
}
*/