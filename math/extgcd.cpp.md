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
  bundledCode: "#line 1 \"math/extgcd.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\npair<long long, long long> extgcd(long long a, long long b) {\n    long\
    \ long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;\n    while (t) {\n      \
    \  long long q = s / t;\n        s -= t * q;\n        swap(s, t);\n        sx\
    \ -= tx * q;\n        swap(sx, tx);\n        sy -= ty * q;\n        swap(sy, ty);\n\
    \    }\n    return {sx, sy};\n}\n\nlong long mod_inv(long long a, long long mod)\
    \ {\n    long long inv = extgcd(a, mod).first;\n    return (inv % mod + mod) %\
    \ mod;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\npair<long long, long long>\
    \ extgcd(long long a, long long b) {\n    long long s = a, sx = 1, sy = 0, t =\
    \ b, tx = 0, ty = 1;\n    while (t) {\n        long long q = s / t;\n        s\
    \ -= t * q;\n        swap(s, t);\n        sx -= tx * q;\n        swap(sx, tx);\n\
    \        sy -= ty * q;\n        swap(sy, ty);\n    }\n    return {sx, sy};\n}\n\
    \nlong long mod_inv(long long a, long long mod) {\n    long long inv = extgcd(a,\
    \ mod).first;\n    return (inv % mod + mod) % mod;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.cpp
  requiredBy: []
  timestamp: '2020-09-10 20:23:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/extgcd.cpp
layout: document
redirect_from:
- /library/math/extgcd.cpp
- /library/math/extgcd.cpp.html
title: math/extgcd.cpp
---
