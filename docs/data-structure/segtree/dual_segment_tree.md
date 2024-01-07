---
title: Dual Segment Tree
documentation_of: ../../../data-structure/segtree/dual_segment_tree.hpp
---

## Description

双対セグメント木は，作用素モノイド $(T, \cdot, e)$ の列に対する区間更新と一点取得を提供するデータ構造である．

空間計算量: $O(n)$

## Operations

- `DualSegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の双対セグメント木を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log n)$
- `void update(int l, int r, T x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる
    - 時間計算量: $O(\log n)$

## Note

この実装は正しくは双対セグメント木ではなく，遅延伝搬セグメント木を半分にしたものである．本来の双対セグメント木では遅延伝搬をせずに，一点取得クエリの際に上に取りに行く．しかしこれは作用素モノイドに可換則を要求するため使い勝手が悪いので，ここでは便宜上遅延伝搬セグメント木を半分にしたものを双対セグメント木と呼んでいる．

## Reference

- [双対セグメント木という概念について](https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/)
- [双対セグメント木](https://hackmd.io/@tatyam-prime/DualSegmentTree)