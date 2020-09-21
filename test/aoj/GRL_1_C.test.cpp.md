---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/floyd_warshall.cpp
    title: Floyd-Warshall Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj/GRL_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#line 1 \"graph/floyd_warshall.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Floyd-Warshall Algorithm\n * @docs docs/graph/floyd_warshall.md\n */\ntemplate\
    \ <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>& dist) {\n   \
    \ int V = dist.size();\n    for (int k = 0; k < V; k++) {\n        for (int i\
    \ = 0; i < V; i++) {\n            for (int j = 0; j < V; j++) {\n            \
    \    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n           \
    \ }\n        }\n    }\n}\n#line 4 \"test/aoj/GRL_1_C.test.cpp\"\n\nusing namespace\
    \ std;\nusing ll = long long;\n\nconst ll INF = 1e18;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    vector<vector<ll>>\
    \ dist(V, vector<ll>(V, INF));\n    for (int i = 0; i < V; i++) dist[i][i] = 0;\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >>\
    \ t >> d;\n        dist[s][t] = d;\n    }\n    floyd_warshall(dist);\n    for\
    \ (int i = 0; i < V; i++) {\n        if (dist[i][i] < 0) {\n            cout <<\
    \ \"NEGATIVE CYCLE\\n\";\n            return 0;\n        }\n    }\n    for (int\
    \ i = 0; i < V; i++) {\n        for (int j = 0; j < V; j++) {\n            if\
    \ (dist[i][j] < 1e10) cout << dist[i][j];\n            else cout << \"INF\";\n\
    \            if (j < V - 1) cout << \" \";\n            else cout << \"\\n\";\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include \"../../graph/floyd_warshall.cpp\"\n\nusing namespace std;\nusing\
    \ ll = long long;\n\nconst ll INF = 1e18;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    vector<vector<ll>>\
    \ dist(V, vector<ll>(V, INF));\n    for (int i = 0; i < V; i++) dist[i][i] = 0;\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >>\
    \ t >> d;\n        dist[s][t] = d;\n    }\n    floyd_warshall(dist);\n    for\
    \ (int i = 0; i < V; i++) {\n        if (dist[i][i] < 0) {\n            cout <<\
    \ \"NEGATIVE CYCLE\\n\";\n            return 0;\n        }\n    }\n    for (int\
    \ i = 0; i < V; i++) {\n        for (int j = 0; j < V; j++) {\n            if\
    \ (dist[i][j] < 1e10) cout << dist[i][j];\n            else cout << \"INF\";\n\
    \            if (j < V - 1) cout << \" \";\n            else cout << \"\\n\";\n\
    \        }\n    }\n}"
  dependsOn:
  - graph/floyd_warshall.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C.test.cpp
- /verify/test/aoj/GRL_1_C.test.cpp.html
title: test/aoj/GRL_1_C.test.cpp
---
