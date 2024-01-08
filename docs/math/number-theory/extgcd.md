---
title: Extended Euclidean Algorithm
documentation_of: ../../../math/number-theory/extgcd.hpp
---

## Description

拡張 Euclid の互除法は，2変数1次不定方程式 $ax + by = \gcd(a, b)$ の解 $(x, y)$ を1組求めるアルゴリズムである．

また，これを利用して，与えられた整数 $a$ の法 $mod$ での逆元を求めることができる．Fermat の小定理を利用したアルゴリズムより制約が少なく定数倍高速であるため，基本的にこちらを用いる．

- `pair<long long, long long> extgcd(long long a, long long b)`
    - $ax + by = \gcd(a, b)$ の解 $(x, y)$ を1組求める
    - 時間計算量: $O(\log \min(a, b))$
- `long long mod_inv(long long a, long long mod)`
    - $a$ の法$mod$での逆元を求める