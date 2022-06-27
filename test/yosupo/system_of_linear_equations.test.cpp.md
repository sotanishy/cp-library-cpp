---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix/matrix.cpp
    title: Matrix
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  - icon: ':x:'
    path: math/system_of_linear_equations.cpp
    title: System of Linear Equations
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
    \ 2 \"math/modint.cpp\"\n#include <iostream>\n#include <algorithm>\n\n/**\n *\
    \ @brief Mod int\n */\ntemplate <int mod>\nclass Modint {\n    using mint = Modint;\n\
    \    static_assert(mod > 0, \"Modulus must be positive\");\n\npublic:\n    static\
    \ constexpr int get_mod() noexcept { return mod; }\n\n    constexpr Modint(long\
    \ long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n  \
    \  constexpr int value() const noexcept { return x; }\n\n    constexpr mint& operator+=(const\
    \ mint& r) noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr\
    \ mint& operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -=\
    \ mod; return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept\
    \ { x = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr\
    \ mint& operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\
    \n    constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
    \ mint operator+(const mint& r) const noexcept { return mint(*this) += r; }\n\
    \    constexpr mint operator-(const mint& r) const noexcept { return mint(*this)\
    \ -= r; }\n    constexpr mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n    constexpr mint operator/(const mint& r) const noexcept\
    \ { return mint(*this) /= r; }\n\n    constexpr bool operator==(const mint& r)\
    \ const noexcept { return x == r.x; }\n    constexpr bool operator!=(const mint&\
    \ r) const noexcept { return x != r.x; }\n\n    constexpr mint inv() const noexcept\
    \ {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0) {\n    \
    \        int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n        while\
    \ (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n   \
    \         n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\nprivate:\n    int x;\n};\n#line 3 \"math/matrix/matrix.cpp\"\n#include\
    \ <cassert>\n#include <cmath>\n#include <initializer_list>\n#include <type_traits>\n\
    #include <vector>\n\ntemplate <typename T>\nclass Matrix {\npublic:\n    static\
    \ Matrix concat(const Matrix& A, const Matrix& B) {\n        assert(A.m == B.m);\n\
    \        Matrix C(A.m, A.n + B.n);\n        for (int i = 0; i < A.m; ++i) {\n\
    \            std::copy(A[i].begin(), A[i].end(), C[i].begin());\n            std::copy(B[i].begin(),\
    \ B[i].end(), C[i].begin() + A.n);\n        }\n        return C;\n    }\n\n  \
    \  Matrix() = default;\n    Matrix(int m, int n) : mat(m, std::vector<T>(n)),\
    \ m(m), n(n) {}\n    Matrix(std::initializer_list<std::initializer_list<T>> list)\
    \ {\n        for (auto& l : list) mat.emplace_back(l);\n        m = mat.size();\n\
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
    \   }\n        return m;\n    }\n\n    template <typename U, typename std::enable_if<std::is_floating_point<U>::value>::type*\
    \ = nullptr>\n    static constexpr bool eq(U a, U b) { return std::abs(a - b)\
    \ < 1e-8; }\n\n    template <typename U, typename std::enable_if<!std::is_floating_point<U>::value>::type*\
    \ = nullptr>\n    static constexpr bool eq(U a, U b) { return a == b; }\n\nprotected:\n\
    \    std::vector<std::vector<T>> mat;\n    int m, n;\n};\n#line 5 \"math/system_of_linear_equations.cpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::vector<T>> solve_system(const Matrix<T>\
    \ A, const std::vector<T>& b) {\n    int m = A.row(), n = A.col();\n    assert(m\
    \ == (int) b.size());\n    Matrix<T> bb(m, 1);\n    for (int i = 0; i < m; ++i)\
    \ bb[i][0] = b[i];\n    auto sol = Matrix<T>::concat(A, bb).rref();\n\n    std::vector<bool>\
    \ independent(n);\n    std::vector<std::vector<T>> ret(1, std::vector<T>(n));\n\
    \    std::vector<std::vector<T>> bases(n, std::vector<T>(n));\n    for (int j\
    \ = 0; j < n; ++j) bases[j][j] = 1;\n    int j = 0;\n    for (int i = 0; i < m;\
    \ ++i) {\n        for (; j < n; ++j) {\n            if (Matrix<T>::eq(sol[i][j],\
    \ T(1))) {\n                independent[j] = true;\n                for (int k\
    \ = j + 1; k < n; ++k) {\n                    bases[k][j] = -sol[i][k];\n    \
    \            }\n                ret[0][j] = sol[i][n];\n                break;\n\
    \            }\n        }\n        if (j == n && !Matrix<T>::eq(sol[i][n], T(0)))\
    \ return {};\n    }\n    for (int j = 0; j < n; ++j) {\n        if (!independent[j])\
    \ ret.push_back(bases[j]);\n    }\n    return ret;\n}\n#line 6 \"test/yosupo/system_of_linear_equations.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, M;\n    cin >> N >> M;\n    Matrix<mint> A(N, M);\n    for (int i\
    \ = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> A[i][j];\n    vector<mint>\
    \ b(N);\n    for (int i = 0; i < N; ++i) cin >> b[i];\n    auto sol = solve_system(A,\
    \ b);\n    if (sol.empty()) {\n        cout << -1 << \"\\n\";\n        return\
    \ 0;\n    }\n    cout << sol.size() - 1 << \"\\n\";\n    for (int i = 0; i < sol.size();\
    \ ++i) {\n        for (int j = 0; j < M; ++j) cout << sol[i][j] << (j < M - 1\
    \ ? \" \" : \"\\n\");\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n#include \"../../math/modint.cpp\"\n#include \"../../math/matrix/matrix.cpp\"\
    \n#include \"../../math/system_of_linear_equations.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing mint = Modint<998244353>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    Matrix<mint>\
    \ A(N, M);\n    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >>\
    \ A[i][j];\n    vector<mint> b(N);\n    for (int i = 0; i < N; ++i) cin >> b[i];\n\
    \    auto sol = solve_system(A, b);\n    if (sol.empty()) {\n        cout << -1\
    \ << \"\\n\";\n        return 0;\n    }\n    cout << sol.size() - 1 << \"\\n\"\
    ;\n    for (int i = 0; i < sol.size(); ++i) {\n        for (int j = 0; j < M;\
    \ ++j) cout << sol[i][j] << (j < M - 1 ? \" \" : \"\\n\");\n    }\n}\n"
  dependsOn:
  - math/modint.cpp
  - math/matrix/matrix.cpp
  - math/system_of_linear_equations.cpp
  isVerificationFile: true
  path: test/yosupo/system_of_linear_equations.test.cpp
  requiredBy: []
  timestamp: '2022-06-27 15:58:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/system_of_linear_equations.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/system_of_linear_equations.test.cpp
- /verify/test/yosupo/system_of_linear_equations.test.cpp.html
title: test/yosupo/system_of_linear_equations.test.cpp
---
