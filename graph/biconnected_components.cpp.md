---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/lowlink.cpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/biconnected_components.test.cpp
    title: test/yosupo/biconnected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/biconnected_components.cpp\"\n#include <stack>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"graph/lowlink.cpp\"\n#include <algorithm>\n\
    #line 5 \"graph/lowlink.cpp\"\n\nclass Lowlink {\npublic:\n    Lowlink() = default;\n\
    \    explicit Lowlink(const std::vector<std::vector<int>>& G) : G(G), ord(G.size(),\
    \ -1), low(G.size()) {\n        for (int i = 0; i < (int) G.size(); ++i) {\n \
    \           if (ord[i] == -1) dfs(i, -1);\n        }\n    }\n\n    std::vector<std::pair<int,\
    \ int>> get_bridges() const {\n        return bridge;\n    }\n\n    std::vector<int>\
    \ get_articulation_points() const {\n        return articulation;\n    }\n\n \
    \   bool is_bridge(int u, int v) const {\n        if (ord[u] > ord[v]) std::swap(u,\
    \ v);\n        return ord[u] < low[v];\n    }\n\nprotected:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> ord, low;\n    std::vector<std::pair<int, int>> bridge;\n\
    \    std::vector<int> articulation;\n\nprivate:\n    int k = 0;\n\n    void dfs(int\
    \ v, int p) {\n        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false, checked = false;\n        int cnt = 0;\n        for (int c : G[v])\
    \ {\n            if (c == p && !checked) {\n                checked = true;\n\
    \                continue;\n            }\n            if (ord[c] == -1) {\n \
    \               ++cnt;\n                dfs(c, v);\n                low[v] = std::min(low[v],\
    \ low[c]);\n                if (p != -1 && ord[v] <= low[c]) is_articulation =\
    \ true;\n                if (ord[v] < low[c]) bridge.push_back(std::minmax(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 6 \"\
    graph/biconnected_components.cpp\"\n\nclass BiconnectedComponents : Lowlink {\n\
    public:\n    BiconnectedComponents() = default;\n    explicit BiconnectedComponents(const\
    \ std::vector<std::vector<int>>& G) : Lowlink(G), G(G), used(G.size()) {\n   \
    \     for (int v = 0; v < (int) G.size(); ++v) {\n            if (!used[v]) dfs(v,\
    \ -1);\n        }\n    }\n\n    std::vector<std::vector<std::pair<int, int>>>\
    \ get_biconnected_components() const {\n        return bc;\n    }\n\nprivate:\n\
    \    std::vector<std::vector<int>> G;\n    std::vector<bool> used;\n    std::stack<std::pair<int,\
    \ int>> st;\n    std::vector<std::vector<std::pair<int, int>>> bc;\n\n    void\
    \ dfs(int v, int p) {\n        used[v] = true;\n        for (int c : G[v]) {\n\
    \            if (c == p) continue;\n            if (!used[c] || ord[c] < ord[v])\
    \ {\n                st.emplace(v, c);\n            }\n            if (!used[c])\
    \ {\n                dfs(c, v);\n                if (ord[v] <= low[c]) {  // v\
    \ is an articulation point\n                    bc.emplace_back();\n         \
    \           while (true) {\n                        auto e = st.top();\n     \
    \                   st.pop();\n                        bc.back().push_back(e);\n\
    \                        if (e.first == v) {\n                            break;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <stack>\n#include <utility>\n#include <vector>\n#include\
    \ \"lowlink.cpp\"\n\nclass BiconnectedComponents : Lowlink {\npublic:\n    BiconnectedComponents()\
    \ = default;\n    explicit BiconnectedComponents(const std::vector<std::vector<int>>&\
    \ G) : Lowlink(G), G(G), used(G.size()) {\n        for (int v = 0; v < (int) G.size();\
    \ ++v) {\n            if (!used[v]) dfs(v, -1);\n        }\n    }\n\n    std::vector<std::vector<std::pair<int,\
    \ int>>> get_biconnected_components() const {\n        return bc;\n    }\n\nprivate:\n\
    \    std::vector<std::vector<int>> G;\n    std::vector<bool> used;\n    std::stack<std::pair<int,\
    \ int>> st;\n    std::vector<std::vector<std::pair<int, int>>> bc;\n\n    void\
    \ dfs(int v, int p) {\n        used[v] = true;\n        for (int c : G[v]) {\n\
    \            if (c == p) continue;\n            if (!used[c] || ord[c] < ord[v])\
    \ {\n                st.emplace(v, c);\n            }\n            if (!used[c])\
    \ {\n                dfs(c, v);\n                if (ord[v] <= low[c]) {  // v\
    \ is an articulation point\n                    bc.emplace_back();\n         \
    \           while (true) {\n                        auto e = st.top();\n     \
    \                   st.pop();\n                        bc.back().push_back(e);\n\
    \                        if (e.first == v) {\n                            break;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n        }\n    }\n};\n"
  dependsOn:
  - graph/lowlink.cpp
  isVerificationFile: false
  path: graph/biconnected_components.cpp
  requiredBy: []
  timestamp: '2022-03-06 21:25:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/biconnected_components.test.cpp
documentation_of: graph/biconnected_components.cpp
layout: document
title: Biconnected Components
---

## Description

二重頂点連結成分は，どの1頂点を取り除いても連結であるような部分グラフである．つまり，関節点を含まない部分グラフである．

関節点と二重頂点連結成分を結んで構成した木は block cut tree と呼ばれる．

空間計算量: $O(V + E)$

## Operations

- `BionnectedComponents(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ を二重頂点連結成分分解する
    - 時間計算量: $O(V + E)$
- `vector<vector<pair<int, int>>> get_biconnected_components()`
    - $G$ の二重頂点連結成分を返す
    - 時間計算量: $O(V)$