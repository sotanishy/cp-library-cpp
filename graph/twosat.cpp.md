---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/scc.cpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/twosat.md
    document_title: 2-SAT
    links: []
  bundledCode: "#line 2 \"graph/twosat.cpp\"\n#include <vector>\n#line 2 \"graph/scc.cpp\"\
    \n#include <algorithm>\n#line 4 \"graph/scc.cpp\"\n\n/*\n * @brief Strongly Connected\
    \ Components\n * @docs docs/graph/scc.md\n */\nclass SCC {\npublic:\n    SCC()\
    \ = default;\n    explicit SCC(int n) : G(n), G_rev(n), comp(n, -1), visited(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n      \
    \  G_rev[v].push_back(u);\n    }\n\n    void build() {\n        for (int v = 0;\
    \ v < (int) G.size(); ++v) dfs(v);\n        std::reverse(order.begin(), order.end());\n\
    \        cnt = 0;\n        for (int v : order) if (comp[v] == -1) rdfs(v, cnt++);\n\
    \    }\n\n    int operator[](int i) const {\n        return comp[i];\n    }\n\n\
    \    int count() const noexcept {\n        return cnt;\n    }\n\nprivate:\n  \
    \  std::vector<std::vector<int>> G, G_rev;\n    std::vector<int> comp, order;\n\
    \    std::vector<bool> visited;\n    int cnt;\n\n    void dfs(int u) {\n     \
    \   if (visited[u]) return;\n        visited[u] = true;\n        for (int v :\
    \ G[u]) dfs(v);\n        order.push_back(u);\n    }\n\n    void rdfs(int u, int\
    \ c) {\n        if (comp[u] != -1) return;\n        comp[u] = c;\n        for\
    \ (int v : G_rev[u]) rdfs(v, c);\n    }\n};\n\n/*\nstd::vector<int> scc_decomposition(const\
    \ std::vector<std::vector<int>>& G) {\n    const int n = G.size();\n    std::vector<std::vector<int>>\
    \ G_rev(n);\n    for (int u = 0; u < n; ++u) {\n        for (int v : G[u]) G_rev[v].push_back(u);\n\
    \    }\n    std::vector<int> comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\
    \n    auto dfs = [&](const auto& self, int u) -> void {\n        if (visited[u])\
    \ return;\n        visited[u] = true;\n        for (int v : G[u]) self(self, v);\n\
    \        order.push_back(v);\n    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs,\
    \ v);\n    std::reverse(order.begin(), order.end());\n    int c = 0;\n\n    auto\
    \ rdfs = [&](const auto& self, int u, int c) -> void {\n        if (comp[u] !=\
    \ -1) return;\n        comp[u] = c;\n        for (int v : G_rev[u]) self(self,\
    \ v, c);\n    }\n\n    for (int v : order) if (comp[v] == -1) rdfs(rdfs, v, c++);\n\
    \    return comp;\n}\n*/\n#line 4 \"graph/twosat.cpp\"\n\n/*\n * @brief 2-SAT\n\
    \ * @docs docs/graph/twosat.md\n */\nclass TwoSat {\npublic:\n    TwoSat() = default;\n\
    \    explicit TwoSat(int n) : n(n), scc(2 * n), val(n) {}\n\n    void add_clause(int\
    \ u, bool a, int v, bool b) {\n        scc.add_edge(n * a + u, n * (!b) + v);\n\
    \        scc.add_edge(n * b + v, n * (!a) + u);\n    }\n\n    void solve() {\n\
    \        scc.build();\n        for (int i = 0; i < n; ++i) {\n            if (scc[i]\
    \ == scc[n + i]) {\n                satisfiable = false;\n                break;\n\
    \            }\n            val[i] = scc[i] > scc[n + i];\n        }\n    }\n\n\
    \    bool is_satisfiable() const noexcept {\n        return satisfiable;\n   \
    \ }\n\n    bool operator[](int i) const {\n        return val[i];\n    }\n\nprivate:\n\
    \    int n;\n    SCC scc;\n    std::vector<bool> val;\n    bool satisfiable =\
    \ true;\n};\n"
  code: "#pragma once\n#include <vector>\n#include \"scc.cpp\"\n\n/*\n * @brief 2-SAT\n\
    \ * @docs docs/graph/twosat.md\n */\nclass TwoSat {\npublic:\n    TwoSat() = default;\n\
    \    explicit TwoSat(int n) : n(n), scc(2 * n), val(n) {}\n\n    void add_clause(int\
    \ u, bool a, int v, bool b) {\n        scc.add_edge(n * a + u, n * (!b) + v);\n\
    \        scc.add_edge(n * b + v, n * (!a) + u);\n    }\n\n    void solve() {\n\
    \        scc.build();\n        for (int i = 0; i < n; ++i) {\n            if (scc[i]\
    \ == scc[n + i]) {\n                satisfiable = false;\n                break;\n\
    \            }\n            val[i] = scc[i] > scc[n + i];\n        }\n    }\n\n\
    \    bool is_satisfiable() const noexcept {\n        return satisfiable;\n   \
    \ }\n\n    bool operator[](int i) const {\n        return val[i];\n    }\n\nprivate:\n\
    \    int n;\n    SCC scc;\n    std::vector<bool> val;\n    bool satisfiable =\
    \ true;\n};"
  dependsOn:
  - graph/scc.cpp
  isVerificationFile: false
  path: graph/twosat.cpp
  requiredBy: []
  timestamp: '2020-10-24 15:32:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: graph/twosat.cpp
layout: document
redirect_from:
- /library/graph/twosat.cpp
- /library/graph/twosat.cpp.html
title: 2-SAT
---
# 2-SAT

2-SAT は，節内のリテラル数が高々2つであるような乗法標準形の論理式に対する充足可能性問題 (SAT) である．

節 $(u \lor v)$ が $(\lnot u \implies v) \land (\lnot v \implies u)$ と同値であることを利用すると，2-SAT を強連結成分分解を用いて解くことができる．

空間計算量: $O(n + m)$．$n$ は変の数，$m$ は節の数

## Constructor

- `TwoSat(int n)`
    - $n$ 変数で初期化する
    - 時間計算量: $O(n)$

## Member functions

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