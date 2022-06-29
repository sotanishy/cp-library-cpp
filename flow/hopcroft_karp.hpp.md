---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_edge_coloring.hpp
    title: Bipartite Edge Coloring
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartite_edge_coloring.test.cpp
    title: test/yosupo/bipartite_edge_coloring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/hopcroft_karp.hpp\"\n#include <limits>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\n\nclass HopcroftKarp {\npublic:\n   \
    \ HopcroftKarp() = default;\n    HopcroftKarp(int U, int V) : U(U), V(V), NIL(U\
    \ + V), G(U), level(U + V + 1), match(U + V + 1, NIL) {}\n\n    void add_edge(int\
    \ u, int v) {\n        G[u].emplace_back(U + v);\n    }\n\n    std::vector<std::pair<int,\
    \ int>> bipartite_matching() {\n        while (bfs()) {\n            for (int\
    \ u = 0; u < U; ++u) {\n                if (match[u] == NIL) {\n             \
    \       dfs(u);\n                }\n            }\n        }\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int u = 0; u < U; ++u) {\n            if (match[u]\
    \ != NIL) ret.emplace_back(u, match[u] - U);\n        }\n        return ret;\n\
    \    }\n\nprivate:\n    static constexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\n\n    const int U, V, NIL;\n    std::vector<std::vector<int>> G;\n   \
    \ std::vector<int> level, match;\n\n    bool bfs() {\n        std::fill(level.begin(),\
    \ level.end(), INF);\n        std::queue<int> q;\n        for (int u = 0; u <\
    \ U; ++u) {\n            if (match[u] == NIL) {\n                level[u] = 0;\n\
    \                q.push(u);\n            }\n        }\n        while (!q.empty())\
    \ {\n            int u = q.front();\n            q.pop();\n            if (level[u]\
    \ < level[NIL]) {\n                for (int v : G[u]) {\n                    if\
    \ (level[match[v]] == INF) {\n                        level[match[v]] = level[u]\
    \ + 1;\n                        q.push(match[v]);\n                    }\n   \
    \             }\n            }\n        }\n        return level[NIL] != INF;\n\
    \    }\n\n    bool dfs(int u) {\n        if (u == NIL) return true;\n        for\
    \ (int v : G[u]) {\n            if (level[match[v]] == level[u] + 1 && dfs(match[v]))\
    \ {\n                match[v] = u;\n                match[u] = v;\n          \
    \      return true;\n            }\n        }\n        level[u] = INF;\n     \
    \   return false;\n    }\n};\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\n\nclass HopcroftKarp {\npublic:\n    HopcroftKarp() = default;\n\
    \    HopcroftKarp(int U, int V) : U(U), V(V), NIL(U + V), G(U), level(U + V +\
    \ 1), match(U + V + 1, NIL) {}\n\n    void add_edge(int u, int v) {\n        G[u].emplace_back(U\
    \ + v);\n    }\n\n    std::vector<std::pair<int, int>> bipartite_matching() {\n\
    \        while (bfs()) {\n            for (int u = 0; u < U; ++u) {\n        \
    \        if (match[u] == NIL) {\n                    dfs(u);\n               \
    \ }\n            }\n        }\n        std::vector<std::pair<int, int>> ret;\n\
    \        for (int u = 0; u < U; ++u) {\n            if (match[u] != NIL) ret.emplace_back(u,\
    \ match[u] - U);\n        }\n        return ret;\n    }\n\nprivate:\n    static\
    \ constexpr int INF = std::numeric_limits<int>::max() / 2;\n\n    const int U,\
    \ V, NIL;\n    std::vector<std::vector<int>> G;\n    std::vector<int> level, match;\n\
    \n    bool bfs() {\n        std::fill(level.begin(), level.end(), INF);\n    \
    \    std::queue<int> q;\n        for (int u = 0; u < U; ++u) {\n            if\
    \ (match[u] == NIL) {\n                level[u] = 0;\n                q.push(u);\n\
    \            }\n        }\n        while (!q.empty()) {\n            int u = q.front();\n\
    \            q.pop();\n            if (level[u] < level[NIL]) {\n            \
    \    for (int v : G[u]) {\n                    if (level[match[v]] == INF) {\n\
    \                        level[match[v]] = level[u] + 1;\n                   \
    \     q.push(match[v]);\n                    }\n                }\n          \
    \  }\n        }\n        return level[NIL] != INF;\n    }\n\n    bool dfs(int\
    \ u) {\n        if (u == NIL) return true;\n        for (int v : G[u]) {\n   \
    \         if (level[match[v]] == level[u] + 1 && dfs(match[v])) {\n          \
    \      match[v] = u;\n                match[u] = v;\n                return true;\n\
    \            }\n        }\n        level[u] = INF;\n        return false;\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/hopcroft_karp.hpp
  requiredBy:
  - graph/bipartite_edge_coloring.hpp
  timestamp: '2022-06-29 12:22:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bipartitematching.test.cpp
  - test/yosupo/bipartite_edge_coloring.test.cpp
documentation_of: flow/hopcroft_karp.hpp
layout: document
title: Hopcroft-Karp Algorithm
---

## Description

Hopcroft-Karp アルゴリズムは，二部グラフの最大マッチングを求めるアルゴリズムである．Dinic のアルゴリズムの特殊ケースである．

## Operations

- `HopcroftKarp(int U, int V)`
    - 頂点数 $(U, V)$ で初期化する
- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
- `vector<pair<int, int>> bipartite_matching()`
    - 二部グラフの最大マッチングを一つ返す
    - 時間計算量: $O(E\sqrt{U+V})$

## Reference

- [Hopcroft–Karp algorithm - Wikipedia](https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm)
