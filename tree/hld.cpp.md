---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/hld.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename M>\nclass HLD {\n    using T = typename M::T;\n\npublic:\n\
    \    HLD() = default;\n    HLD(const std::vector<std::vector<int>>& G, bool edge)\n\
    \        : G(G), size(G.size()), depth(G.size()), par(G.size(), -1),\n       \
    \   in(G.size()), out(G.size()), head(G.size()), heavy(G.size(), -1), edge(edge)\
    \ {\n        dfs(0);\n        decompose(0, 0);\n    }\n\n    template <typename\
    \ F>\n    void update(int v, const T& x, const F& f) const {\n        f(in[v],\
    \ x);\n    }\n\n    template <typename E, typename F>\n    void update(int u,\
    \ int v, const E& x, const F& f) const {\n        while (head[u] != head[v]) {\n\
    \            if (in[head[u]] > in[head[v]]) std::swap(u, v);\n            f(in[head[v]],\
    \ in[v] + 1, x);\n            v = par[head[v]];\n        }\n        if (in[u]\
    \ > in[v]) std::swap(u, v);\n        f(in[u] + edge, in[v] + 1, x);\n    }\n\n\
    \    template <typename F>\n    T path_fold(int u, int v, const F& f) const {\n\
    \        T res = M::id;\n        while (head[u] != head[v]) {\n            if\
    \ (in[head[u]] > in[head[v]]) std::swap(u, v);\n            T val = f(in[head[v]],\
    \ in[v] + 1);\n            res = M::op(val, res);\n            v = par[head[v]];\n\
    \        }\n        if (in[u] > in[v]) std::swap(u, v);\n        T val = f(in[u]\
    \ + edge, in[v] + 1);\n        return M::op(val, res);\n    }\n\n    template\
    \ <typename F>\n    T subtree_fold(int v, const F& f) const {\n        return\
    \ f(in[v] + edge, out[v]);\n    }\n\n    int lca(int u, int v) const {\n     \
    \   while (true) {\n            if (in[u] > in[v]) std::swap(u, v);\n        \
    \    if (head[u] == head[v]) return u;\n            v = par[head[v]];\n      \
    \  }\n    }\n\n    int dist(int u, int v) const {\n        return depth[u] + depth[v]\
    \ - 2 * depth[lca(u, v)];\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> size, depth, par, in, out, head, heavy;\n    bool edge;\n\
    \    int cur_pos = 0;\n\n    void dfs(int v) {\n        size[v] = 1;\n       \
    \ int max_size = 0;\n        for (int c : G[v]) {\n            if (c == par[v])\
    \ continue;\n            par[c] = v;\n            depth[c] = depth[v] + 1;\n \
    \           dfs(c);\n            size[v] += size[c];\n            if (size[c]\
    \ > max_size) {\n                max_size = size[c];\n                heavy[v]\
    \ = c;\n            }\n        }\n    }\n\n    void decompose(int v, int h) {\n\
    \        head[v] = h;\n        in[v] = cur_pos++;\n        if (heavy[v] != -1)\
    \ decompose(heavy[v], h);\n        for (int c : G[v]) {\n            if (c !=\
    \ par[v] && c != heavy[v]) decompose(c, c);\n        }\n        out[v] = cur_pos;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ M>\nclass HLD {\n    using T = typename M::T;\n\npublic:\n    HLD() = default;\n\
    \    HLD(const std::vector<std::vector<int>>& G, bool edge)\n        : G(G), size(G.size()),\
    \ depth(G.size()), par(G.size(), -1),\n          in(G.size()), out(G.size()),\
    \ head(G.size()), heavy(G.size(), -1), edge(edge) {\n        dfs(0);\n       \
    \ decompose(0, 0);\n    }\n\n    template <typename F>\n    void update(int v,\
    \ const T& x, const F& f) const {\n        f(in[v], x);\n    }\n\n    template\
    \ <typename E, typename F>\n    void update(int u, int v, const E& x, const F&\
    \ f) const {\n        while (head[u] != head[v]) {\n            if (in[head[u]]\
    \ > in[head[v]]) std::swap(u, v);\n            f(in[head[v]], in[v] + 1, x);\n\
    \            v = par[head[v]];\n        }\n        if (in[u] > in[v]) std::swap(u,\
    \ v);\n        f(in[u] + edge, in[v] + 1, x);\n    }\n\n    template <typename\
    \ F>\n    T path_fold(int u, int v, const F& f) const {\n        T res = M::id;\n\
    \        while (head[u] != head[v]) {\n            if (in[head[u]] > in[head[v]])\
    \ std::swap(u, v);\n            T val = f(in[head[v]], in[v] + 1);\n         \
    \   res = M::op(val, res);\n            v = par[head[v]];\n        }\n       \
    \ if (in[u] > in[v]) std::swap(u, v);\n        T val = f(in[u] + edge, in[v] +\
    \ 1);\n        return M::op(val, res);\n    }\n\n    template <typename F>\n \
    \   T subtree_fold(int v, const F& f) const {\n        return f(in[v] + edge,\
    \ out[v]);\n    }\n\n    int lca(int u, int v) const {\n        while (true) {\n\
    \            if (in[u] > in[v]) std::swap(u, v);\n            if (head[u] == head[v])\
    \ return u;\n            v = par[head[v]];\n        }\n    }\n\n    int dist(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<int>\
    \ size, depth, par, in, out, head, heavy;\n    bool edge;\n    int cur_pos = 0;\n\
    \n    void dfs(int v) {\n        size[v] = 1;\n        int max_size = 0;\n   \
    \     for (int c : G[v]) {\n            if (c == par[v]) continue;\n         \
    \   par[c] = v;\n            depth[c] = depth[v] + 1;\n            dfs(c);\n \
    \           size[v] += size[c];\n            if (size[c] > max_size) {\n     \
    \           max_size = size[c];\n                heavy[v] = c;\n            }\n\
    \        }\n    }\n\n    void decompose(int v, int h) {\n        head[v] = h;\n\
    \        in[v] = cur_pos++;\n        if (heavy[v] != -1) decompose(heavy[v], h);\n\
    \        for (int c : G[v]) {\n            if (c != par[v] && c != heavy[v]) decompose(c,\
    \ c);\n        }\n        out[v] = cur_pos;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/hld.cpp
  requiredBy: []
  timestamp: '2021-01-17 17:56:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
documentation_of: tree/hld.cpp
layout: document
redirect_from:
- /library/tree/hld.cpp
- /library/tree/hld.cpp.html
title: tree/hld.cpp
---
