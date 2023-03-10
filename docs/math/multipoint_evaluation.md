---
title: Multipoint Evaluation
documentation_of: ../../math/multipoint_evaluation.cpp
---

## Description

多点評価は，与えられた $m$ 点での多項式の値を評価する問題である．

## Operations

- `vector<T> multipoint_evaluation(Polynomial p, vector<T> x)`
    - $p(x_1),p(x_2),\dots,p(x_m)$ の値を評価する
    - 時間計算量: $O(m(\log m)^2+n\log n)$

## Reference

- [Multipoint Evaluation の アルゴリズム - 37zigenのHP](https://37zigen.com/multipoint-evaluation/)