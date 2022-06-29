---
title: Bipartite Edge Coloring
documentation_of: ../../graph/bipartite_edge_coloring.hpp
---

## Description

二部グラフの辺彩色を求める．

Kőnig's Line Coloring Theorem によると，二部グラフ $G$ の頂点の最大次数を $D$ とすると，$G$ は必ず $D$ 色で辺彩色可能である．

## Operations

- `vector<int> bipartite_edge_coloring(vector<pair<int, int>> G, int n, int m)`
    - 頂点数が $(n, m)$ の二部グラフ $G$ の最小辺彩色における各辺の色を返す
    - 時間計算量: $O(E\sqrt{V}\log D)$

## Reference

- [辺彩色 - slideshare](https://www.slideshare.net/catupper/ss-25736611)
- [二部グラフの辺彩色 - ei1333の日記](https://ei1333.hateblo.jp/entry/2020/08/25/015955)
