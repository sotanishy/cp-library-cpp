---
title: Diameter of a Tree
documentation_of: ../../tree/tree_diameter.cpp
---

## Description

DFSを用いて木の直径を求める．

## Operations

- `static int diameter(vector<vector<int>> G)`
    - $G$ の辺の重みをすべて1として直径を求める
    - 時間計算量: $O(n)$
- `static T diameter(vector<vector<Edge<T>>> G)`
    - $G$ の直径を求める
    - 時間計算量: $O(n)$

## Reference

- [木の直径を求めるアルゴリズム](https://algo-logic.info/tree-diameter/)

## TODO

- 長さだけでなく辺も返す