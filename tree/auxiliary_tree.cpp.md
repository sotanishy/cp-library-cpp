---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/auxiliary_tree.cpp\"\n#include <stack>\n#include <utility>\n\
    #include <vector>\n#line 2 \"tree/lca.cpp\"\n#include <algorithm>\n#line 4 \"\
    tree/lca.cpp\"\n\nclass LCA {\npublic:\n    LCA() = default;\n    LCA(const std::vector<std::vector<int>>&\
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
    private:\n    const std::vector<std::vector<int>>& G;\n    const int LOG;\n  \
    \  std::vector<std::vector<int>> table;\n    std::vector<int> depth;\n\n    void\
    \ dfs(int v, int p, int d) {\n        table[0][v] = p;\n        depth[v] = d;\n\
    \        for (int c : G[v]) {\n            if (c != p) dfs(c, v, d + 1);\n   \
    \     }\n    }\n};\n#line 6 \"tree/auxiliary_tree.cpp\"\n\nclass AuxiliaryTree\
    \ {\npublic:\n    AuxiliaryTree() = default;\n    AuxiliaryTree(std::vector<std::vector<int>>&\
    \ G, int root) : G(G), lca(G, root), ord(G.size()), depth(G.size()) {\n      \
    \  dfs(root, -1);\n    }\n\n    std::vector<std::pair<int, int>> query(std::vector<int>\
    \ vs) {\n        std::sort(vs.begin(), vs.end(), [&](int u, int v) {\n       \
    \     return ord[u] < ord[v];\n        });\n        std::vector<std::pair<int,\
    \ int>> edges;\n        std::stack<int> st;\n        st.push(vs[0]);\n       \
    \ for (int i = 1; i < (int) vs.size(); ++i) {\n            int l = lca.query(vs[i\
    \ - 1], vs[i]);\n            if (l != vs[i - 1]) {\n                int u = st.top();\n\
    \                st.pop();\n                while (!st.empty() && depth[l] < depth[st.top()])\
    \ {\n                    edges.push_back({u, st.top()});\n                   \
    \ u = st.top();\n                    st.pop();\n                }\n          \
    \      edges.push_back({u, l});\n                if (st.empty() || st.top() !=\
    \ l) st.push(l);\n            }\n            st.push(vs[i]);\n        }\n    \
    \    while (st.size() > 1) {\n            int u = st.top();\n            st.pop();\n\
    \            edges.push_back({u, st.top()});\n        }\n        return edges;\n\
    \    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    LCA lca;\n    std::vector<int>\
    \ ord, depth;\n    int k = 0;\n\n    void dfs(int v, int p) {\n        ord[v]\
    \ = k++;\n        for (int c : G[v]) {\n            if (c != p) {\n          \
    \      depth[c] = depth[v] + 1;\n                dfs(c, v);\n            }\n \
    \       }\n    }\n};\n"
  code: "#pragma once\n#include <stack>\n#include <utility>\n#include <vector>\n#include\
    \ \"lca.cpp\"\n\nclass AuxiliaryTree {\npublic:\n    AuxiliaryTree() = default;\n\
    \    AuxiliaryTree(std::vector<std::vector<int>>& G, int root) : G(G), lca(G,\
    \ root), ord(G.size()), depth(G.size()) {\n        dfs(root, -1);\n    }\n\n \
    \   std::vector<std::pair<int, int>> query(std::vector<int> vs) {\n        std::sort(vs.begin(),\
    \ vs.end(), [&](int u, int v) {\n            return ord[u] < ord[v];\n       \
    \ });\n        std::vector<std::pair<int, int>> edges;\n        std::stack<int>\
    \ st;\n        st.push(vs[0]);\n        for (int i = 1; i < (int) vs.size(); ++i)\
    \ {\n            int l = lca.query(vs[i - 1], vs[i]);\n            if (l != vs[i\
    \ - 1]) {\n                int u = st.top();\n                st.pop();\n    \
    \            while (!st.empty() && depth[l] < depth[st.top()]) {\n           \
    \         edges.push_back({u, st.top()});\n                    u = st.top();\n\
    \                    st.pop();\n                }\n                edges.push_back({u,\
    \ l});\n                if (st.empty() || st.top() != l) st.push(l);\n       \
    \     }\n            st.push(vs[i]);\n        }\n        while (st.size() > 1)\
    \ {\n            int u = st.top();\n            st.pop();\n            edges.push_back({u,\
    \ st.top()});\n        }\n        return edges;\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    LCA lca;\n    std::vector<int> ord, depth;\n    int k = 0;\n\n    void\
    \ dfs(int v, int p) {\n        ord[v] = k++;\n        for (int c : G[v]) {\n \
    \           if (c != p) {\n                depth[c] = depth[v] + 1;\n        \
    \        dfs(c, v);\n            }\n        }\n    }\n};"
  dependsOn:
  - tree/lca.cpp
  isVerificationFile: false
  path: tree/auxiliary_tree.cpp
  requiredBy: []
  timestamp: '2022-03-20 18:18:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/auxiliary_tree.cpp
layout: document
title: Auxiliary Tree
---

## Description

Auxiliary tree は，木の頂点のある部分集合と集合内の頂点間の LCA のみを含み，頂点同士の関係を保ったままもとの木を圧縮したものである．

## Operations

- `AuxiliaryTree(vector<vector<int>> G, int root)`
    - 前計算をする
    - 時間計算量: $O(n\log n)$
- `vector<pair<int, int>> query(vector<int> vs)`
    - 頂点集合 `vs` から定まる auxiliary tree の辺を返す
    - 時間計算量: $O(k\log n)$

## Reference

- [LCAをベースに構築するAuxiliary Treeのメモ](https://smijake3.hatenablog.com/entry/2019/09/15/200200)
- verify: [https://atcoder.jp/contests/typical90/submissions/30186948]()