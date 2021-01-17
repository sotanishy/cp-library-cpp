---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_diameter.cpp\"\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"graph/edge.cpp\"\n\ntemplate <typename\
    \ T>\nstruct Edge {\n    int from, to;\n    T weight;\n    Edge(int to, T weight)\
    \ : from(-1), to(to), weight(weight) {}\n    Edge(int from, int to, T weight)\
    \ : from(from), to(to), weight(weight) {}\n};\n#line 6 \"tree/tree_diameter.cpp\"\
    \n\nclass TreeDiameter {\npublic:\n    TreeDiameter() = delete;\n\n    static\
    \ int diameter(const std::vector<std::vector<int>>& G) {\n        auto p = dfs(G,\
    \ 0, -1);\n        auto q = dfs(G, p.second, -1);\n        return q.first;\n \
    \   }\n\n    template <typename T>\n    static T diameter(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n        auto p = dfs(G, 0, -1);\n        auto q = dfs(G, p.second, -1);\n\
    \        return q.first;\n    }\n\nprivate:\n    static std::pair<int, int> dfs(const\
    \ std::vector<std::vector<int>>& G, int v, int p) {\n        std::pair<int, int>\
    \ ret(0, v);\n        for (int c : G[v]) {\n            if (c == p) continue;\n\
    \            auto weight = dfs(G, c, v);\n            ++weight.first;\n      \
    \      ret = std::max(ret, weight);\n        }\n        return ret;\n    }\n\n\
    \    template <typename T>\n    static std::pair<T, int> dfs(const std::vector<std::vector<Edge<T>>>&\
    \ G, int v, int p) {\n        std::pair<T, int> ret(0, v);\n        for (auto&\
    \ e : G[v]) {\n            if (e.to == p) continue;\n            auto weight =\
    \ dfs(G, e.to, v);\n            weight.first += e.weight;\n            ret = std::max(ret,\
    \ weight);\n        }\n        return ret;\n    }\n};\n\n/*\nint tree_diameter(const\
    \ std::vector<std::vector<int>>& G) {\n    auto dfs = [&](const auto& self, int\
    \ v, int p) {\n        std::pair<int, int> ret(0, v);\n        for (int c : G[v])\
    \ {\n            if (c == p) continue;\n            auto weight = self(self, c,\
    \ v);\n            ++weight.first;\n            ret = std::max(ret, weight);\n\
    \        }\n        return ret;\n    };\n    auto p = dfs(dfs, 0, -1);\n    auto\
    \ q = dfs(dfs, p.second, -1);\n    return q.first;\n}\n\ntemplate <typename T>\n\
    T tree_diameter(const std::vector<std::vector<Edge<T>>>& G) {\n    auto dfs =\
    \ [&](const auto& self, int v, int p) {\n        std::pair<int, int> ret(0, v);\n\
    \        for (auto& e : G[v]) {\n            if (e.to == p) continue;\n      \
    \      auto weight = self(self, e.to, v);\n            weight.first += e.weight;\n\
    \            ret = std::max(ret, weight);\n        }\n        return ret;\n  \
    \  }\n    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(G, p.second, -1);\n    return\
    \ q.first;\n}\n*/\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    #include \"../graph/edge.cpp\"\n\nclass TreeDiameter {\npublic:\n    TreeDiameter()\
    \ = delete;\n\n    static int diameter(const std::vector<std::vector<int>>& G)\
    \ {\n        auto p = dfs(G, 0, -1);\n        auto q = dfs(G, p.second, -1);\n\
    \        return q.first;\n    }\n\n    template <typename T>\n    static T diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n        auto p = dfs(G, 0, -1);\n \
    \       auto q = dfs(G, p.second, -1);\n        return q.first;\n    }\n\nprivate:\n\
    \    static std::pair<int, int> dfs(const std::vector<std::vector<int>>& G, int\
    \ v, int p) {\n        std::pair<int, int> ret(0, v);\n        for (int c : G[v])\
    \ {\n            if (c == p) continue;\n            auto weight = dfs(G, c, v);\n\
    \            ++weight.first;\n            ret = std::max(ret, weight);\n     \
    \   }\n        return ret;\n    }\n\n    template <typename T>\n    static std::pair<T,\
    \ int> dfs(const std::vector<std::vector<Edge<T>>>& G, int v, int p) {\n     \
    \   std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n           \
    \ if (e.to == p) continue;\n            auto weight = dfs(G, e.to, v);\n     \
    \       weight.first += e.weight;\n            ret = std::max(ret, weight);\n\
    \        }\n        return ret;\n    }\n};\n\n/*\nint tree_diameter(const std::vector<std::vector<int>>&\
    \ G) {\n    auto dfs = [&](const auto& self, int v, int p) {\n        std::pair<int,\
    \ int> ret(0, v);\n        for (int c : G[v]) {\n            if (c == p) continue;\n\
    \            auto weight = self(self, c, v);\n            ++weight.first;\n  \
    \          ret = std::max(ret, weight);\n        }\n        return ret;\n    };\n\
    \    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(dfs, p.second, -1);\n    return\
    \ q.first;\n}\n\ntemplate <typename T>\nT tree_diameter(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n    auto dfs = [&](const auto& self, int v, int p) {\n        std::pair<int,\
    \ int> ret(0, v);\n        for (auto& e : G[v]) {\n            if (e.to == p)\
    \ continue;\n            auto weight = self(self, e.to, v);\n            weight.first\
    \ += e.weight;\n            ret = std::max(ret, weight);\n        }\n        return\
    \ ret;\n    }\n    auto p = dfs(dfs, 0, -1);\n    auto q = dfs(G, p.second, -1);\n\
    \    return q.first;\n}\n*/"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: tree/tree_diameter.cpp
  requiredBy: []
  timestamp: '2021-01-17 17:56:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_A.test.cpp
documentation_of: tree/tree_diameter.cpp
layout: document
title: Diameter of a Tree
---

## Description

DFSを用いて木の直径を求める．

## Operations

- `static int diameter(vector<vector<int>> G)`
    - $G$ の辺の重みをすべて1として直径を求める
    - 時間計算量: $O(n)$
- `static T diameter(vector<vector<Edge<T>>> G)`
    - $G$ の直径を求める
    - 時間計算量: $O(n)$

## Reference

- [木の直径を求めるアルゴリズム](https://algo-logic.info/tree-diameter/)

## TODO

- 長さだけでなく辺も返す