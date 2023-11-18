---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.cpp
    title: Biconnected Components
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.cpp
    title: 2-Edge-Connected Components
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/biconnected_components.test.cpp
    title: test/yosupo/biconnected_components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/lowlink.cpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\nclass Lowlink {\npublic:\n    std::vector<int> ord, low;\n\
    \    std::vector<std::pair<int, int>> bridge;\n    std::vector<int> articulation;\n\
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
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \nclass Lowlink {\npublic:\n    std::vector<int> ord, low;\n    std::vector<std::pair<int,\
    \ int>> bridge;\n    std::vector<int> articulation;\n\n    Lowlink() = default;\n\
    \    explicit Lowlink(const std::vector<std::vector<int>>& G) : ord(G.size(),\
    \ -1), low(G.size()), G(G) {\n        for (int i = 0; i < (int) G.size(); ++i)\
    \ {\n            if (ord[i] == -1) dfs(i, -1);\n        }\n    }\n\n    bool is_bridge(int\
    \ u, int v) const {\n        if (ord[u] > ord[v]) std::swap(u, v);\n        return\
    \ ord[u] < low[v];\n    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n\
    \    int k = 0;\n\n    void dfs(int v, int p) {\n        ord[v] = k++;\n     \
    \   low[v] = ord[v];\n        bool is_articulation = false, checked = false;\n\
    \        int cnt = 0;\n        for (int c : G[v]) {\n            if (c == p &&\
    \ !checked) {\n                checked = true;\n                continue;\n  \
    \          }\n            if (ord[c] == -1) {\n                ++cnt;\n      \
    \          dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n  \
    \              if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n    \
    \            if (ord[v] < low[c]) bridge.push_back(std::minmax(v, c));\n     \
    \       } else {\n                low[v] = std::min(low[v], ord[c]);\n       \
    \     }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.cpp
  requiredBy:
  - graph/two_edge_connected_components.cpp
  - graph/biconnected_components.cpp
  timestamp: '2022-10-05 11:03:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/biconnected_components.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/GRL_3_A.test.cpp
documentation_of: graph/lowlink.cpp
layout: document
title: Lowlink
---

## Description

Lowlink はグラフの橋や関節点などを求める際に有効な概念である．グラフの DFS tree において，頂点 $v$ の訪問時刻を `ord[v]` としたとき，$v$ から後退辺 (DFS tree に含まれない辺) を高々1回用いて到達することができる頂点の `ord` の最小値 `low[v]` を lowlink という．

辺 $(u, v)$ が橋であることの必要十分条件は `ord[u] < low[v]` が成り立つことである．

頂点 $v$ が関節点であることの必要十分条件は
- $v$ が DFS tree の根であり，かつ2つ以上の子を持つ
- $v$ が DFS tree の根ではなく，かつ $v$ のある子 $c$ について `ord[v] <= low[c]` が成り立つ

のどちらかが成り立つことである．

空間計算量: $O(V + E)$

## Operations

- `Lowlink(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ の橋と関節点を求める
    - 時間計算量: $O(V + E)$
- `bool is_bridge(int u, int v)`
    - 辺 $uv$ が橋かどうか判定する
    - 時間計算量: $O(1)$

## Reference

- [橋と関節点, lowlink](https://kagamiz.hatenablog.com/entry/2013/10/05/005213)