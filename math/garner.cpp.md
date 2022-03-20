---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/extgcd.cpp
    title: Extended Euclidean Algorithm
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/arbitrary_mod_convolution.cpp
    title: Arbitrary Mod Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/garner.cpp\"\n#include <vector>\n#line 2 \"math/extgcd.cpp\"\
    \n#include <algorithm>\n#include <utility>\n\nstd::pair<long long, long long>\
    \ extgcd(long long a, long long b) {\n    long long s = a, sx = 1, sy = 0, t =\
    \ b, tx = 0, ty = 1;\n    while (t) {\n        long long q = s / t;\n        std::swap(s\
    \ -= t * q, t);\n        std::swap(sx -= tx * q, tx);\n        std::swap(sy -=\
    \ ty * q, ty);\n    }\n    return {sx, sy};\n}\n\nlong long mod_inv(long long\
    \ a, long long mod) {\n    long long inv = extgcd(a, mod).first;\n    return (inv\
    \ % mod + mod) % mod;\n}\n#line 4 \"math/garner.cpp\"\n\nlong long garner(const\
    \ std::vector<long long>& b, std::vector<long long> m, long long mod) {\n    m.push_back(mod);\n\
    \    int n = m.size();\n    std::vector<long long> coeffs(n, 1);\n    std::vector<long\
    \ long> consts(n, 0);\n    for (int k = 0; k < n - 1; ++k) {\n        long long\
    \ t = (b[k] - consts[k]) * mod_inv(coeffs[k], m[k]) % m[k];\n        if (t < 0)\
    \ t += m[k];\n        for (int i = k + 1; i < n; ++i) {\n            consts[i]\
    \ = (consts[i] + t * coeffs[i]) % m[i];\n            coeffs[i] = coeffs[i] * m[k]\
    \ % m[i];\n        }\n    }\n    return consts.back();\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"extgcd.cpp\"\n\nlong long garner(const\
    \ std::vector<long long>& b, std::vector<long long> m, long long mod) {\n    m.push_back(mod);\n\
    \    int n = m.size();\n    std::vector<long long> coeffs(n, 1);\n    std::vector<long\
    \ long> consts(n, 0);\n    for (int k = 0; k < n - 1; ++k) {\n        long long\
    \ t = (b[k] - consts[k]) * mod_inv(coeffs[k], m[k]) % m[k];\n        if (t < 0)\
    \ t += m[k];\n        for (int i = k + 1; i < n; ++i) {\n            consts[i]\
    \ = (consts[i] + t * coeffs[i]) % m[i];\n            coeffs[i] = coeffs[i] * m[k]\
    \ % m[i];\n        }\n    }\n    return consts.back();\n}"
  dependsOn:
  - math/extgcd.cpp
  isVerificationFile: false
  path: math/garner.cpp
  requiredBy:
  - math/arbitrary_mod_convolution.cpp
  timestamp: '2022-03-20 20:27:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod_1000000007.test.cpp
documentation_of: math/garner.cpp
layout: document
title: Garner's Algorithm
---

## Description

Garner のアルゴリズムは，連立合同式 $x \equiv b_i \mod m_i \quad (i=1,\dots,n)$ の解を求めるアルゴリズムである．

$m_i$が pairwise coprime であるとき，この連立合同式には法$m = m_1\dots m_n$のもとでただ一つの解が存在することが中国の剰余定理によって保証される．

## Operations

- `long long garner(vector<long long> b, vector<long long> m, long long mod)`
    - 連立合同式を満たす最小の非負整数を法$mod$で求める．
    - 時間計算量: $O(n^2)$


## Reference

- [中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ](https://qiita.com/drken/items/ae02240cd1f8edfc86fd)
- [Chinese Remainder Theorem](https://cp-algorithms.com/algebra/chinese-remainder-theorem.html)