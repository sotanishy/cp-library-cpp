---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/gcd_lcm_convolution.hpp
    title: GCD/LCM Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/divisor_zeta_moebius_transform.hpp\"\n#include\
    \ <vector>\n\ntemplate <typename T>\nvoid divisor_fzt(std::vector<T>& a) {\n \
    \   const int n = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int\
    \ p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        for (int k =\
    \ 1; k * p < n; ++k) {\n            sieve[k * p] = false;\n            a[k * p]\
    \ += a[k];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_fmt(std::vector<T>&\
    \ a) {\n    const int n = a.size();\n    std::vector<bool> sieve(n, true);\n \
    \   for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        for\
    \ (int k = (n - 1) / p; k > 0; --k) {\n            sieve[k * p] = false;\n   \
    \         a[k * p] -= a[k];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ multiple_fzt(std::vector<T>& a) {\n    const int n = a.size();\n    std::vector<bool>\
    \ sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n\
    \        for (int k = (n - 1) / p; k > 0; --k) {\n            sieve[k * p] = false;\n\
    \            a[k] += a[k * p];\n        }\n    }\n}\n\ntemplate <typename T>\n\
    void multiple_fmt(std::vector<T>& a) {\n    const int n = a.size();\n    std::vector<bool>\
    \ sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n\
    \        for (int k = 1; k * p < n; ++k) {\n            sieve[k * p] = false;\n\
    \            a[k] -= a[k * p];\n        }\n    }\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nvoid divisor_fzt(std::vector<T>&\
    \ a) {\n    const int n = a.size();\n    std::vector<bool> sieve(n, true);\n \
    \   for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        for\
    \ (int k = 1; k * p < n; ++k) {\n            sieve[k * p] = false;\n         \
    \   a[k * p] += a[k];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_fmt(std::vector<T>&\
    \ a) {\n    const int n = a.size();\n    std::vector<bool> sieve(n, true);\n \
    \   for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        for\
    \ (int k = (n - 1) / p; k > 0; --k) {\n            sieve[k * p] = false;\n   \
    \         a[k * p] -= a[k];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ multiple_fzt(std::vector<T>& a) {\n    const int n = a.size();\n    std::vector<bool>\
    \ sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n\
    \        for (int k = (n - 1) / p; k > 0; --k) {\n            sieve[k * p] = false;\n\
    \            a[k] += a[k * p];\n        }\n    }\n}\n\ntemplate <typename T>\n\
    void multiple_fmt(std::vector<T>& a) {\n    const int n = a.size();\n    std::vector<bool>\
    \ sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n\
    \        for (int k = 1; k * p < n; ++k) {\n            sieve[k * p] = false;\n\
    \            a[k] -= a[k * p];\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/divisor_zeta_moebius_transform.hpp
  requiredBy:
  - convolution/gcd_lcm_convolution.hpp
  timestamp: '2024-01-07 22:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/gcd_convolution.test.cpp
  - test/yosupo/lcm_convolution.test.cpp
documentation_of: convolution/divisor_zeta_moebius_transform.hpp
layout: document
title: "Multiple/Divisor Fast Zeta/M\xF6bius Transform"
---

## Description

約数に関する zeta 変換は，写像 $f$ が与えられたとき，以下を満たす写像 $g$ を得る変換である．Möbius 変換は，zeta 変換の逆変換である (つまり，写像 $g$ が与えられたとき，以下を満たす写像 $f$ を得る変換である)．

$$
g(n) = \sum_{m | n} f(m)
$$

倍数に関する変換も同様である．

約数に関する FZT/FMT を用いると，LCM convolution が高速に計算できる．

$$
c_k = \sum_{\mathrm{lcm}(i,j)=k} a_i b_j
$$

倍数に関する FZT/FMT を用いると，GCD convolution が高速に計算できる．

$$
c_k = \sum_{\gcd(i,j)=k} a_i b_j
$$

## Operations

- `void divisor_fzt(vector<T> a)`
- `void multiple_fzt(vector<T> a)`
    - 数列 $a$ を約数/倍数に関して高速 zeta 変換する
    - 時間計算量: $O(n\log\log n)$
- `void divisor_fmt(vector<T> a)`
- `void multiple_fzt(vector<T> a)`
    - 数列 $a$ を約数に関して高速 Möbius 変換する
    - 時間計算量: $O(n\log\log n)$

## Note

| 畳み込み | 変換 | 逆変換 |
| $\max$ | zeta 変換 (累積和，下位) | Möbius 変換 (累積和，下位) |
| $\min$ | zeta 変換 (累積和，上位) | Möbius 変換 (累積和，上位) |
| $\gcd$ | zeta 変換 (倍数) | Möbius 変換 (倍数) |
| $\mathrm{lcm}$ | zeta 変換 (約数) | Möbius 変換 (約数) |
| $\mathrm{bitwise\ and}$ | zeta 変換 (bit，上位) | Möbius 変換 (bit，上位) |
| $\mathrm{bitwise\ or}$ | zeta 変換 (bit，下位) | Möbius 変換 (bit，下位) |
| $\mathrm{bitwise\ xor}$ | Walsh-Hadamard 変換 | 逆 Walsh-Hadamard 変換 |
| $+$ | Fourier 変換，数論変換 | 逆 Fourier 変換，逆数論変換 |

## Reference

- [ゼータ変換・メビウス変換を理解する - Qiita](https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5)
    - これを読むと，zeta/Möbius 変換が絡む一連の畳み込み操作に関して完全に理解した気持ちになれる．
- [高速ゼータ変換の約数版 O(N log(log(N))) - noshi91のメモ](https://noshi91.hatenablog.com/entry/2018/12/27/121649)
    - 約数に関する FZT/FMT を高速に計算する方法が書かれている (通常は $O(n\log n)$)．