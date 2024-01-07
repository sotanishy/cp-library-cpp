---
title: Dinic's Algorithm
documentation_of: ../../flow/dinic.hpp
---

## Description

Dinic のアルゴリズムは，フローネットワークの最大流を求めるアルゴリズムである．始点からの最短距離を BFS で計算し，残余グラフの増加パスを DFS で見つけ，そのパスにフローを流すことを繰り返す．

## Operations

- `Dinic(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$
- `void add_edge(int u, int v, T cap)`
    - 容量 $cap$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `T max_flow(int s, int t)`
    - 始点 $s$ から終点 $t$ への最大流を求める
    - 時間計算量: $O(V^2E)$

## Reference

- [Dinic 法とその時間計算量 - みさわめも](https://misawa.github.io/others/flow/dinic_time_complexity.html)