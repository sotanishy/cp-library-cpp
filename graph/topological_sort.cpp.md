---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/graph/topological_sort.md
    document_title: Topological Sort
    links: []
  bundledCode: "#line 1 \"graph/topological_sort.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Topological Sort\n * @docs docs/graph/topological_sort.md\n */\n\
    std::vector<int> topological_sort(const std::vector<std::vector<int>>& G) {\n\
    \    int V = G.size();\n    std::vector<int> par_count(V);\n    for (int u = 0;\
    \ u < V; ++u) {\n        for (int v : G[u]) ++par_count[v];\n    }\n    std::stack<int>\
    \ start;\n    for (int v = 0; v < V; ++v) {\n        if (par_count[v] == 0) start.push(v);\n\
    \    }\n\n    std::vector<int> ret;\n    while (!start.empty()) {\n        int\
    \ u = start.top();\n        start.pop();\n        ret.push_back(u);\n        for\
    \ (int v : G[u]) {\n            --par_count[v];\n            if (par_count[v]\
    \ == 0) start.push(v);\n        }\n    }\n\n    for (int c : par_count) {\n  \
    \      if (c > 0) return std::vector<int>();\n    }\n    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Topological Sort\n * @docs docs/graph/topological_sort.md\n\
    \ */\nstd::vector<int> topological_sort(const std::vector<std::vector<int>>& G)\
    \ {\n    int V = G.size();\n    std::vector<int> par_count(V);\n    for (int u\
    \ = 0; u < V; ++u) {\n        for (int v : G[u]) ++par_count[v];\n    }\n    std::stack<int>\
    \ start;\n    for (int v = 0; v < V; ++v) {\n        if (par_count[v] == 0) start.push(v);\n\
    \    }\n\n    std::vector<int> ret;\n    while (!start.empty()) {\n        int\
    \ u = start.top();\n        start.pop();\n        ret.push_back(u);\n        for\
    \ (int v : G[u]) {\n            --par_count[v];\n            if (par_count[v]\
    \ == 0) start.push(v);\n        }\n    }\n\n    for (int c : par_count) {\n  \
    \      if (c > 0) return std::vector<int>();\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.cpp
layout: document
redirect_from:
- /library/graph/topological_sort.cpp
- /library/graph/topological_sort.cpp.html
title: Topological Sort
---
# Topological Sort

トポロジカルソートは，有向非巡回グラフ (DAG) の頂点を順序付けして，任意の辺 $(u, v)$ について $u$ が $v$ よりも前に来るように並べることである．

- `vector<int> topological_sort(vector<vector<int>>& G)`
    - $G$ のトポロジカルソートを返す．$G$ が DAG でないならば，空のリストを返す
    - 時間計算量: $O(V + E)$