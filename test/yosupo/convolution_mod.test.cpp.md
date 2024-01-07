---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/yosupo/convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 2 \"math/modint.hpp\"\
    \n#include <algorithm>\n#include <iostream>\n\n/**\n * @brief Mod int\n */\ntemplate\
    \ <int m>\nclass Modint {\n    using mint = Modint;\n    static_assert(m > 0,\
    \ \"Modulus must be positive\");\n\n   public:\n    static constexpr int mod()\
    \ { return m; }\n\n    constexpr Modint(long long y = 0) : x(y >= 0 ? y % m :\
    \ (y % m + m) % m) {}\n\n    constexpr int val() const { return x; }\n\n    constexpr\
    \ mint& operator+=(const mint& r) {\n        if ((x += r.x) >= m) x -= m;\n  \
    \      return *this;\n    }\n    constexpr mint& operator-=(const mint& r) {\n\
    \        if ((x += m - r.x) >= m) x -= m;\n        return *this;\n    }\n    constexpr\
    \ mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL * x * r.x\
    \ % m);\n        return *this;\n    }\n    constexpr mint& operator/=(const mint&\
    \ r) { return *this *= r.inv(); }\n\n    constexpr bool operator==(const mint&\
    \ r) const { return x == r.x; }\n\n    constexpr mint operator+() const { return\
    \ *this; }\n    constexpr mint operator-() const { return mint(-x); }\n\n    constexpr\
    \ friend mint operator+(const mint& l, const mint& r) {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(const mint& l, const mint&\
    \ r) {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(const\
    \ mint& l, const mint& r) {\n        return mint(l) *= r;\n    }\n    constexpr\
    \ friend mint operator/(const mint& l, const mint& r) {\n        return mint(l)\
    \ /= r;\n    }\n\n    constexpr mint inv() const {\n        int a = x, b = m,\
    \ u = 1, v = 0;\n        while (b > 0) {\n            int t = a / b;\n       \
    \     std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n     \
    \   }\n        return mint(u);\n    }\n\n    constexpr mint pow(long long n) const\
    \ {\n        mint ret(1), mul(x);\n        while (n > 0) {\n            if (n\
    \ & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& r) {\n        return os << r.x;\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& r) {\n        long long t;\n        is >>\
    \ t;\n        r = mint(t);\n        return is;\n    }\n\n   private:\n    int\
    \ x;\n};\n#line 2 \"convolution/ntt.hpp\"\n#include <vector>\n\nconstexpr int\
    \ get_primitive_root(int mod) {\n    if (mod == 167772161) return 3;\n    if (mod\
    \ == 469762049) return 3;\n    if (mod == 754974721) return 11;\n    if (mod ==\
    \ 998244353) return 3;\n    if (mod == 1224736769) return 3;\n}\n\ntemplate <typename\
    \ mint>\nvoid ntt(std::vector<mint>& a) {\n    constexpr int mod = mint::mod();\n\
    \    constexpr mint primitive_root = get_primitive_root(mod);\n\n    const int\
    \ n = a.size();\n    for (int m = n; m > 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n        for (int s = 0; s < n / m; ++s) {\n            mint w =\
    \ 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint l =\
    \ a[s * m + i];\n                mint r = a[s * m + i + m / 2];\n            \
    \    a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n\
    \                w *= omega;\n            }\n        }\n    }\n}\n\ntemplate <typename\
    \ mint>\nvoid intt(std::vector<mint>& a) {\n    constexpr int mod = mint::mod();\n\
    \    constexpr mint primitive_root = get_primitive_root(mod);\n\n    const int\
    \ n = a.size();\n    for (int m = 2; m <= n; m <<= 1) {\n        mint omega =\
    \ primitive_root.pow((mod - 1) / m).inv();\n        for (int s = 0; s < n / m;\
    \ ++s) {\n            mint w = 1;\n            for (int i = 0; i < m / 2; ++i)\
    \ {\n                mint l = a[s * m + i];\n                mint r = a[s * m\
    \ + i + m / 2] * w;\n                a[s * m + i] = l + r;\n                a[s\
    \ * m + i + m / 2] = l - r;\n                w *= omega;\n            }\n    \
    \    }\n    }\n}\n\ntemplate <typename mint>\nstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    const int size = a.size() + b.size() - 1;\n \
    \   const int n = std::bit_ceil((unsigned int)size);\n    a.resize(n);\n    b.resize(n);\n\
    \    ntt(a);\n    ntt(b);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n   \
    \ intt(a);\n    a.resize(size);\n    mint n_inv = mint(n).inv();\n    for (int\
    \ i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}\n#line 5 \"test/yosupo/convolution_mod.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    using mint = Modint<998244353>;\n\nint main() {\n    int N, M;\n    cin >> N >>\
    \ M;\n    vector<mint> a(N), b(M);\n    for (int i = 0; i < N; i++) cin >> a[i];\n\
    \    for (int i = 0; i < M; i++) cin >> b[i];\n    auto c = convolution(a, b);\n\
    \    for (int i = 0; i < N + M - 1; i++) cout << c[i] << (i < N + M - 2 ? \" \"\
    \ : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../../math/modint.hpp\"\n#include \"../../convolution/ntt.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\nusing mint =\
    \ Modint<998244353>;\n\nint main() {\n    int N, M;\n    cin >> N >> M;\n    vector<mint>\
    \ a(N), b(M);\n    for (int i = 0; i < N; i++) cin >> a[i];\n    for (int i =\
    \ 0; i < M; i++) cin >> b[i];\n    auto c = convolution(a, b);\n    for (int i\
    \ = 0; i < N + M - 1; i++) cout << c[i] << (i < N + M - 2 ? \" \" : \"\\n\");\n\
    }\n"
  dependsOn:
  - math/modint.hpp
  - convolution/ntt.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod.test.cpp
- /verify/test/yosupo/convolution_mod.test.cpp.html
title: test/yosupo/convolution_mod.test.cpp
---
