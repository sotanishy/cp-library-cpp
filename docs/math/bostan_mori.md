---
title: Bostan-Mori Algorithm
documentation_of: ../../math/bostan_mori.hpp
---

## Description

Bostan-Mori algorithm は，$d$ 階線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．

## Operations

- `T bostan_mori_division(Polynomial<T> p, Polynomial<T> q, long long n)`
    - $p(x)/q(x)$ の第 $n$ 項を求める．
    - 時間計算量: $O(\mathsf{M}(k) \log n)$, $\mathsf{M(k)}$ は$k$次多項式乗算の計算量 (FFT なら $O(k\log k)$)
- `T bostan_mori_recurrence(vector<T> a, vector<T> c, long long n)`
    - 初めの $k$ 項 $a_0, \dots, a_{k-1}$ と漸化式 $a_n = c_0 a_{n-1} + \dots + c_{k-1} a_{n-k}$ によって定まる数列 $(a_n)$ の第 $n$ 項を求める．
    - 時間計算量: 同上

## Reference

- [線形漸化的数列のN項目の計算 - Qiita](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a)
