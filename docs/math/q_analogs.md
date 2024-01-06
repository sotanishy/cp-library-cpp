---
title: q-Analogs
documentation_of: ../../math/q_analogs.hpp
---

## Description

$q$-数, $q$-階乗, $q$-二項係数を計算する．

空間計算量: $O(n)$

## Operations

- `qAnalogs(mint q, int n)`
    - $n$ 以下の非負整数の $q$-数， $q$-階乗及びその逆元を前計算する
    - 時間計算量: $O(n)$
- `T number(int n)`
    - $[n]_q$ を返す
    - 時間計算量: $O(1)$
- `T fact(int n)`
    - $[n]_q!$ を返す
    - 時間計算量: $O(1)$
- `T fact_inv(int n)`
    - $[n]_q!$ の逆元を返す
    - 時間計算量: $O(1)$
- `T binom(int n, int k)`
    - $\binom{n}{k}_q$ を返す
    - 時間計算量: $O(1)$

## Reference

- [ABC278 Ex - make 1 解説](https://atcoder.jp/contests/abc278/editorial/5210)
- verify: [https://atcoder.jp/contests/abc278/submissions/49047601](https://atcoder.jp/contests/abc278/submissions/49047601)