---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.cpp
    title: Bellman-Ford Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
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
    \n\n#line 1 \"graph/bellman_ford.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"graph/edge.cpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}\n\
    \    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n};\n\
    #line 3 \"graph/bellman_ford.cpp\"\nusing namespace std;\n\n/*\n * @brief Bellman-Ford\
    \ Algorithm\n * @docs docs/graph/bellman_ford.md\n */\ntemplate <typename T>\n\
    vector<T> bellman_ford(vector<Edge<T>>& G, int V, int s) {\n    const auto INF\
    \ = numeric_limits<T>::max();\n    vector<int> dist(V, INF);\n    dist[s] = 0;\n\
    \    for (int i = 0; i < V; i++) {\n        for (auto& e : G) {\n            if\
    \ (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {\n            \
    \    dist[e.to] = dist[e.from] + e.cost;\n                if (i == V - 1) return\
    \ vector<T>();\n            }\n        }\n    }\n    return dist;\n}\n#line 4\
    \ \"test/aoj/GRL_1_B.test.cpp\"\n\nconst int INF = 1e9;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<Edge<int>>\
    \ G;\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >>\
    \ s >> t >> d;\n        G.push_back({s, t, d});\n    }\n    auto dist = bellman_ford(G,\
    \ V, r);\n    if (dist.size() == 0) cout << \"NEGATIVE CYCLE\\n\";\n    else {\n\
    \        for (int i = 0; i < V; i++) {\n            if (dist[i] < INF) cout <<\
    \ dist[i] << \"\\n\";\n            else cout << \"INF\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n\n#include \"../../graph/bellman_ford.cpp\"\n\nconst int INF = 1e9;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int V, E, r;\n\
    \    cin >> V >> E >> r;\n    vector<Edge<int>> G;\n    for (int i = 0; i < E;\
    \ i++) {\n        int s, t, d;\n        cin >> s >> t >> d;\n        G.push_back({s,\
    \ t, d});\n    }\n    auto dist = bellman_ford(G, V, r);\n    if (dist.size()\
    \ == 0) cout << \"NEGATIVE CYCLE\\n\";\n    else {\n        for (int i = 0; i\
    \ < V; i++) {\n            if (dist[i] < INF) cout << dist[i] << \"\\n\";\n  \
    \          else cout << \"INF\\n\";\n        }\n    }\n}"
  dependsOn:
  - graph/bellman_ford.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-11 22:35:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
