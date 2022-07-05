---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/suffix_array.cpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.suffix_array.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #line 2 \"string/suffix_array.cpp\"\n#include <algorithm>\n#include <numeric>\n\
    #include <string>\n#include <vector>\n\nstd::vector<int> suffix_array(const std::string&\
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
    \ }\n    return sa;\n}\n\n/*\n// comparator for substrings\n// used for string\
    \ matching with the suffix array\n\nauto cmp = [&](int si, const string& t) {\n\
    \    int sn = S.size(), tn = t.size();\n    int ti = 0;\n    for (; si < sn &&\
    \ ti < tn; ++si, ++ti) {\n        if (T[si] < t[ti]) return true;\n        if\
    \ (T[si] > t[ti]) return false;\n    }\n    return si == sn && ti < tn;\n};\n\
    */\n#line 4 \"test/aoj/ALDS1_14_B.suffix_array.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string T;\n    cin >> T;\n    string P;\n    cin >> P;\n\
    \    auto sa = suffix_array(T);\n\n    auto cmp = [&](int si, const string& t)\
    \ {\n        int sn = T.size(), tn = t.size();\n        int ti = 0;\n        for\
    \ (; si < sn && ti < tn; ++si, ++ti) {\n            if (T[si] < t[ti]) return\
    \ true;\n            if (T[si] > t[ti]) return false;\n        }\n        return\
    \ si == sn && ti < tn;\n    };\n\n    int lb = lower_bound(sa.begin(), sa.end(),\
    \ P, cmp) - sa.begin();\n    int ub = lower_bound(sa.begin(), sa.end(), P + '~',\
    \ cmp) - sa.begin();\n    vector<int> ans;\n    for (int i = lb; i < ub; i++)\
    \ ans.push_back(sa[i]);\n    sort(ans.begin(), ans.end());\n    for (int i : ans)\
    \ cout << i << \"\\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include \"../../string/suffix_array.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    string T;\n    cin >> T;\n    string P;\n    cin >> P;\n    auto sa = suffix_array(T);\n\
    \n    auto cmp = [&](int si, const string& t) {\n        int sn = T.size(), tn\
    \ = t.size();\n        int ti = 0;\n        for (; si < sn && ti < tn; ++si, ++ti)\
    \ {\n            if (T[si] < t[ti]) return true;\n            if (T[si] > t[ti])\
    \ return false;\n        }\n        return si == sn && ti < tn;\n    };\n\n  \
    \  int lb = lower_bound(sa.begin(), sa.end(), P, cmp) - sa.begin();\n    int ub\
    \ = lower_bound(sa.begin(), sa.end(), P + '~', cmp) - sa.begin();\n    vector<int>\
    \ ans;\n    for (int i = lb; i < ub; i++) ans.push_back(sa[i]);\n    sort(ans.begin(),\
    \ ans.end());\n    for (int i : ans) cout << i << \"\\n\";\n}"
  dependsOn:
  - string/suffix_array.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.suffix_array.test.cpp
  requiredBy: []
  timestamp: '2022-07-05 13:04:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.suffix_array.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.suffix_array.test.cpp
- /verify/test/aoj/ALDS1_14_B.suffix_array.test.cpp.html
title: test/aoj/ALDS1_14_B.suffix_array.test.cpp
---
