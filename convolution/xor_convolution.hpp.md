---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/xor_convolution.hpp\"\n#include <vector>\n\n\
    template <typename T>\nvoid fwht(std::vector<T>& a) {\n    int n = a.size();\n\
    \    for (int h = 1; h < n; h <<= 1) {\n        for (int i = 0; i < n; i += h\
    \ << 1) {\n            for (int j = i; j < i + h; ++j) {\n                T x\
    \ = a[j];\n                T y = a[j | h];\n                a[j] = x + y;\n  \
    \              a[j | h] = x - y;\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid ifwht(std::vector<T>& a) {\n    int n = a.size();\n    for\
    \ (int h = 1; h < n; h <<= 1) {\n        for (int i = 0; i < n; i += h << 1) {\n\
    \            for (int j = i; j < i + h; ++j) {\n                T x = a[j];\n\
    \                T y = a[j | h];\n                a[j] = (x + y) / 2;\n      \
    \          a[j | h] = (x - y) / 2;\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nstatic std::vector<double> xor_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    int size = std::max(a.size(), b.size());\n    int n = 1;\n    while\
    \ (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n    fwht(a);\n    fwht(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    ifwht(a);\n    return a;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nvoid fwht(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int h = 1; h < n; h <<= 1) {\n       \
    \ for (int i = 0; i < n; i += h << 1) {\n            for (int j = i; j < i + h;\
    \ ++j) {\n                T x = a[j];\n                T y = a[j | h];\n     \
    \           a[j] = x + y;\n                a[j | h] = x - y;\n            }\n\
    \        }\n    }\n}\n\ntemplate <typename T>\nvoid ifwht(std::vector<T>& a) {\n\
    \    int n = a.size();\n    for (int h = 1; h < n; h <<= 1) {\n        for (int\
    \ i = 0; i < n; i += h << 1) {\n            for (int j = i; j < i + h; ++j) {\n\
    \                T x = a[j];\n                T y = a[j | h];\n              \
    \  a[j] = (x + y) / 2;\n                a[j | h] = (x - y) / 2;\n            }\n\
    \        }\n    }\n}\n\ntemplate <typename T>\nstatic std::vector<double> xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int size = std::max(a.size(), b.size());\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    fwht(a);\n    fwht(b);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n \
    \   ifwht(a);\n    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/xor_convolution.hpp
  requiredBy: []
  timestamp: '2022-03-24 12:11:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/bitwise_xor_convolution.test.cpp
documentation_of: convolution/xor_convolution.hpp
layout: document
title: Bitwise XOR Convolution (Fast Walsh-Hadamard Transform)
---

## Description

高速 Walsh-Hadamard 変換を用いると，bitwise XOR convolution が計算できる．

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
- `vector<T> xor_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の bitwise XOR convolution を計算する
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