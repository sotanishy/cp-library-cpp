---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n#include <algorithm>\n#include\
    \ <stack>\n#include <vector>\n\nstd::vector<int> topological_sort(const std::vector<std::vector<int>>&\
    \ G) {\n    const int n = G.size();\n    std::vector<int> par_count(n);\n    for\
    \ (int u = 0; u < n; ++u) {\n        for (int v : G[u]) ++par_count[v];\n    }\n\
    \    std::stack<int> st;\n    for (int v = 0; v < n; ++v) {\n        if (par_count[v]\
    \ == 0) st.push(v);\n    }\n\n    std::vector<int> ord;\n    while (!st.empty())\
    \ {\n        int u = st.top();\n        st.pop();\n        ord.push_back(u);\n\
    \        for (int v : G[u]) {\n            --par_count[v];\n            if (par_count[v]\
    \ == 0) st.push(v);\n        }\n    }\n\n    if (*std::ranges::max_element(par_count)\
    \ > 0) return {};\n    return ord;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <stack>\n#include <vector>\n\
    \nstd::vector<int> topological_sort(const std::vector<std::vector<int>>& G) {\n\
    \    const int n = G.size();\n    std::vector<int> par_count(n);\n    for (int\
    \ u = 0; u < n; ++u) {\n        for (int v : G[u]) ++par_count[v];\n    }\n  \
    \  std::stack<int> st;\n    for (int v = 0; v < n; ++v) {\n        if (par_count[v]\
    \ == 0) st.push(v);\n    }\n\n    std::vector<int> ord;\n    while (!st.empty())\
    \ {\n        int u = st.top();\n        st.pop();\n        ord.push_back(u);\n\
    \        for (int v : G[u]) {\n            --par_count[v];\n            if (par_count[v]\
    \ == 0) st.push(v);\n        }\n    }\n\n    if (*std::ranges::max_element(par_count)\
    \ > 0) return {};\n    return ord;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological_sort.hpp
layout: document
title: Topological Sort
---

## Description

トポロジカルソートは，有向非巡回グラフ (DAG) の頂点を順序付けして，任意の辺 $(u, v)$ について $u$ が $v$ よりも前に来るように並べることである．

## Operations

- `vector<int> topological_sort(vector<vector<int>> G)`
    - $G$ のトポロジカルソートを返す．$G$ が DAG でないならば，空のリストを返す
    - 時間計算量: $O(V + E)$