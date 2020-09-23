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
  bundledCode: "#line 1 \"misc/random.cpp\"\n#include <bits/stdc++.h>\n\nclass Random\
    \ {\npublic:\n    // returns a random integer in the range [0, n)\n    unsigned\
    \ int next_int(int n) {\n        return xorshift() % n;\n    }\n\n    // returns\
    \ a random double number in the range [0, 1)\n    double next_double() {\n   \
    \     return xorshift() * (1.0 / 0xFFFFFFFFu);\n    }\n\nprivate:\n    unsigned\
    \ int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\n    unsigned\
    \ int xorshift() {\n        unsigned int t;\n        t = x ^ (x << 11);\n    \
    \    x = y; y = z; z = w;\n        return w = w ^ (w >> 19) ^ (t ^ (t >> 8));\n\
    \    }\n};\n"
  code: "#include <bits/stdc++.h>\n\nclass Random {\npublic:\n    // returns a random\
    \ integer in the range [0, n)\n    unsigned int next_int(int n) {\n        return\
    \ xorshift() % n;\n    }\n\n    // returns a random double number in the range\
    \ [0, 1)\n    double next_double() {\n        return xorshift() * (1.0 / 0xFFFFFFFFu);\n\
    \    }\n\nprivate:\n    unsigned int x = 123456789, y = 362436069, z = 521288629,\
    \ w = 88675123;\n\n    unsigned int xorshift() {\n        unsigned int t;\n  \
    \      t = x ^ (x << 11);\n        x = y; y = z; z = w;\n        return w = w\
    \ ^ (w >> 19) ^ (t ^ (t >> 8));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/random.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:09:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/random.cpp
layout: document
redirect_from:
- /library/misc/random.cpp
- /library/misc/random.cpp.html
title: misc/random.cpp
---
