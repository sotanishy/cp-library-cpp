---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/twosat.cpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/scc.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \nstd::vector<int> scc(const std::vector<std::vector<int>>& G) {\n    const int\
    \ n = G.size();\n    std::vector<std::vector<int>> G_rev(n);\n    for (int u =\
    \ 0; u < n; ++u) {\n        for (int v : G[u]) G_rev[v].push_back(u);\n    }\n\
    \    std::vector<int> comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\
    \n    auto dfs = [&](const auto& self, int u) -> void {\n        if (visited[u])\
    \ return;\n        visited[u] = true;\n        for (int v : G[u]) self(self, v);\n\
    \        order.push_back(u);\n    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs,\
    \ v);\n    std::reverse(order.begin(), order.end());\n    int c = 0;\n\n    auto\
    \ rdfs = [&](const auto& self, int u, int c) -> void {\n        if (comp[u] !=\
    \ -1) return;\n        comp[u] = c;\n        for (int v : G_rev[u]) self(self,\
    \ v, c);\n    };\n\n    for (int v : order) if (comp[v] == -1) rdfs(rdfs, v, c++);\n\
    \    return comp;\n}\n\nstd::vector<std::vector<int>> contract(const std::vector<std::vector<int>>&\
    \ G, const std::vector<int>& comp) {\n    const int n = *max_element(comp.begin(),\
    \ comp.end()) + 1;\n    std::vector<std::vector<int>> G2(n);\n    for (int i =\
    \ 0; i < (int) G.size(); ++i) {\n        for (int j : G[i]) {\n            if\
    \ (comp[i] != comp[j]) {\n                G2[comp[i]].push_back(comp[j]);\n  \
    \          }\n        }\n    }\n    for (int i = 0; i < n; ++i) {\n        std::sort(G2[i].begin(),\
    \ G2[i].end());\n        G2[i].erase(std::unique(G2[i].begin(), G2[i].end()),\
    \ G2[i].end());\n    }\n    return G2;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nstd::vector<int>\
    \ scc(const std::vector<std::vector<int>>& G) {\n    const int n = G.size();\n\
    \    std::vector<std::vector<int>> G_rev(n);\n    for (int u = 0; u < n; ++u)\
    \ {\n        for (int v : G[u]) G_rev[v].push_back(u);\n    }\n    std::vector<int>\
    \ comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\n    auto dfs =\
    \ [&](const auto& self, int u) -> void {\n        if (visited[u]) return;\n  \
    \      visited[u] = true;\n        for (int v : G[u]) self(self, v);\n       \
    \ order.push_back(u);\n    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs, v);\n\
    \    std::reverse(order.begin(), order.end());\n    int c = 0;\n\n    auto rdfs\
    \ = [&](const auto& self, int u, int c) -> void {\n        if (comp[u] != -1)\
    \ return;\n        comp[u] = c;\n        for (int v : G_rev[u]) self(self, v,\
    \ c);\n    };\n\n    for (int v : order) if (comp[v] == -1) rdfs(rdfs, v, c++);\n\
    \    return comp;\n}\n\nstd::vector<std::vector<int>> contract(const std::vector<std::vector<int>>&\
    \ G, const std::vector<int>& comp) {\n    const int n = *max_element(comp.begin(),\
    \ comp.end()) + 1;\n    std::vector<std::vector<int>> G2(n);\n    for (int i =\
    \ 0; i < (int) G.size(); ++i) {\n        for (int j : G[i]) {\n            if\
    \ (comp[i] != comp[j]) {\n                G2[comp[i]].push_back(comp[j]);\n  \
    \          }\n        }\n    }\n    for (int i = 0; i < n; ++i) {\n        std::sort(G2[i].begin(),\
    \ G2[i].end());\n        G2[i].erase(std::unique(G2[i].begin(), G2[i].end()),\
    \ G2[i].end());\n    }\n    return G2;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.cpp
  requiredBy:
  - graph/twosat.cpp
  timestamp: '2021-10-07 13:18:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
  - test/aoj/GRL_3_C.test.cpp
documentation_of: graph/scc.cpp
layout: document
title: Strongly Connected Components
---

## Description

グラフ $G$ の強連結成分分解をする．

この実装では Kosaraju のアルゴリズムを用いている．

強連結成分を一つの頂点に縮約すると，有向非巡回グラフ (DAG) が得られる．

強連結成分のラベルはトポロジカル順序になっている．

## Operations

- `vector<int> scc(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ を強連結成分分解し，各頂点が属する成分のラベルを返す
    - 時間計算量: $O(V + E)$
- `vector<vector<int>> contract(vector<vector<int>> G, vector<int> comp)`
    - グラフ $G$ の隣接リストとその強連結成分が与えられたとき，各強連結成分を縮約したグラフを返す
    - 時間計算量: $O(V + E)$