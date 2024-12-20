---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"test/yosupo/suffixarray.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\
    \n\n#line 2 \"string/suffix_array.hpp\"\n#include <algorithm>\n#include <numeric>\n\
    #include <string>\n#include <vector>\n\ntemplate <typename T>\nstd::vector<int>\
    \ suffix_array(const std::vector<T>& s) {\n    const int n = s.size();\n    std::vector<int>\
    \ sa(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    std::ranges::sort(sa, {},\
    \ [&](int i) { return s[i]; });\n    int cl = 0;\n    std::vector<int> rank(n);\n\
    \    for (int i = 1; i < n; ++i) {\n        if (s[sa[i - 1]] != s[sa[i]]) ++cl;\n\
    \        rank[sa[i]] = cl;\n    }\n    std::vector<int> tmp(n), nrank(n), cnt(n);\n\
    \    for (int k = 1; k < n; k <<= 1) {\n        // sort by second half\n     \
    \   int cnt1 = 0, cnt2 = k;\n        for (int i = 0; i < n; ++i) {\n         \
    \   int j = sa[i] - k;\n            if (j >= 0)\n                tmp[cnt2++] =\
    \ j;\n            else\n                tmp[cnt1++] = j + n;\n        }\n\n  \
    \      // sort by first half\n        std::ranges::fill(cnt, 0);\n        for\
    \ (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n;\
    \ ++i) cnt[i] += cnt[i - 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n\n        // assign new rank\n        nrank[sa[0]] = 0;\n       \
    \ cl = 0;\n        for (int i = 1; i < n; ++i) {\n            if (rank[sa[i -\
    \ 1]] != rank[sa[i]] ||\n                (sa[i - 1] + k < n ? rank[sa[i - 1] +\
    \ k] : -1) !=\n                    (sa[i] + k < n ? rank[sa[i] + k] : -1)) {\n\
    \                ++cl;\n            }\n            nrank[sa[i]] = cl;\n      \
    \  }\n        rank.swap(nrank);\n    }\n    return sa;\n}\n\nstd::vector<int>\
    \ suffix_array(const std::string& s) {\n    return suffix_array(std::vector<char>(s.begin(),\
    \ s.end()));\n}\n\ntemplate <typename T>\nstd::vector<int> cyclic_suffix_array(const\
    \ std::vector<T>& s) {\n    const int n = s.size();\n    std::vector<int> sa(n);\n\
    \    std::iota(sa.begin(), sa.end(), 0);\n    std::ranges::sort(sa, {}, [&](int\
    \ i) { return s[i]; });\n    int cl = 0;\n    std::vector<int> rank(n);\n    for\
    \ (int i = 1; i < n; ++i) {\n        if (s[sa[i - 1]] != s[sa[i]]) ++cl;\n   \
    \     rank[sa[i]] = cl;\n    }\n    std::vector<int> tmp(n), nrank(n), cnt(n);\n\
    \    for (int k = 1; k < n; k <<= 1) {\n        // sort by second half\n     \
    \   int cnt1 = 0, cnt2 = k;\n        for (int i = 0; i < n; ++i) {\n         \
    \   int j = sa[i] - k;\n            if (j >= 0)\n                tmp[cnt2++] =\
    \ j;\n            else\n                tmp[cnt1++] = j + n;\n        }\n\n  \
    \      // sort by first half\n        std::ranges::fill(cnt, 0);\n        for\
    \ (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n;\
    \ ++i) cnt[i] += cnt[i - 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n\n        // assign new rank\n        nrank[sa[0]] = 0;\n       \
    \ cl = 0;\n        for (int i = 1; i < n; ++i) {\n            if (rank[sa[i -\
    \ 1]] != rank[sa[i]] ||\n                rank[(sa[i - 1] + k) % n] != rank[(sa[i]\
    \ + k) % n]) {\n                ++cl;\n            }\n            nrank[sa[i]]\
    \ = cl;\n        }\n        rank.swap(nrank);\n    }\n    return sa;\n}\n\nstd::vector<int>\
    \ cyclic_suffix_array(const std::string& s) {\n    return cyclic_suffix_array(std::vector<char>(s.begin(),\
    \ s.end()));\n}\n\n/*\n// comparator for substrings\n// used for string matching\
    \ with the suffix array\n// use cmp1 for lower_bound and cmp2 for upper_bound\n\
    // replace S with your variable name for the string\n\nauto cmp1 = [&](int si,\
    \ const string& t) {\n    int sn = S.size(), tn = t.size();\n    int ti = 0;\n\
    \    for (; si < sn && ti < tn; ++si, ++ti) {\n        if (S[si] < t[ti]) return\
    \ true;\n        if (S[si] > t[ti]) return false;\n    }\n    return si == sn\
    \ && ti < tn;\n};\n\nauto cmp2 = [&](const string& t, int si) {\n    int sn =\
    \ S.size(), tn = t.size();\n    int ti = 0;\n    for (; si < sn && ti < tn; ++si,\
    \ ++ti) {\n        if (S[si] > t[ti]) return true;\n        if (S[si] < t[ti])\
    \ return false;\n    }\n    return ti == tn && si < tn;\n};\n*/\n#line 4 \"test/yosupo/suffixarray.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string S;\n    cin >> S;\n    auto sa = suffix_array(S);\n\
    \    for (int i = 0; i < S.size(); ++i) {\n        cout << sa[i] << (i < S.size()\
    \ - 1 ? \" \" : \"\\n\");\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"../../string/suffix_array.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    string S;\n    cin >> S;\n    auto sa = suffix_array(S);\n    for (int i\
    \ = 0; i < S.size(); ++i) {\n        cout << sa[i] << (i < S.size() - 1 ? \" \"\
    \ : \"\\n\");\n    }\n}"
  dependsOn:
  - string/suffix_array.hpp
  isVerificationFile: true
  path: test/yosupo/suffixarray.test.cpp
  requiredBy: []
  timestamp: '2024-12-20 23:39:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/suffixarray.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/suffixarray.test.cpp
- /verify/test/yosupo/suffixarray.test.cpp.html
title: test/yosupo/suffixarray.test.cpp
---
