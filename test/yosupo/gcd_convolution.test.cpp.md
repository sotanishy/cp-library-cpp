---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/gcd_lcm_convolution.hpp
    title: "GCD/LCM Convolution (Divisor Fast Zeta/M\xF6bius Transform)"
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
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/yosupo/gcd_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#line 2 \"math/modint.hpp\"\
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
    \ x;\n};\n#line 2 \"convolution/gcd_lcm_convolution.hpp\"\n#include <vector>\n\
    \ntemplate <typename T>\nvoid divisor_fzt(std::vector<T>& a, bool subset) {\n\
    \    int n = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int p\
    \ = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        if (subset) {\n\
    \            for (int k = 1; k * p < n; ++k) {\n                sieve[k * p] =\
    \ false;\n                a[k * p] += a[k];\n            }\n        } else {\n\
    \            for (int k = (n - 1) / p; k > 0; --k) {\n                sieve[k\
    \ * p] = false;\n                a[k] += a[k * p];\n            }\n        }\n\
    \    }\n}\n\ntemplate <typename T>\nvoid divisor_fmt(std::vector<T>& a, bool subset)\
    \ {\n    int n = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int\
    \ p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        if (subset)\
    \ {\n            for (int k = (n - 1) / p; k > 0; --k) {\n                sieve[k\
    \ * p] = false;\n                a[k * p] -= a[k];\n            }\n        } else\
    \ {\n            for (int k = 1; k * p < n; ++k) {\n                sieve[k *\
    \ p] = false;\n                a[k] -= a[k * p];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nstd::vector<T> gcd_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = std::max(a.size(), b.size());\n    a.resize(n);\n\
    \    b.resize(n);\n    divisor_fzt(a, false);\n    divisor_fzt(b, false);\n  \
    \  for (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a, false);\n   \
    \ return a;\n}\n\ntemplate <typename T>\nstd::vector<T> lcm_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = std::max(a.size(), b.size());\n    a.resize(n);\n\
    \    b.resize(n);\n    divisor_fzt(a, true);\n    divisor_fzt(b, true);\n    for\
    \ (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a, true);\n    return\
    \ a;\n}\n#line 5 \"test/yosupo/gcd_convolution.test.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<mint> a(N+1), b(N+1);\n\
    \    for (int i = 1; i <= N; ++i) cin >> a[i];\n    for (int i = 1; i <= N; ++i)\
    \ cin >> b[i];\n    auto c = gcd_convolution(a, b);\n    for (int i = 1; i <=\
    \ N; ++i) cout << c[i] << (i < N ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ \"../../math/modint.hpp\"\n#include \"../../convolution/gcd_lcm_convolution.hpp\"\
    \n\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    using mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n \
    \   vector<mint> a(N+1), b(N+1);\n    for (int i = 1; i <= N; ++i) cin >> a[i];\n\
    \    for (int i = 1; i <= N; ++i) cin >> b[i];\n    auto c = gcd_convolution(a,\
    \ b);\n    for (int i = 1; i <= N; ++i) cout << c[i] << (i < N ? \" \" : \"\\\
    n\");\n}\n"
  dependsOn:
  - math/modint.hpp
  - convolution/gcd_lcm_convolution.hpp
  isVerificationFile: true
  path: test/yosupo/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/gcd_convolution.test.cpp
- /verify/test/yosupo/gcd_convolution.test.cpp.html
title: test/yosupo/gcd_convolution.test.cpp
---
