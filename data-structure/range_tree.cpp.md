---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "data-structure/range_tree.cpp"


    '
  code: ''
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range_tree.cpp
  requiredBy: []
  timestamp: '2021-07-29 21:51:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/range_tree.cpp
layout: document
title: Range Tree
---

## Description

領域木は，2次元平面の長方形領域内の点の個数を効率的に数えるデータ構造である．

空間計算量: $O(n\lg n)$

## Operations

- `void add_point(int x, int y)`
    - 点 $(x, y)$ を追加する
    - 時間計算量: $O(1)$
- `void build()`
    - 領域木を構築する
    - 点 $(x, y)$ を追加する
    - 時間計算量: $O(n\lg n)$
- `int count(int sx, int tx, int sy, int ty)`
    - 長方形領域 $[sx, tx) \times [sy, ty)$ 内の点の個数を返す
    - 時間計算量: $O(\lg^2 n)$

## Reference

- [領域木の布教](https://mugen1337.hatenablog.com/entry/2021/05/22/224041)
