---
title: Cartesian Tree
documentation_of: ../../tree/cartesian_tree.cpp
---

## Description

Cartesian tree は，数列から定まる二分木で，以下の条件を満たすものである．
- 各頂点の重みは，そのどの子の重みよりも小さい
- 木の in-order traversal がもとの数列と一致する

## Operations

- `vector<int> cartesian_tree(vector<int> a)`
    - 数列 $a$ から定まる Cartesian tree を返す．それぞれの頂点の親のラベルを返す．根の親は `-1` とする．
    - 時間計算量: $O(n)$

## Reference

- [列を最小値で分割して再帰するパターンと Cartesian tree](https://kmyk.github.io/blog/blog/2020/07/27/recursion-on-cartesian-tree/)