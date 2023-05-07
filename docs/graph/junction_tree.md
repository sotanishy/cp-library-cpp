---
title: Junction Tree (Width 2)
documentation_of: ../../graph/junction_tree.hpp
---

## Description

与えられた木の木幅が $2$ 以下か判定し，そうならば木幅 $2$ の木分解を構築する．

空間計算量: $O(V + E)$

## Operations

- `JunctionTreeWidth2(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ の木幅 $2$ の木分解を求める．
    - 時間計算量: $O(E\log V)$
- `bool is_treewidth_2()`
    - 木幅が $2$ 以下か判定する
- `vector<Node> get_nodes()`
    - $G$ の junction tree のノードを返す．`Node` は `bag` メンバと `ch` メンバを持つ． `bag` はそのノードに含まれる $G$ の頂点， `ch` は junction tree におけるそのノードの子である．

## Reference

- [木幅が2以下のグラフの木分解と動的計画法 - ei1333の日記](https://ei1333.hateblo.jp/entry/2020/02/12/150319)
- [離散最適化基礎論 (2016年度後学期) グラフの木分解](http://dopal.cs.uec.ac.jp/okamotoy/lect/2016/treewidth/)