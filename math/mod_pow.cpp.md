---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/mod_log.cpp
    title: math/mod_log.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/mod_pow.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nlong long mod_pow(long long n, long long p, long long mod) {\n    long\
    \ long ret = 1;\n    while (p > 0) {\n        if (p & 1) ret = ret * n % mod;\n\
    \        n = n * n % mod;\n        p >>= 1;\n    }\n    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nlong long mod_pow(long\
    \ long n, long long p, long long mod) {\n    long long ret = 1;\n    while (p\
    \ > 0) {\n        if (p & 1) ret = ret * n % mod;\n        n = n * n % mod;\n\
    \        p >>= 1;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/mod_pow.cpp
  requiredBy:
  - math/mod_log.cpp
  timestamp: '2020-09-10 20:23:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_B.test.cpp
documentation_of: math/mod_pow.cpp
layout: document
redirect_from:
- /library/math/mod_pow.cpp
- /library/math/mod_pow.cpp.html
title: math/mod_pow.cpp
---
