---
title: Assignment Problem (Maximum Weight Perfect Matching)
documentation_of: ../../graph/assignment.hpp
---

## Description

割当問題 (最大重み完全マッチング) を Hungarian 法で解く．

## Operations

- `vector<int> assignment(vector<vector<T>> a)`
    - $\sum_{i=1}^n a_{i,p_i}$ を最大化する $(p_i)_{i=1,\dots,n}$ を返す
    - 時間計算量: $O(n^3)$

## Reference

- Lee, Jon. *A First Course in Combinatorial Optimization*. Cambridge: Cambridge University Press, 2010
- [Assignment Problem and Hungarian Algorithm](https://www.topcoder.com/thrive/articles/Assignment%20Problem%20and%20Hungarian%20Algorithm)