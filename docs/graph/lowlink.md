---
title: Lowlink
documentation_of: ../../graph/lowlink.hpp
---

## Description

Lowlink はグラフの橋や関節点などを求める際に有効な概念である．グラフの DFS tree において，頂点 $v$ の訪問時刻を `ord[v]` としたとき，$v$ から後退辺 (DFS tree に含まれない辺) を高々1回用いて到達することができる頂点の `ord` の最小値 `low[v]` を lowlink という．

辺 $(u, v)$ が橋であることの必要十分条件は `ord[u] < low[v]` が成り立つことである．

頂点 $v$ が関節点であることの必要十分条件は
- $v$ が DFS tree の根であり，かつ2つ以上の子を持つ
- $v$ が DFS tree の根ではなく，かつ $v$ のある子 $c$ について `ord[v] <= low[c]` が成り立つ

のどちらかが成り立つことである．

空間計算量: $O(V + E)$

## Operations

- `Lowlink(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ の橋と関節点を求める
    - 時間計算量: $O(V + E)$
- `bool is_bridge(int u, int v)`
    - 辺 $uv$ が橋かどうか判定する
    - 時間計算量: $O(1)$

## Reference

- [橋と関節点, lowlink](https://kagamiz.hatenablog.com/entry/2013/10/05/005213)