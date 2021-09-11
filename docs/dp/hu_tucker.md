---
title: Hu-Tucker Algorithm
documentation_of: ../../dp/hu_tucker.cpp
---

## Description

Hu-Tucker のアルゴリズムは，最適二分探索木問題を高速に解くアルゴリズムである．

正当性の証明は難しいらしい．

- `T hu_tucker(vector<T> w)`
    - 各頂点の重み $w_i$ が与えられたとき，最適二分探索木の重みを求める．
    - 時間計算量: $O(n\lg n)$

## Reference

- [C - 最適二分探索木](https://atcoder.jp/contests/atc002/tasks/atc002_c)