---
title: Dulmage-Mendelsohn Decomposition
documentation_of: ../../graph/dm_decomposition.hpp
---

## Description

Dulmage-Mendelsohn 分解 (DM分解) は，与えられた二部グラフの最大マッチングに関する性質による頂点の分類である．

この実装では，二部グラフ $G$ の頂点を3つの集合 $U, O, E$ に分類する．この分類は以下の性質を持つ:
- $U, O, E$ は pairwise disjoint である
- $G$ の任意の最大マッチングは $U-U$ 辺と $E-O$ 辺からなる
- $G$ の任意の最大マッチングにおいて，$U, O$ に属する頂点はすべてマッチされる
- $G$ の最大マッチングの大きさは $\vert O\vert + \vert U\vert/2$ である

DM 分解は疎行列のブロック対角化に用いられるらしい．行列を行と列の二部グラフとみなし，非零要素のところに辺を張って DM 分解をすると，ブロック対角化ができる (このとき，$U$を更に細かく分類することでブロックを小さくする)．大規模な線形連立方程式を小さな部分問題に分解できて嬉しいらしいが，競プロで使いどころがあるかは知らない．

## Operations

- `vector<int> dm_decomposition(int X, int Y, vector<pair<int, int>> edges)`
    - 二部グラフ $G$ (頂点数 $X$, $Y$，辺は `edges` ) を DM 分解する．返り値は，$0,\dots,X-1$ 番目は $X$ の頂点，$X,\dots,X+Y-1$ 番目は $Y$ の頂点が属する集合を表す．0は$E$, 1は$O$, -1は$U$に属することを意味する
    - 時間計算量: $O(E\sqrt{X + Y})$


## Reference

- [Dulmage Mendelsohn Decomposition](http://www.cse.iitm.ac.in/~meghana/matchings/bip-decomp.pdf)
- [Dulmage–Mendelsohn分解 (DM分解)](http://misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf)
- verify: [https://atcoder.jp/contests/abc223/submissions/26666610](https://atcoder.jp/contests/abc223/submissions/26666610)