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
    \ T>\nT kitamasa(const std::vector<T>& a, const std::vector<T>& c, long long n)\
    \ {\n    const int d = a.size();\n    if (n < d) {\n        return a[n];\n   \
    \ }\n\n    auto dfs = [&](const auto& dfs, long long n) -> std::vector<T> {\n\
    \        if (n == d) {\n            return c;\n        }\n        std::vector<T>\
    \ res(d);\n        if (n & 1 || n < 2 * d) {\n            auto x = dfs(dfs, n\
    \ - 1);\n            for (int j = 0; j < d; ++j) {\n                res[j] = c[j]\
    \ * x[d - 1];\n                if (j > 0) {\n                    res[j] += x[j\
    \ - 1];\n                }\n            }\n        } else {\n            std::vector\
    \ x(d, std::vector<T>(d));\n            x[0] = dfs(dfs, n / 2);\n            for\
    \ (int i = 1; i < d; ++i) {\n                for (int j = 0; j < d; ++j) {\n \
    \                   x[i][j] = c[j] * x[i - 1][d - 1];\n                    if\
    \ (j > 0) {\n                        x[i][j] += x[i - 1][j - 1];\n           \
    \         }\n                }\n            }\n            for (int i = 0; i <\
    \ d; ++i) {\n                for (int j = 0; j < d; ++j) {\n                 \
    \   res[j] += x[0][i] * x[i][j];\n                }\n            }\n        }\n\
    \        return res;\n    };\n\n    auto x = dfs(dfs, n);\n    T ans = 0;\n  \
    \  for (int i = 0; i < d; ++i) {\n        ans += x[i] * a[i];\n    }\n    return\
    \ ans;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nT kitamasa(const\
    \ std::vector<T>& a, const std::vector<T>& c, long long n) {\n    const int d\
    \ = a.size();\n    if (n < d) {\n        return a[n];\n    }\n\n    auto dfs =\
    \ [&](const auto& dfs, long long n) -> std::vector<T> {\n        if (n == d) {\n\
    \            return c;\n        }\n        std::vector<T> res(d);\n        if\
    \ (n & 1 || n < 2 * d) {\n            auto x = dfs(dfs, n - 1);\n            for\
    \ (int j = 0; j < d; ++j) {\n                res[j] = c[j] * x[d - 1];\n     \
    \           if (j > 0) {\n                    res[j] += x[j - 1];\n          \
    \      }\n            }\n        } else {\n            std::vector x(d, std::vector<T>(d));\n\
    \            x[0] = dfs(dfs, n / 2);\n            for (int i = 1; i < d; ++i)\
    \ {\n                for (int j = 0; j < d; ++j) {\n                    x[i][j]\
    \ = c[j] * x[i - 1][d - 1];\n                    if (j > 0) {\n              \
    \          x[i][j] += x[i - 1][j - 1];\n                    }\n              \
    \  }\n            }\n            for (int i = 0; i < d; ++i) {\n             \
    \   for (int j = 0; j < d; ++j) {\n                    res[j] += x[0][i] * x[i][j];\n\
    \                }\n            }\n        }\n        return res;\n    };\n\n\
    \    auto x = dfs(dfs, n);\n    T ans = 0;\n    for (int i = 0; i < d; ++i) {\n\
    \        ans += x[i] * a[i];\n    }\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/kitamasa.cpp
  requiredBy: []
  timestamp: '2022-03-31 14:37:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/kitamasa.cpp
layout: document
title: Kitamasa's Algorithm
---

## Description

Kitamasa 法は，$d$ 階線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．

## Operations

- `T kitamasa(vector<T> a, vector<T> c, long long n)`
    - 初めの $d$ 項 $a_0, \dots, a_{d-1}$ と漸化式 $a_n = c_0 a_{n-d} + \dots + c_{d-1} a_{n-1}$ によって定まる数列 $(a_n)$ の第 $n$ 項を求める．
    - 時間計算量: $O(d^2 \log n)$

## Reference

- [きたまさ法メモ](https://yosupo.hatenablog.com/entry/2015/03/27/025132)