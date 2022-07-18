---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1208.test.cpp
    title: test/aoj/1208.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/stern_brocot_tree.hpp\"\n#include <utility>\n\ntemplate\
    \ <typename F>\nstd::pair<std::pair<long long, long long>, std::pair<long long,\
    \ long long>> stern_brocot_tree(long long n, F cond) {\n    long long a = 0, b\
    \ = 1, c = 1, d = 0;\n    while (true) {\n        long long num = a + c, den =\
    \ b + d;\n        if (num > n || den > n) break;\n        if (cond(num, den))\
    \ {\n            a = num, b = den;\n        } else {\n            c = num, d =\
    \ den;\n        }\n    }\n    return {{a, b}, {c, d}};\n}\n"
  code: "#pragma once\n#include <utility>\n\ntemplate <typename F>\nstd::pair<std::pair<long\
    \ long, long long>, std::pair<long long, long long>> stern_brocot_tree(long long\
    \ n, F cond) {\n    long long a = 0, b = 1, c = 1, d = 0;\n    while (true) {\n\
    \        long long num = a + c, den = b + d;\n        if (num > n || den > n)\
    \ break;\n        if (cond(num, den)) {\n            a = num, b = den;\n     \
    \   } else {\n            c = num, d = den;\n        }\n    }\n    return {{a,\
    \ b}, {c, d}};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/stern_brocot_tree.hpp
  requiredBy: []
  timestamp: '2022-07-18 21:37:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1208.test.cpp
documentation_of: math/stern_brocot_tree.hpp
layout: document
redirect_from:
- /library/math/stern_brocot_tree.hpp
- /library/math/stern_brocot_tree.hpp.html
title: math/stern_brocot_tree.hpp
---
