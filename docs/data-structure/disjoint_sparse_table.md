---
title: Disjoint Sparse Table
documentation_of: ../../data-structure/disjoint_sparse_table.cpp
---

## Description

Disjoint sparse table は，半群 $(T, \cdot)$ の静的な列の区間和を高速に計算するデータ構造である．Sparse table と違って二項演算 $\cdot$ に冪等性を要求しない．

空間計算量: $O(n \lg n)$

## Operations

- `DisjointSparseTable(vector<T> v)`
    - `v`の要素から disjoint sparse table を構築する
    - 時間計算量: $O(n \log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(1)$

## Reference

- [[Tutorial] Disjoint Sparse Table](https://discuss.codechef.com/t/tutorial-disjoint-sparse-table/17404)
- [Disjoint Sparse Table と セグ木に関するポエム](https://noshi91.hatenablog.com/entry/2018/05/08/183946)