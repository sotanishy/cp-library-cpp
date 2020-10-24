---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path.cpp
    title: Shortest Path Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#line 2 \"graph/shortest_path.cpp\"\n#include <limits>\n#include <queue>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n#line 2 \"graph/edge.cpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n \
    \   Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 8\
    \ \"graph/shortest_path.cpp\"\n\n/*\n * @brief Shortest Path Algorithms\n * @docs\
    \ docs/graph/shortest_path.md\n */\n\n/*\n * Bellman-Ford Algorithm\n */\ntemplate\
    \ <typename T>\nstd::vector<T> bellman_ford(const std::vector<Edge<T>>& G, int\
    \ V, int s) {\n    constexpr T INF = std::numeric_limits<T>::max();\n    std::vector<int>\
    \ dist(V, INF);\n    dist[s] = 0;\n    for (int i = 0; i < V; ++i) {\n       \
    \ for (auto& e : G) {\n            if (dist[e.from] != INF && dist[e.to] > dist[e.from]\
    \ + e.weight) {\n                dist[e.to] = dist[e.from] + e.weight;\n     \
    \           if (i == V - 1) return std::vector<T>();\n            }\n        }\n\
    \    }\n    return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n */\ntemplate\
    \ <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>& dist) {\n   \
    \ int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n        for (int i\
    \ = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n            \
    \    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n           \
    \ }\n        }\n    }\n}\n\n/*\n * Dijkstra's Algorithm\n */\ntemplate <typename\
    \ T>\nstd::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>& G, int\
    \ s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n  \
    \  dist[s] = 0;\n    using P = std::pair<T, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty())\
    \ {\n        T weight;\n        int v;\n        std::tie(weight, v) = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < weight) continue;\n        for (auto&\
    \ e : G[v]) {\n            if (dist[e.to] > dist[v] + e.weight) {\n          \
    \      dist[e.to] = dist[v] + e.weight;\n                pq.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n\n    return dist;\n}\n#line 4 \"test/aoj/GRL_1_B.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nconst int INF = 1e9;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ V, E, r;\n    cin >> V >> E >> r;\n    vector<Edge<int>> G;\n    for (int i\
    \ = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >> t >> d;\n    \
    \    G.push_back({s, t, d});\n    }\n    auto dist = bellman_ford(G, V, r);\n\
    \    if (dist.size() == 0) cout << \"NEGATIVE CYCLE\\n\";\n    else {\n      \
    \  for (int i = 0; i < V; i++) {\n            if (dist[i] < INF) cout << dist[i]\
    \ << \"\\n\";\n            else cout << \"INF\\n\";\n        }\n    }\n}\n"
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
  timestamp: '2020-10-24 23:19:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
