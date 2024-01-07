---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: set/zeta_moebius_transform.hpp
    title: "Fast Zeta/M\xF6bius Transform"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Bitwise AND/OR Convolution
    links: []
  bundledCode: "#line 2 \"set/and_or_convolution.hpp\"\n#include <bit>\n#include <vector>\n\
    \n#line 3 \"set/zeta_moebius_transform.hpp\"\n#include <cassert>\n#line 5 \"set/zeta_moebius_transform.hpp\"\
    \n\ntemplate <typename T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    int k = std::bit_width(a.size());\n    for (int i = 0; i < k; ++i) {\n  \
    \      for (int j = 0; j < (1 << k); ++j) {\n            if (!(j >> i & 1)) a[j]\
    \ += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid superset_fmt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    int k = std::bit_width(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if (!(j >> i & 1)) a[j] -= a[j ^ (1 << i)];\n        }\n    }\n\
    }\n\ntemplate <typename T>\nvoid subset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    int k = std::bit_width(a.size());\n    for (int i = 0; i < k; ++i) {\n  \
    \      for (int j = 0; j < (1 << k); ++j) {\n            if (j >> i & 1) a[j]\
    \ += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid subset_fmt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    int k = std::bit_width(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if (j >> i & 1) a[j] -= a[j ^ (1 << i)];\n        }\n    }\n\
    }\n#line 6 \"set/and_or_convolution.hpp\"\n\n/**\n * @brief Bitwise AND/OR Convolution\n\
    \ */\n\ntemplate <typename T>\nstd::vector<T> and_convolution(std::vector<T> a,\
    \ std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(), b.size()));\n\
    \    a.resize(n);\n    b.resize(n);\n    superset_fzt(a);\n    superset_fzt(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    superset_fmt(a);\n    return\
    \ a;\n}\n\ntemplate <typename T>\nstd::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(), b.size()));\n\
    \    a.resize(n);\n    b.resize(n);\n    subset_fzt(a);\n    subset_fzt(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    subset_fmt(a);\n    return\
    \ a;\n}\n"
  code: "#pragma once\n#include <bit>\n#include <vector>\n\n#include \"zeta_moebius_transform.hpp\"\
    \n\n/**\n * @brief Bitwise AND/OR Convolution\n */\n\ntemplate <typename T>\n\
    std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b) {\n    const\
    \ int n = std::bit_ceil(std::max(a.size(), b.size()));\n    a.resize(n);\n   \
    \ b.resize(n);\n    superset_fzt(a);\n    superset_fzt(b);\n    for (int i = 0;\
    \ i < n; ++i) a[i] *= b[i];\n    superset_fmt(a);\n    return a;\n}\n\ntemplate\
    \ <typename T>\nstd::vector<T> or_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    const int n = std::bit_ceil(std::max(a.size(), b.size()));\n    a.resize(n);\n\
    \    b.resize(n);\n    subset_fzt(a);\n    subset_fzt(b);\n    for (int i = 0;\
    \ i < n; ++i) a[i] *= b[i];\n    subset_fmt(a);\n    return a;\n}\n"
  dependsOn:
  - set/zeta_moebius_transform.hpp
  isVerificationFile: false
  path: set/and_or_convolution.hpp
  requiredBy: []
  timestamp: '2024-01-07 12:55:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/bitwise_and_convolution.test.cpp
documentation_of: set/and_or_convolution.hpp
layout: document
redirect_from:
- /library/set/and_or_convolution.hpp
- /library/set/and_or_convolution.hpp.html
title: Bitwise AND/OR Convolution
---
