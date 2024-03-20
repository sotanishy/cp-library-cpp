---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/hld.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename M>\nclass HLD {\n    using T = M::T;\n\n   public:\n    HLD()\
    \ = default;\n    HLD(const std::vector<std::vector<int>>& G, bool edge)\n   \
    \     : G(G),\n          size(G.size()),\n          depth(G.size()),\n       \
    \   par(G.size(), -1),\n          in(G.size()),\n          out(G.size()),\n  \
    \        head(G.size()),\n          heavy(G.size(), -1),\n          edge(edge)\
    \ {\n        dfs(0);\n        decompose(0, 0);\n    }\n\n    template <typename\
    \ F>\n    void update(int v, const T& x, const F& f) const {\n        f(in[v],\
    \ x);\n    }\n\n    template <typename F>\n    void update_edge(int u, int v,\
    \ const T& x, const F& f) const {\n        if (in[u] > in[v]) std::swap(u, v);\n\
    \        f(in[v], x);\n    }\n\n    template <typename E, typename F>\n    void\
    \ update(int u, int v, const E& x, const F& f) const {\n        while (head[u]\
    \ != head[v]) {\n            if (in[head[u]] > in[head[v]]) std::swap(u, v);\n\
    \            f(in[head[v]], in[v] + 1, x);\n            v = par[head[v]];\n  \
    \      }\n        if (in[u] > in[v]) std::swap(u, v);\n        f(in[u] + edge,\
    \ in[v] + 1, x);\n    }\n\n    template <typename F, typename Flip>\n    T path_fold(int\
    \ u, int v, const F& f, const Flip& flip) const {\n        bool flipped = false;\n\
    \        T resu = M::id(), resv = M::id();\n        while (head[u] != head[v])\
    \ {\n            if (in[head[u]] > in[head[v]]) {\n                std::swap(u,\
    \ v);\n                std::swap(resu, resv);\n                flipped ^= true;\n\
    \            }\n            T val = f(in[head[v]], in[v] + 1);\n            resv\
    \ = M::op(val, resv);\n            v = par[head[v]];\n        }\n        if (in[u]\
    \ > in[v]) {\n            std::swap(u, v);\n            std::swap(resu, resv);\n\
    \            flipped ^= true;\n        }\n        T val = f(in[u] + edge, in[v]\
    \ + 1);\n        resv = M::op(val, resv);\n        resv = M::op(flip(resu), resv);\n\
    \        if (flipped) {\n            resv = flip(resv);\n        }\n        return\
    \ resv;\n    }\n\n    template <typename F>\n    T path_fold(int u, int v, const\
    \ F& f) const {\n        return path_fold(u, v, f, [&](auto& v) { return v; });\n\
    \    }\n\n    template <typename F>\n    T subtree_fold(int v, const F& f) const\
    \ {\n        return f(in[v] + edge, out[v]);\n    }\n\n    int lca(int u, int\
    \ v) const {\n        while (true) {\n            if (in[u] > in[v]) std::swap(u,\
    \ v);\n            if (head[u] == head[v]) return u;\n            v = par[head[v]];\n\
    \        }\n    }\n\n    int dist(int u, int v) const {\n        return depth[u]\
    \ + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n   private:\n    std::vector<std::vector<int>>\
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
    \ M>\nclass HLD {\n    using T = M::T;\n\n   public:\n    HLD() = default;\n \
    \   HLD(const std::vector<std::vector<int>>& G, bool edge)\n        : G(G),\n\
    \          size(G.size()),\n          depth(G.size()),\n          par(G.size(),\
    \ -1),\n          in(G.size()),\n          out(G.size()),\n          head(G.size()),\n\
    \          heavy(G.size(), -1),\n          edge(edge) {\n        dfs(0);\n   \
    \     decompose(0, 0);\n    }\n\n    template <typename F>\n    void update(int\
    \ v, const T& x, const F& f) const {\n        f(in[v], x);\n    }\n\n    template\
    \ <typename F>\n    void update_edge(int u, int v, const T& x, const F& f) const\
    \ {\n        if (in[u] > in[v]) std::swap(u, v);\n        f(in[v], x);\n    }\n\
    \n    template <typename E, typename F>\n    void update(int u, int v, const E&\
    \ x, const F& f) const {\n        while (head[u] != head[v]) {\n            if\
    \ (in[head[u]] > in[head[v]]) std::swap(u, v);\n            f(in[head[v]], in[v]\
    \ + 1, x);\n            v = par[head[v]];\n        }\n        if (in[u] > in[v])\
    \ std::swap(u, v);\n        f(in[u] + edge, in[v] + 1, x);\n    }\n\n    template\
    \ <typename F, typename Flip>\n    T path_fold(int u, int v, const F& f, const\
    \ Flip& flip) const {\n        bool flipped = false;\n        T resu = M::id(),\
    \ resv = M::id();\n        while (head[u] != head[v]) {\n            if (in[head[u]]\
    \ > in[head[v]]) {\n                std::swap(u, v);\n                std::swap(resu,\
    \ resv);\n                flipped ^= true;\n            }\n            T val =\
    \ f(in[head[v]], in[v] + 1);\n            resv = M::op(val, resv);\n         \
    \   v = par[head[v]];\n        }\n        if (in[u] > in[v]) {\n            std::swap(u,\
    \ v);\n            std::swap(resu, resv);\n            flipped ^= true;\n    \
    \    }\n        T val = f(in[u] + edge, in[v] + 1);\n        resv = M::op(val,\
    \ resv);\n        resv = M::op(flip(resu), resv);\n        if (flipped) {\n  \
    \          resv = flip(resv);\n        }\n        return resv;\n    }\n\n    template\
    \ <typename F>\n    T path_fold(int u, int v, const F& f) const {\n        return\
    \ path_fold(u, v, f, [&](auto& v) { return v; });\n    }\n\n    template <typename\
    \ F>\n    T subtree_fold(int v, const F& f) const {\n        return f(in[v] +\
    \ edge, out[v]);\n    }\n\n    int lca(int u, int v) const {\n        while (true)\
    \ {\n            if (in[u] > in[v]) std::swap(u, v);\n            if (head[u]\
    \ == head[v]) return u;\n            v = par[head[v]];\n        }\n    }\n\n \
    \   int dist(int u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u,\
    \ v)];\n    }\n\n   private:\n    std::vector<std::vector<int>> G;\n    std::vector<int>\
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
  path: tree/hld.hpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/vertex_add_subtree_sum.hld.test.cpp
documentation_of: tree/hld.hpp
layout: document
title: Heavy-Light Decomposition
---

## Description

HL 分解 (重軽分解) は，木をいくつかのパスに分解する手法である．分解されたパスからなる木は高さが高々 $O(\log n)$ になる．列に対するクエリを処理するデータ構造を用いて各パスを管理することにより，木上のパスクエリを高速に処理することができる．

空間計算量: $O(n)$

## Operations

`update` および `fold` の時間計算量を $f(n)$ とする

- `HLD(vector<vector<int>> G, bool edge)`
    - 木 `G` を HL 分解する．`edge == true` ならクエリは辺に対して実行される．
    - 時間計算量: $O(n)$
- `void update(int v, T x, F update)`
    - 頂点 $v$ に対して `update(x)` を実行する
    - 時間計算量: $O(f(n) \log n)$
- `void update_edge(int u, int v, T x, F update)`
    - 辺 $(u, v)$ に対して `update(x)` を実行する
    - 時間計算量: $O(f(n) \log n)$
- `void update(int u, int v, T x, F update)`
    - $uv$ パス上の頂点/辺に対して `update(x)` を実行する．
    - 時間計算量: $O(f(n) \log n)$
- `T path_fold(int u, int v, F fold)`
    - $uv$ パス上の頂点/辺に対して `fold()` を実行する．
    - 時間計算量: $O(f(n) \log n)$
- `T path_fold(int u, int v, F fold, Flip flip)`
    - $uv$ パス上の頂点/辺に対して `fold()` を実行する．値が非可換なら，左から積をとったときと右から積をとったときの値を入れ替える `flip` 関数を与える必要がある．
    - 時間計算量: $O(f(n) \log n)$
- `T subtree_fold(int v, F fold)`
    - 頂点 $v$ を根とする部分木の頂点/辺に対して `fold()` を実行する．
    - 時間計算量: $O(f(n))$
- `int lca(int u, int v)`
    - 頂点 $u$ と頂点 $v$ の最小共通祖先を返す
    - 時間計算量: $O(\log n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\log n)$

## Reference

- [Heavy-Light Decomposition](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [Heavy-light decomposition](https://cp-algorithms.com/graph/hld.html)
- [Easiest HLD with subtree queries](https://codeforces.com/blog/entry/53170)