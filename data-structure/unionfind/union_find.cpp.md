---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_edge_coloring.hpp
    title: Bipartite Edge Coloring
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_arborescence.cpp
    title: Minimum Spanning Arborescence
  - icon: ':heavy_check_mark:'
    path: graph/mst.cpp
    title: Minimum Spanning Tree Algorithms
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.boruvka.test.cpp
    title: test/aoj/GRL_2_A.boruvka.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.prim.test.cpp
    title: test/aoj/GRL_2_A.prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartite_edge_coloring.test.cpp
    title: test/yosupo/bipartite_edge_coloring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/union_find.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nclass UnionFind {\npublic:\n    UnionFind() = default;\n\
    \    explicit UnionFind(int n) : data(n, -1) {}\n\n    int find(int x) {\n   \
    \     if (data[x] < 0) return x;\n        return data[x] = find(data[x]);\n  \
    \  }\n\n    void unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if (x == y) return;\n        if (data[x] > data[y]) std::swap(x, y);\n\
    \        data[x] += data[y];\n        data[y] = x;\n    }\n\n    bool same(int\
    \ x, int y) {\n        return find(x) == find(y);\n    }\n\n    int size(int x)\
    \ {\n        return -data[find(x)];\n    }\n\nprivate:\n    std::vector<int> data;\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nclass UnionFind\
    \ {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int n) : data(n,\
    \ -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return x;\n      \
    \  return data[x] = find(data[x]);\n    }\n\n    void unite(int x, int y) {\n\
    \        x = find(x);\n        y = find(y);\n        if (x == y) return;\n   \
    \     if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n \
    \       data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind/union_find.cpp
  requiredBy:
  - graph/mst.cpp
  - graph/bipartite_edge_coloring.hpp
  - graph/minimum_spanning_arborescence.cpp
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.boruvka.test.cpp
  - test/aoj/GRL_2_A.prim.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/aoj/DSL_1_A.test.cpp
  - test/yosupo/bipartite_edge_coloring.test.cpp
  - test/yosupo/unionfind.test.cpp
  - test/yosupo/directedmst.test.cpp
documentation_of: data-structure/unionfind/union_find.cpp
layout: document
title: Union Find
---

## Description

Union find (disjoint set union, 素集合データ構造) は，素集合を管理するデータ構造である．

空間計算量: $O(n)$

## Operations

- `UnionFind(int n)`
    - サイズ`n`の union find を構築する．
    - 時間計算量: $O(n)$
- `int find(int x)`
    - $x$ が属する木の根を返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(int x, int y)`
    - $x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `int size(int x)`
    - $x$ が属する集合の大きさを返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ は逆アッカーマン関数である．

この実装では高速化に path compression と union by size を用いている．どちらか一方だと計算量は $O(\log n)$ になるが，両方使用することで $O(\alpha(n))$ になる．path compression の代わりに path splitting や path halving，union by size の代わりに union by rank といった実装手法もあり，どれも同じ計算量を実現する．

## Reference

- [Disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
- [UnionFindTree に関する知見の諸々](https://noshi91.hatenablog.com/entry/2018/05/30/191943)
- [Union Find の計算量の話](https://qiita.com/kopricky/items/3e5847ab1451fe990367)
- [データ構造をマージする一般的なテク](https://wiki.kimiyuki.net/%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0%E3%82%92%E3%83%9E%E3%83%BC%E3%82%B8%E3%81%99%E3%82%8B%E4%B8%80%E8%88%AC%E7%9A%84%E3%81%AA%E3%83%86%E3%82%AF)
- [Disjoint Set Union](https://cp-algorithms.com/data_structures/disjoint_set_union.html#arpa)