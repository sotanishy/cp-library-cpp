---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Golden-Section Search
    links: []
  bundledCode: "#line 2 \"misc/golden_section_search.hpp\"\n#include <cmath>\n\n/**\n\
    \ * @brief Golden-Section Search\n*/\ntemplate <typename F>\ndouble golden_section_search(F\
    \ f, double lb, double ub, int iter = 100) {\n    constexpr double gr = (1 + std::sqrt(5))\
    \ / 2;\n    double m1 = ub - (ub - lb) / gr;\n    double m2 = lb + (ub - lb) /\
    \ gr;\n    double v1 = f(m1), v2 = f(m2);\n    for (int i = 0; i < iter; ++i)\
    \ {\n        if (v1 < v2) {\n            ub = m2;\n            m2 = m1;\n    \
    \        v2 = v1;\n            m1 = ub - (ub - lb) / gr;\n            v1 = f(m1);\n\
    \        } else {\n            lb = m1;\n            m1 = m2;\n            v1\
    \ = v2;\n            m2 = lb + (ub - lb) / gr;\n            v2 = f(m2);\n    \
    \    }\n    }\n    return lb;\n}\n"
  code: "#pragma once\n#include <cmath>\n\n/**\n * @brief Golden-Section Search\n\
    */\ntemplate <typename F>\ndouble golden_section_search(F f, double lb, double\
    \ ub, int iter = 100) {\n    constexpr double gr = (1 + std::sqrt(5)) / 2;\n \
    \   double m1 = ub - (ub - lb) / gr;\n    double m2 = lb + (ub - lb) / gr;\n \
    \   double v1 = f(m1), v2 = f(m2);\n    for (int i = 0; i < iter; ++i) {\n   \
    \     if (v1 < v2) {\n            ub = m2;\n            m2 = m1;\n           \
    \ v2 = v1;\n            m1 = ub - (ub - lb) / gr;\n            v1 = f(m1);\n \
    \       } else {\n            lb = m1;\n            m1 = m2;\n            v1 =\
    \ v2;\n            m2 = lb + (ub - lb) / gr;\n            v2 = f(m2);\n      \
    \  }\n    }\n    return lb;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/golden_section_search.hpp
  requiredBy: []
  timestamp: '2024-01-06 23:45:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/golden_section_search.hpp
layout: document
redirect_from:
- /library/misc/golden_section_search.hpp
- /library/misc/golden_section_search.hpp.html
title: Golden-Section Search
---
