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
  bundledCode: "#line 1 \"math/sieve.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nvector<bool> sieve(int n) {\n    vector<bool> prime(n + 1, true);\n\
    \    prime[0] = prime[1] = false;\n    for (int j = 4; j <= n; j += 2) prime[j]\
    \ = false;\n    for (int i = 3; i <= n; i += 2) {\n        if (!prime[i]) continue;\n\
    \        for (int j = i * i; j <= n; j += 2 * i) prime[j] = false;\n    }\n  \
    \  return prime;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<bool> sieve(int\
    \ n) {\n    vector<bool> prime(n + 1, true);\n    prime[0] = prime[1] = false;\n\
    \    for (int j = 4; j <= n; j += 2) prime[j] = false;\n    for (int i = 3; i\
    \ <= n; i += 2) {\n        if (!prime[i]) continue;\n        for (int j = i *\
    \ i; j <= n; j += 2 * i) prime[j] = false;\n    }\n    return prime;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/sieve.cpp
  requiredBy: []
  timestamp: '2020-08-31 09:52:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/sieve.cpp
layout: document
redirect_from:
- /library/math/sieve.cpp
- /library/math/sieve.cpp.html
title: math/sieve.cpp
---
