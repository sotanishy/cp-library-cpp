---
title: Strongly Connected Components
documentation_of: ../../graph/scc.hpp
---

## Description

グラフ $G$ の強連結成分分解をする．

この実装では Kosaraju のアルゴリズムを用いている．

強連結成分を一つの頂点に縮約すると，有向非巡回グラフ (DAG) が得られる．

強連結成分のラベルはトポロジカル順序になっている．

## Operations

- `vector<int> scc(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ を強連結成分分解し，各頂点が属する成分のラベルを返す
    - 時間計算量: $O(V + E)$
- `vector<vector<int>> contract(vector<vector<int>> G, vector<int> comp)`
    - グラフ $G$ の隣接リストとその強連結成分が与えられたとき，各強連結成分を縮約したグラフを返す
    - 時間計算量: $O(V + E)$