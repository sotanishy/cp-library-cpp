---
title: Combination
documentation_of: ../../math/combination.cpp
---

## Description

階乗 $n!$，組み合わせ $n \choose r$，順列 $_n \mathrm{P} _r$ を法 $mod$ で計算する．

空間計算量: $O(n)$

## Operations

- `Combination(int n)`
    - $n$ 以下の整数の階乗及びその逆元を前計算する
    - 時間計算量: $O(n)$
- `T perm(int n, int r)`
    - $_n \mathrm{P} _r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$
- `T comb(int n, int r)`
    - $n \choose r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$
- `T fact(int n)`
    - $n!$ を計算する
    - 時間計算量: $O(1)$
- `T fact_inv(int n)`
    - $n!$ の逆元を計算する
    - 時間計算量: $O(1)$

以下の関数は`Combination`クラスに含まれない

- `T comb(int n, int r)`
    - $n \choose r$ を計算する．
    - 時間計算量: $O(r)$