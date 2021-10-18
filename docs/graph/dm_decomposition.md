---
title: Dulmage-Mendelsohn Decomposition
documentation_of: ../../graph/dm_decomposition.cpp
---

## Description

Dulmage-Mendelsohn 分解 (DM分解) は，与えられた二部グラフの最大マッチングに関する性質による頂点の分類である．

この実装では，二部グラフ $G$ の頂点を3つの集合 $U, O, E$ に分類する．この分類は以下の性質を持つ:
- $U, O, E$ は pairwise disjoint である
- $G$ の任意の最大マッチングは $U-U$ 辺と $E-O$ 辺からなる
- $G$ の任意の最大マッチングにおいて，$U, O$ に属する頂点はすべてマッチされる
- $G$ の最大マッチングの大きさは $|O| + |U|/2$ である

DM 分解は疎行列のブロック対角化に用いられるらしい．行列を行と列の二部グラフとみなし，非零要素のところに辺を張って DM 分解をすると，ブロック対角化ができる (このとき，$U$を更に細かく分類することでブロックを小さくする)．大規模な線形連立方程式を小さな部分問題に分解できて嬉しいらしいが，競プロで使いどころがあるかは知らない．

- `vector<int> dm_decomposition(vector<vector<int>> G)`
    - 二部グラフ $G$ を DM 分解する．0は$E$, 1は$O$, -1は$U$に属することを意味する
    - 時間計算量: $O(VE)$


## Reference

- [Dulmage Mendelsohn Decomposition](http://www.cse.iitm.ac.in/~meghana/matchings/bip-decomp.pdf)
- [Dulmage–Mendelsohn分解 (DM分解)](http://misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf)