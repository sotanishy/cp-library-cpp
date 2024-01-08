---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Integer Square Root
    links: []
  bundledCode: "#line 2 \"math/number-theory/isqrt.hpp\"\n\n/**\n * @brief Integer\
    \ Square Root\n */\nunsigned long long isqrt(unsigned long long n) {\n    unsigned\
    \ long long x0 = n / 2;\n    if (x0 == 0) return n;\n    unsigned long long x1\
    \ = (x0 + n / x0) / 2;\n    while (x1 < x0) {\n        x0 = x1;\n        x1 =\
    \ (x0 + n / x0) / 2;\n    }\n    return x0;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Integer Square Root\n */\nunsigned long long\
    \ isqrt(unsigned long long n) {\n    unsigned long long x0 = n / 2;\n    if (x0\
    \ == 0) return n;\n    unsigned long long x1 = (x0 + n / x0) / 2;\n    while (x1\
    \ < x0) {\n        x0 = x1;\n        x1 = (x0 + n / x0) / 2;\n    }\n    return\
    \ x0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/isqrt.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/isqrt.hpp
layout: document
redirect_from:
- /library/math/number-theory/isqrt.hpp
- /library/math/number-theory/isqrt.hpp.html
title: Integer Square Root
---
