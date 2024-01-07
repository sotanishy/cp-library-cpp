---
title: 2D Segment Tree
documentation_of: ../../../data-structure/segtree/segment_tree_2d.hpp
---

## Description

2D セグメント木は，モノイド $(T, \cdot, e)$ の重みを持つ2次元平面上の点集合に対する一点更新と矩形領域積取得を提供するデータ構造である．

この実装では，重みをもたせる点を先読みして初期化時に渡す必要がある．

空間計算量: $O(n)$

## Operations

- `SegmentTree2D(vector<pair<X, Y>> pts)`
    - `pts` の点に対する 2D セグメント木を初期化する
    - 時間計算量: $O(n\log n)$
- `void update(X x, Y y, T val)`
    - 点 $(x, y)$ の重みを $val$ に更新する
    - 時間計算量: $O((\log n)^2)$
- `T fold(X sx, X tx, Y sy, Y ty)`
    - 矩形領域 $[sx, tx) \times [sy, ty)$ 内の点の重みの積を取得する
    - 時間計算量: $O((\log n)^2)$
