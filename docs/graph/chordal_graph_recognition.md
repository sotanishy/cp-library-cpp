---
title: Lexicographic BFS
documentation_of: ../../graph/lex_bfs.hpp
---

## Description

Chordal graph は，任意の長さ $4$ 以上のサイクルが弧 (chord) を持つようなグラフである．

Chordal graph である必要十分条件は perfect elimination ordering (PEO) を持つことである．PEO は，頂点の列 $(v_1,v_2,\dots,v_n)$ であって，次の性質を持つものである．
- 各 $i=1,2,\dots,n$ について，$N(v_i) \cap \{v_{i+1},v_{i+2},\dots,v_n\}$ が clique となる (ここで， $N(v)$ は頂点 $v$ の隣接頂点の集合である)

PEO が存在するならば， Lex-BFS の逆順が PEO になっている．

## Operations

- `pair<bool, vector<int>> recognize_chordal_graph(vector<vector<int>> G)`
    - $G$ が chordal graph か判定し，そうならば PEO を，そうでないならば長さ $4$ 以上の induced cycle を一つ返す
    - 時間計算量: $O((n+m)\log n)$

## Reference

- [Chordal Graph: Perfect elimination ordering -kazu0x17’s diary](https://chocobaby-aporo.hatenablog.com/entry/2017/11/04/180325)
- [辞書順幅優先探索Lex BFS（Chordal Graph 5回）- kazu0x17’s diary](https://chocobaby-aporo.hatenablog.com/entry/2018/12/25/011447)