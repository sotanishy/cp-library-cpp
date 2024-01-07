---
title: Lowest Common Ancestor
documentation_of: ../../tree/lca.hpp
---

## Description

根付き木の2頂点間の最小共通祖先を計算する．この実装ではダブリングを用いている．

## Operations

- `LCA(vector<vector<int>> G, int root)`
    - 前計算をする
    - 時間計算量: $O(n\log n)$
- `int query(int u, int v)`
    - 頂点 $u$ と頂点 $v$ の最小共通祖先を返す
    - 時間計算量: $O(\log n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\log n)$
- `int parent(int v, int k)`
    - 頂点 $v$ の $k$ 個上の頂点を求める
- `int jump(int u, int v, int k)`
    - $uv$ パス上の $k$ 番目の頂点を返す．$k=0$ のとき $u$ を，$k>dist(u,v)$ のとき $-1$ を返す．
    - 時間計算量: $O(\log n)$

## Reference

- [Lowest common ancestor](https://en.wikipedia.org/wiki/Lowest_common_ancestor)
- [Lowest common ancestor's binary lifting method for path queries on trees](https://codeforces.com/blog/entry/22325)
- [Lowest Common Ancestor - Tarjan's off-line algorithm](https://cp-algorithms.com/graph/lca_tarjan.html)
- [Lowest Common Ancestor - Farach-Colton and Bender Algorithm](https://cp-algorithms.com/graph/lca_farachcoltonbender.html)
- [Solve RMQ (Range Minimum Query) by finding LCA (Lowest Common Ancestor)](https://cp-algorithms.com/graph/rmq_linear.html)