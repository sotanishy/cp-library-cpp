---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/maximum_independent_set.test.cpp
    title: test/yosupo/maximum_independent_set.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/maximum_independent_set.cpp\"\n#include <vector>\n\
    \nstd::vector<int> maximum_independent_set(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    std::vector<bool> used(n), ans(n);\n    std::vector<int>\
    \ deg(n), dead(n);\n    for (int i = 0; i < n; ++i) deg[i] = G[i].size();\n  \
    \  int res = 0, cnt = 0, alive = n;\n\n    auto dfs = [&](const auto& self) {\n\
    \        if (cnt + alive <= res) return;\n\n        int v = -1;\n        for (int\
    \ i = 0; i < n; ++i) {\n            if (used[i] || dead[i]) continue;\n      \
    \      if (deg[i] <= 1) {\n                v = i;\n                break;\n  \
    \          }\n            if (v < 0 || deg[v] < deg[i]) v = i;\n        }\n  \
    \      if (v < 0) return;\n\n        // not use\n        if (deg[v] != 1) {\n\
    \            dead[v] = true;\n            --alive;\n            for (int u : G[v])\
    \ --deg[u];\n\n            self(self);\n\n            dead[v] = false;\n     \
    \       ++alive;\n            for (int u : G[v]) ++deg[u];\n        }\n\n    \
    \    // use\n        used[v] = true;\n        --alive;\n        for (int u : G[v])\
    \ {\n            if (!dead[u]) --alive;\n            ++dead[u];\n        }\n \
    \       ++cnt;\n        if (res < cnt) {\n            ans = used;\n          \
    \  res = cnt;\n        }\n\n        self(self);\n\n        used[v] = false;\n\
    \        ++alive;\n        for (int u : G[v]) {\n            --dead[u];\n    \
    \        if (!dead[u]) ++alive;\n        }\n        --cnt;\n    };\n\n    dfs(dfs);\n\
    \n    std::vector<int> ret;\n    for (int i = 0; i < n; ++i) {\n        if (ans[i])\
    \ ret.push_back(i);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n\nstd::vector<int> maximum_independent_set(const\
    \ std::vector<std::vector<int>>& G) {\n    int n = G.size();\n    std::vector<bool>\
    \ used(n), ans(n);\n    std::vector<int> deg(n), dead(n);\n    for (int i = 0;\
    \ i < n; ++i) deg[i] = G[i].size();\n    int res = 0, cnt = 0, alive = n;\n\n\
    \    auto dfs = [&](const auto& self) {\n        if (cnt + alive <= res) return;\n\
    \n        int v = -1;\n        for (int i = 0; i < n; ++i) {\n            if (used[i]\
    \ || dead[i]) continue;\n            if (deg[i] <= 1) {\n                v = i;\n\
    \                break;\n            }\n            if (v < 0 || deg[v] < deg[i])\
    \ v = i;\n        }\n        if (v < 0) return;\n\n        // not use\n      \
    \  if (deg[v] != 1) {\n            dead[v] = true;\n            --alive;\n   \
    \         for (int u : G[v]) --deg[u];\n\n            self(self);\n\n        \
    \    dead[v] = false;\n            ++alive;\n            for (int u : G[v]) ++deg[u];\n\
    \        }\n\n        // use\n        used[v] = true;\n        --alive;\n    \
    \    for (int u : G[v]) {\n            if (!dead[u]) --alive;\n            ++dead[u];\n\
    \        }\n        ++cnt;\n        if (res < cnt) {\n            ans = used;\n\
    \            res = cnt;\n        }\n\n        self(self);\n\n        used[v] =\
    \ false;\n        ++alive;\n        for (int u : G[v]) {\n            --dead[u];\n\
    \            if (!dead[u]) ++alive;\n        }\n        --cnt;\n    };\n\n   \
    \ dfs(dfs);\n\n    std::vector<int> ret;\n    for (int i = 0; i < n; ++i) {\n\
    \        if (ans[i]) ret.push_back(i);\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximum_independent_set.cpp
  requiredBy: []
  timestamp: '2021-01-17 23:34:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/maximum_independent_set.test.cpp
documentation_of: graph/maximum_independent_set.cpp
layout: document
title: Maximum Independent Set
---

## Description

最大独立集合を求める．

計算量はよくわからないが，実用上は非常に高速である．$n = 40$ のときに 2 ms 程度で動作する．

- `vector<int> maximum_independent_set(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき， $G$ の最大独立集合を求める．
    - 時間計算量: $O(n1.466^n)$