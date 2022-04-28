---
title: Polynomial
documentation_of: ../../math/polynomial.cpp
---

## Description

係数が`Modint`または`ArbitraryModint`である多項式を扱う．

空間計算量: $O(n)$

## Operations

- `Polynomial inv(int deg)`
    - $\frac{1}{f(x)}$ を $deg - 1$ 次の項まで計算する
    - 時間計算量: $O(n \log n)$
- `Polynomial exp(int deg)`
    - $\exp(f(x))$ を $deg - 1$ 次の項まで計算する
    - 時間計算量: $O(n \log n)$
- `Polynomial log(int deg)`
    - $\log(f(x))$ を $deg - 1$ 次の項まで計算する
    - 時間計算量: $O(n \log n)$
- `Polynomial pow(long long k, int deg)`
    - $(f(x))^k$ を $deg - 1$ 次の項まで計算する
    - 時間計算量: $O(n \log n)$
- `Polynomial diff()`
    - $f'(x)$ を計算する
    - 時間計算量: $O(n)$
- `Polynomial integral()`
    - $\int f(x)$ を計算する
    - 時間計算量: $O(n)$
- `Polynomial taylor_shift(long long c)`
    - $f(x+c)$ を計算する
    - 時間計算量: $O(n \log n)$

## Reference

- [【競技プログラミング】形式的冪級数の応用テクニック(前編) - Qiita](https://qiita.com/hotman78/items/f0e6d2265badd84d429a)

