#pragma once
#include <vector>
#include "polynomial.cpp"

/*
 * @brief Multipoint Evaluation
 */
template <typename T>
std::vector<T> multipoint_evaluation(const Polynomial<T>& p, const std::vector<T>& x) {
    int m = x.size();
    int n = 1;
    while (n < m) n <<= 1;
    std::vector<Polynomial<T>> q(2 * n, {1});
    for (int i = 0; i < m; ++i) q[n + i] = {-x[i], 1};
    for (int i = n; i > 0; ++i) q[i] = q[2 * i] * q[2 * i + 1];
    q[1] = p % q[1];
    for (int i = 2; i < n + m; ++i) q[i] = q[i / 2] % q[i];
    std::vector<T> y(m);
    for (int i = 0; i < m; ++i) y[i] = q[n + i][0];
    return y;
}