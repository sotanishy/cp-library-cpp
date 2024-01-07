---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: Diameter of a Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
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
    \ Edge {\n    int from, to;\n    T weight;\n    Edge() = default;\n    Edge(int\
    \ to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int from, int\
    \ to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 6 \"tree/tree_diameter.cpp\"\
    \n\nstd::pair<int, std::vector<int>> tree_diameter(const std::vector<std::vector<int>>&\
    \ G) {\n    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs,\
    \ int v, int p) -> std::pair<int, int> {\n        std::pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto weight = dfs(dfs, c, v);\n            ++weight.first;\n            if (ret\
    \ < weight) {\n                ret = weight;\n                to[v] = c;\n   \
    \         }\n        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0,\
    \ -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n   \
    \ int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>> tree_diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<int> to(G.size());\n\
    \n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T, int> {\n \
    \       std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n       \
    \     if (e.to == p) continue;\n            auto weight = dfs(dfs, e.to, v);\n\
    \            weight.first += e.weight;\n            if (ret < weight) {\n    \
    \            ret = weight;\n                to[v] = e.to;\n            }\n   \
    \     }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto\
    \ q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n#line 4 \"test/aoj/GRL_5_A.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    vector<vector<Edge<int>>> G(n);\n\
    \    for (int i = 0; i < n - 1; i++) {\n        int s, t, w;\n        cin >> s\
    \ >> t >> w;\n        G[s].push_back({t, w});\n        G[t].push_back({s, w});\n\
    \    }\n    cout << tree_diameter(G).first << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n\n#include \"../../tree/tree_diameter.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int n;\n    cin >> n;\n    vector<vector<Edge<int>>> G(n);\n    for (int\
    \ i = 0; i < n - 1; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n\
    \        G[s].push_back({t, w});\n        G[t].push_back({s, w});\n    }\n   \
    \ cout << tree_diameter(G).first << endl;\n}"
  dependsOn:
  - tree/tree_diameter.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 14:52:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_A.test.cpp
- /verify/test/aoj/GRL_5_A.test.cpp.html
title: test/aoj/GRL_5_A.test.cpp
---
