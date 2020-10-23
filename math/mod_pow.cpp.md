---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/mod_log.cpp
    title: Discrete Logarithm
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.cpp
    title: Quadratic Residue
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/mod_pow.md
    document_title: Mod Exponentiation
    links: []
  bundledCode: "#line 2 \"math/mod_pow.cpp\"\n\n/*\n * @brief Mod Exponentiation\n\
    \ * @docs docs/math/mod_pow.md\n */\nlong long mod_pow(long long a, long long\
    \ p, long long mod) {\n    long long ret = 1;\n    while (p > 0) {\n        if\
    \ (p & 1) ret = ret * a % mod;\n        a = a * a % mod;\n        p >>= 1;\n \
    \   }\n    return ret;\n}\n\nlong long mod_inv(long long a, long long mod) {\n\
    \    return mod_pow(a, mod - 2, mod);\n}\n"
  code: "#pragma once\n\n/*\n * @brief Mod Exponentiation\n * @docs docs/math/mod_pow.md\n\
    \ */\nlong long mod_pow(long long a, long long p, long long mod) {\n    long long\
    \ ret = 1;\n    while (p > 0) {\n        if (p & 1) ret = ret * a % mod;\n   \
    \     a = a * a % mod;\n        p >>= 1;\n    }\n    return ret;\n}\n\nlong long\
    \ mod_inv(long long a, long long mod) {\n    return mod_pow(a, mod - 2, mod);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.cpp
  requiredBy:
  - math/mod_sqrt.cpp
  - math/mod_log.cpp
  timestamp: '2020-10-24 02:15:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/NTL_1_B.test.cpp
  - test/yosupo/sqrt_mod.test.cpp
documentation_of: math/mod_pow.cpp
layout: document
redirect_from:
- /library/math/mod_pow.cpp
- /library/math/mod_pow.cpp.html
title: Mod Exponentiation
---
# Mod Exponentiation

$a^p \mod mod$ を二分累乗法で計算する．

また，$mod$ が素数であるとき，フェルマーの小定理を利用して $n$ の $\mod mod$ での逆元を計算することができる．(拡張ユークリッド互除法を用いた逆元の計算では $mod$ が素数である必要がなく，定数倍速いため，基本的にはそちらを用いる)

- `long long mod_pow(long long a, long long p, long long mod)`
    - $a^p \mod mod$ を計算する
    - 時間計算量: $O(\lg p)$

- `long long mod_inv(long long a, long long mod)`
    - $a$ の $\mod mod$ での逆元を計算する
    - 時間計算量: $O(\lg mod)$