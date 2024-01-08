---
title: Biconnected Components
documentation_of: ../../graph/biconnected_components.hpp
---

## Description

二重頂点連結成分は，どの1頂点を取り除いても連結であるような部分グラフである．つまり，関節点を含まない部分グラフである．

関節点と二重頂点連結成分を結んで構成した木は block cut tree と呼ばれる．

空間計算量: $O(V + E)$

## Operations

- `vector<vector<pair<int, int>>> biconnected_components(vector<vector<int>> G, Lowlink low)`
    - グラフ $G$ の隣接リストと，$G$ の lowlink 構造体が与えられたとき，$G$ を二重頂点連結成分分解する
    - $G$ の二重頂点連結成分を返す
    - 時間計算量: $O(V + E)$

## Note

多重辺は予め取り除いておく必要がある (多重辺を取り除いても二重頂点連結成分は変化しない)．

また，孤立点にも注意する (孤立点はそれで一つの二重頂点連結成分となるが，この関数は辺を返すため，孤立点からなる成分は含まれない)．