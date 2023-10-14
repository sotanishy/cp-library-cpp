---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/tree_isomorphism.hpp
    title: Tree Isomorphism
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2821.test.cpp
    title: test/aoj/2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_diameter.cpp\"\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"graph/edge.cpp\"\n\ntemplate <typename\
    \ T>\nstruct Edge {\n    int from, to;\n    T weight;\n    Edge() = default;\n\
    \    Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 6\
    \ \"tree/tree_diameter.cpp\"\n\nstd::pair<int, std::vector<int>> tree_diameter(const\
    \ std::vector<std::vector<int>>& G) {\n    std::vector<int> to(G.size());\n\n\
    \    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<int, int> {\n\
    \        std::pair<int, int> ret(0, v);\n        for (int c : G[v]) {\n      \
    \      if (c == p) continue;\n            auto weight = dfs(dfs, c, v);\n    \
    \        ++weight.first;\n            if (ret < weight) {\n                ret\
    \ = weight;\n                to[v] = c;\n            }\n        }\n        return\
    \ ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(dfs, p.second,\
    \ -1);\n    std::vector<int> path;\n    int v = p.second;\n    while (v != q.second)\
    \ {\n        path.push_back(v);\n        v = to[v];\n    }\n    path.push_back(v);\n\
    \    return {q.first, path};\n}\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>>\
    \ tree_diameter(const std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<int>\
    \ to(G.size());\n\n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T,\
    \ int> {\n        std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n\
    \            if (e.to == p) continue;\n            auto weight = dfs(dfs, e.to,\
    \ v);\n            weight.first += e.weight;\n            if (ret < weight) {\n\
    \                ret = weight;\n                to[v] = e.to;\n            }\n\
    \        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n   \
    \ auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    #include \"../graph/edge.cpp\"\n\nstd::pair<int, std::vector<int>> tree_diameter(const\
    \ std::vector<std::vector<int>>& G) {\n    std::vector<int> to(G.size());\n\n\
    \    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<int, int> {\n\
    \        std::pair<int, int> ret(0, v);\n        for (int c : G[v]) {\n      \
    \      if (c == p) continue;\n            auto weight = dfs(dfs, c, v);\n    \
    \        ++weight.first;\n            if (ret < weight) {\n                ret\
    \ = weight;\n                to[v] = c;\n            }\n        }\n        return\
    \ ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(dfs, p.second,\
    \ -1);\n    std::vector<int> path;\n    int v = p.second;\n    while (v != q.second)\
    \ {\n        path.push_back(v);\n        v = to[v];\n    }\n    path.push_back(v);\n\
    \    return {q.first, path};\n}\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>>\
    \ tree_diameter(const std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<int>\
    \ to(G.size());\n\n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T,\
    \ int> {\n        std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n\
    \            if (e.to == p) continue;\n            auto weight = dfs(dfs, e.to,\
    \ v);\n            weight.first += e.weight;\n            if (ret < weight) {\n\
    \                ret = weight;\n                to[v] = e.to;\n            }\n\
    \        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n   \
    \ auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: tree/tree_diameter.cpp
  requiredBy:
  - tree/tree_isomorphism.hpp
  timestamp: '2021-02-09 14:52:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_A.test.cpp
  - test/aoj/2821.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  - test/yosupo/tree_diameter.test.cpp
documentation_of: tree/tree_diameter.cpp
layout: document
title: Diameter of a Tree
---

## Description

DFSを用いて木の直径を求める．

## Operations

- `pair<int, vector<int>> tree_diameter(vector<vector<int>> G)`
    - $G$ の辺の重みをすべて1として直径の重みとそれに含まれる頂点を返す
    - 時間計算量: $O(n)$
- `pair<T, vector<int>> tree_diameter(vector<vector<Edge<T>>> G)`
    - $G$ の直径の重みとそれに含まれる頂点を返す
    - 時間計算量: $O(n)$

## Reference

- [木の直径を求めるアルゴリズム](https://algo-logic.info/tree-diameter/)