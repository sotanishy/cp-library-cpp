---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.sparse_table.test.cpp
    title: test/aoj/DSL_3_D.sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sparse_table.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <vector>\n\ntemplate <typename M>\nclass SparseTable\
    \ {\n    using T = M::T;\n\n   public:\n    SparseTable() = default;\n    explicit\
    \ SparseTable(const std::vector<T>& v) {\n        const int n = v.size();\n  \
    \      const int b = std::bit_width((unsigned int)n);\n        lookup.resize(b,\
    \ std::vector<T>(n));\n        std::ranges::copy(v, lookup[0].begin());\n    \
    \    for (int i = 1; i < b; ++i) {\n            for (int j = 0; j + (1 << i) <=\
    \ n; ++j) {\n                lookup[i][j] =\n                    M::op(lookup[i\
    \ - 1][j], lookup[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n   \
    \ }\n\n    T fold(int l, int r) const {\n        if (l == r) return M::id();\n\
    \        int i = std::bit_width((unsigned int)(r - l)) - 1;\n        return M::op(lookup[i][l],\
    \ lookup[i][r - (1 << i)]);\n    }\n\n   private:\n    std::vector<std::vector<T>>\
    \ lookup;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <vector>\n\n\
    template <typename M>\nclass SparseTable {\n    using T = M::T;\n\n   public:\n\
    \    SparseTable() = default;\n    explicit SparseTable(const std::vector<T>&\
    \ v) {\n        const int n = v.size();\n        const int b = std::bit_width((unsigned\
    \ int)n);\n        lookup.resize(b, std::vector<T>(n));\n        std::ranges::copy(v,\
    \ lookup[0].begin());\n        for (int i = 1; i < b; ++i) {\n            for\
    \ (int j = 0; j + (1 << i) <= n; ++j) {\n                lookup[i][j] =\n    \
    \                M::op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);\n\
    \            }\n        }\n    }\n\n    T fold(int l, int r) const {\n       \
    \ if (l == r) return M::id();\n        int i = std::bit_width((unsigned int)(r\
    \ - l)) - 1;\n        return M::op(lookup[i][l], lookup[i][r - (1 << i)]);\n \
    \   }\n\n   private:\n    std::vector<std::vector<T>> lookup;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.sparse_table.test.cpp
documentation_of: data-structure/sparse_table.hpp
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