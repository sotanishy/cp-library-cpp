---
title: Eulerian Walk
documentation_of: ../../graph/eulerian_walk.hpp
---

## Description

Euler 路 (グラフのすべての辺を通る路) を一つ見つける．

奇数次の頂点が0個なら Euler 閉路が存在する．奇数次の頂点が2個なら閉路でない Euler 路が存在する．それ以外のときは Euler 路は存在しない．

この実装では Hierholzer のアルゴリズムを用いている．

## Operations

- `vector<int> eulerian_walk(vector<pair<int, int>> edges, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺集合が与えられたとき，$G$ の Euler 路に現れる頂点を順番に返す．存在しない場合は空リストを返す．
    - 時間計算量: $O(E)$
