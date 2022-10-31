---
title: Intervals
documentation_of: ../../misc/intervals.hpp
---

## Description

整数の閉区間を管理する．

機能的には range update point get の双対セグメント木の上位互換である (`long long` 型の座標を扱える + 区間の列挙が可能である)．

## Operations

- `Intervals(T default_val)`
    - デフォルトの値 `default_val` を受け取り，初期化する
- `T get(X x)`
    - 点 $x$ での値を返す
    - 時間計算量: $O(\log n)$
- `vector<tuple<X, X, T>> get(X l, X r)`
    - 区間 $[l, r]$ と交わる区間を返す
    - 時間計算量: $O(k\log n)$, $k$ は $[l, r]$ と交わる区間の数
- `void set(X l, X y, T v)`
    - 区間 $[l, r]$ の値を $v$ に更新する．
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void erase(X l, X r)`
    - 区間 $[l, r]$ の値をデフォルトの値に戻す
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$