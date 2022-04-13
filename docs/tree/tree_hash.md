---
title: Tree Hashing
documentation_of: ../../tree/tree_hash.hpp
---

## Description

木のハッシュを計算する．木の同型性判定に用いる．

## Operations

- `long long tree_hash(vector<vector<int>> G, int root)`
    - 木 $G$ の隣接リストが与えられたとき，$G$ のハッシュを計算する．`root` が与えられた場合はそれを根とする．
    - 時間計算量: $O(n)$

## Reference

- [Tree Isomorphism - My Algorithm](https://kopricky.github.io/code/Graph/tree_isomorphism.html)