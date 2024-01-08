---
title: Garner's Algorithm
documentation_of: ../../../math/number-theory/garner.hpp
---

## Description

Garner のアルゴリズムは，連立合同式 $x \equiv b_i \mod m_i \quad (i=1,\dots,n)$ の解を求めるアルゴリズムである．

$m_i$が pairwise coprime であるとき，この連立合同式には法$m = m_1\dots m_n$のもとでただ一つの解が存在することが中国の剰余定理によって保証される．

## Operations

- `long long garner(vector<long long> b, vector<long long> m, long long mod)`
    - 連立合同式を満たす最小の非負整数を法$mod$で求める．
    - 時間計算量: $O(n^2)$


## Reference

- [中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ](https://qiita.com/drken/items/ae02240cd1f8edfc86fd)
- [Chinese Remainder Theorem](https://cp-algorithms.com/algebra/chinese-remainder-theorem.html)