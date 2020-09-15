---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.cpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"test/aoj/GRL_3_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#line 1 \"graph/scc.cpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \n/*\n * @brief Strongly Connected Components\n * @docs docs/graph/scc.md\n */\n\
    struct SCC {\npublic:\n    SCC(int n) : G(n), G_rev(n), comp(n, -1), visited(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n      \
    \  G_rev[v].push_back(u);\n    }\n\n    void build() {\n        for (int v = 0;\
    \ v < G.size(); v++) dfs(v);\n        reverse(order.begin(), order.end());\n \
    \       cnt = 0;\n        for (int v : order) if (comp[v] == -1) rdfs(v, cnt++);\n\
    \    }\n\n    int operator[](int i) const {\n        return comp[i];\n    }\n\n\
    \    int count() {\n        return cnt;\n    }\n\nprivate:\n    vector<vector<int>>\
    \ G, G_rev;\n    vector<int> comp, order;\n    vector<bool> visited;\n    int\
    \ cnt;\n\n    void dfs(int u) {\n        if (visited[u]) return;\n        visited[u]\
    \ = true;\n        for (int v : G[u]) dfs(v);\n        order.push_back(u);\n \
    \   }\n\n    void rdfs(int u, int c) {\n        if (comp[u] != -1) return;\n \
    \       comp[u] = c;\n        for (int v : G_rev[u]) rdfs(v, c);\n    }\n};\n\
    #line 4 \"test/aoj/GRL_3_C.test.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    SCC scc(V);\n    for\
    \ (int i = 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n     \
    \   scc.add_edge(s, t);\n    }\n    scc.build();\n    int Q;\n    cin >> Q;\n\
    \    for (int i = 0; i < Q; i++) {\n        int u, v;\n        cin >> u >> v;\n\
    \        cout << (scc[u] == scc[v]) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include \"../../graph/scc.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    SCC scc(V);\n    for\
    \ (int i = 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n     \
    \   scc.add_edge(s, t);\n    }\n    scc.build();\n    int Q;\n    cin >> Q;\n\
    \    for (int i = 0; i < Q; i++) {\n        int u, v;\n        cin >> u >> v;\n\
    \        cout << (scc[u] == scc[v]) << \"\\n\";\n    }\n}"
  dependsOn:
  - graph/scc.cpp
  isVerificationFile: true
  path: test/aoj/GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 22:11:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_C.test.cpp
- /verify/test/aoj/GRL_3_C.test.cpp.html
title: test/aoj/GRL_3_C.test.cpp
---
