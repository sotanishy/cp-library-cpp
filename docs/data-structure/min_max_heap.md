---
title: Min-Max Heap
documentation_of: ../../data-structure/min_max_heap.hpp
---

## Description

Min-max heap は，要素の最大値と最小値を取得することのできるヒープである．

## Operations

- `MinMaxHeap(vector<T> v)`
    - $v$ の要素から min-max heap を構築する
    - 時間計算量: $O(n)$
- `void insert(T x)`
    - $x$ を挿入する
    - 時間計算量: $O(\log n)$
- `T min_element()`
    - 最小値を求める
    - 時間計算量: $O(1)$
- `T max_element()`
    - 最大値を求める
    - 時間計算量: $O(1)$
- `void erase_min()`
    - 最小値を削除する
    - 時間計算量: $O(\log n)$
- `void erase_max()`
    - 最大値を削除する
    - 時間計算量: $O(\log n)$

## Reference

- [Min-max heap - Wikipedia](https://en.wikipedia.org/wiki/Min-max_heap)