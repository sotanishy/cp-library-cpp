---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/linalg/matrix.hpp
    title: Matrix
  - icon: ':x:'
    path: math/linalg/system_of_linear_equations.hpp
    title: System of Linear Equations
  - icon: ':question:'
    path: math/modint.hpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#line 1 \"test/yosupo/system_of_linear_equations.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\n\n#line\
    \ 2 \"math/linalg/system_of_linear_equations.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"math/linalg/matrix.hpp\"\n#include <algorithm>\n#line\
    \ 4 \"math/linalg/matrix.hpp\"\n#include <cmath>\n#include <initializer_list>\n\
    #include <type_traits>\n#line 8 \"math/linalg/matrix.hpp\"\n\ntemplate <typename\
    \ T>\nclass Matrix {\n   public:\n    static Matrix concat(const Matrix& A, const\
    \ Matrix& B) {\n        assert(A.row == B.row);\n        Matrix C(A.row, A.col\
    \ + B.col);\n        for (int i = 0; i < A.row; ++i) {\n            std::ranges::copy(A[i],\
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
    };\n#line 6 \"math/linalg/system_of_linear_equations.hpp\"\n\ntemplate <typename\
    \ T>\nstd::vector<std::vector<T>> solve_system(const Matrix<T> A,\n          \
    \                               const std::vector<T>& b) {\n    auto [row, col]\
    \ = A.shape();\n    assert(row == (int)b.size());\n    Matrix<T> bb(row, 1);\n\
    \    for (int i = 0; i < row; ++i) bb[i][0] = b[i];\n    auto sol = Matrix<T>::concat(A,\
    \ bb);\n    sol.reduce();\n\n    std::vector<bool> independent(col);\n    std::vector\
    \ ret(1, std::vector<T>(col));\n    std::vector bases(col, std::vector<T>(col));\n\
    \    for (int j = 0; j < col; ++j) bases[j][j] = 1;\n    int j = 0;\n    for (int\
    \ i = 0; i < row; ++i) {\n        for (; j < col; ++j) {\n            if (Matrix<T>::eq(sol[i][j],\
    \ T(1))) {\n                independent[j] = true;\n                for (int k\
    \ = j + 1; k < col; ++k) {\n                    bases[k][j] = -sol[i][k];\n  \
    \              }\n                ret[0][j] = sol[i][col];\n                break;\n\
    \            }\n        }\n        if (j == col && !Matrix<T>::eq(sol[i][col],\
    \ T(0))) return {};\n    }\n    for (int j = 0; j < col; ++j) {\n        if (!independent[j])\
    \ ret.push_back(bases[j]);\n    }\n    return ret;\n}\n#line 4 \"test/yosupo/system_of_linear_equations.test.cpp\"\
    \n\n#include <bits/stdc++.h>\n\n#line 4 \"math/modint.hpp\"\n\n/**\n * @brief\
    \ Mod int\n */\ntemplate <int m>\nclass Modint {\n    using mint = Modint;\n \
    \   static_assert(m > 0, \"Modulus must be positive\");\n\n   public:\n    static\
    \ constexpr int mod() { return m; }\n\n    constexpr Modint(long long y = 0) :\
    \ x(y >= 0 ? y % m : (y % m + m) % m) {}\n\n    constexpr int val() const { return\
    \ x; }\n\n    constexpr mint& operator+=(const mint& r) {\n        if ((x += r.x)\
    \ >= m) x -= m;\n        return *this;\n    }\n    constexpr mint& operator-=(const\
    \ mint& r) {\n        if ((x += m - r.x) >= m) x -= m;\n        return *this;\n\
    \    }\n    constexpr mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL\
    \ * x * r.x % m);\n        return *this;\n    }\n    constexpr mint& operator/=(const\
    \ mint& r) { return *this *= r.inv(); }\n\n    constexpr bool operator==(const\
    \ mint& r) const { return x == r.x; }\n\n    constexpr mint operator+() const\
    \ { return *this; }\n    constexpr mint operator-() const { return mint(-x); }\n\
    \n    constexpr friend mint operator+(const mint& l, const mint& r) {\n      \
    \  return mint(l) += r;\n    }\n    constexpr friend mint operator-(const mint&\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(const mint& l, const mint& r) {\n        return mint(l) *= r;\n\
    \    }\n    constexpr friend mint operator/(const mint& l, const mint& r) {\n\
    \        return mint(l) /= r;\n    }\n\n    constexpr mint inv() const {\n   \
    \     int a = x, b = m, u = 1, v = 0;\n        while (b > 0) {\n            int\
    \ t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u -=\
    \ t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const {\n        mint ret(1), mul(x);\n        while (n > 0)\
    \ {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\n   private:\n    int x;\n};\n#line 9 \"test/yosupo/system_of_linear_equations.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nint main() {\n  \
    \  ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N, M;\n\
    \    cin >> N >> M;\n    Matrix<mint> A(N, M);\n    for (int i = 0; i < N; ++i)\n\
    \        for (int j = 0; j < M; ++j) cin >> A[i][j];\n    vector<mint> b(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> b[i];\n    auto sol = solve_system(A,\
    \ b);\n    if (sol.empty()) {\n        cout << -1 << \"\\n\";\n        return\
    \ 0;\n    }\n    cout << sol.size() - 1 << \"\\n\";\n    for (int i = 0; i < (int)sol.size();\
    \ ++i) {\n        for (int j = 0; j < M; ++j)\n            cout << sol[i][j] <<\
    \ (j < M - 1 ? \" \" : \"\\n\");\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n#include \"../../math/linalg/system_of_linear_equations.hpp\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../math/linalg/matrix.hpp\"\n#include \"../../math/modint.hpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nint main() {\n  \
    \  ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N, M;\n\
    \    cin >> N >> M;\n    Matrix<mint> A(N, M);\n    for (int i = 0; i < N; ++i)\n\
    \        for (int j = 0; j < M; ++j) cin >> A[i][j];\n    vector<mint> b(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> b[i];\n    auto sol = solve_system(A,\
    \ b);\n    if (sol.empty()) {\n        cout << -1 << \"\\n\";\n        return\
    \ 0;\n    }\n    cout << sol.size() - 1 << \"\\n\";\n    for (int i = 0; i < (int)sol.size();\
    \ ++i) {\n        for (int j = 0; j < M; ++j)\n            cout << sol[i][j] <<\
    \ (j < M - 1 ? \" \" : \"\\n\");\n    }\n}\n"
  dependsOn:
  - math/linalg/system_of_linear_equations.hpp
  - math/linalg/matrix.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/system_of_linear_equations.test.cpp
  requiredBy: []
  timestamp: '2024-03-02 20:34:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/system_of_linear_equations.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/system_of_linear_equations.test.cpp
- /verify/test/yosupo/system_of_linear_equations.test.cpp.html
title: test/yosupo/system_of_linear_equations.test.cpp
---
