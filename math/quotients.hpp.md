---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Quotient Ranges
    links: []
  bundledCode: "#line 2 \"math/quotients.hpp\"\n#include <vector>\n\n/**\n * @brief\
    \ Quotient Ranges\n */\ntemplate <typename T>\nstd::vector<std::pair<T, T>> quotient_ranges(T\
    \ n) {\n    std::vector<std::pair<T, T>> ret;\n    T i = 1;\n    while (i <= n)\
    \ {\n        T q = n / i;\n        T j = n / q + 1;\n        ret.emplace_back(i,\
    \ j);\n        i = j;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief Quotient Ranges\n */\n\
    template <typename T>\nstd::vector<std::pair<T, T>> quotient_ranges(T n) {\n \
    \   std::vector<std::pair<T, T>> ret;\n    T i = 1;\n    while (i <= n) {\n  \
    \      T q = n / i;\n        T j = n / q + 1;\n        ret.emplace_back(i, j);\n\
    \        i = j;\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/quotients.hpp
  requiredBy: []
  timestamp: '2022-03-24 12:27:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/quotients.hpp
layout: document
redirect_from:
- /library/math/quotients.hpp
- /library/math/quotients.hpp.html
title: Quotient Ranges
---
