---
title: Dynamic Segment Tree
documentation_of: ../../../data-structure/segtree/dynamic_segment_tree.hpp
---

## Description

動的セグメント木は，モノイド $(T, \cdot, e)$ の列に対する一点更新と区間取得を提供するデータ構造である．必要なノードだけを動的に構築することで， $n$ が非常に大きい場合でも効率的に値を管理することができる．

空間計算量: $O(m\log n)$．$m$ は追加した要素の数

## Operations

- `DynamicSegmentTree(long long n)`
    - サイズ`n`で要素がすべて単位元 $e$ の動的セグメント木を構築する
    - 時間計算量: $O(\log n)$
- `T operator[](long long k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log n)$
- `void update(long long k, T x)`
    - $k$ 番目の要素を $x$ に更新する
    - 時間計算量: $O(\log n)$
- `T fold(long long l, long long r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(\log n)$