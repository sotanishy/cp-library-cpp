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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/transform.cpp\"\n#include <vector>\n\n/*\n * Fast Zeta/Mobius\
    \ Transform\n */\n\ntemplate <typename T>\nvoid fzt(std::vector<T>& a, bool subset)\
    \ {\n    int k = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i)\
    \ {\n        for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1)\
    \ == subset) a[j] += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename\
    \ T>\nvoid fmt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if ((j >> i & 1) == subset) a[j] -= a[j ^ (1 << i)];\n      \
    \  }\n    }\n}\n\n/*\n * Divisor Fast Zeta/Mobius Transform\n */\n\ntemplate <typename\
    \ T>\nvoid divisor_fzt(std::vector<T>& a, bool subset) {\n    int n = a.size();\n\
    \    std::vector<bool> sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n  \
    \      if (!sieve[p]) continue;\n        if (subset) {\n            for (int k\
    \ = 1; k * p < n; ++k) {\n                sieve[k * p] = false;\n            \
    \    a[k * p] += a[k];\n            }\n        } else {\n            for (int\
    \ k = (n - 1) / p; k > 0; --k) {\n                sieve[k * p] = false;\n    \
    \            a[k] += a[k * p];\n            }\n        }\n    }\n}\n\ntemplate\
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
  code: "#pragma once\n#include <vector>\n\n/*\n * Fast Zeta/Mobius Transform\n */\n\
    \ntemplate <typename T>\nvoid fzt(std::vector<T>& a, bool subset) {\n    int k\
    \ = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i) {\n       \
    \ for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1) == subset)\
    \ a[j] += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ fmt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if ((j >> i & 1) == subset) a[j] -= a[j ^ (1 << i)];\n      \
    \  }\n    }\n}\n\n/*\n * Divisor Fast Zeta/Mobius Transform\n */\n\ntemplate <typename\
    \ T>\nvoid divisor_fzt(std::vector<T>& a, bool subset) {\n    int n = a.size();\n\
    \    std::vector<bool> sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n  \
    \      if (!sieve[p]) continue;\n        if (subset) {\n            for (int k\
    \ = 1; k * p < n; ++k) {\n                sieve[k * p] = false;\n            \
    \    a[k * p] += a[k];\n            }\n        } else {\n            for (int\
    \ k = (n - 1) / p; k > 0; --k) {\n                sieve[k * p] = false;\n    \
    \            a[k] += a[k * p];\n            }\n        }\n    }\n}\n\ntemplate\
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
  timestamp: '2021-02-06 03:15:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
documentation_of: math/transform.cpp
layout: document
title: Transform
---

## Description

変換アルゴリズム詰め合わせ

## Fast Zeta/Möbius Transform

ゼータ変換 (下位集合) は，写像 $f$ から以下を満たす写像 $g$ を求める．メビウス変換は，写像 $g$ から以下を満たす写像 $f$ を求める．

$$
g(S) = \sum_{T \subseteq S} f(T)
$$

上位集合も同様である．

以下の関数はすべて $a$ が2冪であることを必要とする．

- `void fzt(vector<T> a, bool subset)`
    - $a$ を高速ゼータ変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
- `void fmt(vector<T> a, bool subset)`
    - $a$ を高速メビウス変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$

## Divisor Fast Zeta/Möbius Transform

約数に関するゼータ変換 (下位集合) は，写像 $f$ から以下を満たす写像 $g$ を求める．メビウス変換は，写像 $g$ から以下を満たす写像 $f$ を求める．

$$
g(n) = \sum_{m | n} f(m)
$$

上位集合も同様である．

- `void divisor_fzt(vector<T> a, bool subset)`
    - $a$ を約数に関して高速ゼータ変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
    - ***NOT VERIFIED***
- `void divisor_fmt(vector<T> a, bool subset)`
    - $a$ を約数に関して高速メビウス変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
    - ***NOT VERIFIED***

## Fast Walsh-Hadamard Transform

高速ウォルシュ・アダマール変換を使うと，添え字 xor の畳み込みができる．

以下の関数はすべて $a$ が2冪であることを必要とする．

- `void fwht(vector<T> a)`
    - $a$ を高速ウォルシュ・アダマール変換する
    - 時間計算量: $n\lg n$
- `void ifwht(vector<T> a)`
    - $a$ を逆高速ウォルシュ・アダマール変換する
    - 時間計算量: $n\lg n$


## Note

| 畳み込み | 変換 | 逆変換 |
| $\max$ | ゼータ変換 (累積和，下位) | メビウス変換 (累積和，下位) |
| $\min$ | ゼータ変換 (累積和，上位) | メビウス変換 (累積和，上位) |
| $\gcd$ | ゼータ変換 (約数，上位) | メビウス変換 (約数，上位) |
| $\mathrm{lcm}$ | ゼータ変換 (約数，下位) | メビウス変換 (約数，下位) |
| $\mathrm{bitwise\ or}$ | ゼータ変換 (bit，下位) | メビウス変換 (bit，下位) |
| $\mathrm{bitwise\ and}$ | ゼータ変換 (bit，下位) | メビウス変換 (bit，下位) |
| $\mathrm{bitwise\ xor}$ | ウォルシュ・アダマール変換 | 逆ウォルシュ・アダマール変換 |
| $+$ | フーリエ変換，数論変換 | 逆フーリエ変換，逆数論変換 |



