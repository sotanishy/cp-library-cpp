---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/linalg/matrix.hpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/system_of_linear_equations.test.cpp
    title: test/yosupo/system_of_linear_equations.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/linalg/system_of_linear_equations.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"math/linalg/matrix.hpp\"\n#include <algorithm>\n\
    #line 4 \"math/linalg/matrix.hpp\"\n#include <cmath>\n#include <initializer_list>\n\
    #include <type_traits>\n#line 8 \"math/linalg/matrix.hpp\"\n\ntemplate <typename\
    \ T>\nclass Matrix {\n   public:\n    static Matrix concat(const Matrix& A, const\
    \ Matrix& B) {\n        assert(A.m == B.m);\n        Matrix C(A.m, A.n + B.n);\n\
    \        for (int i = 0; i < A.m; ++i) {\n            std::ranges::copy(A[i],\
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
    \    for (int k = 0; k < n; ++k) {\n                for (int j = 0; j < B.n; ++j)\
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
    \ mat;\n    int m, n;\n};\n#line 6 \"math/linalg/system_of_linear_equations.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::vector<T>> solve_system(const Matrix<T>\
    \ A,\n                                         const std::vector<T>& b) {\n  \
    \  const int m = A.row(), n = A.col();\n    assert(m == (int)b.size());\n    Matrix<T>\
    \ bb(m, 1);\n    for (int i = 0; i < m; ++i) bb[i][0] = b[i];\n    auto sol =\
    \ Matrix<T>::concat(A, bb).rref();\n\n    std::vector<bool> independent(n);\n\
    \    std::vector ret(1, std::vector<T>(n));\n    std::vector bases(n, std::vector<T>(n));\n\
    \    for (int j = 0; j < n; ++j) bases[j][j] = 1;\n    int j = 0;\n    for (int\
    \ i = 0; i < m; ++i) {\n        for (; j < n; ++j) {\n            if (Matrix<T>::eq(sol[i][j],\
    \ T(1))) {\n                independent[j] = true;\n                for (int k\
    \ = j + 1; k < n; ++k) {\n                    bases[k][j] = -sol[i][k];\n    \
    \            }\n                ret[0][j] = sol[i][n];\n                break;\n\
    \            }\n        }\n        if (j == n && !Matrix<T>::eq(sol[i][n], T(0)))\
    \ return {};\n    }\n    for (int j = 0; j < n; ++j) {\n        if (!independent[j])\
    \ ret.push_back(bases[j]);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"matrix.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::vector<T>> solve_system(const Matrix<T>\
    \ A,\n                                         const std::vector<T>& b) {\n  \
    \  const int m = A.row(), n = A.col();\n    assert(m == (int)b.size());\n    Matrix<T>\
    \ bb(m, 1);\n    for (int i = 0; i < m; ++i) bb[i][0] = b[i];\n    auto sol =\
    \ Matrix<T>::concat(A, bb).rref();\n\n    std::vector<bool> independent(n);\n\
    \    std::vector ret(1, std::vector<T>(n));\n    std::vector bases(n, std::vector<T>(n));\n\
    \    for (int j = 0; j < n; ++j) bases[j][j] = 1;\n    int j = 0;\n    for (int\
    \ i = 0; i < m; ++i) {\n        for (; j < n; ++j) {\n            if (Matrix<T>::eq(sol[i][j],\
    \ T(1))) {\n                independent[j] = true;\n                for (int k\
    \ = j + 1; k < n; ++k) {\n                    bases[k][j] = -sol[i][k];\n    \
    \            }\n                ret[0][j] = sol[i][n];\n                break;\n\
    \            }\n        }\n        if (j == n && !Matrix<T>::eq(sol[i][n], T(0)))\
    \ return {};\n    }\n    for (int j = 0; j < n; ++j) {\n        if (!independent[j])\
    \ ret.push_back(bases[j]);\n    }\n    return ret;\n}"
  dependsOn:
  - math/linalg/matrix.hpp
  isVerificationFile: false
  path: math/linalg/system_of_linear_equations.hpp
  requiredBy: []
  timestamp: '2024-03-02 18:46:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/system_of_linear_equations.test.cpp
documentation_of: math/linalg/system_of_linear_equations.hpp
layout: document
title: System of Linear Equations
---

## Description

連立一次方程式を解く．

## Operations

- `vector<vector<T>> solve_system(Matrix<T> A, vector<T> b)`
    - $Ax = b$ の解を返す．返り値を `sol` としたとき，`sol[0]` は解の1つ，`sol[1:]` は解空間の基底である．解がないときは空リストを返す．
    - 時間計算量: $O(mn^2)$
