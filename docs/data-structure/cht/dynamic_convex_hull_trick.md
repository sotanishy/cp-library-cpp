---
title: Dynamic Convex Hull Trick
documentation_of: ../../../data-structure/cht/dynamic_convex_hull_trick.cpp
---

## Description

Convex hull trick は，直線集合 $L$ への追加クエリと最小値クエリを効率的に行う手法である．

空間計算量: $O(n)$

## Operations

- `T add(T a, T b)`
    - 直線 $ax + b$ を $L$ に追加する
    - 時間計算量: $O(\log n)$
- `T get(T x)`
    - 与えられた $x$ に対し，$L$ の中で最小値を取る直線の値を求める
    - 時間計算量: $O(\log n)$