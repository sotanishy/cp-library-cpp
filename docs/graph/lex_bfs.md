---
title: Lexicographic BFS
documentation_of: ../../graph/lex_bfs.hpp
---

## Description

辞書順最小幅優先探索 (Lex-BFS) は，グラフ $G$ の頂点の並べ方 $(v_1,v_2,\dots,v_n)$ であって，以下の性質を持つものである．

- 各 $i=1,2,\dots,n$ について，集合 $S_i$ を $S_i=\{j \mid j \lt i, v_j \in N(v_i) \}$ と定義する (ここで， $N(v)$ は頂点 $v$ の隣接頂点の集合である)．列 $(S_1,S_2,\dots,S_n)$ は辞書順の昇順に並んでいる．

Partition refinement を用いて線形時間で実行できる．

## Operations

- `vector<int> lex_bfs(vector<vector<int>> G)`
    - $G$ の頂点を Lex-BFS 順に並べたリストを返す
    - 時間計算量: $O((n+m)\log n)$

## Note

Partition refinement の実装をサボって log をつけているので，この実装でも時間計算量に log がついている．

Lex-BFS はいくつかのグラフクラスの認識のサブルーチンとして用いられる．
- chordal graph
    - [Chordal Graph Recognition](chordal_graph_recognition.md) を参照
    - 任意の長さ $4$ 以上のサイクルが弧 (chord) を持つグラフ
    - Perfect Elimination Ordering を持つ (参考文献参照)
    - Lex-BFS の逆順が PEO になる
- cograph
    - よくわかっていないが，参考文献 (hos さんのスライド) には色々な応用例が載っている

## Reference

- [辞書順幅優先探索Lex BFS（Chordal Graph 5回）- kazu0x17’s diary](https://chocobaby-aporo.hatenablog.com/entry/2018/12/25/011447)
- [Lexicographic breadth-first search - Wikipedia](https://en.wikipedia.org/wiki/Lexicographic_breadth-first_search)
- [グラフ探索アルゴリズムとその応用](http://hos.ac/slides/20110504_graph.pdf)