---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"string/suffix_array.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct SuffixArray {\n    vector<int> sa;\n    const string\
    \ s;\n\n    SuffixArray(const string& str) : s(str) {\n        int n = s.size();\n\
    \        sa.resize(n);\n        iota(sa.begin(), sa.end(), 0);\n        sort(sa.begin(),\
    \ sa.end(), [&](int i, int j) {\n            return s[i] == s[j] ? i > j : s[i]\
    \ < s[j];\n        });\n        int cl = 0;\n        vector<int> rank(n);\n  \
    \      for (int i = 1; i < n; i++) {\n            if (s[sa[i-1]] != s[sa[i]])\
    \ cl++;\n            rank[sa[i]] = cl;\n        }\n        vector<int> tmp(n),\
    \ nrank(n), cnt(n);\n        for (int k = 1; k < n; k *= 2) {\n            for\
    \ (int i = 0; i < n; i++) {\n                tmp[i] = sa[i] - k;\n           \
    \     if (tmp[i] < 0) tmp[i] += n;\n            }\n            fill(cnt.begin(),\
    \ cnt.end(), 0);\n            for (int i = 0; i < n; i++) cnt[rank[tmp[i]]]++;\n\
    \            for (int i = 1; i < n; i++) cnt[i] += cnt[i-1];\n            for\
    \ (int i = n - 1; i >= 0; i--) sa[--cnt[rank[tmp[i]]]] = tmp[i];\n           \
    \ nrank[sa[0]] = 0;\n            cl = 0;\n            for (int i = 1; i < n; i++)\
    \ {\n                if (rank[sa[i-1]] != rank[sa[i]] || rank[(sa[i-1] + k) %\
    \ n] != rank[(sa[i] + k) % n]) {\n                    cl++;\n                }\n\
    \                nrank[sa[i]] = cl;\n            }\n            swap(rank, nrank);\n\
    \        }\n    }\n\n    int operator[](int k) const {\n        return sa[k];\n\
    \    }\n\n    bool lt_substr(const string& t, int si = 0, int ti = 0) {\n    \
    \    int sn = s.size(), tn = t.size();\n        while (si < sn && ti < tn) {\n\
    \            if (s[si] < t[ti]) return true;\n            if (s[si] > t[ti]) return\
    \ false;\n            si++;\n            ti++;\n        }\n        return si >=\
    \ sn && ti < tn;\n    }\n\n    int lower_bound(const string& t) {\n        int\
    \ lb = -1, ub = sa.size();\n        while (ub - lb > 1) {\n            int m =\
    \ (lb + ub) / 2;\n            if (lt_substr(t, sa[m])) lb = m;\n            else\
    \ ub = m;\n        }\n        return ub;\n    }\n\n    int upper_bound(string&\
    \ t) {\n        t.back()++;\n        int i = lower_bound(t);\n        t.back()--;\n\
    \        return i;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct SuffixArray {\n\
    \    vector<int> sa;\n    const string s;\n\n    SuffixArray(const string& str)\
    \ : s(str) {\n        int n = s.size();\n        sa.resize(n);\n        iota(sa.begin(),\
    \ sa.end(), 0);\n        sort(sa.begin(), sa.end(), [&](int i, int j) {\n    \
    \        return s[i] == s[j] ? i > j : s[i] < s[j];\n        });\n        int\
    \ cl = 0;\n        vector<int> rank(n);\n        for (int i = 1; i < n; i++) {\n\
    \            if (s[sa[i-1]] != s[sa[i]]) cl++;\n            rank[sa[i]] = cl;\n\
    \        }\n        vector<int> tmp(n), nrank(n), cnt(n);\n        for (int k\
    \ = 1; k < n; k *= 2) {\n            for (int i = 0; i < n; i++) {\n         \
    \       tmp[i] = sa[i] - k;\n                if (tmp[i] < 0) tmp[i] += n;\n  \
    \          }\n            fill(cnt.begin(), cnt.end(), 0);\n            for (int\
    \ i = 0; i < n; i++) cnt[rank[tmp[i]]]++;\n            for (int i = 1; i < n;\
    \ i++) cnt[i] += cnt[i-1];\n            for (int i = n - 1; i >= 0; i--) sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n            nrank[sa[0]] = 0;\n            cl = 0;\n            for\
    \ (int i = 1; i < n; i++) {\n                if (rank[sa[i-1]] != rank[sa[i]]\
    \ || rank[(sa[i-1] + k) % n] != rank[(sa[i] + k) % n]) {\n                   \
    \ cl++;\n                }\n                nrank[sa[i]] = cl;\n            }\n\
    \            swap(rank, nrank);\n        }\n    }\n\n    int operator[](int k)\
    \ const {\n        return sa[k];\n    }\n\n    bool lt_substr(const string& t,\
    \ int si = 0, int ti = 0) {\n        int sn = s.size(), tn = t.size();\n     \
    \   while (si < sn && ti < tn) {\n            if (s[si] < t[ti]) return true;\n\
    \            if (s[si] > t[ti]) return false;\n            si++;\n           \
    \ ti++;\n        }\n        return si >= sn && ti < tn;\n    }\n\n    int lower_bound(const\
    \ string& t) {\n        int lb = -1, ub = sa.size();\n        while (ub - lb >\
    \ 1) {\n            int m = (lb + ub) / 2;\n            if (lt_substr(t, sa[m]))\
    \ lb = m;\n            else ub = m;\n        }\n        return ub;\n    }\n\n\
    \    int upper_bound(string& t) {\n        t.back()++;\n        int i = lower_bound(t);\n\
    \        t.back()--;\n        return i;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.cpp
  requiredBy: []
  timestamp: '2020-09-02 15:53:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.test.cpp
documentation_of: string/suffix_array.cpp
layout: document
redirect_from:
- /library/string/suffix_array.cpp
- /library/string/suffix_array.cpp.html
title: string/suffix_array.cpp
---
