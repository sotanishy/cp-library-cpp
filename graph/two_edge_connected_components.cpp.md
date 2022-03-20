---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ 5 \"graph/lowlink.cpp\"\n\nclass Lowlink {\npublic:\n    Lowlink() = default;\n\
    \    explicit Lowlink(const std::vector<std::vector<int>>& G) : G(G), ord(G.size(),\
    \ -1), low(G.size()) {\n        for (int i = 0; i < (int) G.size(); ++i) {\n \
    \           if (ord[i] == -1) dfs(i, -1);\n        }\n    }\n\n    std::vector<std::pair<int,\
    \ int>> get_bridges() const {\n        return bridge;\n    }\n\n    std::vector<int>\
    \ get_articulation_points() const {\n        return articulation;\n    }\n\n \
    \   bool is_bridge(int u, int v) const {\n        if (ord[u] > ord[v]) std::swap(u,\
    \ v);\n        return ord[u] < low[v];\n    }\n\nprotected:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> ord, low;\n    std::vector<std::pair<int, int>> bridge;\n\
    \    std::vector<int> articulation;\n\nprivate:\n    int k = 0;\n\n    void dfs(int\
    \ v, int p) {\n        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false, checked = false;\n        int cnt = 0;\n        for (int c : G[v])\
    \ {\n            if (c == p && !checked) {\n                checked = true;\n\
    \                continue;\n            }\n            if (ord[c] == -1) {\n \
    \               ++cnt;\n                dfs(c, v);\n                low[v] = std::min(low[v],\
    \ low[c]);\n                if (p != -1 && ord[v] <= low[c]) is_articulation =\
    \ true;\n                if (ord[v] < low[c]) bridge.push_back(std::minmax(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 4 \"\
    graph/two_edge_connected_components.cpp\"\n\nstd::vector<int> two_edge_connected_components(const\
    \ std::vector<std::vector<int>>& G) {\n    int k = 0;\n    std::vector<int> comp(G.size(),\
    \ -1);\n    auto lowlink = Lowlink(G);\n\n    auto dfs = [&](const auto& dfs,\
    \ int u) -> void {\n        comp[u] = k;\n        for (int v : G[u]) {\n     \
    \       if (comp[v] == -1 && !lowlink.is_bridge(u, v)) dfs(dfs, v);\n        }\n\
    \    };\n\n    for (int v = 0; v < (int) G.size(); ++v) {\n        if (comp[v]\
    \ == -1) {\n            dfs(dfs, v);\n            ++k;\n        }\n    }\n   \
    \ return comp;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"lowlink.cpp\"\n\nstd::vector<int>\
    \ two_edge_connected_components(const std::vector<std::vector<int>>& G) {\n  \
    \  int k = 0;\n    std::vector<int> comp(G.size(), -1);\n    auto lowlink = Lowlink(G);\n\
    \n    auto dfs = [&](const auto& dfs, int u) -> void {\n        comp[u] = k;\n\
    \        for (int v : G[u]) {\n            if (comp[v] == -1 && !lowlink.is_bridge(u,\
    \ v)) dfs(dfs, v);\n        }\n    };\n\n    for (int v = 0; v < (int) G.size();\
    \ ++v) {\n        if (comp[v] == -1) {\n            dfs(dfs, v);\n           \
    \ ++k;\n        }\n    }\n    return comp;\n}"
  dependsOn:
  - graph/lowlink.cpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.cpp
  requiredBy: []
  timestamp: '2022-03-06 21:25:07+09:00'
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

- `vector<int> two_edge_connected_components(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ を二辺連結成分分解する
    - 時間計算量: $O(V + E)$

## Note

縮約には強連結成分分解のファイルにある`contract`関数がそのまま使える．