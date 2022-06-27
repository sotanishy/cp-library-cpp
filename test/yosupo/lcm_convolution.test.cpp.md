---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/gcd_lcm_convolution.hpp
    title: "GCD/LCM Convolution (Divisor Fast Zeta/M\xF6bius Transform)"
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lcm_convolution
    links:
    - https://judge.yosupo.jp/problem/lcm_convolution
  bundledCode: "#line 1 \"test/yosupo/lcm_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#line 2 \"math/modint.cpp\"\
    \n#include <iostream>\n#include <algorithm>\n\n\n/**\n * @brief Mod int\n */\n\
    template <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod\
    \ > 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
    \ noexcept { return mod; }\n\n    constexpr Modint(long long y = 0) noexcept :\
    \ x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n    constexpr int value()\
    \ const noexcept { return x; }\n\n    constexpr mint& operator+=(const mint& r)\
    \ noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr mint&\
    \ operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod;\
    \ return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept { x\
    \ = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr mint&\
    \ operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\n \
    \   constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
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
    \    }\n\nprivate:\n    int x;\n};\n#line 2 \"convolution/gcd_lcm_convolution.hpp\"\
    \n#include <vector>\n\ntemplate <typename T>\nvoid divisor_fzt(std::vector<T>&\
    \ a, bool subset) {\n    int n = a.size();\n    std::vector<bool> sieve(n, true);\n\
    \    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n       \
    \ if (subset) {\n            for (int k = 1; k * p < n; ++k) {\n             \
    \   sieve[k * p] = false;\n                a[k * p] += a[k];\n            }\n\
    \        } else {\n            for (int k = (n - 1) / p; k > 0; --k) {\n     \
    \           sieve[k * p] = false;\n                a[k] += a[k * p];\n       \
    \     }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_fmt(std::vector<T>&\
    \ a, bool subset) {\n    int n = a.size();\n    std::vector<bool> sieve(n, true);\n\
    \    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n       \
    \ if (subset) {\n            for (int k = (n - 1) / p; k > 0; --k) {\n       \
    \         sieve[k * p] = false;\n                a[k * p] -= a[k];\n         \
    \   }\n        } else {\n            for (int k = 1; k * p < n; ++k) {\n     \
    \           sieve[k * p] = false;\n                a[k] -= a[k * p];\n       \
    \     }\n        }\n    }\n}\n\ntemplate <typename T>\nstd::vector<T> gcd_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = std::max(a.size(), b.size());\n    a.resize(n);\n\
    \    b.resize(n);\n    divisor_fzt(a, false);\n    divisor_fzt(b, false);\n  \
    \  for (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a, false);\n   \
    \ return a;\n}\n\ntemplate <typename T>\nstd::vector<T> lcm_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = std::max(a.size(), b.size());\n    a.resize(n);\n\
    \    b.resize(n);\n    divisor_fzt(a, true);\n    divisor_fzt(b, true);\n    for\
    \ (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a, true);\n    return\
    \ a;\n}\n#line 5 \"test/yosupo/lcm_convolution.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<mint> a(N+1), b(N+1);\n\
    \    for (int i = 1; i <= N; ++i) cin >> a[i];\n    for (int i = 1; i <= N; ++i)\
    \ cin >> b[i];\n    auto c = lcm_convolution(a, b);\n    for (int i = 1; i <=\
    \ N; ++i) cout << c[i] << (i < N ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lcm_convolution\"\n\n#include\
    \ \"../../math/modint.cpp\"\n#include \"../../convolution/gcd_lcm_convolution.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    using mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n \
    \   vector<mint> a(N+1), b(N+1);\n    for (int i = 1; i <= N; ++i) cin >> a[i];\n\
    \    for (int i = 1; i <= N; ++i) cin >> b[i];\n    auto c = lcm_convolution(a,\
    \ b);\n    for (int i = 1; i <= N; ++i) cout << c[i] << (i < N ? \" \" : \"\\\
    n\");\n}\n"
  dependsOn:
  - math/modint.cpp
  - convolution/gcd_lcm_convolution.hpp
  isVerificationFile: true
  path: test/yosupo/lcm_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-06-27 14:39:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/lcm_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lcm_convolution.test.cpp
- /verify/test/yosupo/lcm_convolution.test.cpp.html
title: test/yosupo/lcm_convolution.test.cpp
---
