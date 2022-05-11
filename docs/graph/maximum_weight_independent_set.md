---
title: Maximum Weight Independent Set
documentation_of: ../../graph/maximum_weight_independent_set.hpp
---

## Description

最大重み独立集合の重みを求める．半分全列挙を用いている．

## Operations

- `T maximum_weight_independent_set(vector<vector<int>> G, vector<T> w)`
    - グラフ $G$ の隣接リストと各頂点の重みが与えられたとき， $G$ の最大重み独立集合の重みを求める．
    - 時間計算量: $O(n^2 2^{n/2})$
