---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: Diameter of a Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2821.test.cpp
    title: test/aoj/2821.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_hash.hpp\"\n#include <random>\n#include <utility>\n\
    #include <vector>\n#line 2 \"tree/tree_diameter.cpp\"\n#include <algorithm>\n\
    #line 2 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from,\
    \ to;\n    T weight;\n    Edge() = default;\n    Edge(int to, T weight) : from(-1),\
    \ to(to), weight(weight) {}\n    Edge(int from, int to, T weight) : from(from),\
    \ to(to), weight(weight) {}\n};\n#line 6 \"tree/tree_diameter.cpp\"\n\nstd::pair<int,\
    \ std::vector<int>> tree_diameter(const std::vector<std::vector<int>>& G) {\n\
    \    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs, int\
    \ v, int p) -> std::pair<int, int> {\n        std::pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto weight = dfs(dfs, c, v);\n            ++weight.first;\n            if (ret\
    \ < weight) {\n                ret = weight;\n                to[v] = c;\n   \
    \         }\n        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0,\
    \ -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n   \
    \ int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>> tree_diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<int> to(G.size());\n\
    \n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T, int> {\n \
    \       std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n       \
    \     if (e.to == p) continue;\n            auto weight = dfs(dfs, e.to, v);\n\
    \            weight.first += e.weight;\n            if (ret < weight) {\n    \
    \            ret = weight;\n                to[v] = e.to;\n            }\n   \
    \     }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto\
    \ q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n#line 6 \"tree/tree_hash.hpp\"\
    \n\nlong long tree_hash(const std::vector<std::vector<int>>& G, int root = -1)\
    \ {\n    static constexpr long long mod = (1LL << 61) - 1;\n\n    static auto\
    \ add = [&](long long a, long long b) {\n        if ((a += b) >= mod) a -= mod;\n\
    \        return a;\n    };\n\n    static auto mul = [&](long long a, long long\
    \ b) {\n        __int128_t c = (__int128_t)a * b;\n        return add(c >> 61,\
    \ c & mod);\n    };\n\n    static std::random_device rd;\n    static std::mt19937_64\
    \ rng(rd());\n    static std::uniform_int_distribution<long long> rand(1, mod\
    \ - 1);\n    static std::vector<long long> R;\n\n    auto dfs = [&](auto& dfs,\
    \ int v, int p, int d) -> long long {\n        if ((int) R.size() == d) {\n  \
    \          R.push_back(rand(rng));\n        }\n        long long res = 1;\n  \
    \      for (int c : G[v]) {\n            if (c != p) {\n                res =\
    \ mul(res, dfs(dfs, c, v, d + 1));\n            }\n        }\n        res = add(res,\
    \ R[d]);\n        return res;\n    };\n\n    long long res;\n    if (root == -1)\
    \ {\n        int d;\n        std::vector<int> path;\n        std::tie(d, path)\
    \ = tree_diameter(G);\n        res = dfs(dfs, path[d / 2], -1, 0);\n        if\
    \ (d % 2 == 1) {\n            res = std::min(res, dfs(dfs, path[d / 2 + 1], -1,\
    \ 0));\n        }\n    } else {\n        res = dfs(dfs, root, -1, 0);\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\n#include <random>\n#include <utility>\n#include <vector>\n\
    #include \"tree_diameter.cpp\"\n\nlong long tree_hash(const std::vector<std::vector<int>>&\
    \ G, int root = -1) {\n    static constexpr long long mod = (1LL << 61) - 1;\n\
    \n    static auto add = [&](long long a, long long b) {\n        if ((a += b)\
    \ >= mod) a -= mod;\n        return a;\n    };\n\n    static auto mul = [&](long\
    \ long a, long long b) {\n        __int128_t c = (__int128_t)a * b;\n        return\
    \ add(c >> 61, c & mod);\n    };\n\n    static std::random_device rd;\n    static\
    \ std::mt19937_64 rng(rd());\n    static std::uniform_int_distribution<long long>\
    \ rand(1, mod - 1);\n    static std::vector<long long> R;\n\n    auto dfs = [&](auto&\
    \ dfs, int v, int p, int d) -> long long {\n        if ((int) R.size() == d) {\n\
    \            R.push_back(rand(rng));\n        }\n        long long res = 1;\n\
    \        for (int c : G[v]) {\n            if (c != p) {\n                res\
    \ = mul(res, dfs(dfs, c, v, d + 1));\n            }\n        }\n        res =\
    \ add(res, R[d]);\n        return res;\n    };\n\n    long long res;\n    if (root\
    \ == -1) {\n        int d;\n        std::vector<int> path;\n        std::tie(d,\
    \ path) = tree_diameter(G);\n        res = dfs(dfs, path[d / 2], -1, 0);\n   \
    \     if (d % 2 == 1) {\n            res = std::min(res, dfs(dfs, path[d / 2 +\
    \ 1], -1, 0));\n        }\n    } else {\n        res = dfs(dfs, root, -1, 0);\n\
    \    }\n    return res;\n}\n"
  dependsOn:
  - tree/tree_diameter.cpp
  - graph/edge.cpp
  isVerificationFile: false
  path: tree/tree_hash.hpp
  requiredBy: []
  timestamp: '2022-04-13 16:08:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2821.test.cpp
documentation_of: tree/tree_hash.hpp
layout: document
title: Tree Hashing
---

## Description

木のハッシュを計算する．木の同型性判定に用いる．

## Operations

- `long long tree_hash(vector<vector<int>> G, int root)`
    - 木 $G$ の隣接リストが与えられたとき，$G$ のハッシュを計算する．`root` が与えられた場合はそれを根とする．
    - 時間計算量: $O(n)$

## Reference

- [Tree Isomorphism - My Algorithm](https://kopricky.github.io/code/Graph/tree_isomorphism.html)