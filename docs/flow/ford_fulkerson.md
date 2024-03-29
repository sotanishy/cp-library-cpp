---
title: Ford-Fulkerson Algorithm
documentation_of: ../../flow/ford_fulkerson.hpp
---

## Description

Ford-Fulkerson のアルゴリズムは，フローネットワークの最大流を求めるアルゴリズムである．残余グラフの増加パスを DFS で見つけ，そのパスにフローを流すことを繰り返す．

## Operations

- `FordFulkerson(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$
- `void add_edge(int u, int v, T cap)`
    - 容量 $cap$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `T max_flow(int s, int t)`
    - 始点 $s$ から終点 $t$ への最大流を求める
    - 時間計算量: $O(Ef)$