---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Lifting
    links: []
  bundledCode: "#line 2 \"tree/binary_lifting.hpp\"\n#include <vector>\n#line 2 \"\
    tree/lca.cpp\"\n#include <algorithm>\n#line 4 \"tree/lca.cpp\"\n\nclass LCA {\n\
    public:\n    LCA() = default;\n    LCA(const std::vector<std::vector<int>>& G,\
    \ int root) : G(G), LOG(32 - __builtin_clz(G.size())), depth(G.size()) {\n   \
    \     int V = G.size();\n        table.assign(LOG, std::vector<int>(V, -1));\n\
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
    protected:\n    const std::vector<std::vector<int>>& G;\n    const int LOG;\n\
    \    std::vector<std::vector<int>> table;\n    std::vector<int> depth;\n\n   \
    \ void dfs(int v, int p, int d) {\n        table[0][v] = p;\n        depth[v]\
    \ = d;\n        for (int c : G[v]) {\n            if (c != p) dfs(c, v, d + 1);\n\
    \        }\n    }\n};\n#line 4 \"tree/binary_lifting.hpp\"\n\n/**\n * @brief Binary\
    \ Lifting\n */\ntemplate <typename M>\nclass BinaryLifting : public LCA {\n  \
    \  using T = typename M::T;\n\npublic:\n    BinaryLifting() = default;\n    BinaryLifting(const\
    \ std::vector<std::vector<int>>& G, const std::vector<T> vs, int root) : LCA(G,\
    \ root) {\n        int V = G.size();\n        val.assign(LOG, std::vector<int>(V,\
    \ M::id()));\n        val[0] = vs;\n\n        for (int k = 0; k < LOG - 1; ++k)\
    \ {\n            for (int v = 0; v < V; ++v) {\n                if (table[k][v]\
    \ >= 0) {\n                    val[k + 1][v] = M::op(val[k][v], val[k][table[k][v]]);\n\
    \                }\n            }\n        }\n    }\n\n    T fold(int u, int v)\
    \ const {\n        bool flipped = false;\n        if (depth[u] > depth[v]) {\n\
    \            std::swap(u, v);\n            flipped = true;\n        }\n      \
    \  T resu = M::id(), resv = M::id();\n\n        // go up to the same depth\n \
    \       for (int k = 0; k < LOG; ++k) {\n            if ((depth[v] - depth[u])\
    \ >> k & 1) {\n                resv = M::op(resv, val[k][v]);\n              \
    \  v = table[k][v];\n            }\n        }\n        if (u == v) {\n       \
    \     resu = M::op(val[0][u], M::flip(resv));\n            if (flipped) resu =\
    \ M::flip(resu);\n            return resu;\n        }\n\n        for (int k =\
    \ LOG - 1; k >= 0; --k) {\n            if (table[k][u] != table[k][v]) {\n   \
    \             resu = M::op(resu, val[k][u]);\n                resv = M::op(resv,\
    \ val[k][v]);\n                u = table[k][u];\n                v = table[k][v];\n\
    \            }\n        }\n        resu = M::op(M::op(resu, val[0][table[0][u]]),\
    \ M::flip(resv));\n        if (flipped) resu = M::flip(resu);\n        return\
    \ resu;\n    }\n\nprivate:\n    std::vector<std::vector<T>> val;\n};\n"
  code: "#pragma once\n#include <vector>\n#include \"lca.cpp\"\n\n/**\n * @brief Binary\
    \ Lifting\n */\ntemplate <typename M>\nclass BinaryLifting : public LCA {\n  \
    \  using T = typename M::T;\n\npublic:\n    BinaryLifting() = default;\n    BinaryLifting(const\
    \ std::vector<std::vector<int>>& G, const std::vector<T> vs, int root) : LCA(G,\
    \ root) {\n        int V = G.size();\n        val.assign(LOG, std::vector<int>(V,\
    \ M::id()));\n        val[0] = vs;\n\n        for (int k = 0; k < LOG - 1; ++k)\
    \ {\n            for (int v = 0; v < V; ++v) {\n                if (table[k][v]\
    \ >= 0) {\n                    val[k + 1][v] = M::op(val[k][v], val[k][table[k][v]]);\n\
    \                }\n            }\n        }\n    }\n\n    T fold(int u, int v)\
    \ const {\n        bool flipped = false;\n        if (depth[u] > depth[v]) {\n\
    \            std::swap(u, v);\n            flipped = true;\n        }\n      \
    \  T resu = M::id(), resv = M::id();\n\n        // go up to the same depth\n \
    \       for (int k = 0; k < LOG; ++k) {\n            if ((depth[v] - depth[u])\
    \ >> k & 1) {\n                resv = M::op(resv, val[k][v]);\n              \
    \  v = table[k][v];\n            }\n        }\n        if (u == v) {\n       \
    \     resu = M::op(val[0][u], M::flip(resv));\n            if (flipped) resu =\
    \ M::flip(resu);\n            return resu;\n        }\n\n        for (int k =\
    \ LOG - 1; k >= 0; --k) {\n            if (table[k][u] != table[k][v]) {\n   \
    \             resu = M::op(resu, val[k][u]);\n                resv = M::op(resv,\
    \ val[k][v]);\n                u = table[k][u];\n                v = table[k][v];\n\
    \            }\n        }\n        resu = M::op(M::op(resu, val[0][table[0][u]]),\
    \ M::flip(resv));\n        if (flipped) resu = M::flip(resu);\n        return\
    \ resu;\n    }\n\nprivate:\n    std::vector<std::vector<T>> val;\n};\n"
  dependsOn:
  - tree/lca.cpp
  isVerificationFile: false
  path: tree/binary_lifting.hpp
  requiredBy: []
  timestamp: '2022-07-02 23:35:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/binary_lifting.hpp
layout: document
redirect_from:
- /library/tree/binary_lifting.hpp
- /library/tree/binary_lifting.hpp.html
title: Binary Lifting
---
