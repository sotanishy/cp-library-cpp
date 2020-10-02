---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.prim.test.cpp
    title: test/aoj/GRL_2_A.prim.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/prim.md
    document_title: Prim's Algorithm
    links: []
  bundledCode: "#line 1 \"graph/prim.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"graph/edge.cpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n \
    \   Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 3\
    \ \"graph/prim.cpp\"\n\n/*\n * @brief Prim's Algorithm\n * @docs docs/graph/prim.md\n\
    \ */\ntemplate <typename T>\nT prim(const std::vector<std::vector<Edge<T>>>& G)\
    \ {\n    std::vector<bool> used(G.size());\n    using P = std::pair<T, int>;\n\
    \    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0,\
    \ 0);\n    T ret = 0;\n    while (!pq.empty()) {\n        auto p = pq.top();\n\
    \        pq.pop();\n        int v = p.second;\n        if (used[v]) continue;\n\
    \        used[v] = true;\n        ret += p.first;\n        for (auto& e : G[v])\
    \ {\n            pq.emplace(e.weight, e.to);\n        }\n    }\n    return ret;\n\
    }\n"
  code: "#include <bits/stdc++.h>\n#include \"edge.cpp\"\n\n/*\n * @brief Prim's Algorithm\n\
    \ * @docs docs/graph/prim.md\n */\ntemplate <typename T>\nT prim(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n    std::vector<bool> used(G.size());\n    using P = std::pair<T, int>;\n\
    \    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0,\
    \ 0);\n    T ret = 0;\n    while (!pq.empty()) {\n        auto p = pq.top();\n\
    \        pq.pop();\n        int v = p.second;\n        if (used[v]) continue;\n\
    \        used[v] = true;\n        ret += p.first;\n        for (auto& e : G[v])\
    \ {\n            pq.emplace(e.weight, e.to);\n        }\n    }\n    return ret;\n\
    }"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: graph/prim.cpp
  requiredBy: []
  timestamp: '2020-10-03 00:05:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.prim.test.cpp
documentation_of: graph/prim.cpp
layout: document
redirect_from:
- /library/graph/prim.cpp
- /library/graph/prim.cpp.html
title: Prim's Algorithm
---
# Prim's Algorithm

Prim のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `T prim(vector<vector<Edge<T>>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，最小全域木の重みを求める
    - 時間計算量: $O(E\lg V)$