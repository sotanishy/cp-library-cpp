---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/tree_isomorphism.hpp
    title: Tree Isomorphism
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_diameter.hpp\"\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\n\nstd::pair<int, std::vector<int>> tree_diameter(\n\
    \    const std::vector<std::vector<int>>& G) {\n    std::vector<int> to(G.size());\n\
    \n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<int, int> {\n\
    \        std::pair<int, int> ret(0, v);\n        for (int c : G[v]) {\n      \
    \      if (c == p) continue;\n            auto weight = dfs(dfs, c, v);\n    \
    \        ++weight.first;\n            if (ret < weight) {\n                ret\
    \ = weight;\n                to[v] = c;\n            }\n        }\n        return\
    \ ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(dfs, p.second,\
    \ -1);\n    std::vector<int> path;\n    int v = p.second;\n    while (v != q.second)\
    \ {\n        path.push_back(v);\n        v = to[v];\n    }\n    path.push_back(v);\n\
    \    return {q.first, path};\n}\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>>\
    \ tree_diameter(\n    const std::vector<std::vector<std::pair<int, T>>>& G) {\n\
    \    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs, int\
    \ v, int p) -> std::pair<T, int> {\n        std::pair<T, int> ret(0, v);\n   \
    \     for (auto& [u, w] : G[v]) {\n            if (u == p) continue;\n       \
    \     auto weight = dfs(dfs, u, v);\n            weight.first += w;\n        \
    \    if (ret < weight) {\n                ret = weight;\n                to[v]\
    \ = u;\n            }\n        }\n        return ret;\n    };\n\n    auto p =\
    \ dfs(dfs, 0, -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int>\
    \ path;\n    int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \nstd::pair<int, std::vector<int>> tree_diameter(\n    const std::vector<std::vector<int>>&\
    \ G) {\n    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs,\
    \ int v, int p) -> std::pair<int, int> {\n        std::pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto weight = dfs(dfs, c, v);\n            ++weight.first;\n            if (ret\
    \ < weight) {\n                ret = weight;\n                to[v] = c;\n   \
    \         }\n        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0,\
    \ -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n   \
    \ int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>> tree_diameter(\n  \
    \  const std::vector<std::vector<std::pair<int, T>>>& G) {\n    std::vector<int>\
    \ to(G.size());\n\n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T,\
    \ int> {\n        std::pair<T, int> ret(0, v);\n        for (auto& [u, w] : G[v])\
    \ {\n            if (u == p) continue;\n            auto weight = dfs(dfs, u,\
    \ v);\n            weight.first += w;\n            if (ret < weight) {\n     \
    \           ret = weight;\n                to[v] = u;\n            }\n       \
    \ }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto q\
    \ = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree/tree_diameter.hpp
  requiredBy:
  - tree/tree_isomorphism.hpp
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  - test/yosupo/tree_diameter.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
documentation_of: tree/tree_diameter.hpp
layout: document
title: Diameter of a Tree
---

## Description

DFSを用いて木の直径を求める．

## Operations

- `pair<int, vector<int>> tree_diameter(vector<vector<int>> G)`
    - $G$ の辺の重みをすべて1として直径の重みとそれに含まれる頂点を返す
    - 時間計算量: $O(n)$
- `pair<T, vector<int>> tree_diameter(vector<vector<pair<int, T>>> G)`
    - $G$ の直径の重みとそれに含まれる頂点を返す
    - 時間計算量: $O(n)$

## Reference

- [木の直径を求めるアルゴリズム](https://algo-logic.info/tree-diameter/)