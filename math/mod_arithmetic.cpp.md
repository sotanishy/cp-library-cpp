---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_arithmetic.cpp\"\n#include <cmath>\n#include <numeric>\n\
    #include <unordered_map>\n\n/*\n * Modular Exponentiation\n */\nlong long mod_pow(long\
    \ long a, long long p, int mod) {\n    long long ret = 1;\n    while (p > 0) {\n\
    \        if (p & 1) ret = ret * a % mod;\n        a = a * a % mod;\n        p\
    \ >>= 1;\n    }\n    return ret;\n}\n\nlong long mod_inv(long long a, int mod)\
    \ {\n    return mod_pow(a, mod - 2, mod);\n}\n\n/*\n * Discrete Logarithm\n */\n\
    int mod_log(long long a, long long b, int mod) {\n    // make a and mod coprime\n\
    \    a %= mod;\n    b %= mod;\n    long long k = 1, add = 0, g;\n    while ((g\
    \ = std::gcd(a, mod)) > 1) {\n        if (b == k) return add;\n        if (b %\
    \ g) return -1;\n        b /= g;\n        mod /= g;\n        ++add;\n        k\
    \ = k * a / g % mod;\n    }\n\n    // baby-step\n    const int m = sqrt(mod) +\
    \ 1;\n    std::unordered_map<long long, int> baby_index;\n    long long baby =\
    \ b;\n    for (int i = 0; i <= m; ++i) {\n        baby_index[baby] = i;\n    \
    \    baby = baby * a % mod;\n    }\n\n    // giant-step\n    long long am = 1;\n\
    \    for (int i = 0; i < m; ++i) am = am * a % mod;\n    long long giant = k;\n\
    \    for (int i = 1; i <= m; ++i) {\n        giant = giant * am % mod;\n     \
    \   if (baby_index.count(giant)) {\n            return i * m - baby_index[giant]\
    \ + add;\n        }\n    }\n    return -1;\n}\n\n/*\n * Quadratic Residue\n */\n\
    long long mod_sqrt(long long n, int mod) {\n    if (n == 0) return 0;\n    if\
    \ (mod == 2) return 1;\n    if (std::gcd(n, mod) != 1) return -1;\n    if (mod_pow(n,\
    \ (mod - 1) / 2, mod) == mod - 1) return -1;\n\n    int Q = mod - 1, S = 0;\n\
    \    while (!(Q & 1)) Q >>= 1, ++S;\n    long long z = 2;\n    while (true) {\n\
    \        if (mod_pow(z, (mod - 1) / 2, mod) == mod - 1) break;\n        ++z;\n\
    \    }\n    int M = S;\n    long long c = mod_pow(z, Q, mod);\n    long long t\
    \ = mod_pow(n, Q, mod);\n    long long R = mod_pow(n, (Q + 1) / 2, mod);\n   \
    \ while (t != 1) {\n        int i = 0;\n        long long s = t;\n        while\
    \ (s != 1) {\n            s = s * s % mod;\n            ++i;\n        }\n    \
    \    long long b = mod_pow(c, 1 << (M - i - 1), mod);\n        M = i;\n      \
    \  c = b * b % mod;\n        t = t * c % mod;\n        R = R * b % mod;\n    }\n\
    \    return R;\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <numeric>\n#include <unordered_map>\n\
    \n/*\n * Modular Exponentiation\n */\nlong long mod_pow(long long a, long long\
    \ p, int mod) {\n    long long ret = 1;\n    while (p > 0) {\n        if (p &\
    \ 1) ret = ret * a % mod;\n        a = a * a % mod;\n        p >>= 1;\n    }\n\
    \    return ret;\n}\n\nlong long mod_inv(long long a, int mod) {\n    return mod_pow(a,\
    \ mod - 2, mod);\n}\n\n/*\n * Discrete Logarithm\n */\nint mod_log(long long a,\
    \ long long b, int mod) {\n    // make a and mod coprime\n    a %= mod;\n    b\
    \ %= mod;\n    long long k = 1, add = 0, g;\n    while ((g = std::gcd(a, mod))\
    \ > 1) {\n        if (b == k) return add;\n        if (b % g) return -1;\n   \
    \     b /= g;\n        mod /= g;\n        ++add;\n        k = k * a / g % mod;\n\
    \    }\n\n    // baby-step\n    const int m = sqrt(mod) + 1;\n    std::unordered_map<long\
    \ long, int> baby_index;\n    long long baby = b;\n    for (int i = 0; i <= m;\
    \ ++i) {\n        baby_index[baby] = i;\n        baby = baby * a % mod;\n    }\n\
    \n    // giant-step\n    long long am = 1;\n    for (int i = 0; i < m; ++i) am\
    \ = am * a % mod;\n    long long giant = k;\n    for (int i = 1; i <= m; ++i)\
    \ {\n        giant = giant * am % mod;\n        if (baby_index.count(giant)) {\n\
    \            return i * m - baby_index[giant] + add;\n        }\n    }\n    return\
    \ -1;\n}\n\n/*\n * Quadratic Residue\n */\nlong long mod_sqrt(long long n, int\
    \ mod) {\n    if (n == 0) return 0;\n    if (mod == 2) return 1;\n    if (std::gcd(n,\
    \ mod) != 1) return -1;\n    if (mod_pow(n, (mod - 1) / 2, mod) == mod - 1) return\
    \ -1;\n\n    int Q = mod - 1, S = 0;\n    while (!(Q & 1)) Q >>= 1, ++S;\n   \
    \ long long z = 2;\n    while (true) {\n        if (mod_pow(z, (mod - 1) / 2,\
    \ mod) == mod - 1) break;\n        ++z;\n    }\n    int M = S;\n    long long\
    \ c = mod_pow(z, Q, mod);\n    long long t = mod_pow(n, Q, mod);\n    long long\
    \ R = mod_pow(n, (Q + 1) / 2, mod);\n    while (t != 1) {\n        int i = 0;\n\
    \        long long s = t;\n        while (s != 1) {\n            s = s * s % mod;\n\
    \            ++i;\n        }\n        long long b = mod_pow(c, 1 << (M - i - 1),\
    \ mod);\n        M = i;\n        c = b * b % mod;\n        t = t * c % mod;\n\
    \        R = R * b % mod;\n    }\n    return R;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_arithmetic.cpp
  requiredBy: []
  timestamp: '2021-02-06 03:15:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sqrt_mod.test.cpp
  - test/yosupo/discrete_logarithm_mod.test.cpp
  - test/aoj/NTL_1_B.test.cpp
documentation_of: math/mod_arithmetic.cpp
layout: document
title: Modular Arithmetic
---

## Description

モジュラ計算アルゴリズム詰め合わせ

## Modular Exponentiation

$a^p \mod mod$ を二分累乗法で計算する．

また，$mod$ が素数であるとき，フェルマーの小定理を利用して $n$ の $\mod mod$ での逆元を計算することができる．(拡張ユークリッド互除法を用いた逆元の計算では $mod$ が素数である必要がなく，定数倍速いため，基本的にはそちらを用いる)

- `long long mod_pow(long long a, long long p, int mod)`
    - $a^p \mod mod$ を計算する
    - 時間計算量: $O(\lg p)$

- `long long mod_inv(long long a, int mod)`
    - $a$ の $\mod mod$ での逆元を計算する
    - 時間計算量: $O(\lg mod)$

## Discrete Logarithm

離散対数を計算する．すなわち，$a^x = b (\mod mod)$ を満たす $x$ を求める．

Baby-step giant-step 法を用いている．

- `int mod_log(long long a, long long b, int mod)`
    - $a^x = b (\mod mod)$ を満たす $x$ を求める．存在しない場合は $-1$ を返す．
    - 時間計算量: $O(\sqrt{mod})$

## Quadratic Residue

平方剰余を計算する．すなわち，$r^2 = n (\mod p)$ を満たす $r$ を求める．

Tonelli-Shanks algorithm を用いている．時間計算量はよくわからない．

- `long long mod_sqrt(long long n, long long p)`
    - $r^2 = n (\mod p)$ を満たす $r$ を求める．$n = 0$ のときは $0$ を返す．$n$ と $p$ が互いに素でないときと $r$ が存在しないときは$-1$ を返す．