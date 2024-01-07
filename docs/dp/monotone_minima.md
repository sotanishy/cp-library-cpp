---
title: Monotone Minima
documentation_of: ../../dp/monotone_minima.hpp
---

## Description

Monotone minima は，monotone 行列の各行の argmin を高速に求めるアルゴリズムである．

$n \times m$ 行列 $A$ が monotone であるとは，

$\mathrm{argmin} A_{i,\ast} \leq \mathrm{argmin} A_{i+1,\ast}$ が成り立つことである．

$A$ が更に totally monotone ($A$ の任意の部分行列が monotone) であれば，SMAWK algorithm という更に高速なアルゴリズムが存在する．

- `vector<int> monotone_minima(int n, int m, F f)`
    - $A_{i,j}=f(i,j)$ である $n \times m$ 行列 $A$ の各行の argmin を求める
    - 時間計算量: $O((n + m)\log n)$

## Reference

- [Totally Monotone Matrix Searching (SMAWK algorithm)](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/)