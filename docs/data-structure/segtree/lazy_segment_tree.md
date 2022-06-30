---
title: Segment Tree with Lazy Propagation
documentation_of: ../../../data-structure/segtree/lazy_segment_tree.cpp
---

## Description

遅延伝搬セグメント木は，モノイド $(T, \cdot, e_M)$ の列と，作用素モノイド $(E, \circ, e_O)$ による作用 $*: T \times E \rightarrow T$ を扱うデータ構造である．区間更新と区間取得を提供する．

作用 $*$ は $T$ の準自己同型である．すなわち，以下の性質が成り立つ．
- $\forall a \in T, a * e_O = a$
- $\forall a \in T, f, g \in E, a * (f \circ g) = (a * f) * g$
- $\forall a, b \in T, f \in E, (a \cdot b) * f = (a * f) \cdot (b * f)$

空間計算量: $O(n)$

## Operations

- `LazySegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e_M$ の遅延伝搬セグメント木を構築する
    - 時間計算量: $O(n)$
- `LazySegmentTree(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の遅延伝搬セグメント木を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log n)$
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる
    - 時間計算量: $O(\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(\log n)$
- `int find_first(int l, F cond)`
    - `fold(l, r)` が条件 `cond` を満たすような最小の $r (> l)$ 返す．列の単調性を仮定する．そのような $r$ が存在しない場合は `-1` を返す
    - 時間計算量: $O(\log n)$
- `int find_last(int r, F cond)`
    - `fold(l, r)` が条件 `cond` を満たすような最大の $l (< r)$ 返す．列の単調性を仮定する．そのような $l$ が存在しない場合は `-1` を返す
    - 時間計算量: $O(\log n)$

## Note

作用が区間の長さに比例するとき (e.g. 区間加算)，作用の分配則は成り立たないが，これはモノイドを $T \times \mathbb{N}$ に拡張して区間の長さを持たせ，適切に $*$ を定義することで対処できる．

また，作用素が単位元を持たない半群であるとき（e.g. 区間更新）は，適当な値を集合に添加してそれを単位元として扱うことができる．

作用素の分配則が成り立たない場合，Segment tree beats を用いて高速に計算できる場合がある．

## Reference

- [遅延評価セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/30/224339)
- [遅延伝播セグメント木について](https://beet-aizu.hatenablog.com/entry/2017/12/01/225955)
- [SegmentTreeに載る代数的構造について](https://qiita.com/keymoon/items/0f929a19ed30f34ae6e8)
- [遅延伝搬segment木についてもっと詳しく](https://kimiyuki.net/blog/2018/11/03/lazy-propagation-segment-tree/)
