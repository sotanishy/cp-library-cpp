---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/interpolation.cpp
    title: Polynomial Interpolation
  - icon: ':warning:'
    path: math/multipoint_evaluation.cpp
    title: Multipoint Evaluation
  - icon: ':question:'
    path: math/polynomial.cpp
    title: Polynomial
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ntt.cpp\"\n#include <vector>\n\ntemplate <typename\
    \ mint>\nclass NTT {\npublic:\n    NTT() = delete;\n\n    static std::vector<mint>\
    \ convolve(const std::vector<mint>& a, const std::vector<mint>& b) {\n       \
    \ int size = a.size() + b.size() - 1;\n        int n = 1;\n        while (n <\
    \ size) n <<= 1;\n        std::vector<mint> na(a.begin(), a.end()), nb(b.begin(),\
    \ b.end());\n        na.resize(n);\n        nb.resize(n);\n        ntt(na, false);\n\
    \        ntt(nb, false);\n        for (int i = 0; i < n; ++i) na[i] *= nb[i];\n\
    \        intt(na, false);\n        na.resize(size);\n        mint n_inv = mint(n).inv();\n\
    \        for (int i = 0; i < size; ++i) na[i] *= n_inv;\n        return na;\n\
    \    }\n\n    static void ntt(std::vector<mint>& a, bool ordered = true) {\n \
    \       int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n       \
    \     mint omega = primitive_root.pow((mod - 1) / m);\n            for (int s\
    \ = 0; s < n / m; ++s) {\n                mint w = 1;\n                for (int\
    \ i = 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n     \
    \               mint r = a[s * m + i + m / 2];\n                    a[s * m +\
    \ i] = l + r;\n                    a[s * m + i + m / 2] = (l - r) * w;\n     \
    \               w *= omega;\n                }\n            }\n        }\n   \
    \     if (ordered) bit_reverse(a);\n    }\n\n    static void intt(std::vector<mint>&\
    \ a, bool ordered = true) {\n        if (ordered) bit_reverse(a);\n        int\
    \ n = a.size();\n        for (int m = 2; m <= n; m <<= 1) {\n            mint\
    \ omega = primitive_root.pow((mod - 1) / m).inv();\n            for (int s = 0;\
    \ s < n / m; ++s) {\n                mint w = 1;\n                for (int i =\
    \ 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n         \
    \           mint r = a[s * m + i + m / 2] * w;\n                    a[s * m +\
    \ i] = l + r;\n                    a[s * m + i + m / 2] = l - r;\n           \
    \         w *= omega;\n                }\n            }\n        }\n    }\n\n\
    private:\n    static constexpr mint get_primitive_root(int mod) {\n        if\
    \ (mod == 167772161) return 3;\n        if (mod == 469762049) return 3;\n    \
    \    if (mod == 754974721) return 11;\n        if (mod == 998244353) return 3;\n\
    \        if (mod == 1224736769) return 3;\n    }\n\n    static constexpr int mod\
    \ = mint::get_mod();\n    static constexpr mint primitive_root = get_primitive_root(mod);\n\
    \n    static void bit_reverse(std::vector<mint>& a) {\n        int n = a.size();\n\
    \        for (int i = 0, j = 1; j < n - 1; ++j) {\n            for (int k = n\
    \ >> 1; k > (i ^= k); k >>= 1);\n            if (i < j) std::swap(a[i], a[j]);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename mint>\nclass NTT {\n\
    public:\n    NTT() = delete;\n\n    static std::vector<mint> convolve(const std::vector<mint>&\
    \ a, const std::vector<mint>& b) {\n        int size = a.size() + b.size() - 1;\n\
    \        int n = 1;\n        while (n < size) n <<= 1;\n        std::vector<mint>\
    \ na(a.begin(), a.end()), nb(b.begin(), b.end());\n        na.resize(n);\n   \
    \     nb.resize(n);\n        ntt(na, false);\n        ntt(nb, false);\n      \
    \  for (int i = 0; i < n; ++i) na[i] *= nb[i];\n        intt(na, false);\n   \
    \     na.resize(size);\n        mint n_inv = mint(n).inv();\n        for (int\
    \ i = 0; i < size; ++i) na[i] *= n_inv;\n        return na;\n    }\n\n    static\
    \ void ntt(std::vector<mint>& a, bool ordered = true) {\n        int n = a.size();\n\
    \        for (int m = n; m > 1; m >>= 1) {\n            mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n            for (int s = 0; s < n / m; ++s) {\n                mint\
    \ w = 1;\n                for (int i = 0; i < m / 2; ++i) {\n                \
    \    mint l = a[s * m + i];\n                    mint r = a[s * m + i + m / 2];\n\
    \                    a[s * m + i] = l + r;\n                    a[s * m + i +\
    \ m / 2] = (l - r) * w;\n                    w *= omega;\n                }\n\
    \            }\n        }\n        if (ordered) bit_reverse(a);\n    }\n\n   \
    \ static void intt(std::vector<mint>& a, bool ordered = true) {\n        if (ordered)\
    \ bit_reverse(a);\n        int n = a.size();\n        for (int m = 2; m <= n;\
    \ m <<= 1) {\n            mint omega = primitive_root.pow((mod - 1) / m).inv();\n\
    \            for (int s = 0; s < n / m; ++s) {\n                mint w = 1;\n\
    \                for (int i = 0; i < m / 2; ++i) {\n                    mint l\
    \ = a[s * m + i];\n                    mint r = a[s * m + i + m / 2] * w;\n  \
    \                  a[s * m + i] = l + r;\n                    a[s * m + i + m\
    \ / 2] = l - r;\n                    w *= omega;\n                }\n        \
    \    }\n        }\n    }\n\nprivate:\n    static constexpr mint get_primitive_root(int\
    \ mod) {\n        if (mod == 167772161) return 3;\n        if (mod == 469762049)\
    \ return 3;\n        if (mod == 754974721) return 11;\n        if (mod == 998244353)\
    \ return 3;\n        if (mod == 1224736769) return 3;\n    }\n\n    static constexpr\
    \ int mod = mint::get_mod();\n    static constexpr mint primitive_root = get_primitive_root(mod);\n\
    \n    static void bit_reverse(std::vector<mint>& a) {\n        int n = a.size();\n\
    \        for (int i = 0, j = 1; j < n - 1; ++j) {\n            for (int k = n\
    \ >> 1; k > (i ^= k); k >>= 1);\n            if (i < j) std::swap(a[i], a[j]);\n\
    \        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/ntt.cpp
  requiredBy:
  - math/interpolation.cpp
  - math/multipoint_evaluation.cpp
  - math/polynomial.cpp
  timestamp: '2021-02-06 03:15:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
documentation_of: math/ntt.cpp
layout: document
title: Number Theoretic Transform
---

## Description

数論変換 (NTT) は，有限体 $\mathbb{F}_p$ 上の高速 Fourier 変換である．

## Operations

- `static vector<double> convolve(vector<T> a, vector<T> b)`
    - $a$ と $b$ の畳み込みを計算する
    - 時間計算量: $O(n\lg n)$
- `static void ntt(vector<mint> a, bool ordered)`
    - $a$ を数論変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\lg n)$
- `static void intt(vector<mint> a, bool ordered)`
    - $a$ を逆数論変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\lg n)$

## Note

数列の長さ $n$ が $p - 1$ を割り切るとき，1の原子 $n$ 乗根が必ず存在する．$n$ の長さを2冪にするため，素数 $p$ は $a \times 2^k + 1$ の形に表したとき $k$ が十分大きいものを用いる．

以下の `p` と原子根の組み合わせがよく用いられる:
- (167772161, 3)
- (469762049, 3)
- (754974721, 11)
- (998244353, 3)
- (1224736769, 3) (自作`Modint`では加算でオーバーフローする)

$k$ の値はそれぞれ，25, 26, 24, 23, 24である．