---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/linalg/characteristic_polynomial.hpp
    title: Characteristic Polynomial
  - icon: ':heavy_check_mark:'
    path: math/linalg/square_matrix.hpp
    title: Square Matrix
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
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <initializer_list>\n#include <type_traits>\n#include <vector>\n\ntemplate\
    \ <typename T>\nclass Matrix {\n   public:\n    static Matrix concat(const Matrix&\
    \ A, const Matrix& B) {\n        assert(A.m == B.m);\n        Matrix C(A.m, A.n\
    \ + B.n);\n        for (int i = 0; i < A.m; ++i) {\n            std::ranges::copy(A[i],\
    \ C[i].begin());\n            std::ranges::copy(B[i], C[i].begin() + A.n);\n \
    \       }\n        return C;\n    }\n\n    Matrix() = default;\n    Matrix(int\
    \ m, int n) : mat(m, std::vector<T>(n)), m(m), n(n) {}\n    Matrix(std::initializer_list<std::initializer_list<T>>\
    \ list) {\n        for (auto& l : list) mat.emplace_back(l);\n        m = mat.size();\n\
    \        n = mat[0].size();\n    }\n\n    int row() const { return m; }\n    int\
    \ col() const { return n; }\n\n    const std::vector<T>& operator[](int i) const\
    \ { return mat[i]; }\n    std::vector<T>& operator[](int i) { return mat[i]; }\n\
    \n    Matrix& operator+=(const Matrix& rhs) {\n        assert(m == rhs.m && n\
    \ == rhs.n);\n        for (int i = 0; i < m; ++i) {\n            for (int j =\
    \ 0; j < n; ++j) {\n                mat[i][j] += rhs[i][j];\n            }\n \
    \       }\n        return *this;\n    }\n\n    Matrix& operator-=(const Matrix&\
    \ rhs) {\n        assert(m == rhs.m && n == rhs.n);\n        for (int i = 0; i\
    \ < m; ++i) {\n            for (int j = 0; j < n; ++j) {\n                mat[i][j]\
    \ -= rhs[i][j];\n            }\n        }\n        return *this;\n    }\n\n  \
    \  Matrix operator+(const Matrix& rhs) const { return Matrix(*this) += rhs; }\n\
    \    Matrix operator-(const Matrix& rhs) const { return Matrix(*this) -= rhs;\
    \ }\n\n    Matrix transpose() const {\n        Matrix ret(n, m);\n        for\
    \ (int i = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j) {\n     \
    \           ret[i][j] = mat[j][i];\n            }\n        }\n        return ret;\n\
    \    }\n\n    Matrix matmul(const Matrix& B) const {\n        assert(n == B.m);\n\
    \        Matrix ret(m, B.n);\n        for (int i = 0; i < m; ++i) {\n        \
    \    for (int j = 0; j < B.n; ++j) {\n                for (int k = 0; k < n; ++k)\
    \ {\n                    ret[i][j] += mat[i][k] * B[k][j];\n                }\n\
    \            }\n        }\n        return ret;\n    }\n\n    Matrix rref() const\
    \ {\n        Matrix A(*this);\n        int pivot = 0;\n        for (int j = 0;\
    \ j < n; ++j) {\n            int i = pivot;\n            while (i < m && eq(A[i][j],\
    \ T(0))) ++i;\n            if (i == m) continue;\n\n            if (i != pivot)\
    \ A[i].swap(A[pivot]);\n\n            T p = A[pivot][j];\n            for (int\
    \ l = j; l < n; ++l) A[pivot][l] /= p;\n\n            for (int k = 0; k < m; ++k)\
    \ {\n                if (k == pivot) continue;\n                T v = A[k][j];\n\
    \                for (int l = j; l < n; ++l) {\n                    A[k][l] -=\
    \ A[pivot][l] * v;\n                }\n            }\n\n            ++pivot;\n\
    \        }\n        return A;\n    }\n\n    int rank() const {\n        auto A\
    \ = rref();\n        for (int i = 0; i < m; ++i) {\n            bool nonzero =\
    \ false;\n            for (int j = 0; j < n; ++j) {\n                if (!eq(A[i][j],\
    \ T(0))) {\n                    nonzero = true;\n                    break;\n\
    \                }\n            }\n            if (!nonzero) return i;\n     \
    \   }\n        return m;\n    }\n\n    template <typename U,\n              typename\
    \ std::enable_if<std::is_floating_point<U>::value>::type* =\n                \
    \  nullptr>\n    static constexpr bool eq(U a, U b) {\n        return std::abs(a\
    \ - b) < 1e-8;\n    }\n\n    template <typename U, typename std::enable_if<!std::is_floating_point<\n\
    \                              U>::value>::type* = nullptr>\n    static constexpr\
    \ bool eq(U a, U b) {\n        return a == b;\n    }\n\n   protected:\n    std::vector<std::vector<T>>\
    \ mat;\n    int m, n;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/linalg/matrix.hpp
  requiredBy:
  - math/linalg/characteristic_polynomial.hpp
  - math/linalg/square_matrix.hpp
  - math/linalg/system_of_linear_equations.hpp
  timestamp: '2024-01-07 21:12:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_product.test.cpp
  - test/yosupo/characteristic_polynomial.test.cpp
  - test/yosupo/inverse_matrix.test.cpp
  - test/yosupo/pow_of_matrix.test.cpp
  - test/yosupo/system_of_linear_equations.test.cpp
  - test/yosupo/matrix_det.test.cpp
documentation_of: math/linalg/matrix.hpp
layout: document
title: Matrix
---

## Description

行列を表す．

## Operations

- `Matrix(int m, int n)`
    - $m \times n$ 零行列を構築する
    - 時間計算量: $O(mn)$
- `Matrix(initializer_list<initializer_list<T>> list)`
    - `list` の要素で行列を構築する
    - 時間計算量: $O(mn)$
- `static Matrix concatenate(const Matrix& A, const Matrix& B)`
    - $A$ と $B$ を結合した行列を返す
    - 時間計算量: $O(m(n_A + n_B))$
- `Matrix transpose()`
    - 転置行列を返す
    - 時間計算量: $O(mn)$
- `Matrix matmul(const Matrix& B)`
    - 行列積 $AB$ を返す
    - 時間計算量: $O(m_A n_A n_B)$
- `Matrix rref()`
    - $A$ に対して掃き出し法を行った結果を返す
    - 時間計算量: $O(mn^2)$
- `int rank()`
    - $A$ の階数を返す
    - 時間計算量: $O(mn^2)$