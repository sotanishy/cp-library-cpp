---
title: Arbitrary Mod Convolution
documentation_of: ../../math/arbitrary_mod_convolution.cpp
---

## Description

任意の mod で畳み込みを計算する．

$p_1 = 167772161, p_2 = 469762049, p_3 = 754974721$ の3つの素数を用いた数論変換による畳み込みを計算した後，Garner のアルゴリズムで答えを復元する．

mod を取る前の値が $p_1 \times p_2 \times p_3$ 未満なら正しく復元できるので，mod が 32-bit 整数の場合 $n \leq 2^22$ 程度までなら計算できる．

## Operations

- `vector<int> arbitrary_mod_convolution(vector<int> a, vector<int>, int mod)`
    - $a$ と $b$ の畳み込みを $mod$ で割った余りを計算する
    - 時間計算量: $O(n\log n)$
