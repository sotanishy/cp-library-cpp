---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/ford_fulkerson.cpp
    title: Ford-Fulkerson Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.ford_fulkerson.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\n\n#line\
    \ 2 \"flow/ford_fulkerson.cpp\"\n#include <algorithm>\n#include <limits>\n#include\
    \ <vector>\n\ntemplate <typename T>\nclass FordFulkerson {\npublic:\n    FordFulkerson()\
    \ = default;\n    explicit FordFulkerson(int n) : G(n), used(n) {}\n\n    void\
    \ add_edge(int u, int v, T cap) {\n        G[u].emplace_back(v, cap, (int) G[v].size());\n\
    \        G[v].emplace_back(u, 0, (int) G[u].size() - 1);\n    }\n\n    T max_flow(int\
    \ s, int t) {\n        T flow = 0;\n        while (true) {\n            std::fill(used.begin(),\
    \ used.end(), false);\n            T f = dfs(s, t, INF);\n            if (f ==\
    \ 0) return flow;\n            flow += f;\n        }\n    }\n\nprivate:\n    struct\
    \ Edge {\n        int to;\n        T cap;\n        int rev;\n        Edge(int\
    \ to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\n    const T INF\
    \ = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>> G;\n\
    \    std::vector<bool> used;\n\n    T dfs(int v, int t, T f) {\n        if (v\
    \ == t) return f;\n        used[v] = true;\n        for (auto& e : G[v]) {\n \
    \           if (!used[e.to] && e.cap > 0) {\n                T d = dfs(e.to, t,\
    \ std::min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    };\n#line 4 \"test/aoj/GRL_6_A.ford_fulkerson.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    FordFulkerson<int>\
    \ flow(V);\n    for (int i = 0; i < E; i++) {\n        int u, v, c;\n        cin\
    \ >> u >> v >> c;\n        flow.add_edge(u, v, c);\n    }\n    cout << flow.max_flow(0,\
    \ V - 1) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"../../flow/ford_fulkerson.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E;\n    cin >> V >> E;\n    FordFulkerson<int> flow(V);\n    for\
    \ (int i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >> v >> c;\n\
    \        flow.add_edge(u, v, c);\n    }\n    cout << flow.max_flow(0, V - 1) <<\
    \ endl;\n}"
  dependsOn:
  - flow/ford_fulkerson.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.ford_fulkerson.test.cpp
- /verify/test/aoj/GRL_6_A.ford_fulkerson.test.cpp.html
title: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
---
