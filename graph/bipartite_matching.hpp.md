---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/bipartite_edge_coloring.hpp
    title: Bipartite Edge Coloring
  - icon: ':warning:'
    path: graph/dm_decomposition.hpp
    title: Dulmage-Mendelsohn Decomposition
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  - icon: ':x:'
    path: test/yosupo/bipartite_edge_coloring.test.cpp
    title: test/yosupo/bipartite_edge_coloring.test.cpp
  - icon: ':x:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bipartite_matching.hpp\"\n#include <limits>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\nclass BipartiteMatching {\n\
    \   public:\n    BipartiteMatching() = default;\n    BipartiteMatching(int U,\
    \ int V)\n        : U(U),\n          V(V),\n          NIL(U + V),\n          G(U),\n\
    \          level(U + V + 1),\n          match(U + V + 1, NIL) {}\n\n    void add_edge(int\
    \ u, int v) { G[u].emplace_back(U + v); }\n\n    std::vector<std::pair<int, int>>\
    \ max_matching() {\n        while (bfs()) {\n            for (int u = 0; u < U;\
    \ ++u) {\n                if (match[u] == NIL) {\n                    dfs(u);\n\
    \                }\n            }\n        }\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int u = 0; u < U; ++u) {\n            if (match[u]\
    \ != NIL) ret.emplace_back(u, match[u] - U);\n        }\n        return ret;\n\
    \    }\n\n   private:\n    static constexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\n\n    const int U, V, NIL;\n    std::vector<std::vector<int>> G;\n   \
    \ std::vector<int> level, match;\n\n    bool bfs() {\n        std::ranges::fill(level,\
    \ INF);\n        std::queue<int> q;\n        for (int u = 0; u < U; ++u) {\n \
    \           if (match[u] == NIL) {\n                level[u] = 0;\n          \
    \      q.push(u);\n            }\n        }\n        while (!q.empty()) {\n  \
    \          int u = q.front();\n            q.pop();\n            if (level[u]\
    \ < level[NIL]) {\n                for (int v : G[u]) {\n                    if\
    \ (level[match[v]] == INF) {\n                        level[match[v]] = level[u]\
    \ + 1;\n                        q.push(match[v]);\n                    }\n   \
    \             }\n            }\n        }\n        return level[NIL] != INF;\n\
    \    }\n\n    bool dfs(int u) {\n        if (u == NIL) return true;\n        for\
    \ (int v : G[u]) {\n            if (level[match[v]] == level[u] + 1 && dfs(match[v]))\
    \ {\n                match[v] = u;\n                match[u] = v;\n          \
    \      return true;\n            }\n        }\n        level[u] = INF;\n     \
    \   return false;\n    }\n};\n\n/*\n * Bipartite matching using Ford-Fulkerson\
    \ algorithm\n * Time complexity: O(VE)\n */\nclass BipartiteMatchingFF {\n   public:\n\
    \    BipartiteMatchingFF() = default;\n    explicit BipartiteMatchingFF(int n)\
    \ : G(n), used(n), match(n) {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    std::vector<std::pair<int, int>> max_matching()\
    \ {\n        int res = 0;\n        std::ranges::fill(match, -1);\n        for\
    \ (int v = 0; v < (int)G.size(); ++v) {\n            if (match[v] == -1) {\n \
    \               std::fill(used.begin(), used.end(), false);\n                if\
    \ (dfs(v)) ++res;\n            }\n        }\n\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int i = 0; i < (int)G.size(); ++i) {\n            if\
    \ (i < match[i]) ret.emplace_back(i, match[i]);\n        }\n        return ret;\n\
    \    }\n\n   private:\n    std::vector<std::vector<int>> G;\n    std::vector<bool>\
    \ used;\n    std::vector<int> match;\n\n    bool dfs(int u) {\n        used[u]\
    \ = true;\n        for (int v : G[u]) {\n            int w = match[v];\n     \
    \       if (w == -1 || (!used[w] && dfs(w))) {\n                match[u] = v;\n\
    \                match[v] = u;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n};\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\nclass BipartiteMatching {\n   public:\n    BipartiteMatching() =\
    \ default;\n    BipartiteMatching(int U, int V)\n        : U(U),\n          V(V),\n\
    \          NIL(U + V),\n          G(U),\n          level(U + V + 1),\n       \
    \   match(U + V + 1, NIL) {}\n\n    void add_edge(int u, int v) { G[u].emplace_back(U\
    \ + v); }\n\n    std::vector<std::pair<int, int>> max_matching() {\n        while\
    \ (bfs()) {\n            for (int u = 0; u < U; ++u) {\n                if (match[u]\
    \ == NIL) {\n                    dfs(u);\n                }\n            }\n \
    \       }\n        std::vector<std::pair<int, int>> ret;\n        for (int u =\
    \ 0; u < U; ++u) {\n            if (match[u] != NIL) ret.emplace_back(u, match[u]\
    \ - U);\n        }\n        return ret;\n    }\n\n   private:\n    static constexpr\
    \ int INF = std::numeric_limits<int>::max() / 2;\n\n    const int U, V, NIL;\n\
    \    std::vector<std::vector<int>> G;\n    std::vector<int> level, match;\n\n\
    \    bool bfs() {\n        std::ranges::fill(level, INF);\n        std::queue<int>\
    \ q;\n        for (int u = 0; u < U; ++u) {\n            if (match[u] == NIL)\
    \ {\n                level[u] = 0;\n                q.push(u);\n            }\n\
    \        }\n        while (!q.empty()) {\n            int u = q.front();\n   \
    \         q.pop();\n            if (level[u] < level[NIL]) {\n               \
    \ for (int v : G[u]) {\n                    if (level[match[v]] == INF) {\n  \
    \                      level[match[v]] = level[u] + 1;\n                     \
    \   q.push(match[v]);\n                    }\n                }\n            }\n\
    \        }\n        return level[NIL] != INF;\n    }\n\n    bool dfs(int u) {\n\
    \        if (u == NIL) return true;\n        for (int v : G[u]) {\n          \
    \  if (level[match[v]] == level[u] + 1 && dfs(match[v])) {\n                match[v]\
    \ = u;\n                match[u] = v;\n                return true;\n        \
    \    }\n        }\n        level[u] = INF;\n        return false;\n    }\n};\n\
    \n/*\n * Bipartite matching using Ford-Fulkerson algorithm\n * Time complexity:\
    \ O(VE)\n */\nclass BipartiteMatchingFF {\n   public:\n    BipartiteMatchingFF()\
    \ = default;\n    explicit BipartiteMatchingFF(int n) : G(n), used(n), match(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n      \
    \  G[v].push_back(u);\n    }\n\n    std::vector<std::pair<int, int>> max_matching()\
    \ {\n        int res = 0;\n        std::ranges::fill(match, -1);\n        for\
    \ (int v = 0; v < (int)G.size(); ++v) {\n            if (match[v] == -1) {\n \
    \               std::fill(used.begin(), used.end(), false);\n                if\
    \ (dfs(v)) ++res;\n            }\n        }\n\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int i = 0; i < (int)G.size(); ++i) {\n            if\
    \ (i < match[i]) ret.emplace_back(i, match[i]);\n        }\n        return ret;\n\
    \    }\n\n   private:\n    std::vector<std::vector<int>> G;\n    std::vector<bool>\
    \ used;\n    std::vector<int> match;\n\n    bool dfs(int u) {\n        used[u]\
    \ = true;\n        for (int v : G[u]) {\n            int w = match[v];\n     \
    \       if (w == -1 || (!used[w] && dfs(w))) {\n                match[u] = v;\n\
    \                match[v] = u;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite_matching.hpp
  requiredBy:
  - graph/bipartite_edge_coloring.hpp
  - graph/dm_decomposition.hpp
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/bipartite_edge_coloring.test.cpp
  - test/yosupo/bipartitematching.test.cpp
  - test/aoj/GRL_7_A.test.cpp
documentation_of: graph/bipartite_matching.hpp
layout: document
title: Bipartite Matching
---

## Description

二部グラフの最大マッチングを Hopcroft-Karp アルゴリズムで求める．これは Dinic のアルゴリズムの特殊ケースである．

## Operations

- `BipartiteMatching(int U, int V)`
    - 頂点数 $(U, V)$ で初期化する
- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
- `vector<pair<int, int>> max_matching()`
    - 二部グラフの最大マッチングを一つ返す
    - 時間計算量: $O(E\sqrt{U+V})$

## Reference

- [Hopcroft–Karp algorithm - Wikipedia](https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm)
