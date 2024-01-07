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
  bundledCode: "#line 2 \"set/walsh_hadamard_transform.hpp\"\n#include <bit>\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <typename T>\nvoid fwht(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int h = 1; h < n; h <<= 1) {\n        for (int i = 0; i < n; i += h\
    \ << 1) {\n            for (int j = i; j < i + h; ++j) {\n                T x\
    \ = a[j], y = a[j | h];\n                a[j] = x + y;\n                a[j |\
    \ h] = x - y;\n            }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ ifwht(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n   \
    \ const int n = a.size();\n    const T inv2 = T(1) / 2;\n    for (int h = 1; h\
    \ < n; h <<= 1) {\n        for (int i = 0; i < n; i += h << 1) {\n           \
    \ for (int j = i; j < i + h; ++j) {\n                T x = a[j], y = a[j | h];\n\
    \                a[j] = (x + y) * inv2;\n                a[j | h] = (x - y) *\
    \ inv2;\n            }\n        }\n    }\n}\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <vector>\n\ntemplate\
    \ <typename T>\nvoid fwht(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int h = 1; h < n; h <<= 1) {\n        for\
    \ (int i = 0; i < n; i += h << 1) {\n            for (int j = i; j < i + h; ++j)\
    \ {\n                T x = a[j], y = a[j | h];\n                a[j] = x + y;\n\
    \                a[j | h] = x - y;\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid ifwht(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    const T inv2 = T(1) / 2;\n    for (int h = 1;\
    \ h < n; h <<= 1) {\n        for (int i = 0; i < n; i += h << 1) {\n         \
    \   for (int j = i; j < i + h; ++j) {\n                T x = a[j], y = a[j | h];\n\
    \                a[j] = (x + y) * inv2;\n                a[j | h] = (x - y) *\
    \ inv2;\n            }\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: set/walsh_hadamard_transform.hpp
  requiredBy: []
  timestamp: '2024-01-07 12:10:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: set/walsh_hadamard_transform.hpp
layout: document
title: Fast Walsh-Hadamard Transform
---

## Description

Walsh-Hadamard 変換を用いると，bitwise XOR convolution が計算できる．

$$
c_k = \sum_{i\oplus j=k} a_i b_j
$$

## Operations

- `void fwht(vector<T> a)`
    - 数列 $a$ を高速 Walsh-Hadamard 変換する
    - 時間計算量: $O(n\log n)$
- `void ifwht(vector<T> a)`
    - 数列 $a$ を逆高速 Walsh-Hadamard 変換する
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

- [Hadamard 変換とbitwise XOR convolution - sapphire15の日記](https://sapphire15.hatenablog.com/entry/2021/09/13/114900)
- [Fast Walsh Hadamard Transforms and it's inner workings - Codeforces](https://codeforces.com/blog/entry/71899)