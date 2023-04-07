---
title: Xor Segment Tree
documentation_of: ../../../data-structure/segtree/xor_segment_tree.hpp
---

## Description

XOR セグメント木は，通常のセグメント木の操作の際に， index をすべて非負整数 $x$ との xor を適用したものに置き換えて操作することができる．

空間計算量: $O(n \log n)$

## Operations

- `XorSegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ のセグメント木を構築する
    - 時間計算量: $O(n\log n)$
- `SegmentTree(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`のセグメント木を構築する
    - 時間計算量: $O(n\log n)$
- `void update(int k, T x)`
    - $k$ 番目の要素を $x$ に更新する
    - 時間計算量: $O(\sqrt{n})$
- `T fold(int l, int r, int x)`
    - $a_{l\oplus x} * a_{(l+1)\oplus x} * \dots * a_{(r-1) \oplus x}$ を計算する
    - 時間計算量: $O(\sqrt{n})$

## Note

モノイドが可換であるバージョン `XorSegmentTreeCommutative` は，通常のセグメント木と同じ計算量で各種操作を実行することができる．

## Reference

- verify: [https://yukicoder.me/submissions/847011](https://yukicoder.me/submissions/847011)
