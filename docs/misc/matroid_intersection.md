---
title: Matroid Intersection
documentation_of: ../../misc/matroid_intersection.hpp
---

## Description

共通の台集合 $E$ 上の 2 つのマトロイド $M_1=(E, \mathcal{I}(M_1)),\,M_2=(E, \mathcal{I}(M_2))$ が与えられたとき，$S\in \mathcal{I}(M_1) \cap \mathcal{I}(M_2)$ を満たす $S$ の中で $|S|$ が最大のものを一つ計算する．

## Operations

- `set<int> matroid_intersection(int E, F1 oracle1, F2 oracle2)`
    - $|E|$ と，$M_1,\,M_2$ のオラクルが与えられたとき，$\mathcal{I}(M_1) \cap \mathcal{I}(M_2)$ 中で要素数が最大の集合 $S$ を返す．
    - 時間計算量: $O(R^{1.5}|E|(C_1+C_2)\log R)$, $R$ は $\min(r_{M_1}(E), r_{M_2}(E))$, $C_i$ はオラクル $i$ の計算量

## Note

この実装では，オラクルを呼び出すごとに $S$ 全体を見て独立性を判定しているが，差分だけ更新するような実装ができれば $C_i$ を小さくすることができる．

## Reference

- Lee, Jon. *A First Course in Combinatorial Optimization*. Cambridge: Cambridge University Press, 2010
- [[Tutorial] Matroid intersection in simple words - Codeforces](https://codeforces.com/blog/entry/69287)
- verify: [https://codeforces.com/gym/102156/submission/172034538](https://codeforces.com/gym/102156/submission/172034538)
