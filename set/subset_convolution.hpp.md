---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: set/zeta_moebius_transform.hpp
    title: "Fast Zeta/M\xF6bius Transform"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/linalg/hafnian.hpp
    title: Hafnian
  - icon: ':heavy_check_mark:'
    path: set/set_power_series.hpp
    title: Set Power Series
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_set_power_series.test.cpp
    title: test/yosupo/exp_of_set_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"set/subset_convolution.hpp\"\n#include <array>\n#include\
    \ <vector>\n\n#line 2 \"set/zeta_moebius_transform.hpp\"\n#include <bit>\n#include\
    \ <cassert>\n#line 5 \"set/zeta_moebius_transform.hpp\"\n\ntemplate <typename\
    \ T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
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
    \            if (!(j & i)) a[j | i] -= a[j];\n        }\n    }\n}\n#line 6 \"\
    set/subset_convolution.hpp\"\n\ntemplate <typename T, std::size_t N>\nstd::array<T,\
    \ N>& operator+=(std::array<T, N>& lhs,\n                             const std::array<T,\
    \ N>& rhs) {\n    for (int i = 0; i < (int)N; ++i) lhs[i] += rhs[i];\n    return\
    \ lhs;\n}\n\ntemplate <typename T, std::size_t N>\nstd::array<T, N>& operator-=(std::array<T,\
    \ N>& lhs,\n                             const std::array<T, N>& rhs) {\n    for\
    \ (int i = 0; i < (int)N; ++i) lhs[i] -= rhs[i];\n    return lhs;\n}\n\ntemplate\
    \ <typename T, int N>\nstd::vector<T> subset_convolution(const std::vector<T>&\
    \ a,\n                                  const std::vector<T>& b) {\n    using\
    \ Poly = std::array<T, N + 1>;\n    const int n = std::bit_ceil(std::max(a.size(),\
    \ b.size()));\n\n    // convert to polynomials\n    std::vector<Poly> pa(n), pb(n);\n\
    \    for (int i = 0; i < (int)a.size(); ++i) {\n        pa[i][std::popcount((unsigned\
    \ int)i)] = a[i];\n    }\n    for (int i = 0; i < (int)b.size(); ++i) {\n    \
    \    pb[i][std::popcount((unsigned int)i)] = b[i];\n    }\n\n    // bitwise or\
    \ convolution\n    subset_fzt(pa);\n    subset_fzt(pb);\n    for (int i = 0; i\
    \ < n; ++i) {\n        Poly pc;\n        for (int j = 0; j <= N; ++j) {\n    \
    \        for (int k = 0; k <= N - j; ++k) {\n                pc[j + k] += pa[i][j]\
    \ * pb[i][k];\n            }\n        }\n        pa[i].swap(pc);\n    }\n    subset_fmt(pa);\n\
    \n    // convert back\n    std::vector<T> ret(n);\n    for (int i = 0; i < n;\
    \ ++i) {\n        ret[i] = pa[i][std::popcount((unsigned int)i)];\n    }\n   \
    \ return ret;\n}\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n\n#include \"zeta_moebius_transform.hpp\"\
    \n\ntemplate <typename T, std::size_t N>\nstd::array<T, N>& operator+=(std::array<T,\
    \ N>& lhs,\n                             const std::array<T, N>& rhs) {\n    for\
    \ (int i = 0; i < (int)N; ++i) lhs[i] += rhs[i];\n    return lhs;\n}\n\ntemplate\
    \ <typename T, std::size_t N>\nstd::array<T, N>& operator-=(std::array<T, N>&\
    \ lhs,\n                             const std::array<T, N>& rhs) {\n    for (int\
    \ i = 0; i < (int)N; ++i) lhs[i] -= rhs[i];\n    return lhs;\n}\n\ntemplate <typename\
    \ T, int N>\nstd::vector<T> subset_convolution(const std::vector<T>& a,\n    \
    \                              const std::vector<T>& b) {\n    using Poly = std::array<T,\
    \ N + 1>;\n    const int n = std::bit_ceil(std::max(a.size(), b.size()));\n\n\
    \    // convert to polynomials\n    std::vector<Poly> pa(n), pb(n);\n    for (int\
    \ i = 0; i < (int)a.size(); ++i) {\n        pa[i][std::popcount((unsigned int)i)]\
    \ = a[i];\n    }\n    for (int i = 0; i < (int)b.size(); ++i) {\n        pb[i][std::popcount((unsigned\
    \ int)i)] = b[i];\n    }\n\n    // bitwise or convolution\n    subset_fzt(pa);\n\
    \    subset_fzt(pb);\n    for (int i = 0; i < n; ++i) {\n        Poly pc;\n  \
    \      for (int j = 0; j <= N; ++j) {\n            for (int k = 0; k <= N - j;\
    \ ++k) {\n                pc[j + k] += pa[i][j] * pb[i][k];\n            }\n \
    \       }\n        pa[i].swap(pc);\n    }\n    subset_fmt(pa);\n\n    // convert\
    \ back\n    std::vector<T> ret(n);\n    for (int i = 0; i < n; ++i) {\n      \
    \  ret[i] = pa[i][std::popcount((unsigned int)i)];\n    }\n    return ret;\n}\n"
  dependsOn:
  - set/zeta_moebius_transform.hpp
  isVerificationFile: false
  path: set/subset_convolution.hpp
  requiredBy:
  - math/linalg/hafnian.hpp
  - set/set_power_series.hpp
  timestamp: '2024-01-07 16:57:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/exp_of_set_power_series.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
  - test/yosupo/subset_convolution.test.cpp
documentation_of: set/subset_convolution.hpp
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