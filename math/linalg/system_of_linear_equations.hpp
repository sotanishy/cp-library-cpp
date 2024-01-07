#pragma once
#include <cassert>
#include <vector>

#include "matrix.hpp"

template <typename T>
std::vector<std::vector<T>> solve_system(const Matrix<T> A,
                                         const std::vector<T>& b) {
    const int m = A.row(), n = A.col();
    assert(m == (int)b.size());
    Matrix<T> bb(m, 1);
    for (int i = 0; i < m; ++i) bb[i][0] = b[i];
    auto sol = Matrix<T>::concat(A, bb).rref();

    std::vector<bool> independent(n);
    std::vector ret(1, std::vector<T>(n));
    std::vector bases(n, std::vector<T>(n));
    for (int j = 0; j < n; ++j) bases[j][j] = 1;
    int j = 0;
    for (int i = 0; i < m; ++i) {
        for (; j < n; ++j) {
            if (Matrix<T>::eq(sol[i][j], T(1))) {
                independent[j] = true;
                for (int k = j + 1; k < n; ++k) {
                    bases[k][j] = -sol[i][k];
                }
                ret[0][j] = sol[i][n];
                break;
            }
        }
        if (j == n && !Matrix<T>::eq(sol[i][n], T(0))) return {};
    }
    for (int j = 0; j < n; ++j) {
        if (!independent[j]) ret.push_back(bases[j]);
    }
    return ret;
}