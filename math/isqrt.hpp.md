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
  bundledCode: "#line 2 \"math/isqrt.hpp\"\n\ntemplate <typename T>\nT isqrt(T n)\
    \ {\n    T x0 = n / 2;\n    if (x0 == 0) return n;\n    T x1 = (x0 + n / x0) /\
    \ 2;\n    while (x1 < x0) {\n        x0 = x1;\n        x1 = (x0 + n / x0) / 2;\n\
    \    }\n    return x0;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nT isqrt(T n) {\n    T x0 = n / 2;\n\
    \    if (x0 == 0) return n;\n    T x1 = (x0 + n / x0) / 2;\n    while (x1 < x0)\
    \ {\n        x0 = x1;\n        x1 = (x0 + n / x0) / 2;\n    }\n    return x0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/isqrt.hpp
  requiredBy: []
  timestamp: '2022-07-18 21:37:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/isqrt.hpp
layout: document
redirect_from:
- /library/math/isqrt.hpp
- /library/math/isqrt.hpp.html
title: math/isqrt.hpp
---
