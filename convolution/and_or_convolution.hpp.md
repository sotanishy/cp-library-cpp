---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: math/matrix/hafnian.hpp
    title: Hafnian
  - icon: ':heavy_check_mark:'
    path: math/set_power_series.hpp
    title: math/set_power_series.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_set_power_series.test.cpp
    title: test/yosupo/exp_of_set_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/and_or_convolution.hpp\"\n#include <vector>\n\
    \ntemplate <typename T>\nvoid fzt(std::vector<T>& a, bool subset) {\n    int k\
    \ = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i) {\n       \
    \ for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1) == subset)\
    \ a[j] += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ fmt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if ((j >> i & 1) == subset) a[j] -= a[j ^ (1 << i)];\n      \
    \  }\n    }\n}\n\ntemplate <typename T>\nstd::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int size = std::max(a.size(), b.size());\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    fzt(a, true);\n    fzt(b, true);\n    for (int i = 0; i < n; ++i) a[i] *=\
    \ b[i];\n    fmt(a, true);\n    return a;\n}\n\ntemplate <typename T>\nstd::vector<T>\
    \ and_convolution(std::vector<T> a, std::vector<T> b) {\n    int size = std::max(a.size(),\
    \ b.size());\n    int n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n\
    \    b.resize(n);\n    fzt(a, false);\n    fzt(b, false);\n    for (int i = 0;\
    \ i < n; ++i) a[i] *= b[i];\n    fmt(a, false);\n    return a;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nvoid fzt(std::vector<T>&\
    \ a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n    for (int i\
    \ = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j) {\n         \
    \   if ((j >> i & 1) == subset) a[j] += a[j ^ (1 << i)];\n        }\n    }\n}\n\
    \ntemplate <typename T>\nvoid fmt(std::vector<T>& a, bool subset) {\n    int k\
    \ = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i) {\n       \
    \ for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1) == subset)\
    \ a[j] -= a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nstd::vector<T>\
    \ or_convolution(std::vector<T> a, std::vector<T> b) {\n    int size = std::max(a.size(),\
    \ b.size());\n    int n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n\
    \    b.resize(n);\n    fzt(a, true);\n    fzt(b, true);\n    for (int i = 0; i\
    \ < n; ++i) a[i] *= b[i];\n    fmt(a, true);\n    return a;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {\n \
    \   int size = std::max(a.size(), b.size());\n    int n = 1;\n    while (n < size)\
    \ n <<= 1;\n    a.resize(n);\n    b.resize(n);\n    fzt(a, false);\n    fzt(b,\
    \ false);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    fmt(a, false);\n\
    \    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/and_or_convolution.hpp
  requiredBy:
  - math/matrix/hafnian.hpp
  - math/set_power_series.hpp
  - convolution/subset_convolution.hpp
  timestamp: '2022-03-24 12:11:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/exp_of_set_power_series.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/subset_convolution.test.cpp
documentation_of: convolution/and_or_convolution.hpp
layout: document
title: "Bitwise AND/OR Convolution (Subset/Superset Fast Zeta/M\xF6bius Transform)"
---

## Description

下位集合に関する Zeta 変換は，写像 $f$ が与えられたとき，以下を満たす写像 $g$ を得る変換である．Möbius 変換は，zeta 変換の逆変換である (つまり，写像 $g$ が与えられたとき，以下を満たす写像 $f$ を得る変換である)．

$$
g(S) = \sum_{T \subseteq S} f(T)
$$

上位集合に関するものも同様である．

下位集合に関する FZT/FMT を用いると，bitwise OR convolution が高速に計算できる．

$$
c_k = \sum_{i\lor j=k} a_i b_j
$$

上位集合に関する FZT/FMT を用いると，bitwise AND convolution が高速に計算できる．

$$
c_k = \sum_{i\land j=k} a_i b_j
$$


## Operations

- `void fzt(vector<T> a, bool subset)`
    - 数列 $a$ を高速 zeta 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる．$a$ の長さが2冪であることを要求する．
    - 時間計算量: $O(n\log n)$
- `void fmt(vector<T> a, bool subset)`
    - 数列 $a$ を高速 Möbius 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる．$a$ の長さが2冪であることを要求する．
    - 時間計算量: $O(n\log n)$
- `vector<T> and_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の bitwise AND convolution を計算する
    - 時間計算量: $O(n\log n)$
- `vector<T> or_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の bitwise OR convolution を計算する
    - 時間計算量: $O(n\log n)$

## Note

| 畳み込み | 変換 | 逆変換 |
| $\max$ | zeta 変換 (累積和，下位) | Möbius 変換 (累積和，下位) |
| $\min$ | zeta 変換 (累積和，上位) | Möbius 変換 (累積和，上位) |
| $\gcd$ | zeta 変換 (約数，上位) | Möbius 変換 (約数，上位) |
| $\mathrm{lcm}$ | zeta 変換 (約数，下位) | Möbius 変換 (約数，下位) |
| $\mathrm{bitwise\ and}$ | zeta 変換 (bit，上位) | Möbius 変換 (bit，上位) |
| $\mathrm{bitwise\ or}$ | zeta 変換 (bit，下位) | Möbius 変換 (bit，下位) |
| $\mathrm{bitwise\ xor}$ | Walsh-Hadamard 変換 | 逆 Walsh-Hadamard 変換 |
| $+$ | Fourier 変換，数論変換 | 逆 Fourier 変換，逆数論変換 |

## Reference

- [ゼータ変換・メビウス変換を理解する - Qiita](https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5)
    - これを読むと，zeta/Möbius 変換が絡む一連の畳み込み操作に関して完全に理解した気持ちになれる．