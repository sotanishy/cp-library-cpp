---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/linalg/hafnian.hpp
    title: Hafnian
  - icon: ':heavy_check_mark:'
    path: math/set/and_or_convolution.hpp
    title: Bitwise AND/OR Convolution
  - icon: ':heavy_check_mark:'
    path: math/set/set_power_series.hpp
    title: Set Power Series
  - icon: ':heavy_check_mark:'
    path: math/set/subset_convolution.hpp
    title: Subset Convolution
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
  bundledCode: "#line 2 \"math/set/zeta_moebius_transform.hpp\"\n#include <bit>\n\
    #include <cassert>\n#include <vector>\n\ntemplate <typename T>\nvoid superset_fzt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j] += a[j | i];\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid superset_fmt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j] -= a[j | i];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid subset_fzt(std::vector<T>& a)\
    \ {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j | i] += a[j];\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid subset_fmt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j | i] -= a[j];\n   \
    \     }\n    }\n}\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <vector>\n\ntemplate\
    \ <typename T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j] += a[j | i];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid superset_fmt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j] -= a[j | i];\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid subset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j | i] += a[j];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid subset_fmt(std::vector<T>& a)\
    \ {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j | i] -= a[j];\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/set/zeta_moebius_transform.hpp
  requiredBy:
  - math/linalg/hafnian.hpp
  - math/set/and_or_convolution.hpp
  - math/set/subset_convolution.hpp
  - math/set/set_power_series.hpp
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/exp_of_set_power_series.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
  - test/yosupo/subset_convolution.test.cpp
documentation_of: math/set/zeta_moebius_transform.hpp
layout: document
title: "Fast Zeta/M\xF6bius Transform"
---

## Description

下位集合に関する zeta 変換は，写像 $f$ が与えられたとき，以下を満たす写像 $g$ を得る変換である．Möbius 変換は，zeta 変換の逆変換である (つまり，写像 $g$ が与えられたとき，以下を満たす写像 $f$ を得る変換である)．

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

- `void subset_fzt(vector<T> a)`
- `void superset_fzt(vector<T> a)`
    - 数列 $a$ を高速 zeta 変換する
    - 時間計算量: $O(n\log n)$
- `void subset_fmt(vector<T> a)`
- `void superset_fmt(vector<T> a)`
    - 数列 $a$ を高速 Möbius 変換する
    - 時間計算量: $O(n\log n)$

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