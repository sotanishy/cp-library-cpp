---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/biconnected_components.test.cpp
    title: test/yosupo/biconnected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/biconnected_components.hpp\"\n#include <stack>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"graph/lowlink.hpp\"\n#include <algorithm>\n\
    #line 5 \"graph/lowlink.hpp\"\n\nclass Lowlink {\n   public:\n    std::vector<int>\
    \ ord, low;\n    std::vector<std::pair<int, int>> bridge;\n    std::vector<int>\
    \ articulation;\n\n    Lowlink() = default;\n    explicit Lowlink(const std::vector<std::vector<int>>&\
    \ G)\n        : ord(G.size(), -1), low(G.size()), G(G) {\n        for (int i =\
    \ 0; i < (int)G.size(); ++i) {\n            if (ord[i] == -1) dfs(i, -1);\n  \
    \      }\n    }\n\n    bool is_bridge(int u, int v) const {\n        if (ord[u]\
    \ > ord[v]) std::swap(u, v);\n        return ord[u] < low[v];\n    }\n\n   private:\n\
    \    std::vector<std::vector<int>> G;\n    int k = 0;\n\n    void dfs(int v, int\
    \ p) {\n        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false, checked = false;\n        int cnt = 0;\n        for (int c : G[v])\
    \ {\n            if (c == p && !checked) {\n                checked = true;\n\
    \                continue;\n            }\n            if (ord[c] == -1) {\n \
    \               ++cnt;\n                dfs(c, v);\n                low[v] = std::min(low[v],\
    \ low[c]);\n                if (p != -1 && ord[v] <= low[c]) is_articulation =\
    \ true;\n                if (ord[v] < low[c]) bridge.push_back(std::minmax(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 7 \"\
    graph/biconnected_components.hpp\"\n\nstd::vector<std::vector<std::pair<int, int>>>\
    \ biconnected_components(\n    const std::vector<std::vector<int>>& G, const Lowlink&\
    \ low) {\n    std::vector<bool> used(G.size());\n    std::stack<std::pair<int,\
    \ int>> st;\n    std::vector<std::vector<std::pair<int, int>>> bc;\n\n    auto\
    \ dfs = [&](auto& dfs, int v, int p) -> void {\n        used[v] = true;\n    \
    \    for (int c : G[v]) {\n            if (c == p) continue;\n            if (!used[c]\
    \ || low.ord[c] < low.ord[v]) {\n                st.emplace(v, c);\n         \
    \   }\n            if (!used[c]) {\n                dfs(dfs, c, v);\n        \
    \        if (low.ord[v] <= low.low[c]) {  // v is an articulation point\n    \
    \                bc.emplace_back();\n                    while (true) {\n    \
    \                    auto e = st.top();\n                        st.pop();\n \
    \                       bc.back().push_back(e);\n                        if (e.first\
    \ == v) {\n                            break;\n                        }\n   \
    \                 }\n                }\n            }\n        }\n    };\n\n \
    \   for (int v = 0; v < (int)G.size(); ++v) {\n        if (!used[v]) dfs(dfs,\
    \ v, -1);\n    }\n\n    return bc;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <utility>\n#include <vector>\n\n\
    #include \"lowlink.hpp\"\n\nstd::vector<std::vector<std::pair<int, int>>> biconnected_components(\n\
    \    const std::vector<std::vector<int>>& G, const Lowlink& low) {\n    std::vector<bool>\
    \ used(G.size());\n    std::stack<std::pair<int, int>> st;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> bc;\n\n    auto dfs = [&](auto& dfs, int v, int p) -> void {\n      \
    \  used[v] = true;\n        for (int c : G[v]) {\n            if (c == p) continue;\n\
    \            if (!used[c] || low.ord[c] < low.ord[v]) {\n                st.emplace(v,\
    \ c);\n            }\n            if (!used[c]) {\n                dfs(dfs, c,\
    \ v);\n                if (low.ord[v] <= low.low[c]) {  // v is an articulation\
    \ point\n                    bc.emplace_back();\n                    while (true)\
    \ {\n                        auto e = st.top();\n                        st.pop();\n\
    \                        bc.back().push_back(e);\n                        if (e.first\
    \ == v) {\n                            break;\n                        }\n   \
    \                 }\n                }\n            }\n        }\n    };\n\n \
    \   for (int v = 0; v < (int)G.size(); ++v) {\n        if (!used[v]) dfs(dfs,\
    \ v, -1);\n    }\n\n    return bc;\n}"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/biconnected_components.hpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/biconnected_components.test.cpp
documentation_of: graph/biconnected_components.hpp
layout: document
title: Biconnected Components
---

## Description

二重頂点連結成分は，どの1頂点を取り除いても連結であるような部分グラフである．つまり，関節点を含まない部分グラフである．

関節点と二重頂点連結成分を結んで構成した木は block cut tree と呼ばれる．

空間計算量: $O(V + E)$

## Operations

- `vector<vector<pair<int, int>>> biconnected_components(vector<vector<int>> G, Lowlink low)`
    - グラフ $G$ の隣接リストと，$G$ の lowlink 構造体が与えられたとき，$G$ を二重頂点連結成分分解する
    - $G$ の二重頂点連結成分を返す
    - 時間計算量: $O(V + E)$

## Note

多重辺は予め取り除いておく必要がある (多重辺を取り除いても二重頂点連結成分は変化しない)．

また，孤立点にも注意する (孤立点はそれで一つの二重頂点連結成分となるが，この関数は辺を返すため，孤立点からなる成分は含まれない)．