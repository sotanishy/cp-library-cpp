---
title: Leftist Heap
documentation_of: ../../data-structure/leftist_heap.cpp
---

## Description

Leftist heap は，meldable heap (マージ可能ヒープ) の一種である．

## Operations

- `static LeftistHeap meld(LeftistHeap a, LeftistHeap b)`
    - $a$ と $b$ を併合する
    - 時間計算量: $O(\lg n)$
- `pair<int, T> top()`
    - 最小値とその id を返す
    - 時間計算量: $O(1)$
- `void pop()`
    - 最小値を削除する
    - 時間計算量: $O(\lg n)$
- `void push(int id, T x)`
    - 値 $x$ を持つ要素 $id$ を追加する
    - 時間計算量: $O(\lg n)$
- `void add(T x)`
    - 全ての要素の値に $x$ を加算する
    - 時間計算量: $O(1)$

## Reference

- [Leftist Heap & Skew Heap](http://hos.ac/blog/#blog0001)