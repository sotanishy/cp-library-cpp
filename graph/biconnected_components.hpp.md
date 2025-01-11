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
    \ <unordered_map>\n#include <utility>\n#include <vector>\n\n#line 2 \"graph/lowlink.hpp\"\
    \n#include <algorithm>\n#line 5 \"graph/lowlink.hpp\"\n\nclass Lowlink {\n   public:\n\
    \    std::vector<int> ord, low;\n    std::vector<std::pair<int, int>> bridge;\n\
    \    std::vector<int> articulation;\n\n    Lowlink() = default;\n    explicit\
    \ Lowlink(const std::vector<std::vector<int>>& G)\n        : ord(G.size(), -1),\
    \ low(G.size()), G(G) {\n        for (int i = 0; i < (int)G.size(); ++i) {\n \
    \           if (ord[i] == -1) dfs(i, -1);\n        }\n    }\n\n    bool is_bridge(int\
    \ u, int v) const {\n        if (ord[u] > ord[v]) std::swap(u, v);\n        return\
    \ ord[u] < low[v];\n    }\n\n   private:\n    std::vector<std::vector<int>> G;\n\
    \    int k = 0;\n\n    void dfs(int v, int p) {\n        ord[v] = k++;\n     \
    \   low[v] = ord[v];\n        bool is_articulation = false, checked = false;\n\
    \        int cnt = 0;\n        for (int c : G[v]) {\n            if (c == p &&\
    \ !checked) {\n                checked = true;\n                continue;\n  \
    \          }\n            if (ord[c] == -1) {\n                ++cnt;\n      \
    \          dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n  \
    \              if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n    \
    \            if (ord[v] < low[c]) bridge.push_back(std::minmax(v, c));\n     \
    \       } else {\n                low[v] = std::min(low[v], ord[c]);\n       \
    \     }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 8 \"\
    graph/biconnected_components.hpp\"\n\nstd::vector<std::vector<int>> biconnected_components(\n\
    \    const std::vector<std::vector<int>>& G, const Lowlink& low) {\n    std::vector<bool>\
    \ used(G.size());\n    std::stack<std::pair<int, int>> st;\n    std::vector<std::vector<int>>\
    \ blocks;\n    std::vector<int> isolated;\n\n    auto dfs = [&](auto& dfs, int\
    \ v, int p) -> void {\n        used[v] = true;\n        for (int c : G[v]) {\n\
    \            if (c == p) continue;\n            if (!used[c] || low.ord[c] < low.ord[v])\
    \ {\n                st.emplace(v, c);\n            }\n            if (!used[c])\
    \ {\n                dfs(dfs, c, v);\n                if (low.ord[v] <= low.low[c])\
    \ {  // v is an articulation point\n                    blocks.emplace_back();\n\
    \                    auto& block = blocks.back();\n                    while (true)\
    \ {\n                        auto e = st.top();\n                        st.pop();\n\
    \                        block.push_back(e.first);\n                        block.push_back(e.second);\n\
    \                        if (e.first == v) {\n                            break;\n\
    \                        }\n                    }\n                    std::sort(block.begin(),\
    \ block.end());\n                    block.erase(std::ranges::unique(block).begin(),\n\
    \                                block.end());\n                }\n          \
    \  }\n        }\n    };\n\n    for (int v = 0; v < (int)G.size(); ++v) {\n   \
    \     if (!used[v]) dfs(dfs, v, -1);\n        if (G[v].empty()) {\n          \
    \  blocks.push_back({v});\n        }\n    }\n\n    return blocks;\n}\n\n// B:\
    \ number of blocks, C: number of cut vertices\n// 0 through B - 1: block\n// B\
    \ through B + C - 1: cut\nstd::vector<std::vector<int>> block_cut_tree(\n    const\
    \ std::vector<std::vector<int>>& blocks, const std::vector<int>& cuts) {\n   \
    \ const int B = blocks.size();\n    std::vector<std::vector<int>> bct(B + (int)cuts.size());\n\
    \    std::unordered_map<int, int> cut_idx;\n    for (int i = 0; i < (int)cuts.size();\
    \ ++i) cut_idx[cuts[i]] = i;\n\n    for (int i = 0; i < (int)blocks.size(); ++i)\
    \ {\n        auto& block = blocks[i];\n        for (int v : block) {\n       \
    \     if (cut_idx.contains(v)) {\n                int j = B + cut_idx[v];\n  \
    \              bct[i].push_back(j);\n                bct[j].push_back(i);\n  \
    \          }\n        }\n    }\n\n    return bct;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <unordered_map>\n#include <utility>\n\
    #include <vector>\n\n#include \"lowlink.hpp\"\n\nstd::vector<std::vector<int>>\
    \ biconnected_components(\n    const std::vector<std::vector<int>>& G, const Lowlink&\
    \ low) {\n    std::vector<bool> used(G.size());\n    std::stack<std::pair<int,\
    \ int>> st;\n    std::vector<std::vector<int>> blocks;\n    std::vector<int> isolated;\n\
    \n    auto dfs = [&](auto& dfs, int v, int p) -> void {\n        used[v] = true;\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ if (!used[c] || low.ord[c] < low.ord[v]) {\n                st.emplace(v, c);\n\
    \            }\n            if (!used[c]) {\n                dfs(dfs, c, v);\n\
    \                if (low.ord[v] <= low.low[c]) {  // v is an articulation point\n\
    \                    blocks.emplace_back();\n                    auto& block =\
    \ blocks.back();\n                    while (true) {\n                       \
    \ auto e = st.top();\n                        st.pop();\n                    \
    \    block.push_back(e.first);\n                        block.push_back(e.second);\n\
    \                        if (e.first == v) {\n                            break;\n\
    \                        }\n                    }\n                    std::sort(block.begin(),\
    \ block.end());\n                    block.erase(std::ranges::unique(block).begin(),\n\
    \                                block.end());\n                }\n          \
    \  }\n        }\n    };\n\n    for (int v = 0; v < (int)G.size(); ++v) {\n   \
    \     if (!used[v]) dfs(dfs, v, -1);\n        if (G[v].empty()) {\n          \
    \  blocks.push_back({v});\n        }\n    }\n\n    return blocks;\n}\n\n// B:\
    \ number of blocks, C: number of cut vertices\n// 0 through B - 1: block\n// B\
    \ through B + C - 1: cut\nstd::vector<std::vector<int>> block_cut_tree(\n    const\
    \ std::vector<std::vector<int>>& blocks, const std::vector<int>& cuts) {\n   \
    \ const int B = blocks.size();\n    std::vector<std::vector<int>> bct(B + (int)cuts.size());\n\
    \    std::unordered_map<int, int> cut_idx;\n    for (int i = 0; i < (int)cuts.size();\
    \ ++i) cut_idx[cuts[i]] = i;\n\n    for (int i = 0; i < (int)blocks.size(); ++i)\
    \ {\n        auto& block = blocks[i];\n        for (int v : block) {\n       \
    \     if (cut_idx.contains(v)) {\n                int j = B + cut_idx[v];\n  \
    \              bct[i].push_back(j);\n                bct[j].push_back(i);\n  \
    \          }\n        }\n    }\n\n    return bct;\n}\n"
  dependsOn:
  - graph/lowlink.hpp
  isVerificationFile: false
  path: graph/biconnected_components.hpp
  requiredBy: []
  timestamp: '2025-01-11 16:44:40+09:00'
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

- `vector<vector<int>> biconnected_components(vector<vector<int>> G, Lowlink low)`
    - グラフ $G$ の隣接リストと，$G$ の lowlink 構造体が与えられたとき，$G$ を二重頂点連結成分分解する．$G$ の二重頂点連結成分を返す
    - 時間計算量: $O(V + E)$
- `vector<vector<int>> block_cut_tree(vector<vector<int>> blocks, vector<int> cuts)`
    - ブロック（二重頂点連結成分）とカット（関節点）のリストが与えられたときに，対応する block cut tree の隣接リストを返す
    - 時間計算量: $O(B + C)$
