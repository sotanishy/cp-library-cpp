---
title: Stirling Number of the First Kind
documentation_of: ../../math/stirling_first.hpp
---

## Description

第1種 Stirling 数 $s(n,k)$ は，以下の恒等式で定義される数である．

$$
x(x-1)\cdots(x-(n-1)) = \sum_{k=0}^n s(n,k) x^k
$$

$s(n,k)$ の絶対値 (${n \brack k}$ と書く) は，$n$ 要素の置換のうち，$k$ 個のサイクルに分解されるものの個数である．

## Operations

- `vector<T> stirling_first_table(int n)`
    - $s(n,k)$ を各 $k=0,1,\dots,n$ について計算する
    - 時間計算量: $O(n\log n)$

## Notes

第1種 Stirling 数について以下の式が成り立つ．

$$
s(n,k) = (-1)^{(n-k)} {n \brack k}
$$

$$
{n\brack k} = {n-1\brack k-1} + (n-1){n-1 \brack k}
$$

## Reference

- [「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)

