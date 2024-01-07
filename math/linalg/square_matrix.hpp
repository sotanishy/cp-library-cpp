#pragma once
#include <algorithm>
#include <cassert>
#include <initializer_list>

#include "matrix.hpp"

template <typename T>
class SquareMatrix : public Matrix<T> {
    using Matrix<T>::Matrix;
    using Matrix<T>::eq;
    using Matrix<T>::n;

   public:
    static SquareMatrix I(int n) {
        SquareMatrix ret(n);
        for (int i = 0; i < n; ++i) ret[i][i] = 1;
        return ret;
    }

    SquareMatrix() = default;
    explicit SquareMatrix(int n) : Matrix<T>(n, n) {}
    SquareMatrix(const Matrix<T>& mat) : Matrix<T>(mat) {
        assert(Matrix<T>::m == n);
    }
    SquareMatrix(std::initializer_list<std::initializer_list<T>> list)
        : Matrix<T>(list) {
        assert(Matrix<T>::m == n);
    }

    SquareMatrix pow(long long k) const {
        auto ret = I(n);
        auto A(*this);
        while (k > 0) {
            if (k & 1) ret = ret.matmul(A);
            A = A.matmul(A);
            k >>= 1;
        }
        return ret;
    }

    T det() const {
        SquareMatrix A(*this);
        T ret = 1;
        for (int j = 0; j < n; ++j) {
            int i = j;
            while (i < n && eq(A[i][j], T(0))) ++i;
            if (i == n) return 0;

            if (i != j) {
                A[i].swap(A[j]);
                ret = -ret;
            }

            T p = A[j][j];
            ret *= p;
            for (int l = j; l < n; ++l) A[j][l] /= p;

            for (int k = j + 1; k < n; ++k) {
                T v = A[k][j];
                for (int l = j; l < n; ++l) {
                    A[k][l] -= A[j][l] * v;
                }
            }
        }
        return ret;
    }

    SquareMatrix inv() const {
        assert(!eq(det(), T(0)));
        auto IB = Matrix<T>::concat(*this, I(n)).rref();
        SquareMatrix B(n);
        for (int i = 0; i < n; ++i) {
            std::copy(IB[i].begin() + n, IB[i].end(), B[i].begin());
        }
        return B;
    }
};