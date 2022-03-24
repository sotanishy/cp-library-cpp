---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dominatortree.test.cpp
    title: test/yosupo/dominatortree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dominator_tree.cpp\"\n#include <numeric>\n#include\
    \ <vector>\n\nstd::vector<int> dominator_tree(const std::vector<std::vector<int>>&\
    \ G, int s) {\n    const int n = G.size();\n\n    // label nodes with the arrival\
    \ times of a dfs\n    std::vector<int> sdom(n, -1), par(n, -1), vs;\n    vs.reserve(n);\n\
    \    int k = 0;\n\n    auto dfs = [&](auto& dfs, int v) -> void {\n        sdom[v]\
    \ = k++;\n        vs.push_back(v);\n        for (int c : G[v]) {\n           \
    \ if (sdom[c] == -1) {\n                par[c] = v;\n                dfs(dfs,\
    \ c);\n            }\n        }\n    };\n\n    dfs(dfs, s);\n\n    std::vector<std::vector<int>>\
    \ G_rev(n);\n    for (int u = 0; u < n; ++u) {\n        if (sdom[u] == -1) continue;\n\
    \        for (int v : G[u]) {\n            G_rev[v].push_back(u);\n        }\n\
    \    }\n\n    // union find with path compression\n    std::vector<int> dsu(n),\
    \ val(n);\n    std::iota(dsu.begin(), dsu.end(), 0);\n    std::iota(val.begin(),\
    \ val.end(), 0);\n\n    auto unite = [&](int u, int v) {  // make u the parent\
    \ of v\n        dsu[v] = u;\n    };\n\n    auto find = [&](auto& find, int v)\
    \ -> int {\n        if (v == dsu[v]) return v;\n        int r = find(find, dsu[v]);\n\
    \        if (sdom[val[v]] > sdom[val[dsu[v]]]) {\n            val[v] = val[dsu[v]];\n\
    \        }\n        return dsu[v] = r;\n    };\n\n    auto eval = [&](int v) {\
    \   // return the ancestor of v with minimum sdom\n        find(find, v);\n  \
    \      return val[v];\n    };\n\n    // calculate sdom\n    std::vector<int> us(n);\n\
    \    std::vector<std::vector<int>> bucket(n);\n    for (int i = k - 1; i > 0;\
    \ --i) {\n        int w = vs[i];\n        for (int v : G_rev[w]) {\n         \
    \   sdom[w] = std::min(sdom[w], sdom[eval(v)]);\n        }\n        bucket[vs[sdom[w]]].push_back(w);\n\
    \        for (int v : bucket[par[w]]) {\n            us[v] = eval(v);\n      \
    \  }\n        bucket[par[w]].clear();\n        unite(par[w], w);\n    }\n\n  \
    \  // calculate idom\n    std::vector<int> idom(n, -1);\n    idom[s] = sdom[s];\n\
    \    for (int i = 1; i < k; ++i) {\n        int w = vs[i], u = us[w];\n      \
    \  idom[w] = (sdom[w] == sdom[u] ? sdom[w] : idom[u]);\n    }\n    for (int v\
    \ : vs) {\n        idom[v] = vs[idom[v]];\n    }\n    return idom;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n\nstd::vector<int> dominator_tree(const\
    \ std::vector<std::vector<int>>& G, int s) {\n    const int n = G.size();\n\n\
    \    // label nodes with the arrival times of a dfs\n    std::vector<int> sdom(n,\
    \ -1), par(n, -1), vs;\n    vs.reserve(n);\n    int k = 0;\n\n    auto dfs = [&](auto&\
    \ dfs, int v) -> void {\n        sdom[v] = k++;\n        vs.push_back(v);\n  \
    \      for (int c : G[v]) {\n            if (sdom[c] == -1) {\n              \
    \  par[c] = v;\n                dfs(dfs, c);\n            }\n        }\n    };\n\
    \n    dfs(dfs, s);\n\n    std::vector<std::vector<int>> G_rev(n);\n    for (int\
    \ u = 0; u < n; ++u) {\n        if (sdom[u] == -1) continue;\n        for (int\
    \ v : G[u]) {\n            G_rev[v].push_back(u);\n        }\n    }\n\n    //\
    \ union find with path compression\n    std::vector<int> dsu(n), val(n);\n   \
    \ std::iota(dsu.begin(), dsu.end(), 0);\n    std::iota(val.begin(), val.end(),\
    \ 0);\n\n    auto unite = [&](int u, int v) {  // make u the parent of v\n   \
    \     dsu[v] = u;\n    };\n\n    auto find = [&](auto& find, int v) -> int {\n\
    \        if (v == dsu[v]) return v;\n        int r = find(find, dsu[v]);\n   \
    \     if (sdom[val[v]] > sdom[val[dsu[v]]]) {\n            val[v] = val[dsu[v]];\n\
    \        }\n        return dsu[v] = r;\n    };\n\n    auto eval = [&](int v) {\
    \   // return the ancestor of v with minimum sdom\n        find(find, v);\n  \
    \      return val[v];\n    };\n\n    // calculate sdom\n    std::vector<int> us(n);\n\
    \    std::vector<std::vector<int>> bucket(n);\n    for (int i = k - 1; i > 0;\
    \ --i) {\n        int w = vs[i];\n        for (int v : G_rev[w]) {\n         \
    \   sdom[w] = std::min(sdom[w], sdom[eval(v)]);\n        }\n        bucket[vs[sdom[w]]].push_back(w);\n\
    \        for (int v : bucket[par[w]]) {\n            us[v] = eval(v);\n      \
    \  }\n        bucket[par[w]].clear();\n        unite(par[w], w);\n    }\n\n  \
    \  // calculate idom\n    std::vector<int> idom(n, -1);\n    idom[s] = sdom[s];\n\
    \    for (int i = 1; i < k; ++i) {\n        int w = vs[i], u = us[w];\n      \
    \  idom[w] = (sdom[w] == sdom[u] ? sdom[w] : idom[u]);\n    }\n    for (int v\
    \ : vs) {\n        idom[v] = vs[idom[v]];\n    }\n    return idom;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dominator_tree.cpp
  requiredBy: []
  timestamp: '2022-03-24 13:03:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dominatortree.test.cpp
documentation_of: graph/dominator_tree.cpp
layout: document
title: Dominator Tree
---

## Description

有向グラフ $G$ において，頂点 $v$ が頂点 $w$ の dominator であるとは，$G$ における任意の $s-w$ パス ($s$ は source vertex) が $v$ を通ることである．

$v$ が $w$ の immediate dominator であるとは，$v$ が $w$ の dominator であり，かつ $v$ が $w$ の任意の dominator $u$ を dominate しないことである．これは $w$ に対して一意に定まる．

$G$ の dominator tree は，$G$ で $v$ が $w$ の immediate dominator であるときかつそのときに限り有向辺 $(v, w)$ が存在するような有向木である．

## Operations

- `vector<int> dominator_tree(vector<vector<int>> G, int s)`
    - グラフ $G$ の隣接リストと source vertex $s$ が与えられたとき，各頂点 $v$ の immediate dominator を返す．$v$ が $s$ なら到達できない場合 `-1` を返す．$s$ の immediate dominator は $s$ とする．
    - 時間計算量: $O((V + E) \log V)$

## Reference

- [Dominator Tree of a Directed Graph](https://tanujkhattar.wordpress.com/2016/01/11/dominator-tree-of-a-directed-graph/)
- [Dominator Tree](https://sigma425.hatenablog.com/entry/2015/12/25/224053)