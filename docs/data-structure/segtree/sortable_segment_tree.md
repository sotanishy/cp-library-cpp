---
title: Sortable Segment Tree
documentation_of: ../../../data-structure/segtree/sortable_segment_tree.hpp
---

## Description

通常のセグメント木の機能に加えて，区間ソートクエリを処理することができる．ソートされた区間を，キーを添字とする動的セグメント木で管理することでこれを実現する．キーは distinct な 64-bit 整数である．

空間計算量: $O(n\log m)$, $m$ はキーの最大値

## Operations

- `SortableSegmentTree(long long max_key, vector<pair<long long, T>> kv)`
    - キーと値のペアの列から，ソート可能セグメント木を構築する
    - 時間計算量: $O(n \log m)$
- `void update(int k, long long key, T val)`
    - $k$ 番目の要素のキーを `key` に，値を `val` に更新する
    - 時間計算量: $O(\log m)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(\log m)$
- `void sort(int l, int r, bool descending = false)`
    - 区間 $[l, r)$ をキーをもとにソートする
    - 時間計算量: $\mathrm{amortized}\ O(\log m)$

## Reference

- [Range Sort Range Product ってなんですか - Mathenachia](https://www.mathenachia.blog/range-sort-range-product/)