---
title: Range Tree
documentation_of: ../../data-structure/range_tree.cpp
---

## Description

領域木は，2次元平面の長方形領域内の点に対する値の総和クエリを扱うデータ構造である．

空間計算量: $O(n\log n)$

## Operations

- `RangeTree(int n, vector<tuple<int, Y, T>>> pts)`
    - `pts` の点から領域木を構築する．点は $(x, y, v)$ の形式で与えられる．
    - 時間計算量: $O(n\log n)$
- `T fold(int sx, int tx, Y sy, Y ty)`
    - 長方形領域 $[sx, tx) \times [sy, ty)$ 内の点に対する値の総和を計算する
    - 時間計算量: $O((\log n)^2)$

## Reference

- [領域木の布教](https://mugen1337.hatenablog.com/entry/2021/05/22/224041)
