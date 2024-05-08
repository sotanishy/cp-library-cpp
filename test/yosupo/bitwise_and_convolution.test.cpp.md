---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: Mod int
  - icon: ':heavy_check_mark:'
    path: math/set/and_or_convolution.hpp
    title: Bitwise AND/OR Convolution
  - icon: ':heavy_check_mark:'
    path: math/set/zeta_moebius_transform.hpp
    title: "Fast Zeta/M\xF6bius Transform"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/yosupo/bitwise_and_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 4 \"math/modint.hpp\"\n\n/**\n * @brief Mod int\n */\n\
    template <int m>\nclass Modint {\n    using mint = Modint;\n    static_assert(m\
    \ > 0, \"Modulus must be positive\");\n\n   public:\n    static constexpr int\
    \ mod() { return m; }\n\n    constexpr Modint(long long y = 0) : x(y >= 0 ? y\
    \ % m : (y % m + m) % m) {}\n\n    constexpr int val() const { return x; }\n\n\
    \    constexpr mint& operator+=(const mint& r) {\n        if ((x += r.x) >= m)\
    \ x -= m;\n        return *this;\n    }\n    constexpr mint& operator-=(const\
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
    \    }\n\n   private:\n    int x;\n};\n#line 2 \"math/set/and_or_convolution.hpp\"\
    \n#include <bit>\n#line 4 \"math/set/and_or_convolution.hpp\"\n\n#line 5 \"math/set/zeta_moebius_transform.hpp\"\
    \n\ntemplate <typename T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j] += a[j | i];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid superset_fmt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j] -= a[j | i];\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid subset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j | i] += a[j];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid subset_fmt(std::vector<T>& a)\
    \ {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j | i] -= a[j];\n        }\n    }\n}\n#line 6 \"\
    math/set/and_or_convolution.hpp\"\n\n/**\n * @brief Bitwise AND/OR Convolution\n\
    \ */\n\ntemplate <typename T>\nstd::vector<T> and_convolution(std::vector<T> a,\
    \ std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(), b.size()));\n\
    \    a.resize(n);\n    b.resize(n);\n    superset_fzt(a);\n    superset_fzt(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    superset_fmt(a);\n    return\
    \ a;\n}\n\ntemplate <typename T>\nstd::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(), b.size()));\n\
    \    a.resize(n);\n    b.resize(n);\n    subset_fzt(a);\n    subset_fzt(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    subset_fmt(a);\n    return\
    \ a;\n}\n#line 7 \"test/yosupo/bitwise_and_convolution.test.cpp\"\nusing namespace\
    \ std;\nusing ll = long long;\n\nusing mint = Modint<998244353>;\n\nint main()\
    \ {\n    int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for\
    \ (auto& x : a) cin >> x;\n    for (auto& x : b) cin >> x;\n    auto c = and_convolution(a,\
    \ b);\n    for (int i = 0; i < (1 << N); ++i)\n        cout << c[i] << (i < (1\
    \ << N) - 1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/modint.hpp\"\n#include \"\
    ../../math/set/and_or_convolution.hpp\"\nusing namespace std;\nusing ll = long\
    \ long;\n\nusing mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin\
    \ >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for (auto& x : a) cin >>\
    \ x;\n    for (auto& x : b) cin >> x;\n    auto c = and_convolution(a, b);\n \
    \   for (int i = 0; i < (1 << N); ++i)\n        cout << c[i] << (i < (1 << N)\
    \ - 1 ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - math/modint.hpp
  - math/set/and_or_convolution.hpp
  - math/set/zeta_moebius_transform.hpp
  isVerificationFile: true
  path: test/yosupo/bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bitwise_and_convolution.test.cpp
- /verify/test/yosupo/bitwise_and_convolution.test.cpp.html
title: test/yosupo/bitwise_and_convolution.test.cpp
---
