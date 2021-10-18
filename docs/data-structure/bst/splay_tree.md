---
title: Splay Tree
documentation_of: ../../../data-structure/bst/splay_tree.cpp
---

## Descriptions

Splay tree は，平衡二分探索木の一種である．ノードを根に持ってくる splay という操作を利用して様々な操作を実現している．同じ要素への連続アクセスが高速であるという特徴がある．モノイドを扱い，セグメント木が提供する操作に加えて挿入，削除，併合，分割，区間反転が可能である．

空間計算量: $O(n)$

## Operations

- `static SplayTree join(SplayTree l, SplayTree r)`
    - `l` と `r` を併合する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `pair<SplayTree, SplayTree> split(int k)`
    - $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void update(int k, T x)`
    - $k$ 番目の要素の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void reverse(int l, int r)`
    - 区間 $[l, r)$ を反転する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void insert(int k, T x)`
    - $k$ 番目に $x$ を挿入する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void erase(int k)`
    - $k$ 番目の要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void push_front(T x)`
- `void push_back(T x)`
- `void pop_front()`
- `void pop_back()`
    - 先頭/末尾への要素の追加/削除
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 空か判定する
    - 時間計算量: $O(1)$

## Reference

- [プログラミングコンテストでのデータ構造 2　～平衡二分探索木編～](https://www.slideshare.net/iwiwi/2-12188757)
- [Splay tree](https://en.wikipedia.org/wiki/Splay_tree)
- [Self-adjusting Binary Search Trees](https://www.cs.cmu.edu/~sleator/papers/self-adjusting.pdf)