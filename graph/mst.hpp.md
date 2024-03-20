---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/union_find.hpp
    title: Union Find
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan Minimum Spanning Tree
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
  - icon: ':heavy_check_mark:'
    path: test/yosupo/manhattanmst.test.cpp
    title: test/yosupo/manhattanmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/mst.hpp\"\n#include <algorithm>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\n#line 4 \"data-structure/unionfind/union_find.hpp\"\
    \n\nclass UnionFind {\n   public:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) { return find(x) ==\
    \ find(y); }\n\n    int size(int x) { return -data[find(x)]; }\n\n   private:\n\
    \    std::vector<int> data;\n};\n#line 8 \"graph/mst.hpp\"\n\ntemplate <typename\
    \ T>\nusing Edge = std::tuple<int, int, T>;\n\n/*\n * Kruskal's Algorithm\n */\n\
    template <typename T>\nstd::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>>\
    \ G, int V) {\n    std::ranges::sort(G, {}, [](auto& e) { return std::get<2>(e);\
    \ });\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>> edges;\n\
    \    for (auto& [u, v, w] : G) {\n        if (!uf.same(u, v)) {\n            uf.unite(u,\
    \ v);\n            weight += w;\n            edges.push_back({u, v, w});\n   \
    \     }\n    }\n    return {weight, edges};\n}\n\n/*\n * Prim's Algorithm\n */\n\
    template <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(\n    const std::vector<std::vector<std::pair<int,\
    \ T>>>& G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto&\
    \ e1, const auto& e2) {\n        return std::get<2>(e1) > std::get<2>(e2);\n \
    \   };\n    std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)>\
    \ pq(cmp);\n    pq.emplace(0, 0, 0);\n    T weight = 0;\n    std::vector<Edge<T>>\
    \ edges;\n    while (!pq.empty()) {\n        auto [p, v, w] = pq.top();\n    \
    \    pq.pop();\n        if (used[v]) continue;\n        used[v] = true;\n    \
    \    weight += w;\n        if (v != 0) edges.push_back({p, v, w});\n        for\
    \ (auto& [u, w2] : G[v]) {\n            pq.emplace(v, u, w2);\n        }\n   \
    \ }\n    return {weight, edges};\n}\n\n/*\n * Boruvka's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> boruvka(std::vector<Edge<T>>\
    \ G, int V) {\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>>\
    \ edges;\n    while (uf.size(0) < V) {\n        std::vector<Edge<T>> cheapest(V,\n\
    \                                      {-1, -1, std::numeric_limits<T>::max()});\n\
    \        for (auto [u, v, w] : G) {\n            if (!uf.same(u, v)) {\n     \
    \           u = uf.find(u);\n                v = uf.find(v);\n               \
    \ if (w < std::get<2>(cheapest[u])) cheapest[u] = {u, v, w};\n               \
    \ if (w < std::get<2>(cheapest[v])) cheapest[v] = {u, v, w};\n            }\n\
    \        }\n        for (auto [u, v, w] : cheapest) {\n            if (u != -1\
    \ && !uf.same(u, v)) {\n                uf.unite(u, v);\n                weight\
    \ += w;\n                edges.push_back({u, v, w});\n            }\n        }\n\
    \    }\n    return {weight, edges};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\n#include \"../data-structure/unionfind/union_find.hpp\"\n\
    \ntemplate <typename T>\nusing Edge = std::tuple<int, int, T>;\n\n/*\n * Kruskal's\
    \ Algorithm\n */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>>\
    \ G, int V) {\n    std::ranges::sort(G, {}, [](auto& e) { return std::get<2>(e);\
    \ });\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>> edges;\n\
    \    for (auto& [u, v, w] : G) {\n        if (!uf.same(u, v)) {\n            uf.unite(u,\
    \ v);\n            weight += w;\n            edges.push_back({u, v, w});\n   \
    \     }\n    }\n    return {weight, edges};\n}\n\n/*\n * Prim's Algorithm\n */\n\
    template <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(\n    const std::vector<std::vector<std::pair<int,\
    \ T>>>& G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto&\
    \ e1, const auto& e2) {\n        return std::get<2>(e1) > std::get<2>(e2);\n \
    \   };\n    std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)>\
    \ pq(cmp);\n    pq.emplace(0, 0, 0);\n    T weight = 0;\n    std::vector<Edge<T>>\
    \ edges;\n    while (!pq.empty()) {\n        auto [p, v, w] = pq.top();\n    \
    \    pq.pop();\n        if (used[v]) continue;\n        used[v] = true;\n    \
    \    weight += w;\n        if (v != 0) edges.push_back({p, v, w});\n        for\
    \ (auto& [u, w2] : G[v]) {\n            pq.emplace(v, u, w2);\n        }\n   \
    \ }\n    return {weight, edges};\n}\n\n/*\n * Boruvka's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> boruvka(std::vector<Edge<T>>\
    \ G, int V) {\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>>\
    \ edges;\n    while (uf.size(0) < V) {\n        std::vector<Edge<T>> cheapest(V,\n\
    \                                      {-1, -1, std::numeric_limits<T>::max()});\n\
    \        for (auto [u, v, w] : G) {\n            if (!uf.same(u, v)) {\n     \
    \           u = uf.find(u);\n                v = uf.find(v);\n               \
    \ if (w < std::get<2>(cheapest[u])) cheapest[u] = {u, v, w};\n               \
    \ if (w < std::get<2>(cheapest[v])) cheapest[v] = {u, v, w};\n            }\n\
    \        }\n        for (auto [u, v, w] : cheapest) {\n            if (u != -1\
    \ && !uf.same(u, v)) {\n                uf.unite(u, v);\n                weight\
    \ += w;\n                edges.push_back({u, v, w});\n            }\n        }\n\
    \    }\n    return {weight, edges};\n}"
  dependsOn:
  - data-structure/unionfind/union_find.hpp
  isVerificationFile: false
  path: graph/mst.hpp
  requiredBy:
  - graph/manhattan_mst.hpp
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.prim.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/aoj/GRL_2_A.boruvka.test.cpp
  - test/yosupo/manhattanmst.test.cpp
documentation_of: graph/mst.hpp
layout: document
title: Minimum Spanning Tree Algorithms
---

## Description

最小全域木を求めるアルゴリズム詰め合わせ

## Kruskal's Algorithm

Kruskal のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> kruskal(vector<Edge<T>> G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\log V)$

## Prim's Algorithm

Prim のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> prim(vector<vector<Edge<T>>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\log V)$

## Borůvka's Algorithm

Borůvka のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> boruvka(vector<Edge<T>> G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\log V)$