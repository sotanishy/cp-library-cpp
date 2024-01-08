---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/maximum_independent_set.test.cpp
    title: test/yosupo/maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/maximum_independent_set.hpp\"\n#include <algorithm>\n\
    #include <vector>\n\nstd::vector<int> maximum_independent_set(\n    const std::vector<std::vector<int>>&\
    \ G) {\n    const int n = G.size();\n    std::vector<bool> used(n), ans(n);\n\
    \    std::vector<int> deg(n), dead(n);\n    std::ranges::transform(G, deg.begin(),\
    \ [&](auto& g) { return g.size(); });\n    int res = 0, cnt = 0, alive = n;\n\n\
    \    auto dfs = [&](const auto& dfs) {\n        if (cnt + alive <= res) return;\n\
    \n        int v = -1;\n        for (int i = 0; i < n; ++i) {\n            if (used[i]\
    \ || dead[i]) continue;\n            if (deg[i] <= 1) {\n                v = i;\n\
    \                break;\n            }\n            if (v < 0 || deg[v] < deg[i])\
    \ v = i;\n        }\n        if (v < 0) return;\n\n        // not use\n      \
    \  if (deg[v] != 1) {\n            dead[v] = true;\n            --alive;\n   \
    \         for (int u : G[v]) --deg[u];\n\n            dfs(dfs);\n\n          \
    \  dead[v] = false;\n            ++alive;\n            for (int u : G[v]) ++deg[u];\n\
    \        }\n\n        // use\n        used[v] = true;\n        --alive;\n    \
    \    for (int u : G[v]) {\n            if (!dead[u]) --alive;\n            ++dead[u];\n\
    \        }\n        ++cnt;\n        if (res < cnt) {\n            ans = used;\n\
    \            res = cnt;\n        }\n\n        dfs(dfs);\n\n        used[v] = false;\n\
    \        ++alive;\n        for (int u : G[v]) {\n            --dead[u];\n    \
    \        if (!dead[u]) ++alive;\n        }\n        --cnt;\n    };\n\n    dfs(dfs);\n\
    \n    std::vector<int> ret;\n    for (int i = 0; i < n; ++i) {\n        if (ans[i])\
    \ ret.push_back(i);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nstd::vector<int>\
    \ maximum_independent_set(\n    const std::vector<std::vector<int>>& G) {\n  \
    \  const int n = G.size();\n    std::vector<bool> used(n), ans(n);\n    std::vector<int>\
    \ deg(n), dead(n);\n    std::ranges::transform(G, deg.begin(), [&](auto& g) {\
    \ return g.size(); });\n    int res = 0, cnt = 0, alive = n;\n\n    auto dfs =\
    \ [&](const auto& dfs) {\n        if (cnt + alive <= res) return;\n\n        int\
    \ v = -1;\n        for (int i = 0; i < n; ++i) {\n            if (used[i] || dead[i])\
    \ continue;\n            if (deg[i] <= 1) {\n                v = i;\n        \
    \        break;\n            }\n            if (v < 0 || deg[v] < deg[i]) v =\
    \ i;\n        }\n        if (v < 0) return;\n\n        // not use\n        if\
    \ (deg[v] != 1) {\n            dead[v] = true;\n            --alive;\n       \
    \     for (int u : G[v]) --deg[u];\n\n            dfs(dfs);\n\n            dead[v]\
    \ = false;\n            ++alive;\n            for (int u : G[v]) ++deg[u];\n \
    \       }\n\n        // use\n        used[v] = true;\n        --alive;\n     \
    \   for (int u : G[v]) {\n            if (!dead[u]) --alive;\n            ++dead[u];\n\
    \        }\n        ++cnt;\n        if (res < cnt) {\n            ans = used;\n\
    \            res = cnt;\n        }\n\n        dfs(dfs);\n\n        used[v] = false;\n\
    \        ++alive;\n        for (int u : G[v]) {\n            --dead[u];\n    \
    \        if (!dead[u]) ++alive;\n        }\n        --cnt;\n    };\n\n    dfs(dfs);\n\
    \n    std::vector<int> ret;\n    for (int i = 0; i < n; ++i) {\n        if (ans[i])\
    \ ret.push_back(i);\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/maximum_independent_set.test.cpp
documentation_of: graph/maximum_independent_set.hpp
layout: document
title: Maximum Independent Set
---

## Description

最大独立集合を求める．

計算量はよくわからないが，実用上は非常に高速である．$n = 40$ のときに 2 ms 程度で動作する．

## Operations

- `vector<int> maximum_independent_set(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき， $G$ の最大独立集合を求める．
    - 時間計算量: $O(n1.466^n)$