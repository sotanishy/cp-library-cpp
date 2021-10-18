---
title: Sliding Window Aggregation
documentation_of: ../../data-structure/sliding_window_aggregation.cpp
---

## Description

Sliding window aggregation は，半群 $(T, \cdot)$ を扱い，要素の総和の計算が可能なキューである．スタックを2つ用いてキューをシミュレートする．

## Operations

- `void push(T x)`
    - $x$ をキューの末尾に追加する
    - 時間計算量: $O(1)$
- `void pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `bool empty()`
    - キューが空かどうか判定する
    - 時間計算量: $O(1)$
- `T fold()`
    - キューの要素全体の演算結果を返す
    - 時間計算量: $O(1)$

## Reference

- [Sliding Window Aggregation](https://scrapbox.io/data-structures/Sliding_Window_Aggregation)
- [Constant-Time Sliding Window Aggregation](http://hirzels.com/martin/papers/tr15-rc25574-daba.pdf)