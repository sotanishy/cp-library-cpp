---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/enumerate_runs.hpp
    title: Enumerate Runs
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/runenumerate.test.cpp
    title: test/yosupo/runenumerate.test.cpp
  - icon: ':x:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/z_array.hpp\"\n#include <string>\n#include <vector>\n\
    \nstd::vector<int> z_array(const std::string& s) {\n    const int n = s.size();\n\
    \    std::vector<int> z(n);\n    z[0] = n;\n    int l = 0, r = 0;\n    for (int\
    \ i = 1; i < n; ++i) {\n        int k = i - l;\n        if (i <= r && z[k] < r\
    \ - i + 1) {\n            z[i] = z[k];\n        } else {\n            l = i;\n\
    \            if (i > r) r = i;\n            while (r < n && s[r - l] == s[r])\
    \ ++r;\n            --r;\n            z[i] = r - l + 1;\n        }\n    }\n  \
    \  return z;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\nstd::vector<int> z_array(const\
    \ std::string& s) {\n    const int n = s.size();\n    std::vector<int> z(n);\n\
    \    z[0] = n;\n    int l = 0, r = 0;\n    for (int i = 1; i < n; ++i) {\n   \
    \     int k = i - l;\n        if (i <= r && z[k] < r - i + 1) {\n            z[i]\
    \ = z[k];\n        } else {\n            l = i;\n            if (i > r) r = i;\n\
    \            while (r < n && s[r - l] == s[r]) ++r;\n            --r;\n      \
    \      z[i] = r - l + 1;\n        }\n    }\n    return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_array.hpp
  requiredBy:
  - string/enumerate_runs.hpp
  timestamp: '2024-01-07 22:05:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/runenumerate.test.cpp
  - test/yosupo/zalgorithm.test.cpp
documentation_of: string/z_array.hpp
layout: document
redirect_from:
- /library/string/z_array.hpp
- /library/string/z_array.hpp.html
title: string/z_array.hpp
---
