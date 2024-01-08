---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/chromatic_number.test.cpp
    title: test/yosupo/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/chromatic_number.hpp\"\n#include <bit>\n#include <vector>\n\
    \nint chromatic_number(std::vector<std::vector<bool>>& G) {\n    const int n =\
    \ G.size();\n    std::vector<int> neighbor(n);\n    for (int i = 0; i < (int)G.size();\
    \ ++i) {\n        for (int j = 0; j < (int)G.size(); ++j) {\n            if (G[i][j])\
    \ neighbor[i] |= 1 << j;\n        }\n    }\n    // number of subsets of S that\
    \ are independent\n    std::vector<int> ind(1 << n);\n    ind[0] = 1;\n    for\
    \ (int S = 1; S < (1 << n); ++S) {\n        int v = std::countr_zero((unsigned\
    \ int)S);\n        // (not containing v) + (containing v)\n        ind[S] = ind[S\
    \ ^ (1 << v)] + ind[(S ^ (1 << v)) & ~neighbor[v]];\n    }\n    // number of ways\
    \ to choose k subsets of S that are independent\n    auto f = ind;\n    for (int\
    \ k = 1;; ++k) {\n        // numer of ways to choose k subsets of S so that they\
    \ cover S\n        int g = 0;\n        for (int S = 0; S < (1 << n); ++S) {\n\
    \            g += (std::popcount((unsigned int)S) & 1 ? -1 : 1) * f[S];\n    \
    \    }\n        if (g) return k;\n        for (int S = 1; S < (1 << n); ++S) {\n\
    \            f[S] *= ind[S];\n        }\n    }\n}\n"
  code: "#pragma once\n#include <bit>\n#include <vector>\n\nint chromatic_number(std::vector<std::vector<bool>>&\
    \ G) {\n    const int n = G.size();\n    std::vector<int> neighbor(n);\n    for\
    \ (int i = 0; i < (int)G.size(); ++i) {\n        for (int j = 0; j < (int)G.size();\
    \ ++j) {\n            if (G[i][j]) neighbor[i] |= 1 << j;\n        }\n    }\n\
    \    // number of subsets of S that are independent\n    std::vector<int> ind(1\
    \ << n);\n    ind[0] = 1;\n    for (int S = 1; S < (1 << n); ++S) {\n        int\
    \ v = std::countr_zero((unsigned int)S);\n        // (not containing v) + (containing\
    \ v)\n        ind[S] = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~neighbor[v]];\n\
    \    }\n    // number of ways to choose k subsets of S that are independent\n\
    \    auto f = ind;\n    for (int k = 1;; ++k) {\n        // numer of ways to choose\
    \ k subsets of S so that they cover S\n        int g = 0;\n        for (int S\
    \ = 0; S < (1 << n); ++S) {\n            g += (std::popcount((unsigned int)S)\
    \ & 1 ? -1 : 1) * f[S];\n        }\n        if (g) return k;\n        for (int\
    \ S = 1; S < (1 << n); ++S) {\n            f[S] *= ind[S];\n        }\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/chromatic_number.test.cpp
documentation_of: graph/chromatic_number.hpp
layout: document
title: Chromatic Number
---

## Description

グラフの彩色数は，グラフの隣り合う頂点の色が異なるように頂点を彩色するために必要な最小の色の数である．

## Operations

- `int chromatic_number(vector<vector<bool>> G)`
    - グラフ $G$ の隣接行列が与えられたとき，$G$ の彩色数を求める
    - 時間計算量: $O(n 2^n)$

## Reference

- [指数時間アルゴリズム入門](https://www.slideshare.net/wata_orz/ss-12131479)