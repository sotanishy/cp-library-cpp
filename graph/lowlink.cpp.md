---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/graph/lowlink.cpp
    document_title: Lowlink
    links: []
  bundledCode: "#line 1 \"graph/lowlink.cpp\"\n#include <bits/stdc++.h>\n\n/*\n *\
    \ @brief Lowlink\n * @docs docs/graph/lowlink.cpp\n */\nclass Lowlink {\npublic:\n\
    \    Lowlink() = default;\n    explicit Lowlink(const std::vector<std::vector<int>>\
    \ G) : G(G), ord(G.size(), -1), low(G.size()) {\n        for (int i = 0; i < (int)\
    \ G.size(); ++i) {\n            if (ord[i] == -1) dfs(i, -1);\n        }\n   \
    \ }\n\n    std::vector<std::pair<int, int>> get_bridges() const {\n        return\
    \ bridge;\n    }\n\n    std::vector<int> get_articulation_points() const {\n \
    \       return articulation;\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> ord, low;\n    std::vector<std::pair<int, int>> bridge;\n\
    \    std::vector<int> articulation;\n    int k = 0;\n\n    void dfs(int v, int\
    \ p) {\n        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n            if\
    \ (ord[c] == -1) {\n                ++cnt;\n                dfs(c, v);\n     \
    \           low[v] = std::min(low[v], low[c]);\n                if (p != -1 &&\
    \ ord[v] <= low[c]) is_articulation = true;\n                if (ord[v] < low[c])\
    \ bridge.emplace_back(std::min(v, c), std::max(v, c));\n            } else if\
    \ (c != p) {\n                low[v] = std::min(low[v], ord[c]);\n           \
    \ }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n    \
    \    if (is_articulation) articulation.push_back(v);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Lowlink\n * @docs docs/graph/lowlink.cpp\n\
    \ */\nclass Lowlink {\npublic:\n    Lowlink() = default;\n    explicit Lowlink(const\
    \ std::vector<std::vector<int>> G) : G(G), ord(G.size(), -1), low(G.size()) {\n\
    \        for (int i = 0; i < (int) G.size(); ++i) {\n            if (ord[i] ==\
    \ -1) dfs(i, -1);\n        }\n    }\n\n    std::vector<std::pair<int, int>> get_bridges()\
    \ const {\n        return bridge;\n    }\n\n    std::vector<int> get_articulation_points()\
    \ const {\n        return articulation;\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> ord, low;\n    std::vector<std::pair<int, int>> bridge;\n\
    \    std::vector<int> articulation;\n    int k = 0;\n\n    void dfs(int v, int\
    \ p) {\n        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n            if\
    \ (ord[c] == -1) {\n                ++cnt;\n                dfs(c, v);\n     \
    \           low[v] = std::min(low[v], low[c]);\n                if (p != -1 &&\
    \ ord[v] <= low[c]) is_articulation = true;\n                if (ord[v] < low[c])\
    \ bridge.emplace_back(std::min(v, c), std::max(v, c));\n            } else if\
    \ (c != p) {\n                low[v] = std::min(low[v], ord[c]);\n           \
    \ }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n    \
    \    if (is_articulation) articulation.push_back(v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.cpp
  requiredBy: []
  timestamp: '2020-09-28 15:24:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/GRL_3_B.test.cpp
documentation_of: graph/lowlink.cpp
layout: document
redirect_from:
- /library/graph/lowlink.cpp
- /library/graph/lowlink.cpp.html
title: Lowlink
---
