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
  bundledCode: "#line 2 \"graph/maximum_weight_independent_set.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <vector>\n\ntemplate <typename T>\nT maximum_weight_independent_set(const\
    \ std::vector<std::vector<int>>& G, const std::vector<T>& w) {\n    const int\
    \ n = G.size();\n    const int n1 = n / 2;\n    const int n2 = n - n1;\n    std::vector<T>\
    \ neighbors11(n1), neighbors12(n1), neighbors22(n2);\n    for (int i = 0; i <\
    \ n; ++i) {\n        for (int j : G[i]) {\n            if (i < n1 && j < n1) neighbors11[i]\
    \ |= 1 << j;\n            if (i < n1 && j >= n1) neighbors12[i] |= 1 << (j - n1);\n\
    \            if (i >= n1 && j >= n1) neighbors22[i - n1] |= 1 << (j - n1);\n \
    \       }\n    }\n    std::vector<int> dp(1 << n2);\n    for (int S = 0; S < 1\
    \ << n2; ++S) {\n        T s = 0;\n        int neighbor = 0;\n        for (int\
    \ i = 0; i < n2; ++i) {\n            if (S >> i & 1) {\n                s += w[n1\
    \ + i];\n                neighbor |= neighbors22[i];\n            }\n        }\n\
    \        if (!(neighbor & S)) {\n            dp[S] = std::max(dp[S], s);\n   \
    \     }\n        for (int i = 0; i < n2; ++i) {\n            if (!(S >> i & 1))\
    \ {\n                dp[S | (1 << i)] = std::max(dp[S | (1 << i)], dp[S]);\n \
    \           }\n        }\n    }\n    T ans = 0;\n    for (int S = 0; S < 1 <<\
    \ n1; ++S) {\n        if (!(S & 1)) continue;\n        int s = 0;\n        int\
    \ neighbor1 = 0;\n        int neighbor2 = 0;\n        for (int i = 0; i < n1;\
    \ ++i) {\n            if (S >> i & 1) {\n                s += w[i];\n        \
    \        neighbor1 |= neighbors11[i];\n                neighbor2 |= neighbors12[i];\n\
    \            }\n        }\n        if (!(neighbor1 & S)) {\n            ans =\
    \ std::max(ans, s + dp[neighbor2 ^ ((1 << n2) - 1)]);\n        }\n    }\n    return\
    \ ans;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    \ntemplate <typename T>\nT maximum_weight_independent_set(const std::vector<std::vector<int>>&\
    \ G, const std::vector<T>& w) {\n    const int n = G.size();\n    const int n1\
    \ = n / 2;\n    const int n2 = n - n1;\n    std::vector<T> neighbors11(n1), neighbors12(n1),\
    \ neighbors22(n2);\n    for (int i = 0; i < n; ++i) {\n        for (int j : G[i])\
    \ {\n            if (i < n1 && j < n1) neighbors11[i] |= 1 << j;\n           \
    \ if (i < n1 && j >= n1) neighbors12[i] |= 1 << (j - n1);\n            if (i >=\
    \ n1 && j >= n1) neighbors22[i - n1] |= 1 << (j - n1);\n        }\n    }\n   \
    \ std::vector<int> dp(1 << n2);\n    for (int S = 0; S < 1 << n2; ++S) {\n   \
    \     T s = 0;\n        int neighbor = 0;\n        for (int i = 0; i < n2; ++i)\
    \ {\n            if (S >> i & 1) {\n                s += w[n1 + i];\n        \
    \        neighbor |= neighbors22[i];\n            }\n        }\n        if (!(neighbor\
    \ & S)) {\n            dp[S] = std::max(dp[S], s);\n        }\n        for (int\
    \ i = 0; i < n2; ++i) {\n            if (!(S >> i & 1)) {\n                dp[S\
    \ | (1 << i)] = std::max(dp[S | (1 << i)], dp[S]);\n            }\n        }\n\
    \    }\n    T ans = 0;\n    for (int S = 0; S < 1 << n1; ++S) {\n        if (!(S\
    \ & 1)) continue;\n        int s = 0;\n        int neighbor1 = 0;\n        int\
    \ neighbor2 = 0;\n        for (int i = 0; i < n1; ++i) {\n            if (S >>\
    \ i & 1) {\n                s += w[i];\n                neighbor1 |= neighbors11[i];\n\
    \                neighbor2 |= neighbors12[i];\n            }\n        }\n    \
    \    if (!(neighbor1 & S)) {\n            ans = std::max(ans, s + dp[neighbor2\
    \ ^ ((1 << n2) - 1)]);\n        }\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximum_weight_independent_set.hpp
  requiredBy: []
  timestamp: '2022-05-09 11:09:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maximum_weight_independent_set.hpp
layout: document
title: Maximum Weight Independent Set
---

## Description

最大重み独立集合の重みを求める．半分全列挙を用いている．

## Operations

- `T maximum_weight_independent_set(vector<vector<int>> G, vector<T> w)`
    - グラフ $G$ の隣接リストと各頂点の重みが与えられたとき， $G$ の最大重み独立集合の重みを求める．
    - 時間計算量: $O(n^2 2^{n/2})$
