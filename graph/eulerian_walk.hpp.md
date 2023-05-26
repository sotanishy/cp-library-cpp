---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/eulerian_walk.hpp\"\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\nstd::vector<int> eulerian_walk(const std::vector<std::pair<int,\
    \ int>>& edges,\n                               int V) {\n    std::vector<std::vector<std::pair<int,\
    \ int>>> G(V);\n    std::vector<int> deg(V);\n    for (int i = 0; i < (int)edges.size();\
    \ ++i) {\n        auto [a, b] = edges[i];\n        G[a].push_back({b, i});\n \
    \       G[b].push_back({a, i});\n        ++deg[a];\n        ++deg[b];\n    }\n\
    \    int s = 0;\n    int cnt = 0;\n    for (int i = 0; i < V; ++i) {\n       \
    \ if (deg[i] % 2) {\n            ++cnt;\n            s = i;\n        }\n    }\n\
    \    if (cnt != 0 && cnt != 2) return {};\n    std::vector<int> ret;\n    std::stack<int>\
    \ st;\n    st.push(s);\n    std::vector<bool> used(edges.size());\n    while (!st.empty())\
    \ {\n        int u = st.top();\n        while (!G[u].empty() && used[G[u].back().second])\
    \ G[u].pop_back();\n        if (G[u].empty()) {\n            ret.push_back(u);\n\
    \            st.pop();\n        } else {\n            auto [v, i] = G[u].back();\n\
    \            G[u].pop_back();\n            used[i] = true;\n            st.emplace(v);\n\
    \        }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <utility>\n#include <vector>\n\n\
    std::vector<int> eulerian_walk(const std::vector<std::pair<int, int>>& edges,\n\
    \                               int V) {\n    std::vector<std::vector<std::pair<int,\
    \ int>>> G(V);\n    std::vector<int> deg(V);\n    for (int i = 0; i < (int)edges.size();\
    \ ++i) {\n        auto [a, b] = edges[i];\n        G[a].push_back({b, i});\n \
    \       G[b].push_back({a, i});\n        ++deg[a];\n        ++deg[b];\n    }\n\
    \    int s = 0;\n    int cnt = 0;\n    for (int i = 0; i < V; ++i) {\n       \
    \ if (deg[i] % 2) {\n            ++cnt;\n            s = i;\n        }\n    }\n\
    \    if (cnt != 0 && cnt != 2) return {};\n    std::vector<int> ret;\n    std::stack<int>\
    \ st;\n    st.push(s);\n    std::vector<bool> used(edges.size());\n    while (!st.empty())\
    \ {\n        int u = st.top();\n        while (!G[u].empty() && used[G[u].back().second])\
    \ G[u].pop_back();\n        if (G[u].empty()) {\n            ret.push_back(u);\n\
    \            st.pop();\n        } else {\n            auto [v, i] = G[u].back();\n\
    \            G[u].pop_back();\n            used[i] = true;\n            st.emplace(v);\n\
    \        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/eulerian_walk.hpp
  requiredBy: []
  timestamp: '2023-05-27 03:55:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/eulerian_walk.hpp
layout: document
title: Eulerian Walk
---

## Description

Euler 路 (グラフのすべての辺を通る路) を一つ見つける．

奇数次の頂点が0個なら Euler 閉路が存在する．奇数次の頂点が2個なら閉路でない Euler 路が存在する．それ以外のときは Euler 路は存在しない．

この実装では Hierholzer のアルゴリズムを用いている．

## Operations

- `vector<int> eulerian_walk(vector<pair<int, int>> edges, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺集合が与えられたとき，$G$ の Euler 路に現れる頂点を順番に返す．存在しない場合は空リストを返す．
    - 時間計算量: $O(E)$
