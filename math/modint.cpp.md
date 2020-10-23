---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/modint.cpp\"\n#include <bits/stdc++.h>\n\ntemplate\
    \ <int mod>\nclass Modint {\n    static_assert(mod > 0, \"Modulus must be positive\"\
    );\n\npublic:\n    static constexpr int get_mod() noexcept { return mod; }\n\n\
    \    constexpr Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod\
    \ + mod) % mod) {}\n\n    constexpr int value() const noexcept { return x; }\n\
    \n    constexpr Modint& operator+=(const Modint& r) noexcept { if ((x += r.x)\
    \ >= mod) x -= mod; return *this; }\n    constexpr Modint& operator-=(const Modint&\
    \ r) noexcept { if ((x += mod - r.x) >= mod) x -= mod; return *this; }\n    constexpr\
    \ Modint& operator*=(const Modint& r) noexcept { x = static_cast<int>(1LL * x\
    \ * r.x % mod); return *this; }\n    constexpr Modint& operator/=(const Modint&\
    \ r) noexcept { *this *= r.inv(); return *this; }\n\n    constexpr Modint operator-()\
    \ const noexcept { return Modint(-x); }\n\n    constexpr Modint operator+(const\
    \ Modint& r) const noexcept { return Modint(*this) += r; }\n    constexpr Modint\
    \ operator-(const Modint& r) const noexcept { return Modint(*this) -= r; }\n \
    \   constexpr Modint operator*(const Modint& r) const noexcept { return Modint(*this)\
    \ *= r; }\n    constexpr Modint operator/(const Modint& r) const noexcept { return\
    \ Modint(*this) /= r; }\n\n    constexpr bool operator==(const Modint& r) const\
    \ noexcept { return x == r.x; }\n    constexpr bool operator!=(const Modint& r)\
    \ const noexcept { return x != r.x; }\n\n    constexpr Modint inv() const noexcept\
    \ {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0) {\n    \
    \        int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return Modint(u);\n    }\n\n    constexpr\
    \ Modint pow(long long n) const noexcept {\n        Modint ret(1), mul(x);\n \
    \       while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Modint& r) {\n        return\
    \ os << r.x;\n    }\n\n    friend std::istream& operator>>(std::istream& is, Modint&\
    \ r) {\n        long long t;\n        is >> t;\n        r = Modint(t);\n     \
    \   return is;\n    }\n\nprivate:\n    int x;\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\ntemplate <int mod>\nclass Modint\
    \ {\n    static_assert(mod > 0, \"Modulus must be positive\");\n\npublic:\n  \
    \  static constexpr int get_mod() noexcept { return mod; }\n\n    constexpr Modint(long\
    \ long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n  \
    \  constexpr int value() const noexcept { return x; }\n\n    constexpr Modint&\
    \ operator+=(const Modint& r) noexcept { if ((x += r.x) >= mod) x -= mod; return\
    \ *this; }\n    constexpr Modint& operator-=(const Modint& r) noexcept { if ((x\
    \ += mod - r.x) >= mod) x -= mod; return *this; }\n    constexpr Modint& operator*=(const\
    \ Modint& r) noexcept { x = static_cast<int>(1LL * x * r.x % mod); return *this;\
    \ }\n    constexpr Modint& operator/=(const Modint& r) noexcept { *this *= r.inv();\
    \ return *this; }\n\n    constexpr Modint operator-() const noexcept { return\
    \ Modint(-x); }\n\n    constexpr Modint operator+(const Modint& r) const noexcept\
    \ { return Modint(*this) += r; }\n    constexpr Modint operator-(const Modint&\
    \ r) const noexcept { return Modint(*this) -= r; }\n    constexpr Modint operator*(const\
    \ Modint& r) const noexcept { return Modint(*this) *= r; }\n    constexpr Modint\
    \ operator/(const Modint& r) const noexcept { return Modint(*this) /= r; }\n\n\
    \    constexpr bool operator==(const Modint& r) const noexcept { return x == r.x;\
    \ }\n    constexpr bool operator!=(const Modint& r) const noexcept { return x\
    \ != r.x; }\n\n    constexpr Modint inv() const noexcept {\n        int a = x,\
    \ b = mod, u = 1, v = 0;\n        while (b > 0) {\n            int t = a / b;\n\
    \            std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n\
    \        }\n        return Modint(u);\n    }\n\n    constexpr Modint pow(long\
    \ long n) const noexcept {\n        Modint ret(1), mul(x);\n        while (n >\
    \ 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n        \
    \    n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Modint& r) {\n        return os << r.x;\n\
    \    }\n\n    friend std::istream& operator>>(std::istream& is, Modint& r) {\n\
    \        long long t;\n        is >> t;\n        r = Modint(t);\n        return\
    \ is;\n    }\n\nprivate:\n    int x;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy: []
  timestamp: '2020-10-24 00:03:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: math/modint.cpp
---
