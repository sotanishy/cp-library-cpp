---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Arbitrary Mod int
    links: []
  bundledCode: "#line 2 \"math/arbitrary_modint.cpp\"\n#include <iostream>\n#include\
    \ <algorithm>\n#include <cassert>\n\n/*\n * @brief Arbitrary Mod int\n */\nclass\
    \ ArbitraryModint {\n    using mint = ArbitraryModint;\n\npublic:\n    static\
    \ int& mod() noexcept {\n        static int mod_ = 1;\n        return mod_;\n\
    \    }\n\n    static void set_mod(int mod_) {\n        assert(mod_ > 0);\n   \
    \     mod() = mod_;\n    }\n\n    ArbitraryModint(long long y = 0) noexcept :\
    \ x(y >= 0 ? y % mod() : (y % mod() + mod()) % mod()) {}\n\n    int value() const\
    \ noexcept { return x; }\n\n    mint& operator+=(const mint& r) noexcept { if\
    \ ((x += r.x) >= mod()) x -= mod(); return *this; }\n    mint& operator-=(const\
    \ mint& r) noexcept { if ((x += mod() - r.x) >= mod()) x -= mod(); return *this;\
    \ }\n    mint& operator*=(const mint& r) noexcept { x = static_cast<int>(1LL *\
    \ x * r.x % mod()); return *this; }\n    mint& operator/=(const mint& r) noexcept\
    \ { *this *= r.inv(); return *this; }\n\n    mint operator-() const noexcept {\
    \ return mint(-x); }\n\n    mint operator+(const mint& r) const noexcept { return\
    \ mint(*this) += r; }\n    mint operator-(const mint& r) const noexcept { return\
    \ mint(*this) -= r; }\n    mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n    mint operator/(const mint& r) const noexcept { return\
    \ mint(*this) /= r; }\n\n    bool operator==(const mint& r) const noexcept { return\
    \ x == r.x; }\n    bool operator!=(const mint& r) const noexcept { return x !=\
    \ r.x; }\n\n    mint inv() const noexcept {\n        int a = x, b = mod(), u =\
    \ 1, v = 0;\n        while (b > 0) {\n            int t = a / b;\n           \
    \ std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n        }\n\
    \        return mint(u);\n    }\n\n    mint pow(long long n) const noexcept {\n\
    \        mint ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1)\
    \ ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n    \
    \    return ret;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const mint& r) {\n        return os << r.x;\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& r) {\n        long long t;\n        is >>\
    \ t;\n        r = mint(t);\n        return is;\n    }\n\nprivate:\n    int x;\n\
    };\n"
  code: "#pragma once\n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\
    \n/*\n * @brief Arbitrary Mod int\n */\nclass ArbitraryModint {\n    using mint\
    \ = ArbitraryModint;\n\npublic:\n    static int& mod() noexcept {\n        static\
    \ int mod_ = 1;\n        return mod_;\n    }\n\n    static void set_mod(int mod_)\
    \ {\n        assert(mod_ > 0);\n        mod() = mod_;\n    }\n\n    ArbitraryModint(long\
    \ long y = 0) noexcept : x(y >= 0 ? y % mod() : (y % mod() + mod()) % mod()) {}\n\
    \n    int value() const noexcept { return x; }\n\n    mint& operator+=(const mint&\
    \ r) noexcept { if ((x += r.x) >= mod()) x -= mod(); return *this; }\n    mint&\
    \ operator-=(const mint& r) noexcept { if ((x += mod() - r.x) >= mod()) x -= mod();\
    \ return *this; }\n    mint& operator*=(const mint& r) noexcept { x = static_cast<int>(1LL\
    \ * x * r.x % mod()); return *this; }\n    mint& operator/=(const mint& r) noexcept\
    \ { *this *= r.inv(); return *this; }\n\n    mint operator-() const noexcept {\
    \ return mint(-x); }\n\n    mint operator+(const mint& r) const noexcept { return\
    \ mint(*this) += r; }\n    mint operator-(const mint& r) const noexcept { return\
    \ mint(*this) -= r; }\n    mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n    mint operator/(const mint& r) const noexcept { return\
    \ mint(*this) /= r; }\n\n    bool operator==(const mint& r) const noexcept { return\
    \ x == r.x; }\n    bool operator!=(const mint& r) const noexcept { return x !=\
    \ r.x; }\n\n    mint inv() const noexcept {\n        int a = x, b = mod(), u =\
    \ 1, v = 0;\n        while (b > 0) {\n            int t = a / b;\n           \
    \ std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n        }\n\
    \        return mint(u);\n    }\n\n    mint pow(long long n) const noexcept {\n\
    \        mint ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1)\
    \ ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n    \
    \    return ret;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const mint& r) {\n        return os << r.x;\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& r) {\n        long long t;\n        is >>\
    \ t;\n        r = mint(t);\n        return is;\n    }\n\nprivate:\n    int x;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/arbitrary_modint.cpp
  requiredBy: []
  timestamp: '2022-12-12 15:48:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/arbitrary_modint.cpp
layout: document
redirect_from:
- /library/math/arbitrary_modint.cpp
- /library/math/arbitrary_modint.cpp.html
title: Arbitrary Mod int
---
