---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.cpp
    title: Suffix Array
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
    #line 2 \"string/suffix_array.cpp\"\n#include <algorithm>\n#include <limits>\n\
    #include <numeric>\n#line 7 \"string/suffix_array.cpp\"\n\nclass SuffixArray {\n\
    public:\n    SuffixArray() = default;\n    explicit SuffixArray(const std::string&\
    \ str) : s(str) {\n        int n = s.size();\n        sa.resize(n);\n        std::iota(sa.begin(),\
    \ sa.end(), 0);\n        std::sort(sa.begin(), sa.end(), [&](int i, int j) {\n\
    \            return s[i] < s[j];\n        });\n        int cl = 0;\n        std::vector<int>\
    \ rank(n);\n        for (int i = 1; i < n; ++i) {\n            if (s[sa[i - 1]]\
    \ != s[sa[i]]) ++cl;\n            rank[sa[i]] = cl;\n        }\n        std::vector<int>\
    \ tmp(n), nrank(n), cnt(n);\n        for (int k = 1; k < n; k <<= 1) {\n     \
    \       // sort by second half\n            int cnt1 = 0, cnt2 = k;\n        \
    \    for (int i = 0; i < n; ++i) {\n                int j = sa[i] - k;\n     \
    \           if (j >= 0) tmp[cnt2++] = j;\n                else tmp[cnt1++] = j\
    \ + n;\n            }\n\n            // sort by first half\n            std::fill(cnt.begin(),\
    \ cnt.end(), 0);\n            for (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n\
    \            for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];\n            for\
    \ (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]] = tmp[i];\n\n         \
    \   // assign new rank\n            nrank[sa[0]] = 0;\n            cl = 0;\n \
    \           for (int i = 1; i < n; ++i) {\n                if (rank[sa[i - 1]]\
    \ != rank[sa[i]]\n                    || (sa[i - 1] + k < n ? rank[sa[i - 1] +\
    \ k] : -1) != (sa[i] + k < n ? rank[sa[i] + k] : -1)) {\n                    ++cl;\n\
    \                }\n                nrank[sa[i]] = cl;\n            }\n      \
    \      std::swap(rank, nrank);\n        }\n    }\n\n    int operator[](int k)\
    \ const {\n        return sa[k];\n    }\n\n    int lower_bound(const std::string&\
    \ t) const {\n        int lb = -1, ub = sa.size();\n        while (ub - lb > 1)\
    \ {\n            int m = (lb + ub) / 2;\n            if (lt_substr(t, sa[m]))\
    \ lb = m;\n            else ub = m;\n        }\n        return ub;\n    }\n\n\
    \    int upper_bound(const std::string& t) const {\n        return lower_bound(t\
    \ + std::numeric_limits<char>::max());\n    }\n\nprivate:\n    std::vector<int>\
    \ sa;\n    const std::string s;\n\n    bool lt_substr(const std::string& t, int\
    \ si) const {\n        int sn = s.size(), tn = t.size();\n        int ti = 0;\n\
    \        for (; si < sn && ti < tn; ++si, ++ti) {\n            if (s[si] < t[ti])\
    \ return true;\n            if (s[si] > t[ti]) return false;\n        }\n    \
    \    return si >= sn && ti < tn;\n    }\n};\n#line 5 \"string/lcp_array.cpp\"\n\
    \nstd::vector<int> lcp_array(const std::string& s, const SuffixArray& sa) {\n\
    \    int n = s.size();\n    std::vector<int> rank(n);\n    for (int i = 0; i <\
    \ n; ++i) rank[sa[i]] = i;\n    int h = 0;\n    std::vector<int> lcp(n - 1);\n\
    \    for (int i = 0; i < n; ++i) {\n        if (h > 0) --h;\n        if (rank[i]\
    \ == 0) continue;\n        int j = sa[rank[i] - 1];\n        while (j + h < n\
    \ && i + h < n && s[j + h] == s[i + h]) ++h;\n        lcp[rank[i] - 1] = h;\n\
    \    }\n    return lcp;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n#include \"suffix_array.cpp\"\
    \n\nstd::vector<int> lcp_array(const std::string& s, const SuffixArray& sa) {\n\
    \    int n = s.size();\n    std::vector<int> rank(n);\n    for (int i = 0; i <\
    \ n; ++i) rank[sa[i]] = i;\n    int h = 0;\n    std::vector<int> lcp(n - 1);\n\
    \    for (int i = 0; i < n; ++i) {\n        if (h > 0) --h;\n        if (rank[i]\
    \ == 0) continue;\n        int j = sa[rank[i] - 1];\n        while (j + h < n\
    \ && i + h < n && s[j + h] == s[i + h]) ++h;\n        lcp[rank[i] - 1] = h;\n\
    \    }\n    return lcp;\n}"
  dependsOn:
  - string/suffix_array.cpp
  isVerificationFile: false
  path: string/lcp_array.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:23:01+09:00'
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