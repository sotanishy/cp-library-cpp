---
title: Carmichael Function
documentation_of: ../../math/carmichael.cpp
---

## Description

Carmichael 関数 $\lambda(n)$ の値を求める．これは，$n$ と互いに素である $n$ 以下の自然数 $a$ 全てに対して$a^m \equiv 1 \mod n$ を満たすような最小の自然数 $m$ を与える．

Euler の定理より $m = \phi(n)$ は上の条件を満たすが，それが最小の $m$ であるとは限らない．最小の $m$ が $\lambda(n)$ である．

## Operations

- `long long carmichael(long long n)`
    - $\lambda(n)$ を求める
    - 時間計算量: $O(\sqrt{n})$