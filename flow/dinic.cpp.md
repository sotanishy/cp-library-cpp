---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.dinic.test.cpp
    title: test/aoj/GRL_6_A.dinic.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/dinic.md
    document_title: Dinic's Algorithm
    links: []
  bundledCode: "#line 2 \"flow/dinic.cpp\"\n#include <algorithm>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\n/*\n * @brief Dinic's Algorithm\n * @docs\
    \ docs/flow/dinic.md\n */\ntemplate <typename T>\nclass Dinic {\npublic:\n   \
    \ Dinic() = default;\n    explicit Dinic(int V) : G(V), level(V), iter(V) {}\n\
    \n    void add_edge(int u, int v, T cap) {\n        G[u].emplace_back(v, cap,\
    \ (int) G[v].size());\n        G[v].emplace_back(u, 0, (int) G[u].size() - 1);\n\
    \    }\n\n    T max_flow(int s, int t) {\n        T flow = 0;\n        while (bfs(s,\
    \ t)) {\n            std::fill(iter.begin(), iter.end(), 0);\n            T f\
    \ = 0;\n            while ((f = dfs(s, t, INF)) > 0) flow += f;\n        }\n \
    \       return flow;\n    }\n\nprivate:\n    struct Edge {\n        int to;\n\
    \        T cap;\n        int rev;\n        Edge(int to, T cap, int rev) : to(to),\
    \ cap(cap), rev(rev) {}\n    };\n\n    static constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n\n    std::vector<std::vector<Edge>> G;\n    std::vector<int> level, iter;\n\
    \n    bool bfs(int s, int t) {\n        std::fill(level.begin(), level.end(),\
    \ -1);\n        level[s] = 0;\n        std::queue<int> q;\n        q.push(s);\n\
    \        while (!q.empty() && level[t] == -1) {\n            int v = q.front();\n\
    \            q.pop();\n            for (auto& e : G[v]) {\n                if\
    \ (e.cap > 0 && level[e.to] == -1) {\n                    level[e.to] = level[v]\
    \ + 1;\n                    q.push(e.to);\n                }\n            }\n\
    \        }\n        return level[t] != -1;\n    }\n\n    T dfs(int v, int t, T\
    \ f) {\n        if (v == t) return f;\n        for (int& i = iter[v]; i < (int)\
    \ G[v].size(); ++i) {\n            Edge& e = G[v][i];\n            if (e.cap >\
    \ 0 && level[v] < level[e.to]) {\n                T d = dfs(e.to, t, std::min(f,\
    \ e.cap));\n                if (d > 0) {\n                    e.cap -= d;\n  \
    \                  G[e.to][e.rev].cap += d;\n                    return d;\n \
    \               }\n            }\n        }\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\n/*\n * @brief Dinic's Algorithm\n * @docs docs/flow/dinic.md\n\
    \ */\ntemplate <typename T>\nclass Dinic {\npublic:\n    Dinic() = default;\n\
    \    explicit Dinic(int V) : G(V), level(V), iter(V) {}\n\n    void add_edge(int\
    \ u, int v, T cap) {\n        G[u].emplace_back(v, cap, (int) G[v].size());\n\
    \        G[v].emplace_back(u, 0, (int) G[u].size() - 1);\n    }\n\n    T max_flow(int\
    \ s, int t) {\n        T flow = 0;\n        while (bfs(s, t)) {\n            std::fill(iter.begin(),\
    \ iter.end(), 0);\n            T f = 0;\n            while ((f = dfs(s, t, INF))\
    \ > 0) flow += f;\n        }\n        return flow;\n    }\n\nprivate:\n    struct\
    \ Edge {\n        int to;\n        T cap;\n        int rev;\n        Edge(int\
    \ to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\n    static constexpr\
    \ T INF = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>>\
    \ G;\n    std::vector<int> level, iter;\n\n    bool bfs(int s, int t) {\n    \
    \    std::fill(level.begin(), level.end(), -1);\n        level[s] = 0;\n     \
    \   std::queue<int> q;\n        q.push(s);\n        while (!q.empty() && level[t]\
    \ == -1) {\n            int v = q.front();\n            q.pop();\n           \
    \ for (auto& e : G[v]) {\n                if (e.cap > 0 && level[e.to] == -1)\
    \ {\n                    level[e.to] = level[v] + 1;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n        return level[t] != -1;\n\
    \    }\n\n    T dfs(int v, int t, T f) {\n        if (v == t) return f;\n    \
    \    for (int& i = iter[v]; i < (int) G[v].size(); ++i) {\n            Edge& e\
    \ = G[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n       \
    \         T d = dfs(e.to, t, std::min(f, e.cap));\n                if (d > 0)\
    \ {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap +=\
    \ d;\n                    return d;\n                }\n            }\n      \
    \  }\n        return 0;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/dinic.cpp
  requiredBy: []
  timestamp: '2020-10-24 15:32:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.dinic.test.cpp
documentation_of: flow/dinic.cpp
layout: document
redirect_from:
- /library/flow/dinic.cpp
- /library/flow/dinic.cpp.html
title: Dinic's Algorithm
---
# Dinic's Algorithm

Dinic のアルゴリズムは，フローネットワークの最大流を求めるアルゴリズムである．始点からの最短距離を BFS で計算し，残余グラフの増加パスを DFS で見つけ，そのパスにフローを流すことを繰り返す．

## Template parameters

- `T`
    - 容量の型

## Construcor

- `Dinic(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$

## Member functions

- `void add_edge(int u, int v, T cap)`
    - 容量 $cap$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `T max_flow(int s, int t)`
    - 始点 $s$ から終点 $t$ への最大流を求める
    - 時間計算量: $O(V^2E)$