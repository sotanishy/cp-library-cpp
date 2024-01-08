---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"test/aoj/GRL_3_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#line 2 \"graph/lowlink.hpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\nclass Lowlink {\n   public:\n    std::vector<int> ord, low;\n\
    \    std::vector<std::pair<int, int>> bridge;\n    std::vector<int> articulation;\n\
    \n    Lowlink() = default;\n    explicit Lowlink(const std::vector<std::vector<int>>&\
    \ G)\n        : ord(G.size(), -1), low(G.size()), G(G) {\n        for (int i =\
    \ 0; i < (int)G.size(); ++i) {\n            if (ord[i] == -1) dfs(i, -1);\n  \
    \      }\n    }\n\n    bool is_bridge(int u, int v) const {\n        if (ord[u]\
    \ > ord[v]) std::swap(u, v);\n        return ord[u] < low[v];\n    }\n\n   private:\n\
    \    std::vector<std::vector<int>> G;\n    int k = 0;\n\n    void dfs(int v, int\
    \ p) {\n        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false, checked = false;\n        int cnt = 0;\n        for (int c : G[v])\
    \ {\n            if (c == p && !checked) {\n                checked = true;\n\
    \                continue;\n            }\n            if (ord[c] == -1) {\n \
    \               ++cnt;\n                dfs(c, v);\n                low[v] = std::min(low[v],\
    \ low[c]);\n                if (p != -1 && ord[v] <= low[c]) is_articulation =\
    \ true;\n                if (ord[v] < low[c]) bridge.push_back(std::minmax(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 4 \"\
    test/aoj/GRL_3_B.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int i\
    \ = 0; i < E; ++i) {\n        int s, t;\n        cin >> s >> t;\n        G[s].push_back(t);\n\
    \        G[t].push_back(s);\n    }\n    Lowlink lowlink(G);\n    auto bridges\
    \ = lowlink.bridge;\n    sort(bridges.begin(), bridges.end());\n    for (auto&\
    \ p : bridges) {\n        cout << p.first << \" \" << p.second << \"\\n\";\n \
    \   }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include \"../../graph/lowlink.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int\
    \ i = 0; i < E; ++i) {\n        int s, t;\n        cin >> s >> t;\n        G[s].push_back(t);\n\
    \        G[t].push_back(s);\n    }\n    Lowlink lowlink(G);\n    auto bridges\
    \ = lowlink.bridge;\n    sort(bridges.begin(), bridges.end());\n    for (auto&\
    \ p : bridges) {\n        cout << p.first << \" \" << p.second << \"\\n\";\n \
    \   }\n}"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 14:54:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_B.test.cpp
- /verify/test/aoj/GRL_3_B.test.cpp.html
title: test/aoj/GRL_3_B.test.cpp
---
