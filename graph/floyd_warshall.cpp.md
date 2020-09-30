---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/floyd_warshall.md
    document_title: Floyd-Warshall Algorithm
    links: []
  bundledCode: "#line 1 \"graph/floyd_warshall.cpp\"\n#include <bits/stdc++.h>\n\n\
    /*\n * @brief Floyd-Warshall Algorithm\n * @docs docs/graph/floyd_warshall.md\n\
    \ */\ntemplate <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>&\
    \ dist) {\n    int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n     \
    \   for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n\
    \                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n}\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Floyd-Warshall Algorithm\n * @docs\
    \ docs/graph/floyd_warshall.md\n */\ntemplate <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>&\
    \ dist) {\n    int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n     \
    \   for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n\
    \                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/floyd_warshall.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_C.test.cpp
documentation_of: graph/floyd_warshall.cpp
layout: document
redirect_from:
- /library/graph/floyd_warshall.cpp
- /library/graph/floyd_warshall.cpp.html
title: Floyd-Warshall Algorithm
---
# Floyd-Warshall Algorithm

Floyd-Warshall のアルゴリズムは，重み付きグラフの全点対最短経路問題を解くアルゴリズムである．負閉路検出にも用いられる．

- `void floyd_warshall(vector<vector<T>> dist)`
    - グラフ $G$ の隣接行列が与えられたとき，全頂点間の最短距離を計算する
    - 時間計算量: $O(V^3)$