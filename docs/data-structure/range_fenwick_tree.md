---
title: Fenwick Tree with Range Update
documentation_of: ../../data-structure/range_fenwick_tree.hpp
---

## Description

接頭辞和を扱う Fenwick tree を2つ使うことで，区間加算を実現できる．

空間計算量: $O(n)$

## Operations

- `RangeFenwickTree(int n)`
    - サイズ`n`で要素がすべて $0$ の区間更新 Fenwick tree を構築する
    - 時間計算量: $O(n)$
- `T prefix_sum(int i)`
    - $[0, i)$ の総和を計算する
    - 時間計算量: $O(\log n)$
- `void add(int l, int r, T x)`
    - 区間 $[l, r)$ に $x$ を加える
    - 時間計算量: $O(\log n)$

## Reference

- [Binary Indexed Tree のはなし](http://hos.ac/slides/20140319_bit.pdf)