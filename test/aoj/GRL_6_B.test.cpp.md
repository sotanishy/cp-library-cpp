---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/min_cost_flow.cpp
    title: Minimum Cost Flow
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#line 2 \"flow/min_cost_flow.cpp\"\n#include <algorithm>\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\n\
    template <typename Cap, typename Cost>\nclass MinCostFlow {\npublic:\n    MinCostFlow()\
    \ = default;\n    explicit MinCostFlow(int V) : V(V), G(V) {}\n\n    void add_edge(int\
    \ u, int v, Cap cap, Cost cost) {\n        G[u].emplace_back(v, cap, cost, (int)\
    \ G[v].size());\n        G[v].emplace_back(u, 0, -cost, (int) G[u].size() - 1);\n\
    \    }\n\n    Cost min_cost_flow(int s, int t, Cap f) {\n        int ret = 0;\n\
    \        std::vector<Cost> dist(V);\n        std::vector<int> prevv(V), preve(V);\n\
    \        using P = std::pair<Cost, int>;\n        std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> pq;\n\n        auto h = calculate_initial_potential(s);\n\n\
    \        while (f > 0) {\n            // update h using dijkstra\n           \
    \ std::fill(dist.begin(), dist.end(), INF);\n            dist[s] = 0;\n      \
    \      pq.emplace(0, s);\n            while (!pq.empty()) {\n                Cost\
    \ d;\n                int v;\n                std::tie(d, v) = pq.top();\n   \
    \             pq.pop();\n                if (dist[v] < d) continue;\n        \
    \        for (int i = 0; i < (int) G[v].size(); ++i) {\n                    Edge&\
    \ e = G[v][i];\n                    Cost ndist = dist[v] + e.cost + h[v] - h[e.to];\n\
    \                    if (e.cap > 0 && dist[e.to] > ndist) {\n                \
    \        dist[e.to] = ndist;\n                        prevv[e.to] = v;\n     \
    \                   preve[e.to] = i;\n                        pq.emplace(dist[e.to],\
    \ e.to);\n                    }\n                }\n            }\n\n        \
    \    if (dist[t] == INF) return -1;  // if the amount of flow is arbitrary, comment\
    \ this out\n            for (int v = 0; v < V; ++v) h[v] += dist[v];\n\n     \
    \       // if (h[t] >= 0) break;  // if the amount of flow is arbitrary, uncomment\
    \ this\n\n            Cap d = f;\n            for (int v = t; v != s; v = prevv[v])\
    \ {\n                d = std::min(d, G[prevv[v]][preve[v]].cap);\n           \
    \ }\n            f -= d;\n            ret += d * h[t];\n            for (int v\
    \ = t; v != s; v = prevv[v]) {\n                Edge& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n        }\n        return ret;\n    }\n\nprivate:\n    struct Edge {\n\
    \        int to;\n        Cap cap;\n        Cost cost;\n        int rev;\n   \
    \     Edge(int to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost),\
    \ rev(rev) {}\n    };\n\n    static constexpr Cost INF = std::numeric_limits<Cost>::max()\
    \ / 2;\n\n    int V;\n    std::vector<std::vector<Edge>> G;\n\n\n    std::vector<Cost>\
    \ calculate_initial_potential(int s) {\n        std::vector<Cost> h(V);\n    \
    \    // if all costs are nonnegative, then do nothing\n        return h;\n\n \
    \       // if there is a negative edge,\n        // use Bellman-Ford or topological\
    \ sort and a DP (for DAG)\n        // std::fill(h.begin(), h.end(), INF);\n  \
    \      // h[s] = 0;\n        // for (int i = 0; i < V - 1; ++i) {\n        //\
    \     for (int v = 0; v < V; ++v) {\n        //         for (auto& e : G[v]) {\n\
    \        //             if (e.cap > 0 && h[v] != INF && h[e.to] > h[v] + e.cost)\
    \ {\n        //                 h[e.to] = h[v] + e.cost;\n        //         \
    \    }\n        //         }\n        //     }\n        // }\n        // return\
    \ h;\n    }\n};\n#line 4 \"test/aoj/GRL_6_B.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E, F;\n    cin >> V >> E >> F;\n    MinCostFlow<int,\
    \ int> mcf(V);\n    for (int i = 0; i < E; i++) {\n        int u, v, c, d;\n \
    \       cin >> u >> v >> c >> d;\n        mcf.add_edge(u, v, c, d);\n    }\n \
    \   cout << mcf.min_cost_flow(0, V - 1, F) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include \"../../flow/min_cost_flow.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E, F;\n    cin >> V >> E >> F;\n    MinCostFlow<int, int> mcf(V);\n\
    \    for (int i = 0; i < E; i++) {\n        int u, v, c, d;\n        cin >> u\
    \ >> v >> c >> d;\n        mcf.add_edge(u, v, c, d);\n    }\n    cout << mcf.min_cost_flow(0,\
    \ V - 1, F) << endl;\n}"
  dependsOn:
  - flow/min_cost_flow.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2021-10-30 12:57:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B.test.cpp
- /verify/test/aoj/GRL_6_B.test.cpp.html
title: test/aoj/GRL_6_B.test.cpp
---
