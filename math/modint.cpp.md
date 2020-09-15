---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/modint.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <int mod>\nstruct ModInt {\n    int x;\n\n    ModInt() : x(0)\
    \ {}\n\n    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod))\
    \ {}\n\n    ModInt &operator+=(const ModInt& p) {\n        if ((x += p.x) >= mod)\
    \ x -= mod;\n        return *this;\n    }\n\n    ModInt &operator-=(const ModInt&\
    \ p) {\n        if ((x += mod - p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    ModInt &operator*=(const ModInt& p) {\n        x = (int) (1LL *\
    \ x * p.x % mod);\n        return *this;\n    }\n\n    ModInt &operator/=(const\
    \ ModInt& p) {\n        *this *= p.inverse();\n        return *this;\n    }\n\n\
    \    ModInt operator-() const { return ModInt(-x); }\n\n    ModInt operator+(const\
    \ ModInt& p) const { return ModInt(*this) += p; }\n\n    ModInt operator-(const\
    \ ModInt& p) const { return ModInt(*this) -= p; }\n\n    ModInt operator*(const\
    \ ModInt& p) const { return ModInt(*this) *= p; }\n\n    ModInt operator/(const\
    \ ModInt& p) const { return ModInt(*this) *= p; }\n\n    bool operator==(const\
    \ ModInt& p) const { return x == p.x; }\n\n    bool operator!=(const ModInt& p)\
    \ const { return x != p.x; }\n\n    ModInt inverse() const {\n        int a =\
    \ x, b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n\
    \            swap(a -= t * b, b);\n            swap(u - t * v, v);\n        }\n\
    \        return ModInt(u);\n    }\n\n    ModInt pow(long long n) const {\n   \
    \     ModInt ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1)\
    \ ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n    \
    \    return ret;\n    }\n\n    friend ostream &operator<<(ostream& os, const ModInt&\
    \ p) {\n        return os << p.x;\n    }\n\n    friend istream &operator>>(istream&\
    \ is, ModInt& a) {\n        long long t;\n        is >> t;\n        a = ModInt<mod>(t);\n\
    \        return is;\n    }\n\n    static int get_mod() { return mod; }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <int mod>\nstruct\
    \ ModInt {\n    int x;\n\n    ModInt() : x(0) {}\n\n    ModInt(long long y) :\
    \ x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod)) {}\n\n    ModInt &operator+=(const\
    \ ModInt& p) {\n        if ((x += p.x) >= mod) x -= mod;\n        return *this;\n\
    \    }\n\n    ModInt &operator-=(const ModInt& p) {\n        if ((x += mod - p.x)\
    \ >= mod) x -= mod;\n        return *this;\n    }\n\n    ModInt &operator*=(const\
    \ ModInt& p) {\n        x = (int) (1LL * x * p.x % mod);\n        return *this;\n\
    \    }\n\n    ModInt &operator/=(const ModInt& p) {\n        *this *= p.inverse();\n\
    \        return *this;\n    }\n\n    ModInt operator-() const { return ModInt(-x);\
    \ }\n\n    ModInt operator+(const ModInt& p) const { return ModInt(*this) += p;\
    \ }\n\n    ModInt operator-(const ModInt& p) const { return ModInt(*this) -= p;\
    \ }\n\n    ModInt operator*(const ModInt& p) const { return ModInt(*this) *= p;\
    \ }\n\n    ModInt operator/(const ModInt& p) const { return ModInt(*this) *= p;\
    \ }\n\n    bool operator==(const ModInt& p) const { return x == p.x; }\n\n   \
    \ bool operator!=(const ModInt& p) const { return x != p.x; }\n\n    ModInt inverse()\
    \ const {\n        int a = x, b = mod, u = 1, v = 0, t;\n        while (b > 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(u\
    \ - t * v, v);\n        }\n        return ModInt(u);\n    }\n\n    ModInt pow(long\
    \ long n) const {\n        ModInt ret(1), mul(x);\n        while (n > 0) {\n \
    \           if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>=\
    \ 1;\n        }\n        return ret;\n    }\n\n    friend ostream &operator<<(ostream&\
    \ os, const ModInt& p) {\n        return os << p.x;\n    }\n\n    friend istream\
    \ &operator>>(istream& is, ModInt& a) {\n        long long t;\n        is >> t;\n\
    \        a = ModInt<mod>(t);\n        return is;\n    }\n\n    static int get_mod()\
    \ { return mod; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy: []
  timestamp: '2020-08-31 09:52:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: math/modint.cpp
---
