---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Fraction
    links: []
  bundledCode: "#line 2 \"misc/fraction.hpp\"\n#include <cmath>\n#include <iostream>\n\
    #include <numeric>\n\n/**\n * @brief Fraction\n */\ntemplate <typename T>\nstruct\
    \ Fraction {\n    T num, den;\n    Fraction(T num = 0, T den = 1) : num(num),\
    \ den(den) { reduce(); }\n    void reduce() {\n        T g = std::gcd(num, den);\n\
    \        num /= g, den /= g;\n        if (den < 0) num = -num, den = -den;\n \
    \   }\n    constexpr Fraction& operator+=(const Fraction& r) {\n        num =\
    \ num * r.den + r.num * den;\n        den *= r.den;\n        reduce();\n     \
    \   return *this;\n    }\n    constexpr Fraction& operator-=(const Fraction& r)\
    \ {\n        num = num * r.den - r.num * den;\n        den *= r.den;\n       \
    \ reduce();\n        return *this;\n    }\n    constexpr Fraction& operator*=(const\
    \ Fraction& r) {\n        num *= r.num;\n        den *= r.den;\n        reduce();\n\
    \        return *this;\n    }\n    constexpr Fraction& operator/=(const Fraction&\
    \ r) {\n        num *= r.den;\n        den *= r.num;\n        reduce();\n    \
    \    return *this;\n    }\n\n    constexpr bool operator==(const Fraction& r)\
    \ const {\n        return num * r.den == r.num * den;\n    }\n    constexpr auto\
    \ operator<=>(const Fraction& r) const {\n        return num * r.den <=> r.num\
    \ * den;\n    }\n\n    constexpr Fraction operator+() const { return *this; }\n\
    \    constexpr Fraction operator-() const { return Fraction(-num, den); }\n\n\
    \    constexpr friend Fraction operator+(const Fraction& l, const Fraction& r)\
    \ {\n        return Fraction(l) += r;\n    }\n    constexpr friend Fraction operator-(const\
    \ Fraction& l, const Fraction& r) {\n        return Fraction(l) -= r;\n    }\n\
    \    constexpr friend Fraction operator*(const Fraction& l, const Fraction& r)\
    \ {\n        return Fraction(l) *= r;\n    }\n    constexpr friend Fraction operator/(const\
    \ Fraction& l, const Fraction& r) {\n        return Fraction(l) /= r;\n    }\n\
    \n    friend ostream& operator<<(ostream& os, const Fraction& p) {\n        return\
    \ os << p.num << \"/\" << p.den;\n    }\n};\n"
  code: "#pragma once\n#include <cmath>\n#include <iostream>\n#include <numeric>\n\
    \n/**\n * @brief Fraction\n */\ntemplate <typename T>\nstruct Fraction {\n   \
    \ T num, den;\n    Fraction(T num = 0, T den = 1) : num(num), den(den) { reduce();\
    \ }\n    void reduce() {\n        T g = std::gcd(num, den);\n        num /= g,\
    \ den /= g;\n        if (den < 0) num = -num, den = -den;\n    }\n    constexpr\
    \ Fraction& operator+=(const Fraction& r) {\n        num = num * r.den + r.num\
    \ * den;\n        den *= r.den;\n        reduce();\n        return *this;\n  \
    \  }\n    constexpr Fraction& operator-=(const Fraction& r) {\n        num = num\
    \ * r.den - r.num * den;\n        den *= r.den;\n        reduce();\n        return\
    \ *this;\n    }\n    constexpr Fraction& operator*=(const Fraction& r) {\n   \
    \     num *= r.num;\n        den *= r.den;\n        reduce();\n        return\
    \ *this;\n    }\n    constexpr Fraction& operator/=(const Fraction& r) {\n   \
    \     num *= r.den;\n        den *= r.num;\n        reduce();\n        return\
    \ *this;\n    }\n\n    constexpr bool operator==(const Fraction& r) const {\n\
    \        return num * r.den == r.num * den;\n    }\n    constexpr auto operator<=>(const\
    \ Fraction& r) const {\n        return num * r.den <=> r.num * den;\n    }\n\n\
    \    constexpr Fraction operator+() const { return *this; }\n    constexpr Fraction\
    \ operator-() const { return Fraction(-num, den); }\n\n    constexpr friend Fraction\
    \ operator+(const Fraction& l, const Fraction& r) {\n        return Fraction(l)\
    \ += r;\n    }\n    constexpr friend Fraction operator-(const Fraction& l, const\
    \ Fraction& r) {\n        return Fraction(l) -= r;\n    }\n    constexpr friend\
    \ Fraction operator*(const Fraction& l, const Fraction& r) {\n        return Fraction(l)\
    \ *= r;\n    }\n    constexpr friend Fraction operator/(const Fraction& l, const\
    \ Fraction& r) {\n        return Fraction(l) /= r;\n    }\n\n    friend ostream&\
    \ operator<<(ostream& os, const Fraction& p) {\n        return os << p.num <<\
    \ \"/\" << p.den;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/fraction.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/fraction.hpp
layout: document
redirect_from:
- /library/misc/fraction.hpp
- /library/misc/fraction.hpp.html
title: Fraction
---
