---
title: Discrete Logarithm of Monoid Action
documentation_of: ../../math/discrete_log_monoid_action.hpp
---

## Description

モノイド作用に関する離散対数問題を解く．すなわち，モノイド $M$ が集合 $S$ に作用しているとき，$x \in X, s,t\in S$ と正整数 $N$ に対して $x^n s = t$ かつ $0 \leq n \lt N$ となる $n$ が存在するか判定し，あればそのうち最小のものを求める．

## Operations

- `int discrete_log_monoid_action(T x, S s, S t, long long N)`
    - $x^n s=t$ かつ $0 \leq n \lt N$ となる $n$ が存在すればそのうち最小のものを，存在しなければ $-1$ を返す
    - 時間計算量: $\mathrm{expected}\,O(\sqrt{N})$

## Note

集合 `S` は `std::hash` を実装している必要がある．

## Reference

- [モノイド作用に関する離散対数問題](https://maspypy.com/%e3%83%a2%e3%83%8e%e3%82%a4%e3%83%89%e4%bd%9c%e7%94%a8%e3%81%ab%e9%96%a2%e3%81%99%e3%82%8b%e9%9b%a2%e6%95%a3%e5%af%be%e6%95%b0%e5%95%8f%e9%a1%8c)
- verify: [https://atcoder.jp/contests/abc270/submissions/40150377](https://atcoder.jp/contests/abc270/submissions/40150377)
