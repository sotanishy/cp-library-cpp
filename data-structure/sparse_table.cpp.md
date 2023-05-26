---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.sparse_table.test.cpp
    title: test/aoj/DSL_3_D.sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sparse_table.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <typename M>\nclass SparseTable {\n    using T =\
    \ typename M::T;\n\n   public:\n    SparseTable() = default;\n    explicit SparseTable(const\
    \ std::vector<T>& v) {\n        int n = v.size(), b = 0;\n        while ((1 <<\
    \ b) <= n) ++b;\n        lookup.resize(b, std::vector<T>(n));\n        std::copy(v.begin(),\
    \ v.end(), lookup[0].begin());\n        for (int i = 1; i < b; ++i) {\n      \
    \      for (int j = 0; j + (1 << i) <= n; ++j) {\n                lookup[i][j]\
    \ =\n                    M::op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n    }\n\n    T fold(int l, int r) const {\n\
    \        if (l == r) return M::id();\n        int i = 31 - __builtin_clz(r - l);\n\
    \        return M::op(lookup[i][l], lookup[i][r - (1 << i)]);\n    }\n\n   private:\n\
    \    std::vector<std::vector<T>> lookup;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ M>\nclass SparseTable {\n    using T = typename M::T;\n\n   public:\n    SparseTable()\
    \ = default;\n    explicit SparseTable(const std::vector<T>& v) {\n        int\
    \ n = v.size(), b = 0;\n        while ((1 << b) <= n) ++b;\n        lookup.resize(b,\
    \ std::vector<T>(n));\n        std::copy(v.begin(), v.end(), lookup[0].begin());\n\
    \        for (int i = 1; i < b; ++i) {\n            for (int j = 0; j + (1 <<\
    \ i) <= n; ++j) {\n                lookup[i][j] =\n                    M::op(lookup[i\
    \ - 1][j], lookup[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n   \
    \ }\n\n    T fold(int l, int r) const {\n        if (l == r) return M::id();\n\
    \        int i = 31 - __builtin_clz(r - l);\n        return M::op(lookup[i][l],\
    \ lookup[i][r - (1 << i)]);\n    }\n\n   private:\n    std::vector<std::vector<T>>\
    \ lookup;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.cpp
  requiredBy: []
  timestamp: '2023-05-27 03:55:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.sparse_table.test.cpp
documentation_of: data-structure/sparse_table.cpp
layout: document
title: Sparse Table
---

## Description

Sparse table は，冪等モノイド $(T, \cdot, e)$ の静的な列の区間積を高速に計算するデータ構造である．

冪等な二項演算とは， $\forall a \in T, a \cdot a = a$ が成り立つような写像 $\cdot: T \times T \rightarrow T$ である．冪等な二項演算には，max, min, gcd, bitwise and, bitwise or などがある．

空間計算量: $O(n \log n)$

## Operations

- `SparseTable(vector<T> v)`
    - `v`の要素から sparse table を構築する
    - 時間計算量: $O(n \log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(1)$

## Reference

- [Sparse Table](https://cp-algorithms.com/data_structures/sparse-table.html)