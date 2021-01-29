---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_palindromes.test.cpp
    title: test/yosupo/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/manacher.cpp\"\n#include <algorithm>\n#include <vector>\n\
    #include <string>\n\nstd::vector<int> manacher(const std::string& s) {\n    int\
    \ n = s.size();\n    std::vector<int> vs(2 * n - 1);\n    // odd length\n    for\
    \ (int i = 0, l = 0, r = -1; i < n; ++i) {\n        int k = (i > r) ? 1 : std::min(vs[2\
    \ * (l + r - i)], r - i + 1);\n        while (0 <= i - k && i + k < n && s[i -\
    \ k] == s[i + k]) ++k;\n        vs[2 * i] = k;\n        --k;\n        if (i +\
    \ k > r) {\n            l = i - k;\n            r = i + k;\n        }\n    }\n\
    \    // even length\n    for (int i = 1, l = 0, r = -1; i < n; ++i) {\n      \
    \  int k = (i > r) ? 0 : std::min(vs[2 * (l + r - i + 1) - 1], r - i + 1);\n \
    \       while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) ++k;\n\
    \        vs[2 * i - 1] = k;\n        --k;\n        if (i + k > r) {\n        \
    \    l = i - k - 1;\n            r = i + k;\n        }\n    }\n    return vs;\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include <string>\n\
    \nstd::vector<int> manacher(const std::string& s) {\n    int n = s.size();\n \
    \   std::vector<int> vs(2 * n - 1);\n    // odd length\n    for (int i = 0, l\
    \ = 0, r = -1; i < n; ++i) {\n        int k = (i > r) ? 1 : std::min(vs[2 * (l\
    \ + r - i)], r - i + 1);\n        while (0 <= i - k && i + k < n && s[i - k] ==\
    \ s[i + k]) ++k;\n        vs[2 * i] = k;\n        --k;\n        if (i + k > r)\
    \ {\n            l = i - k;\n            r = i + k;\n        }\n    }\n    //\
    \ even length\n    for (int i = 1, l = 0, r = -1; i < n; ++i) {\n        int k\
    \ = (i > r) ? 0 : std::min(vs[2 * (l + r - i + 1) - 1], r - i + 1);\n        while\
    \ (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) ++k;\n        vs[2\
    \ * i - 1] = k;\n        --k;\n        if (i + k > r) {\n            l = i - k\
    \ - 1;\n            r = i + k;\n        }\n    }\n    return vs;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.cpp
  requiredBy: []
  timestamp: '2021-01-29 21:47:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_palindromes.test.cpp
documentation_of: string/manacher.cpp
layout: document
title: Manacher's Algorithm
---

## Description

Manacher のアルゴリズムは，文字列中の回文である部分文字列を求めるアルゴリズムである．

返り値を$A$とする．$S_i$を中心とする最大の回文の長さを$x$とすると，$A[2i] = (x + 1) / 2$．$S_iS_{i+1}$を中心とする最大の回文の長さを$x$とすると，$A[2i + 1] = x / 2$．

- `vector<int> manacher(string s)`
    - Manacher のアルゴリズムを実行する
    - 時間計算量: $O(n)$

## Reference

- [Manacher's Algorithm - Finding all sub-palindromes in O(N)](https://cp-algorithms.com/string/manacher.html)