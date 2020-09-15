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
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/graph/dijkstra.md
    document_title: Dijkstra's Algorithm
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.cpp\"\n#include <bits/stdc++.h>\n#line 2\
    \ \"graph/edge.cpp\"\nusing namespace std;\n\ntemplate <typename T>\nstruct Edge\
    \ {\n    int from, to;\n    T cost;\n    Edge(int to, T cost) : from(-1), to(to),\
    \ cost(cost) {}\n    Edge(int from, int to, T cost) : from(from), to(to), cost(cost)\
    \ {}\n};\n#line 3 \"graph/dijkstra.cpp\"\nusing namespace std;\n\n/*\n * @brief\
    \ Dijkstra's Algorithm\n * @docs docs/graph/dijkstra.md\n */\ntemplate <typename\
    \ T>\nvector<T> dijkstra(vector<vector<Edge<T>>>& G, int s) {\n    const T INF\
    \ = numeric_limits<T>::max();\n    vector<T> dist(G.size(), INF);\n    dist[s]\
    \ = 0;\n    using P = pair<T, int>;\n    priority_queue<P, vector<P>, greater<P>>\
    \ pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        T cost;\n \
    \       int v;\n        tie(cost, v) = pq.top();\n        pq.pop();\n        if\
    \ (dist[v] < cost) continue;\n        for (auto& e : G[v]) {\n            if (dist[e.to]\
    \ > dist[v] + e.cost) {\n                dist[e.to] = dist[v] + e.cost;\n    \
    \            pq.emplace(dist[e.to], e.to);\n            }\n        }\n    }\n\n\
    \    return dist;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"edge.cpp\"\nusing namespace std;\n\n\
    /*\n * @brief Dijkstra's Algorithm\n * @docs docs/graph/dijkstra.md\n */\ntemplate\
    \ <typename T>\nvector<T> dijkstra(vector<vector<Edge<T>>>& G, int s) {\n    const\
    \ T INF = numeric_limits<T>::max();\n    vector<T> dist(G.size(), INF);\n    dist[s]\
    \ = 0;\n    using P = pair<T, int>;\n    priority_queue<P, vector<P>, greater<P>>\
    \ pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        T cost;\n \
    \       int v;\n        tie(cost, v) = pq.top();\n        pq.pop();\n        if\
    \ (dist[v] < cost) continue;\n        for (auto& e : G[v]) {\n            if (dist[e.to]\
    \ > dist[v] + e.cost) {\n                dist[e.to] = dist[v] + e.cost;\n    \
    \            pq.emplace(dist[e.to], e.to);\n            }\n        }\n    }\n\n\
    \    return dist;\n}"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: graph/dijkstra.cpp
  requiredBy: []
  timestamp: '2020-09-11 22:35:33+09:00'
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

- `vector<T> dijkstra(vector<vector<Edge<T>>>& G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する
    - 時間計算量: $O(E \lg V)$