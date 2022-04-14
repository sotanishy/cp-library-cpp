---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/lagrange_interpolation.hpp\"\n#include <vector>\n\n\
    template <typename T>\nT lagrange_interpolation(const std::vector<T>& f, long\
    \ long n) {\n    const int d = f.size() - 1;\n    std::vector<T> fact(d + 1, 1),\
    \ fact_inv(d + 1, 1);\n    for (int i = 1; i <= d; ++i) fact[i] = fact[i - 1]\
    \ * i;\n    fact_inv[d] = T(1) / fact[d];\n    for (int i = d; i > 0; --i) fact_inv[i\
    \ - 1] = fact_inv[i] * i;\n\n    std::vector<T> num(d + 1, 1);\n    T a = 1;\n\
    \    for (int i = 0; i <= d; ++i) {\n        num[i] *= a;\n        a *= n - i;\n\
    \    }\n    a = 1;\n    for (int i = d; i >= 0; --i) {\n        num[i] *= a;\n\
    \        a *= n - i;\n    }\n    T ans = 0;\n    for (int i = 0; i <= d; ++i)\
    \ {\n        ans += ((i + d) & 1 ? -1 : 1) * f[i] * num[i] * fact_inv[i] * fact_inv[d\
    \ - i];\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nT lagrange_interpolation(const\
    \ std::vector<T>& f, long long n) {\n    const int d = f.size() - 1;\n    std::vector<T>\
    \ fact(d + 1, 1), fact_inv(d + 1, 1);\n    for (int i = 1; i <= d; ++i) fact[i]\
    \ = fact[i - 1] * i;\n    fact_inv[d] = T(1) / fact[d];\n    for (int i = d; i\
    \ > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\n\n    std::vector<T> num(d + 1,\
    \ 1);\n    T a = 1;\n    for (int i = 0; i <= d; ++i) {\n        num[i] *= a;\n\
    \        a *= n - i;\n    }\n    a = 1;\n    for (int i = d; i >= 0; --i) {\n\
    \        num[i] *= a;\n        a *= n - i;\n    }\n    T ans = 0;\n    for (int\
    \ i = 0; i <= d; ++i) {\n        ans += ((i + d) & 1 ? -1 : 1) * f[i] * num[i]\
    \ * fact_inv[i] * fact_inv[d - i];\n    }\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2022-03-31 22:55:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/lagrange_interpolation.hpp
layout: document
title: Lagrange Interpolation
---

## Description

Lagrange 補間は，$d+1$ 点が与えられたときにそれらを通る$d$次以下の多項式を求めるアルゴリズムである．この多項式は一意に定まる．

## Operations

- `T lagrange_interpolation(vector<T> f, long long n)`
    - $f(0),f(1),\dots,f(d)$ が与えられたときに，$f(n)$を求める
    - 時間計算量: $O(d)$

## Reference

- [ABC208 F - Cumulative Sum 解説](https://atcoder.jp/contests/abc208/editorial/2195)
- verify: [https://atcoder.jp/contests/abc208/submissions/30592769]()