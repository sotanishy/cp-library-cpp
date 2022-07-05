---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.test.cpp
    title: test/yosupo/number_of_substrings.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/lcp_array.cpp\"\n#include <string>\n#include <vector>\n\
    \nstd::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa)\
    \ {\n    int n = s.size();\n    std::vector<int> rank(n);\n    for (int i = 0;\
    \ i < n; ++i) rank[sa[i]] = i;\n    int h = 0;\n    std::vector<int> lcp(n - 1);\n\
    \    for (int i = 0; i < n; ++i) {\n        if (h > 0) --h;\n        if (rank[i]\
    \ == 0) continue;\n        int j = sa[rank[i] - 1];\n        while (j + h < n\
    \ && i + h < n && s[j + h] == s[i + h]) ++h;\n        lcp[rank[i] - 1] = h;\n\
    \    }\n    return lcp;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\nstd::vector<int> lcp_array(const\
    \ std::string& s, const std::vector<int>& sa) {\n    int n = s.size();\n    std::vector<int>\
    \ rank(n);\n    for (int i = 0; i < n; ++i) rank[sa[i]] = i;\n    int h = 0;\n\
    \    std::vector<int> lcp(n - 1);\n    for (int i = 0; i < n; ++i) {\n       \
    \ if (h > 0) --h;\n        if (rank[i] == 0) continue;\n        int j = sa[rank[i]\
    \ - 1];\n        while (j + h < n && i + h < n && s[j + h] == s[i + h]) ++h;\n\
    \        lcp[rank[i] - 1] = h;\n    }\n    return lcp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/lcp_array.cpp
  requiredBy: []
  timestamp: '2022-07-05 13:16:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/number_of_substrings.test.cpp
documentation_of: string/lcp_array.cpp
layout: document
title: Longest Common Prefix Array
---

## Description

高さ配列 (LCP array) は，接尾辞配列における隣同士の接尾辞で，先頭何文字が共通しているかを表す配列である．`lcp[i]` は接尾辞 `s[sa[i]..]` と接尾辞 `s[sa[i + 1]..]` の先頭で共通している文字数になる．

## Operations

- `vector<int> lcp_array(string s, SuffixArray sa)`
    - 文字列 `s` と `s` の接尾辞配列 `sa` から高さ配列を構築する
    - 時間計算量: $O(n)$