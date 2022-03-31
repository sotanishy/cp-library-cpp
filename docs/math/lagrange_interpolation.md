---
title: Lagrange Interpolation
documentation_of: ../../math/lagrange_interpolation.hpp
---

## Description

Lagrange 補間は，$d+1$ 点が与えられたときにそれらを通る$d$次以下の多項式を求めるアルゴリズムである．この多項式は一意に定まる．

## Operations

- `T lagrange_interpolation(vector<T> f, long long n)`
    - $f(0),f(1),\dots,f(d)$ が与えられたときに，$f(n)$を求める
    - 時間計算量: $O(d)$

## Reference

- [ABC208 F - Cumulative Sum 解説](https://atcoder.jp/contests/abc208/editorial/2195)