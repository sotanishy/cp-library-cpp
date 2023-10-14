---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/range_contour_aggregation.hpp
    title: Range Contour Aggregation
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/centroid_decomposition.hpp\"\n#include <tuple>\n#include\
    \ <vector>\n\nstd::tuple<std::vector<int>, std::vector<int>, std::vector<int>>\
    \ centroid_decomposition(const std::vector<std::vector<int>>& G) {\n    int N\
    \ = G.size();\n    std::vector<int> sz(N), level(N, -1), sz_comp(N), par(N);\n\
    \n    auto dfs_size = [&](auto& dfs_size, int v, int p) -> int {\n        sz[v]\
    \ = 1;\n        for (int c : G[v]) {\n            if (c != p && level[c] == -1)\
    \ sz[v] += dfs_size(dfs_size, c, v);\n        }\n        return sz[v];\n    };\n\
    \n    auto dfs_centroid = [&](auto& dfs_centroid, int v, int p, int n) -> int\
    \ {\n        for (int c : G[v]) {\n            if (c != p && level[c] == -1 &&\
    \ sz[c] > n / 2) return dfs_centroid(dfs_centroid, c, v, n);\n        }\n    \
    \    return v;\n    };\n\n    auto decompose = [&](auto& decompose, int v, int\
    \ k, int p) -> void {\n        int n = dfs_size(dfs_size, v, -1);\n        int\
    \ s = dfs_centroid(dfs_centroid, v, -1, n);\n        level[s] = k;\n        sz_comp[s]\
    \ = n;\n        par[s] = p;\n        for (int c : G[s]) {\n            if (level[c]\
    \ == -1) decompose(decompose, c, k + 1, s);\n        }\n    };\n\n    decompose(decompose,\
    \ 0, 0, -1);\n    return {level, sz_comp, par};\n}\n"
  code: "#pragma once\n#include <tuple>\n#include <vector>\n\nstd::tuple<std::vector<int>,\
    \ std::vector<int>, std::vector<int>> centroid_decomposition(const std::vector<std::vector<int>>&\
    \ G) {\n    int N = G.size();\n    std::vector<int> sz(N), level(N, -1), sz_comp(N),\
    \ par(N);\n\n    auto dfs_size = [&](auto& dfs_size, int v, int p) -> int {\n\
    \        sz[v] = 1;\n        for (int c : G[v]) {\n            if (c != p && level[c]\
    \ == -1) sz[v] += dfs_size(dfs_size, c, v);\n        }\n        return sz[v];\n\
    \    };\n\n    auto dfs_centroid = [&](auto& dfs_centroid, int v, int p, int n)\
    \ -> int {\n        for (int c : G[v]) {\n            if (c != p && level[c] ==\
    \ -1 && sz[c] > n / 2) return dfs_centroid(dfs_centroid, c, v, n);\n        }\n\
    \        return v;\n    };\n\n    auto decompose = [&](auto& decompose, int v,\
    \ int k, int p) -> void {\n        int n = dfs_size(dfs_size, v, -1);\n      \
    \  int s = dfs_centroid(dfs_centroid, v, -1, n);\n        level[s] = k;\n    \
    \    sz_comp[s] = n;\n        par[s] = p;\n        for (int c : G[s]) {\n    \
    \        if (level[c] == -1) decompose(decompose, c, k + 1, s);\n        }\n \
    \   };\n\n    decompose(decompose, 0, 0, -1);\n    return {level, sz_comp, par};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid_decomposition.hpp
  requiredBy:
  - tree/range_contour_aggregation.hpp
  timestamp: '2022-07-02 23:54:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
  - test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
documentation_of: tree/centroid_decomposition.hpp
layout: document
title: Centroid Decomposition
---

## Description

木の重心とは，木の頂点であって，その頂点を除いてできる森の各連結成分のサイズがもとの木の半分以下になるようなものである．

木の重心による分割を再帰的に行う．木上の分割統治に用いる．

## Operations

- `tuple<vector<int>, vector<int>, vector<int>> centroid_decomposition(vector<vector<int>> G)`
  - 木 $G$ の隣接リストが与えられたとき，3つ組 `(level, sz, par)` を返す．
    - `level`: $G$ を重心分解したときの各頂点のレベル (何回目の分割でそれが重心となるか)
    - `sz`: 各頂点が重心となるときにそれが含まれる部分木のサイズ
    - `par`: 各頂点が重心となる直前に属していた部分木の重心
  - 時間計算量: $O(n\log n)$

## Reference

- [ツリーの重心分解 (木の重心分解) の図解 - Qiita](https://qiita.com/drken/items/4b4c3f1824339b090202)
