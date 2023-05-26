---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/stirling_second.hpp
    title: Stirling Number of the Second Kind
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/combination.cpp\"\n#include <vector>\n\ntemplate <typename\
    \ mint>\nclass Combination {\n   public:\n    Combination() = default;\n    Combination(int\
    \ n) : fact_(n + 1), fact_inv_(n + 1) {\n        fact_[0] = 1;\n        for (int\
    \ i = 1; i <= n; ++i) fact_[i] = fact_[i - 1] * i;\n        fact_inv_[n]=fact_[n].inv();\n\
    \        for (int i = n; i > 0; --i) fact_inv_[i - 1] = fact_inv_[i] * i;\n  \
    \  }\n\n    mint perm(int n, int k) const {\n        if (k < 0 || n < k) return\
    \ 0;\n        return fact_[n] * fact_inv_[n - k];\n    }\n\n    mint comb(int\
    \ n, int k) const {\n        if (k < 0 || n < k) return 0;\n        return fact_[n]\
    \ * fact_inv_[k] * fact_inv_[n - k];\n    }\n\n    mint fact(int n) const { return\
    \ fact_[n]; }\n    mint fact_inv(int n) const { return fact_inv_[n]; }\n\n   private:\n\
    \    std::vector<mint> fact_, fact_inv_;\n};\n\ntemplate <typename T>\nT comb(long\
    \ long n, int k) {\n    if (k < 0 || n < k) return 0;\n    T num = 1, den = 1;\n\
    \    for (int i = 1; i <= k; ++i) {\n        num = num * (n - i + 1);\n      \
    \  den = den * i;\n    }\n    return num / den;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename mint>\nclass Combination\
    \ {\n   public:\n    Combination() = default;\n    Combination(int n) : fact_(n\
    \ + 1), fact_inv_(n + 1) {\n        fact_[0] = 1;\n        for (int i = 1; i <=\
    \ n; ++i) fact_[i] = fact_[i - 1] * i;\n        fact_inv_[n]=fact_[n].inv();\n\
    \        for (int i = n; i > 0; --i) fact_inv_[i - 1] = fact_inv_[i] * i;\n  \
    \  }\n\n    mint perm(int n, int k) const {\n        if (k < 0 || n < k) return\
    \ 0;\n        return fact_[n] * fact_inv_[n - k];\n    }\n\n    mint comb(int\
    \ n, int k) const {\n        if (k < 0 || n < k) return 0;\n        return fact_[n]\
    \ * fact_inv_[k] * fact_inv_[n - k];\n    }\n\n    mint fact(int n) const { return\
    \ fact_[n]; }\n    mint fact_inv(int n) const { return fact_inv_[n]; }\n\n   private:\n\
    \    std::vector<mint> fact_, fact_inv_;\n};\n\ntemplate <typename T>\nT comb(long\
    \ long n, int k) {\n    if (k < 0 || n < k) return 0;\n    T num = 1, den = 1;\n\
    \    for (int i = 1; i <= k; ++i) {\n        num = num * (n - i + 1);\n      \
    \  den = den * i;\n    }\n    return num / den;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/combination.cpp
  requiredBy:
  - math/stirling_second.hpp
  timestamp: '2023-05-27 03:55:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
documentation_of: math/combination.cpp
layout: document
title: Combination
---

## Description

階乗 $n!$，組み合わせ $n \choose r$，順列 $_n \mathrm{P} _r$ を法 $mod$ で計算する．

空間計算量: $O(n)$

## Operations

- `Combination(int n)`
    - $n$ 以下の整数の階乗及びその逆元を前計算する
    - 時間計算量: $O(n)$
- `T perm(int n, int r)`
    - $_n \mathrm{P} _r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$
- `T comb(int n, int r)`
    - $n \choose r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$
- `T fact(int n)`
    - $n!$ を計算する
    - 時間計算量: $O(1)$
- `T fact_inv(int n)`
    - $n!$ の逆元を計算する
    - 時間計算量: $O(1)$

以下の関数は`Combination`クラスに含まれない

- `T comb(int n, int r)`
    - $n \choose r$ を計算する．
    - 時間計算量: $O(r)$