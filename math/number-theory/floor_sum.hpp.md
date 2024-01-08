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
  bundledCode: "#line 2 \"math/number-theory/floor_sum.hpp\"\n\nlong long floor_sum(long\
    \ long n, long long m, long long a, long long b) {\n    long long sum = 0;\n \
    \   if (a >= m) {\n        sum += (a / m) * n * (n - 1) / 2;\n        a %= m;\n\
    \    }\n    if (b >= m) {\n        sum += (b / m) * n;\n        b %= m;\n    }\n\
    \    long long y = (a * n + b) / m;\n    if (y == 0) return sum;\n    long long\
    \ x = (m * y - b + a - 1) / a;\n    sum += (n - x) * y + floor_sum(y, a, m, a\
    \ * x - m * y + b);\n    return sum;\n}\n"
  code: "#pragma once\n\nlong long floor_sum(long long n, long long m, long long a,\
    \ long long b) {\n    long long sum = 0;\n    if (a >= m) {\n        sum += (a\
    \ / m) * n * (n - 1) / 2;\n        a %= m;\n    }\n    if (b >= m) {\n       \
    \ sum += (b / m) * n;\n        b %= m;\n    }\n    long long y = (a * n + b) /\
    \ m;\n    if (y == 0) return sum;\n    long long x = (m * y - b + a - 1) / a;\n\
    \    sum += (n - x) * y + floor_sum(y, a, m, a * x - m * y + b);\n    return sum;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/floor_sum.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/floor_sum.hpp
layout: document
title: Sum of Floor of Linear
---

## Description

一次関数の床関数の和 $\sum_{i=0}^{N-1} \left\lfloor \frac{Ai + B}{M} \right\rfloor$ を再帰的に計算する．

計算量はユークリッドの互除法と同様に対数時間となるが，どの変数に依存するのかはよくわかっていない (僕が理解していない)．

- `long long floor_sum(long long n, long long m, long long a, long long b)`
    - $\sum_{i=0}^{N-1} \left\lfloor \frac{Ai + B}{M} \right\rfloor$ を計算する