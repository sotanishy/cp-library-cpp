---
title: Range Contour Aggregation
documentation_of: ../../tree/range_contour_aggregation.hpp
---

## Description

木上の等高線集約クエリ (の変種1) (参考文献を参照) を扱う．

空間計算量: $O(n\log n)$

## Operations

- `RangeContourAggregation(vector<vector<int>> G)`
    - 木 $G$ に対する前計算を行う
    - 時間計算量: $O(n\log n)$
- `void update(int v, T x)`
    - 頂点 $v$ の値を $x$ に更新する
    - 時間計算量: $O((\log n)^2)$
- `T fold(int v, int d)`
    - $v$ からの距離が $d$ 未満の頂点の値の総和を求める
    - 時間計算量: $O((\log n)^2)$

## Reference

- [木上の等高線集約クエリ - suisen のブログ](https://suisen-kyopro.hatenablog.com/entry/2022/03/21/220009)