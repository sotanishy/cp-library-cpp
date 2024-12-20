---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/linalg/characteristic_polynomial.hpp
    title: Characteristic Polynomial
  - icon: ':heavy_check_mark:'
    path: math/linalg/system_of_linear_equations.hpp
    title: System of Linear Equations
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inverse_matrix.test.cpp
    title: test/yosupo/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_product.test.cpp
    title: test/yosupo/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_rank.test.cpp
    title: test/yosupo/matrix_rank.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_matrix.test.cpp
    title: test/yosupo/pow_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/system_of_linear_equations.test.cpp
    title: test/yosupo/system_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/linalg/matrix.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <initializer_list>\n#include <type_traits>\n\
    #include <vector>\n\ntemplate <typename T>\nclass Matrix {\n   public:\n    static\
    \ Matrix concat(const Matrix& A, const Matrix& B) {\n        assert(A.row == B.row);\n\
    \        Matrix C(A.row, A.col + B.col);\n        for (int i = 0; i < A.row; ++i)\
    \ {\n            std::ranges::copy(A[i], C[i].begin());\n            std::ranges::copy(B[i],\
    \ C[i].begin() + A.col);\n        }\n        return C;\n    }\n\n    static Matrix\
    \ I(int n) {\n        Matrix ret(n);\n        for (int i = 0; i < n; ++i) ret[i][i]\
    \ = 1;\n        return ret;\n    }\n\n    Matrix() = default;\n    Matrix(int\
    \ n) : Matrix(n, n) {}\n    Matrix(int row, int col)\n        : row(row), col(col),\
    \ mat(row, std::vector<T>(col)) {}\n    Matrix(const std::vector<std::vector<T>>&\
    \ mat)\n        : row(mat.size()), col(mat[0].size()), mat(mat) {}\n\n    int\
    \ row_size() const { return row; }\n    int col_size() const { return col; }\n\
    \    std::pair<int, int> shape() const { return {row, col}; }\n\n    const std::vector<T>&\
    \ operator[](int i) const { return mat[i]; }\n    std::vector<T>& operator[](int\
    \ i) { return mat[i]; }\n\n    Matrix submatrix(int i0, int i1, int j0, int j1)\
    \ const {\n        Matrix ret(i1 - i0, j1 - j0);\n        for (int i = i0; i <\
    \ i1; ++i) {\n            std::ranges::copy(mat[i].begin() + j0, mat[i].begin()\
    \ + j1,\n                              ret.mat[i - i0].begin());\n        }\n\
    \        return ret;\n    }\n\n    // --- binary operations with matrix ---\n\n\
    \    Matrix& operator+=(const Matrix& rhs) {\n        assert(shape() == rhs.shape());\n\
    \        for (int i = 0; i < row; ++i) {\n            for (int j = 0; j < col;\
    \ ++j) {\n                mat[i][j] += rhs[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n    Matrix& operator-=(const Matrix& rhs) {\n \
    \       assert(shape() == rhs.shape());\n        for (int i = 0; i < row; ++i)\
    \ {\n            for (int j = 0; j < col; ++j) {\n                mat[i][j] -=\
    \ rhs[i][j];\n            }\n        }\n        return *this;\n    }\n    Matrix&\
    \ operator*=(const Matrix& rhs) {\n        assert(col == rhs.row);\n        Matrix\
    \ res(row, rhs.col);\n        for (int i = 0; i < row; ++i) {\n            for\
    \ (int k = 0; k < col; ++k) {\n                for (int j = 0; j < rhs.col; ++j)\
    \ {\n                    res[i][j] += mat[i][k] * rhs.mat[k][j];\n           \
    \     }\n            }\n        }\n        return *this = res;\n    }\n\n    Matrix\
    \ operator+(const Matrix& rhs) const { return Matrix(*this) += rhs; }\n    Matrix\
    \ operator-(const Matrix& rhs) const { return Matrix(*this) -= rhs; }\n    Matrix\
    \ operator*(const Matrix& rhs) const { return Matrix(*this) *= rhs; }\n\n    constexpr\
    \ bool operator==(const Matrix& rhs) const {\n        if (shape() != rhs.shape())\
    \ return false;\n        for (int i = 0; i < row; ++i) {\n            for (int\
    \ j = 0; j < col; ++j) {\n                if (!eq(mat[i][j], rhs.mat[i][j])) return\
    \ false;\n            }\n        }\n        return true;\n    }\n\n    // ---\
    \ scalar multiplication ---\n\n    Matrix& operator*=(const T& rhs) {\n      \
    \  for (auto& row : mat) {\n            for (auto& x : row) x *= rhs;\n      \
    \  }\n        return *this;\n    }\n    Matrix& operator/=(const T& rhs) { return\
    \ *this /= rhs; }\n\n    Matrix operator*(const T& rhs) const { return Matrix(*this)\
    \ *= rhs; }\n    Matrix operator/(const T& rhs) const { return Matrix(*this) /=\
    \ rhs; }\n\n    // --- other operations for general matrices ---\n\n    Matrix\
    \ operator-() const {\n        Matrix ret(*this);\n        for (auto& row : ret.mat)\
    \ {\n            for (auto& x : row) x = -x;\n        }\n        return ret;\n\
    \    }\n\n    Matrix transpose() const {\n        Matrix ret(col, row);\n    \
    \    for (int i = 0; i < col; ++i) {\n            for (int j = 0; j < row; ++j)\
    \ {\n                ret[i][j] = mat[j][i];\n            }\n        }\n      \
    \  return ret;\n    }\n\n    void reduce() {\n        int pivot = 0;\n       \
    \ for (int j = 0; j < col; ++j) {\n            int i = pivot;\n            while\
    \ (i < row && eq(mat[i][j], T(0))) ++i;\n            if (i == row) continue;\n\
    \n            if (i != pivot) mat[i].swap(mat[pivot]);\n\n            T pinv =\
    \ T(1) / mat[pivot][j];\n            for (int l = j; l < col; ++l) mat[pivot][l]\
    \ *= pinv;\n\n            for (int k = 0; k < row; ++k) {\n                if\
    \ (k == pivot) continue;\n                T v = mat[k][j];\n                for\
    \ (int l = j; l < col; ++l) {\n                    mat[k][l] -= mat[pivot][l]\
    \ * v;\n                }\n            }\n\n            ++pivot;\n        }\n\
    \    }\n\n    int rank() const {\n        auto A = *this;\n        A.reduce();\n\
    \        for (int i = 0; i < row; ++i) {\n            bool nonzero = false;\n\
    \            for (int j = 0; j < col; ++j) {\n                if (!eq(A[i][j],\
    \ T(0))) {\n                    nonzero = true;\n                    break;\n\
    \                }\n            }\n            if (!nonzero) return i;\n     \
    \   }\n        return row;\n    }\n\n    // --- other operations for square matrices\
    \ ---\n\n    void assert_square() const { assert(row == col); }\n\n    Matrix\
    \ pow(long long k) const {\n        assert_square();\n        auto ret = I(row);\n\
    \        auto A = *this;\n        while (k > 0) {\n            if (k & 1) ret\
    \ *= A;\n            A *= A;\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    T det() const {\n        assert_square();\n        auto A\
    \ = *this;\n        T ret = 1;\n        for (int j = 0; j < col; ++j) {\n    \
    \        int i = j;\n            while (i < row && eq(A[i][j], T(0))) ++i;\n \
    \           if (i == row) return 0;\n\n            if (i != j) {\n           \
    \     A[i].swap(A[j]);\n                ret = -ret;\n            }\n\n       \
    \     T p = A[j][j];\n            ret *= p;\n            auto pinv = T(1) / p;\n\
    \            for (int l = j; l < col; ++l) A[j][l] *= pinv;\n\n            for\
    \ (int k = j + 1; k < row; ++k) {\n                T v = A[k][j];\n          \
    \      for (int l = j; l < col; ++l) {\n                    A[k][l] -= A[j][l]\
    \ * v;\n                }\n            }\n        }\n        return ret;\n   \
    \ }\n\n    Matrix inv() const {\n        assert_square();\n        auto IB = concat(*this,\
    \ I(row));\n        IB.reduce();\n        assert(IB.submatrix(0, row, 0, col)\
    \ == I(row));\n        return IB.submatrix(0, row, col, 2 * col);\n    }\n\n \
    \   template <typename U,\n              typename std::enable_if<std::is_floating_point<U>::value>::type*\
    \ =\n                  nullptr>\n    static constexpr bool eq(U a, U b) {\n  \
    \      return std::abs(a - b) < 1e-8;\n    }\n\n    template <typename U, typename\
    \ std::enable_if<!std::is_floating_point<\n                              U>::value>::type*\
    \ = nullptr>\n    static constexpr bool eq(U a, U b) {\n        return a == b;\n\
    \    }\n\n   protected:\n    int row, col;\n    std::vector<std::vector<T>> mat;\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <initializer_list>\n#include <type_traits>\n#include <vector>\n\ntemplate\
    \ <typename T>\nclass Matrix {\n   public:\n    static Matrix concat(const Matrix&\
    \ A, const Matrix& B) {\n        assert(A.row == B.row);\n        Matrix C(A.row,\
    \ A.col + B.col);\n        for (int i = 0; i < A.row; ++i) {\n            std::ranges::copy(A[i],\
    \ C[i].begin());\n            std::ranges::copy(B[i], C[i].begin() + A.col);\n\
    \        }\n        return C;\n    }\n\n    static Matrix I(int n) {\n       \
    \ Matrix ret(n);\n        for (int i = 0; i < n; ++i) ret[i][i] = 1;\n       \
    \ return ret;\n    }\n\n    Matrix() = default;\n    Matrix(int n) : Matrix(n,\
    \ n) {}\n    Matrix(int row, int col)\n        : row(row), col(col), mat(row,\
    \ std::vector<T>(col)) {}\n    Matrix(const std::vector<std::vector<T>>& mat)\n\
    \        : row(mat.size()), col(mat[0].size()), mat(mat) {}\n\n    int row_size()\
    \ const { return row; }\n    int col_size() const { return col; }\n    std::pair<int,\
    \ int> shape() const { return {row, col}; }\n\n    const std::vector<T>& operator[](int\
    \ i) const { return mat[i]; }\n    std::vector<T>& operator[](int i) { return\
    \ mat[i]; }\n\n    Matrix submatrix(int i0, int i1, int j0, int j1) const {\n\
    \        Matrix ret(i1 - i0, j1 - j0);\n        for (int i = i0; i < i1; ++i)\
    \ {\n            std::ranges::copy(mat[i].begin() + j0, mat[i].begin() + j1,\n\
    \                              ret.mat[i - i0].begin());\n        }\n        return\
    \ ret;\n    }\n\n    // --- binary operations with matrix ---\n\n    Matrix& operator+=(const\
    \ Matrix& rhs) {\n        assert(shape() == rhs.shape());\n        for (int i\
    \ = 0; i < row; ++i) {\n            for (int j = 0; j < col; ++j) {\n        \
    \        mat[i][j] += rhs[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n    Matrix& operator-=(const Matrix& rhs) {\n        assert(shape() ==\
    \ rhs.shape());\n        for (int i = 0; i < row; ++i) {\n            for (int\
    \ j = 0; j < col; ++j) {\n                mat[i][j] -= rhs[i][j];\n          \
    \  }\n        }\n        return *this;\n    }\n    Matrix& operator*=(const Matrix&\
    \ rhs) {\n        assert(col == rhs.row);\n        Matrix res(row, rhs.col);\n\
    \        for (int i = 0; i < row; ++i) {\n            for (int k = 0; k < col;\
    \ ++k) {\n                for (int j = 0; j < rhs.col; ++j) {\n              \
    \      res[i][j] += mat[i][k] * rhs.mat[k][j];\n                }\n          \
    \  }\n        }\n        return *this = res;\n    }\n\n    Matrix operator+(const\
    \ Matrix& rhs) const { return Matrix(*this) += rhs; }\n    Matrix operator-(const\
    \ Matrix& rhs) const { return Matrix(*this) -= rhs; }\n    Matrix operator*(const\
    \ Matrix& rhs) const { return Matrix(*this) *= rhs; }\n\n    constexpr bool operator==(const\
    \ Matrix& rhs) const {\n        if (shape() != rhs.shape()) return false;\n  \
    \      for (int i = 0; i < row; ++i) {\n            for (int j = 0; j < col; ++j)\
    \ {\n                if (!eq(mat[i][j], rhs.mat[i][j])) return false;\n      \
    \      }\n        }\n        return true;\n    }\n\n    // --- scalar multiplication\
    \ ---\n\n    Matrix& operator*=(const T& rhs) {\n        for (auto& row : mat)\
    \ {\n            for (auto& x : row) x *= rhs;\n        }\n        return *this;\n\
    \    }\n    Matrix& operator/=(const T& rhs) { return *this /= rhs; }\n\n    Matrix\
    \ operator*(const T& rhs) const { return Matrix(*this) *= rhs; }\n    Matrix operator/(const\
    \ T& rhs) const { return Matrix(*this) /= rhs; }\n\n    // --- other operations\
    \ for general matrices ---\n\n    Matrix operator-() const {\n        Matrix ret(*this);\n\
    \        for (auto& row : ret.mat) {\n            for (auto& x : row) x = -x;\n\
    \        }\n        return ret;\n    }\n\n    Matrix transpose() const {\n   \
    \     Matrix ret(col, row);\n        for (int i = 0; i < col; ++i) {\n       \
    \     for (int j = 0; j < row; ++j) {\n                ret[i][j] = mat[j][i];\n\
    \            }\n        }\n        return ret;\n    }\n\n    void reduce() {\n\
    \        int pivot = 0;\n        for (int j = 0; j < col; ++j) {\n           \
    \ int i = pivot;\n            while (i < row && eq(mat[i][j], T(0))) ++i;\n  \
    \          if (i == row) continue;\n\n            if (i != pivot) mat[i].swap(mat[pivot]);\n\
    \n            T pinv = T(1) / mat[pivot][j];\n            for (int l = j; l <\
    \ col; ++l) mat[pivot][l] *= pinv;\n\n            for (int k = 0; k < row; ++k)\
    \ {\n                if (k == pivot) continue;\n                T v = mat[k][j];\n\
    \                for (int l = j; l < col; ++l) {\n                    mat[k][l]\
    \ -= mat[pivot][l] * v;\n                }\n            }\n\n            ++pivot;\n\
    \        }\n    }\n\n    int rank() const {\n        auto A = *this;\n       \
    \ A.reduce();\n        for (int i = 0; i < row; ++i) {\n            bool nonzero\
    \ = false;\n            for (int j = 0; j < col; ++j) {\n                if (!eq(A[i][j],\
    \ T(0))) {\n                    nonzero = true;\n                    break;\n\
    \                }\n            }\n            if (!nonzero) return i;\n     \
    \   }\n        return row;\n    }\n\n    // --- other operations for square matrices\
    \ ---\n\n    void assert_square() const { assert(row == col); }\n\n    Matrix\
    \ pow(long long k) const {\n        assert_square();\n        auto ret = I(row);\n\
    \        auto A = *this;\n        while (k > 0) {\n            if (k & 1) ret\
    \ *= A;\n            A *= A;\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    T det() const {\n        assert_square();\n        auto A\
    \ = *this;\n        T ret = 1;\n        for (int j = 0; j < col; ++j) {\n    \
    \        int i = j;\n            while (i < row && eq(A[i][j], T(0))) ++i;\n \
    \           if (i == row) return 0;\n\n            if (i != j) {\n           \
    \     A[i].swap(A[j]);\n                ret = -ret;\n            }\n\n       \
    \     T p = A[j][j];\n            ret *= p;\n            auto pinv = T(1) / p;\n\
    \            for (int l = j; l < col; ++l) A[j][l] *= pinv;\n\n            for\
    \ (int k = j + 1; k < row; ++k) {\n                T v = A[k][j];\n          \
    \      for (int l = j; l < col; ++l) {\n                    A[k][l] -= A[j][l]\
    \ * v;\n                }\n            }\n        }\n        return ret;\n   \
    \ }\n\n    Matrix inv() const {\n        assert_square();\n        auto IB = concat(*this,\
    \ I(row));\n        IB.reduce();\n        assert(IB.submatrix(0, row, 0, col)\
    \ == I(row));\n        return IB.submatrix(0, row, col, 2 * col);\n    }\n\n \
    \   template <typename U,\n              typename std::enable_if<std::is_floating_point<U>::value>::type*\
    \ =\n                  nullptr>\n    static constexpr bool eq(U a, U b) {\n  \
    \      return std::abs(a - b) < 1e-8;\n    }\n\n    template <typename U, typename\
    \ std::enable_if<!std::is_floating_point<\n                              U>::value>::type*\
    \ = nullptr>\n    static constexpr bool eq(U a, U b) {\n        return a == b;\n\
    \    }\n\n   protected:\n    int row, col;\n    std::vector<std::vector<T>> mat;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: math/linalg/matrix.hpp
  requiredBy:
  - math/linalg/characteristic_polynomial.hpp
  - math/linalg/system_of_linear_equations.hpp
  timestamp: '2024-03-02 20:34:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_product.test.cpp
  - test/yosupo/system_of_linear_equations.test.cpp
  - test/yosupo/inverse_matrix.test.cpp
  - test/yosupo/matrix_rank.test.cpp
  - test/yosupo/pow_of_matrix.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/characteristic_polynomial.test.cpp
documentation_of: math/linalg/matrix.hpp
layout: document
title: Matrix
---

## Description

行列を表す．

## Operations

- `Matrix(int n)`
    - $n \times n$ 零行列を構築する
- `Matrix(int row, int col)`
    - $\mathit{row} \times \mathit{col}$ 零行列を構築する
- `Matrix(vector<vector<T>> mat)`
    - `mat` の要素で行列を構築する
- `static Matrix concat(Matrix A, Matrix B)`
    - $A$ と $B$ を結合した行列を返す
- `static Matrix I(int n)`
    - $n \times n$ 単位行列を返す
- `Matrix operator*(Matrix rhs)`
    - 行列積を計算する
    - 時間計算量: $O(n^3)$
- `Matrix transpose()`
    - 転置行列を返す
- `void reduce()`
    - 行列を掃き出す
    - 時間計算量: $O(n^3)$
- `int rank()`
    - の階数を返す
    - 時間計算量: $O(n^3)$

## Operations for Square Matrices

- `Matrix pow(long long k)`
    - 行列の $k$ 乗を返す
    - 時間計算量: $O(n^3 \log k)$
- `T det()`
    - 行列式を返す
    - 時間計算量: $O(n^3 \log k)$
- `Matrix inv()`
    - 逆行列を返す
    - 時間計算量: $O(n^3)$