---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: Diameter of a Tree
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
    \n\n#line 2 \"tree/tree_diameter.cpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n#line 2 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge {\n    int from, to;\n    T weight;\n    Edge(int to, T weight) : from(-1),\
    \ to(to), weight(weight) {}\n    Edge(int from, int to, T weight) : from(from),\
    \ to(to), weight(weight) {}\n};\n#line 6 \"tree/tree_diameter.cpp\"\n\nclass TreeDiameter\
    \ {\npublic:\n    TreeDiameter() = delete;\n\n    static int diameter(const std::vector<std::vector<int>>&\
    \ G) {\n        auto p = dfs(G, 0, -1);\n        auto q = dfs(G, p.second, -1);\n\
    \        return q.first;\n    }\n\n    template <typename T>\n    static T diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n        auto p = dfs(G, 0, -1);\n \
    \       auto q = dfs(G, p.second, -1);\n        return q.first;\n    }\n\nprivate:\n\
    \    static std::pair<int, int> dfs(const std::vector<std::vector<int>>& G, int\
    \ v, int p) {\n        std::pair<int, int> ret(0, v);\n        for (int c : G[v])\
    \ {\n            if (c == p) continue;\n            auto weight = dfs(G, c, v);\n\
    \            ++weight.first;\n            ret = std::max(ret, weight);\n     \
    \   }\n        return ret;\n    }\n\n    template <typename T>\n    static std::pair<T,\
    \ int> dfs(const std::vector<std::vector<Edge<T>>>& G, int v, int p) {\n     \
    \   std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n           \
    \ if (e.to == p) continue;\n            auto weight = dfs(G, e.to, v);\n     \
    \       weight.first += e.weight;\n            ret = std::max(ret, weight);\n\
    \        }\n        return ret;\n    }\n};\n\n/*\nint tree_diameter(const std::vector<std::vector<int>>&\
    \ G) {\n    auto dfs = [&](const auto& self, int v, int p) {\n        std::pair<int,\
    \ int> ret(0, v);\n        for (int c : G[v]) {\n            if (c == p) continue;\n\
    \            auto weight = self(self, c, v);\n            ++weight.first;\n  \
    \          ret = std::max(ret, weight);\n        }\n        return ret;\n    };\n\
    \    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(dfs, p.second, -1);\n    return\
    \ q.first;\n}\n\ntemplate <typename T>\nT tree_diameter(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n    auto dfs = [&](const auto& self, int v, int p) {\n        std::pair<int,\
    \ int> ret(0, v);\n        for (auto& e : G[v]) {\n            if (e.to == p)\
    \ continue;\n            auto weight = self(self, e.to, v);\n            weight.first\
    \ += e.weight;\n            ret = std::max(ret, weight);\n        }\n        return\
    \ ret;\n    }\n    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(G, p.second, -1);\n\
    \    return q.first;\n}\n*/\n#line 4 \"test/aoj/GRL_5_A.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    vector<vector<Edge<int>>> G(n);\n\
    \    for (int i = 0; i < n - 1; i++) {\n        int s, t, w;\n        cin >> s\
    \ >> t >> w;\n        G[s].push_back({t, w});\n        G[t].push_back({s, w});\n\
    \    }\n    cout << TreeDiameter::diameter(G) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#include \"../../tree/tree_diameter.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int n;\n    cin >> n;\n    vector<vector<Edge<int>>> G(n);\n    for (int\
    \ i = 0; i < n - 1; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n\
    \        G[s].push_back({t, w});\n        G[t].push_back({s, w});\n    }\n   \
    \ cout << TreeDiameter::diameter(G) << endl;\n}"
  dependsOn:
  - tree/tree_diameter.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 17:56:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: test/aoj/GRL_5_A.test.cpp
---
