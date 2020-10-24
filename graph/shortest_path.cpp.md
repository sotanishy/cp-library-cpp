---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/range_edge_graph.cpp
    title: Range Edge Graph
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/shortest_path.md
    document_title: Shortest Path Algorithms
    links: []
  bundledCode: "#line 2 \"graph/shortest_path.cpp\"\n#include <limits>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n#line 2 \"graph/edge.cpp\"\n#include <bits/stdc++.h>\n\
    \ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n   \
    \ Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int from,\
    \ int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 7 \"graph/shortest_path.cpp\"\
    \n\n/*\n * @brief Shortest Path Algorithms\n * @docs docs/graph/shortest_path.md\n\
    \ */\n\n/*\n * Bellman-Ford Algorithm\n */\ntemplate <typename T>\nstd::vector<T>\
    \ bellman_ford(const std::vector<Edge<T>>& G, int V, int s) {\n    constexpr T\
    \ INF = std::numeric_limits<T>::max();\n    std::vector<int> dist(V, INF);\n \
    \   dist[s] = 0;\n    for (int i = 0; i < V; ++i) {\n        for (auto& e : G)\
    \ {\n            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.weight)\
    \ {\n                dist[e.to] = dist[e.from] + e.weight;\n                if\
    \ (i == V - 1) return std::vector<T>();\n            }\n        }\n    }\n   \
    \ return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n */\ntemplate <typename\
    \ T>\nvoid floyd_warshall(std::vector<std::vector<T>>& dist) {\n    int V = dist.size();\n\
    \    for (int k = 0; k < V; ++k) {\n        for (int i = 0; i < V; ++i) {\n  \
    \          for (int j = 0; j < V; ++j) {\n                dist[i][j] = std::min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n            }\n        }\n    }\n}\n\n/*\n * Dijkstra's\
    \ Algorithm\n */\ntemplate <typename T>\nstd::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>&\
    \ G, int s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n\
    \    dist[s] = 0;\n    using P = std::pair<T, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty())\
    \ {\n        T weight;\n        int v;\n        std::tie(weight, v) = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < weight) continue;\n        for (auto&\
    \ e : G[v]) {\n            if (dist[e.to] > dist[v] + e.weight) {\n          \
    \      dist[e.to] = dist[v] + e.weight;\n                pq.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n\n    return dist;\n}\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n#include \"edge.cpp\"\n\n/*\n * @brief Shortest Path Algorithms\n\
    \ * @docs docs/graph/shortest_path.md\n */\n\n/*\n * Bellman-Ford Algorithm\n\
    \ */\ntemplate <typename T>\nstd::vector<T> bellman_ford(const std::vector<Edge<T>>&\
    \ G, int V, int s) {\n    constexpr T INF = std::numeric_limits<T>::max();\n \
    \   std::vector<int> dist(V, INF);\n    dist[s] = 0;\n    for (int i = 0; i <\
    \ V; ++i) {\n        for (auto& e : G) {\n            if (dist[e.from] != INF\
    \ && dist[e.to] > dist[e.from] + e.weight) {\n                dist[e.to] = dist[e.from]\
    \ + e.weight;\n                if (i == V - 1) return std::vector<T>();\n    \
    \        }\n        }\n    }\n    return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n\
    \ */\ntemplate <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>&\
    \ dist) {\n    int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n     \
    \   for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n\
    \                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n}\n\n/*\n * Dijkstra's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>&\
    \ G, int s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n\
    \    dist[s] = 0;\n    using P = std::pair<T, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty())\
    \ {\n        T weight;\n        int v;\n        std::tie(weight, v) = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < weight) continue;\n        for (auto&\
    \ e : G[v]) {\n            if (dist[e.to] > dist[v] + e.weight) {\n          \
    \      dist[e.to] = dist[v] + e.weight;\n                pq.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n\n    return dist;\n}"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: graph/shortest_path.cpp
  requiredBy:
  - graph/range_edge_graph.cpp
  timestamp: '2020-10-24 15:48:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
  - test/aoj/GRL_1_C.test.cpp
  - test/aoj/GRL_1_A.test.cpp
documentation_of: graph/shortest_path.cpp
layout: document
redirect_from:
- /library/graph/shortest_path.cpp
- /library/graph/shortest_path.cpp.html
title: Shortest Path Algorithms
---
# Shortest Path Algorithms

最短経路問題を解くアルゴリズム詰め合わせ

## Bellman-Ford Algorithm

Bellman-Ford のアルゴリズムは，重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．負閉路の検出にも用いられる．

- `vector<T> bellman_ford(vector<Edge<T>> G, int V, int s)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する．$G$ が負閉路を含む場合は，空のリストを返す
    - 時間計算量: $O(VE)$

## Floyd-Warshall Algorithm

Floyd-Warshall のアルゴリズムは，重み付きグラフの全点対最短経路問題を解くアルゴリズムである．負閉路検出にも用いられる．

- `void floyd_warshall(vector<vector<T>> dist)`
    - グラフ $G$ の隣接行列が与えられたとき，全頂点間の最短距離を計算する
    - 時間計算量: $O(V^3)$

## Dijkstra's Algorithm

Dijkstra のアルゴリズムは，負辺のない重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．

- `vector<T> dijkstra(vector<vector<Edge<T>>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する
    - 時間計算量: $O(E \lg V)$
