#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <initializer_list>
#include <type_traits>
#include <vector>

template <typename T>
class Matrix {
   public:
    static Matrix concat(const Matrix& A, const Matrix& B) {
        assert(A.row == B.row);
        Matrix C(A.row, A.col + B.col);
        for (int i = 0; i < A.row; ++i) {
            std::ranges::copy(A[i], C[i].begin());
            std::ranges::copy(B[i], C[i].begin() + A.col);
        }
        return C;
    }

    static Matrix I(int n) {
        Matrix ret(n);
        for (int i = 0; i < n; ++i) ret[i][i] = 1;
        return ret;
    }

    Matrix() = default;
    Matrix(int n) : Matrix(n, n) {}
    Matrix(int row, int col)
        : row(row), col(col), mat(row, std::vector<T>(col)) {}
    Matrix(const std::vector<std::vector<T>>& mat)
        : row(mat.size()), col(mat[0].size()), mat(mat) {}

    int row_size() const { return row; }
    int col_size() const { return col; }
    std::pair<int, int> shape() const { return {row, col}; }

    const std::vector<T>& operator[](int i) const { return mat[i]; }
    std::vector<T>& operator[](int i) { return mat[i]; }

    Matrix submatrix(int i0, int i1, int j0, int j1) const {
        Matrix ret(i1 - i0, j1 - j0);
        for (int i = i0; i < i1; ++i) {
            std::ranges::copy(mat[i].begin() + j0, mat[i].begin() + j1,
                              ret.mat[i - i0].begin());
        }
        return ret;
    }

    // --- binary operations with matrix ---

    Matrix& operator+=(const Matrix& rhs) {
        assert(shape() == rhs.shape());
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                mat[i][j] += rhs[i][j];
            }
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& rhs) {
        assert(shape() == rhs.shape());
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                mat[i][j] -= rhs[i][j];
            }
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& rhs) {
        assert(col == rhs.row);
        Matrix res(row, rhs.col);
        for (int i = 0; i < row; ++i) {
            for (int k = 0; k < col; ++k) {
                for (int j = 0; j < rhs.col; ++j) {
                    res[i][j] += mat[i][k] * rhs.mat[k][j];
                }
            }
        }
        return *this = res;
    }

    Matrix operator+(const Matrix& rhs) const { return Matrix(*this) += rhs; }
    Matrix operator-(const Matrix& rhs) const { return Matrix(*this) -= rhs; }
    Matrix operator*(const Matrix& rhs) const { return Matrix(*this) *= rhs; }

    constexpr bool operator==(const Matrix& rhs) const {
        if (shape() != rhs.shape()) return false;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (!eq(mat[i][j], rhs.mat[i][j])) return false;
            }
        }
        return true;
    }

    // --- scalar multiplication ---

    Matrix& operator*=(const T& rhs) {
        for (auto& row : mat) {
            for (auto& x : row) x *= rhs;
        }
        return *this;
    }
    Matrix& operator/=(const T& rhs) { return *this /= rhs; }

    Matrix operator*(const T& rhs) const { return Matrix(*this) *= rhs; }
    Matrix operator/(const T& rhs) const { return Matrix(*this) /= rhs; }

    // --- other operations for general matrices ---

    Matrix operator-() const {
        Matrix ret(*this);
        for (auto& row : ret.mat) {
            for (auto& x : row) x = -x;
        }
        return ret;
    }

    Matrix transpose() const {
        Matrix ret(col, row);
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                ret[i][j] = mat[j][i];
            }
        }
        return ret;
    }

    void reduce() {
        int pivot = 0;
        for (int j = 0; j < col; ++j) {
            int i = pivot;
            while (i < row && eq(mat[i][j], T(0))) ++i;
            if (i == row) continue;

            if (i != pivot) mat[i].swap(mat[pivot]);

            T pinv = T(1) / mat[pivot][j];
            for (int l = j; l < col; ++l) mat[pivot][l] *= pinv;

            for (int k = 0; k < row; ++k) {
                if (k == pivot) continue;
                T v = mat[k][j];
                for (int l = j; l < col; ++l) {
                    mat[k][l] -= mat[pivot][l] * v;
                }
            }

            ++pivot;
        }
    }

    int rank() const {
        auto A = *this;
        A.reduce();
        for (int i = 0; i < row; ++i) {
            bool nonzero = false;
            for (int j = 0; j < col; ++j) {
                if (!eq(A[i][j], T(0))) {
                    nonzero = true;
                    break;
                }
            }
            if (!nonzero) return i;
        }
        return row;
    }

    // --- other operations for square matrices ---

    void assert_square() const { assert(row == col); }

    Matrix pow(long long k) const {
        assert_square();
        auto ret = I(row);
        auto A = *this;
        while (k > 0) {
            if (k & 1) ret *= A;
            A *= A;
            k >>= 1;
        }
        return ret;
    }

    T det() const {
        assert_square();
        auto A = *this;
        T ret = 1;
        for (int j = 0; j < col; ++j) {
            int i = j;
            while (i < row && eq(A[i][j], T(0))) ++i;
            if (i == row) return 0;

            if (i != j) {
                A[i].swap(A[j]);
                ret = -ret;
            }

            T p = A[j][j];
            ret *= p;
            auto pinv = T(1) / p;
            for (int l = j; l < col; ++l) A[j][l] *= pinv;

            for (int k = j + 1; k < row; ++k) {
                T v = A[k][j];
                for (int l = j; l < col; ++l) {
                    A[k][l] -= A[j][l] * v;
                }
            }
        }
        return ret;
    }

    Matrix inv() const {
        assert_square();
        auto IB = concat(*this, I(row));
        IB.reduce();
        assert(IB.submatrix(0, row, 0, col) == I(row));
        return IB.submatrix(0, row, col, 2 * col);
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
    int row, col;
    std::vector<std::vector<T>> mat;
};
