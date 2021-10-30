---
title: Fenwick Tree
documentation_of: ../../data-structure/fenwick_tree.cpp
---

## Description

Fenwick tree，または binary indexed tree (BIT) は，可換モノイド $(T, \cdot, e)$ の列に対する一点更新と接頭辞和の取得を提供するデータ構造である．

セグメント木より制約が強く，操作が限られているが，実装が簡潔で定数倍速い．浮動小数点の演算をするときは，セグメント木よりも誤差が大きくなる傾向があるので注意が必要である．

空間計算量: $O(n)$

## Operations

- `FenwickTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の Fenwick tree を構築する
    - 時間計算量: $O(n)$
- `T prefix_fold(int i)`
    - 区間 $[0, i)$ の値を fold する
    - 時間計算量: $O(\log n)$
- `void update(int i, T x)`
    - $i$ 番目の要素を $x$ と演算した値に更新する
    - 時間計算量: $O(\log n)$
- `int lower_bound(T x)`
- `int lower_bound(T x, Compare cmp)`
    - `cmp(prefix_fold(i), x) == false` となる最初の $i$ を返す．そのような $i$ が存在しない場合は $n$ を返す．`cmp` を指定しない場合は `<` で比較される．列の単調性を仮定する．
    - 時間計算量: $O(\log n)$

## Reference

- [Binary Indexed Tree のはなし](http://hos.ac/slides/20140319_bit.pdf)