---
title: BFS on a Complement Graph
documentation_of: ../../graph/complement_bfs.hpp
---

## Description

補グラフで幅優先探索を行う．

## Operations

- `vector<int> complement_bfs(vector<vector<int>> Gcomp, int s)`
    - グラフ $G$ の補グラフが与えられたとき， $G$ 上で $s$ から各頂点への最短距離を求める
    - 時間計算量: $O(n+m)$

## Reference

- [ABC319 G - Counting Shortest Paths 解説](https://atcoder.jp/contests/abc319/editorial/7120)
- verify: [https://atcoder.jp/contests/abc319/submissions/45437018](https://atcoder.jp/contests/abc319/submissions/45437018)
