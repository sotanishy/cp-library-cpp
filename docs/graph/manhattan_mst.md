---
title: Manhattan Minimum Spanning Tree
documentation_of: ../../graph/manhattan_mst.hpp
---

## Description

2次元平面上に点が与えられ，各点の間にそのマンハッタン距離の重みを持つ辺が張られているとき，最小全域木を計算する．

## Operations

- `vector<T, Edge<T>> manhattan_mst(vector<pair<T, T>> pts)`
    - `pts` の点からなるグラフの最小全域木を求める
    - 時間計算量: $O(n\log n)$

## Reference

- [Manhattan Minimum Spanning Tree - 霧でも食ってろ](https://knuu.github.io/manhattan_mst.html)
- [Line Sweep Algorithms - topcoder](https://www.topcoder.com/thrive/articles/Line%20Sweep%20Algorithms)
