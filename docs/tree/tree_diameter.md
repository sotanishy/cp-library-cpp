---
title: Diameter of a Tree
documentation_of: ../../tree/tree_diameter.hpp
---

## Description

DFSを用いて木の直径を求める．

## Operations

- `pair<int, vector<int>> tree_diameter(vector<vector<int>> G)`
    - $G$ の辺の重みをすべて1として直径の重みとそれに含まれる頂点を返す
    - 時間計算量: $O(n)$
- `pair<T, vector<int>> tree_diameter(vector<vector<pair<int, T>>> G)`
    - $G$ の直径の重みとそれに含まれる頂点を返す
    - 時間計算量: $O(n)$

## Reference

- [木の直径を求めるアルゴリズム](https://algo-logic.info/tree-diameter/)