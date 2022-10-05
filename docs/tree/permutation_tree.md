---
title: Permutation Tree
documentation_of: ../../tree/permutation_tree.hpp
---

## Description

Permutation tree は，順列の区間のマージ過程を表す木である．$\max_{l\leq i < r} p_i - \min_{l\leq i < r} p_i = r - l$ となるような区間の数え上げなどに使える．

## Operations

- `PermutationTree(vector<int> p)`
    - 順列 $p$ から permutation tree を構築する．
    - 時間計算量: $O(n\log n)$

## Reference

- [Tutorial on Permutation Tree (析合树） - Codeforces](https://codeforces.com/blog/entry/78898)
- [Permutation tree （順列木） - cplib-cpp](https://hitonanode.github.io/cplib-cpp/other_algorithms/permutation_tree.hpp.html)



