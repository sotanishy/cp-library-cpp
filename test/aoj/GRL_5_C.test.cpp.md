---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#line 2 \"tree/lca.cpp\"\n#include <algorithm>\n#include <vector>\n\nclass\
    \ LCA {\npublic:\n    LCA() = default;\n    LCA(const std::vector<std::vector<int>>&\
    \ G, int root) : G(G), LOG(32 - __builtin_clz(G.size())), depth(G.size()) {\n\
    \        int V = G.size();\n        table.assign(LOG, std::vector<int>(V, -1));\n\
    \n        dfs(root, -1, 0);\n\n        for (int k = 0; k < LOG - 1; ++k) {\n \
    \           for (int v = 0; v < V; ++v) {\n                if (table[k][v] >=\
    \ 0) {\n                    table[k + 1][v] = table[k][table[k][v]];\n       \
    \         }\n            }\n        }\n    }\n\n    int query(int u, int v) const\
    \ {\n        if (depth[u] > depth[v]) std::swap(u, v);\n\n        // go up to\
    \ the same depth\n        for (int k = 0; k < LOG; ++k) {\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) {\n                v = table[k][v];\n            }\n \
    \       }\n        if (u == v) return u;\n\n        for (int k = LOG - 1; k >=\
    \ 0; --k) {\n            if (table[k][u] != table[k][v]) {\n                u\
    \ = table[k][u];\n                v = table[k][v];\n            }\n        }\n\
    \        return table[0][u];\n    }\n\n    int dist(int u, int v) const {\n  \
    \      return depth[u] + depth[v] - 2 * depth[query(u, v)];\n    }\n\nprivate:\n\
    \    const std::vector<std::vector<int>>& G;\n    const int LOG;\n    std::vector<std::vector<int>>\
    \ table;\n    std::vector<int> depth;\n\n    void dfs(int v, int p, int d) {\n\
    \        table[0][v] = p;\n        depth[v] = d;\n        for (int c : G[v]) {\n\
    \            if (c != p) dfs(c, v, d + 1);\n        }\n    }\n};\n#line 4 \"test/aoj/GRL_5_C.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    vector<vector<int>> G(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int k;\n        cin >> k;\n      \
    \  for (int j = 0; j < k; j++) {\n            int c;\n            cin >> c;\n\
    \            G[i].push_back(c);\n        }\n    }\n    LCA lca(G, 0);\n    int\
    \ q;\n    cin >> q;\n    for (int i = 0; i < q; i++) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        cout << lca.query(u, v) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include \"../../tree/lca.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int n;\n    cin >> n;\n    vector<vector<int>> G(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        int k;\n        cin >> k;\n        for (int j = 0; j\
    \ < k; j++) {\n            int c;\n            cin >> c;\n            G[i].push_back(c);\n\
    \        }\n    }\n    LCA lca(G, 0);\n    int q;\n    cin >> q;\n    for (int\
    \ i = 0; i < q; i++) {\n        int u, v;\n        cin >> u >> v;\n        cout\
    \ << lca.query(u, v) << \"\\n\";\n    }\n}"
  dependsOn:
  - tree/lca.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 17:56:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---
