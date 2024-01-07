---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Minimize Periodic Function
    links:
    - https://twitter.com/maspy_stars/status/1502589106039123970
    - https://twitter.com/noshi91/status/1477671298998616065
  bundledCode: "#line 2 \"misc/min_periodic_function.hpp\"\n#include <utility>\n\n\
    /**\n * @brief Minimize Periodic Function\n * @see https://twitter.com/maspy_stars/status/1502589106039123970\n\
    \ * @see https://twitter.com/noshi91/status/1477671298998616065\n */\ntemplate\
    \ <typename T, typename F>\nT minimize_periodic_function(int n, F f) {\n    int\
    \ a = 0, b = n, c = 2 * n;\n    while (c - a > 2) {\n        int l = (a + b) /\
    \ 2, r = (b + c + 1) / 2;\n        if (f(l) < f(b))\n            std::tie(c, b)\
    \ = std::make_pair(b, l);\n        else if (f(b) > f(r))\n            std::tie(a,\
    \ b) = std::make_pair(b, r);\n        else\n            std::tie(a, c) = std::make_pair(l,\
    \ r);\n    }\n    return f(b);\n}\n"
  code: "#pragma once\n#include <utility>\n\n/**\n * @brief Minimize Periodic Function\n\
    \ * @see https://twitter.com/maspy_stars/status/1502589106039123970\n * @see https://twitter.com/noshi91/status/1477671298998616065\n\
    \ */\ntemplate <typename T, typename F>\nT minimize_periodic_function(int n, F\
    \ f) {\n    int a = 0, b = n, c = 2 * n;\n    while (c - a > 2) {\n        int\
    \ l = (a + b) / 2, r = (b + c + 1) / 2;\n        if (f(l) < f(b))\n          \
    \  std::tie(c, b) = std::make_pair(b, l);\n        else if (f(b) > f(r))\n   \
    \         std::tie(a, b) = std::make_pair(b, r);\n        else\n            std::tie(a,\
    \ c) = std::make_pair(l, r);\n    }\n    return f(b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/min_periodic_function.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/min_periodic_function.hpp
layout: document
redirect_from:
- /library/misc/min_periodic_function.hpp
- /library/misc/min_periodic_function.hpp.html
title: Minimize Periodic Function
---
