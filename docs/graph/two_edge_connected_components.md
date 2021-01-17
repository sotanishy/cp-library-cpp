---
title: 2-Edge-Connected Components
documentation_of: ../../graph/two_edge_connected_components.cpp
---

## Description

二辺連結成分は，どの1本の辺を取り除いても連結であるような部分グラフである．つまり，橋を含まない部分グラフである．

二辺連結成分を縮約して得られるグラフは森になっている．

空間計算量: $O(V + E)$

## Operations

- `TwoEdgeConnectedComponents(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ を二辺連結成分分解する
    - 時間計算量: $O(V + E)$
- `int operator[](int i)`
    - 頂点 $v$ が属する二辺連結成分のラベルを返す
- `int count()`
    - $G$ の二辺連結成分の数を返す