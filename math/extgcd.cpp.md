---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/extgcd.cpp\"\n#include <algorithm>\n#include <utility>\n\
    \nstd::pair<long long, long long> extgcd(long long a, long long b) {\n    long\
    \ long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;\n    while (t) {\n      \
    \  long long q = s / t;\n        std::swap(s -= t * q, t);\n        std::swap(sx\
    \ -= tx * q, tx);\n        std::swap(sy -= ty * q, ty);\n    }\n    return {sx,\
    \ sy};\n}\n\nlong long mod_inv(long long a, long long mod) {\n    long long inv\
    \ = extgcd(a, mod).first;\n    return (inv % mod + mod) % mod;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n\nstd::pair<long\
    \ long, long long> extgcd(long long a, long long b) {\n    long long s = a, sx\
    \ = 1, sy = 0, t = b, tx = 0, ty = 1;\n    while (t) {\n        long long q =\
    \ s / t;\n        std::swap(s -= t * q, t);\n        std::swap(sx -= tx * q, tx);\n\
    \        std::swap(sy -= ty * q, ty);\n    }\n    return {sx, sy};\n}\n\nlong\
    \ long mod_inv(long long a, long long mod) {\n    long long inv = extgcd(a, mod).first;\n\
    \    return (inv % mod + mod) % mod;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy: []
  timestamp: '2021-02-06 00:41:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.cpp
layout: document
title: Extended Euclidean Algorithm
---

## Description

拡張ユークリッドの互除法は，2変数1次ディオファントス方程式 $ax + by = \gcd(a, b)$ の解 $(x, y)$ を1組求めるアルゴリズムである．

また，これを利用して $a$ の $\mod mod$ での逆元を求めることができる．フェルマーの小定理を利用したアルゴリズムより制約が少なく定数倍高速であるため，基本的にこちらを用いる．

- `pair<long long, long long> extgcd(long long a, long long b)`
    - $ax + by = \gcd(a, b)$ の解 $(x, y)$ を1組求める
    - 時間計算量: $O(\log \min(a, b))$
- `long long mod_inv(long long a, long long mod)`
    - $a$ の $\mod mod$ での逆元を求める