---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/min_cost_flow.cpp\"\n#include <algorithm>\n#include\
    \ <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate <typename Cap, typename Cost>\nclass MinCostFlow {\npublic:\n\
    \    MinCostFlow() = default;\n    explicit MinCostFlow(int V) : V(V), G(V) {}\n\
    \n    void add_edge(int u, int v, Cap cap, Cost cost) {\n        G[u].emplace_back(v,\
    \ cap, cost, (int) G[v].size());\n        G[v].emplace_back(u, 0, -cost, (int)\
    \ G[u].size() - 1);\n    }\n\n    Cost min_cost_flow(int s, int t, Cap f) {\n\
    \        int ret = 0;\n        std::vector<Cost> dist(V), h(V);\n        std::vector<int>\
    \ prevv(V), preve(V);\n        using P = std::pair<Cost, int>;\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n\n        while (f > 0) {\n          \
    \  // update h using dijkstra\n            std::fill(dist.begin(), dist.end(),\
    \ INF);\n            dist[s] = 0;\n            pq.emplace(0, s);\n           \
    \ while (!pq.empty()) {\n                Cost d;\n                int v;\n   \
    \             std::tie(d, v) = pq.top();\n                pq.pop();\n        \
    \        if (dist[v] < d) continue;\n                for (int i = 0; i < (int)\
    \ G[v].size(); ++i) {\n                    Edge& e = G[v][i];\n              \
    \      Cost ndist = dist[v] + e.cost + h[v] - h[e.to];\n                    if\
    \ (e.cap > 0 && dist[e.to] > ndist) {\n                        dist[e.to] = ndist;\n\
    \                        prevv[e.to] = v;\n                        preve[e.to]\
    \ = i;\n                        pq.emplace(dist[e.to], e.to);\n              \
    \      }\n                }\n            }\n\n            if (dist[t] == INF)\
    \ return -1;\n            for (int v = 0; v < V; ++v) h[v] += dist[v];\n\n   \
    \         Cap m = f;\n            for (int v = t; v != s; v = prevv[v]) {\n  \
    \              m = std::min(m, G[prevv[v]][preve[v]].cap);\n            }\n  \
    \          f -= m;\n            ret += m * h[t];\n            for (int v = t;\
    \ v != s; v = prevv[v]) {\n                Edge& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= m;\n                G[v][e.rev].cap += m;\n        \
    \    }\n        }\n        return ret;\n    }\n\nprivate:\n    struct Edge {\n\
    \        int to;\n        Cap cap;\n        Cost cost;\n        int rev;\n   \
    \     Edge(int to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost),\
    \ rev(rev) {}\n    };\n\n    static constexpr Cost INF = std::numeric_limits<Cost>::max()\
    \ / 2;\n\n    int V;\n    std::vector<std::vector<Edge>> G;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ Cap, typename Cost>\nclass MinCostFlow {\npublic:\n    MinCostFlow() = default;\n\
    \    explicit MinCostFlow(int V) : V(V), G(V) {}\n\n    void add_edge(int u, int\
    \ v, Cap cap, Cost cost) {\n        G[u].emplace_back(v, cap, cost, (int) G[v].size());\n\
    \        G[v].emplace_back(u, 0, -cost, (int) G[u].size() - 1);\n    }\n\n   \
    \ Cost min_cost_flow(int s, int t, Cap f) {\n        int ret = 0;\n        std::vector<Cost>\
    \ dist(V), h(V);\n        std::vector<int> prevv(V), preve(V);\n        using\
    \ P = std::pair<Cost, int>;\n        std::priority_queue<P, std::vector<P>, std::greater<P>>\
    \ pq;\n\n        while (f > 0) {\n            // update h using dijkstra\n   \
    \         std::fill(dist.begin(), dist.end(), INF);\n            dist[s] = 0;\n\
    \            pq.emplace(0, s);\n            while (!pq.empty()) {\n          \
    \      Cost d;\n                int v;\n                std::tie(d, v) = pq.top();\n\
    \                pq.pop();\n                if (dist[v] < d) continue;\n     \
    \           for (int i = 0; i < (int) G[v].size(); ++i) {\n                  \
    \  Edge& e = G[v][i];\n                    Cost ndist = dist[v] + e.cost + h[v]\
    \ - h[e.to];\n                    if (e.cap > 0 && dist[e.to] > ndist) {\n   \
    \                     dist[e.to] = ndist;\n                        prevv[e.to]\
    \ = v;\n                        preve[e.to] = i;\n                        pq.emplace(dist[e.to],\
    \ e.to);\n                    }\n                }\n            }\n\n        \
    \    if (dist[t] == INF) return -1;\n            for (int v = 0; v < V; ++v) h[v]\
    \ += dist[v];\n\n            Cap m = f;\n            for (int v = t; v != s; v\
    \ = prevv[v]) {\n                m = std::min(m, G[prevv[v]][preve[v]].cap);\n\
    \            }\n            f -= m;\n            ret += m * h[t];\n          \
    \  for (int v = t; v != s; v = prevv[v]) {\n                Edge& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= m;\n                G[v][e.rev].cap += m;\n        \
    \    }\n        }\n        return ret;\n    }\n\nprivate:\n    struct Edge {\n\
    \        int to;\n        Cap cap;\n        Cost cost;\n        int rev;\n   \
    \     Edge(int to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost),\
    \ rev(rev) {}\n    };\n\n    static constexpr Cost INF = std::numeric_limits<Cost>::max()\
    \ / 2;\n\n    int V;\n    std::vector<std::vector<Edge>> G;\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/min_cost_flow.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_B.test.cpp
documentation_of: flow/min_cost_flow.cpp
layout: document
title: Minimum Cost Flow
---

## Description

フローネットワークの最小費用流を求める．

## Operations

- `MinCostFlow(int V)`
    - グラフを $V$ 頂点で初期化する
    - 時間計算量: $O(V)$
- `void add_edge(int u, int v, Cap cap, Cost cost)`
    - 容量 $cap$，コスト $cost$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `Cost min_cost_flow(int s, int t, Cap f)`
    - 始点 $s$ から終点 $t$ への流量 $f$ の最小費用流を求める
    - 時間計算量: $O(fE\log V)$