---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/enumerate_runs.hpp
    title: Enumerate Runs
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/runenumerate.test.cpp
    title: test/yosupo/runenumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_array.cpp\"\n#include <string>\n#include <vector>\n\
    \nstd::vector<int> z_array(const std::string& s) {\n    int n = s.size();\n  \
    \  std::vector<int> z(n);\n    z[0] = n;\n    int l = 0, r = 0;\n    for (int\
    \ i = 1; i < n; ++i) {\n        int k = i - l;\n        if (i <= r && z[k] < r\
    \ - i + 1) {\n            z[i] = z[k];\n        } else {\n            l = i;\n\
    \            if (i > r) r = i;\n            while (r < n && s[r - l] == s[r])\
    \ ++r;\n            --r;\n            z[i] = r - l + 1;\n        }\n    }\n  \
    \  return z;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\nstd::vector<int> z_array(const\
    \ std::string& s) {\n    int n = s.size();\n    std::vector<int> z(n);\n    z[0]\
    \ = n;\n    int l = 0, r = 0;\n    for (int i = 1; i < n; ++i) {\n        int\
    \ k = i - l;\n        if (i <= r && z[k] < r - i + 1) {\n            z[i] = z[k];\n\
    \        } else {\n            l = i;\n            if (i > r) r = i;\n       \
    \     while (r < n && s[r - l] == s[r]) ++r;\n            --r;\n            z[i]\
    \ = r - l + 1;\n        }\n    }\n    return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_array.cpp
  requiredBy:
  - string/enumerate_runs.hpp
  timestamp: '2021-01-17 18:23:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/runenumerate.test.cpp
  - test/yosupo/zalgorithm.test.cpp
documentation_of: string/z_array.cpp
layout: document
title: Z Array
---

## Description

Z array は，文字列 `S` と `S[i:]` の最長共通接頭辞の長さを表す配列である．Z array を求めるアルゴリズムは Z algorithm と呼ばれる．

Z array を用いると文字列中のパターンをすべて検索することができる．文字列を `S`，パターンを `P` とし，`P$S` (`$` は `S` にも `P` にも含まれない文字) の Z array を構築すると，値が `P` の長さと一致するところで `P` が現れる．

## Operations

- `vector<int> z_array(string s)`
    - Z array を構築する
    - 時間計算量: $O(n)$

## Reference

- [Z algorithm (Linear time pattern searching Algorithm)](https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/)