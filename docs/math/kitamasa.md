---
title: Kitamasa's Algorithm
documentation_of: ../../math/kitamasa.cpp
---

## Description

Kitamasa 法は，$k$ 階線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．

- `T kitamasa(vector<T> a, vector<T> d, int n)`
    - 初めの $k$ 項 $a_0, \dots, a_{k-1}$ と漸化式 $a_n = d_0 a_{n-k} + \dots + d_{k-1} a_{n-1}$ によって定まる数列 $(a_n)$ の第 $n$ 項を求める．
    - 時間計算量: $O(k^2 \lg n)$

## Reference

- [きたまさ法メモ](https://yosupo.hatenablog.com/entry/2015/03/27/025132)