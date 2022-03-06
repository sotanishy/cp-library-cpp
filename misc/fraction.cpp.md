---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Fraction
    links: []
  bundledCode: "#line 2 \"misc/fraction.cpp\"\n#include <numeric>\n\n/*\n * @brief\
    \ Fraction\n */\ntemplate <typename T>\nstruct Fraction {\n    T num, den;\n \
    \   Fraction(T num = 0, T den = 1) : num(num), den(den) { reduce(); }\n    void\
    \ reduce() {\n        T g = std::gcd(num, den);\n        num /= g, den /= g;\n\
    \        if (den < 0) num = -num, den = -den;\n    }\n    Fraction& operator+=(const\
    \ Fraction& rhs) {\n        num = num*rhs.den + rhs.num*den;\n        den *= rhs.den;\n\
    \        reduce();\n        return *this;\n    }\n    Fraction& operator-=(const\
    \ Fraction& rhs) {\n        num = num*rhs.den - rhs.num*den;\n        den *= rhs.den;\n\
    \        reduce();\n        return *this;\n    }\n    Fraction& operator*=(const\
    \ Fraction& rhs) {\n        num *= rhs.num;\n        den *= rhs.den;\n       \
    \ reduce();\n        return *this;\n    }\n    Fraction& operator/=(const Fraction&\
    \ rhs) {\n        num *= rhs.den;\n        den *= rhs.num;\n        reduce();\n\
    \        return *this;\n    }\n    Fraction operator-() const { return Fraction(-num,\
    \ den); }\n    Fraction operator+(const Fraction& rhs) const { return Fraction(*this)\
    \ += rhs; }\n    Fraction operator-(const Fraction& rhs) const { return Fraction(*this)\
    \ -= rhs; }\n    Fraction operator*(const Fraction& rhs) const { return Fraction(*this)\
    \ *= rhs; }\n    Fraction operator/(const Fraction& rhs) const { return Fraction(*this)\
    \ /= rhs; }\n    bool operator==(const Fraction& rhs) const { return num*rhs.den\
    \ == rhs.num*den; }\n    bool operator!=(const Fraction& rhs) const { return !(*this\
    \ == rhs); }\n    bool operator<(const Fraction& rhs) const { return num*rhs.den\
    \ < rhs.num*den; };\n    bool operator>(const Fraction& rhs) const { return num*rhs.den\
    \ > rhs.num*den; };\n    bool operator<=(const Fraction& rhs) const { return !(*this\
    \ > rhs); };\n    bool operator>=(const Fraction& rhs) const { return !(*this\
    \ < rhs); };\n    friend ostream &operator<<(ostream& os, const Fraction& p) {\
    \ return os << p.num << \"/\" << p.den; }\n};\n"
  code: "#pragma once\n#include <numeric>\n\n/*\n * @brief Fraction\n */\ntemplate\
    \ <typename T>\nstruct Fraction {\n    T num, den;\n    Fraction(T num = 0, T\
    \ den = 1) : num(num), den(den) { reduce(); }\n    void reduce() {\n        T\
    \ g = std::gcd(num, den);\n        num /= g, den /= g;\n        if (den < 0) num\
    \ = -num, den = -den;\n    }\n    Fraction& operator+=(const Fraction& rhs) {\n\
    \        num = num*rhs.den + rhs.num*den;\n        den *= rhs.den;\n        reduce();\n\
    \        return *this;\n    }\n    Fraction& operator-=(const Fraction& rhs) {\n\
    \        num = num*rhs.den - rhs.num*den;\n        den *= rhs.den;\n        reduce();\n\
    \        return *this;\n    }\n    Fraction& operator*=(const Fraction& rhs) {\n\
    \        num *= rhs.num;\n        den *= rhs.den;\n        reduce();\n       \
    \ return *this;\n    }\n    Fraction& operator/=(const Fraction& rhs) {\n    \
    \    num *= rhs.den;\n        den *= rhs.num;\n        reduce();\n        return\
    \ *this;\n    }\n    Fraction operator-() const { return Fraction(-num, den);\
    \ }\n    Fraction operator+(const Fraction& rhs) const { return Fraction(*this)\
    \ += rhs; }\n    Fraction operator-(const Fraction& rhs) const { return Fraction(*this)\
    \ -= rhs; }\n    Fraction operator*(const Fraction& rhs) const { return Fraction(*this)\
    \ *= rhs; }\n    Fraction operator/(const Fraction& rhs) const { return Fraction(*this)\
    \ /= rhs; }\n    bool operator==(const Fraction& rhs) const { return num*rhs.den\
    \ == rhs.num*den; }\n    bool operator!=(const Fraction& rhs) const { return !(*this\
    \ == rhs); }\n    bool operator<(const Fraction& rhs) const { return num*rhs.den\
    \ < rhs.num*den; };\n    bool operator>(const Fraction& rhs) const { return num*rhs.den\
    \ > rhs.num*den; };\n    bool operator<=(const Fraction& rhs) const { return !(*this\
    \ > rhs); };\n    bool operator>=(const Fraction& rhs) const { return !(*this\
    \ < rhs); };\n    friend ostream &operator<<(ostream& os, const Fraction& p) {\
    \ return os << p.num << \"/\" << p.den; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/fraction.cpp
  requiredBy: []
  timestamp: '2022-03-06 20:10:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/fraction.cpp
layout: document
redirect_from:
- /library/misc/fraction.cpp
- /library/misc/fraction.cpp.html
title: Fraction
---
