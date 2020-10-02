---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/dijkstra.md
    document_title: Dijkstra's Algorithm
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\n#include <bits/stdc++.h>\n#line 2\
    \ \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n\
    \    T weight;\n    Edge(int to, T weight) : from(-1), to(to), weight(weight)\
    \ {}\n    Edge(int from, int to, T weight) : from(from), to(to), weight(weight)\
    \ {}\n};\n#line 3 \"graph/dijkstra.cpp\"\n\n/*\n * @brief Dijkstra's Algorithm\n\
    \ * @docs docs/graph/dijkstra.md\n */\ntemplate <typename T>\nstd::vector<T> dijkstra(const\
    \ std::vector<std::vector<Edge<T>>>& G, int s) {\n    std::vector<T> dist(G.size(),\
    \ std::numeric_limits<T>::max());\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        T weight;\n        int\
    \ v;\n        std::tie(weight, v) = pq.top();\n        pq.pop();\n        if (dist[v]\
    \ < weight) continue;\n        for (auto& e : G[v]) {\n            if (dist[e.to]\
    \ > dist[v] + e.weight) {\n                dist[e.to] = dist[v] + e.weight;\n\
    \                pq.emplace(dist[e.to], e.to);\n            }\n        }\n   \
    \ }\n\n    return dist;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"edge.cpp\"\n\n/*\n * @brief Dijkstra's\
    \ Algorithm\n * @docs docs/graph/dijkstra.md\n */\ntemplate <typename T>\nstd::vector<T>\
    \ dijkstra(const std::vector<std::vector<Edge<T>>>& G, int s) {\n    std::vector<T>\
    \ dist(G.size(), std::numeric_limits<T>::max());\n    dist[s] = 0;\n    using\
    \ P = std::pair<T, int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        T weight;\n\
    \        int v;\n        std::tie(weight, v) = pq.top();\n        pq.pop();\n\
    \        if (dist[v] < weight) continue;\n        for (auto& e : G[v]) {\n   \
    \         if (dist[e.to] > dist[v] + e.weight) {\n                dist[e.to] =\
    \ dist[v] + e.weight;\n                pq.emplace(dist[e.to], e.to);\n       \
    \     }\n        }\n    }\n\n    return dist;\n}"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2020-10-03 00:05:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_A.test.cpp
documentation_of: graph/dijkstra.cpp
layout: document
redirect_from:
- /library/graph/dijkstra.cpp
- /library/graph/dijkstra.cpp.html
title: Dijkstra's Algorithm
---
# Dijkstra's Algorithm

Dijkstra のアルゴリズムは，負辺のない重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．

- `vector<T> dijkstra(vector<vector<Edge<T>>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する
    - 時間計算量: $O(E \lg V)$