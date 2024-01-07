---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.dinic.test.cpp
    title: test/aoj/GRL_6_A.dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/dinic.hpp\"\n#include <algorithm>\n#include <limits>\n\
    #include <queue>\n#include <set>\n#include <stack>\n#include <vector>\n\ntemplate\
    \ <typename T>\nclass Dinic {\n   public:\n    Dinic() = default;\n    explicit\
    \ Dinic(int V) : G(V), level(V), iter(V) {}\n\n    void add_edge(int u, int v,\
    \ T cap) {\n        G[u].push_back({v, (int)G[v].size(), cap});\n        G[v].push_back({u,\
    \ (int)G[u].size() - 1, 0});\n    }\n\n    T max_flow(int s, int t) {\n      \
    \  T flow = 0;\n        while (bfs(s, t)) {\n            std::ranges::fill(iter,\
    \ 0);\n            T f = 0;\n            while ((f = dfs(s, t, INF)) > 0) flow\
    \ += f;\n        }\n        return flow;\n    }\n\n    std::set<int> min_cut(int\
    \ s) {\n        std::stack<int> st;\n        std::set<int> visited;\n        st.push(s);\n\
    \        visited.insert(s);\n        while (!st.empty()) {\n            int v\
    \ = st.top();\n            st.pop();\n            for (auto& e : G[v]) {\n   \
    \             if (e.cap > 0 && !visited.contains(e.to)) {\n                  \
    \  visited.insert(e.to);\n                    st.push(e.to);\n               \
    \ }\n            }\n        }\n        return visited;\n    }\n\n   private:\n\
    \    struct Edge {\n        int to, rev;\n        T cap;\n    };\n\n    static\
    \ constexpr T INF = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>>\
    \ G;\n    std::vector<int> level, iter;\n\n    bool bfs(int s, int t) {\n    \
    \    std::ranges::fill(level, -1);\n        level[s] = 0;\n        std::queue<int>\
    \ q;\n        q.push(s);\n        while (!q.empty() && level[t] == -1) {\n   \
    \         int v = q.front();\n            q.pop();\n            for (auto& e :\
    \ G[v]) {\n                if (e.cap > 0 && level[e.to] == -1) {\n           \
    \         level[e.to] = level[v] + 1;\n                    q.push(e.to);\n   \
    \             }\n            }\n        }\n        return level[t] != -1;\n  \
    \  }\n\n    T dfs(int v, int t, T f) {\n        if (v == t) return f;\n      \
    \  for (int& i = iter[v]; i < (int)G[v].size(); ++i) {\n            Edge& e =\
    \ G[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n         \
    \       T d = dfs(e.to, t, std::min(f, e.cap));\n                if (d > 0) {\n\
    \                    e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \        return 0;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <queue>\n\
    #include <set>\n#include <stack>\n#include <vector>\n\ntemplate <typename T>\n\
    class Dinic {\n   public:\n    Dinic() = default;\n    explicit Dinic(int V) :\
    \ G(V), level(V), iter(V) {}\n\n    void add_edge(int u, int v, T cap) {\n   \
    \     G[u].push_back({v, (int)G[v].size(), cap});\n        G[v].push_back({u,\
    \ (int)G[u].size() - 1, 0});\n    }\n\n    T max_flow(int s, int t) {\n      \
    \  T flow = 0;\n        while (bfs(s, t)) {\n            std::ranges::fill(iter,\
    \ 0);\n            T f = 0;\n            while ((f = dfs(s, t, INF)) > 0) flow\
    \ += f;\n        }\n        return flow;\n    }\n\n    std::set<int> min_cut(int\
    \ s) {\n        std::stack<int> st;\n        std::set<int> visited;\n        st.push(s);\n\
    \        visited.insert(s);\n        while (!st.empty()) {\n            int v\
    \ = st.top();\n            st.pop();\n            for (auto& e : G[v]) {\n   \
    \             if (e.cap > 0 && !visited.contains(e.to)) {\n                  \
    \  visited.insert(e.to);\n                    st.push(e.to);\n               \
    \ }\n            }\n        }\n        return visited;\n    }\n\n   private:\n\
    \    struct Edge {\n        int to, rev;\n        T cap;\n    };\n\n    static\
    \ constexpr T INF = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>>\
    \ G;\n    std::vector<int> level, iter;\n\n    bool bfs(int s, int t) {\n    \
    \    std::ranges::fill(level, -1);\n        level[s] = 0;\n        std::queue<int>\
    \ q;\n        q.push(s);\n        while (!q.empty() && level[t] == -1) {\n   \
    \         int v = q.front();\n            q.pop();\n            for (auto& e :\
    \ G[v]) {\n                if (e.cap > 0 && level[e.to] == -1) {\n           \
    \         level[e.to] = level[v] + 1;\n                    q.push(e.to);\n   \
    \             }\n            }\n        }\n        return level[t] != -1;\n  \
    \  }\n\n    T dfs(int v, int t, T f) {\n        if (v == t) return f;\n      \
    \  for (int& i = iter[v]; i < (int)G[v].size(); ++i) {\n            Edge& e =\
    \ G[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n         \
    \       T d = dfs(e.to, t, std::min(f, e.cap));\n                if (d > 0) {\n\
    \                    e.cap -= d;\n                    G[e.to][e.rev].cap += d;\n\
    \                    return d;\n                }\n            }\n        }\n\
    \        return 0;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/dinic.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:08:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.dinic.test.cpp
documentation_of: flow/dinic.hpp
layout: document
title: Dinic's Algorithm
---

## Description

Dinic のアルゴリズムは，フローネットワークの最大流を求めるアルゴリズムである．始点からの最短距離を BFS で計算し，残余グラフの増加パスを DFS で見つけ，そのパスにフローを流すことを繰り返す．

## Operations

- `Dinic(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$
- `void add_edge(int u, int v, T cap)`
    - 容量 $cap$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `T max_flow(int s, int t)`
    - 始点 $s$ から終点 $t$ への最大流を求める
    - 時間計算量: $O(V^2E)$

## Reference

- [Dinic 法とその時間計算量 - みさわめも](https://misawa.github.io/others/flow/dinic_time_complexity.html)