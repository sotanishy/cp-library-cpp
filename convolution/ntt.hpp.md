---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/arbitrary_mod_convolution.hpp
    title: Arbitrary Mod Convolution
  - icon: ':heavy_check_mark:'
    path: math/bostan_mori.hpp
    title: Bostan-Mori Algorithm
  - icon: ':warning:'
    path: math/interpolation.cpp
    title: Polynomial Interpolation
  - icon: ':warning:'
    path: math/multipoint_evaluation.cpp
    title: Multipoint Evaluation
  - icon: ':heavy_check_mark:'
    path: math/polynomial.cpp
    title: Polynomial
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/division_of_polynomials.test.cpp
    title: test/yosupo/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/ntt.hpp\"\n#include <vector>\n\nconstexpr int\
    \ get_primitive_root(int mod) {\n    if (mod == 167772161) return 3;\n    if (mod\
    \ == 469762049) return 3;\n    if (mod == 754974721) return 11;\n    if (mod ==\
    \ 998244353) return 3;\n    if (mod == 1224736769) return 3;\n}\n\ntemplate <typename\
    \ T>\nvoid bit_reverse(std::vector<T>& a) {\n    int n = a.size();\n    for (int\
    \ i = 0, j = 1; j < n - 1; ++j) {\n        for (int k = n >> 1; k > (i ^= k);\
    \ k >>= 1);\n        if (i < j) std::swap(a[i], a[j]);\n    }\n}\n\ntemplate <typename\
    \ mint>\nvoid ntt(std::vector<mint>& a, bool ordered = true) {\n    constexpr\
    \ int mod = mint::get_mod();\n    constexpr mint primitive_root = get_primitive_root(mod);\n\
    \n    int n = a.size();\n    for (int m = n; m > 1; m >>= 1) {\n        mint omega\
    \ = primitive_root.pow((mod - 1) / m);\n        for (int s = 0; s < n / m; ++s)\
    \ {\n            mint w = 1;\n            for (int i = 0; i < m / 2; ++i) {\n\
    \                mint l = a[s * m + i];\n                mint r = a[s * m + i\
    \ + m / 2];\n                a[s * m + i] = l + r;\n                a[s * m +\
    \ i + m / 2] = (l - r) * w;\n                w *= omega;\n            }\n    \
    \    }\n    }\n    if (ordered) bit_reverse(a);\n}\n\ntemplate <typename mint>\n\
    void intt(std::vector<mint>& a, bool ordered = true) {\n    constexpr int mod\
    \ = mint::get_mod();\n    constexpr mint primitive_root = get_primitive_root(mod);\n\
    \n    if (ordered) bit_reverse(a);\n    int n = a.size();\n    for (int m = 2;\
    \ m <= n; m <<= 1) {\n        mint omega = primitive_root.pow((mod - 1) / m).inv();\n\
    \        for (int s = 0; s < n / m; ++s) {\n            mint w = 1;\n        \
    \    for (int i = 0; i < m / 2; ++i) {\n                mint l = a[s * m + i];\n\
    \                mint r = a[s * m + i + m / 2] * w;\n                a[s * m +\
    \ i] = l + r;\n                a[s * m + i + m / 2] = l - r;\n               \
    \ w *= omega;\n            }\n        }\n    }\n}\n\ntemplate <typename mint>\n\
    std::vector<mint> convolution(std::vector<mint> a, std::vector<mint> b) {\n  \
    \  int size = a.size() + b.size() - 1;\n    int n = 1;\n    while (n < size) n\
    \ <<= 1;\n    a.resize(n);\n    b.resize(n);\n    ntt(a, false);\n    ntt(b, false);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    intt(a, false);\n    a.resize(size);\n\
    \    mint n_inv = mint(n).inv();\n    for (int i = 0; i < size; ++i) a[i] *= n_inv;\n\
    \    return a;\n}\n"
  code: "#pragma once\n#include <vector>\n\nconstexpr int get_primitive_root(int mod)\
    \ {\n    if (mod == 167772161) return 3;\n    if (mod == 469762049) return 3;\n\
    \    if (mod == 754974721) return 11;\n    if (mod == 998244353) return 3;\n \
    \   if (mod == 1224736769) return 3;\n}\n\ntemplate <typename T>\nvoid bit_reverse(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int i = 0, j = 1; j < n - 1; ++j) {\n\
    \        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n        if (i < j) std::swap(a[i],\
    \ a[j]);\n    }\n}\n\ntemplate <typename mint>\nvoid ntt(std::vector<mint>& a,\
    \ bool ordered = true) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    int n = a.size();\n  \
    \  for (int m = n; m > 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n        for (int s = 0; s < n / m; ++s) {\n            mint w =\
    \ 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint l =\
    \ a[s * m + i];\n                mint r = a[s * m + i + m / 2];\n            \
    \    a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n\
    \                w *= omega;\n            }\n        }\n    }\n    if (ordered)\
    \ bit_reverse(a);\n}\n\ntemplate <typename mint>\nvoid intt(std::vector<mint>&\
    \ a, bool ordered = true) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
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
    \    ntt(a, false);\n    ntt(b, false);\n    for (int i = 0; i < n; ++i) a[i]\
    \ *= b[i];\n    intt(a, false);\n    a.resize(size);\n    mint n_inv = mint(n).inv();\n\
    \    for (int i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/ntt.hpp
  requiredBy:
  - math/multipoint_evaluation.cpp
  - math/polynomial.cpp
  - math/bostan_mori.hpp
  - math/interpolation.cpp
  - convolution/arbitrary_mod_convolution.hpp
  timestamp: '2022-03-24 12:27:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
documentation_of: convolution/ntt.hpp
layout: document
title: Number Theoretic Transform
---

## Description

数論変換 (NTT) は，有限体 $\mathbb{F}_p$ 上の高速 Fourier 変換である．

## Operations

- `void ntt(vector<mint> a, bool ordered)`
    - 数列 $a$ を数論変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\log n)$
- `void intt(vector<mint> a, bool ordered)`
    - 数列 $a$ を逆数論変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\log n)$
- `vector<mint> convolution(vector<mint> a, vector<mint> b)`
    - 数列 $a$ と $b$ の畳み込みを計算する
    - 時間計算量: $O(n\log n)$

## Note

数列の長さ $n$ が $p - 1$ を割り切るとき，1の原子 $n$ 乗根が必ず存在する．$n$ の長さを2冪にするため，素数 $p$ は $a \times 2^k + 1$ の形に表したとき $k$ が十分大きいものを用いる．

以下の `p` と原子根の組み合わせがよく用いられる:
- (167772161, 3)
- (469762049, 3)
- (754974721, 11)
- (998244353, 3)
- (1224736769, 3) ($2p$ が 32-bit 符号付き整数に収まらないので，私の `Modint` では扱えない)

$k$ の値はそれぞれ，25, 26, 24, 23, 24である．