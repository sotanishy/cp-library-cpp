---
title: Euler's Totient Function
documentation_of: ../../math/euler_totient.cpp
---

## Description

Euler の totient 関数 $\phi(n)$ の値を求める．これは $n$ 以下の自然数のうち $n$ と互いに素であるものの個数である．

## Operations

- `long long euler_totient(long long n)`
    - $\phi(n)$ を求める
    - 時間計算量: $O(\sqrt{n})$
- `vector<int> euler_totient(int n)`
    - $n$ 以下の正整数 $i$ について $\phi(i)$ を求める
    - 時間計算量: $O(n \log\log n)$