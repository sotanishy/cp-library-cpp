---
title: Partition Function
documentation_of: ../../math/partition_function.hpp
---

## Description

非負整数 $n$ に対し，分割数 $p(n)$ とは， $n$ を順番の違いを除いて正整数の総和として表す方法の総数である．

分割数 $p(n)$ の母関数は次式で与えられる．

$$
\sum_{n=0}^\infty p(n)x^n = \prod_{k=1}^\infty \frac{1}{1-x^k}
$$

右辺の分母は， Euler の五角数定理によって高速に計算できる．

## Operations

- `Polynomial<T> partition_function_table(int n)`
    - $p(k)$ を各 $k=0,1,\dots,n$ について計算する
    - 時間計算量: $O(n\log n)$
