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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/twosat.cpp\"\n#include <vector>\n#line 2 \"graph/scc.cpp\"\
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
    \ G2[i].end());\n    }\n    return G2;\n}\n#line 4 \"graph/twosat.cpp\"\n\nclass\
    \ TwoSat {\npublic:\n    TwoSat() = default;\n    explicit TwoSat(int n) : n(n),\
    \ G(2 * n), val(n) {}\n\n    void add_clause(int u, bool a, int v, bool b) {\n\
    \        G[n * a + u].push_back(n * (!b) + v);\n        G[n * b + v].push_back(n\
    \ * (!a) + u);\n    }\n\n    void solve() {\n        auto comp = scc(G);\n   \
    \     for (int i = 0; i < n; ++i) {\n            if (comp[i] == comp[n + i]) {\n\
    \                satisfiable = false;\n                break;\n            }\n\
    \            val[i] = comp[i] > comp[n + i];\n        }\n    }\n\n    bool is_satisfiable()\
    \ const noexcept {\n        return satisfiable;\n    }\n\n    bool operator[](int\
    \ i) const {\n        return val[i];\n    }\n\nprivate:\n    int n;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<bool> val;\n    bool satisfiable = true;\n};\n"
  code: "#pragma once\n#include <vector>\n#include \"scc.cpp\"\n\nclass TwoSat {\n\
    public:\n    TwoSat() = default;\n    explicit TwoSat(int n) : n(n), G(2 * n),\
    \ val(n) {}\n\n    void add_clause(int u, bool a, int v, bool b) {\n        G[n\
    \ * a + u].push_back(n * (!b) + v);\n        G[n * b + v].push_back(n * (!a) +\
    \ u);\n    }\n\n    void solve() {\n        auto comp = scc(G);\n        for (int\
    \ i = 0; i < n; ++i) {\n            if (comp[i] == comp[n + i]) {\n          \
    \      satisfiable = false;\n                break;\n            }\n         \
    \   val[i] = comp[i] > comp[n + i];\n        }\n    }\n\n    bool is_satisfiable()\
    \ const noexcept {\n        return satisfiable;\n    }\n\n    bool operator[](int\
    \ i) const {\n        return val[i];\n    }\n\nprivate:\n    int n;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<bool> val;\n    bool satisfiable = true;\n};"
  dependsOn:
  - graph/scc.cpp
  isVerificationFile: false
  path: graph/twosat.cpp
  requiredBy: []
  timestamp: '2021-10-07 13:18:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: graph/twosat.cpp
layout: document
title: 2-SAT
---

## Description

2-SAT は，節内のリテラル数が高々2つであるような乗法標準形の論理式に対する充足可能性問題 (SAT) である．

節 $(u \lor v)$ が $(\lnot u \implies v) \land (\lnot v \implies u)$ と同値であることを利用すると，2-SAT を強連結成分分解を用いて解くことができる．

空間計算量: $O(n + m)$．$n$ は変の数，$m$ は節の数

## Operations

- `TwoSat(int n)`
    - $n$ 変数で初期化する
    - 時間計算量: $O(n)$
- `void add_clause(int u, bool a, int v, bool b)`
    - 節 $(u \lor v)$ を追加する．`a == false` ならば，$u$ を $\lnot u$ で置き換える．同様に`b == false` ならば，$v$ を $\lnot v$ で置き換える
    - 時間計算量: $O(1)$
- `void solve()`
    - 問題を解く
    - 時間計算量: $O(n + m)$
- `bool is_satisfiable()`
    - 問題が充足可能かどうか返す
    - 時間計算量: $O(1)$
- `bool operator[](int i)`
    - 充足可能ならば，$i$ 番目の変数の真偽値を返す
    - 時間計算量: $O(1)$