---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/lca.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \nclass LCA {\npublic:\n    LCA() = default;\n    LCA(const std::vector<std::vector<int>>&\
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
    \            if (c != p) dfs(c, v, d + 1);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nclass LCA {\npublic:\n\
    \    LCA() = default;\n    LCA(const std::vector<std::vector<int>>& G, int root)\
    \ : G(G), LOG(32 - __builtin_clz(G.size())), depth(G.size()) {\n        int V\
    \ = G.size();\n        table.assign(LOG, std::vector<int>(V, -1));\n\n       \
    \ dfs(root, -1, 0);\n\n        for (int k = 0; k < LOG - 1; ++k) {\n         \
    \   for (int v = 0; v < V; ++v) {\n                if (table[k][v] >= 0) {\n \
    \                   table[k + 1][v] = table[k][table[k][v]];\n               \
    \ }\n            }\n        }\n    }\n\n    int query(int u, int v) const {\n\
    \        if (depth[u] > depth[v]) std::swap(u, v);\n\n        // go up to the\
    \ same depth\n        for (int k = 0; k < LOG; ++k) {\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) {\n                v = table[k][v];\n            }\n \
    \       }\n        if (u == v) return u;\n\n        for (int k = LOG - 1; k >=\
    \ 0; --k) {\n            if (table[k][u] != table[k][v]) {\n                u\
    \ = table[k][u];\n                v = table[k][v];\n            }\n        }\n\
    \        return table[0][u];\n    }\n\n    int dist(int u, int v) const {\n  \
    \      return depth[u] + depth[v] - 2 * depth[query(u, v)];\n    }\n\nprivate:\n\
    \    const std::vector<std::vector<int>>& G;\n    const int LOG;\n    std::vector<std::vector<int>>\
    \ table;\n    std::vector<int> depth;\n\n    void dfs(int v, int p, int d) {\n\
    \        table[0][v] = p;\n        depth[v] = d;\n        for (int c : G[v]) {\n\
    \            if (c != p) dfs(c, v, d + 1);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/lca.cpp
  requiredBy: []
  timestamp: '2021-01-17 17:56:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.test.cpp
  - test/aoj/GRL_5_C.test.cpp
documentation_of: tree/lca.cpp
layout: document
title: Lowest Common Ancestor
---

## Description

根付き木の2頂点間の最小共通祖先を計算する．この実装ではダブリングを用いている．

## Operations

- `LCA(vector<vector<int>> G, int root)`
    - 前計算をする
    - 時間計算量: $O(n\lg n)$
- `int query(int u, int v)`
    - 頂点 $u$ と頂点 $v$ の最小共通祖先を返す
    - 時間計算量: $O(\lg n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\lg n)$

## Reference

- [Lowest common ancestor](https://en.wikipedia.org/wiki/Lowest_common_ancestor)
- [Lowest common ancestor's binary lifting method for path queries on trees](https://codeforces.com/blog/entry/22325)
- [Lowest Common Ancestor - Tarjan's off-line algorithm](https://cp-algorithms.com/graph/lca_tarjan.html)
- [Lowest Common Ancestor - Farach-Colton and Bender Algorithm](https://cp-algorithms.com/graph/lca_farachcoltonbender.html)
- [Solve RMQ (Range Minimum Query) by finding LCA (Lowest Common Ancestor)](https://cp-algorithms.com/graph/rmq_linear.html)

## TODO

- パスクエリ
- オイラーツアー
- Tarjan's offline algorithm
- Farach-Colton and Bender algorithm
- RMQ