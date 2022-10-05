---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/lowlink.cpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/two_edge_connected_components.cpp\"\n#include <vector>\n\
    #line 2 \"graph/lowlink.cpp\"\n#include <algorithm>\n#include <utility>\n#line\
    \ 5 \"graph/lowlink.cpp\"\n\nclass Lowlink {\npublic:\n    std::vector<int> ord,\
    \ low;\n    std::vector<std::pair<int, int>> bridge;\n    std::vector<int> articulation;\n\
    \n    Lowlink() = default;\n    explicit Lowlink(const std::vector<std::vector<int>>&\
    \ G) : ord(G.size(), -1), low(G.size()), G(G) {\n        for (int i = 0; i < (int)\
    \ G.size(); ++i) {\n            if (ord[i] == -1) dfs(i, -1);\n        }\n   \
    \ }\n\n    bool is_bridge(int u, int v) const {\n        if (ord[u] > ord[v])\
    \ std::swap(u, v);\n        return ord[u] < low[v];\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    int k = 0;\n\n    void dfs(int v, int p) {\n        ord[v] = k++;\n\
    \        low[v] = ord[v];\n        bool is_articulation = false, checked = false;\n\
    \        int cnt = 0;\n        for (int c : G[v]) {\n            if (c == p &&\
    \ !checked) {\n                checked = true;\n                continue;\n  \
    \          }\n            if (ord[c] == -1) {\n                ++cnt;\n      \
    \          dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n  \
    \              if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n    \
    \            if (ord[v] < low[c]) bridge.push_back(std::minmax(v, c));\n     \
    \       } else {\n                low[v] = std::min(low[v], ord[c]);\n       \
    \     }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 4 \"\
    graph/two_edge_connected_components.cpp\"\n\nstd::vector<int> two_edge_connected_components(const\
    \ std::vector<std::vector<int>>& G, const Lowlink& low) {\n    int k = 0;\n  \
    \  std::vector<int> comp(G.size(), -1);\n\n    auto dfs = [&](const auto& dfs,\
    \ int u) -> void {\n        comp[u] = k;\n        for (int v : G[u]) {\n     \
    \       if (comp[v] == -1 && !low.is_bridge(u, v)) dfs(dfs, v);\n        }\n \
    \   };\n\n    for (int v = 0; v < (int) G.size(); ++v) {\n        if (comp[v]\
    \ == -1) {\n            dfs(dfs, v);\n            ++k;\n        }\n    }\n   \
    \ return comp;\n}\n\nstd::vector<std::vector<int>> contract(const std::vector<std::vector<int>>&\
    \ G, const std::vector<int>& comp) {\n    const int n = *max_element(comp.begin(),\
    \ comp.end()) + 1;\n    std::vector<std::vector<int>> G2(n);\n    for (int i =\
    \ 0; i < (int) G.size(); ++i) {\n        for (int j : G[i]) {\n            if\
    \ (comp[i] != comp[j]) {\n                G2[comp[i]].push_back(comp[j]);\n  \
    \          }\n        }\n    }\n    for (int i = 0; i < n; ++i) {\n        std::sort(G2[i].begin(),\
    \ G2[i].end());\n        G2[i].erase(std::unique(G2[i].begin(), G2[i].end()),\
    \ G2[i].end());\n    }\n    return G2;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"lowlink.cpp\"\n\nstd::vector<int>\
    \ two_edge_connected_components(const std::vector<std::vector<int>>& G, const\
    \ Lowlink& low) {\n    int k = 0;\n    std::vector<int> comp(G.size(), -1);\n\n\
    \    auto dfs = [&](const auto& dfs, int u) -> void {\n        comp[u] = k;\n\
    \        for (int v : G[u]) {\n            if (comp[v] == -1 && !low.is_bridge(u,\
    \ v)) dfs(dfs, v);\n        }\n    };\n\n    for (int v = 0; v < (int) G.size();\
    \ ++v) {\n        if (comp[v] == -1) {\n            dfs(dfs, v);\n           \
    \ ++k;\n        }\n    }\n    return comp;\n}\n\nstd::vector<std::vector<int>>\
    \ contract(const std::vector<std::vector<int>>& G, const std::vector<int>& comp)\
    \ {\n    const int n = *max_element(comp.begin(), comp.end()) + 1;\n    std::vector<std::vector<int>>\
    \ G2(n);\n    for (int i = 0; i < (int) G.size(); ++i) {\n        for (int j :\
    \ G[i]) {\n            if (comp[i] != comp[j]) {\n                G2[comp[i]].push_back(comp[j]);\n\
    \            }\n        }\n    }\n    for (int i = 0; i < n; ++i) {\n        std::sort(G2[i].begin(),\
    \ G2[i].end());\n        G2[i].erase(std::unique(G2[i].begin(), G2[i].end()),\
    \ G2[i].end());\n    }\n    return G2;\n}"
  dependsOn:
  - graph/lowlink.cpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.cpp
  requiredBy: []
  timestamp: '2022-10-05 11:03:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: graph/two_edge_connected_components.cpp
layout: document
title: 2-Edge-Connected Components
---

## Description

二辺連結成分は，どの1本の辺を取り除いても連結であるような部分グラフである．つまり，橋を含まない部分グラフである．

二辺連結成分を縮約して得られるグラフは森になっている．

空間計算量: $O(V + E)$

## Operations

- `vector<int> two_edge_connected_components(vector<vector<int>> G, Lowlink low)`
    - グラフ $G$ の隣接リストと，$G$ の lowlink 構造体が与えられたとき，$G$ を二辺連結成分分解する
    - 時間計算量: $O(V + E)$

## Note

縮約には強連結成分分解のファイルにある`contract`関数がそのまま使える．