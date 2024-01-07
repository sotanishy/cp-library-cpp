---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path.cpp
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
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#line 2 \"graph/shortest_path.cpp\"\n#include <limits>\n#include <queue>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#line 2 \"graph/edge.cpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n \
    \   Edge() = default;\n    Edge(int to, T weight) : from(-1), to(to), weight(weight)\
    \ {}\n    Edge(int from, int to, T weight) : from(from), to(to), weight(weight)\
    \ {}\n};\n#line 9 \"graph/shortest_path.cpp\"\n\n/*\n * Bellman-Ford Algorithm\n\
    \ */\ntemplate <typename T>\nstd::vector<T> bellman_ford(const std::vector<Edge<T>>&\
    \ G, int V, int s) {\n    constexpr T INF = std::numeric_limits<T>::max();\n \
    \   std::vector<T> dist(V, INF);\n    dist[s] = 0;\n    for (int i = 0; i < V;\
    \ ++i) {\n        for (auto& e : G) {\n            if (dist[e.from] != INF &&\
    \ dist[e.to] > dist[e.from] + e.weight) {\n                dist[e.to] = dist[e.from]\
    \ + e.weight;\n                if (i == V - 1) return std::vector<T>();\n    \
    \        }\n        }\n    }\n    return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n\
    \ */\ntemplate <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>&\
    \ dist) {\n    int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n     \
    \   for (int i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n\
    \                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \            }\n        }\n    }\n}\n\n/*\n * Dijkstra's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>&\
    \ G, int s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n\
    \    dist[s] = 0;\n    using P = std::pair<T, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty())\
    \ {\n        T d;\n        int v;\n        std::tie(d, v) = pq.top();\n      \
    \  pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& e : G[v])\
    \ {\n            if (dist[e.to] > d + e.weight) {\n                dist[e.to]\
    \ = d + e.weight;\n                pq.emplace(dist[e.to], e.to);\n           \
    \ }\n        }\n    }\n\n    return dist;\n}\n\ntemplate <typename T>\nstd::pair<std::vector<T>,\
    \ std::vector<int>> shortest_path_tree(\n    const std::vector<std::vector<Edge<T>>>&\
    \ G, int s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n\
    \    std::vector<int> par(G.size(), -1);\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        T d;\n        int v;\n\
    \        std::tie(d, v) = pq.top();\n        pq.pop();\n        if (dist[v] <\
    \ d) continue;\n        for (auto& e : G[v]) {\n            if (dist[e.to] > d\
    \ + e.weight) {\n                dist[e.to] = d + e.weight;\n                par[e.to]\
    \ = v;\n                pq.emplace(dist[e.to], e.to);\n            }\n       \
    \ }\n    }\n\n    return {dist, par};\n}\n\n/*\n * Breadth-First Search\n */\n\
    std::vector<int> bfs(const std::vector<std::vector<int>>& G, int s) {\n    std::vector<int>\
    \ dist(G.size(), -1);\n    dist[s] = 0;\n    std::queue<int> que;\n    que.push(s);\n\
    \n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \        for (int u : G[v]) {\n            if (dist[u] == -1) {\n            \
    \    dist[u] = dist[v] + 1;\n                que.push(u);\n            }\n   \
    \     }\n    }\n\n    return dist;\n}\n\n/*\n * Dial's Algorithm\n */\nstd::vector<int>\
    \ dial(const std::vector<std::vector<Edge<int>>>& G, int s,\n                \
    \      int w) {\n    std::vector<int> dist(G.size(), std::numeric_limits<int>::max());\n\
    \    dist[s] = 0;\n    std::vector<std::vector<int>> buckets(w * G.size(), std::vector<int>());\n\
    \    buckets[0].push_back(s);\n\n    for (int d = 0; d < (int)buckets.size();\
    \ ++d) {\n        while (!buckets[d].empty()) {\n            int v = buckets[d].back();\n\
    \            buckets[d].pop_back();\n            if (dist[v] < d) continue;\n\
    \            for (auto& e : G[v]) {\n                if (dist[e.to] > d + e.weight)\
    \ {\n                    dist[e.to] = d + e.weight;\n                    buckets[dist[e.to]].push_back(e.to);\n\
    \                }\n            }\n        }\n    }\n    return dist;\n}\n#line\
    \ 4 \"test/aoj/GRL_1_B.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nconst int INF = 1e9;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<Edge<int>>\
    \ G;\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >>\
    \ s >> t >> d;\n        G.push_back({s, t, d});\n    }\n    auto dist = bellman_ford(G,\
    \ V, r);\n    if (dist.size() == 0) cout << \"NEGATIVE CYCLE\\n\";\n    else {\n\
    \        for (int i = 0; i < V; i++) {\n            if (dist[i] < INF) cout <<\
    \ dist[i] << \"\\n\";\n            else cout << \"INF\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include \"../../graph/shortest_path.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nconst int INF = 1e9;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<Edge<int>>\
    \ G;\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >>\
    \ s >> t >> d;\n        G.push_back({s, t, d});\n    }\n    auto dist = bellman_ford(G,\
    \ V, r);\n    if (dist.size() == 0) cout << \"NEGATIVE CYCLE\\n\";\n    else {\n\
    \        for (int i = 0; i < V; i++) {\n            if (dist[i] < INF) cout <<\
    \ dist[i] << \"\\n\";\n            else cout << \"INF\\n\";\n        }\n    }\n\
    }"
  dependsOn:
  - graph/shortest_path.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-11-18 13:57:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
