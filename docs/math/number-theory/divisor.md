---
title: Divisor
documentation_of: ../../../math/number-theory/divisor.hpp
---

## Description

$n$ の約数を試し割り法で全て求める．

## Operations

- `vector<long long> divisor(long long n)`
    - $n$ の約数を昇順で返す
    - 時間計算量: $O(\sqrt{n})$