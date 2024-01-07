---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/ford_fulkerson.hpp
    title: Ford-Fulkerson Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.ford_fulkerson.test.cpp\"\n#define PROBLEM\
    \ \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\n\n#line 7 \"flow/ford_fulkerson.hpp\"\n\ntemplate\
    \ <typename T>\nclass FordFulkerson {\n   public:\n    FordFulkerson() = default;\n\
    \    explicit FordFulkerson(int n) : G(n), used(n) {}\n\n    void add_edge(int\
    \ u, int v, T cap) {\n        G[u].push_back({v, (int)G[v].size(), cap});\n  \
    \      G[v].push_back({u, (int)G[u].size() - 1, 0});\n    }\n\n    T max_flow(int\
    \ s, int t) {\n        T flow = 0;\n        while (true) {\n            std::fill(used.begin(),\
    \ used.end(), false);\n            T f = dfs(s, t, INF);\n            if (f ==\
    \ 0) return flow;\n            flow += f;\n        }\n    }\n\n    std::set<int>\
    \ min_cut(int s) {\n        std::stack<int> st;\n        std::set<int> visited;\n\
    \        st.push(s);\n        visited.insert(s);\n        while (!st.empty())\
    \ {\n            int v = st.top();\n            st.pop();\n            for (auto&\
    \ e : G[v]) {\n                if (e.cap > 0 && !visited.count(e.to)) {\n    \
    \                visited.insert(e.to);\n                    st.push(e.to);\n \
    \               }\n            }\n        }\n        return visited;\n    }\n\n\
    \   private:\n    struct Edge {\n        int to, rev;\n        T cap;\n    };\n\
    \n    const T INF = std::numeric_limits<T>::max() / 2;\n\n    std::vector<std::vector<Edge>>\
    \ G;\n    std::vector<bool> used;\n\n    T dfs(int v, int t, T f) {\n        if\
    \ (v == t) return f;\n        used[v] = true;\n        for (auto& e : G[v]) {\n\
    \            if (!used[e.to] && e.cap > 0) {\n                T d = dfs(e.to,\
    \ t, std::min(f, e.cap));\n                if (d > 0) {\n                    e.cap\
    \ -= d;\n                    G[e.to][e.rev].cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    };\n#line 7 \"test/aoj/GRL_6_A.ford_fulkerson.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int V, E;\n    cin >> V >> E;\n    FordFulkerson<int> flow(V);\n    for (int\
    \ i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >> v >> c;\n  \
    \      flow.add_edge(u, v, c);\n    }\n    cout << flow.max_flow(0, V - 1) <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../flow/ford_fulkerson.hpp\"\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E;\n    cin >> V >> E;\n    FordFulkerson<int> flow(V);\n    for\
    \ (int i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >> v >> c;\n\
    \        flow.add_edge(u, v, c);\n    }\n    cout << flow.max_flow(0, V - 1) <<\
    \ endl;\n}"
  dependsOn:
  - flow/ford_fulkerson.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.ford_fulkerson.test.cpp
- /verify/test/aoj/GRL_6_A.ford_fulkerson.test.cpp.html
title: test/aoj/GRL_6_A.ford_fulkerson.test.cpp
---
