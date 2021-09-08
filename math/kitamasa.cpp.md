---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/kitamasa.cpp\"\n#include <vector>\n\ntemplate <typename\
    \ T>\nT kitamasa(const std::vector<T>& a, const std::vector<T>& d, int n) {\n\
    \    const int k = a.size();\n    if (n < k) {\n        return a[n];\n    }\n\n\
    \    auto dfs = [&](const auto& dfs, int n) -> std::vector<T> {\n        if (n\
    \ == k) {\n            return d;\n        }\n        std::vector<T> res(k);\n\
    \        if (n & 1 || n < 2 * k) {\n            auto x = dfs(dfs, n - 1);\n  \
    \          for (int j = 0; j < k; ++j) {\n                res[j] = d[j] * x[k\
    \ - 1];\n                if (j > 0) {\n                    res[j] += x[j - 1];\n\
    \                }\n            }\n        } else {\n            std::vector x(k,\
    \ std::vector<T>(k));\n            x[0] = dfs(dfs, n / 2);\n            for (int\
    \ i = 1; i < k; ++i) {\n                for (int j = 0; j < k; ++j) {\n      \
    \              x[i][j] = d[j] * x[i - 1][k - 1];\n                    if (j >\
    \ 0) {\n                        x[i][j] += x[i - 1][j - 1];\n                \
    \    }\n                }\n            }\n            for (int i = 0; i < k; ++i)\
    \ {\n                for (int j = 0; j < k; ++j) {\n                    res[j]\
    \ += x[0][i] * x[i][j];\n                }\n            }\n        }\n       \
    \ return res;\n    };\n\n    auto x = dfs(dfs, n);\n    T ans = 0;\n    for (int\
    \ i = 0; i < k; ++i) {\n        ans += x[i] * a[i];\n    }\n    return ans;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nT kitamasa(const\
    \ std::vector<T>& a, const std::vector<T>& d, int n) {\n    const int k = a.size();\n\
    \    if (n < k) {\n        return a[n];\n    }\n\n    auto dfs = [&](const auto&\
    \ dfs, int n) -> std::vector<T> {\n        if (n == k) {\n            return d;\n\
    \        }\n        std::vector<T> res(k);\n        if (n & 1 || n < 2 * k) {\n\
    \            auto x = dfs(dfs, n - 1);\n            for (int j = 0; j < k; ++j)\
    \ {\n                res[j] = d[j] * x[k - 1];\n                if (j > 0) {\n\
    \                    res[j] += x[j - 1];\n                }\n            }\n \
    \       } else {\n            std::vector x(k, std::vector<T>(k));\n         \
    \   x[0] = dfs(dfs, n / 2);\n            for (int i = 1; i < k; ++i) {\n     \
    \           for (int j = 0; j < k; ++j) {\n                    x[i][j] = d[j]\
    \ * x[i - 1][k - 1];\n                    if (j > 0) {\n                     \
    \   x[i][j] += x[i - 1][j - 1];\n                    }\n                }\n  \
    \          }\n            for (int i = 0; i < k; ++i) {\n                for (int\
    \ j = 0; j < k; ++j) {\n                    res[j] += x[0][i] * x[i][j];\n   \
    \             }\n            }\n        }\n        return res;\n    };\n\n   \
    \ auto x = dfs(dfs, n);\n    T ans = 0;\n    for (int i = 0; i < k; ++i) {\n \
    \       ans += x[i] * a[i];\n    }\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/kitamasa.cpp
  requiredBy: []
  timestamp: '2021-09-08 22:33:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/kitamasa.cpp
layout: document
title: Kitamasa's Algorithm
---

## Description

Kitamasa 法は，$k$ 階線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．

- `T kitamasa(vector<T> a, vector<T> d, int n)`
    - 初めの $k$ 項 $a_0, \dots, a_{k-1}$ と漸化式 $a_n = d_0 a_{n-k} + \dots + d_{k-1} a_{n-1}$ によって定まる数列 $(a_n)$ の第 $n$ 項を求める．
    - 時間計算量: $O(k^2 \lg n)$

## Reference

- [きたまさ法メモ](https://yosupo.hatenablog.com/entry/2015/03/27/025132)