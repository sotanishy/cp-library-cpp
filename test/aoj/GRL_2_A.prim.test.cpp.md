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
    \n\n#line 1 \"graph/prim.cpp\"\n#include <bits/stdc++.h>\n#line 3 \"graph/edge.cpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n \
    \   Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 3\
    \ \"graph/prim.cpp\"\n\n/*\n * @brief Prim's Algorithm\n * @docs docs/graph/prim.md\n\
    \ */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto& e1,\
    \ const auto& e2) { return e1.weight > e2.weight; };\n    std::priority_queue<Edge<T>,\
    \ std::vector<Edge<T>>, decltype(cmp)> pq(cmp);\n    pq.emplace(0, 0, 0);\n  \
    \  T weight = 0;\n    std::vector<Edge<T>> edges;\n    while (!pq.empty()) {\n\
    \        auto e = pq.top();\n        pq.pop();\n        if (used[e.to]) continue;\n\
    \        used[e.to] = true;\n        weight += e.weight;\n        if (e.to !=\
    \ 0) edges.push_back(e);\n        for (auto& f : G[e.to]) {\n            pq.emplace(e.to,\
    \ f.to, f.weight);\n        }\n    }\n    return {weight, edges};\n}\n#line 4\
    \ \"test/aoj/GRL_2_A.prim.test.cpp\"\n\nusing namespace std;\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int V, E;\n   \
    \ cin >> V >> E;\n    vector<vector<Edge<int>>> G(V);\n    for (int i = 0; i <\
    \ E; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        G[s].push_back({t,\
    \ w});\n        G[t].push_back({s, w});\n    }\n    cout << prim(G).first << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../graph/prim.cpp\"\n\nusing namespace std;\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int V, E;\n   \
    \ cin >> V >> E;\n    vector<vector<Edge<int>>> G(V);\n    for (int i = 0; i <\
    \ E; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        G[s].push_back({t,\
    \ w});\n        G[t].push_back({s, w});\n    }\n    cout << prim(G).first << endl;\n\
    }"
  dependsOn:
  - graph/prim.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.prim.test.cpp
  requiredBy: []
  timestamp: '2020-10-12 02:39:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.prim.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.prim.test.cpp
- /verify/test/aoj/GRL_2_A.prim.test.cpp.html
title: test/aoj/GRL_2_A.prim.test.cpp
---
