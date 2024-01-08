---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: sat/twosat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':x:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/scc.hpp\"\n#include <algorithm>\n#include <ranges>\n\
    #include <vector>\n\nstd::vector<int> scc(const std::vector<std::vector<int>>&\
    \ G) {\n    const int n = G.size();\n    std::vector<std::vector<int>> G_rev(n);\n\
    \    for (int u = 0; u < n; ++u) {\n        for (int v : G[u]) G_rev[v].push_back(u);\n\
    \    }\n    std::vector<int> comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\
    \n    auto dfs = [&](const auto& dfs, int u) -> void {\n        if (visited[u])\
    \ return;\n        visited[u] = true;\n        for (int v : G[u]) dfs(dfs, v);\n\
    \        order.push_back(u);\n    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs,\
    \ v);\n    int c = 0;\n\n    auto rdfs = [&](const auto& rdfs, int u, int c) ->\
    \ void {\n        if (comp[u] != -1) return;\n        comp[u] = c;\n        for\
    \ (int v : G_rev[u]) rdfs(rdfs, v, c);\n    };\n\n    for (int v : order | std::views::reverse)\
    \ {\n        if (comp[v] == -1) rdfs(rdfs, v, c++);\n    }\n    return comp;\n\
    }\n\nstd::vector<std::vector<int>> contract(const std::vector<std::vector<int>>&\
    \ G,\n                                       const std::vector<int>& comp) {\n\
    \    const int n = *std::ranges::max_element(comp) + 1;\n    std::vector<std::vector<int>>\
    \ G2(n);\n    for (int i = 0; i < (int)G.size(); ++i) {\n        for (int j :\
    \ G[i]) {\n            if (comp[i] != comp[j]) {\n                G2[comp[i]].push_back(comp[j]);\n\
    \            }\n        }\n    }\n    for (int i = 0; i < n; ++i) {\n        std::ranges::sort(G2[i]);\n\
    \        G2[i].erase(std::ranges::unique(G2[i]).begin(), G2[i].end());\n    }\n\
    \    return G2;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <ranges>\n#include <vector>\n\
    \nstd::vector<int> scc(const std::vector<std::vector<int>>& G) {\n    const int\
    \ n = G.size();\n    std::vector<std::vector<int>> G_rev(n);\n    for (int u =\
    \ 0; u < n; ++u) {\n        for (int v : G[u]) G_rev[v].push_back(u);\n    }\n\
    \    std::vector<int> comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\
    \n    auto dfs = [&](const auto& dfs, int u) -> void {\n        if (visited[u])\
    \ return;\n        visited[u] = true;\n        for (int v : G[u]) dfs(dfs, v);\n\
    \        order.push_back(u);\n    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs,\
    \ v);\n    int c = 0;\n\n    auto rdfs = [&](const auto& rdfs, int u, int c) ->\
    \ void {\n        if (comp[u] != -1) return;\n        comp[u] = c;\n        for\
    \ (int v : G_rev[u]) rdfs(rdfs, v, c);\n    };\n\n    for (int v : order | std::views::reverse)\
    \ {\n        if (comp[v] == -1) rdfs(rdfs, v, c++);\n    }\n    return comp;\n\
    }\n\nstd::vector<std::vector<int>> contract(const std::vector<std::vector<int>>&\
    \ G,\n                                       const std::vector<int>& comp) {\n\
    \    const int n = *std::ranges::max_element(comp) + 1;\n    std::vector<std::vector<int>>\
    \ G2(n);\n    for (int i = 0; i < (int)G.size(); ++i) {\n        for (int j :\
    \ G[i]) {\n            if (comp[i] != comp[j]) {\n                G2[comp[i]].push_back(comp[j]);\n\
    \            }\n        }\n    }\n    for (int i = 0; i < n; ++i) {\n        std::ranges::sort(G2[i]);\n\
    \        G2[i].erase(std::ranges::unique(G2[i]).begin(), G2[i].end());\n    }\n\
    \    return G2;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy:
  - sat/twosat.hpp
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/scc.test.cpp
  - test/yosupo/two_sat.test.cpp
documentation_of: graph/scc.hpp
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