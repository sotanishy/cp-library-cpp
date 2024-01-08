---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/shortest_path.hpp
    title: Shortest Path Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \\\n    \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 7 \"graph/shortest_path.hpp\"\n\n/*\n * Bellman-Ford\
    \ Algorithm\n */\ntemplate <typename T>\nstd::vector<T> bellman_ford(const std::vector<std::tuple<int,\
    \ int, T>>& G,\n                            int V, int s) {\n    constexpr T INF\
    \ = std::numeric_limits<T>::max();\n    std::vector<T> dist(V, INF);\n    dist[s]\
    \ = 0;\n    for (int i = 0; i < V; ++i) {\n        for (auto& [s, t, w] : G) {\n\
    \            if (dist[s] != INF && dist[t] > dist[s] + w) {\n                dist[t]\
    \ = dist[s] + w;\n                if (i == V - 1) return {};\n            }\n\
    \        }\n    }\n    return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n */\n\
    template <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>& dist)\
    \ {\n    const int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n     \
    \   for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n\
    \                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n}\n\n/*\n * Dijkstra's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::vector<T> dijkstra(const std::vector<std::vector<std::pair<int,\
    \ T>>>& G,\n                        int s) {\n    std::vector<T> dist(G.size(),\
    \ std::numeric_limits<T>::max());\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        auto [d, v] = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& [u,\
    \ w] : G[v]) {\n            if (dist[u] > d + w) {\n                dist[u] =\
    \ d + w;\n                pq.emplace(dist[u], u);\n            }\n        }\n\
    \    }\n\n    return dist;\n}\n\ntemplate <typename T>\nstd::pair<std::vector<T>,\
    \ std::vector<int>> shortest_path_tree(\n    const std::vector<std::vector<std::pair<int,\
    \ T>>>& G, int s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n\
    \    std::vector<int> par(G.size(), -1);\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        auto [d, v] = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& [u,\
    \ w] : G[v]) {\n            if (dist[u] > d + w) {\n                dist[u] =\
    \ d + w;\n                par[u] = v;\n                pq.emplace(dist[u], u);\n\
    \            }\n        }\n    }\n\n    return {dist, par};\n}\n\n/*\n * Breadth-First\
    \ Search\n */\nstd::vector<int> bfs(const std::vector<std::vector<int>>& G, int\
    \ s) {\n    std::vector<int> dist(G.size(), -1);\n    dist[s] = 0;\n    std::queue<int>\
    \ que;\n    que.push(s);\n\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (int u : G[v]) {\n            if (dist[u] ==\
    \ -1) {\n                dist[u] = dist[v] + 1;\n                que.push(u);\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\n/*\n * Dial's Algorithm\n\
    \ */\nstd::vector<int> dial(const std::vector<std::vector<std::pair<int, int>>>&\
    \ G,\n                      int s, int w) {\n    std::vector<int> dist(G.size(),\
    \ std::numeric_limits<int>::max());\n    dist[s] = 0;\n    std::vector<std::vector<int>>\
    \ buckets(w * G.size(), std::vector<int>());\n    buckets[0].push_back(s);\n\n\
    \    for (int d = 0; d < (int)buckets.size(); ++d) {\n        while (!buckets[d].empty())\
    \ {\n            int v = buckets[d].back();\n            buckets[d].pop_back();\n\
    \            if (dist[v] < d) continue;\n            for (auto& [u, w] : G[v])\
    \ {\n                if (dist[u] > d + w) {\n                    dist[u] = d +\
    \ w;\n                    buckets[dist[u]].push_back(u);\n                }\n\
    \            }\n        }\n    }\n    return dist;\n}\n#line 7 \"test/aoj/GRL_1_B.test.cpp\"\
    \nusing namespace std;\n\nconst int INF = 1e9;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<tuple<int,\
    \ int, int>> G;\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n   \
    \     cin >> s >> t >> d;\n        G.push_back({s, t, d});\n    }\n    auto dist\
    \ = bellman_ford(G, V, r);\n    if (dist.size() == 0)\n        cout << \"NEGATIVE\
    \ CYCLE\\n\";\n    else {\n        for (int i = 0; i < V; i++) {\n           \
    \ if (dist[i] < INF)\n                cout << dist[i] << \"\\n\";\n          \
    \  else\n                cout << \"INF\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../graph/shortest_path.hpp\"\nusing\
    \ namespace std;\n\nconst int INF = 1e9;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<tuple<int,\
    \ int, int>> G;\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n   \
    \     cin >> s >> t >> d;\n        G.push_back({s, t, d});\n    }\n    auto dist\
    \ = bellman_ford(G, V, r);\n    if (dist.size() == 0)\n        cout << \"NEGATIVE\
    \ CYCLE\\n\";\n    else {\n        for (int i = 0; i < V; i++) {\n           \
    \ if (dist[i] < INF)\n                cout << dist[i] << \"\\n\";\n          \
    \  else\n                cout << \"INF\\n\";\n        }\n    }\n}"
  dependsOn:
  - graph/shortest_path.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
