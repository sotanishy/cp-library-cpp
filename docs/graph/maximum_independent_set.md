---
title: Maximum Independent Set
documentation_of: ../../graph/maximum_independent_set.hpp
---

## Description

最大独立集合を求める．

計算量はよくわからないが，実用上は非常に高速である．$n = 40$ のときに 2 ms 程度で動作する．

## Operations

- `vector<int> maximum_independent_set(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき， $G$ の最大独立集合を求める．
    - 時間計算量: $O(n1.466^n)$