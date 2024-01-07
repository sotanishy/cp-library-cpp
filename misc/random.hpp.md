---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/random.hpp\"\n\nclass Random {\n   public:\n    //\
    \ returns a random integer in the range [0, n)\n    unsigned int next_int(int\
    \ n) { return xorshift() % n; }\n\n    // returns a random double number in the\
    \ range [0, 1)\n    double next_double() { return xorshift() * (1.0 / 0xFFFFFFFFu);\
    \ }\n\n   private:\n    unsigned int x = 123456789, y = 362436069, z = 521288629,\
    \ w = 88675123;\n\n    unsigned int xorshift() {\n        unsigned int t;\n  \
    \      t = x ^ (x << 11);\n        x = y;\n        y = z;\n        z = w;\n  \
    \      return w = w ^ (w >> 19) ^ (t ^ (t >> 8));\n    }\n};\n"
  code: "#pragma once\n\nclass Random {\n   public:\n    // returns a random integer\
    \ in the range [0, n)\n    unsigned int next_int(int n) { return xorshift() %\
    \ n; }\n\n    // returns a random double number in the range [0, 1)\n    double\
    \ next_double() { return xorshift() * (1.0 / 0xFFFFFFFFu); }\n\n   private:\n\
    \    unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n\
    \n    unsigned int xorshift() {\n        unsigned int t;\n        t = x ^ (x <<\
    \ 11);\n        x = y;\n        y = z;\n        z = w;\n        return w = w ^\
    \ (w >> 19) ^ (t ^ (t >> 8));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/random.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/random.hpp
layout: document
redirect_from:
- /library/misc/random.hpp
- /library/misc/random.hpp.html
title: misc/random.hpp
---
