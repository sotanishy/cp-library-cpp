---
title: System of Linear Equations
documentation_of: ../../../math/linalg/system_of_linear_equations.hpp
---

## Description

連立一次方程式を解く．

## Operations

- `vector<vector<T>> solve_system(Matrix<T> A, vector<T> b)`
    - $Ax = b$ の解を返す．返り値を `sol` としたとき，`sol[0]` は解の1つ，`sol[1:]` は解空間の基底である．解がないときは空リストを返す．
    - 時間計算量: $O(mn^2)$
