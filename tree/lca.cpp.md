---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tree/auxiliary_tree.cpp
    title: Auxiliary Tree
  - icon: ':warning:'
    path: tree/binary_lifting.hpp
    title: Binary Lifting
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
    \      return depth[u] + depth[v] - 2 * depth[query(u, v)];\n    }\n\n    int\
    \ parent(int v, int k) const {\n        for (int i = LOG - 1; i >= 0; --i) {\n\
    \            if (k >= (1 << i)) {\n                v = table[i][v];\n        \
    \        k -= 1 << i;\n            }\n        }\n        return v;\n    }\n\n\
    \    int jump(int u, int v, int k) const {\n        int l = query(u, v);\n   \
    \     int du = depth[u] - depth[l];\n        int dv = depth[v] - depth[l];\n \
    \       if (du + dv < k) return -1;\n        if (k < du) return parent(u, k);\n\
    \        return parent(v, du + dv - k);\n    }\n\n\nprotected:\n    const std::vector<std::vector<int>>&\
    \ G;\n    const int LOG;\n    std::vector<std::vector<int>> table;\n    std::vector<int>\
    \ depth;\n\n    void dfs(int v, int p, int d) {\n        table[0][v] = p;\n  \
    \      depth[v] = d;\n        for (int c : G[v]) {\n            if (c != p) dfs(c,\
    \ v, d + 1);\n        }\n    }\n};\n"
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
    \      return depth[u] + depth[v] - 2 * depth[query(u, v)];\n    }\n\n    int\
    \ parent(int v, int k) const {\n        for (int i = LOG - 1; i >= 0; --i) {\n\
    \            if (k >= (1 << i)) {\n                v = table[i][v];\n        \
    \        k -= 1 << i;\n            }\n        }\n        return v;\n    }\n\n\
    \    int jump(int u, int v, int k) const {\n        int l = query(u, v);\n   \
    \     int du = depth[u] - depth[l];\n        int dv = depth[v] - depth[l];\n \
    \       if (du + dv < k) return -1;\n        if (k < du) return parent(u, k);\n\
    \        return parent(v, du + dv - k);\n    }\n\n\nprotected:\n    const std::vector<std::vector<int>>&\
    \ G;\n    const int LOG;\n    std::vector<std::vector<int>> table;\n    std::vector<int>\
    \ depth;\n\n    void dfs(int v, int p, int d) {\n        table[0][v] = p;\n  \
    \      depth[v] = d;\n        for (int c : G[v]) {\n            if (c != p) dfs(c,\
    \ v, d + 1);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/lca.cpp
  requiredBy:
  - tree/auxiliary_tree.cpp
  - tree/binary_lifting.hpp
  timestamp: '2022-08-04 12:02:47+09:00'
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
    - 時間計算量: $O(n\log n)$
- `int query(int u, int v)`
    - 頂点 $u$ と頂点 $v$ の最小共通祖先を返す
    - 時間計算量: $O(\log n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\log n)$
- `int parent(int v, int k)`
    - 頂点 $v$ の $k$ 個上の頂点を求める
- `int jump(int u, int v, int k)`
    - $uv$ パス上の $k$ 番目の頂点を返す．$k=0$ のとき $u$ を，$k>dist(u,v)$ のとき $-1$ を返す．
    - 時間計算量: $O(\log n)$

## Reference

- [Lowest common ancestor](https://en.wikipedia.org/wiki/Lowest_common_ancestor)
- [Lowest common ancestor's binary lifting method for path queries on trees](https://codeforces.com/blog/entry/22325)
- [Lowest Common Ancestor - Tarjan's off-line algorithm](https://cp-algorithms.com/graph/lca_tarjan.html)
- [Lowest Common Ancestor - Farach-Colton and Bender Algorithm](https://cp-algorithms.com/graph/lca_farachcoltonbender.html)
- [Solve RMQ (Range Minimum Query) by finding LCA (Lowest Common Ancestor)](https://cp-algorithms.com/graph/rmq_linear.html)