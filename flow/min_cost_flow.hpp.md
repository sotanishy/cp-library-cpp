---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/min_cost_flow.hpp\"\n#include <algorithm>\n#include\
    \ <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate <typename Cap, typename Cost>\nclass MinCostFlow {\n  \
    \ public:\n    MinCostFlow() = default;\n    explicit MinCostFlow(int V) : V(V),\
    \ G(V), add(0) {}\n\n    void add_edge(int u, int v, Cap cap, Cost cost) {\n \
    \       G[u].emplace_back(v, cap, cost, (int)G[v].size());\n        G[v].emplace_back(u,\
    \ 0, -cost, (int)G[u].size() - 1);\n    }\n\n    void add_edge(int u, int v, Cap\
    \ lb, Cap ub, Cost cost) {\n        add_edge(u, v, ub - lb, cost);\n        add_edge(u,\
    \ v, lb, cost - M);\n        add += M * lb;\n    }\n\n    Cost min_cost_flow(int\
    \ s, int t, Cap f, bool arbitrary = false) {\n        Cost ret = add;\n      \
    \  std::vector<Cost> dist(V);\n        std::vector<int> prevv(V), preve(V);\n\
    \        using P = std::pair<Cost, int>;\n        std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> pq;\n\n        auto h = calculate_initial_potential(s);\n\n\
    \        while (f > 0) {\n            // update h using dijkstra\n           \
    \ std::ranges::fill(dist, INF);\n            dist[s] = 0;\n            pq.emplace(0,\
    \ s);\n            while (!pq.empty()) {\n                auto [d, v] = pq.top();\n\
    \                pq.pop();\n                if (dist[v] < d) continue;\n     \
    \           for (int i = 0; i < (int)G[v].size(); ++i) {\n                   \
    \ Edge& e = G[v][i];\n                    Cost ndist = dist[v] + e.cost + h[v]\
    \ - h[e.to];\n                    if (e.cap > 0 && dist[e.to] > ndist) {\n   \
    \                     dist[e.to] = ndist;\n                        prevv[e.to]\
    \ = v;\n                        preve[e.to] = i;\n                        pq.emplace(dist[e.to],\
    \ e.to);\n                    }\n                }\n            }\n\n        \
    \    if (!arbitrary && dist[t] == INF) return -1;\n            for (int v = 0;\
    \ v < V; ++v) h[v] += dist[v];\n\n            if (arbitrary && h[t] >= 0) break;\n\
    \n            Cap d = f;\n            for (int v = t; v != s; v = prevv[v]) {\n\
    \                d = std::min(d, G[prevv[v]][preve[v]].cap);\n            }\n\
    \            f -= d;\n            ret += d * h[t];\n            for (int v = t;\
    \ v != s; v = prevv[v]) {\n                Edge& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n        }\n        return ret;\n    }\n\n   private:\n    struct Edge\
    \ {\n        int to;\n        Cap cap;\n        Cost cost;\n        int rev;\n\
    \        Edge(int to, Cap cap, Cost cost, int rev)\n            : to(to), cap(cap),\
    \ cost(cost), rev(rev) {}\n    };\n\n    static constexpr Cost INF = std::numeric_limits<Cost>::max()\
    \ / 2;\n    // large constant used for minimum flow requirement for edges\n  \
    \  static constexpr Cost M = INF / 1e9;\n\n    int V;\n    std::vector<std::vector<Edge>>\
    \ G;\n    Cost add;\n\n    std::vector<Cost> calculate_initial_potential(int s)\
    \ {\n        std::vector<Cost> h(V);\n        // if all costs are nonnegative,\
    \ then do nothing\n        return h;\n\n        // if there is a negative edge,\n\
    \        // use Bellman-Ford or topological sort and a DP (for DAG)\n        //\
    \ std::fill(h.begin(), h.end(), INF);\n        // h[s] = 0;\n        // for (int\
    \ i = 0; i < V - 1; ++i) {\n        //     for (int v = 0; v < V; ++v) {\n   \
    \     //         for (auto& e : G[v]) {\n        //             if (e.cap > 0\
    \ && h[v] != INF && h[e.to] > h[v] + e.cost)\n        //             {\n     \
    \   //                 h[e.to] = h[v] + e.cost;\n        //             }\n  \
    \      //         }\n        //     }\n        // }\n\n        // return h;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ Cap, typename Cost>\nclass MinCostFlow {\n   public:\n    MinCostFlow() = default;\n\
    \    explicit MinCostFlow(int V) : V(V), G(V), add(0) {}\n\n    void add_edge(int\
    \ u, int v, Cap cap, Cost cost) {\n        G[u].emplace_back(v, cap, cost, (int)G[v].size());\n\
    \        G[v].emplace_back(u, 0, -cost, (int)G[u].size() - 1);\n    }\n\n    void\
    \ add_edge(int u, int v, Cap lb, Cap ub, Cost cost) {\n        add_edge(u, v,\
    \ ub - lb, cost);\n        add_edge(u, v, lb, cost - M);\n        add += M * lb;\n\
    \    }\n\n    Cost min_cost_flow(int s, int t, Cap f, bool arbitrary = false)\
    \ {\n        Cost ret = add;\n        std::vector<Cost> dist(V);\n        std::vector<int>\
    \ prevv(V), preve(V);\n        using P = std::pair<Cost, int>;\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n\n        auto h = calculate_initial_potential(s);\n\
    \n        while (f > 0) {\n            // update h using dijkstra\n          \
    \  std::ranges::fill(dist, INF);\n            dist[s] = 0;\n            pq.emplace(0,\
    \ s);\n            while (!pq.empty()) {\n                auto [d, v] = pq.top();\n\
    \                pq.pop();\n                if (dist[v] < d) continue;\n     \
    \           for (int i = 0; i < (int)G[v].size(); ++i) {\n                   \
    \ Edge& e = G[v][i];\n                    Cost ndist = dist[v] + e.cost + h[v]\
    \ - h[e.to];\n                    if (e.cap > 0 && dist[e.to] > ndist) {\n   \
    \                     dist[e.to] = ndist;\n                        prevv[e.to]\
    \ = v;\n                        preve[e.to] = i;\n                        pq.emplace(dist[e.to],\
    \ e.to);\n                    }\n                }\n            }\n\n        \
    \    if (!arbitrary && dist[t] == INF) return -1;\n            for (int v = 0;\
    \ v < V; ++v) h[v] += dist[v];\n\n            if (arbitrary && h[t] >= 0) break;\n\
    \n            Cap d = f;\n            for (int v = t; v != s; v = prevv[v]) {\n\
    \                d = std::min(d, G[prevv[v]][preve[v]].cap);\n            }\n\
    \            f -= d;\n            ret += d * h[t];\n            for (int v = t;\
    \ v != s; v = prevv[v]) {\n                Edge& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n        }\n        return ret;\n    }\n\n   private:\n    struct Edge\
    \ {\n        int to;\n        Cap cap;\n        Cost cost;\n        int rev;\n\
    \        Edge(int to, Cap cap, Cost cost, int rev)\n            : to(to), cap(cap),\
    \ cost(cost), rev(rev) {}\n    };\n\n    static constexpr Cost INF = std::numeric_limits<Cost>::max()\
    \ / 2;\n    // large constant used for minimum flow requirement for edges\n  \
    \  static constexpr Cost M = INF / 1e9;\n\n    int V;\n    std::vector<std::vector<Edge>>\
    \ G;\n    Cost add;\n\n    std::vector<Cost> calculate_initial_potential(int s)\
    \ {\n        std::vector<Cost> h(V);\n        // if all costs are nonnegative,\
    \ then do nothing\n        return h;\n\n        // if there is a negative edge,\n\
    \        // use Bellman-Ford or topological sort and a DP (for DAG)\n        //\
    \ std::fill(h.begin(), h.end(), INF);\n        // h[s] = 0;\n        // for (int\
    \ i = 0; i < V - 1; ++i) {\n        //     for (int v = 0; v < V; ++v) {\n   \
    \     //         for (auto& e : G[v]) {\n        //             if (e.cap > 0\
    \ && h[v] != INF && h[e.to] > h[v] + e.cost)\n        //             {\n     \
    \   //                 h[e.to] = h[v] + e.cost;\n        //             }\n  \
    \      //         }\n        //     }\n        // }\n\n        // return h;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/min_cost_flow.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:08:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_B.test.cpp
documentation_of: flow/min_cost_flow.hpp
layout: document
title: Minimum Cost Flow
---

## Description

フローネットワークの最小費用流を求める．この実装では，primal-dual 法を用いている．

## Operations

- `MinCostFlow(int V)`
    - グラフを $V$ 頂点で初期化する
    - 時間計算量: $O(V)$
- `void add_edge(int u, int v, Cap cap, Cost cost)`
    - 容量 $cap$，コスト $cost$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `void add_edge(int u, int v, Cap lb, Cap ub, Cost cost)`
    - 最小流量 $lb$, 容量 $ub$，コスト $cost$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `Cost min_cost_flow(int s, int t, Cap f, bool arbitrary)`
    - 始点 $s$ から終点 $t$ への流量 $f$ の最小費用流を求める．`arbitrary == true` の場合，流量は $f$ 以下の任意の値とする．
    - 時間計算量: $O(fE\log V)$

## Note

このライブラリがそのまま使える場合は，すべての辺のコストが非負である普通の最小費用流のとき．以下，いろいろな状況での使い方を説明する．

- 負辺がある場合
    - ポテンシャルの初期値の計算に，負辺があっても動作する最短路アルゴリズムを用いる必要がある．Bellman-Ford algorithm を用いることができる．また，グラフがDAGである場合は，トポロジカルソートしてDPすることができる．`calculate_initial_potential()`という private メソッドを用意しているのでその中を自分で書き換える．
    - 蟻本に載っているテク（超頂点を作って頑張る）を用いて負辺を除去することもできる．
- 負閉路がある場合
    - Bellman-Ford algorithm で負閉路を見つけてそこに流せるだけ流しておけば良い．