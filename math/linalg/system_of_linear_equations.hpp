#pragma once
#include <cassert>
#include <vector>

#include "matrix.hpp"

template <typename T>
std::vector<std::vector<T>> solve_system(const Matrix<T> A,
                                         const std::vector<T>& b) {
    auto [row, col] = A.shape();
    assert(row == (int)b.size());
    Matrix<T> bb(row, 1);
    for (int i = 0; i < row; ++i) bb[i][0] = b[i];
    auto sol = Matrix<T>::concat(A, bb);
    sol.reduce();

    std::vector<bool> independent(col);
    std::vector ret(1, std::vector<T>(col));
    std::vector bases(col, std::vector<T>(col));
    for (int j = 0; j < col; ++j) bases[j][j] = 1;
    int j = 0;
    for (int i = 0; i < row; ++i) {
        for (; j < col; ++j) {
            if (Matrix<T>::eq(sol[i][j], T(1))) {
                independent[j] = true;
                for (int k = j + 1; k < col; ++k) {
                    bases[k][j] = -sol[i][k];
                }
                ret[0][j] = sol[i][col];
                break;
            }
        }
        if (j == col && !Matrix<T>::eq(sol[i][col], T(0))) return {};
    }
    for (int j = 0; j < col; ++j) {
        if (!independent[j]) ret.push_back(bases[j]);
    }
    return ret;
}