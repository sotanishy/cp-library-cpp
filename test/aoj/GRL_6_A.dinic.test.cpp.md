---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/dinic.cpp
    title: Dinic's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.dinic.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#line 2 \"flow/dinic.cpp\"\n#include <algorithm>\n#include <limits>\n#include\
    \ <set>\n#include <stack>\n#include <queue>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass Dinic {\npublic:\n    Dinic() = default;\n    explicit Dinic(int V)\
    \ : G(V), level(V), iter(V) {}\n\n    void add_edge(int u, int v, T cap) {\n \
    \       G[u].emplace_back(v, (int) G[v].size(), cap);\n        G[v].emplace_back(u,\
    \ (int) G[u].size() - 1, 0);\n    }\n\n    T max_flow(int s, int t) {\n      \
    \  T flow = 0;\n        while (bfs(s, t)) {\n            std::fill(iter.begin(),\
    \ iter.end(), 0);\n            T f = 0;\n            while ((f = dfs(s, t, INF))\
    \ > 0) flow += f;\n        }\n        return flow;\n    }\n\n    std::set<int>\
    \ min_cut(int s) {\n        std::stack<int> st;\n        std::set<int> visited;\n\
    \        st.push(s);\n        visited.insert(s);\n        while (!st.empty())\
    \ {\n            int v = st.top();\n            st.pop();\n            for (auto&\
    \ e : G[v]) {\n                if (e.cap > 0 && !visited.count(e.to)) {\n    \
    \                visited.insert(e.to);\n                    st.push(e.to);\n \
    \               }\n            }\n        }\n        return visited;\n    }\n\n\
    private:\n    struct Edge {\n        int to, rev;\n        T cap;\n    };\n\n\
    \    static constexpr T INF = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>>\
    \ G;\n    std::vector<int> level, iter;\n\n    bool bfs(int s, int t) {\n    \
    \    std::fill(level.begin(), level.end(), -1);\n        level[s] = 0;\n     \
    \   std::queue<int> q;\n        q.push(s);\n        while (!q.empty() && level[t]\
    \ == -1) {\n            int v = q.front();\n            q.pop();\n           \
    \ for (auto& e : G[v]) {\n                if (e.cap > 0 && level[e.to] == -1)\
    \ {\n                    level[e.to] = level[v] + 1;\n                    q.push(e.to);\n\
    \                }\n            }\n        }\n        return level[t] != -1;\n\
    \    }\n\n    T dfs(int v, int t, T f) {\n        if (v == t) return f;\n    \
    \    for (int& i = iter[v]; i < (int) G[v].size(); ++i) {\n            Edge& e\
    \ = G[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n       \
    \         T d = dfs(e.to, t, std::min(f, e.cap));\n                if (d > 0)\
    \ {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap +=\
    \ d;\n                    return d;\n                }\n            }\n      \
    \  }\n        return 0;\n    }\n};\n#line 4 \"test/aoj/GRL_6_A.dinic.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    Dinic<int> flow(V);\n\
    \    for (int i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >>\
    \ v >> c;\n        flow.add_edge(u, v, c);\n    }\n    cout << flow.max_flow(0,\
    \ V - 1) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include \"../../flow/dinic.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E;\n    cin >> V >> E;\n    Dinic<int> flow(V);\n    for (int i =\
    \ 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >> v >> c;\n      \
    \  flow.add_edge(u, v, c);\n    }\n    cout << flow.max_flow(0, V - 1) << endl;\n\
    }"
  dependsOn:
  - flow/dinic.cpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.dinic.test.cpp
  requiredBy: []
  timestamp: '2022-12-19 17:08:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.dinic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.dinic.test.cpp
- /verify/test/aoj/GRL_6_A.dinic.test.cpp.html
title: test/aoj/GRL_6_A.dinic.test.cpp
---
