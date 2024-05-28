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
  bundledCode: "#line 2 \"misc/golden_section_search.hpp\"\n#include <numbers>\n\n\
    /**\n * @brief Golden-Section Search\n */\ntemplate <typename F>\ndouble golden_section_search(F\
    \ f, double lb, double ub, int iter = 100) {\n    constexpr auto phi = std::numbers::phi;\n\
    \    double m1 = ub - (ub - lb) / phi;\n    double m2 = lb + (ub - lb) / phi;\n\
    \    auto v1 = f(m1), v2 = f(m2);\n    for (int i = 0; i < iter; ++i) {\n    \
    \    if (v1 < v2) {\n            ub = m2;\n            m2 = m1;\n            v2\
    \ = v1;\n            m1 = ub - (ub - lb) / phi;\n            v1 = f(m1);\n   \
    \     } else {\n            lb = m1;\n            m1 = m2;\n            v1 = v2;\n\
    \            m2 = lb + (ub - lb) / phi;\n            v2 = f(m2);\n        }\n\
    \    }\n    return lb;\n}\n\n// [lb, ub] (inclusive)\ntemplate <typename F>\n\
    long long golden_section_search(F f, long long lb, long long ub) {\n    // t-s,\
    \ s, t are consecutive fibonacci numbers\n    long long s = 1, t = 2;\n    while\
    \ (t < ub - lb + 2) std::swap(s += t, t);\n    long long l = lb - 1, m1 = l +\
    \ t - s, m2 = l + s;\n    auto v1 = f(m1), v2 = f(m2);\n    while (m1 != m2) {\n\
    \        std::swap(s, t -= s);\n        if (ub < m2 || v1 <= v2) {\n         \
    \   m2 = m1;\n            v2 = v1;\n            m1 = l + t - s;\n            v1\
    \ = f(m1);\n        } else {\n            l = m1;\n            m1 = m2;\n    \
    \        v1 = v2;\n            m2 = l + s;\n            v2 = m2 <= ub ? f(m2)\
    \ : v1;\n        }\n    }\n    return m1;\n}\n"
  code: "#pragma once\n#include <numbers>\n\n/**\n * @brief Golden-Section Search\n\
    \ */\ntemplate <typename F>\ndouble golden_section_search(F f, double lb, double\
    \ ub, int iter = 100) {\n    constexpr auto phi = std::numbers::phi;\n    double\
    \ m1 = ub - (ub - lb) / phi;\n    double m2 = lb + (ub - lb) / phi;\n    auto\
    \ v1 = f(m1), v2 = f(m2);\n    for (int i = 0; i < iter; ++i) {\n        if (v1\
    \ < v2) {\n            ub = m2;\n            m2 = m1;\n            v2 = v1;\n\
    \            m1 = ub - (ub - lb) / phi;\n            v1 = f(m1);\n        } else\
    \ {\n            lb = m1;\n            m1 = m2;\n            v1 = v2;\n      \
    \      m2 = lb + (ub - lb) / phi;\n            v2 = f(m2);\n        }\n    }\n\
    \    return lb;\n}\n\n// [lb, ub] (inclusive)\ntemplate <typename F>\nlong long\
    \ golden_section_search(F f, long long lb, long long ub) {\n    // t-s, s, t are\
    \ consecutive fibonacci numbers\n    long long s = 1, t = 2;\n    while (t < ub\
    \ - lb + 2) std::swap(s += t, t);\n    long long l = lb - 1, m1 = l + t - s, m2\
    \ = l + s;\n    auto v1 = f(m1), v2 = f(m2);\n    while (m1 != m2) {\n       \
    \ std::swap(s, t -= s);\n        if (ub < m2 || v1 <= v2) {\n            m2 =\
    \ m1;\n            v2 = v1;\n            m1 = l + t - s;\n            v1 = f(m1);\n\
    \        } else {\n            l = m1;\n            m1 = m2;\n            v1 =\
    \ v2;\n            m2 = l + s;\n            v2 = m2 <= ub ? f(m2) : v1;\n    \
    \    }\n    }\n    return m1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/golden_section_search.hpp
  requiredBy: []
  timestamp: '2024-05-28 22:29:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/golden_section_search.hpp
layout: document
redirect_from:
- /library/misc/golden_section_search.hpp
- /library/misc/golden_section_search.hpp.html
title: Golden-Section Search
---
