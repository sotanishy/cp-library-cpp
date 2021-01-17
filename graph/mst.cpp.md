---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/union_find.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.boruvka.test.cpp
    title: test/aoj/GRL_2_A.boruvka.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.prim.test.cpp
    title: test/aoj/GRL_2_A.prim.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/mst.cpp\"\n#include <algorithm>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n#line 2 \"graph/edge.cpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n    Edge(int\
    \ to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int from, int\
    \ to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 4 \"data-structure/unionfind/union_find.cpp\"\
    \n\nclass UnionFind {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};\n#line 8 \"graph/mst.cpp\"\n\
    \n/*\n * Kruskal's Algorithm\n */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>>\
    \ kruskal(std::vector<Edge<T>> G, int V) {\n    std::sort(G.begin(), G.end(),\
    \ [](const auto& e1, const auto& e2) {\n        return e1.weight < e2.weight;\n\
    \    });\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>> edges;\n\
    \    for (auto& e : G) {\n        if (!uf.same(e.from, e.to)) {\n            uf.unite(e.from,\
    \ e.to);\n            weight += e.weight;\n            edges.push_back(e);\n \
    \       }\n    }\n    return {weight, edges};\n}\n\n/*\n * Prim's Algorithm\n\
    \ */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto& e1,\
    \ const auto& e2) { return e1.weight > e2.weight; };\n    std::priority_queue<Edge<T>,\
    \ std::vector<Edge<T>>, decltype(cmp)> pq(cmp);\n    pq.emplace(0, 0, 0);\n  \
    \  T weight = 0;\n    std::vector<Edge<T>> edges;\n    while (!pq.empty()) {\n\
    \        auto e = pq.top();\n        pq.pop();\n        if (used[e.to]) continue;\n\
    \        used[e.to] = true;\n        weight += e.weight;\n        if (e.to !=\
    \ 0) edges.push_back(e);\n        for (auto& f : G[e.to]) {\n            pq.emplace(e.to,\
    \ f.to, f.weight);\n        }\n    }\n    return {weight, edges};\n}\n\n/*\n *\
    \ Boruvka's Algorithm\n */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>>\
    \ boruvka(std::vector<Edge<T>> G, int V) {\n    UnionFind uf(V);\n    T weight\
    \ = 0;\n    std::vector<Edge<T>> edges;\n    while (uf.size(0) < V) {\n      \
    \  std::vector<Edge<T>> cheapest(V, {-1, -1, std::numeric_limits<T>::max()});\n\
    \        for (auto& e : G) {\n            if (!uf.same(e.from, e.to)) {\n    \
    \            int u = uf.find(e.from);\n                int v = uf.find(e.to);\n\
    \                if (e.weight < cheapest[u].weight) cheapest[u] = e;\n       \
    \         if (e.weight < cheapest[v].weight) cheapest[v] = e;\n            }\n\
    \        }\n        for (auto& e : cheapest) {\n            if (e.from != -1 &&\
    \ !uf.same(e.from, e.to)) {\n                uf.unite(e.from, e.to);\n       \
    \         weight += e.weight;\n                edges.push_back(e);\n         \
    \   }\n        }\n    }\n    return {weight, edges};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n#include \"edge.cpp\"\n#include \"../data-structure/unionfind/union_find.cpp\"\
    \n\n/*\n * Kruskal's Algorithm\n */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>>\
    \ kruskal(std::vector<Edge<T>> G, int V) {\n    std::sort(G.begin(), G.end(),\
    \ [](const auto& e1, const auto& e2) {\n        return e1.weight < e2.weight;\n\
    \    });\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>> edges;\n\
    \    for (auto& e : G) {\n        if (!uf.same(e.from, e.to)) {\n            uf.unite(e.from,\
    \ e.to);\n            weight += e.weight;\n            edges.push_back(e);\n \
    \       }\n    }\n    return {weight, edges};\n}\n\n/*\n * Prim's Algorithm\n\
    \ */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto& e1,\
    \ const auto& e2) { return e1.weight > e2.weight; };\n    std::priority_queue<Edge<T>,\
    \ std::vector<Edge<T>>, decltype(cmp)> pq(cmp);\n    pq.emplace(0, 0, 0);\n  \
    \  T weight = 0;\n    std::vector<Edge<T>> edges;\n    while (!pq.empty()) {\n\
    \        auto e = pq.top();\n        pq.pop();\n        if (used[e.to]) continue;\n\
    \        used[e.to] = true;\n        weight += e.weight;\n        if (e.to !=\
    \ 0) edges.push_back(e);\n        for (auto& f : G[e.to]) {\n            pq.emplace(e.to,\
    \ f.to, f.weight);\n        }\n    }\n    return {weight, edges};\n}\n\n/*\n *\
    \ Boruvka's Algorithm\n */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>>\
    \ boruvka(std::vector<Edge<T>> G, int V) {\n    UnionFind uf(V);\n    T weight\
    \ = 0;\n    std::vector<Edge<T>> edges;\n    while (uf.size(0) < V) {\n      \
    \  std::vector<Edge<T>> cheapest(V, {-1, -1, std::numeric_limits<T>::max()});\n\
    \        for (auto& e : G) {\n            if (!uf.same(e.from, e.to)) {\n    \
    \            int u = uf.find(e.from);\n                int v = uf.find(e.to);\n\
    \                if (e.weight < cheapest[u].weight) cheapest[u] = e;\n       \
    \         if (e.weight < cheapest[v].weight) cheapest[v] = e;\n            }\n\
    \        }\n        for (auto& e : cheapest) {\n            if (e.from != -1 &&\
    \ !uf.same(e.from, e.to)) {\n                uf.unite(e.from, e.to);\n       \
    \         weight += e.weight;\n                edges.push_back(e);\n         \
    \   }\n        }\n    }\n    return {weight, edges};\n}"
  dependsOn:
  - graph/edge.cpp
  - data-structure/unionfind/union_find.cpp
  isVerificationFile: false
  path: graph/mst.cpp
  requiredBy: []
  timestamp: '2021-01-17 23:34:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.prim.test.cpp
  - test/aoj/GRL_2_A.boruvka.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
documentation_of: graph/mst.cpp
layout: document
title: Minimum Spanning Tree Algorithms
---

## Description

最小全域木を求めるアルゴリズム詰め合わせ

## Kruskal's Algorithm

Kruskal のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> kruskal(vector<Edge<T>> G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\lg V)$

## Prim's Algorithm

Prim のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> prim(vector<vector<Edge<T>>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\lg V)$

## Borůvka's Algorithm

Borůvka のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> boruvka(vector<Edge<T>> G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\lg V)$