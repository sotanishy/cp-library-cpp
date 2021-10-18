---
title: Sqrt Tree
documentation_of: ../../data-structure/sqrt_tree.cpp
---

## Description

Sqrt tree は，半群 $(T, \cdot)$ の静的な列の区間和を高速に計算するデータ構造である．平方分割を再帰的に行うことで木の高さを $O(\log\log n)$ にしている．Sparse table と比べて前処理が高速でメモリ使用量が少ないという特徴がある．

ここでは実装していないが，$O(\sqrt{N})$ で要素の更新も可能である．

空間計算量: $O(n\log\log n)$

## Operations

- `SqrtTree(vector<T> v)`
    - `v` から sqrt tree を構築する
    - 時間計算量: $O(n\log\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ を fold する
    - 時間計算量: $O(1)$

## Reference

- [Sqrt-tree: answering queries in O(1) with O(NloglogN) preprocessing.](https://codeforces.com/blog/entry/57046)
- [Sqrt-tree (part 2): modifications in O(sqrtN), lazy propagation](https://codeforces.com/blog/entry/59092)
- [OPTIMAL PREPROCESSING FOR ANSWERING ON-LINE PRODUCT QUERIES](https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.79.1554&rep=rep1&type=pdf)