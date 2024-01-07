---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
    title: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/ford_fulkerson.hpp\"\n#include <algorithm>\n#include\
    \ <limits>\n#include <set>\n#include <stack>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass FordFulkerson {\n   public:\n    FordFulkerson() = default;\n    explicit\
    \ FordFulkerson(int n) : G(n), used(n) {}\n\n    void add_edge(int u, int v, T\
    \ cap) {\n        G[u].push_back({v, (int)G[v].size(), cap});\n        G[v].push_back({u,\
    \ (int)G[u].size() - 1, 0});\n    }\n\n    T max_flow(int s, int t) {\n      \
    \  T flow = 0;\n        while (true) {\n            std::ranges::fill(used, false);\n\
    \            T f = dfs(s, t, INF);\n            if (f == 0) return flow;\n   \
    \         flow += f;\n        }\n    }\n\n    std::set<int> min_cut(int s) {\n\
    \        std::stack<int> st;\n        std::set<int> visited;\n        st.push(s);\n\
    \        visited.insert(s);\n        while (!st.empty()) {\n            int v\
    \ = st.top();\n            st.pop();\n            for (auto& e : G[v]) {\n   \
    \             if (e.cap > 0 && !visited.count(e.to)) {\n                    visited.insert(e.to);\n\
    \                    st.push(e.to);\n                }\n            }\n      \
    \  }\n        return visited;\n    }\n\n   private:\n    struct Edge {\n     \
    \   int to, rev;\n        T cap;\n    };\n\n    const T INF = std::numeric_limits<T>::max()\
    \ / 2;\n\n    std::vector<std::vector<Edge>> G;\n    std::vector<bool> used;\n\
    \n    T dfs(int v, int t, T f) {\n        if (v == t) return f;\n        used[v]\
    \ = true;\n        for (auto& e : G[v]) {\n            if (!used[e.to] && e.cap\
    \ > 0) {\n                T d = dfs(e.to, t, std::min(f, e.cap));\n          \
    \      if (d > 0) {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <set>\n#include\
    \ <stack>\n#include <vector>\n\ntemplate <typename T>\nclass FordFulkerson {\n\
    \   public:\n    FordFulkerson() = default;\n    explicit FordFulkerson(int n)\
    \ : G(n), used(n) {}\n\n    void add_edge(int u, int v, T cap) {\n        G[u].push_back({v,\
    \ (int)G[v].size(), cap});\n        G[v].push_back({u, (int)G[u].size() - 1, 0});\n\
    \    }\n\n    T max_flow(int s, int t) {\n        T flow = 0;\n        while (true)\
    \ {\n            std::ranges::fill(used, false);\n            T f = dfs(s, t,\
    \ INF);\n            if (f == 0) return flow;\n            flow += f;\n      \
    \  }\n    }\n\n    std::set<int> min_cut(int s) {\n        std::stack<int> st;\n\
    \        std::set<int> visited;\n        st.push(s);\n        visited.insert(s);\n\
    \        while (!st.empty()) {\n            int v = st.top();\n            st.pop();\n\
    \            for (auto& e : G[v]) {\n                if (e.cap > 0 && !visited.count(e.to))\
    \ {\n                    visited.insert(e.to);\n                    st.push(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \n   private:\n    struct Edge {\n        int to, rev;\n        T cap;\n    };\n\
    \n    const T INF = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>>\
    \ G;\n    std::vector<bool> used;\n\n    T dfs(int v, int t, T f) {\n        if\
    \ (v == t) return f;\n        used[v] = true;\n        for (auto& e : G[v]) {\n\
    \            if (!used[e.to] && e.cap > 0) {\n                T d = dfs(e.to,\
    \ t, std::min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: flow/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:08:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_6_A.ford_fulkerson.test.cpp
documentation_of: flow/ford_fulkerson.hpp
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