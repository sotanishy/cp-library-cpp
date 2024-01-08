---
title: Dominator Tree
documentation_of: ../../graph/dominator_tree.hpp
---

## Description

有向グラフ $G$ において，頂点 $v$ が頂点 $w$ の dominator であるとは，$G$ における任意の $s-w$ パス ($s$ は source vertex) が $v$ を通ることである．

$v$ が $w$ の immediate dominator であるとは，$v$ が $w$ の dominator であり，かつ $v$ が $w$ の任意の dominator $u$ を dominate しないことである．これは $w$ に対して一意に定まる．

$G$ の dominator tree は，$G$ で $v$ が $w$ の immediate dominator であるときかつそのときに限り有向辺 $(v, w)$ が存在するような有向木である．

## Operations

- `vector<int> dominator_tree(vector<vector<int>> G, int s)`
    - グラフ $G$ の隣接リストと source vertex $s$ が与えられたとき，各頂点 $v$ の immediate dominator を返す．$v$ が $s$ なら到達できない場合 `-1` を返す．$s$ の immediate dominator は $s$ とする．
    - 時間計算量: $O((V + E) \log V)$

## Reference

- [Dominator Tree of a Directed Graph](https://tanujkhattar.wordpress.com/2016/01/11/dominator-tree-of-a-directed-graph/)
- [Dominator Tree](https://sigma425.hatenablog.com/entry/2015/12/25/224053)