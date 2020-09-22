---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/twosat.cpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/graph/scc.md
    document_title: Strongly Connected Components
    links: []
  bundledCode: "#line 1 \"graph/scc.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Strongly Connected Components\n * @docs docs/graph/scc.md\n */\nclass SCC {\n\
    public:\n    SCC() = default;\n    explicit SCC(int n) : G(n), G_rev(n), comp(n,\
    \ -1), visited(n) {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n\
    \        G_rev[v].push_back(u);\n    }\n\n    void build() {\n        for (int\
    \ v = 0; v < (int) G.size(); ++v) dfs(v);\n        std::reverse(order.begin(),\
    \ order.end());\n        cnt = 0;\n        for (int v : order) if (comp[v] ==\
    \ -1) rdfs(v, cnt++);\n    }\n\n    int operator[](int i) const {\n        return\
    \ comp[i];\n    }\n\n    int count() const noexcept {\n        return cnt;\n \
    \   }\n\nprivate:\n    std::vector<std::vector<int>> G, G_rev;\n    std::vector<int>\
    \ comp, order;\n    std::vector<bool> visited;\n    int cnt;\n\n    void dfs(int\
    \ u) {\n        if (visited[u]) return;\n        visited[u] = true;\n        for\
    \ (int v : G[u]) dfs(v);\n        order.push_back(u);\n    }\n\n    void rdfs(int\
    \ u, int c) {\n        if (comp[u] != -1) return;\n        comp[u] = c;\n    \
    \    for (int v : G_rev[u]) rdfs(v, c);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Strongly Connected Components\n\
    \ * @docs docs/graph/scc.md\n */\nclass SCC {\npublic:\n    SCC() = default;\n\
    \    explicit SCC(int n) : G(n), G_rev(n), comp(n, -1), visited(n) {}\n\n    void\
    \ add_edge(int u, int v) {\n        G[u].push_back(v);\n        G_rev[v].push_back(u);\n\
    \    }\n\n    void build() {\n        for (int v = 0; v < (int) G.size(); ++v)\
    \ dfs(v);\n        std::reverse(order.begin(), order.end());\n        cnt = 0;\n\
    \        for (int v : order) if (comp[v] == -1) rdfs(v, cnt++);\n    }\n\n   \
    \ int operator[](int i) const {\n        return comp[i];\n    }\n\n    int count()\
    \ const noexcept {\n        return cnt;\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G, G_rev;\n    std::vector<int> comp, order;\n    std::vector<bool> visited;\n\
    \    int cnt;\n\n    void dfs(int u) {\n        if (visited[u]) return;\n    \
    \    visited[u] = true;\n        for (int v : G[u]) dfs(v);\n        order.push_back(u);\n\
    \    }\n\n    void rdfs(int u, int c) {\n        if (comp[u] != -1) return;\n\
    \        comp[u] = c;\n        for (int v : G_rev[u]) rdfs(v, c);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.cpp
  requiredBy:
  - graph/twosat.cpp
  timestamp: '2020-09-23 00:47:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_C.test.cpp
  - test/yosupo/two_sat.test.cpp
documentation_of: graph/scc.cpp
layout: document
redirect_from:
- /library/graph/scc.cpp
- /library/graph/scc.cpp.html
title: Strongly Connected Components
---
# Strongly Connected Components

グラフ $G$ の強連結成分分解をする．

この実装では Kosaraju のアルゴリズムを用いている．

強連結成分を一つの頂点に縮約すると，有向非巡回グラフ (DAG) が得られる．

強連結成分のラベルはトポロジカル順序になっている．

空間計算量: $O(V + E)$

## Constructor

- `SCC(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$

## Member functions

- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `void build()`
    - 強連結成分分解をする
    - 時間計算量: $O(V + E)$
- `int operator[](int i)`
    - 頂点 $i$ が属する強連結成分のラベルを返す
    - 時間計算量: $O(1)$
- `int count()`
    - 強連結成分の数を返す
    - 時間計算量: $O(1)$