---
title: Subset Convolution
documentation_of: ../../set/subset_convolution.hpp
---

## Description

数列 $f$ と $g$ の subset convolution $f * g$ は以下で定義される．

$$
(f * g)(S) = \sum_{T \subset S} f(T) g(S\setminus T)
$$

$f, g$ の長さを $2^n$ とするとき，素朴に部分集合を列挙する方法では計算量は $O(3^n)$ となるが，$O(n^2 2^n)$ で計算することができる．

## Operations

- `vector<T> subset_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の subset convolution を計算する
    - 時間計算量: $O(n^2 2^n)$

## Reference

- [Subset Convolutionのアルゴリズム - 37zigenのHP](https://37zigen.com/subset-convolution/)