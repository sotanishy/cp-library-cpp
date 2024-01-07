---
title: Kitamasa's Algorithm
documentation_of: ../../math/kitamasa.cpp
---

## Description

Kitamasa 法は，$d$ 階線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．

## Operations

- `T kitamasa(vector<T> a, vector<T> c, long long n)`
    - 初めの $d$ 項 $a_0, \dots, a_{d-1}$ と漸化式 $a_n = c_0 a_{n-d} + \dots + c_{d-1} a_{n-1}$ によって定まる数列 $(a_n)$ の第 $n$ 項を求める．
    - 時間計算量: $O(d^2 \log n)$

## Reference

- [きたまさ法メモ](https://yosupo.hatenablog.com/entry/2015/03/27/025132)