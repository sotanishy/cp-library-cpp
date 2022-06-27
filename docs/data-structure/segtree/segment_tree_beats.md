---
title: Segment Tree Beats
documentation_of: ../../../data-structure/segtree/segment_tree_beats.cpp
---

## Description

Segment tree beats は，遅延伝搬セグメント木の亜種で，作用の分配則が成り立たず，作用に失敗した場合に，子に関する計算結果を用いてボトムアップに再構築するデータ構造である．

作用 `act` の返り値の型は `pair<M::T, bool>` で，作用に失敗した場合 `false` を返す．

空間計算量: $O(n)$

## Operations

- `SegmentTreeBeats(int n)`
    - サイズ`n`で要素がすべて単位元 $e_M$ の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `SegmentTreeBeats(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する

## Note

時間計算量はモノイドや作用の設計による．

実現できる機能の例
- range chmin/chmax/add, range sum (Library Checker - Range Chmin Chmax Add Range Sum)
    - chmin/chmax クエリで，sum の計算に失敗する．
    - 計算量は $\mathrm{amortized}\,O(\log^2 n)$
    - 計算量解析はわからん．
- range divide/update, range sum (ABC256Ex - I like Query Problem)
    - 区間に含まれる要素がすべて同じではない場合，divide クエリに失敗する．
    - 計算量は $\mathrm{amortiezed}\,O(\log n \log \max A)$
    - 計算量解析は [公式解説](https://atcoder.jp/contests/abc256/editorial/4113) を参照．

## Reference

- [A simple introduction to "Segment tree beats" - Codeforces](https://codeforces.com/blog/entry/5731)
- [Segment Tree Beatsの実装メモ (基本まわり) - 日々ｄｒｄｒする人のメモ](https://smijake3.hatenablog.com/entry/2019/04/28/021457)
- [atcoder::lazy_segtree に1行書き足すだけの抽象化 Segment Tree Beats - ひとなので](https://rsm9.hatenablog.com/entry/2021/02/01/220408)