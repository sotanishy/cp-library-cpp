---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_pow.cpp
    title: Mod Exponentiation
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Quadratic Residue
    links: []
  bundledCode: "#line 2 \"math/mod_sqrt.cpp\"\n#include <numeric>\n#line 2 \"math/mod_pow.cpp\"\
    \n\n/*\n * @brief Mod Exponentiation\n * @docs docs/math/mod_pow.md\n */\nlong\
    \ long mod_pow(long long a, long long p, long long mod) {\n    long long ret =\
    \ 1;\n    while (p > 0) {\n        if (p & 1) ret = ret * a % mod;\n        a\
    \ = a * a % mod;\n        p >>= 1;\n    }\n    return ret;\n}\n\nlong long mod_inv(long\
    \ long a, long long mod) {\n    return mod_pow(a, mod - 2, mod);\n}\n#line 4 \"\
    math/mod_sqrt.cpp\"\n\n/*\n * @brief Quadratic Residue\n */\nlong long mod_sqrt(long\
    \ long n, long long p) {\n    if (n == 0) return 0;\n    if (p == 2) return 1;\n\
    \    if (std::gcd(n, p) != 1) return -1;\n    if (mod_pow(n, (p - 1) / 2, p) ==\
    \ p - 1) return -1;\n    int Q = p - 1, S = 0;\n    while (!(Q & 1)) Q >>= 1,\
    \ ++S;\n    long long z = 2;\n    while (true) {\n        if (mod_pow(z, (p -\
    \ 1) / 2, p) == p - 1) break;\n        ++z;\n    }\n    int M = S;\n    long long\
    \ c = mod_pow(z, Q, p);\n    long long t = mod_pow(n, Q, p);\n    long long R\
    \ = mod_pow(n, (Q + 1) / 2, p);\n    while (t != 1) {\n        int i = 0;\n  \
    \      long long s = t;\n        while (s != 1) {\n            s = s * s % p;\n\
    \            ++i;\n        }\n        long long b = mod_pow(c, 1 << (M - i - 1),\
    \ p);\n        M = i;\n        c = b * b % p;\n        t = t * c % p;\n      \
    \  R = R * b % p;\n    }\n    return R;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include \"mod_pow.cpp\"\n\n/*\n * @brief\
    \ Quadratic Residue\n */\nlong long mod_sqrt(long long n, long long p) {\n   \
    \ if (n == 0) return 0;\n    if (p == 2) return 1;\n    if (std::gcd(n, p) !=\
    \ 1) return -1;\n    if (mod_pow(n, (p - 1) / 2, p) == p - 1) return -1;\n   \
    \ int Q = p - 1, S = 0;\n    while (!(Q & 1)) Q >>= 1, ++S;\n    long long z =\
    \ 2;\n    while (true) {\n        if (mod_pow(z, (p - 1) / 2, p) == p - 1) break;\n\
    \        ++z;\n    }\n    int M = S;\n    long long c = mod_pow(z, Q, p);\n  \
    \  long long t = mod_pow(n, Q, p);\n    long long R = mod_pow(n, (Q + 1) / 2,\
    \ p);\n    while (t != 1) {\n        int i = 0;\n        long long s = t;\n  \
    \      while (s != 1) {\n            s = s * s % p;\n            ++i;\n      \
    \  }\n        long long b = mod_pow(c, 1 << (M - i - 1), p);\n        M = i;\n\
    \        c = b * b % p;\n        t = t * c % p;\n        R = R * b % p;\n    }\n\
    \    return R;\n}"
  dependsOn:
  - math/mod_pow.cpp
  isVerificationFile: false
  path: math/mod_sqrt.cpp
  requiredBy: []
  timestamp: '2020-10-24 02:15:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sqrt_mod.test.cpp
documentation_of: math/mod_sqrt.cpp
layout: document
redirect_from:
- /library/math/mod_sqrt.cpp
- /library/math/mod_sqrt.cpp.html
title: Quadratic Residue
---
