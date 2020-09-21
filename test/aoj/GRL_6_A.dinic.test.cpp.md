---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/dinic.cpp
    title: Dinic's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.dinic.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#line 1 \"flow/dinic.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief Dinic's\
    \ Algorithm\n * @docs docs/flow/dinic.md\n */\ntemplate <typename T>\nclass Dinic\
    \ {\npublic:\n    explicit Dinic(int V) : G(V), level(V), iter(V) {}\n\n    void\
    \ add_edge(int u, int v, T cap) {\n        G[u].emplace_back(v, cap, (int) G[v].size());\n\
    \        G[v].emplace_back(u, 0, (int) G[u].size() - 1);\n    }\n\n    T max_flow(int\
    \ s, int t) {\n        T flow = 0;\n        while (bfs(s, t)) {\n            std::fill(iter.begin(),\
    \ iter.end(), 0);\n            T f = 0;\n            while ((f = dfs(s, t, INF))\
    \ > 0) flow += f;\n        }\n        return flow;\n    }\n\nprivate:\n    struct\
    \ Edge {\n        int to;\n        T cap;\n        int rev;\n        Edge(int\
    \ to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n\n    const T INF\
    \ = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>> G;\n\
    \    std::vector<int> level, iter;\n\n    bool bfs(int s, int t) {\n        std::fill(level.begin(),\
    \ level.end(), -1);\n        level[s] = 0;\n        std::queue<int> q;\n     \
    \   q.push(s);\n        while (!q.empty() && level[t] == -1) {\n            int\
    \ v = q.front();\n            q.pop();\n            for (auto& e : G[v]) {\n \
    \               if (e.cap > 0 && level[e.to] == -1) {\n                    level[e.to]\
    \ = level[v] + 1;\n                    q.push(e.to);\n                }\n    \
    \        }\n        }\n        return level[t] != -1;\n    }\n\n    T dfs(int\
    \ v, int t, T f) {\n        if (v == t) return f;\n        for (int& i = iter[v];\
    \ i < (int) G[v].size(); i++) {\n            Edge& e = G[v][i];\n            if\
    \ (e.cap > 0 && level[v] < level[e.to]) {\n                T d = dfs(e.to, t,\
    \ std::min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    };\n#line 4 \"test/aoj/GRL_6_A.dinic.test.cpp\"\n\nusing namespace std;\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ V, E;\n    cin >> V >> E;\n    Dinic<int> flow(V);\n    for (int i = 0; i <\
    \ E; i++) {\n        int u, v, c;\n        cin >> u >> v >> c;\n        flow.add_edge(u,\
    \ v, c);\n    }\n    cout << flow.max_flow(0, V - 1) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"../../flow/dinic.cpp\"\n\nusing namespace std;\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int V, E;\n   \
    \ cin >> V >> E;\n    Dinic<int> flow(V);\n    for (int i = 0; i < E; i++) {\n\
    \        int u, v, c;\n        cin >> u >> v >> c;\n        flow.add_edge(u, v,\
    \ c);\n    }\n    cout << flow.max_flow(0, V - 1) << endl;\n}"
  dependsOn:
  - flow/dinic.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.dinic.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.dinic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.dinic.test.cpp
- /verify/test/aoj/GRL_6_A.dinic.test.cpp.html
title: test/aoj/GRL_6_A.dinic.test.cpp
---
