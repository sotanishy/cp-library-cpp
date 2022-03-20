---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/chromatic_number.test.cpp
    title: test/yosupo/chromatic_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/chromatic_number.cpp\"\n#include <vector>\n\nint chromatic_number(std::vector<std::vector<bool>>&\
    \ G) {\n    int n = G.size();\n    std::vector<int> edges(n);\n    for (int i\
    \ = 0; i < (int) G.size(); ++i) {\n        for (int j = 0; j < (int) G.size();\
    \ ++j) {\n            if (G[i][j]) edges[i] |= 1 << j;\n        }\n    }\n   \
    \ // number of subsets of S that are independent\n    std::vector<int> ind(1 <<\
    \ n);\n    ind[0] = 1;\n    for (int S = 1; S < (1 << n); ++S) {\n        int\
    \ v = __builtin_ctz(S);\n        // (not containing v) + (containing v)\n    \
    \    ind[S] = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~edges[v]];\n    }\n  \
    \  // number of ways to choose k subsets of S that are independent\n    auto f\
    \ = ind;\n    for (int k = 1; ; ++k) {\n        // numer of ways to choose k subsets\
    \ of S so that they cover S\n        int g = 0;\n        for (int S = 0; S < (1\
    \ << n); ++S) {\n            g += (__builtin_parity(S) ? -1 : 1) * f[S];\n   \
    \     }\n        if (g) return k;\n        for (int S = 1; S < (1 << n); ++S)\
    \ {\n            f[S] *= ind[S];\n        }\n    }\n}\n"
  code: "#pragma once\n#include <vector>\n\nint chromatic_number(std::vector<std::vector<bool>>&\
    \ G) {\n    int n = G.size();\n    std::vector<int> edges(n);\n    for (int i\
    \ = 0; i < (int) G.size(); ++i) {\n        for (int j = 0; j < (int) G.size();\
    \ ++j) {\n            if (G[i][j]) edges[i] |= 1 << j;\n        }\n    }\n   \
    \ // number of subsets of S that are independent\n    std::vector<int> ind(1 <<\
    \ n);\n    ind[0] = 1;\n    for (int S = 1; S < (1 << n); ++S) {\n        int\
    \ v = __builtin_ctz(S);\n        // (not containing v) + (containing v)\n    \
    \    ind[S] = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~edges[v]];\n    }\n  \
    \  // number of ways to choose k subsets of S that are independent\n    auto f\
    \ = ind;\n    for (int k = 1; ; ++k) {\n        // numer of ways to choose k subsets\
    \ of S so that they cover S\n        int g = 0;\n        for (int S = 0; S < (1\
    \ << n); ++S) {\n            g += (__builtin_parity(S) ? -1 : 1) * f[S];\n   \
    \     }\n        if (g) return k;\n        for (int S = 1; S < (1 << n); ++S)\
    \ {\n            f[S] *= ind[S];\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/chromatic_number.cpp
  requiredBy: []
  timestamp: '2022-03-20 19:41:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/chromatic_number.test.cpp
documentation_of: graph/chromatic_number.cpp
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