#pragma once
#include <vector>
#include "polynomial.cpp"

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