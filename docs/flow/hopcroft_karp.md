---
title: Hopcroft-Karp Algorithm
documentation_of: ../../flow/hopcroft_karp.hpp
---

## Description

Hopcroft-Karp アルゴリズムは，二部グラフの最大マッチングを求めるアルゴリズムである．Dinic のアルゴリズムの特殊ケースである．

## Operations

- `HopcroftKarp(int U, int V)`
    - 頂点数 $(U, V)$ で初期化する
- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
- `vector<pair<int, int>> bipartite_matching()`
    - 二部グラフの最大マッチングを一つ返す
    - 時間計算量: $O(E\sqrt{U+V})$

## Reference

- [Hopcroft–Karp algorithm - Wikipedia](https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm)
