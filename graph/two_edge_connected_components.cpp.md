---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/lowlink.cpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n            if\
    \ (c == p) continue;\n            if (ord[c] == -1) {\n                ++cnt;\n\
    \                dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n\
    \                if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n  \
    \              if (ord[v] < low[c]) bridge.emplace_back(std::min(v, c), std::max(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 4 \"\
    graph/two_edge_connected_components.cpp\"\n\nclass TwoEdgeConnectedComponents\
    \ : Lowlink {\npublic:\n    TwoEdgeConnectedComponents() = default;\n    explicit\
    \ TwoEdgeConnectedComponents(const std::vector<std::vector<int>>& G) : Lowlink(G),\
    \ comp(G.size(), -1) {\n        for (int v = 0; v < (int) G.size(); ++v) {\n \
    \           if (comp[v] == -1) dfs(v, cnt++);\n        }\n    }\n\n    int operator[](int\
    \ i) const {\n        return comp[i];\n    }\n\n    int count() const noexcept\
    \ {\n        return cnt;\n    }\n\nprivate:\n    std::vector<int> comp;\n    int\
    \ cnt = 0;\n\n    void dfs(int u, int c) {\n        comp[u] = c;\n        for\
    \ (int v : G[u]) {\n            if (comp[v] == -1 && !is_bridge(u, v)) dfs(v,\
    \ c);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include \"lowlink.cpp\"\n\nclass TwoEdgeConnectedComponents\
    \ : Lowlink {\npublic:\n    TwoEdgeConnectedComponents() = default;\n    explicit\
    \ TwoEdgeConnectedComponents(const std::vector<std::vector<int>>& G) : Lowlink(G),\
    \ comp(G.size(), -1) {\n        for (int v = 0; v < (int) G.size(); ++v) {\n \
    \           if (comp[v] == -1) dfs(v, cnt++);\n        }\n    }\n\n    int operator[](int\
    \ i) const {\n        return comp[i];\n    }\n\n    int count() const noexcept\
    \ {\n        return cnt;\n    }\n\nprivate:\n    std::vector<int> comp;\n    int\
    \ cnt = 0;\n\n    void dfs(int u, int c) {\n        comp[u] = c;\n        for\
    \ (int v : G[u]) {\n            if (comp[v] == -1 && !is_bridge(u, v)) dfs(v,\
    \ c);\n        }\n    }\n};"
  dependsOn:
  - graph/lowlink.cpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.cpp
  requiredBy: []
  timestamp: '2021-03-30 13:20:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
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

- `TwoEdgeConnectedComponents(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ を二辺連結成分分解する
    - 時間計算量: $O(V + E)$
- `int operator[](int i)`
    - 頂点 $v$ が属する二辺連結成分のラベルを返す
- `int count()`
    - $G$ の二辺連結成分の数を返す