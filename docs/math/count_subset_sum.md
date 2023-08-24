---
title: Count Subset Sum
documentation_of: ../../math/count_subset_sum.hpp
---

## Description

各 $v=1,2,\dots,V$ に対して，与えられた数列の部分列であって総和が $v$ であるものの個数を数える．

## Operations

- `vector<mint> count_subset_sum(vector<int> val, int V)`
    - 各 $v=1,2,\dots,V$ に対して，総和 $v$ の部分列の個数を数える
    - 時間計算量: $O(n\log n)$
