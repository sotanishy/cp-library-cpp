---
title: Factorial
documentation_of: ../../math/factorial.hpp
---

## Description

$n! \pmod m$ を計算する

空間計算量: $O(\sqrt{m} \log m)$

## Operations

- `Factorial()`
    - 前計算を行う
    - 時間計算量: $O(\sqrt{m} (\log m)^2)$
- `mint query(int m)`
    - $n! \pmod m$ を計算する
    - 時間計算量: $O(\sqrt{m})$

## Reference

- [Multipoint Evaluation の アルゴリズム - 37zigenのHP](https://37zigen.com/multipoint-evaluation/)