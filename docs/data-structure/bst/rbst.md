---
title: Randomized Binary Search Tree
documentation_of: ../../../data-structure/bst/rbst.cpp
---

## Description

Randomized binary search tree は，平衡二分探索木の一種である．treap とほとんど同じだが，ノードにランダムな優先度を与えるのではなく，木を併合するときに木の根を部分木のサイズに比例する確率でランダムに決める．モノイドを扱い，セグメント木が提供する操作に加えて挿入，削除，併合，分割，区間反転が可能である．

空間計算量: $O(n)$

## Operations

- `static RBST join(RBST l, RBST r)`
    - `l` と `r` を併合する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `pair<RBST, RBST> split(int k)`
    - $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void update(int k, T x)`
    - $k$ 番目の要素の値を $x$ に変更する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void reverse(int l, int r)`
    - 区間 $[l, r)$ を反転する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void insert(int k, T x)`
    - $k$ 番目に $x$ を挿入する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void erase(int k)`
    - $k$ 番目の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void push_front(T x)`
- `void push_back(T x)`
- `void pop_front()`
- `void pop_back()`
    - 先頭/末尾への要素の追加/削除
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 空か判定する
    - 時間計算量: $O(1)$

## Reference

- [プログラミングコンテストでのデータ構造 2　～平衡二分探索木編～](https://www.slideshare.net/iwiwi/2-12188757)