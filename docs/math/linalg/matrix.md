---
title: Matrix
documentation_of: ../../../math/linalg/matrix.hpp
---

## Description

行列を表す．

## Operations

- `Matrix(int n)`
    - $n \times n$ 零行列を構築する
- `Matrix(int row, int col)`
    - $\mathit{row} \times \mathit{col}$ 零行列を構築する
- `Matrix(vector<vector<T>> mat)`
    - `mat` の要素で行列を構築する
- `static Matrix concat(Matrix A, Matrix B)`
    - $A$ と $B$ を結合した行列を返す
- `static Matrix I(int n)`
    - $n \times n$ 単位行列を返す
- `Matrix operator*(Matrix rhs)`
    - 行列積を計算する
    - 時間計算量: $O(n^3)$
- `Matrix transpose()`
    - 転置行列を返す
- `void reduce()`
    - 行列を掃き出す
    - 時間計算量: $O(n^3)$
- `int rank()`
    - の階数を返す
    - 時間計算量: $O(n^3)$

## Operations for Square Matrices

- `Matrix pow(long long k)`
    - 行列の $k$ 乗を返す
    - 時間計算量: $O(n^3 \log k)$
- `T det()`
    - 行列式を返す
    - 時間計算量: $O(n^3 \log k)$
- `Matrix inv()`
    - 逆行列を返す
    - 時間計算量: $O(n^3)$