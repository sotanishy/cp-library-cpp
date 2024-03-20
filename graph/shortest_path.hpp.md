---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/range_edge_graph.hpp
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest_path.hpp\"\n#include <limits>\n#include <queue>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n/*\n * Bellman-Ford\
    \ Algorithm\n */\ntemplate <typename T>\nstd::vector<T> bellman_ford(const std::vector<std::tuple<int,\
    \ int, T>>& G,\n                            int V, int s) {\n    constexpr T INF\
    \ = std::numeric_limits<T>::max();\n    std::vector<T> dist(V, INF);\n    dist[s]\
    \ = 0;\n    for (int i = 0; i < V; ++i) {\n        for (auto& [s, t, w] : G) {\n\
    \            if (dist[s] != INF && dist[t] > dist[s] + w) {\n                dist[t]\
    \ = dist[s] + w;\n                if (i == V - 1) return {};\n            }\n\
    \        }\n    }\n    return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n */\n\
    template <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>& dist)\
    \ {\n    const int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n     \
    \   for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n\
    \                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n}\n\n/*\n * Dijkstra's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::vector<T> dijkstra(const std::vector<std::vector<std::pair<int,\
    \ T>>>& G,\n                        int s) {\n    std::vector<T> dist(G.size(),\
    \ std::numeric_limits<T>::max());\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        auto [d, v] = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& [u,\
    \ w] : G[v]) {\n            if (dist[u] > d + w) {\n                dist[u] =\
    \ d + w;\n                pq.emplace(dist[u], u);\n            }\n        }\n\
    \    }\n\n    return dist;\n}\n\ntemplate <typename T>\nstd::pair<std::vector<T>,\
    \ std::vector<int>> shortest_path_tree(\n    const std::vector<std::vector<std::pair<int,\
    \ T>>>& G, int s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n\
    \    std::vector<int> par(G.size(), -1);\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        auto [d, v] = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& [u,\
    \ w] : G[v]) {\n            if (dist[u] > d + w) {\n                dist[u] =\
    \ d + w;\n                par[u] = v;\n                pq.emplace(dist[u], u);\n\
    \            }\n        }\n    }\n\n    return {dist, par};\n}\n\n/*\n * Breadth-First\
    \ Search\n */\nstd::vector<int> bfs(const std::vector<std::vector<int>>& G, int\
    \ s) {\n    std::vector<int> dist(G.size(), -1);\n    dist[s] = 0;\n    std::queue<int>\
    \ que;\n    que.push(s);\n\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (int u : G[v]) {\n            if (dist[u] ==\
    \ -1) {\n                dist[u] = dist[v] + 1;\n                que.push(u);\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\n/*\n * Dial's Algorithm\n\
    \ */\nstd::vector<int> dial(const std::vector<std::vector<std::pair<int, int>>>&\
    \ G,\n                      int s, int w) {\n    std::vector<int> dist(G.size(),\
    \ std::numeric_limits<int>::max());\n    dist[s] = 0;\n    std::vector<std::vector<int>>\
    \ buckets(w * G.size(), std::vector<int>());\n    buckets[0].push_back(s);\n\n\
    \    for (int d = 0; d < (int)buckets.size(); ++d) {\n        while (!buckets[d].empty())\
    \ {\n            int v = buckets[d].back();\n            buckets[d].pop_back();\n\
    \            if (dist[v] < d) continue;\n            for (auto& [u, w] : G[v])\
    \ {\n                if (dist[u] > d + w) {\n                    dist[u] = d +\
    \ w;\n                    buckets[dist[u]].push_back(u);\n                }\n\
    \            }\n        }\n    }\n    return dist;\n}\n"
  code: "#pragma once\n#include <limits>\n#include <queue>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\n/*\n * Bellman-Ford Algorithm\n */\ntemplate\
    \ <typename T>\nstd::vector<T> bellman_ford(const std::vector<std::tuple<int,\
    \ int, T>>& G,\n                            int V, int s) {\n    constexpr T INF\
    \ = std::numeric_limits<T>::max();\n    std::vector<T> dist(V, INF);\n    dist[s]\
    \ = 0;\n    for (int i = 0; i < V; ++i) {\n        for (auto& [s, t, w] : G) {\n\
    \            if (dist[s] != INF && dist[t] > dist[s] + w) {\n                dist[t]\
    \ = dist[s] + w;\n                if (i == V - 1) return {};\n            }\n\
    \        }\n    }\n    return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n */\n\
    template <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>& dist)\
    \ {\n    const int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n     \
    \   for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n\
    \                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n}\n\n/*\n * Dijkstra's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::vector<T> dijkstra(const std::vector<std::vector<std::pair<int,\
    \ T>>>& G,\n                        int s) {\n    std::vector<T> dist(G.size(),\
    \ std::numeric_limits<T>::max());\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        auto [d, v] = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& [u,\
    \ w] : G[v]) {\n            if (dist[u] > d + w) {\n                dist[u] =\
    \ d + w;\n                pq.emplace(dist[u], u);\n            }\n        }\n\
    \    }\n\n    return dist;\n}\n\ntemplate <typename T>\nstd::pair<std::vector<T>,\
    \ std::vector<int>> shortest_path_tree(\n    const std::vector<std::vector<std::pair<int,\
    \ T>>>& G, int s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n\
    \    std::vector<int> par(G.size(), -1);\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        auto [d, v] = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& [u,\
    \ w] : G[v]) {\n            if (dist[u] > d + w) {\n                dist[u] =\
    \ d + w;\n                par[u] = v;\n                pq.emplace(dist[u], u);\n\
    \            }\n        }\n    }\n\n    return {dist, par};\n}\n\n/*\n * Breadth-First\
    \ Search\n */\nstd::vector<int> bfs(const std::vector<std::vector<int>>& G, int\
    \ s) {\n    std::vector<int> dist(G.size(), -1);\n    dist[s] = 0;\n    std::queue<int>\
    \ que;\n    que.push(s);\n\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (int u : G[v]) {\n            if (dist[u] ==\
    \ -1) {\n                dist[u] = dist[v] + 1;\n                que.push(u);\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\n/*\n * Dial's Algorithm\n\
    \ */\nstd::vector<int> dial(const std::vector<std::vector<std::pair<int, int>>>&\
    \ G,\n                      int s, int w) {\n    std::vector<int> dist(G.size(),\
    \ std::numeric_limits<int>::max());\n    dist[s] = 0;\n    std::vector<std::vector<int>>\
    \ buckets(w * G.size(), std::vector<int>());\n    buckets[0].push_back(s);\n\n\
    \    for (int d = 0; d < (int)buckets.size(); ++d) {\n        while (!buckets[d].empty())\
    \ {\n            int v = buckets[d].back();\n            buckets[d].pop_back();\n\
    \            if (dist[v] < d) continue;\n            for (auto& [u, w] : G[v])\
    \ {\n                if (dist[u] > d + w) {\n                    dist[u] = d +\
    \ w;\n                    buckets[dist[u]].push_back(u);\n                }\n\
    \            }\n        }\n    }\n    return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path.hpp
  requiredBy:
  - graph/range_edge_graph.hpp
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
  - test/aoj/GRL_1_C.test.cpp
  - test/aoj/GRL_1_A.test.cpp
  - test/yosupo/shortest_path.test.cpp
documentation_of: graph/shortest_path.hpp
layout: document
title: Shortest Path Algorithms
---

## Description

最短経路問題を解くアルゴリズム詰め合わせ

## Bellman-Ford Algorithm

Bellman-Ford のアルゴリズムは，重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．負閉路検出にも用いられる．

- `vector<T> bellman_ford(vector<tuple<int, int, T>> G, int V, int s)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する．$G$ が負閉路を含む場合は，空のリストを返す
    - 時間計算量: $O(VE)$

## Floyd-Warshall Algorithm

Floyd-Warshall のアルゴリズムは，重み付きグラフの全点対最短経路問題を解くアルゴリズムである．負閉路検出にも用いられる．

- `void floyd_warshall(vector<vector<T>> dist)`
    - グラフ $G$ の隣接行列が与えられたとき，全頂点間の最短距離を計算する
    - 時間計算量: $O(V^3)$

## Dijkstra's Algorithm

Dijkstra のアルゴリズムは，負辺のない重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．

- `vector<T> dijkstra(vector<vector<pair<int, T>>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短距離を計算する
    - 時間計算量: $O(E \log V)$
- `pair<vector<T>, vector<T>> shortest_path_tree(vector<vector<pair<int, T>>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短距離と， $s$ を根とするある最短経路木における各頂点の親を返す
    - 時間計算量: $O(E \log V)$

## Breadth-First Search

***NOT VERIFIED***

幅優先探索は，重みがすべて1のグラフの単一始点最短経路問題を解くアルゴリズムである．

- `vector<T> bfs(vector<vector<int>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短距離を計算する
    - 時間計算量: $O(V + E)$

## Dial's Algorithm

***NOT VERIFIED***

Dial のアルゴリズムは，負辺のない重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．辺の重みが整数であり，上限が小さいときに Dijkstra のアルゴリズムより高速に動作する．

- `vector<int> dial(vector<vector<pair<int, int>>> G, int s, int w)`
    - グラフ $G$ の隣接リストと辺の重みの上限 $w$ が与えられたとき，始点 $s$ から各頂点への最短距離を計算する
    - 時間計算量: $O(E + wV)$