---
title: Strongly Connected Components
documentation_of: ../../graph/scc.cpp
---

## Description

グラフ $G$ の強連結成分分解をする．

この実装では Kosaraju のアルゴリズムを用いている．

強連結成分を一つの頂点に縮約すると，有向非巡回グラフ (DAG) が得られる．

強連結成分のラベルはトポロジカル順序になっている．

空間計算量: $O(V + E)$

## Operations

- `SCC(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$
- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `void build()`
    - 強連結成分分解をする
    - 時間計算量: $O(V + E)$
- `int operator[](int i)`
    - 頂点 $i$ が属する強連結成分のラベルを返す
    - 時間計算量: $O(1)$
- `int count()`
    - 強連結成分の数を返す
    - 時間計算量: $O(1)$