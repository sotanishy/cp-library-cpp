---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_quotients.test.cpp
    title: test/yosupo/enumerate_quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Intervals with Equal Quotients
    links: []
  bundledCode: "#line 2 \"math/number-theory/quotients.hpp\"\n#include <vector>\n\n\
    /**\n * @brief Intervals with Equal Quotients\n */\ntemplate <typename T>\nstd::vector<std::pair<T,\
    \ T>> quotient_ranges(T n) {\n    std::vector<std::pair<T, T>> ret;\n    T i =\
    \ 1;\n    while (i <= n) {\n        T q = n / i;\n        T j = n / q + 1;\n \
    \       ret.emplace_back(i, j);\n        i = j;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief Intervals with Equal Quotients\n\
    \ */\ntemplate <typename T>\nstd::vector<std::pair<T, T>> quotient_ranges(T n)\
    \ {\n    std::vector<std::pair<T, T>> ret;\n    T i = 1;\n    while (i <= n) {\n\
    \        T q = n / i;\n        T j = n / q + 1;\n        ret.emplace_back(i, j);\n\
    \        i = j;\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/quotients.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_quotients.test.cpp
documentation_of: math/number-theory/quotients.hpp
layout: document
redirect_from:
- /library/math/number-theory/quotients.hpp
- /library/math/number-theory/quotients.hpp.html
title: Intervals with Equal Quotients
---
