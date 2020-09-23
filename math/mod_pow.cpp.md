---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/mod_log.cpp
    title: Discrete Logarithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/mod_pow.md
    document_title: Mod Exponentiation
    links: []
  bundledCode: "#line 1 \"math/mod_pow.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Mod Exponentiation\n * @docs docs/math/mod_pow.md\n */\nstd::int64_t mod_pow(std::int64_t\
    \ a, std::int64_t p, std::int64_t mod) {\n    std::int64_t ret = 1;\n    while\
    \ (p > 0) {\n        if (p & 1) ret = ret * a % mod;\n        a = a * a % mod;\n\
    \        p >>= 1;\n    }\n    return ret;\n}\n\nstd::int64_t mod_inv(std::int64_t\
    \ a, std::int64_t mod) {\n    return mod_pow(a, mod - 2, mod);\n}\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Mod Exponentiation\n * @docs docs/math/mod_pow.md\n\
    \ */\nstd::int64_t mod_pow(std::int64_t a, std::int64_t p, std::int64_t mod) {\n\
    \    std::int64_t ret = 1;\n    while (p > 0) {\n        if (p & 1) ret = ret\
    \ * a % mod;\n        a = a * a % mod;\n        p >>= 1;\n    }\n    return ret;\n\
    }\n\nstd::int64_t mod_inv(std::int64_t a, std::int64_t mod) {\n    return mod_pow(a,\
    \ mod - 2, mod);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.cpp
  requiredBy:
  - math/mod_log.cpp
  timestamp: '2020-09-23 11:09:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_B.test.cpp
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