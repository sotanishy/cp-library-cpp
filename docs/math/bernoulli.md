---
title: Bernoulli Number
documentation_of: ../../math/bernoulli.hpp
---

## Description

Bernoulli 数 $B_k$ は，以下の恒等式で定義される数である．

$$
\frac{x}{e^x-1} = \sum_{k=0} \frac{B_k}{k!}x^k
$$

Bernoulli 数は，最初の $n$ 個の正整数の $p$ 乗和を与える Faulhaber の公式に現れる．

$$
\sum_{k=1}^n k^p = \frac{1}{p+1} \sum_{j=0}^p (-1)^j \binom{p+1}{j} B_j n^{p-j+1}
$$

## Operations

- `vector<T> bernoulli_table(int n)`
    - $B_k$ を各 $k=0,1,\dots,n$ について計算する
    - 時間計算量: $O(n\log n)$
- `T sum_of_powers(long long n, int p)`
    - $\sum_{k=1}^n k^p$ を計算する
    - 時間計算量: $O(p \log p)$
- `vector<T> sum_of_powers_table(long long n, int p)`
    - $\sum_{k=1}^n k^r$ を各 $r = 0,1,\dots,p$ について 計算する
    - 時間計算量: $O(p \log p)$

## Reference

- verify: [https://atcoder.jp/contests/oupc2023-day1/submissions/49058484](https://atcoder.jp/contests/oupc2023-day1/submissions/49058484)

