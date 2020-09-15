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
  bundledCode: "#line 1 \"math/floor_sum.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nlong long floor_sum(long long n, long long m, long long a, long long\
    \ b) {\n    long long sum = 0;\n    if (a >= m) {\n        sum += (a / m) * n\
    \ * (n - 1) / 2;\n        a %= m;\n    }\n    if (b >= m) {\n        sum += (b\
    \ / m) * n;\n        b %= m;\n    }\n    long long y = (a * n + b) / m;\n    if\
    \ (y == 0) return sum;\n    long long x = (m * y - b + a - 1) / a;\n    sum +=\
    \ (n - x) * y + floor_sum(y, a, m, a * x - m * y + b);\n    return sum;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nlong long floor_sum(long\
    \ long n, long long m, long long a, long long b) {\n    long long sum = 0;\n \
    \   if (a >= m) {\n        sum += (a / m) * n * (n - 1) / 2;\n        a %= m;\n\
    \    }\n    if (b >= m) {\n        sum += (b / m) * n;\n        b %= m;\n    }\n\
    \    long long y = (a * n + b) / m;\n    if (y == 0) return sum;\n    long long\
    \ x = (m * y - b + a - 1) / a;\n    sum += (n - x) * y + floor_sum(y, a, m, a\
    \ * x - m * y + b);\n    return sum;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum.cpp
  requiredBy: []
  timestamp: '2020-09-11 18:56:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor_sum.cpp
layout: document
redirect_from:
- /library/math/floor_sum.cpp
- /library/math/floor_sum.cpp.html
title: math/floor_sum.cpp
---
