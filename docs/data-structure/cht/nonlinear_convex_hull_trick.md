---
title: Nonlinear Convex Hull Trick
documentation_of: ../../../data-structure/cht/nonlinear_convex_hull_trick.hpp
---

## Description

互いにたかだか 1 回しか交わらない関数の集合への追加クエリと最小値取得クエリを処理する．

追加クエリは次の意味での単調性を満たす必要がある：最も新しく追加された関数は，十分大きな $x$ において，集合内の関数の中で最小値を取る．

空間計算量: $O(n)$

## Operations

- `void add(F f)`
    - 関数 $f$ を集合に追加する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `T get(T x)`
    - 与えられた $x$ に対し，最小値を取る関数の値を求める
    - 時間計算量: $\mathrm{amortized}\ O(1)$

## Reference

- verify: [https://atcoder.jp/contests/abc373/submissions/58145171](https://atcoder.jp/contests/abc373/submissions/58145171)