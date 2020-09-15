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
  bundledCode: "#line 1 \"misc/slide_min.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <typename T>\nvector<T> slide_min(const vector<T>& v, int k)\
    \ {\n    vector<T> ret;\n    deque<int> dq;\n    for (int i = 0; i < v.size();\
    \ i++) {\n        while (!dq.empty() && v[dq.back()] >= v[i]) dq.pop_back();\n\
    \        dq.push_back(i);\n        if (i >= k - 1) {\n            ret.push_back(v[dq.front()]);\n\
    \            if (dq.front() == i - k + 1) dq.pop_front();\n        }\n    }\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T>\n\
    vector<T> slide_min(const vector<T>& v, int k) {\n    vector<T> ret;\n    deque<int>\
    \ dq;\n    for (int i = 0; i < v.size(); i++) {\n        while (!dq.empty() &&\
    \ v[dq.back()] >= v[i]) dq.pop_back();\n        dq.push_back(i);\n        if (i\
    \ >= k - 1) {\n            ret.push_back(v[dq.front()]);\n            if (dq.front()\
    \ == i - k + 1) dq.pop_front();\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/slide_min.cpp
  requiredBy: []
  timestamp: '2020-09-14 04:40:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/slide_min.cpp
layout: document
redirect_from:
- /library/misc/slide_min.cpp
- /library/misc/slide_min.cpp.html
title: misc/slide_min.cpp
---
