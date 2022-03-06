---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/transform.cpp\"\n#include <vector>\n\n/*\n * Fast Zeta/Moebius\
    \ Transform\n */\n\ntemplate <typename T>\nvoid fzt(std::vector<T>& a, bool subset)\
    \ {\n    int k = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i)\
    \ {\n        for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1)\
    \ == subset) a[j] += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename\
    \ T>\nvoid fmt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if ((j >> i & 1) == subset) a[j] -= a[j ^ (1 << i)];\n      \
    \  }\n    }\n}\n\n/*\n * Divisor Fast Zeta/Moebius Transform\n */\n\ntemplate\
    \ <typename T>\nvoid divisor_fzt(std::vector<T>& a, bool subset) {\n    int n\
    \ = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int p = 2; p <\
    \ n; ++p) {\n        if (!sieve[p]) continue;\n        if (subset) {\n       \
    \     for (int k = 1; k * p < n; ++k) {\n                sieve[k * p] = false;\n\
    \                a[k * p] += a[k];\n            }\n        } else {\n        \
    \    for (int k = (n - 1) / p; k > 0; --k) {\n                sieve[k * p] = false;\n\
    \                a[k] += a[k * p];\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid divisor_fmt(std::vector<T>& a, bool subset) {\n    int n\
    \ = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int p = 2; p <\
    \ n; ++p) {\n        if (!sieve[p]) continue;\n        if (subset) {\n       \
    \     for (int k = (n - 1) / p; k > 0; --k) {\n                sieve[k * p] =\
    \ false;\n                a[k * p] -= a[k];\n            }\n        } else {\n\
    \            for (int k = 1; k * p < n; ++k) {\n                sieve[k * p] =\
    \ false;\n                a[k] -= a[k * p];\n            }\n        }\n    }\n\
    }\n\n/*\n * Fast Walsh-Hadamard Transform\n */\n\ntemplate <typename T>\nvoid\
    \ fwht(std::vector<T>& a) {\n    int n = a.size();\n    for (int h = 1; h < n;\
    \ h <<= 1) {\n        for (int i = 0; i < n; i += h << 1) {\n            for (int\
    \ j = i; j < i + h; ++j) {\n                T x = a[j];\n                T y =\
    \ a[j | h];\n                a[j] = x + y;\n                a[j | h] = x - y;\n\
    \            }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid ifwht(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int h = 1; h < n; h <<= 1) {\n       \
    \ for (int i = 0; i < n; i += h << 1) {\n            for (int j = i; j < i + h;\
    \ ++j) {\n                T x = a[j];\n                T y = a[j | h];\n     \
    \           a[j] = (x + y) / 2;\n                a[j | h] = (x - y) / 2;\n   \
    \         }\n        }\n    }\n}\n"
  code: "#pragma once\n#include <vector>\n\n/*\n * Fast Zeta/Moebius Transform\n */\n\
    \ntemplate <typename T>\nvoid fzt(std::vector<T>& a, bool subset) {\n    int k\
    \ = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i) {\n       \
    \ for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1) == subset)\
    \ a[j] += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ fmt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if ((j >> i & 1) == subset) a[j] -= a[j ^ (1 << i)];\n      \
    \  }\n    }\n}\n\n/*\n * Divisor Fast Zeta/Moebius Transform\n */\n\ntemplate\
    \ <typename T>\nvoid divisor_fzt(std::vector<T>& a, bool subset) {\n    int n\
    \ = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int p = 2; p <\
    \ n; ++p) {\n        if (!sieve[p]) continue;\n        if (subset) {\n       \
    \     for (int k = 1; k * p < n; ++k) {\n                sieve[k * p] = false;\n\
    \                a[k * p] += a[k];\n            }\n        } else {\n        \
    \    for (int k = (n - 1) / p; k > 0; --k) {\n                sieve[k * p] = false;\n\
    \                a[k] += a[k * p];\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid divisor_fmt(std::vector<T>& a, bool subset) {\n    int n\
    \ = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int p = 2; p <\
    \ n; ++p) {\n        if (!sieve[p]) continue;\n        if (subset) {\n       \
    \     for (int k = (n - 1) / p; k > 0; --k) {\n                sieve[k * p] =\
    \ false;\n                a[k * p] -= a[k];\n            }\n        } else {\n\
    \            for (int k = 1; k * p < n; ++k) {\n                sieve[k * p] =\
    \ false;\n                a[k] -= a[k * p];\n            }\n        }\n    }\n\
    }\n\n/*\n * Fast Walsh-Hadamard Transform\n */\n\ntemplate <typename T>\nvoid\
    \ fwht(std::vector<T>& a) {\n    int n = a.size();\n    for (int h = 1; h < n;\
    \ h <<= 1) {\n        for (int i = 0; i < n; i += h << 1) {\n            for (int\
    \ j = i; j < i + h; ++j) {\n                T x = a[j];\n                T y =\
    \ a[j | h];\n                a[j] = x + y;\n                a[j | h] = x - y;\n\
    \            }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid ifwht(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int h = 1; h < n; h <<= 1) {\n       \
    \ for (int i = 0; i < n; i += h << 1) {\n            for (int j = i; j < i + h;\
    \ ++j) {\n                T x = a[j];\n                T y = a[j | h];\n     \
    \           a[j] = (x + y) / 2;\n                a[j | h] = (x - y) / 2;\n   \
    \         }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/transform.cpp
  requiredBy: []
  timestamp: '2021-12-04 19:51:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/lcm_convolution.test.cpp
  - test/yosupo/gcd_convolution.test.cpp
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
documentation_of: math/transform.cpp
layout: document
title: Transform
---

## Description

変換アルゴリズム詰め合わせ

## Fast Zeta/Möbius Transform

Zeta 変換 (下位集合) は，写像 $f$ から以下を満たす写像 $g$ を求める．Möbius 変換は，写像 $g$ から以下を満たす写像 $f$ を求める．

$$
g(S) = \sum_{T \subseteq S} f(T)
$$

上位集合も同様である．

以下の関数はすべて $a$ が2冪であることを必要とする．

- `void fzt(vector<T> a, bool subset)`
    - $a$ を高速 zeta 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
- `void fmt(vector<T> a, bool subset)`
    - $a$ を高速 Möbius 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$

## Divisor Fast Zeta/Möbius Transform

約数に関する zeta 変換 (下位集合) は，写像 $f$ から以下を満たす写像 $g$ を求める．Möbius 変換は，写像 $g$ から以下を満たす写像 $f$ を求める．

$$
g(n) = \sum_{m | n} f(m)
$$

上位集合も同様である．

- `void divisor_fzt(vector<T> a, bool subset)`
    - $a$ を約数に関して高速 zeta 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
- `void divisor_fmt(vector<T> a, bool subset)`
    - $a$ を約数に関して高速 Möbius 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$

## Fast Walsh-Hadamard Transform

高速 Walsh-Hadamard 変換を使うと，添え字 xor の畳み込みができる．

以下の関数はすべて $a$ が2冪であることを必要とする．

- `void fwht(vector<T> a)`
    - $a$ を高速 Walsh-Hadamard 変換する
    - 時間計算量: $n\lg n$
- `void ifwht(vector<T> a)`
    - $a$ を逆高速 Walsh-Hadamard 変換する
    - 時間計算量: $n\lg n$


## Note

| 畳み込み | 変換 | 逆変換 |
| $\max$ | zeta 変換 (累積和，下位) | Möbius 変換 (累積和，下位) |
| $\min$ | zeta 変換 (累積和，上位) | Möbius 変換 (累積和，上位) |
| $\gcd$ | zeta 変換 (約数，上位) | Möbius 変換 (約数，上位) |
| $\mathrm{lcm}$ | zeta 変換 (約数，下位) | Möbius 変換 (約数，下位) |
| $\mathrm{bitwise\ or}$ | zeta 変換 (bit，下位) | Möbius 変換 (bit，下位) |
| $\mathrm{bitwise\ and}$ | zeta 変換 (bit，下位) | Möbius 変換 (bit，下位) |
| $\mathrm{bitwise\ xor}$ | Walsh-Hadamard 変換 | 逆 Walsh-Hadamard 変換 |
| $+$ | Fourier 変換，数論変換 | 逆 Fourier 変換，逆数論変換 |



