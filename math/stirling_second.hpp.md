---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: math/combination.cpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/stirling_second.hpp\"\n#include <vector>\n#line 3 \"\
    convolution/ntt.hpp\"\n\nconstexpr int get_primitive_root(int mod) {\n    if (mod\
    \ == 167772161) return 3;\n    if (mod == 469762049) return 3;\n    if (mod ==\
    \ 754974721) return 11;\n    if (mod == 998244353) return 3;\n    if (mod == 1224736769)\
    \ return 3;\n}\n\ntemplate <typename T>\nvoid bit_reverse(std::vector<T>& a) {\n\
    \    int n = a.size();\n    for (int i = 0, j = 1; j < n - 1; ++j) {\n       \
    \ for (int k = n >> 1; k > (i ^= k); k >>= 1);\n        if (i < j) std::swap(a[i],\
    \ a[j]);\n    }\n}\n\ntemplate <typename mint>\nvoid ntt(std::vector<mint>& a,\
    \ bool ordered = false) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    int n = a.size();\n  \
    \  for (int m = n; m > 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n        for (int s = 0; s < n / m; ++s) {\n            mint w =\
    \ 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint l =\
    \ a[s * m + i];\n                mint r = a[s * m + i + m / 2];\n            \
    \    a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n\
    \                w *= omega;\n            }\n        }\n    }\n    if (ordered)\
    \ bit_reverse(a);\n}\n\ntemplate <typename mint>\nvoid intt(std::vector<mint>&\
    \ a, bool ordered = false) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    if (ordered) bit_reverse(a);\n\
    \    int n = a.size();\n    for (int m = 2; m <= n; m <<= 1) {\n        mint omega\
    \ = primitive_root.pow((mod - 1) / m).inv();\n        for (int s = 0; s < n /\
    \ m; ++s) {\n            mint w = 1;\n            for (int i = 0; i < m / 2; ++i)\
    \ {\n                mint l = a[s * m + i];\n                mint r = a[s * m\
    \ + i + m / 2] * w;\n                a[s * m + i] = l + r;\n                a[s\
    \ * m + i + m / 2] = l - r;\n                w *= omega;\n            }\n    \
    \    }\n    }\n}\n\ntemplate <typename mint>\nstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int size = a.size() + b.size() - 1;\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    ntt(a);\n    ntt(b);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n   \
    \ intt(a);\n    a.resize(size);\n    mint n_inv = mint(n).inv();\n    for (int\
    \ i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}\n#line 3 \"math/combination.cpp\"\
    \n\ntemplate <typename mint>\nclass Combination {\n   public:\n    Combination()\
    \ = default;\n    Combination(int n) : fact_(n + 1), fact_inv_(n + 1) {\n    \
    \    fact_[0] = 1;\n        for (int i = 1; i <= n; ++i) fact_[i] = fact_[i -\
    \ 1] * i;\n        fact_inv_[n]=fact_[n].inv();\n        for (int i = n; i > 0;\
    \ --i) fact_inv_[i - 1] = fact_inv_[i] * i;\n    }\n\n    mint perm(int n, int\
    \ k) const {\n        if (k < 0 || n < k) return 0;\n        return fact_[n] *\
    \ fact_inv_[n - k];\n    }\n\n    mint comb(int n, int k) const {\n        if\
    \ (k < 0 || n < k) return 0;\n        return fact_[n] * fact_inv_[k] * fact_inv_[n\
    \ - k];\n    }\n\n    mint fact(int n) const { return fact_[n]; }\n    mint fact_inv(int\
    \ n) const { return fact_inv_[n]; }\n\n   private:\n    std::vector<mint> fact_,\
    \ fact_inv_;\n};\n\ntemplate <typename T>\nT comb(long long n, int k) {\n    if\
    \ (k < 0 || n < k) return 0;\n    T num = 1, den = 1;\n    for (int i = 1; i <=\
    \ k; ++i) {\n        num = num * (n - i + 1);\n        den = den * i;\n    }\n\
    \    return num / den;\n}\n#line 5 \"math/stirling_second.hpp\"\n\ntemplate <typename\
    \ T>\nstd::vector<T> stirling_second_table(int n) {\n    T f = 1;\n    for (int\
    \ i = 1; i <= n; ++i) f *= i;\n    f = T(1) / f;\n    std::vector<T> a(n + 1),\
    \ b(n + 1);\n    for (int i = n; i >= 0; --i) {\n        a[i] = f * (i % 2 ? -1\
    \ : 1);\n        b[i] = f * T(i).pow(n);\n        f *= i;\n    }\n    auto c =\
    \ convolution(a, b);\n    return std::vector(c.begin(), c.begin() + n + 1);\n\
    }\n\ntemplate <typename T>\nT stirling_second(int n, int k) {\n    Combination<T>\
    \ comb(n);\n    T res = 0;\n    for (int i = 0; i <= k; ++i) {\n        T tmp\
    \ = comb.comb(k, i) * T(i).pow(n);\n        if ((k - i) & 1) res -= tmp;\n   \
    \     else res += tmp;\n    }\n    res /= comb.fact(k);\n    return res;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../convolution/ntt.hpp\"\n#include\
    \ \"combination.cpp\"\n\ntemplate <typename T>\nstd::vector<T> stirling_second_table(int\
    \ n) {\n    T f = 1;\n    for (int i = 1; i <= n; ++i) f *= i;\n    f = T(1) /\
    \ f;\n    std::vector<T> a(n + 1), b(n + 1);\n    for (int i = n; i >= 0; --i)\
    \ {\n        a[i] = f * (i % 2 ? -1 : 1);\n        b[i] = f * T(i).pow(n);\n \
    \       f *= i;\n    }\n    auto c = convolution(a, b);\n    return std::vector(c.begin(),\
    \ c.begin() + n + 1);\n}\n\ntemplate <typename T>\nT stirling_second(int n, int\
    \ k) {\n    Combination<T> comb(n);\n    T res = 0;\n    for (int i = 0; i <=\
    \ k; ++i) {\n        T tmp = comb.comb(k, i) * T(i).pow(n);\n        if ((k -\
    \ i) & 1) res -= tmp;\n        else res += tmp;\n    }\n    res /= comb.fact(k);\n\
    \    return res;\n}"
  dependsOn:
  - convolution/ntt.hpp
  - math/combination.cpp
  isVerificationFile: false
  path: math/stirling_second.hpp
  requiredBy: []
  timestamp: '2023-09-02 12:26:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
documentation_of: math/stirling_second.hpp
layout: document
title: Stirling Number of the Second Kind
---

## Description

第2種 Stirling 数 ${n \brace k}$ は，以下の恒等式で定義される数である．

$$
{n \brace k} = \frac{1}{k!} \sum_{i=0}^n (-1)^{k-i} \binom{k}{i} i^n
$$


${n \brace k}$ は，$n$ 個の区別できるボールを， $k$ 個の区別できない箱に，すべての箱に1つ以上のボールが入るように分配する方法の数である．

## Operations

- `vector<T> stirling_second_table(int n)`
    - ${n \brace k}$ を各 $k=0,1,\dots,n$ について計算する
    - 時間計算量: $O(n\log n)$
- `T stirling_second(int n, int k)`
    - ${n \brace k}$ を計算する
    - 時間計算量: $O(n+k\log n)$

## Notes

第2種 Stirling 数について以下の式が成り立つ．

$$
x^n = \sum_{k=0}^n {n\brace k} x(x-1)\cdots(x-(k-1))
$$

$$
{n\brace k} = {n-1\brace k-1} + k{n-1 \brace k}
$$

## Reference

- [「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)
