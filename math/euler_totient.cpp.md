---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/euler_totient.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nlong long euler_totient(long long n) {\n    long long ret\
    \ = n;\n    if (n % 2 == 0) {\n        ret -= ret / 2;\n        while (n % 2 ==\
    \ 0) n /= 2;\n    }\n    for (long long i = 3; i * i <= n; i += 2) {\n       \
    \ if (n % i == 0) {\n            ret -= ret / i;\n            while (n % i ==\
    \ 0) n /= i;\n        }\n    }\n    if (n != 1) ret -= ret / n;\n    return ret;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nlong long euler_totient(long\
    \ long n) {\n    long long ret = n;\n    if (n % 2 == 0) {\n        ret -= ret\
    \ / 2;\n        while (n % 2 == 0) n /= 2;\n    }\n    for (long long i = 3; i\
    \ * i <= n; i += 2) {\n        if (n % i == 0) {\n            ret -= ret / i;\n\
    \            while (n % i == 0) n /= i;\n        }\n    }\n    if (n != 1) ret\
    \ -= ret / n;\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_totient.cpp
  requiredBy: []
  timestamp: '2020-08-31 09:52:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
documentation_of: math/euler_totient.cpp
layout: document
redirect_from:
- /library/math/euler_totient.cpp
- /library/math/euler_totient.cpp.html
title: math/euler_totient.cpp
---
