---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_triangles.test.cpp
    title: test/yosupo/enumerate_triangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/enumerate_triangles.cpp\"\n#include <vector>\n\nstd::vector<std::tuple<int,\
    \ int, int>> enumerate_triangles(const std::vector<std::vector<int>>& G) {\n \
    \   int n = G.size();\n    std::vector<int> deg(n);\n    for (int i = 0; i < n;\
    \ ++i) deg[i] = G[i].size();\n    std::vector<std::vector<int>> G2(n);\n    std::vector<std::pair<int,\
    \ int>> edges;\n    for (int i = 0; i < n; ++i) {\n        for (int j : G[i])\
    \ {\n            if (std::make_pair(deg[i], i) < std::make_pair(deg[j], j)) {\n\
    \                G2[i].push_back(j);\n                edges.push_back({i, j});\n\
    \            }\n        }\n    }\n    std::vector<std::tuple<int, int, int>> ret;\n\
    \    std::vector<bool> used(n);\n    for (auto& [a, b] : edges) {\n        for\
    \ (int c : G2[a]) used[c] = true;\n        for (int c : G2[b]) {\n           \
    \ if (used[c]) {\n                ret.push_back({a, b, c});\n            }\n \
    \       }\n        for (int c : G2[a]) used[c] = false;\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\nstd::vector<std::tuple<int, int, int>>\
    \ enumerate_triangles(const std::vector<std::vector<int>>& G) {\n    int n = G.size();\n\
    \    std::vector<int> deg(n);\n    for (int i = 0; i < n; ++i) deg[i] = G[i].size();\n\
    \    std::vector<std::vector<int>> G2(n);\n    std::vector<std::pair<int, int>>\
    \ edges;\n    for (int i = 0; i < n; ++i) {\n        for (int j : G[i]) {\n  \
    \          if (std::make_pair(deg[i], i) < std::make_pair(deg[j], j)) {\n    \
    \            G2[i].push_back(j);\n                edges.push_back({i, j});\n \
    \           }\n        }\n    }\n    std::vector<std::tuple<int, int, int>> ret;\n\
    \    std::vector<bool> used(n);\n    for (auto& [a, b] : edges) {\n        for\
    \ (int c : G2[a]) used[c] = true;\n        for (int c : G2[b]) {\n           \
    \ if (used[c]) {\n                ret.push_back({a, b, c});\n            }\n \
    \       }\n        for (int c : G2[a]) used[c] = false;\n    }\n    return ret;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/enumerate_triangles.cpp
  requiredBy: []
  timestamp: '2022-03-20 23:18:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_triangles.test.cpp
documentation_of: graph/enumerate_triangles.cpp
layout: document
title: Enumerate Triangles
---

## Description

無向グラフの三角形を全列挙する．

## Operations

- `vector<tuple<int, int, int>> enumerate_triangles(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ の三角形を全列挙する．
    - 時間計算量: $O(E\sqrt{E})$

## Reference

- [Enumerate Triangles(三角形全列挙)](https://ei1333.github.io/library/graph/others/enumerate-triangles.hpp.html)