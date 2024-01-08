---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/linalg/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: math/linalg/square_matrix.hpp
    title: Square Matrix
  - icon: ':question:'
    path: math/modint.hpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_matrix
    links:
    - https://judge.yosupo.jp/problem/pow_of_matrix
  bundledCode: "#line 1 \"test/yosupo/pow_of_matrix.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/pow_of_matrix\"\n\n#include <bits/stdc++.h>\n\n\
    #line 4 \"math/linalg/square_matrix.hpp\"\n#include <initializer_list>\n\n#line\
    \ 6 \"math/linalg/matrix.hpp\"\n#include <type_traits>\n#line 8 \"math/linalg/matrix.hpp\"\
    \n\ntemplate <typename T>\nclass Matrix {\n   public:\n    static Matrix concat(const\
    \ Matrix& A, const Matrix& B) {\n        assert(A.m == B.m);\n        Matrix C(A.m,\
    \ A.n + B.n);\n        for (int i = 0; i < A.m; ++i) {\n            std::ranges::copy(A[i],\
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
    \ mat;\n    int m, n;\n};\n#line 7 \"math/linalg/square_matrix.hpp\"\n\ntemplate\
    \ <typename T>\nclass SquareMatrix : public Matrix<T> {\n    using Matrix<T>::Matrix;\n\
    \    using Matrix<T>::eq;\n    using Matrix<T>::n;\n\n   public:\n    static SquareMatrix\
    \ I(int n) {\n        SquareMatrix ret(n);\n        for (int i = 0; i < n; ++i)\
    \ ret[i][i] = 1;\n        return ret;\n    }\n\n    SquareMatrix() = default;\n\
    \    explicit SquareMatrix(int n) : Matrix<T>(n, n) {}\n    SquareMatrix(const\
    \ Matrix<T>& mat) : Matrix<T>(mat) {\n        assert(Matrix<T>::m == n);\n   \
    \ }\n    SquareMatrix(std::initializer_list<std::initializer_list<T>> list)\n\
    \        : Matrix<T>(list) {\n        assert(Matrix<T>::m == n);\n    }\n\n  \
    \  SquareMatrix pow(long long k) const {\n        auto ret = I(n);\n        auto\
    \ A(*this);\n        while (k > 0) {\n            if (k & 1) ret = ret.matmul(A);\n\
    \            A = A.matmul(A);\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    T det() const {\n        SquareMatrix A(*this);\n       \
    \ T ret = 1;\n        for (int j = 0; j < n; ++j) {\n            int i = j;\n\
    \            while (i < n && eq(A[i][j], T(0))) ++i;\n            if (i == n)\
    \ return 0;\n\n            if (i != j) {\n                A[i].swap(A[j]);\n \
    \               ret = -ret;\n            }\n\n            T p = A[j][j];\n   \
    \         ret *= p;\n            for (int l = j; l < n; ++l) A[j][l] /= p;\n\n\
    \            for (int k = j + 1; k < n; ++k) {\n                T v = A[k][j];\n\
    \                for (int l = j; l < n; ++l) {\n                    A[k][l] -=\
    \ A[j][l] * v;\n                }\n            }\n        }\n        return ret;\n\
    \    }\n\n    SquareMatrix inv() const {\n        assert(!eq(det(), T(0)));\n\
    \        auto IB = Matrix<T>::concat(*this, I(n)).rref();\n        SquareMatrix\
    \ B(n);\n        for (int i = 0; i < n; ++i) {\n            std::copy(IB[i].begin()\
    \ + n, IB[i].end(), B[i].begin());\n        }\n        return B;\n    }\n};\n\
    #line 4 \"math/modint.hpp\"\n\n/**\n * @brief Mod int\n */\ntemplate <int m>\n\
    class Modint {\n    using mint = Modint;\n    static_assert(m > 0, \"Modulus must\
    \ be positive\");\n\n   public:\n    static constexpr int mod() { return m; }\n\
    \n    constexpr Modint(long long y = 0) : x(y >= 0 ? y % m : (y % m + m) % m)\
    \ {}\n\n    constexpr int val() const { return x; }\n\n    constexpr mint& operator+=(const\
    \ mint& r) {\n        if ((x += r.x) >= m) x -= m;\n        return *this;\n  \
    \  }\n    constexpr mint& operator-=(const mint& r) {\n        if ((x += m - r.x)\
    \ >= m) x -= m;\n        return *this;\n    }\n    constexpr mint& operator*=(const\
    \ mint& r) {\n        x = static_cast<int>(1LL * x * r.x % m);\n        return\
    \ *this;\n    }\n    constexpr mint& operator/=(const mint& r) { return *this\
    \ *= r.inv(); }\n\n    constexpr bool operator==(const mint& r) const { return\
    \ x == r.x; }\n\n    constexpr mint operator+() const { return *this; }\n    constexpr\
    \ mint operator-() const { return mint(-x); }\n\n    constexpr friend mint operator+(const\
    \ mint& l, const mint& r) {\n        return mint(l) += r;\n    }\n    constexpr\
    \ friend mint operator-(const mint& l, const mint& r) {\n        return mint(l)\
    \ -= r;\n    }\n    constexpr friend mint operator*(const mint& l, const mint&\
    \ r) {\n        return mint(l) *= r;\n    }\n    constexpr friend mint operator/(const\
    \ mint& l, const mint& r) {\n        return mint(l) /= r;\n    }\n\n    constexpr\
    \ mint inv() const {\n        int a = x, b = m, u = 1, v = 0;\n        while (b\
    \ > 0) {\n            int t = a / b;\n            std::swap(a -= t * b, b);\n\
    \            std::swap(u -= t * v, v);\n        }\n        return mint(u);\n \
    \   }\n\n    constexpr mint pow(long long n) const {\n        mint ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend std::ostream& operator<<(std::ostream& os, const mint& r) {\n       \
    \ return os << r.x;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& r) {\n        long long t;\n        is >> t;\n        r = mint(t);\n\
    \        return is;\n    }\n\n   private:\n    int x;\n};\n#line 7 \"test/yosupo/pow_of_matrix.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nint main() {\n  \
    \  ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N;\n  \
    \  long long K;\n    cin >> N >> K;\n    SquareMatrix<mint> a(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n        for (int j = 0; j < N; ++j) cin >> a[i][j];\n\
    \    }\n    a = a.pow(K);\n    for (int i = 0; i < N; ++i) {\n        for (int\
    \ j = 0; j < N; ++j) cout << a[i][j] << (j < N - 1 ? \" \" : \"\\n\");\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../math/linalg/square_matrix.hpp\"\n#include\
    \ \"../../math/modint.hpp\"\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N;\n    long long K;\n    cin >> N >> K;\n    SquareMatrix<mint> a(N);\n\
    \    for (int i = 0; i < N; ++i) {\n        for (int j = 0; j < N; ++j) cin >>\
    \ a[i][j];\n    }\n    a = a.pow(K);\n    for (int i = 0; i < N; ++i) {\n    \
    \    for (int j = 0; j < N; ++j) cout << a[i][j] << (j < N - 1 ? \" \" : \"\\\
    n\");\n    }\n}\n"
  dependsOn:
  - math/linalg/square_matrix.hpp
  - math/linalg/matrix.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/pow_of_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 21:12:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/pow_of_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/pow_of_matrix.test.cpp
- /verify/test/yosupo/pow_of_matrix.test.cpp.html
title: test/yosupo/pow_of_matrix.test.cpp
---
