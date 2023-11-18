---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/lcp_array.cpp
    title: Longest Common Prefix Array
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.cpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/longest_common_substring.test.cpp
    title: test/yosupo/longest_common_substring.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Longest Common Substring
    links: []
  bundledCode: "#line 2 \"string/longest_common_substring.hpp\"\n#include <algorithm>\n\
    #include <string>\n\n#line 3 \"string/lcp_array.cpp\"\n#include <vector>\n\ntemplate\
    \ <typename T>\nstd::vector<int> lcp_array(const std::vector<T>& s,\n        \
    \                   const std::vector<int>& sa) {\n    int n = s.size();\n   \
    \ std::vector<int> rank(n);\n    for (int i = 0; i < n; ++i) rank[sa[i]] = i;\n\
    \    int h = 0;\n    std::vector<int> lcp(n - 1);\n    for (int i = 0; i < n;\
    \ ++i) {\n        if (h > 0) --h;\n        if (rank[i] == 0) continue;\n     \
    \   int j = sa[rank[i] - 1];\n        while (j + h < n && i + h < n && s[j + h]\
    \ == s[i + h]) ++h;\n        lcp[rank[i] - 1] = h;\n    }\n    return lcp;\n}\n\
    \nstd::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa)\
    \ {\n    return lcp_array(std::vector<char>(s.begin(), s.end()), sa);\n}\n#line\
    \ 3 \"string/suffix_array.cpp\"\n#include <numeric>\n#line 6 \"string/suffix_array.cpp\"\
    \n\ntemplate <typename T>\nstd::vector<int> suffix_array(const std::vector<T>&\
    \ s) {\n    int n = s.size();\n    std::vector<int> sa(n);\n    std::iota(sa.begin(),\
    \ sa.end(), 0);\n    std::sort(sa.begin(), sa.end(), [&](int i, int j) {\n   \
    \     return s[i] < s[j];\n    });\n    int cl = 0;\n    std::vector<int> rank(n);\n\
    \    for (int i = 1; i < n; ++i) {\n        if (s[sa[i - 1]] != s[sa[i]]) ++cl;\n\
    \        rank[sa[i]] = cl;\n    }\n    std::vector<int> tmp(n), nrank(n), cnt(n);\n\
    \    for (int k = 1; k < n; k <<= 1) {\n        // sort by second half\n     \
    \   int cnt1 = 0, cnt2 = k;\n        for (int i = 0; i < n; ++i) {\n         \
    \   int j = sa[i] - k;\n            if (j >= 0) tmp[cnt2++] = j;\n           \
    \ else tmp[cnt1++] = j + n;\n        }\n\n        // sort by first half\n    \
    \    std::fill(cnt.begin(), cnt.end(), 0);\n        for (int i = 0; i < n; ++i)\
    \ ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n; ++i) cnt[i] += cnt[i -\
    \ 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]] = tmp[i];\n\
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
    \ t[ti]) return false;\n    }\n    return si == sn && ti < tn;\n};\n*/\n#line\
    \ 7 \"string/longest_common_substring.hpp\"\n\n/**\n * @brief Longest Common Substring\n\
    \ */\nstd::tuple<int, int, int, int> longest_common_substring(const std::string&\
    \ S,\n                                                        const std::string&\
    \ T) {\n    const int N = S.size();\n    auto ST = S + \"$\" + T;\n    auto sa\
    \ = suffix_array(ST);\n    auto lcp = lcp_array(ST, sa);\n    std::pair<int, std::tuple<int,\
    \ int, int, int>> ans(0, {0, 0, 0, 0});\n    for (int i = 0; i < (int)ST.size()\
    \ - 1; ++i) {\n        int len = lcp[i];\n        if (len == 0) continue;\n  \
    \      if (sa[i] < N && sa[i + 1] >= N + 1) {\n            int a = sa[i], c =\
    \ sa[i + 1] - N - 1;\n            ans = std::max(ans, {len, {a, a + len, c, c\
    \ + len}});\n        } else if (sa[i] >= N + 1 && sa[i + 1] < N) {\n         \
    \   int a = sa[i + 1], c = sa[i] - N - 1;\n            ans = std::max(ans, {len,\
    \ {a, a + len, c, c + len}});\n        }\n    }\n    return ans.second;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <string>\n\n#include \"lcp_array.cpp\"\
    \n#include \"suffix_array.cpp\"\n\n/**\n * @brief Longest Common Substring\n */\n\
    std::tuple<int, int, int, int> longest_common_substring(const std::string& S,\n\
    \                                                        const std::string& T)\
    \ {\n    const int N = S.size();\n    auto ST = S + \"$\" + T;\n    auto sa =\
    \ suffix_array(ST);\n    auto lcp = lcp_array(ST, sa);\n    std::pair<int, std::tuple<int,\
    \ int, int, int>> ans(0, {0, 0, 0, 0});\n    for (int i = 0; i < (int)ST.size()\
    \ - 1; ++i) {\n        int len = lcp[i];\n        if (len == 0) continue;\n  \
    \      if (sa[i] < N && sa[i + 1] >= N + 1) {\n            int a = sa[i], c =\
    \ sa[i + 1] - N - 1;\n            ans = std::max(ans, {len, {a, a + len, c, c\
    \ + len}});\n        } else if (sa[i] >= N + 1 && sa[i + 1] < N) {\n         \
    \   int a = sa[i + 1], c = sa[i] - N - 1;\n            ans = std::max(ans, {len,\
    \ {a, a + len, c, c + len}});\n        }\n    }\n    return ans.second;\n}"
  dependsOn:
  - string/lcp_array.cpp
  - string/suffix_array.cpp
  isVerificationFile: false
  path: string/longest_common_substring.hpp
  requiredBy: []
  timestamp: '2023-11-18 13:57:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/longest_common_substring.test.cpp
documentation_of: string/longest_common_substring.hpp
layout: document
redirect_from:
- /library/string/longest_common_substring.hpp
- /library/string/longest_common_substring.hpp.html
title: Longest Common Substring
---
