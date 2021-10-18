---
title: Topological Sort
documentation_of: ../../graph/topological_sort.cpp
---

## Description

トポロジカルソートは，有向非巡回グラフ (DAG) の頂点を順序付けして，任意の辺 $(u, v)$ について $u$ が $v$ よりも前に来るように並べることである．

## Operations

- `vector<int> topological_sort(vector<vector<int>> G)`
    - $G$ のトポロジカルソートを返す．$G$ が DAG でないならば，空のリストを返す
    - 時間計算量: $O(V + E)$