---
title: Triangle Enumeration
documentation_of: ../../graph/enumerate_triangles.hpp
---

## Description

無向グラフの三角形を全列挙する．

## Operations

- `vector<tuple<int, int, int>> enumerate_triangles(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ の三角形を全列挙する．
    - 時間計算量: $O(E\sqrt{E})$

## Reference

- [Enumerate Triangles(三角形全列挙)](https://ei1333.github.io/library/graph/others/enumerate-triangles.hpp.html)