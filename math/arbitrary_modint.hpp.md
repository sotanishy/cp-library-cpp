---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/binomial_coefficient_prime_mod.test.cpp
    title: test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/montmort_number_mod.test.cpp
    title: test/yosupo/montmort_number_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Arbitrary Mod int
    links: []
  bundledCode: "#line 2 \"math/arbitrary_modint.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n\n/**\n * @brief Arbitrary Mod int\n */\nclass\
    \ ArbitraryModint {\n    using mint = ArbitraryModint;\n\n   public:\n    static\
    \ int& mod() {\n        static int mod_ = 1;\n        return mod_;\n    }\n\n\
    \    static void set_mod(int mod_) {\n        assert(mod_ > 0);\n        mod()\
    \ = mod_;\n    }\n\n    ArbitraryModint(long long y = 0)\n        : x(y >= 0 ?\
    \ y % mod() : (y % mod() + mod()) % mod()) {}\n\n    int val() const { return\
    \ x; }\n\n    mint& operator+=(const mint& r) {\n        if ((x += r.x) >= mod())\
    \ x -= mod();\n        return *this;\n    }\n    mint& operator-=(const mint&\
    \ r) {\n        if ((x += mod() - r.x) >= mod()) x -= mod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL\
    \ * x * r.x % mod());\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& r) { return *this *= r.inv(); }\n\n    bool operator==(const mint& r)\
    \ const { return x == r.x; }\n\n    mint operator+() const { return *this; }\n\
    \    mint operator-() const { return mint(-x); }\n\n    friend mint operator+(const\
    \ mint& l, const mint& r) { return mint(l) += r; }\n    friend mint operator-(const\
    \ mint& l, const mint& r) { return mint(l) -= r; }\n    friend mint operator*(const\
    \ mint& l, const mint& r) { return mint(l) *= r; }\n    friend mint operator/(const\
    \ mint& l, const mint& r) { return mint(l) /= r; }\n\n    mint inv() const {\n\
    \        int a = x, b = mod(), u = 1, v = 0;\n        while (b > 0) {\n      \
    \      int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return mint(u);\n    }\n\n    mint pow(long\
    \ long n) const {\n        mint ret(1), mul(x);\n        while (n > 0) {\n   \
    \         if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& r) {\n        return os << r.x;\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& r) {\n        long long t;\n        is >>\
    \ t;\n        r = mint(t);\n        return is;\n    }\n\n   private:\n    int\
    \ x;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n\
    \n/**\n * @brief Arbitrary Mod int\n */\nclass ArbitraryModint {\n    using mint\
    \ = ArbitraryModint;\n\n   public:\n    static int& mod() {\n        static int\
    \ mod_ = 1;\n        return mod_;\n    }\n\n    static void set_mod(int mod_)\
    \ {\n        assert(mod_ > 0);\n        mod() = mod_;\n    }\n\n    ArbitraryModint(long\
    \ long y = 0)\n        : x(y >= 0 ? y % mod() : (y % mod() + mod()) % mod()) {}\n\
    \n    int val() const { return x; }\n\n    mint& operator+=(const mint& r) {\n\
    \        if ((x += r.x) >= mod()) x -= mod();\n        return *this;\n    }\n\
    \    mint& operator-=(const mint& r) {\n        if ((x += mod() - r.x) >= mod())\
    \ x -= mod();\n        return *this;\n    }\n    mint& operator*=(const mint&\
    \ r) {\n        x = static_cast<int>(1LL * x * r.x % mod());\n        return *this;\n\
    \    }\n    mint& operator/=(const mint& r) { return *this *= r.inv(); }\n\n \
    \   bool operator==(const mint& r) const { return x == r.x; }\n\n    mint operator+()\
    \ const { return *this; }\n    mint operator-() const { return mint(-x); }\n\n\
    \    friend mint operator+(const mint& l, const mint& r) { return mint(l) += r;\
    \ }\n    friend mint operator-(const mint& l, const mint& r) { return mint(l)\
    \ -= r; }\n    friend mint operator*(const mint& l, const mint& r) { return mint(l)\
    \ *= r; }\n    friend mint operator/(const mint& l, const mint& r) { return mint(l)\
    \ /= r; }\n\n    mint inv() const {\n        int a = x, b = mod(), u = 1, v =\
    \ 0;\n        while (b > 0) {\n            int t = a / b;\n            std::swap(a\
    \ -= t * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return\
    \ mint(u);\n    }\n\n    mint pow(long long n) const {\n        mint ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend std::ostream& operator<<(std::ostream& os, const mint& r) {\n       \
    \ return os << r.x;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& r) {\n        long long t;\n        is >> t;\n        r = mint(t);\n\
    \        return is;\n    }\n\n   private:\n    int x;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/arbitrary_modint.hpp
  requiredBy: []
  timestamp: '2024-01-07 20:49:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/binomial_coefficient_prime_mod.test.cpp
  - test/yosupo/montmort_number_mod.test.cpp
documentation_of: math/arbitrary_modint.hpp
layout: document
redirect_from:
- /library/math/arbitrary_modint.hpp
- /library/math/arbitrary_modint.hpp.html
title: Arbitrary Mod int
---
