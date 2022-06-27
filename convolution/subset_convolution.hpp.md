---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/and_or_convolution.hpp
    title: "Bitwise AND/OR Convolution (Subset/Superset Fast Zeta/M\xF6bius Transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/subset_convolution.hpp\"\n#include <array>\n\
    #include <vector>\n#line 3 \"convolution/and_or_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nvoid fzt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if ((j >> i & 1) == subset) a[j] += a[j ^ (1 << i)];\n      \
    \  }\n    }\n}\n\ntemplate <typename T>\nvoid fmt(std::vector<T>& a, bool subset)\
    \ {\n    int k = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i)\
    \ {\n        for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1)\
    \ == subset) a[j] -= a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename\
    \ T>\nstd::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {\n  \
    \  int size = std::max(a.size(), b.size());\n    int n = 1;\n    while (n < size)\
    \ n <<= 1;\n    a.resize(n);\n    b.resize(n);\n    fzt(a, true);\n    fzt(b,\
    \ true);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    fmt(a, true);\n \
    \   return a;\n}\n\ntemplate <typename T>\nstd::vector<T> and_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int size = std::max(a.size(), b.size());\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    fzt(a, false);\n    fzt(b, false);\n    for (int i = 0; i < n; ++i) a[i]\
    \ *= b[i];\n    fmt(a, false);\n    return a;\n}\n#line 5 \"convolution/subset_convolution.hpp\"\
    \n\ntemplate <typename T, std::size_t N>\nstd::array<T, N>& operator+=(std::array<T,\
    \ N>& lhs, const std::array<T, N>& rhs) {\n    for (int i = 0; i < (int) N; ++i)\
    \ lhs[i] += rhs[i];\n    return lhs;\n}\n\ntemplate <typename T, std::size_t N>\n\
    std::array<T, N>& operator-=(std::array<T, N>& lhs, const std::array<T, N>& rhs)\
    \ {\n    for (int i = 0; i < (int) N; ++i) lhs[i] -= rhs[i];\n    return lhs;\n\
    }\n\ntemplate <typename T, int N>\nstd::vector<T> subset_convolution(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    using Poly = std::array<T, N + 1>;\n    int\
    \ size = std::max(a.size(), b.size());\n    int n = 1;\n    while (n < size) n\
    \ <<= 1;\n\n    // convert to polynomials\n    std::vector<Poly> pa(n), pb(n);\n\
    \    for (int i = 0; i < (int) a.size(); ++i) {\n        pa[i][__builtin_popcount(i)]\
    \ = a[i];\n    }\n    for (int i = 0; i < (int) b.size(); ++i) {\n        pb[i][__builtin_popcount(i)]\
    \ = b[i];\n    }\n\n    // bitwise or convolution\n    fzt(pa, true);\n    fzt(pb,\
    \ true);\n    for (int i = 0; i < n; ++i) {\n        Poly pc;\n        for (int\
    \ j = 0; j <= N; ++j) {\n            for (int k = 0; k <= N - j; ++k) {\n    \
    \            pc[j + k] += pa[i][j] * pb[i][k];\n            }\n        }\n   \
    \     pa[i].swap(pc);\n    }\n    fmt(pa, true);\n\n    // convert back\n    std::vector<T>\
    \ ret(n);\n    for (int i = 0; i < n; ++i) {\n        ret[i] = pa[i][__builtin_popcount(i)];\n\
    \    }\n    return ret;\n}\n\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include \"and_or_convolution.hpp\"\
    \n\ntemplate <typename T, std::size_t N>\nstd::array<T, N>& operator+=(std::array<T,\
    \ N>& lhs, const std::array<T, N>& rhs) {\n    for (int i = 0; i < (int) N; ++i)\
    \ lhs[i] += rhs[i];\n    return lhs;\n}\n\ntemplate <typename T, std::size_t N>\n\
    std::array<T, N>& operator-=(std::array<T, N>& lhs, const std::array<T, N>& rhs)\
    \ {\n    for (int i = 0; i < (int) N; ++i) lhs[i] -= rhs[i];\n    return lhs;\n\
    }\n\ntemplate <typename T, int N>\nstd::vector<T> subset_convolution(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    using Poly = std::array<T, N + 1>;\n    int\
    \ size = std::max(a.size(), b.size());\n    int n = 1;\n    while (n < size) n\
    \ <<= 1;\n\n    // convert to polynomials\n    std::vector<Poly> pa(n), pb(n);\n\
    \    for (int i = 0; i < (int) a.size(); ++i) {\n        pa[i][__builtin_popcount(i)]\
    \ = a[i];\n    }\n    for (int i = 0; i < (int) b.size(); ++i) {\n        pb[i][__builtin_popcount(i)]\
    \ = b[i];\n    }\n\n    // bitwise or convolution\n    fzt(pa, true);\n    fzt(pb,\
    \ true);\n    for (int i = 0; i < n; ++i) {\n        Poly pc;\n        for (int\
    \ j = 0; j <= N; ++j) {\n            for (int k = 0; k <= N - j; ++k) {\n    \
    \            pc[j + k] += pa[i][j] * pb[i][k];\n            }\n        }\n   \
    \     pa[i].swap(pc);\n    }\n    fmt(pa, true);\n\n    // convert back\n    std::vector<T>\
    \ ret(n);\n    for (int i = 0; i < n; ++i) {\n        ret[i] = pa[i][__builtin_popcount(i)];\n\
    \    }\n    return ret;\n}\n\n"
  dependsOn:
  - convolution/and_or_convolution.hpp
  isVerificationFile: false
  path: convolution/subset_convolution.hpp
  requiredBy: []
  timestamp: '2022-04-06 10:49:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/subset_convolution.test.cpp
documentation_of: convolution/subset_convolution.hpp
layout: document
title: Subset Convolution
---

## Description

数列 $f$ と $g$ の subset convolution $f * g$ は以下で定義される．

$$
(f * g)(S) = \sum_{T \subset S} f(T) g(S\setminus T)
$$

$f, g$ の長さを $2^n$ とするとき，素朴に部分集合を列挙する方法では計算量は $O(3^n)$ となるが，$O(n^2 2^n)$ で計算することができる．

## Operations

- `vector<T> subset_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の subset convolution を計算する
    - 時間計算量: $O(n^2 2^n)$

## Reference

- [Subset Convolutionのアルゴリズム - 37zigenのHP](https://37zigen.com/subset-convolution/)