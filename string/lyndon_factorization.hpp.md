---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lyndon_factorization.test.cpp
    title: test/yosupo/lyndon_factorization.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/lyndon_factorization.hpp\"\n#include <string>\n#include\
    \ <vector>\n\nstd::vector<int> lyndon_factorization(const std::string& s) {\n\
    \    const int n = s.size();\n    std::vector<int> res;\n    for (int i = 0; i\
    \ < n;) {\n        int j = i + 1, k = i;\n        while (j < n && s[k] <= s[j])\
    \ {\n            if (s[k] < s[j]) {\n                k = i;\n            } else\
    \ {\n                ++k;\n            }\n            ++j;\n        }\n      \
    \  while (i <= k) {\n            res.push_back(i);\n            i += j - k;\n\
    \        }\n    }\n    res.push_back(n);\n    return res;\n}\n"
  code: "#include <string>\n#include <vector>\n\nstd::vector<int> lyndon_factorization(const\
    \ std::string& s) {\n    const int n = s.size();\n    std::vector<int> res;\n\
    \    for (int i = 0; i < n;) {\n        int j = i + 1, k = i;\n        while (j\
    \ < n && s[k] <= s[j]) {\n            if (s[k] < s[j]) {\n                k =\
    \ i;\n            } else {\n                ++k;\n            }\n            ++j;\n\
    \        }\n        while (i <= k) {\n            res.push_back(i);\n        \
    \    i += j - k;\n        }\n    }\n    res.push_back(n);\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/lyndon_factorization.hpp
  requiredBy: []
  timestamp: '2023-11-26 16:39:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lyndon_factorization.test.cpp
documentation_of: string/lyndon_factorization.hpp
layout: document
title: Lyndon Factorization
---

## Description

Lyndon word とは，その任意の proper suffix よりも辞書順で真に小さいような文字列である．

任意の文字列は，単調非増加な Lyndon word の結合として一意的に分解される．この分解を Lyndon factorization という．

## Operations

- `vector<int> lyndon_factorization(string s)`
    - 文字列 $s$ を Lyndon factorization したときの，各 Lyndon word の最初の index を返す
    - 時間計算量: $O(n)$

## Reference

- [Lyndon factorization - Algorithms for Competitive Programming](https://cp-algorithms.com/string/lyndon_factorization.html)