---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/bipartite_matching.cpp
    title: Bipartite Matching
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dm_decomposition.cpp\"\n#include <stack>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"flow/bipartite_matching.cpp\"\n#include\
    \ <algorithm>\n#line 4 \"flow/bipartite_matching.cpp\"\n\nclass BipartiteMatching\
    \ {\npublic:\n    BipartiteMatching() = default;\n    explicit BipartiteMatching(int\
    \ n) : G(n), used(n), match(n) {}\n\n    void add_edge(int u, int v) {\n     \
    \   G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    int bipartite_matching()\
    \ {\n        int res = 0;\n        std::fill(match.begin(), match.end(), -1);\n\
    \        for (int v = 0; v < (int) G.size(); ++v) {\n            if (match[v]\
    \ == -1) {\n                std::fill(used.begin(), used.end(), false);\n    \
    \            if (dfs(v)) ++res;\n            }\n        }\n        return res;\n\
    \    }\n\n    std::vector<std::pair<int, int>> get_edges() {\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int i = 0; i < (int) G.size(); ++i) {\n           \
    \ if (i < match[i]) ret.emplace_back(i, match[i]);\n        }\n        return\
    \ ret;\n    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<bool>\
    \ used;\n    std::vector<int> match;\n\n    bool dfs(int u) {\n        used[u]\
    \ = true;\n        for (int v : G[u]) {\n            int w = match[v];\n     \
    \       if (w == -1 || (!used[w] && dfs(w))) {\n                match[u] = v;\n\
    \                match[v] = u;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n};\n#line 6 \"graph/dm_decomposition.cpp\"\
    \n\nstd::vector<int> dm_decomposition(const std::vector<std::vector<int>>& G)\
    \ {\n    int N = G.size();\n    BipartiteMatching bm(N);\n    for (int u = 0;\
    \ u < N; ++u) {\n        for (int v : G[u]) {\n            if (u < v) {\n    \
    \            bm.add_edge(u, v);\n            }\n        }\n    }\n    bm.bipartite_matching();\n\
    \    std::vector<int> comp(N), matched(N, -1);\n    for (auto [u, v] : bm.get_edges())\
    \ {\n        comp[u] = comp[v] = -1;\n        matched[u] = v;\n        matched[v]\
    \ = u;\n    }\n    std::stack<std::pair<int, bool>> st;  // whether or not the\
    \ previous edges is used in the matching\n    for (int v = 0; v < N; ++v) {\n\
    \        if (comp[v] == 0) {\n            st.push({v, 0});\n            st.push({v,\
    \ 1});\n        }\n    }\n    while (!st.empty()) {\n        auto [u, b] = st.top();\n\
    \        st.pop();\n        for (int v : G[u]) {\n            if (comp[v] == -1\
    \ && (b ^ (matched[u] == v))) {\n                comp[v] = comp[u] ^ 1;\n    \
    \            st.push({v, !b});\n            }\n        }\n    }\n    return comp;\n\
    }\n"
  code: "#pragma once\n#include <stack>\n#include <utility>\n#include <vector>\n#include\
    \ \"../flow/bipartite_matching.cpp\"\n\nstd::vector<int> dm_decomposition(const\
    \ std::vector<std::vector<int>>& G) {\n    int N = G.size();\n    BipartiteMatching\
    \ bm(N);\n    for (int u = 0; u < N; ++u) {\n        for (int v : G[u]) {\n  \
    \          if (u < v) {\n                bm.add_edge(u, v);\n            }\n \
    \       }\n    }\n    bm.bipartite_matching();\n    std::vector<int> comp(N),\
    \ matched(N, -1);\n    for (auto [u, v] : bm.get_edges()) {\n        comp[u] =\
    \ comp[v] = -1;\n        matched[u] = v;\n        matched[v] = u;\n    }\n   \
    \ std::stack<std::pair<int, bool>> st;  // whether or not the previous edges is\
    \ used in the matching\n    for (int v = 0; v < N; ++v) {\n        if (comp[v]\
    \ == 0) {\n            st.push({v, 0});\n            st.push({v, 1});\n      \
    \  }\n    }\n    while (!st.empty()) {\n        auto [u, b] = st.top();\n    \
    \    st.pop();\n        for (int v : G[u]) {\n            if (comp[v] == -1 &&\
    \ (b ^ (matched[u] == v))) {\n                comp[v] = comp[u] ^ 1;\n       \
    \         st.push({v, !b});\n            }\n        }\n    }\n    return comp;\n\
    }"
  dependsOn:
  - flow/bipartite_matching.cpp
  isVerificationFile: false
  path: graph/dm_decomposition.cpp
  requiredBy: []
  timestamp: '2021-10-18 15:45:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dm_decomposition.cpp
layout: document
title: Dulmage-Mendelsohn Decomposition
---

## Description

Dulmage-Mendelsohn 分解 (DM分解) は，与えられた二部グラフの最大マッチングに関する性質による頂点の分類である．

この実装では，二部グラフ $G$ の頂点を3つの集合 $U, O, E$ に分類する．この分類は以下の性質を持つ:
- $U, O, E$ は pairwise disjoint である
- $G$ の任意の最大マッチングは $U-U$ 辺と $E-O$ 辺からなる
- $G$ の任意の最大マッチングにおいて，$U, O$ に属する頂点はすべてマッチされる
- $G$ の最大マッチングの大きさは $|O| + |U|/2$ である

DM 分解は疎行列のブロック対角化に用いられるらしい．行列を行と列の二部グラフとみなし，非零要素のところに辺を張って DM 分解をすると，ブロック対角化ができる (このとき，$U$を更に細かく分類することでブロックを小さくする)．大規模な線形連立方程式を小さな部分問題に分解できて嬉しいらしいが，競プロで使いどころがあるかは知らない．

- `vector<int> dm_decomposition(vector<vector<int>> G)`
    - 二部グラフ $G$ を DM 分解する．0は$E$, 1は$O$, -1は$U$に属することを意味する
    - 時間計算量: $O(VE)$


## Reference

- [Dulmage Mendelsohn Decomposition](http://www.cse.iitm.ac.in/~meghana/matchings/bip-decomp.pdf)
- [Dulmage–Mendelsohn分解 (DM分解)](http://misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf)