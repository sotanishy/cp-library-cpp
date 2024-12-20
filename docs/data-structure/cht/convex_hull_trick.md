---
title: Convex Hull Trick
documentation_of: ../../../data-structure/cht/convex_hull_trick.hpp
---

## Description

Convex hull trick は，直線集合 $L$ への追加クエリと最小値クエリを効率的に行う手法である．

この実装では，追加する直線の傾きが単調非増加である必要がある．傾きに単調性がないときは平衡二分探索木を用いた CHT または Li Chao tree を使用せよ．

空間計算量: $O(n)$

## Operations

- `void add(T a, T b)`
    - 直線 $ax + b$ を $L$ に追加する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `T get(T x)`
    - 与えられた $x$ に対し，$L$ の中で最小値を取る直線の値を求める
    - 時間計算量: $\mathrm{amortized}\ O(1)$

## Reference

- [Convex-Hull Trick](https://satanic0258.hatenablog.com/entry/2016/08/16/181331)