---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.cpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#line 1 \"string/suffix_array.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/*\n * @brief Suffix Array\n * @docs docs/string/suffix_array.md\n */\n\
    struct SuffixArray {\n    vector<int> sa;\n    const string s;\n\n    SuffixArray(const\
    \ string& str) : s(str) {\n        int n = s.size();\n        sa.resize(n);\n\
    \        iota(sa.begin(), sa.end(), 0);\n        sort(sa.begin(), sa.end(), [&](int\
    \ i, int j) {\n            return s[i] == s[j] ? i > j : s[i] < s[j];\n      \
    \  });\n        int cl = 0;\n        vector<int> rank(n);\n        for (int i\
    \ = 1; i < n; i++) {\n            if (s[sa[i-1]] != s[sa[i]]) cl++;\n        \
    \    rank[sa[i]] = cl;\n        }\n        vector<int> tmp(n), nrank(n), cnt(n);\n\
    \        for (int k = 1; k < n; k *= 2) {\n            for (int i = 0; i < n;\
    \ i++) {\n                tmp[i] = sa[i] - k;\n                if (tmp[i] < 0)\
    \ tmp[i] += n;\n            }\n            fill(cnt.begin(), cnt.end(), 0);\n\
    \            for (int i = 0; i < n; i++) cnt[rank[tmp[i]]]++;\n            for\
    \ (int i = 1; i < n; i++) cnt[i] += cnt[i-1];\n            for (int i = n - 1;\
    \ i >= 0; i--) sa[--cnt[rank[tmp[i]]]] = tmp[i];\n            nrank[sa[0]] = 0;\n\
    \            cl = 0;\n            for (int i = 1; i < n; i++) {\n            \
    \    if (rank[sa[i-1]] != rank[sa[i]] || rank[(sa[i-1] + k) % n] != rank[(sa[i]\
    \ + k) % n]) {\n                    cl++;\n                }\n               \
    \ nrank[sa[i]] = cl;\n            }\n            swap(rank, nrank);\n        }\n\
    \    }\n\n    int operator[](int k) const {\n        return sa[k];\n    }\n\n\
    \    bool lt_substr(const string& t, int si = 0, int ti = 0) {\n        int sn\
    \ = s.size(), tn = t.size();\n        while (si < sn && ti < tn) {\n         \
    \   if (s[si] < t[ti]) return true;\n            if (s[si] > t[ti]) return false;\n\
    \            si++;\n            ti++;\n        }\n        return si >= sn && ti\
    \ < tn;\n    }\n\n    int lower_bound(const string& t) {\n        int lb = -1,\
    \ ub = sa.size();\n        while (ub - lb > 1) {\n            int m = (lb + ub)\
    \ / 2;\n            if (lt_substr(t, sa[m])) lb = m;\n            else ub = m;\n\
    \        }\n        return ub;\n    }\n\n    int upper_bound(string& t) {\n  \
    \      t.back()++;\n        int i = lower_bound(t);\n        t.back()--;\n   \
    \     return i;\n    }\n};\n#line 4 \"test/aoj/ALDS1_14_B.test.cpp\"\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    string T;\n\
    \    cin >> T;\n    string P;\n    cin >> P;\n    SuffixArray sa(T + '$');\n \
    \   int lb = sa.lower_bound(P);\n    int ub = sa.upper_bound(P);\n    vector<int>\
    \ ans;\n    for (int i = lb; i < ub; i++) ans.push_back(sa[i]);\n    sort(ans.begin(),\
    \ ans.end());\n    for (int i : ans) cout << i << \"\\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include \"../../string/suffix_array.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string T;\n    cin >> T;\n    string P;\n    cin >> P;\n\
    \    SuffixArray sa(T + '$');\n    int lb = sa.lower_bound(P);\n    int ub = sa.upper_bound(P);\n\
    \    vector<int> ans;\n    for (int i = lb; i < ub; i++) ans.push_back(sa[i]);\n\
    \    sort(ans.begin(), ans.end());\n    for (int i : ans) cout << i << \"\\n\"\
    ;\n}"
  dependsOn:
  - string/suffix_array.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 23:45:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.test.cpp
- /verify/test/aoj/ALDS1_14_B.test.cpp.html
title: test/aoj/ALDS1_14_B.test.cpp
---
