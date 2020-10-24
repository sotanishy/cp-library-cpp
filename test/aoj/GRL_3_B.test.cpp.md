---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.cpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"test/aoj/GRL_3_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#line 2 \"graph/lowlink.cpp\"\n#include <algorithm>\n#include <utility>\n\
    #include <vector>\n\n/*\n * @brief Lowlink\n * @docs docs/graph/lowlink.md\n */\n\
    class Lowlink {\npublic:\n    Lowlink() = default;\n    explicit Lowlink(const\
    \ std::vector<std::vector<int>> G) : G(G), ord(G.size(), -1), low(G.size()) {\n\
    \        for (int i = 0; i < (int) G.size(); ++i) {\n            if (ord[i] ==\
    \ -1) dfs(i, -1);\n        }\n    }\n\n    std::vector<std::pair<int, int>> get_bridges()\
    \ const {\n        return bridge;\n    }\n\n    std::vector<int> get_articulation_points()\
    \ const {\n        return articulation;\n    }\n\n    bool is_bridge(int u, int\
    \ v) {\n        if (ord[u] > ord[v]) std::swap(u, v);\n        return ord[u] <\
    \ low[v];\n    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<int>\
    \ ord, low;\n    std::vector<std::pair<int, int>> bridge;\n    std::vector<int>\
    \ articulation;\n    int k = 0;\n\n    void dfs(int v, int p) {\n        ord[v]\
    \ = k++;\n        low[v] = ord[v];\n        bool is_articulation = false, checked\
    \ = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n            if\
    \ (c == p && !checked) {\n                checked = true;\n                continue;\n\
    \            }\n            if (ord[c] == -1) {\n                ++cnt;\n    \
    \            dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n\
    \                if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n  \
    \              if (ord[v] < low[c]) bridge.emplace_back(std::min(v, c), std::max(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 4 \"\
    test/aoj/GRL_3_B.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int i\
    \ = 0; i < E; ++i) {\n        int s, t;\n        cin >> s >> t;\n        G[s].push_back(t);\n\
    \        G[t].push_back(s);\n    }\n    Lowlink lowlink(G);\n    vector<pair<int,\
    \ int>> bridges = lowlink.get_bridges();\n    sort(bridges.begin(), bridges.end());\n\
    \    for (auto& p : bridges) {\n        cout << p.first << \" \" << p.second <<\
    \ \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include \"../../graph/lowlink.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V);\n    for (int\
    \ i = 0; i < E; ++i) {\n        int s, t;\n        cin >> s >> t;\n        G[s].push_back(t);\n\
    \        G[t].push_back(s);\n    }\n    Lowlink lowlink(G);\n    vector<pair<int,\
    \ int>> bridges = lowlink.get_bridges();\n    sort(bridges.begin(), bridges.end());\n\
    \    for (auto& p : bridges) {\n        cout << p.first << \" \" << p.second <<\
    \ \"\\n\";\n    }\n}"
  dependsOn:
  - graph/lowlink.cpp
  isVerificationFile: true
  path: test/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 15:56:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_B.test.cpp
- /verify/test/aoj/GRL_3_B.test.cpp.html
title: test/aoj/GRL_3_B.test.cpp
---
