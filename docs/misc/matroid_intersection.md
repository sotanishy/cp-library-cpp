---
title: Matroid Intersection
documentation_of: ../../misc/matroid_intersection.hpp
---

## Description

共通の台集合 $E$ 上の 2 つのマトロイド $M_1=(E, \mathcal{I}(M_1)),\,M_2=(E, \mathcal{I}(M_2))$ が与えられたとき，$S\in \mathcal{I}(M_1) \cap \mathcal{I}(M_2)$ を満たす $S$ の中で $\vert S\vert$ が最大のものを一つ計算する．

各 $k=1,2,\dots$ について $|S|=k$ の実行可能集合を保ちながら，bipartite augmentation graph 上での augmenting path に沿って augment を繰り返すアルゴリズムを用いている．

## Operations

- `set<int> matroid_intersection(int E, F1 oracle1, F2 oracle2)`
    - $\vert E\vert$ と，$M_1,\,M_2$ のオラクルが与えられたとき，$\mathcal{I}(M_1) \cap \mathcal{I}(M_2)$ 中で要素数が最大の集合 $S$ を返す．
    - 時間計算量: $O(R^{1.5}\vert E\vert(C_1+C_2)\log R)$, $R$ は $\min(r_{M_1}(E), r_{M_2}(E))$, $C_i$ はオラクル $i$ の計算量

## Note

- この実装では，オラクルを呼び出すごとに $S$ 全体を見て独立性を判定しているが，差分だけ更新するような実装ができれば $C_i$ を小さくすることができる．
- この実装では重みなしのマトロイド交差を解く．重みがある場合は，最短路の代わりに「最大重みの source-sink パスの中で最短のもの」を用いて augment すればよい．
- 基本的には，問題のマトロイドの構造に特化したアルゴリズムを用いるほうが高速なことが多い．

## Reference

- Lee, Jon. *A First Course in Combinatorial Optimization*. Cambridge: Cambridge University Press, 2010
- [[Tutorial] Matroid intersection in simple words - Codeforces](https://codeforces.com/blog/entry/69287)
- [ICPC国内予選F解説 - slideshare](https://www.slideshare.net/tmaehara/icpcf)
- verify: [https://codeforces.com/gym/102156/submission/172034538](https://codeforces.com/gym/102156/submission/172034538)
