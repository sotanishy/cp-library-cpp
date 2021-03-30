---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/lowlink.cpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/aoj/GRL_3_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#line 2 \"graph/lowlink.cpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\nclass Lowlink {\npublic:\n    Lowlink() = default;\n    explicit\
    \ Lowlink(const std::vector<std::vector<int>>& G) : G(G), ord(G.size(), -1), low(G.size())\
    \ {\n        for (int i = 0; i < (int) G.size(); ++i) {\n            if (ord[i]\
    \ == -1) dfs(i, -1);\n        }\n    }\n\n    std::vector<std::pair<int, int>>\
    \ get_bridges() const {\n        return bridge;\n    }\n\n    std::vector<int>\
    \ get_articulation_points() const {\n        return articulation;\n    }\n\n \
    \   bool is_bridge(int u, int v) const {\n        if (ord[u] > ord[v]) std::swap(u,\
    \ v);\n        return ord[u] < low[v];\n    }\n\nprotected:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> ord, low;\n    std::vector<std::pair<int, int>> bridge;\n\
    \    std::vector<int> articulation;\n\nprivate:\n    int k = 0;\n\n    void dfs(int\
    \ v, int p) {\n        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n            if\
    \ (c == p) continue;\n            if (ord[c] == -1) {\n                ++cnt;\n\
    \                dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n\
    \                if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n  \
    \              if (ord[v] < low[c]) bridge.emplace_back(std::min(v, c), std::max(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 4 \"\
    test/aoj/GRL_3_A.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int i\
    \ = 0; i < E; ++i) {\n        int s, t;\n        cin >> s >> t;\n        G[s].push_back(t);\n\
    \        G[t].push_back(s);\n    }\n    Lowlink lowlink(G);\n    vector<int> pts\
    \ = lowlink.get_articulation_points();\n    sort(pts.begin(), pts.end());\n  \
    \  for (int v : pts) cout << v << \"\\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include \"../../graph/lowlink.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int\
    \ i = 0; i < E; ++i) {\n        int s, t;\n        cin >> s >> t;\n        G[s].push_back(t);\n\
    \        G[t].push_back(s);\n    }\n    Lowlink lowlink(G);\n    vector<int> pts\
    \ = lowlink.get_articulation_points();\n    sort(pts.begin(), pts.end());\n  \
    \  for (int v : pts) cout << v << \"\\n\";\n}"
  dependsOn:
  - graph/lowlink.cpp
  isVerificationFile: true
  path: test/aoj/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2021-03-30 13:20:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_A.test.cpp
- /verify/test/aoj/GRL_3_A.test.cpp.html
title: test/aoj/GRL_3_A.test.cpp
---
