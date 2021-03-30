---
title: Bionnected Components
documentation_of: ../../graph/biconnected_components.cpp
---

## Description

二重頂点連結成分は，どの1頂点を取り除いても連結であるような部分グラフである．つまり，関節点を含まない部分グラフである．

空間計算量: $O(V + E)$

## Operations

- `BionnectedComponents(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ を二重頂点連結成分分解する
    - 時間計算量: $O(V + E)$
- `vector<vector<pair<int, int>>> get_biconnected_components()`
    - $G$ の二重頂点連結成分を返す