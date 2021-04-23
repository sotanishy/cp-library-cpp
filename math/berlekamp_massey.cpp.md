---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/find_linear_recurrence.test.cpp
    title: test/yosupo/find_linear_recurrence.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/berlekamp_massey.cpp\"\n#include <vector>\n\ntemplate\
    \ <typename T>\nstd::vector<T> berlekamp_massey(std::vector<T> a) {\n    int n\
    \ = a.size();\n    std::vector<T> B = {1}, C = {1};\n    T b = 1;\n    int L =\
    \ 0, m = 1;\n    for (int i = 0; i < n; ++i) {\n        T d = a[i];\n        for\
    \ (int j = 1; j < (int) C.size(); ++j) {\n            d += a[i-j] * C[j];\n  \
    \      }\n        if (d == 0) {\n            ++m;\n        } else {\n        \
    \    auto tmp =  C;\n            if (C.size() < m + B.size()) {\n            \
    \    C.resize(m + B.size());\n            }\n            T f = d / b;\n      \
    \      for (int j = 0; j < (int) B.size(); ++j) {\n                C[m + j] -=\
    \ f * B[j];\n            }\n            if (2 * L <= i) {\n                L =\
    \ i + 1 - L;\n                b = d;\n                B = tmp;\n             \
    \   m = 1;\n            } else {\n                ++m;\n            }\n      \
    \  }\n    }\n    std::vector<T> ret(L);\n    for (int i = 1; i <= L; ++i) {\n\
    \        ret[i-1] = -C[i];\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nstd::vector<T>\
    \ berlekamp_massey(std::vector<T> a) {\n    int n = a.size();\n    std::vector<T>\
    \ B = {1}, C = {1};\n    T b = 1;\n    int L = 0, m = 1;\n    for (int i = 0;\
    \ i < n; ++i) {\n        T d = a[i];\n        for (int j = 1; j < (int) C.size();\
    \ ++j) {\n            d += a[i-j] * C[j];\n        }\n        if (d == 0) {\n\
    \            ++m;\n        } else {\n            auto tmp =  C;\n            if\
    \ (C.size() < m + B.size()) {\n                C.resize(m + B.size());\n     \
    \       }\n            T f = d / b;\n            for (int j = 0; j < (int) B.size();\
    \ ++j) {\n                C[m + j] -= f * B[j];\n            }\n            if\
    \ (2 * L <= i) {\n                L = i + 1 - L;\n                b = d;\n   \
    \             B = tmp;\n                m = 1;\n            } else {\n       \
    \         ++m;\n            }\n        }\n    }\n    std::vector<T> ret(L);\n\
    \    for (int i = 1; i <= L; ++i) {\n        ret[i-1] = -C[i];\n    }\n    return\
    \ ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/berlekamp_massey.cpp
  requiredBy: []
  timestamp: '2021-04-23 22:08:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/find_linear_recurrence.test.cpp
documentation_of: math/berlekamp_massey.cpp
layout: document
title: Berlekamp-Massey Algorithm
---

## Description

Berlekamp-Massey のアルゴリズムは，与えられた数列を生成する最短の線形漸化式を求めるアルゴリズムである．

## Operations

- `vector<T> berlekamp_massey(vector<T> a)`
    - $a$ を生成する最短の線形漸化式を1つ求める
    - 時間計算量: $O(n^2)$

## Reference

- [Berlekamp–Massey algorithm](https://en.wikipedia.org/wiki/Berlekamp%E2%80%93Massey_algorithm)
- [Linear Recurrence and Berlekamp-Massey Algorithm](https://codeforces.com/blog/entry/61306?f0a28=1)