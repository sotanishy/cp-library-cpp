---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/manacher.cpp\"\n#include <bits/stdc++.h>\n\nstd::vector<int>\
    \ manacher(const std::string& s) {\n    int n = s.size();\n    std::vector<int>\
    \ vs(n);\n    int i = 0, j = 0;\n    while (i < n) {\n        while (0 <= i -\
    \ j && i + j < n && s[i - j] == s[i + j]) ++j;\n        vs[i] = j;\n        int\
    \ k = 1;\n        while (0 <= i - k && i + k < n && k + vs[i - k] < j) {\n   \
    \         vs[i + k] = vs[i - k];\n            ++k;\n        }\n        i += k;\n\
    \        j -= k;\n    }\n    return vs;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\nstd::vector<int> manacher(const\
    \ std::string& s) {\n    int n = s.size();\n    std::vector<int> vs(n);\n    int\
    \ i = 0, j = 0;\n    while (i < n) {\n        while (0 <= i - j && i + j < n &&\
    \ s[i - j] == s[i + j]) ++j;\n        vs[i] = j;\n        int k = 1;\n       \
    \ while (0 <= i - k && i + k < n && k + vs[i - k] < j) {\n            vs[i + k]\
    \ = vs[i - k];\n            ++k;\n        }\n        i += k;\n        j -= k;\n\
    \    }\n    return vs;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.cpp
  requiredBy: []
  timestamp: '2020-10-01 22:29:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.cpp
layout: document
redirect_from:
- /library/string/manacher.cpp
- /library/string/manacher.cpp.html
title: string/manacher.cpp
---
