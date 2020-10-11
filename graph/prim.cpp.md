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
  bundledCode: "#line 1 \"graph/prim.cpp\"\n#include <bits/stdc++.h>\n#line 3 \"graph/edge.cpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n \
    \   Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 3\
    \ \"graph/prim.cpp\"\n\n/*\n * @brief Prim's Algorithm\n * @docs docs/graph/prim.md\n\
    \ */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto& e1,\
    \ const auto& e2) { return e1.weight > e2.weight; };\n    std::priority_queue<Edge<T>,\
    \ std::vector<Edge<T>>, decltype(cmp)> pq(cmp);\n    pq.emplace(0, 0, 0);\n  \
    \  T weight = 0;\n    std::vector<Edge<T>> edges;\n    while (!pq.empty()) {\n\
    \        auto e = pq.top();\n        pq.pop();\n        if (used[e.to]) continue;\n\
    \        used[e.to] = true;\n        weight += e.weight;\n        if (e.to !=\
    \ 0) edges.push_back(e);\n        for (auto& f : G[e.to]) {\n            pq.emplace(e.to,\
    \ f.to, f.weight);\n        }\n    }\n    return {weight, edges};\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"edge.cpp\"\n\n/*\n * @brief Prim's Algorithm\n\
    \ * @docs docs/graph/prim.md\n */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>>\
    \ prim(const std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<bool> used(G.size());\n\
    \    auto cmp = [](const auto& e1, const auto& e2) { return e1.weight > e2.weight;\
    \ };\n    std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> pq(cmp);\n\
    \    pq.emplace(0, 0, 0);\n    T weight = 0;\n    std::vector<Edge<T>> edges;\n\
    \    while (!pq.empty()) {\n        auto e = pq.top();\n        pq.pop();\n  \
    \      if (used[e.to]) continue;\n        used[e.to] = true;\n        weight +=\
    \ e.weight;\n        if (e.to != 0) edges.push_back(e);\n        for (auto& f\
    \ : G[e.to]) {\n            pq.emplace(e.to, f.to, f.weight);\n        }\n   \
    \ }\n    return {weight, edges};\n}"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: graph/prim.cpp
  requiredBy: []
  timestamp: '2020-10-12 02:39:54+09:00'
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

- `pair<T, vector<Edge<T>>> prim(vector<vector<Edge<T>>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\lg V)$