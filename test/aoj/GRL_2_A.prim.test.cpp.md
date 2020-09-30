---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: graph/prim.cpp
    title: Prim's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.prim.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#line 1 \"graph/prim.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"graph/edge.cpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T cost;\n   \
    \ Edge(int to, T cost) : from(-1), to(to), cost(cost) {}\n    Edge(int from, int\
    \ to, T cost) : from(from), to(to), cost(cost) {}\n};\n#line 3 \"graph/prim.cpp\"\
    \n\n/*\n * @brief Prim's Algorithm\n * @docs docs/graph/prim.md\n */\ntemplate\
    \ <typename T>\nT prim(const std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<bool>\
    \ used(G.size());\n    using P = std::pair<T, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0, 0);\n    T ret = 0;\n\
    \    while (!pq.empty()) {\n        auto p = pq.top();\n        pq.pop();\n  \
    \      int v = p.second;\n        if (used[v]) continue;\n        used[v] = true;\n\
    \        ret += p.first;\n        for (auto& e : G[v]) {\n            pq.emplace(e.cost,\
    \ e.to);\n        }\n    }\n    return ret;\n}\n#line 4 \"test/aoj/GRL_2_A.prim.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    vector<vector<Edge<int>>>\
    \ G(V);\n    for (int i = 0; i < E; i++) {\n        int s, t, w;\n        cin\
    \ >> s >> t >> w;\n        G[s].push_back({t, w});\n        G[t].push_back({s,\
    \ w});\n    }\n    cout << prim(G) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../graph/prim.cpp\"\n\nusing namespace std;\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int V, E;\n   \
    \ cin >> V >> E;\n    vector<vector<Edge<int>>> G(V);\n    for (int i = 0; i <\
    \ E; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        G[s].push_back({t,\
    \ w});\n        G[t].push_back({s, w});\n    }\n    cout << prim(G) << endl;\n\
    }"
  dependsOn:
  - graph/prim.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.prim.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.prim.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.prim.test.cpp
- /verify/test/aoj/GRL_2_A.prim.test.cpp.html
title: test/aoj/GRL_2_A.prim.test.cpp
---
