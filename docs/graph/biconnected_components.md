---
title: Biconnected Components
documentation_of: ../../graph/biconnected_components.hpp
---

## Description

二重頂点連結成分は，どの1頂点を取り除いても連結であるような部分グラフである．つまり，関節点を含まない部分グラフである．

関節点と二重頂点連結成分を結んで構成した木は block cut tree と呼ばれる．

空間計算量: $O(V + E)$

## Operations

- `vector<vector<int>> biconnected_components(vector<vector<int>> G, Lowlink low)`
    - グラフ $G$ の隣接リストと，$G$ の lowlink 構造体が与えられたとき，$G$ を二重頂点連結成分分解する．$G$ の二重頂点連結成分を返す
    - 時間計算量: $O(V + E)$
- `vector<vector<int>> block_cut_tree(vector<vector<int>> blocks, vector<int> cuts)`
    - ブロック（二重頂点連結成分）とカット（関節点）のリストが与えられたときに，対応する block cut tree の隣接リストを返す
    - 時間計算量: $O(B + C)$
