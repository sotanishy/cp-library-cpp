---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/gcd_lcm_convolution.hpp\"\n#include <vector>\n\
    \ntemplate <typename T>\nvoid divisor_fzt(std::vector<T>& a, bool subset) {\n\
    \    int n = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int p\
    \ = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        if (subset) {\n\
    \            for (int k = 1; k * p < n; ++k) {\n                sieve[k * p] =\
    \ false;\n                a[k * p] += a[k];\n            }\n        } else {\n\
    \            for (int k = (n - 1) / p; k > 0; --k) {\n                sieve[k\
    \ * p] = false;\n                a[k] += a[k * p];\n            }\n        }\n\
    \    }\n}\n\ntemplate <typename T>\nvoid divisor_fmt(std::vector<T>& a, bool subset)\
    \ {\n    int n = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int\
    \ p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        if (subset)\
    \ {\n            for (int k = (n - 1) / p; k > 0; --k) {\n                sieve[k\
    \ * p] = false;\n                a[k * p] -= a[k];\n            }\n        } else\
    \ {\n            for (int k = 1; k * p < n; ++k) {\n                sieve[k *\
    \ p] = false;\n                a[k] -= a[k * p];\n            }\n        }\n \
    \   }\n}\n\ntemplate <typename T>\nstd::vector<T> gcd_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = std::max(a.size(), b.size());\n    a.resize(n);\n\
    \    b.resize(n);\n    divisor_fzt(a, false);\n    divisor_fzt(b, false);\n  \
    \  for (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a, false);\n   \
    \ return a;\n}\n\ntemplate <typename T>\nstd::vector<T> lcm_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = std::max(a.size(), b.size());\n    a.resize(n);\n\
    \    b.resize(n);\n    divisor_fzt(a, true);\n    divisor_fzt(b, true);\n    for\
    \ (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a, true);\n    return\
    \ a;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nvoid divisor_fzt(std::vector<T>&\
    \ a, bool subset) {\n    int n = a.size();\n    std::vector<bool> sieve(n, true);\n\
    \    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n       \
    \ if (subset) {\n            for (int k = 1; k * p < n; ++k) {\n             \
    \   sieve[k * p] = false;\n                a[k * p] += a[k];\n            }\n\
    \        } else {\n            for (int k = (n - 1) / p; k > 0; --k) {\n     \
    \           sieve[k * p] = false;\n                a[k] += a[k * p];\n       \
    \     }\n        }\n    }\n}\n\ntemplate <typename T>\nvoid divisor_fmt(std::vector<T>&\
    \ a, bool subset) {\n    int n = a.size();\n    std::vector<bool> sieve(n, true);\n\
    \    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n       \
    \ if (subset) {\n            for (int k = (n - 1) / p; k > 0; --k) {\n       \
    \         sieve[k * p] = false;\n                a[k * p] -= a[k];\n         \
    \   }\n        } else {\n            for (int k = 1; k * p < n; ++k) {\n     \
    \           sieve[k * p] = false;\n                a[k] -= a[k * p];\n       \
    \     }\n        }\n    }\n}\n\ntemplate <typename T>\nstd::vector<T> gcd_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = std::max(a.size(), b.size());\n    a.resize(n);\n\
    \    b.resize(n);\n    divisor_fzt(a, false);\n    divisor_fzt(b, false);\n  \
    \  for (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a, false);\n   \
    \ return a;\n}\n\ntemplate <typename T>\nstd::vector<T> lcm_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int n = std::max(a.size(), b.size());\n    a.resize(n);\n\
    \    b.resize(n);\n    divisor_fzt(a, true);\n    divisor_fzt(b, true);\n    for\
    \ (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a, true);\n    return\
    \ a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/gcd_lcm_convolution.hpp
  requiredBy: []
  timestamp: '2022-03-24 13:03:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/gcd_convolution.test.cpp
  - test/yosupo/lcm_convolution.test.cpp
documentation_of: convolution/gcd_lcm_convolution.hpp
layout: document
title: "GCD/LCM Convolution (Divisor Fast Zeta/M\xF6bius Transform)"
---

## Description

約数に関する Zeta 変換 (下位集合) は，写像 $f$ が与えられたとき，以下を満たす写像 $g$ を得る変換である．Möbius 変換は，zeta 変換の逆変換である (つまり，写像 $g$ が与えられたとき，以下を満たす写像 $f$ を得る変換である)．

$$
g(n) = \sum_{m | n} f(m)
$$

上位集合も同様である．

下位集合に関する FZT/FMT を用いると，LCM convolution が高速に計算できる．

$$
c_k = \sum_{\mathrm{lcm}(i,j)=k} a_i b_j
$$

上位集合に関する FZT/FMT を用いると，GCD convolution が高速に計算できる．

$$
c_k = \sum_{\gcd(i,j)=k} a_i b_j
$$

## Operations

- `void divisor_fzt(vector<T> a, bool subset)`
    - 数列 $a$ を約数に関して高速 zeta 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる．
    - 時間計算量: $O(n\log\log n)$
- `void divisor_fmt(vector<T> a, bool subset)`
    - 数列 $a$ を約数に関して高速 Möbius 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる．
    - 時間計算量: $O(n\log\log n)$
- `vector<T> gcd_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の GCD convolution を計算する
    - 時間計算量: $O(n\log\log n)$
- `vector<T> lcm_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の LCM convolution を計算する
    - 時間計算量: $O(n\log\log n)$

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
- [高速ゼータ変換の約数版 O(N log(log(N))) - noshi91のメモ](https://noshi91.hatenablog.com/entry/2018/12/27/121649)
    - 約数に関する FZT/FMT を高速に計算する方法が書かれている (通常は $O(n\log n)$)．