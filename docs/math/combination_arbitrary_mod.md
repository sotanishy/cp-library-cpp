---
title: Combination
documentation_of: ../../math/combination_arbitrary_mod.hpp
---

## Description

二項係数を任意の mod で計算する．

- `vector<mint> combination_arbitrary_mod(int n)`
    - $\binom{n}{k}\quad (k=0,\dots,n)$ を mod $m$ で計算する
    - 時間計算量: $O(n\log m / \log\log m)$

## Reference

- [任意 mod で二項係数を列挙する](https://qiita.com/suisen_cp/items/d0ab7e728b98bbec818f)