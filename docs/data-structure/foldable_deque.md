---
title: Foldable Deque
documentation_of: ../../data-structure/foldable_deque.hpp
---

## Description

Stack 2つで deque をシミュレートする技法で，半群要素の総積の計算が可能な deque を作ることができる． Sliding window aggregation の deque 版である．

## Operations

- `void push_front(T x)`
    - $x$ を deque の先頭に追加する
    - 時間計算量: $O(1)$
- `void push_back(T x)`
    - $x$ を deque の末尾に追加する
    - 時間計算量: $O(1)$
- `void pop_front()`
    - deque の先頭要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `void pop_back()`
    - deque の先頭要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `bool empty()`
    - deque が空かどうか判定する
    - 時間計算量: $O(1)$
- `T fold()`
    - deque の要素の総積を返す
    - 時間計算量: $O(1)$

## Reference

- [Amortize analysis of Deque with 2 Stack - slideshare](https://www.slideshare.net/catupper/amortize-analysis-of-deque-with-2-stack)
