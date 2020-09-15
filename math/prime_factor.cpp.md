---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_A.test.cpp
    title: test/aoj/NTL_1_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/prime_factor.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nmap<long long, int> prime_factor(long long n) {\n    map<long\
    \ long, int> ret;\n    if (n % 2 == 0) {\n        int cnt = 0;\n        while\
    \ (n % 2 == 0) {\n            cnt++;\n            n /= 2;\n        }\n       \
    \ ret[2] = cnt;\n    }\n    for (long long i = 3; i * i <= n; i += 2) {\n    \
    \    if (n % i == 0) {\n            int cnt = 0;\n            while (n % i ==\
    \ 0) {\n                cnt++;\n                n /= i;\n            }\n     \
    \       ret[i] = cnt;\n        }\n    }\n    if (n != 1) ret[n] = 1;\n    return\
    \ ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nmap<long long, int> prime_factor(long\
    \ long n) {\n    map<long long, int> ret;\n    if (n % 2 == 0) {\n        int\
    \ cnt = 0;\n        while (n % 2 == 0) {\n            cnt++;\n            n /=\
    \ 2;\n        }\n        ret[2] = cnt;\n    }\n    for (long long i = 3; i * i\
    \ <= n; i += 2) {\n        if (n % i == 0) {\n            int cnt = 0;\n     \
    \       while (n % i == 0) {\n                cnt++;\n                n /= i;\n\
    \            }\n            ret[i] = cnt;\n        }\n    }\n    if (n != 1) ret[n]\
    \ = 1;\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_factor.cpp
  requiredBy: []
  timestamp: '2020-08-31 09:52:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_A.test.cpp
documentation_of: math/prime_factor.cpp
layout: document
redirect_from:
- /library/math/prime_factor.cpp
- /library/math/prime_factor.cpp.html
title: math/prime_factor.cpp
---
