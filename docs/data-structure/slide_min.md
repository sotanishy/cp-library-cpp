---
title: Sliding Window Minimum
documentation_of: ../../data-structure/slide_min.cpp
---

## Description

スライド最小値は，全順序集合 $T$ を扱い，要素の最小値を求めることができるキューである．

## Operations

- `void push(T x)`
    - $x$ をキューの末尾に追加する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `void pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $O(1)$
- `T get()`
    - キューの要素全体の最小値/最大値を返す
    - 時間計算量: $O(1)$