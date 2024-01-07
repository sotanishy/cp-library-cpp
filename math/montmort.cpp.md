---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/montmort_number_mod.test.cpp
    title: test/yosupo/montmort_number_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Monmort Number
    links: []
  bundledCode: "#line 2 \"math/montmort.cpp\"\n#include <vector>\n\n/*\n * @brief\
    \ Monmort Number\n */\ntemplate <typename T>\nstd::vector<T> montmort_table(int\
    \ n) {\n    std::vector<T> ret(n + 1);\n    if (n == 1) return ret;\n    ret[2]\
    \ = 1;\n    for (int i = 3; i <= n; ++i) {\n        ret[i] = (ret[i - 1] + ret[i\
    \ - 2]) * (i - 1);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n\n/*\n * @brief Monmort Number\n */\ntemplate\
    \ <typename T>\nstd::vector<T> montmort_table(int n) {\n    std::vector<T> ret(n\
    \ + 1);\n    if (n == 1) return ret;\n    ret[2] = 1;\n    for (int i = 3; i <=\
    \ n; ++i) {\n        ret[i] = (ret[i - 1] + ret[i - 2]) * (i - 1);\n    }\n  \
    \  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/montmort.cpp
  requiredBy: []
  timestamp: '2022-04-28 21:35:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/montmort_number_mod.test.cpp
documentation_of: math/montmort.cpp
layout: document
redirect_from:
- /library/math/montmort.cpp
- /library/math/montmort.cpp.html
title: Monmort Number
---
