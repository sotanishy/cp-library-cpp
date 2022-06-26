---
title: Intervals
documentation_of: ../../misc/intervals.hpp
---

## Description

整数の閉区間の集合を管理する．

## Operations

- `bool covered(T x)`
- `bool covered(T l, T r)`
    - 区間 $[l, r]$ が含まれているか判定する
    - 時間計算量: $O(\log n)$
- `vector<pair<T, T>> get(T x)`
    - $x$ を含む区間を返す．そのような区間がない場合 $(-\infty, \infty)$ を返す．
    - 時間計算量: $O(\log n)$
- `vector<pair<T, T>> get(T l, T r)`
    - 区間 $[l, r]$ と交わる区間を返す．
    - 時間計算量: $O(\log n)$
- `void insert(T x)`
- `void insert(T l, T r)`
    - 区間 $[l, r]$ を集合に追加する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void erase(T x)`
- `void erase(T l, T r)`
    - 区間 $[l, r]$ を集合から削除する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `T mex(T x)`
    - $x$ 以上の整数のうち，集合に含まれない最小のものを返す
    - 時間計算量: $O(\log n)$

## Note

隣り合う区間はマージされるので，マージしたくない場合は座標を2倍するなどして適当に処理する．

## Reference

- [区間をsetで管理するやつでもうバグらせたくない](https://mugen1337.hatenablog.com/entry/2020/10/14/134022)
- [要素の追加・削除と mex を対数時間で処理するよ](https://rsk0315.hatenablog.com/entry/2020/10/11/125049)

