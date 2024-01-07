---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/linalg/matrix.hpp
    title: Matrix
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/linalg/characteristic_polynomial.hpp
    title: Characteristic Polynomial
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inverse_matrix.test.cpp
    title: test/yosupo/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_matrix.test.cpp
    title: test/yosupo/pow_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/linalg/square_matrix.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <initializer_list>\n\n#line 4 \"math/linalg/matrix.hpp\"\
    \n#include <cmath>\n#line 6 \"math/linalg/matrix.hpp\"\n#include <type_traits>\n\
    #include <vector>\n\ntemplate <typename T>\nclass Matrix {\n   public:\n    static\
    \ Matrix concat(const Matrix& A, const Matrix& B) {\n        assert(A.m == B.m);\n\
    \        Matrix C(A.m, A.n + B.n);\n        for (int i = 0; i < A.m; ++i) {\n\
    \            std::ranges::copy(A[i], C[i].begin());\n            std::ranges::copy(B[i],\
    \ C[i].begin() + A.n);\n        }\n        return C;\n    }\n\n    Matrix() =\
    \ default;\n    Matrix(int m, int n) : mat(m, std::vector<T>(n)), m(m), n(n) {}\n\
    \    Matrix(std::initializer_list<std::initializer_list<T>> list) {\n        for\
    \ (auto& l : list) mat.emplace_back(l);\n        m = mat.size();\n        n =\
    \ mat[0].size();\n    }\n\n    int row() const { return m; }\n    int col() const\
    \ { return n; }\n\n    const std::vector<T>& operator[](int i) const { return\
    \ mat[i]; }\n    std::vector<T>& operator[](int i) { return mat[i]; }\n\n    Matrix&\
    \ operator+=(const Matrix& rhs) {\n        assert(m == rhs.m && n == rhs.n);\n\
    \        for (int i = 0; i < m; ++i) {\n            for (int j = 0; j < n; ++j)\
    \ {\n                mat[i][j] += rhs[i][j];\n            }\n        }\n     \
    \   return *this;\n    }\n\n    Matrix& operator-=(const Matrix& rhs) {\n    \
    \    assert(m == rhs.m && n == rhs.n);\n        for (int i = 0; i < m; ++i) {\n\
    \            for (int j = 0; j < n; ++j) {\n                mat[i][j] -= rhs[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix operator+(const\
    \ Matrix& rhs) const { return Matrix(*this) += rhs; }\n    Matrix operator-(const\
    \ Matrix& rhs) const { return Matrix(*this) -= rhs; }\n\n    Matrix transpose()\
    \ const {\n        Matrix ret(n, m);\n        for (int i = 0; i < n; ++i) {\n\
    \            for (int j = 0; j < m; ++j) {\n                ret[i][j] = mat[j][i];\n\
    \            }\n        }\n        return ret;\n    }\n\n    Matrix matmul(const\
    \ Matrix& B) const {\n        assert(n == B.m);\n        Matrix ret(m, B.n);\n\
    \        for (int i = 0; i < m; ++i) {\n            for (int j = 0; j < B.n; ++j)\
    \ {\n                for (int k = 0; k < n; ++k) {\n                    ret[i][j]\
    \ += mat[i][k] * B[k][j];\n                }\n            }\n        }\n     \
    \   return ret;\n    }\n\n    Matrix rref() const {\n        Matrix A(*this);\n\
    \        int pivot = 0;\n        for (int j = 0; j < n; ++j) {\n            int\
    \ i = pivot;\n            while (i < m && eq(A[i][j], T(0))) ++i;\n          \
    \  if (i == m) continue;\n\n            if (i != pivot) A[i].swap(A[pivot]);\n\
    \n            T p = A[pivot][j];\n            for (int l = j; l < n; ++l) A[pivot][l]\
    \ /= p;\n\n            for (int k = 0; k < m; ++k) {\n                if (k ==\
    \ pivot) continue;\n                T v = A[k][j];\n                for (int l\
    \ = j; l < n; ++l) {\n                    A[k][l] -= A[pivot][l] * v;\n      \
    \          }\n            }\n\n            ++pivot;\n        }\n        return\
    \ A;\n    }\n\n    int rank() const {\n        auto A = rref();\n        for (int\
    \ i = 0; i < m; ++i) {\n            bool nonzero = false;\n            for (int\
    \ j = 0; j < n; ++j) {\n                if (!eq(A[i][j], T(0))) {\n          \
    \          nonzero = true;\n                    break;\n                }\n  \
    \          }\n            if (!nonzero) return i;\n        }\n        return m;\n\
    \    }\n\n    template <typename U,\n              typename std::enable_if<std::is_floating_point<U>::value>::type*\
    \ =\n                  nullptr>\n    static constexpr bool eq(U a, U b) {\n  \
    \      return std::abs(a - b) < 1e-8;\n    }\n\n    template <typename U, typename\
    \ std::enable_if<!std::is_floating_point<\n                              U>::value>::type*\
    \ = nullptr>\n    static constexpr bool eq(U a, U b) {\n        return a == b;\n\
    \    }\n\n   protected:\n    std::vector<std::vector<T>> mat;\n    int m, n;\n\
    };\n#line 7 \"math/linalg/square_matrix.hpp\"\n\ntemplate <typename T>\nclass\
    \ SquareMatrix : public Matrix<T> {\n    using Matrix<T>::Matrix;\n    using Matrix<T>::eq;\n\
    \    using Matrix<T>::n;\n\n   public:\n    static SquareMatrix I(int n) {\n \
    \       SquareMatrix ret(n);\n        for (int i = 0; i < n; ++i) ret[i][i] =\
    \ 1;\n        return ret;\n    }\n\n    SquareMatrix() = default;\n    explicit\
    \ SquareMatrix(int n) : Matrix<T>(n, n) {}\n    SquareMatrix(const Matrix<T>&\
    \ mat) : Matrix<T>(mat) {\n        assert(Matrix<T>::m == n);\n    }\n    SquareMatrix(std::initializer_list<std::initializer_list<T>>\
    \ list)\n        : Matrix<T>(list) {\n        assert(Matrix<T>::m == n);\n   \
    \ }\n\n    SquareMatrix pow(long long k) const {\n        auto ret = I(n);\n \
    \       auto A(*this);\n        while (k > 0) {\n            if (k & 1) ret =\
    \ ret.matmul(A);\n            A = A.matmul(A);\n            k >>= 1;\n       \
    \ }\n        return ret;\n    }\n\n    T det() const {\n        SquareMatrix A(*this);\n\
    \        T ret = 1;\n        for (int j = 0; j < n; ++j) {\n            int i\
    \ = j;\n            while (i < n && eq(A[i][j], T(0))) ++i;\n            if (i\
    \ == n) return 0;\n\n            if (i != j) {\n                A[i].swap(A[j]);\n\
    \                ret = -ret;\n            }\n\n            T p = A[j][j];\n  \
    \          ret *= p;\n            for (int l = j; l < n; ++l) A[j][l] /= p;\n\n\
    \            for (int k = j + 1; k < n; ++k) {\n                T v = A[k][j];\n\
    \                for (int l = j; l < n; ++l) {\n                    A[k][l] -=\
    \ A[j][l] * v;\n                }\n            }\n        }\n        return ret;\n\
    \    }\n\n    SquareMatrix inv() const {\n        assert(!eq(det(), T(0)));\n\
    \        auto IB = Matrix<T>::concat(*this, I(n)).rref();\n        SquareMatrix\
    \ B(n);\n        for (int i = 0; i < n; ++i) {\n            std::copy(IB[i].begin()\
    \ + n, IB[i].end(), B[i].begin());\n        }\n        return B;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <initializer_list>\n\
    \n#include \"matrix.hpp\"\n\ntemplate <typename T>\nclass SquareMatrix : public\
    \ Matrix<T> {\n    using Matrix<T>::Matrix;\n    using Matrix<T>::eq;\n    using\
    \ Matrix<T>::n;\n\n   public:\n    static SquareMatrix I(int n) {\n        SquareMatrix\
    \ ret(n);\n        for (int i = 0; i < n; ++i) ret[i][i] = 1;\n        return\
    \ ret;\n    }\n\n    SquareMatrix() = default;\n    explicit SquareMatrix(int\
    \ n) : Matrix<T>(n, n) {}\n    SquareMatrix(const Matrix<T>& mat) : Matrix<T>(mat)\
    \ {\n        assert(Matrix<T>::m == n);\n    }\n    SquareMatrix(std::initializer_list<std::initializer_list<T>>\
    \ list)\n        : Matrix<T>(list) {\n        assert(Matrix<T>::m == n);\n   \
    \ }\n\n    SquareMatrix pow(long long k) const {\n        auto ret = I(n);\n \
    \       auto A(*this);\n        while (k > 0) {\n            if (k & 1) ret =\
    \ ret.matmul(A);\n            A = A.matmul(A);\n            k >>= 1;\n       \
    \ }\n        return ret;\n    }\n\n    T det() const {\n        SquareMatrix A(*this);\n\
    \        T ret = 1;\n        for (int j = 0; j < n; ++j) {\n            int i\
    \ = j;\n            while (i < n && eq(A[i][j], T(0))) ++i;\n            if (i\
    \ == n) return 0;\n\n            if (i != j) {\n                A[i].swap(A[j]);\n\
    \                ret = -ret;\n            }\n\n            T p = A[j][j];\n  \
    \          ret *= p;\n            for (int l = j; l < n; ++l) A[j][l] /= p;\n\n\
    \            for (int k = j + 1; k < n; ++k) {\n                T v = A[k][j];\n\
    \                for (int l = j; l < n; ++l) {\n                    A[k][l] -=\
    \ A[j][l] * v;\n                }\n            }\n        }\n        return ret;\n\
    \    }\n\n    SquareMatrix inv() const {\n        assert(!eq(det(), T(0)));\n\
    \        auto IB = Matrix<T>::concat(*this, I(n)).rref();\n        SquareMatrix\
    \ B(n);\n        for (int i = 0; i < n; ++i) {\n            std::copy(IB[i].begin()\
    \ + n, IB[i].end(), B[i].begin());\n        }\n        return B;\n    }\n};"
  dependsOn:
  - math/linalg/matrix.hpp
  isVerificationFile: false
  path: math/linalg/square_matrix.hpp
  requiredBy:
  - math/linalg/characteristic_polynomial.hpp
  timestamp: '2024-01-07 21:12:19+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/characteristic_polynomial.test.cpp
  - test/yosupo/inverse_matrix.test.cpp
  - test/yosupo/pow_of_matrix.test.cpp
  - test/yosupo/matrix_det.test.cpp
documentation_of: math/linalg/square_matrix.hpp
layout: document
title: Square Matrix
---

## Description

正方行列を表す．

## Operations

- `SquareMatrix(int n)`
    - $n \times n$ 零行列を構築する
    - 時間計算量: $O(n^2)$
- `SquareMatrix(initializer_list<initializer_list<T>> list)`
    - `list` の要素で正方行列を構築する
    - 時間計算量: $O(n^2)$
- `static SquareMatrix I(int n)`
    - $n \times n$ 単位行列を返す
    - 時間計算量: $O(n^2)$
- `SquareMatrix pow(long long k)`
    - $A^k$ を返す
    - 時間計算量: $O(n^3 \log k)$
- `T det()`
    - 行列式 $\det(A)$ を返す
    - 時間計算量: $O(n^3)$
- `SquareMatrix inv()`
    - 逆行列 $A^{-1}$ を返す
    - 時間計算量: $O(n^3)$