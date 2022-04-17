---
title: Centroid Decomposition
documentation_of: ../../tree/centroid_decomposition.hpp
---

## Description

木の重心とは，木の頂点であって，その頂点を除いてできる森の各連結成分のサイズがもとの木の半分以下になるようなものである．

木の重心による分割を再帰的に行う．木上の分割統治に用いる．

## Operations

- `pair<vector<int>, vector<int>> centroid_decomposition(vector<vector<int>> G)`
  - 木 $G$ の隣接リストが与えられたとき，$G$ を重心分解したときの各頂点のレベル (何回目の分割でそれが重心となるか) と，各頂点が重心となるときにそれが含まれる部分木のサイズを返す
  - 時間計算量: $O(n\log n)$

## Reference

- [ツリーの重心分解 (木の重心分解) の図解 - Qiita](https://qiita.com/drken/items/4b4c3f1824339b090202)
