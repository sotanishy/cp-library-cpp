---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_B.test.cpp
    title: test/aoj/GRL_5_B.test.cpp
  - icon: ':x:'
    path: test/yosupo/tree_path_composite_sum.test.cpp
    title: test/yosupo/tree_path_composite_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/rerooting.cpp\"\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename M, typename Cost,\n          typename M::T (*apply_edge)(typename\
    \ M::T, int, int, Cost),\n          typename M::T (*apply_vertex)(typename M::T,\
    \ int)>\nclass Rerooting {\n    using T = typename M::T;\n\n   public:\n    explicit\
    \ Rerooting(int n) : G(n) {}\n\n    void add_edge(int u, int v, Cost c) {\n  \
    \      G[u].emplace_back(v, c);\n        G[v].emplace_back(u, c);\n    }\n\n \
    \   std::vector<T> run() {\n        dp_sub.resize(G.size(), M::id());\n      \
    \  dp_all.resize(G.size());\n        dfs_sub(0, -1);\n        dfs_all(0, -1, M::id());\n\
    \        return dp_all;\n    }\n\n   private:\n    std::vector<std::vector<std::pair<int,\
    \ Cost>>> G;\n    std::vector<T> dp_sub, dp_all;\n\n    void dfs_sub(int v, int\
    \ p) {\n        for (auto [c, cost] : G[v]) {\n            if (c == p) continue;\n\
    \            dfs_sub(c, v);\n            dp_sub[v] = M::op(dp_sub[v], apply_edge(dp_sub[c],\
    \ v, c, cost));\n        }\n        dp_sub[v] = apply_vertex(dp_sub[v], v);\n\
    \    }\n\n    void dfs_all(int v, int p, const T& val) {\n        std::vector<T>\
    \ ds = {val};\n        for (auto [c, cost] : G[v]) {\n            if (c == p)\
    \ continue;\n            ds.push_back(apply_edge(dp_sub[c], v, c, cost));\n  \
    \      }\n        int n = ds.size();\n        std::vector<T> head(n + 1, M::id()),\
    \ tail(n + 1, M::id());\n        for (int i = 0; i < n; ++i) head[i + 1] = M::op(head[i],\
    \ ds[i]);\n        for (int i = n - 1; i >= 0; --i) tail[i] = M::op(ds[i], tail[i\
    \ + 1]);\n        dp_all[v] = apply_vertex(head[n], v);\n        int k = 1;\n\
    \        for (auto [c, cost] : G[v]) {\n            if (c == p) continue;\n  \
    \          dfs_all(c, v,\n                    apply_edge(apply_vertex(M::op(head[k],\
    \ tail[k + 1]), v), c,\n                               v, cost));\n          \
    \  ++k;\n        }\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ M, typename Cost,\n          typename M::T (*apply_edge)(typename M::T, int,\
    \ int, Cost),\n          typename M::T (*apply_vertex)(typename M::T, int)>\n\
    class Rerooting {\n    using T = typename M::T;\n\n   public:\n    explicit Rerooting(int\
    \ n) : G(n) {}\n\n    void add_edge(int u, int v, Cost c) {\n        G[u].emplace_back(v,\
    \ c);\n        G[v].emplace_back(u, c);\n    }\n\n    std::vector<T> run() {\n\
    \        dp_sub.resize(G.size(), M::id());\n        dp_all.resize(G.size());\n\
    \        dfs_sub(0, -1);\n        dfs_all(0, -1, M::id());\n        return dp_all;\n\
    \    }\n\n   private:\n    std::vector<std::vector<std::pair<int, Cost>>> G;\n\
    \    std::vector<T> dp_sub, dp_all;\n\n    void dfs_sub(int v, int p) {\n    \
    \    for (auto [c, cost] : G[v]) {\n            if (c == p) continue;\n      \
    \      dfs_sub(c, v);\n            dp_sub[v] = M::op(dp_sub[v], apply_edge(dp_sub[c],\
    \ v, c, cost));\n        }\n        dp_sub[v] = apply_vertex(dp_sub[v], v);\n\
    \    }\n\n    void dfs_all(int v, int p, const T& val) {\n        std::vector<T>\
    \ ds = {val};\n        for (auto [c, cost] : G[v]) {\n            if (c == p)\
    \ continue;\n            ds.push_back(apply_edge(dp_sub[c], v, c, cost));\n  \
    \      }\n        int n = ds.size();\n        std::vector<T> head(n + 1, M::id()),\
    \ tail(n + 1, M::id());\n        for (int i = 0; i < n; ++i) head[i + 1] = M::op(head[i],\
    \ ds[i]);\n        for (int i = n - 1; i >= 0; --i) tail[i] = M::op(ds[i], tail[i\
    \ + 1]);\n        dp_all[v] = apply_vertex(head[n], v);\n        int k = 1;\n\
    \        for (auto [c, cost] : G[v]) {\n            if (c == p) continue;\n  \
    \          dfs_all(c, v,\n                    apply_edge(apply_vertex(M::op(head[k],\
    \ tail[k + 1]), v), c,\n                               v, cost));\n          \
    \  ++k;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/rerooting.cpp
  requiredBy: []
  timestamp: '2023-05-14 13:38:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/tree_path_composite_sum.test.cpp
  - test/aoj/GRL_5_B.test.cpp
documentation_of: tree/rerooting.cpp
layout: document
title: Rerooting
---

## Description

全方位木DP (rerooting) は，木において，各頂点を根としたときの木DPの値を求めるアルゴリズムである．

DPは $dp_v = g(f(dp_{c_1}, e_1) * \dots * f(dp_{c_k}, e_k), v)$ という形の遷移で表されるとする．

空間計算量: $O(n)$

## Template Parameters

- `M`
    - 可換モノイド
- `Cost`
    - 辺のコストの型
- `T apply_edge(T a, int s, int t, Cost c)`
    - 遷移の $f$
- `T apply_vertex(T x, int v)`
    - 遷移の $g$

## Operations

- `Rerooting(int n)`
    - 頂点数 $n$ で木を初期化する
    - 時間計算量: $O(n)$
- `void add_edge(int u, int v, Cost c)`
    - 頂点 $uv$ 間にコスト $c$ の辺を張る
    - 時間計算量: $O(1)$
- `vector<T> run()`
    - 各頂点を根としたときの木DPの値を求める
    - 時間計算量: $O(n)$

## Reference

- [†全方位木DP†について](https://ei1333.hateblo.jp/entry/2017/04/10/224413)
- [【全方位木DP】明日使える便利な木構造のアルゴリズム](https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e)
