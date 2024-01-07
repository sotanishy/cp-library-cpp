---
title: Treap with Lazy Propagation
documentation_of: ../../../data-structure/bst/lazy_treap.hpp
---

## Description

遅延伝搬 treap は，区間更新が可能な treap である．扱える代数的構造は遅延伝搬セグメント木と同様なので，そちらを参照．遅延伝搬セグメント木が提供する操作に加えて挿入，削除，併合，分割，区間反転が可能である．

基本的には非可換のモノイドも扱えるが，`reverse` 操作をする場合は可換性が必要である．非可換も実装を少しいじれば扱えるがめんどくさいので実装していない．

空間計算量: $O(n)$

## Operations

- `static Treap join(Treap l, Treap r)`
    - `l` と `r` を併合する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `pair<Treap, Treap> split(int k)`
    - $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる．
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
    - 先頭/末尾に $x$ を追加する/の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 空か判定する
    - 時間計算量: $O(1)$

## Note

本当は`std::unique_ptr`を使いたいんだがなぜかGitHub上でめちゃくちゃ遅くなるので生ポインタを使っている．`std::unique_ptr`にしてコンパイルが通るような書き方はしているので生ポインタによる怖いことは起きないと思う．