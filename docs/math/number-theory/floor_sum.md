---
title: Sum of Floor of Linear
documentation_of: ../../../math/number-theory/floor_sum.hpp
---

## Description

一次関数の床関数の和 $\sum_{i=0}^{N-1} \left\lfloor \frac{Ai + B}{M} \right\rfloor$ を再帰的に計算する．

計算量はユークリッドの互除法と同様に対数時間となるが，どの変数に依存するのかはよくわかっていない (僕が理解していない)．

- `long long floor_sum(long long n, long long m, long long a, long long b)`
    - $\sum_{i=0}^{N-1} \left\lfloor \frac{Ai + B}{M} \right\rfloor$ を計算する