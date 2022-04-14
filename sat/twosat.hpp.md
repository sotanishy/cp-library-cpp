---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.cpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"sat/twosat.hpp\"\n#include <vector>\n#line 2 \"graph/scc.cpp\"\
    \n#include <algorithm>\n#line 4 \"graph/scc.cpp\"\n\nstd::vector<int> scc(const\
    \ std::vector<std::vector<int>>& G) {\n    const int n = G.size();\n    std::vector<std::vector<int>>\
    \ G_rev(n);\n    for (int u = 0; u < n; ++u) {\n        for (int v : G[u]) G_rev[v].push_back(u);\n\
    \    }\n    std::vector<int> comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\
    \n    auto dfs = [&](const auto& self, int u) -> void {\n        if (visited[u])\
    \ return;\n        visited[u] = true;\n        for (int v : G[u]) self(self, v);\n\
    \        order.push_back(u);\n    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs,\
    \ v);\n    std::reverse(order.begin(), order.end());\n    int c = 0;\n\n    auto\
    \ rdfs = [&](const auto& self, int u, int c) -> void {\n        if (comp[u] !=\
    \ -1) return;\n        comp[u] = c;\n        for (int v : G_rev[u]) self(self,\
    \ v, c);\n    };\n\n    for (int v : order) if (comp[v] == -1) rdfs(rdfs, v, c++);\n\
    \    return comp;\n}\n\nstd::vector<std::vector<int>> contract(const std::vector<std::vector<int>>&\
    \ G, const std::vector<int>& comp) {\n    const int n = *max_element(comp.begin(),\
    \ comp.end()) + 1;\n    std::vector<std::vector<int>> G2(n);\n    for (int i =\
    \ 0; i < (int) G.size(); ++i) {\n        for (int j : G[i]) {\n            if\
    \ (comp[i] != comp[j]) {\n                G2[comp[i]].push_back(comp[j]);\n  \
    \          }\n        }\n    }\n    for (int i = 0; i < n; ++i) {\n        std::sort(G2[i].begin(),\
    \ G2[i].end());\n        G2[i].erase(std::unique(G2[i].begin(), G2[i].end()),\
    \ G2[i].end());\n    }\n    return G2;\n}\n#line 4 \"sat/twosat.hpp\"\n\nstd::vector<bool>\
    \ two_sat(int n, const std::vector<std::tuple<int, bool, int, bool>>& clauses)\
    \ {\n    std::vector<std::vector<int>> G(2 * n);\n    std::vector<bool> val(n);\n\
    \n    for (auto& [i, f, j, g] : clauses) {\n        G[n * f + i].push_back(n *\
    \ (!g) + j);\n        G[n * g + j].push_back(n * (!f) + i);\n    }\n\n    auto\
    \ comp = scc(G);\n    for (int i = 0; i < n; ++i) {\n        if (comp[i] == comp[n\
    \ + i]) {\n            // not satisfiable\n            return {};\n        }\n\
    \        val[i] = comp[i] > comp[n + i];\n    }\n    return val;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../graph/scc.cpp\"\n\nstd::vector<bool>\
    \ two_sat(int n, const std::vector<std::tuple<int, bool, int, bool>>& clauses)\
    \ {\n    std::vector<std::vector<int>> G(2 * n);\n    std::vector<bool> val(n);\n\
    \n    for (auto& [i, f, j, g] : clauses) {\n        G[n * f + i].push_back(n *\
    \ (!g) + j);\n        G[n * g + j].push_back(n * (!f) + i);\n    }\n\n    auto\
    \ comp = scc(G);\n    for (int i = 0; i < n; ++i) {\n        if (comp[i] == comp[n\
    \ + i]) {\n            // not satisfiable\n            return {};\n        }\n\
    \        val[i] = comp[i] > comp[n + i];\n    }\n    return val;\n}"
  dependsOn:
  - graph/scc.cpp
  isVerificationFile: false
  path: sat/twosat.hpp
  requiredBy: []
  timestamp: '2022-04-14 13:03:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: sat/twosat.hpp
layout: document
title: 2-SAT
---

## Description

2-SAT は，節内のリテラル数が高々2つであるような乗法標準形の論理式に対する充足可能性問題 (SAT) である．

節 $(u \lor v)$ が $(\lnot u \rightarrow v) \land (\lnot v \rightarrow u)$ と同値であることを利用すると，2-SAT を強連結成分分解を用いて解くことができる．

## Operations

- `vector<bool> two_sat(int n, vector<tuple<int, bool, int, bool>> clauses)`
    - $n$ リテラルを含む節のリストが与えられた時，すべての節を充足するリテラルの真偽値の組み合わせを一つ返す．節は `{i, f, j, g}` の形で与え，$((x_i = f) \lor (x_j = g))$ を追加する．問題が充足可能でない場合，空リストを返す．
    - 時間計算量: $O(n)$