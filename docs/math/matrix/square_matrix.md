---
title: Square Matrix
documentation_of: ../../../math/matrix/square_matrix.cpp
---

## Description

正方行列を表す．

## Operations

- `SquareMatrix(int n)`
    - $n \times n$ 零行列を構築する
    - 時間計算量: $O(n^2)$
- `SquareMatrix(initializer_list<initializer_list<T>> list)`
    - `list` の要素で正方行列を構築する
    - 時間計算量: $O(n^2)$
- `static SquareMatrix I(int n)`
    - $n \times n$ 単位行列を返す
    - 時間計算量: $O(n^2)$
- `SquareMatrix pow(long long k)`
    - $A^k$ を返す
    - 時間計算量: $O(n^3 \log k)$
- `T det()`
    - 行列式 $\det(A)$ を返す
    - 時間計算量: $O(n^3)$
- `SquareMatrix inv()`
    - 逆行列 $A^{-1}$ を返す
    - 時間計算量: $O(n^3)$