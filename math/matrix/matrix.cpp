#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <type_traits>
#include <vector>

template <typename T>
class Matrix : public std::vector<std::vector<T>> {
   public:
    static Matrix concat(const Matrix& A, const Matrix& B) {
        assert(A.m == B.m);
        Matrix C(A.m, A.n + B.n);
        for (int i = 0; i < A.m; ++i) {
            std::copy(A[i].begin(), A[i].end(), C[i].begin());
            std::copy(B[i].begin(), B[i].end(), C[i].begin() + A.n);
        }
        return C;
    }

    Matrix() = default;
    Matrix(int m, int n) : mat(m, std::vector<T>(n)), m(m), n(n) {}
    Matrix(std::initializer_list<std::initializer_list<T>> list) {
        for (auto& l : list) mat.emplace_back(l);
        m = mat.size();
        n = mat[0].size();
    }

    Matrix& operator+=(const Matrix& rhs) {
        assert(m == rhs.m && n == rhs.n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] += rhs[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& rhs) {
        assert(m == rhs.m && n == rhs.n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mat[i][j] -= rhs[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& rhs) const { return Matrix(*this) += rhs; }
    Matrix operator-(const Matrix& rhs) const { return Matrix(*this) -= rhs; }

    Matrix transpose() const {
        Matrix ret(n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ret[i][j] = mat[j][i];
            }
        }
        return ret;
    }

    Matrix matmul(const Matrix& B) const {
        assert(n == B.m);
        Matrix ret(m, B.n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < B.n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ret[i][j] += mat[i][k] * B[k][j];
                }
            }
        }
        return ret;
    }

    Matrix rref() const {
        Matrix A(*this);
        int pivot = 0;
        for (int j = 0; j < n; ++j) {
            int i = pivot;
            while (i < m && eq(A[i][j], T(0))) ++i;
            if (i == m) continue;

            if (i != pivot) A[i].swap(A[pivot]);

            T p = A[pivot][j];
            for (int l = j; l < n; ++l) A[pivot][l] /= p;

            for (int k = 0; k < m; ++k) {
                if (k == pivot) continue;
                T v = A[k][j];
                for (int l = j; l < n; ++l) {
                    A[k][l] -= A[pivot][l] * v;
                }
            }

            ++pivot;
        }
        return A;
    }

    int rank() const {
        auto A = rref();
        for (int i = 0; i < m; ++i) {
            bool nonzero = false;
            for (int j = 0; j < n; ++j) {
                if (!eq(A[i][j], T(0))) {
                    nonzero = true;
                    break;
                }
            }
            if (!nonzero) return i;
        }
        return m;
    }

    template <typename U,
              typename std::enable_if<std::is_floating_point<U>::value>::type* =
                  nullptr>
    static constexpr bool eq(U a, U b) {
        return std::abs(a - b) < 1e-8;
    }

    template <typename U, typename std::enable_if<!std::is_floating_point<
                              U>::value>::type* = nullptr>
    static constexpr bool eq(U a, U b) {
        return a == b;
    }

   protected:
    std::vector<std::vector<T>> mat;
    int m, n;
};