---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: Mod int
  - icon: ':heavy_check_mark:'
    path: set/walsh_hadamard_transform.hpp
    title: Fast Walsh-Hadamard Transform
  - icon: ':heavy_check_mark:'
    path: set/xor_convolution.hpp
    title: Bitwise XOR Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/yosupo/bitwise_xor_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\n#include\
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
    \    }\n\n   private:\n    int x;\n};\n#line 2 \"set/xor_convolution.hpp\"\n#include\
    \ <bit>\n#line 4 \"set/xor_convolution.hpp\"\n\n#line 5 \"set/walsh_hadamard_transform.hpp\"\
    \n\ntemplate <typename T>\nvoid fwht(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int h = 1; h < n; h <<= 1) {\n        for\
    \ (int i = 0; i < n; i += h << 1) {\n            for (int j = i; j < i + h; ++j)\
    \ {\n                T x = a[j], y = a[j | h];\n                a[j] = x + y;\n\
    \                a[j | h] = x - y;\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid ifwht(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    const T inv2 = T(1) / 2;\n    for (int h = 1;\
    \ h < n; h <<= 1) {\n        for (int i = 0; i < n; i += h << 1) {\n         \
    \   for (int j = i; j < i + h; ++j) {\n                T x = a[j], y = a[j | h];\n\
    \                a[j] = (x + y) * inv2;\n                a[j | h] = (x - y) *\
    \ inv2;\n            }\n        }\n    }\n}\n#line 6 \"set/xor_convolution.hpp\"\
    \n\n/**\n * @brief Bitwise XOR Convolution\n */\n\ntemplate <typename T>\nstd::vector<T>\
    \ xor_convolution(std::vector<T> a, std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(),\
    \ b.size()));\n    a.resize(n);\n    b.resize(n);\n    fwht(a);\n    fwht(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    ifwht(a);\n    return a;\n\
    }\n#line 7 \"test/yosupo/bitwise_xor_convolution.test.cpp\"\nusing namespace std;\n\
    using ll = long long;\n\nusing mint = Modint<998244353>;\n\nint main() {\n   \
    \ int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for (auto&\
    \ x : a) cin >> x;\n    for (auto& x : b) cin >> x;\n    auto c = xor_convolution(a,\
    \ b);\n    for (int i = 0; i < (1 << N); ++i)\n        cout << c[i] << (i < (1\
    \ << N) - 1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/modint.hpp\"\n#include \"\
    ../../set/xor_convolution.hpp\"\nusing namespace std;\nusing ll = long long;\n\
    \nusing mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n\
    \    vector<mint> a(1 << N), b(1 << N);\n    for (auto& x : a) cin >> x;\n   \
    \ for (auto& x : b) cin >> x;\n    auto c = xor_convolution(a, b);\n    for (int\
    \ i = 0; i < (1 << N); ++i)\n        cout << c[i] << (i < (1 << N) - 1 ? \" \"\
    \ : \"\\n\");\n}\n"
  dependsOn:
  - math/modint.hpp
  - set/xor_convolution.hpp
  - set/walsh_hadamard_transform.hpp
  isVerificationFile: true
  path: test/yosupo/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp.html
title: test/yosupo/bitwise_xor_convolution.test.cpp
---
