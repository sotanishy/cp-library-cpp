---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
    title: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/ford_fulkerson.cpp\"\n#include <algorithm>\n#include\
    \ <limits>\n#include <vector>\n\ntemplate <typename T>\nclass FordFulkerson {\n\
    public:\n    FordFulkerson() = default;\n    explicit FordFulkerson(int n) : G(n),\
    \ used(n) {}\n\n    void add_edge(int u, int v, T cap) {\n        G[u].emplace_back(v,\
    \ cap, (int) G[v].size());\n        G[v].emplace_back(u, 0, (int) G[u].size()\
    \ - 1);\n    }\n\n    T max_flow(int s, int t) {\n        T flow = 0;\n      \
    \  while (true) {\n            std::fill(used.begin(), used.end(), false);\n \
    \           T f = dfs(s, t, INF);\n            if (f == 0) return flow;\n    \
    \        flow += f;\n        }\n    }\n\nprivate:\n    struct Edge {\n       \
    \ int to;\n        T cap;\n        int rev;\n        Edge(int to, T cap, int rev)\
    \ : to(to), cap(cap), rev(rev) {}\n    };\n\n    const T INF = std::numeric_limits<T>::max()\
    \ / 2;\n\n    std::vector<std::vector<Edge>> G;\n    std::vector<bool> used;\n\
    \n    T dfs(int v, int t, T f) {\n        if (v == t) return f;\n        used[v]\
    \ = true;\n        for (auto& e : G[v]) {\n            if (!used[e.to] && e.cap\
    \ > 0) {\n                T d = dfs(e.to, t, std::min(f, e.cap));\n          \
    \      if (d > 0) {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <vector>\n\
    \ntemplate <typename T>\nclass FordFulkerson {\npublic:\n    FordFulkerson() =\
    \ default;\n    explicit FordFulkerson(int n) : G(n), used(n) {}\n\n    void add_edge(int\
    \ u, int v, T cap) {\n        G[u].emplace_back(v, cap, (int) G[v].size());\n\
    \        G[v].emplace_back(u, 0, (int) G[u].size() - 1);\n    }\n\n    T max_flow(int\
    \ s, int t) {\n        T flow = 0;\n        while (true) {\n            std::fill(used.begin(),\
    \ used.end(), false);\n            T f = dfs(s, t, INF);\n            if (f ==\
    \ 0) return flow;\n            flow += f;\n        }\n    }\n\nprivate:\n    struct\
    \ Edge {\n        int to;\n        T cap;\n        int rev;\n        Edge(int\
    \ to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\n    const T INF\
    \ = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>> G;\n\
    \    std::vector<bool> used;\n\n    T dfs(int v, int t, T f) {\n        if (v\
    \ == t) return f;\n        used[v] = true;\n        for (auto& e : G[v]) {\n \
    \           if (!used[e.to] && e.cap > 0) {\n                T d = dfs(e.to, t,\
    \ std::min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: flow/ford_fulkerson.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.ford_fulkerson.test.cpp
documentation_of: flow/ford_fulkerson.cpp
layout: document
title: Ford-Fulkerson Algorithm
---

## Description

Ford-Fulkerson のアルゴリズムは，フローネットワークの最大流を求めるアルゴリズムである．残余グラフの増加パスを DFS で見つけ，そのパスにフローを流すことを繰り返す．

## Operations

- `FordFulkerson(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$
- `void add_edge(int u, int v, T cap)`
    - 容量 $cap$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `T max_flow(int s, int t)`
    - 始点 $s$ から終点 $t$ への最大流を求める
    - 時間計算量: $O(Ef)$