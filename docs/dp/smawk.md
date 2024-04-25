---
title: SMAWK Algorithm
documentation_of: ../../dp/smawk.hpp
---

## Description

SMAWK algorithm は，totally monotone 行列の各行の argmin を高速に求めるアルゴリズムである．

単に monotone の場合は monotone minima が使える．

- `vector<int> smawk(int n, int m, F f)`
    - $A_{i,j}=f(i,j)$ である $n \times m$ 行列 $A$ の各行の argmin を求める
    - 時間計算量: $O(n + m)$

## Note

多分壊れてる．monotone minima使って

## Reference

- [Totally Monotone Matrix Searching (SMAWK algorithm)](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/)
- [The SMAWK Algorithm](http://web.cs.unlv.edu/larmore/Courses/CSC477/monge.pdf)
- [SMAWK Algorithm](https://noshi91.github.io/Library/algorithm/smawk.cpp.html)