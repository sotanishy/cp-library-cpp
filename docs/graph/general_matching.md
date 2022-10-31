---
title: General Matching
documentation_of: ../../graph/general_matching.hpp
---

## Description

一般グラフの最大マッチングを，Edmonds の花アルゴリズムで求める．

## Operations

- `GeneralMatching(int n)`
    - 頂点数 $n$ で初期化する
- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
- `vector<pair<int, int>> max_matching()`
    - 一般グラフの最大マッチングを一つ返す
    - 時間計算量: $O(n^3)$

## Reference

- Lee, Jon. *A First Course in Combinatorial Optimization*. Cambridge: Cambridge University Press, 2010
- [[Tutorial] Blossom Algorithm for General Matching in O(n^3) - Codeforces](https://codeforces.com/blog/entry/92339)