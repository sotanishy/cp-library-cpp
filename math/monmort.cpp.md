---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Monmort Number
    links: []
  bundledCode: "#line 1 \"math/monmort.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Monmort Number\n */\ntemplate <typename T>\nT monmort(int n) {\n    if (n ==\
    \ 1) return 1;\n    if (n == 2) return 2;\n    T a = 1, b = 2, c;\n    for (int\
    \ i = 3; i <= n; ++i) {\n        c = (i - 1) * (a + b);\n        a = b;\n    \
    \    b = c;\n    }\n    return b;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Monmort Number\n */\ntemplate <typename\
    \ T>\nT monmort(int n) {\n    if (n == 1) return 1;\n    if (n == 2) return 2;\n\
    \    T a = 1, b = 2, c;\n    for (int i = 3; i <= n; ++i) {\n        c = (i -\
    \ 1) * (a + b);\n        a = b;\n        b = c;\n    }\n    return b;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/monmort.cpp
  requiredBy: []
  timestamp: '2020-10-01 22:29:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/monmort.cpp
layout: document
redirect_from:
- /library/math/monmort.cpp
- /library/math/monmort.cpp.html
title: Monmort Number
---
