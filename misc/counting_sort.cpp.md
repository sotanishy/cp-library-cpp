---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"misc/counting_sort.cpp\"\n#include <bits/stdc++.h>\n\nstd::vector<int>\
    \ counting_sort(const std::vector<int>& v, int k) {\n    std::vector<int> cnt(k+1);\n\
    \    for (int i = 0; i < (int) v.size(); i++) cnt[v[i]]++;\n    for (int i = 1;\
    \ i <= k; i++) cnt[i] += cnt[i-1];\n    std::vector<int> ret(v.size());\n    for\
    \ (int i = v.size() - 1; i >= 0; i--) ret[--cnt[v[i]]] = v[i];\n    return ret;\n\
    }\n"
  code: "#include <bits/stdc++.h>\n\nstd::vector<int> counting_sort(const std::vector<int>&\
    \ v, int k) {\n    std::vector<int> cnt(k+1);\n    for (int i = 0; i < (int) v.size();\
    \ i++) cnt[v[i]]++;\n    for (int i = 1; i <= k; i++) cnt[i] += cnt[i-1];\n  \
    \  std::vector<int> ret(v.size());\n    for (int i = v.size() - 1; i >= 0; i--)\
    \ ret[--cnt[v[i]]] = v[i];\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/counting_sort.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/counting_sort.cpp
layout: document
redirect_from:
- /library/misc/counting_sort.cpp
- /library/misc/counting_sort.cpp.html
title: misc/counting_sort.cpp
---
