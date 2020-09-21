---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/graph/bellman_ford.md
    document_title: Bellman-Ford Algorithm
    links: []
  bundledCode: "#line 1 \"graph/bellman_ford.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}\n\
    \    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n};\n\
    #line 3 \"graph/bellman_ford.cpp\"\n\n/*\n * @brief Bellman-Ford Algorithm\n *\
    \ @docs docs/graph/bellman_ford.md\n */\ntemplate <typename T>\nstd::vector<T>\
    \ bellman_ford(const std::vector<Edge<T>>& G, int V, int s) {\n    const auto\
    \ INF = std::numeric_limits<T>::max();\n    std::vector<int> dist(V, INF);\n \
    \   dist[s] = 0;\n    for (int i = 0; i < V; i++) {\n        for (auto& e : G)\
    \ {\n            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost)\
    \ {\n                dist[e.to] = dist[e.from] + e.cost;\n                if (i\
    \ == V - 1) return std::vector<T>();\n            }\n        }\n    }\n    return\
    \ dist;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"edge.cpp\"\n\n/*\n * @brief Bellman-Ford\
    \ Algorithm\n * @docs docs/graph/bellman_ford.md\n */\ntemplate <typename T>\n\
    std::vector<T> bellman_ford(const std::vector<Edge<T>>& G, int V, int s) {\n \
    \   const auto INF = std::numeric_limits<T>::max();\n    std::vector<int> dist(V,\
    \ INF);\n    dist[s] = 0;\n    for (int i = 0; i < V; i++) {\n        for (auto&\
    \ e : G) {\n            if (dist[e.from] != INF && dist[e.to] > dist[e.from] +\
    \ e.cost) {\n                dist[e.to] = dist[e.from] + e.cost;\n           \
    \     if (i == V - 1) return std::vector<T>();\n            }\n        }\n   \
    \ }\n    return dist;\n}"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: graph/bellman_ford.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
documentation_of: graph/bellman_ford.cpp
layout: document
redirect_from:
- /library/graph/bellman_ford.cpp
- /library/graph/bellman_ford.cpp.html
title: Bellman-Ford Algorithm
---
# Bellman-Ford Algorithm

Bellman-Ford のアルゴリズムは，重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．負閉路の検出にも用いられる．

- `vector<T> bellman_ford(vector<Edge<T>>& G, int V, int s)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する．$G$ が負閉路を含む場合は，空のリストを返す
    - 時間計算量: $O(VE)$