---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: Diameter of a Tree
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"test/aoj/GRL_5_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#line 1 \"tree/tree_diameter.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"graph/edge.cpp\"\
    \nusing namespace std;\n\ntemplate <typename T>\nstruct Edge {\n    int from,\
    \ to;\n    T cost;\n    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}\n\
    \    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n};\n\
    #line 3 \"tree/tree_diameter.cpp\"\nusing namespace std;\n\n/*\n * @brief Diameter\
    \ of a Tree\n * @docs docs/tree/tree_diameter.md\n */\nclass TreeDiameter {\n\
    public:\n    static int diameter(const vector<vector<int>>& G) {\n        auto\
    \ p = dfs(G, 0, -1);\n        auto q = dfs(G, p.second, -1);\n        return q.first;\n\
    \    }\n\n    template <typename T>\n    static T diameter(const vector<vector<Edge<T>>>&\
    \ G) {\n        auto p = dfs(G, 0, -1);\n        auto q = dfs(G, p.second, -1);\n\
    \        return q.first;\n    }\n\nprivate:\n    static pair<int, int> dfs(const\
    \ vector<vector<int>>& G, int v, int p) {\n        pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto cost = dfs(G, c, v);\n            cost.first++;\n            ret = max(ret,\
    \ cost);\n        }\n        return ret;\n    }\n\n    template <typename T>\n\
    \    static pair<T, int> dfs(const vector<vector<Edge<T>>>& G, int v, int p) {\n\
    \        pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n           \
    \ if (e.to == p) continue;\n            auto cost = dfs(G, e.to, v);\n       \
    \     cost.first += e.cost;\n            ret = max(ret, cost);\n        }\n  \
    \      return ret;\n    }\n};\n#line 4 \"test/aoj/GRL_5_A.test.cpp\"\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n;\n  \
    \  cin >> n;\n    vector<vector<Edge<int>>> G(n);\n    for (int i = 0; i < n -\
    \ 1; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        G[s].push_back({t,\
    \ w});\n        G[t].push_back({s, w});\n    }\n    cout << TreeDiameter::diameter(G)\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#include \"../../tree/tree_diameter.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    vector<vector<Edge<int>>> G(n);\n\
    \    for (int i = 0; i < n - 1; i++) {\n        int s, t, w;\n        cin >> s\
    \ >> t >> w;\n        G[s].push_back({t, w});\n        G[t].push_back({s, w});\n\
    \    }\n    cout << TreeDiameter::diameter(G) << endl;\n}"
  dependsOn:
  - tree/tree_diameter.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: test/aoj/GRL_5_A.test.cpp
---
