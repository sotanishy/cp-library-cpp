---
title: Sparse Table
documentation_of: ../../data-structure/sparse_table.hpp
---

## Description

Sparse table は，冪等モノイド $(T, \cdot, e)$ の静的な列の区間積を高速に計算するデータ構造である．

冪等な二項演算とは， $\forall a \in T, a \cdot a = a$ が成り立つような写像 $\cdot: T \times T \rightarrow T$ である．冪等な二項演算には，max, min, gcd, bitwise and, bitwise or などがある．

空間計算量: $O(n \log n)$

## Operations

- `SparseTable(vector<T> v)`
    - `v`の要素から sparse table を構築する
    - 時間計算量: $O(n \log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(1)$

## Reference

- [Sparse Table](https://cp-algorithms.com/data_structures/sparse-table.html)