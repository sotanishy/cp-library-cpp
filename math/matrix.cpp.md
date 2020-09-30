---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/matrix.md
    document_title: Matrix
    links: []
  bundledCode: "#line 1 \"math/matrix.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Matrix\n * @docs docs/math/matrix.md\n */\ntemplate <typename T>\nstruct Matrix\
    \ {\n    std::vector<std::vector<T>> A;\n    int m, n;\n\n    const double EPS\
    \ = 1e-8;\n\n    Matrix() = default;\n    Matrix(int m, int n) : A(m, std::vector<T>(n)),\
    \ m(m), n(n) {}\n    Matrix(std::initializer_list<std::initializer_list<T>> list)\
    \ {\n        for (auto& l : list) {\n            A.push_back(std::vector<T>(l.begin(),\
    \ l.end()));\n        }\n        m = A.size();\n        n = A[0].size();\n   \
    \ }\n\n    static Matrix I(int n) {\n        Matrix ret(n, n);\n        for (int\
    \ i = 0; i < n; ++i) ret[i][i] = 1;\n        return ret;\n    }\n\n    static\
    \ Matrix concatenate(const Matrix& A, const Matrix& B) {\n        assert(A.m ==\
    \ B.m);\n        Matrix C(A.m, A.n + B.n);\n        for (int i = 0; i < A.m; ++i)\
    \ {\n            for (int j = 0; j < A.n; ++j) {\n                C[i][j] = A[i][j];\n\
    \            }\n            for (int j = 0; j < B.n; ++j) {\n                C[i][A.n\
    \ + j] = B[i][j];\n            }\n        }\n        return C;\n    }\n\n    const\
    \ std::vector<T>& operator[](int i) const {\n        return A[i];\n    }\n\n \
    \   std::vector<T>& operator[](int i) {\n        return A[i];\n    }\n\n    Matrix&\
    \ operator+=(const Matrix& B) {\n        assert(m == B.m && n == B.n);\n     \
    \   for (int i = 0; i < m; ++i) {\n            for (int j = 0; j < n; ++j) {\n\
    \                (*this)[i][j] += B[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n\n    Matrix& operator-=(const Matrix& B) {\n        assert(m\
    \ == B.m && n == B.n);\n        for (int i = 0; i < m; ++i) {\n            for\
    \ (int j = 0; j < n; ++j) {\n                (*this)[i][j] -= B[i][j];\n     \
    \       }\n        }\n        return *this;\n    }\n\n    Matrix operator+(const\
    \ Matrix& B) const {\n        return Matrix(*this) += B;\n    }\n\n    Matrix\
    \ operator-(const Matrix& B) const {\n        return Matrix(*this) -= B;\n   \
    \ }\n\n    Matrix transpose() const {\n        Matrix ret(n, m);\n        for\
    \ (int i = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j) {\n     \
    \           ret[i][j] = A[j][i];\n            }\n        }\n        return ret;\n\
    \    }\n\n    Matrix matmul(const Matrix& B) const {\n        assert(n == B.m);\n\
    \        Matrix C(m, B.n);\n        for (int i = 0; i < m; ++i) {\n          \
    \  for (int j = 0; j < B.n; ++j) {\n                for (int k = 0; k < n; ++k)\
    \ {\n                    C[i][j] += A[i][k] * B[k][j];\n                }\n  \
    \          }\n        }\n        return C;\n    }\n\n    Matrix pow(long long\
    \ k) const {\n        assert(m == n);\n        Matrix ret = Matrix::I(n);\n  \
    \      Matrix B(*this);\n        while (k > 0) {\n            if (k & 1) ret =\
    \ ret.matmul(B);\n            B = B.matmul(B);\n            k >>= 1;\n       \
    \ }\n        return ret;\n    }\n\n    Matrix rref() const {\n        Matrix B(*this);\n\
    \        int pivot = 0;\n        for (int col = 0; col < n; ++col) {\n       \
    \     int row = pivot;\n            for (; row < m && std::abs(B[row][col]) <\
    \ EPS; ++rol) {}\n\n            if (row == m) continue;\n\n            if (row\
    \ != pivot) std::swap(B[row], B[pivot]);\n\n            T p = B[pivot][col];\n\
    \            for (int c = col; c < n; ++c) {\n                B[pivot][c] /= p;\n\
    \            }\n\n            for (int r = 0; r < m; ++r) {\n                if\
    \ (r == pivot) continue;\n\n                T v = B[r][col];\n               \
    \ for (int c = col; c < n; ++c) {\n                    B[r][c] -= B[pivot][c]\
    \ * v;\n                }\n            }\n\n            ++pivot;\n        }\n\
    \        return B;\n    }\n\n    T det() const {\n        assert(m == n);\n  \
    \      Matrix B(*this);\n        T ret = 1;\n        for (int j = 0; j < n; ++j)\
    \ {\n            int i = j;\n            for (; i < m && std::abs(B[i][j]) < EPS;\
    \ ++i) {}\n\n            if (i == m) return 0;\n\n            if (i != j) {\n\
    \                std::swap(B[i], B[j]);\n                ret = -ret;\n       \
    \     }\n\n            T p = B[j][j];\n            ret *= p;\n            for\
    \ (int l = j; l < n; ++l) {\n                B[j][l] /= p;\n            }\n\n\
    \            for (int k = j + 1; k < m; ++k) {\n                T v = B[k][j];\n\
    \                for (int l = j; l < n; ++l) {\n                    B[k][l] -=\
    \ B[j][l] * v;\n                }\n            }\n        }\n        return ret;\n\
    \    }\n\n    int rank() const {\n        auto B = rref();\n        for (int i\
    \ = 0; i < m; ++i) {\n            bool nonzero = false;\n            for (int\
    \ j = 0; j < n; ++j) {\n                if (std::abs(B[i][j]) > EPS) {\n     \
    \               nonzero = true;\n                    break;\n                }\n\
    \            }\n            if (!nonzero) return i;\n        }\n        return\
    \ m;\n    }\n\n    Matrix inverse() const {\n        assert(std::abs(det(A)) >\
    \ EPS);\n        Matrix AI = concatenate(*this, I(n));\n        Matrix Ib = rref(AI);\n\
    \        Matrix B(n);\n        for (int i = 0; i < n; ++i) {\n            for\
    \ (int j = 0; j < n; ++j) {\n                B[i][j] = IB[i][n + j];\n       \
    \     }\n        }\n        return B;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Matrix\n * @docs docs/math/matrix.md\n\
    \ */\ntemplate <typename T>\nstruct Matrix {\n    std::vector<std::vector<T>>\
    \ A;\n    int m, n;\n\n    const double EPS = 1e-8;\n\n    Matrix() = default;\n\
    \    Matrix(int m, int n) : A(m, std::vector<T>(n)), m(m), n(n) {}\n    Matrix(std::initializer_list<std::initializer_list<T>>\
    \ list) {\n        for (auto& l : list) {\n            A.push_back(std::vector<T>(l.begin(),\
    \ l.end()));\n        }\n        m = A.size();\n        n = A[0].size();\n   \
    \ }\n\n    static Matrix I(int n) {\n        Matrix ret(n, n);\n        for (int\
    \ i = 0; i < n; ++i) ret[i][i] = 1;\n        return ret;\n    }\n\n    static\
    \ Matrix concatenate(const Matrix& A, const Matrix& B) {\n        assert(A.m ==\
    \ B.m);\n        Matrix C(A.m, A.n + B.n);\n        for (int i = 0; i < A.m; ++i)\
    \ {\n            for (int j = 0; j < A.n; ++j) {\n                C[i][j] = A[i][j];\n\
    \            }\n            for (int j = 0; j < B.n; ++j) {\n                C[i][A.n\
    \ + j] = B[i][j];\n            }\n        }\n        return C;\n    }\n\n    const\
    \ std::vector<T>& operator[](int i) const {\n        return A[i];\n    }\n\n \
    \   std::vector<T>& operator[](int i) {\n        return A[i];\n    }\n\n    Matrix&\
    \ operator+=(const Matrix& B) {\n        assert(m == B.m && n == B.n);\n     \
    \   for (int i = 0; i < m; ++i) {\n            for (int j = 0; j < n; ++j) {\n\
    \                (*this)[i][j] += B[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n\n    Matrix& operator-=(const Matrix& B) {\n        assert(m\
    \ == B.m && n == B.n);\n        for (int i = 0; i < m; ++i) {\n            for\
    \ (int j = 0; j < n; ++j) {\n                (*this)[i][j] -= B[i][j];\n     \
    \       }\n        }\n        return *this;\n    }\n\n    Matrix operator+(const\
    \ Matrix& B) const {\n        return Matrix(*this) += B;\n    }\n\n    Matrix\
    \ operator-(const Matrix& B) const {\n        return Matrix(*this) -= B;\n   \
    \ }\n\n    Matrix transpose() const {\n        Matrix ret(n, m);\n        for\
    \ (int i = 0; i < n; ++i) {\n            for (int j = 0; j < m; ++j) {\n     \
    \           ret[i][j] = A[j][i];\n            }\n        }\n        return ret;\n\
    \    }\n\n    Matrix matmul(const Matrix& B) const {\n        assert(n == B.m);\n\
    \        Matrix C(m, B.n);\n        for (int i = 0; i < m; ++i) {\n          \
    \  for (int j = 0; j < B.n; ++j) {\n                for (int k = 0; k < n; ++k)\
    \ {\n                    C[i][j] += A[i][k] * B[k][j];\n                }\n  \
    \          }\n        }\n        return C;\n    }\n\n    Matrix pow(long long\
    \ k) const {\n        assert(m == n);\n        Matrix ret = Matrix::I(n);\n  \
    \      Matrix B(*this);\n        while (k > 0) {\n            if (k & 1) ret =\
    \ ret.matmul(B);\n            B = B.matmul(B);\n            k >>= 1;\n       \
    \ }\n        return ret;\n    }\n\n    Matrix rref() const {\n        Matrix B(*this);\n\
    \        int pivot = 0;\n        for (int col = 0; col < n; ++col) {\n       \
    \     int row = pivot;\n            for (; row < m && std::abs(B[row][col]) <\
    \ EPS; ++rol) {}\n\n            if (row == m) continue;\n\n            if (row\
    \ != pivot) std::swap(B[row], B[pivot]);\n\n            T p = B[pivot][col];\n\
    \            for (int c = col; c < n; ++c) {\n                B[pivot][c] /= p;\n\
    \            }\n\n            for (int r = 0; r < m; ++r) {\n                if\
    \ (r == pivot) continue;\n\n                T v = B[r][col];\n               \
    \ for (int c = col; c < n; ++c) {\n                    B[r][c] -= B[pivot][c]\
    \ * v;\n                }\n            }\n\n            ++pivot;\n        }\n\
    \        return B;\n    }\n\n    T det() const {\n        assert(m == n);\n  \
    \      Matrix B(*this);\n        T ret = 1;\n        for (int j = 0; j < n; ++j)\
    \ {\n            int i = j;\n            for (; i < m && std::abs(B[i][j]) < EPS;\
    \ ++i) {}\n\n            if (i == m) return 0;\n\n            if (i != j) {\n\
    \                std::swap(B[i], B[j]);\n                ret = -ret;\n       \
    \     }\n\n            T p = B[j][j];\n            ret *= p;\n            for\
    \ (int l = j; l < n; ++l) {\n                B[j][l] /= p;\n            }\n\n\
    \            for (int k = j + 1; k < m; ++k) {\n                T v = B[k][j];\n\
    \                for (int l = j; l < n; ++l) {\n                    B[k][l] -=\
    \ B[j][l] * v;\n                }\n            }\n        }\n        return ret;\n\
    \    }\n\n    int rank() const {\n        auto B = rref();\n        for (int i\
    \ = 0; i < m; ++i) {\n            bool nonzero = false;\n            for (int\
    \ j = 0; j < n; ++j) {\n                if (std::abs(B[i][j]) > EPS) {\n     \
    \               nonzero = true;\n                    break;\n                }\n\
    \            }\n            if (!nonzero) return i;\n        }\n        return\
    \ m;\n    }\n\n    Matrix inverse() const {\n        assert(std::abs(det(A)) >\
    \ EPS);\n        Matrix AI = concatenate(*this, I(n));\n        Matrix Ib = rref(AI);\n\
    \        Matrix B(n);\n        for (int i = 0; i < n; ++i) {\n            for\
    \ (int j = 0; j < n; ++j) {\n                B[i][j] = IB[i][n + j];\n       \
    \     }\n        }\n        return B;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:05:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: Matrix
---
# Matrix

行列を表す．

絶対使わない機能ばかりついているので，使用するときは使う部分だけ残すとよい．また行列の積で mod を取る機能はついていないので，そこは自分でその都度実装する．

## Template parameters

- `T`
    - 行列の要素の型

## Constructor

- `Matrix(int m, int n)`
    - $m \times n$ 零行列を構築する
    - 時間計算量: $O(mn)$

- `Matrix(initializer_list<initializer_list<T>> list)`
    - `list` の要素で行列を構築する
    - 時間計算量: $O(mn)$

## Member functions

- `static Matrix I(int n)`
    - $n \times n$ 単位行列を返す
    - 時間計算量: $O(n^2)$

- `static Matrix concatenate(const Matrix& A, const Matrix& B)`
    - $A$ と $B$ を結合した行列を返す
    - 時間計算量: $O(mn_A n_B)$

- `Matrix transpose()`
    - 転置行列を返す
    - 時間計算量: $O(mn)$

- `Matrix matmul(const Matrix& B)`
    - 行列積 $AB$ を返す
    - 時間計算量: $O(m_A n_A n_B)$

- `Matrix pow(long long k)`
    - $A^k$ を返す
    - 時間計算量: $O(n^3 \lg k)$

- `Matrix rref()`
    - $A$ に対して掃き出し法を行った結果を返す
    - 時間計算量: $O(mn^2)$

- `T det()`
    - 行列式 $|A|$ を返す
    - 時間計算量: $O(mn^2)$

- `int rank()`
    - $A$ の階数を返す
    - 時間計算量: $O(mn^2)$

- `Matrix inverse()`
    - 逆行列 $A^{-1}$ を返す
    - 時間計算量: $O(mn^2)$