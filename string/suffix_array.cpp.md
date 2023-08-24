---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.suffix_array.test.cpp
    title: test/aoj/ALDS1_14_B.suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.test.cpp
    title: test/yosupo/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix_array.cpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <string>\n#include <vector>\n\ntemplate <typename T>\nstd::vector<int>\
    \ suffix_array(const std::vector<T>& s) {\n    int n = s.size();\n    std::vector<int>\
    \ sa(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    std::sort(sa.begin(), sa.end(),\
    \ [&](int i, int j) {\n        return s[i] < s[j];\n    });\n    int cl = 0;\n\
    \    std::vector<int> rank(n);\n    for (int i = 1; i < n; ++i) {\n        if\
    \ (s[sa[i - 1]] != s[sa[i]]) ++cl;\n        rank[sa[i]] = cl;\n    }\n    std::vector<int>\
    \ tmp(n), nrank(n), cnt(n);\n    for (int k = 1; k < n; k <<= 1) {\n        //\
    \ sort by second half\n        int cnt1 = 0, cnt2 = k;\n        for (int i = 0;\
    \ i < n; ++i) {\n            int j = sa[i] - k;\n            if (j >= 0) tmp[cnt2++]\
    \ = j;\n            else tmp[cnt1++] = j + n;\n        }\n\n        // sort by\
    \ first half\n        std::fill(cnt.begin(), cnt.end(), 0);\n        for (int\
    \ i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n; ++i)\
    \ cnt[i] += cnt[i - 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n\n        // assign new rank\n        nrank[sa[0]] = 0;\n       \
    \ cl = 0;\n        for (int i = 1; i < n; ++i) {\n            if (rank[sa[i -\
    \ 1]] != rank[sa[i]]\n                || (sa[i - 1] + k < n ? rank[sa[i - 1] +\
    \ k] : -1) != (sa[i] + k < n ? rank[sa[i] + k] : -1)) {\n                ++cl;\n\
    \            }\n            nrank[sa[i]] = cl;\n        }\n        std::swap(rank,\
    \ nrank);\n    }\n    return sa;\n}\n\nstd::vector<int> suffix_array(const std::string&\
    \ s) {\n    return suffix_array(std::vector<char>(s.begin(), s.end()));\n}\n\n\
    \ntemplate <typename T>\nstd::vector<int> cyclic_suffix_array(const std::vector<T>&\
    \ s) {\n    int n = s.size();\n    std::vector<int> sa(n);\n    std::iota(sa.begin(),\
    \ sa.end(), 0);\n    std::sort(sa.begin(), sa.end(), [&](int i, int j) { return\
    \ s[i] < s[j]; });\n    int cl = 0;\n    std::vector<int> rank(n);\n    for (int\
    \ i = 1; i < n; ++i) {\n        if (s[sa[i - 1]] != s[sa[i]]) ++cl;\n        rank[sa[i]]\
    \ = cl;\n    }\n    std::vector<int> tmp(n), nrank(n), cnt(n);\n    for (int k\
    \ = 1; k < n; k <<= 1) {\n        // sort by second half\n        int cnt1 = 0,\
    \ cnt2 = k;\n        for (int i = 0; i < n; ++i) {\n            int j = sa[i]\
    \ - k;\n            if (j >= 0)\n                tmp[cnt2++] = j;\n          \
    \  else\n                tmp[cnt1++] = j + n;\n        }\n\n        // sort by\
    \ first half\n        std::fill(cnt.begin(), cnt.end(), 0);\n        for (int\
    \ i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n; ++i)\
    \ cnt[i] += cnt[i - 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n\n        // assign new rank\n        nrank[sa[0]] = 0;\n       \
    \ cl = 0;\n        for (int i = 1; i < n; ++i) {\n            if (rank[sa[i -\
    \ 1]] != rank[sa[i]] ||\n                rank[(sa[i - 1] + k) % n] != rank[(sa[i]\
    \ + k) % n]) {\n                ++cl;\n            }\n            nrank[sa[i]]\
    \ = cl;\n        }\n        std::swap(rank, nrank);\n    }\n    return sa;\n}\n\
    \nstd::vector<int> cyclic_suffix_array(const std::string& s) {\n    return cyclic_suffix_array(std::vector<char>(s.begin(),\
    \ s.end()));\n}\n\n/*\n// comparator for substrings\n// used for string matching\
    \ with the suffix array\n\nauto cmp = [&](int si, const string& t) {\n    int\
    \ sn = S.size(), tn = t.size();\n    int ti = 0;\n    for (; si < sn && ti < tn;\
    \ ++si, ++ti) {\n        if (T[si] < t[ti]) return true;\n        if (T[si] >\
    \ t[ti]) return false;\n    }\n    return si == sn && ti < tn;\n};\n*/\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <string>\n\
    #include <vector>\n\ntemplate <typename T>\nstd::vector<int> suffix_array(const\
    \ std::vector<T>& s) {\n    int n = s.size();\n    std::vector<int> sa(n);\n \
    \   std::iota(sa.begin(), sa.end(), 0);\n    std::sort(sa.begin(), sa.end(), [&](int\
    \ i, int j) {\n        return s[i] < s[j];\n    });\n    int cl = 0;\n    std::vector<int>\
    \ rank(n);\n    for (int i = 1; i < n; ++i) {\n        if (s[sa[i - 1]] != s[sa[i]])\
    \ ++cl;\n        rank[sa[i]] = cl;\n    }\n    std::vector<int> tmp(n), nrank(n),\
    \ cnt(n);\n    for (int k = 1; k < n; k <<= 1) {\n        // sort by second half\n\
    \        int cnt1 = 0, cnt2 = k;\n        for (int i = 0; i < n; ++i) {\n    \
    \        int j = sa[i] - k;\n            if (j >= 0) tmp[cnt2++] = j;\n      \
    \      else tmp[cnt1++] = j + n;\n        }\n\n        // sort by first half\n\
    \        std::fill(cnt.begin(), cnt.end(), 0);\n        for (int i = 0; i < n;\
    \ ++i) ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n; ++i) cnt[i] += cnt[i\
    \ - 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]] = tmp[i];\n\
    \n        // assign new rank\n        nrank[sa[0]] = 0;\n        cl = 0;\n   \
    \     for (int i = 1; i < n; ++i) {\n            if (rank[sa[i - 1]] != rank[sa[i]]\n\
    \                || (sa[i - 1] + k < n ? rank[sa[i - 1] + k] : -1) != (sa[i] +\
    \ k < n ? rank[sa[i] + k] : -1)) {\n                ++cl;\n            }\n   \
    \         nrank[sa[i]] = cl;\n        }\n        std::swap(rank, nrank);\n   \
    \ }\n    return sa;\n}\n\nstd::vector<int> suffix_array(const std::string& s)\
    \ {\n    return suffix_array(std::vector<char>(s.begin(), s.end()));\n}\n\n\n\
    template <typename T>\nstd::vector<int> cyclic_suffix_array(const std::vector<T>&\
    \ s) {\n    int n = s.size();\n    std::vector<int> sa(n);\n    std::iota(sa.begin(),\
    \ sa.end(), 0);\n    std::sort(sa.begin(), sa.end(), [&](int i, int j) { return\
    \ s[i] < s[j]; });\n    int cl = 0;\n    std::vector<int> rank(n);\n    for (int\
    \ i = 1; i < n; ++i) {\n        if (s[sa[i - 1]] != s[sa[i]]) ++cl;\n        rank[sa[i]]\
    \ = cl;\n    }\n    std::vector<int> tmp(n), nrank(n), cnt(n);\n    for (int k\
    \ = 1; k < n; k <<= 1) {\n        // sort by second half\n        int cnt1 = 0,\
    \ cnt2 = k;\n        for (int i = 0; i < n; ++i) {\n            int j = sa[i]\
    \ - k;\n            if (j >= 0)\n                tmp[cnt2++] = j;\n          \
    \  else\n                tmp[cnt1++] = j + n;\n        }\n\n        // sort by\
    \ first half\n        std::fill(cnt.begin(), cnt.end(), 0);\n        for (int\
    \ i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n; ++i)\
    \ cnt[i] += cnt[i - 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n\n        // assign new rank\n        nrank[sa[0]] = 0;\n       \
    \ cl = 0;\n        for (int i = 1; i < n; ++i) {\n            if (rank[sa[i -\
    \ 1]] != rank[sa[i]] ||\n                rank[(sa[i - 1] + k) % n] != rank[(sa[i]\
    \ + k) % n]) {\n                ++cl;\n            }\n            nrank[sa[i]]\
    \ = cl;\n        }\n        std::swap(rank, nrank);\n    }\n    return sa;\n}\n\
    \nstd::vector<int> cyclic_suffix_array(const std::string& s) {\n    return cyclic_suffix_array(std::vector<char>(s.begin(),\
    \ s.end()));\n}\n\n/*\n// comparator for substrings\n// used for string matching\
    \ with the suffix array\n\nauto cmp = [&](int si, const string& t) {\n    int\
    \ sn = S.size(), tn = t.size();\n    int ti = 0;\n    for (; si < sn && ti < tn;\
    \ ++si, ++ti) {\n        if (T[si] < t[ti]) return true;\n        if (T[si] >\
    \ t[ti]) return false;\n    }\n    return si == sn && ti < tn;\n};\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.cpp
  requiredBy: []
  timestamp: '2023-04-08 00:55:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/suffixarray.test.cpp
  - test/yosupo/number_of_substrings.test.cpp
  - test/aoj/ALDS1_14_B.suffix_array.test.cpp
documentation_of: string/suffix_array.cpp
layout: document
title: Suffix Array
---

## Description

接尾辞配列 (suffix array) は，文字列のインデックスを接尾辞の辞書順に並べたものである．文字列検索が効率的に行える．

この実装では Manber-Myers のアルゴリズムを用いている．ソートに基数ソートを用いることで時間計算量を $O(n\log^2 n)$ から $O(n\log n)$ に改善している．

なお，SA-IS という $O(n)$ のアルゴリズムもある (未実装)．

## Operations

- `vector<int> suffix_array(string s)`
    - `s` の接尾辞配列を構築する
    - 時間計算量: $O(n\log n)$

## Reference

- [Suffix Array](https://cp-algorithms.com/string/suffix-array.html)