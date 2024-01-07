---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Minimum Cyclic Shift
    links: []
  bundledCode: "#line 2 \"string/min_cyclic_shift.hpp\"\n#include <string>\n#include\
    \ <vector>\n\n/**\n * @brief Minimum Cyclic Shift\n */\n\ntemplate <typename T>\n\
    std::vector<T> min_cyclic_shift(const std::vector<T>& s) {\n    const int n =\
    \ s.size();\n    auto ss = s;\n    ss.insert(ss.end(), s.begin(), s.end());\n\
    \    int i = 0, ans = 0;\n    while (i < n) {\n        ans = i;\n        int j\
    \ = i + 1, k = i;\n        while (j < 2 * n && ss[k] <= ss[j]) {\n           \
    \ if (ss[k] < ss[j])\n                k = i;\n            else\n             \
    \   k++;\n            j++;\n        }\n        while (i <= k) i += j - k;\n  \
    \  }\n    return std::vector<T>(ss.begin() + ans, ss.begin() + ans + n);\n}\n\n\
    std::string min_cyclic_shift(const std::string& s) {\n    auto res = min_cyclic_shift(std::vector<char>(s.begin(),\
    \ s.end()));\n    return std::string(res.begin(), res.end());\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\n/**\n * @brief Minimum\
    \ Cyclic Shift\n */\n\ntemplate <typename T>\nstd::vector<T> min_cyclic_shift(const\
    \ std::vector<T>& s) {\n    const int n = s.size();\n    auto ss = s;\n    ss.insert(ss.end(),\
    \ s.begin(), s.end());\n    int i = 0, ans = 0;\n    while (i < n) {\n       \
    \ ans = i;\n        int j = i + 1, k = i;\n        while (j < 2 * n && ss[k] <=\
    \ ss[j]) {\n            if (ss[k] < ss[j])\n                k = i;\n         \
    \   else\n                k++;\n            j++;\n        }\n        while (i\
    \ <= k) i += j - k;\n    }\n    return std::vector<T>(ss.begin() + ans, ss.begin()\
    \ + ans + n);\n}\n\nstd::string min_cyclic_shift(const std::string& s) {\n   \
    \ auto res = min_cyclic_shift(std::vector<char>(s.begin(), s.end()));\n    return\
    \ std::string(res.begin(), res.end());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/min_cyclic_shift.hpp
  requiredBy: []
  timestamp: '2024-01-07 22:05:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/min_cyclic_shift.hpp
layout: document
redirect_from:
- /library/string/min_cyclic_shift.hpp
- /library/string/min_cyclic_shift.hpp.html
title: Minimum Cyclic Shift
---
