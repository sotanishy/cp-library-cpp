---
title: Euler's Totient Function
documentation_of: ../../math/euler_totient.cpp
---

## Description

Euler の totient 関数 $\varphi(n)$ は，$n$ 以下の自然数のうち $n$ と互いに素であるものの個数である．

## Operations

- `long long euler_totient(long long n)`
    - $\varphi(n)$ を求める
    - 時間計算量: $O(\sqrt{n})$
- `vector<int> euler_totient_table(int n)`
    - $n$ 以下の正整数 $i$ について $\varphi(i)$ を求める
    - 時間計算量: $O(n \log\log n)$
- `pair<vector<mint>, vector<mint>> totient_summatory_table(long long n)`
    - 自然数 $1\leq i \leq N$ を用いて $k=\lfloor \frac{n}{i} \rfloor$ と表される各自然数について，$\Phi(k)=\sum_{j=1}^k \varphi(j)$ を求める
        - vector の組 `(small, large)` を返す．`small[i]` は $\Phi(i)$, `large[i]` は $\Phi(\lfloor \frac{n}{i} \rfloor)$ である．
    - 時間計算量: $O(n^{2/3}(\log\log n)^{1/3})$

## Reference

- [トーティエント関数 $\varphi(i)$ の和 $\sum_{i=1}^N \varphi(i)$ を $O(N^{2/3})$
で求める - yukicoder wiki](https://yukicoder.me/wiki/sum_totient)