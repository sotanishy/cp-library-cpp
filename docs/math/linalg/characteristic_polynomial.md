---
title: Characteristic Polynomial
documentation_of: ../../../math/linalg/characteristic_polynomial.hpp
---

## Description

正方行列の特性多項式を求める．

## Operations

- `Polynomial characteristic_polynomial(SquareMatrix mat)`
    - 与えられた正方行列の特性多項式を求める
    - 時間計算量: $O(n^3)$

## Reference

- [R. Rehman and I. Ipsen, La Budde's Method for Computing Characteristic Polynomials, https://arxiv.org/abs/1104.3769](https://arxiv.org/abs/1104.3769)
- [Characteristic Polynomial / $\det(M_0+xM_1)$ - competitive-programming-library](https://rniya.github.io/competitive-programming-library/src/matrix/characteristic_polynomial.hpp.html)