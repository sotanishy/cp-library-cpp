---
title: Möbius Function
documentation_of: ../../math/moebius.hpp
---

## Description

Möbius 関数 $\mu(n)$ は次のように定義される:
- $\mu(n) = 0$ ($n$ が平方因子を持つとき)
- $\mu(n) = (-1)^k$ ($n$ の素因数が $k$ 個のとき)

## Operations

- `int moebius(long long n)`
    - $\mu(n)$ を求める
    - 時間計算量: $O(\sqrt{n})$
- `vector<int> moebius_table(n)`
    - $n$ 以下の正整数 $i$ について $\mu(i)$ を求める
    - 時間計算量: $O(n \log\log n)$
- `pair<vector<mint>, vector<mint>> mertens_table(long long n)`
    - 自然数 $1\leq i \leq N$ を用いて $k=\lfloor \frac{n}{i} \rfloor$ と表される各自然数について，Mertens 関数 $M(k)=\sum_{j=1}^k \mu(j)$ を求める
        - vector の組 `(small, large)` を返す．`small[i]` は $M(i)$, `large[i]` は $M(\lfloor \frac{n}{i} \rfloor)$ である．
    - 時間計算量: $O(n^{2/3}(\log\log n)^{1/3})$