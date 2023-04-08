---
title: Lagrange Polynomial
documentation_of: ../../math/lagrange_polynomial.hpp
---

## Description

Lagrange 多項式は，与えられた $d+1$ 点を通る $d$ 次以下の多項式である．この多項式は存在すれば一意に定まる．

## Operations

- `Polynomial<T> lagrange_polynomial(vector<T> x, vector<T> y)`
    - $(x_i,y_i)\,(i=0,1,\dots,n)$ を通る Lagrange 多項式を求める
    - 時間計算量: $O(n (\log n)^2)$

## Reference

- [多項式補間：アルゴリズム](https://37zigen.com/lagrange-interpolation/)
