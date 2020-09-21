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
    \ std;\n\ntemplate <int mod>\nstruct Modint {\n    int x;\n\n    Modint() : x(0)\
    \ {}\n    Modint(long long y) : x(y >= 0 ? y % mod : y % mod + mod) {}\n\n   \
    \ Modint& operator+=(const Modint& p) { if ((x += p.x) >= mod) x -= mod; return\
    \ *this; }\n    Modint& operator-=(const Modint& p) { if ((x += mod - p.x) >=\
    \ mod) x -= mod; return *this; }\n    Modint& operator*=(const Modint& p) { x\
    \ = (int) (1LL * x * p.x % mod); return *this; }\n    Modint& operator/=(const\
    \ Modint& p) { *this *= p.inv(); return *this; }\n\n    Modint operator-() const\
    \ { return Modint(-x); }\n\n    Modint operator+(const Modint& p) const { return\
    \ Modint(*this) += p; }\n    Modint operator-(const Modint& p) const { return\
    \ Modint(*this) -= p; }\n    Modint operator*(const Modint& p) const { return\
    \ Modint(*this) *= p; }\n    Modint operator/(const Modint& p) const { return\
    \ Modint(*this) /= p; }\n\n    bool operator==(const Modint& p) const { return\
    \ x == p.x; }\n    bool operator!=(const Modint& p) const { return x != p.x; }\n\
    \n    Modint inv() const {\n        int a = x, b = mod, u = 1, v = 0, t;\n   \
    \     while (b > 0) {\n            t = a / b;\n            swap(a -= t * b, b);\n\
    \            swap(u -= t * v, v);\n        }\n        return Modint(u);\n    }\n\
    \n    Modint pow(long long n) const {\n        Modint ret(1), mul(x);\n      \
    \  while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n\
    \            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream\
    \ &operator<<(ostream& os, const Modint& p) {\n        return os << p.x;\n   \
    \ }\n\n    friend istream &operator>>(istream& is, Modint& a) {\n        long\
    \ long t;\n        is >> t;\n        a = Modint<mod>(t);\n        return is;\n\
    \    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <int mod>\nstruct\
    \ Modint {\n    int x;\n\n    Modint() : x(0) {}\n    Modint(long long y) : x(y\
    \ >= 0 ? y % mod : y % mod + mod) {}\n\n    Modint& operator+=(const Modint& p)\
    \ { if ((x += p.x) >= mod) x -= mod; return *this; }\n    Modint& operator-=(const\
    \ Modint& p) { if ((x += mod - p.x) >= mod) x -= mod; return *this; }\n    Modint&\
    \ operator*=(const Modint& p) { x = (int) (1LL * x * p.x % mod); return *this;\
    \ }\n    Modint& operator/=(const Modint& p) { *this *= p.inv(); return *this;\
    \ }\n\n    Modint operator-() const { return Modint(-x); }\n\n    Modint operator+(const\
    \ Modint& p) const { return Modint(*this) += p; }\n    Modint operator-(const\
    \ Modint& p) const { return Modint(*this) -= p; }\n    Modint operator*(const\
    \ Modint& p) const { return Modint(*this) *= p; }\n    Modint operator/(const\
    \ Modint& p) const { return Modint(*this) /= p; }\n\n    bool operator==(const\
    \ Modint& p) const { return x == p.x; }\n    bool operator!=(const Modint& p)\
    \ const { return x != p.x; }\n\n    Modint inv() const {\n        int a = x, b\
    \ = mod, u = 1, v = 0, t;\n        while (b > 0) {\n            t = a / b;\n \
    \           swap(a -= t * b, b);\n            swap(u -= t * v, v);\n        }\n\
    \        return Modint(u);\n    }\n\n    Modint pow(long long n) const {\n   \
    \     Modint ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1)\
    \ ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n    \
    \    return ret;\n    }\n\n    friend ostream &operator<<(ostream& os, const Modint&\
    \ p) {\n        return os << p.x;\n    }\n\n    friend istream &operator>>(istream&\
    \ is, Modint& a) {\n        long long t;\n        is >> t;\n        a = Modint<mod>(t);\n\
    \        return is;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy: []
  timestamp: '2020-09-22 01:15:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/modint.cpp
layout: document
redirect_from:
- /library/math/modint.cpp
- /library/math/modint.cpp.html
title: math/modint.cpp
---
