---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/rerooting.cpp\"\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename M,\n          typename Cost,\n          typename M::T (*leaf)(),\n\
    \          typename M::T (*apply)(typename M::T, int, int, Cost)>\nclass Rerooting\
    \ {\n    using T = typename M::T;\n\npublic:\n    explicit Rerooting(int n) :\
    \ G(n) {}\n\n    void add_edge(int u, int v, Cost c) {\n        G[u].emplace_back(v,\
    \ c);\n        G[v].emplace_back(u, c);\n    }\n\n    std::vector<T> run() {\n\
    \        dp_sub.resize(G.size(), M::id);\n        dp_all.resize(G.size());\n \
    \       dfs_sub(0, -1);\n        dfs_all(0, -1, M::id);\n        return dp_all;\n\
    \    }\n\nprivate:\n    std::vector<std::vector<std::pair<int, Cost>>> G;\n  \
    \  std::vector<T> dp_sub, dp_all;\n\n    void dfs_sub(int v, int p) {\n      \
    \  bool is_leaf = true;\n        for (auto [c, cost] : G[v]) {\n            if\
    \ (c == p) continue;\n            is_leaf = false;\n            dfs_sub(c, v);\n\
    \            dp_sub[v] = M::op(dp_sub[v], apply(dp_sub[c], v, c, cost));\n   \
    \     }\n        if (is_leaf) dp_sub[v] = leaf();\n    }\n\n    void dfs_all(int\
    \ v, int p, const T& val) {\n        std::vector<T> ds = {val};\n        for (auto\
    \ [c, cost] : G[v]) {\n            if (c == p) continue;\n            ds.push_back(apply(dp_sub[c],\
    \ v, c, cost));\n        }\n        int n = ds.size();\n        std::vector<T>\
    \ head(n + 1, M::id), tail(n + 1, M::id);\n        for (int i = 0; i < n; ++i)\
    \ head[i+1] = M::op(head[i], ds[i]);\n        for (int i = n - 1; i >= 0; --i)\
    \ tail[i] = M::op(ds[i], tail[i+1]);\n        dp_all[v] = head[n];\n        int\
    \ k = 1;\n        for (auto [c, cost] : G[v]) {\n            if (c == p) continue;\n\
    \            dfs_all(c, v, apply(M::op(head[k], tail[k+1]), c, v, cost));\n  \
    \          ++k;\n        }\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ M,\n          typename Cost,\n          typename M::T (*leaf)(),\n         \
    \ typename M::T (*apply)(typename M::T, int, int, Cost)>\nclass Rerooting {\n\
    \    using T = typename M::T;\n\npublic:\n    explicit Rerooting(int n) : G(n)\
    \ {}\n\n    void add_edge(int u, int v, Cost c) {\n        G[u].emplace_back(v,\
    \ c);\n        G[v].emplace_back(u, c);\n    }\n\n    std::vector<T> run() {\n\
    \        dp_sub.resize(G.size(), M::id);\n        dp_all.resize(G.size());\n \
    \       dfs_sub(0, -1);\n        dfs_all(0, -1, M::id);\n        return dp_all;\n\
    \    }\n\nprivate:\n    std::vector<std::vector<std::pair<int, Cost>>> G;\n  \
    \  std::vector<T> dp_sub, dp_all;\n\n    void dfs_sub(int v, int p) {\n      \
    \  bool is_leaf = true;\n        for (auto [c, cost] : G[v]) {\n            if\
    \ (c == p) continue;\n            is_leaf = false;\n            dfs_sub(c, v);\n\
    \            dp_sub[v] = M::op(dp_sub[v], apply(dp_sub[c], v, c, cost));\n   \
    \     }\n        if (is_leaf) dp_sub[v] = leaf();\n    }\n\n    void dfs_all(int\
    \ v, int p, const T& val) {\n        std::vector<T> ds = {val};\n        for (auto\
    \ [c, cost] : G[v]) {\n            if (c == p) continue;\n            ds.push_back(apply(dp_sub[c],\
    \ v, c, cost));\n        }\n        int n = ds.size();\n        std::vector<T>\
    \ head(n + 1, M::id), tail(n + 1, M::id);\n        for (int i = 0; i < n; ++i)\
    \ head[i+1] = M::op(head[i], ds[i]);\n        for (int i = n - 1; i >= 0; --i)\
    \ tail[i] = M::op(ds[i], tail[i+1]);\n        dp_all[v] = head[n];\n        int\
    \ k = 1;\n        for (auto [c, cost] : G[v]) {\n            if (c == p) continue;\n\
    \            dfs_all(c, v, apply(M::op(head[k], tail[k+1]), c, v, cost));\n  \
    \          ++k;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/rerooting.cpp
  requiredBy: []
  timestamp: '2021-10-10 00:56:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/rerooting.cpp
layout: document
title: Rerooting
---

## Description

全方位木DPは，木において，各頂点を根としたときの木DPの値を求めるアルゴリズムである．

空間計算量: $O(n)$

## Template Parameters

- `M`
    - 可換モノイド
- `Cost`
    - 辺のコストの型
- `T leaf()`
    - 葉におけるDPの値
- `T apply(T a, int s, int t, Cost c)`
    - 辺 $st$ のコストが $c$ で $t$ の部分木の値が $a$ であるときに $s$ の部分木の値を求める

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