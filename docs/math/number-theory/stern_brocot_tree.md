---
title: Stern-Brocot Tree
documentation_of: ../../../math/number-theory/stern_brocot_tree.hpp
---

## Description

Stern-Brocot tree は，有理数の探索に用いられる二分木である．

## Operations

- `pair<pair<long long, long long>, pair<long long, long long>> stern_brocot_tree_search(long long n, F cond)`
    - 分母及び分子が $n$ 以下の既約分数 $p/q$ のうち，条件 $\mathrm{cond}(p/q)$ を満たす最大のもの $a/b$ と満たさない最小のもの $c/d$ を返す． $\mathrm{cond}(p/q)$ の単調性を仮定する．
    - 時間計算量: $O(f(n)\log n)$, $f(n)$ は $\mathrm{cond}(p/q)$ の計算量


## Reference

- [ABC294 F - Sugar Water 2 解説](https://atcoder.jp/contests/abc294/editorial/6017)
- verify: [https://yukicoder.me/submissions/857736](https://yukicoder.me/submissions/857736)