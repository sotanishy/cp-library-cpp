---
title: Stirling Number of the Second Kind
documentation_of: ../../math/stirling_second.hpp
---

## Description

第2種 Stirling 数 ${n \brace k}$ は，以下の恒等式で定義される数である．

$$
{n \brace k} = \frac{1}{k!} \sum_{i=0}^n (-1)^{k-i} \binom{k}{i} i^n
$$


${n \brace k$ は，$n$ 個の区別できるボールを， $k$ 個の区別できない箱に，すべての箱に1つ以上のボールが入るように分配する方法の数である．

## Operations

- `vector<T> stirling_second_table(int n)`
    - ${n \brace k}$ を各 $k=0,1,\dots,n$ について計算する
    - 時間計算量: $O(n\log n)$
- `T stirling_second(int n, int k)`
    - ${n \brace k}$ を計算する
    - 時間計算量: $O(n+k\log n)$

## Notes

第2種 Stirling 数について以下の式が成り立つ．

$$
x^n = \sum_{k=0}^n {n\brace k} x(x-1)\cdots(x-(k-1))
$$

$$
{n\brace k} = {n-1\brace k-1} + k{n-1 \brace k}
$$

## Reference

- [「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)
