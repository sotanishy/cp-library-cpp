---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/linalg/hafnian.hpp
    title: Hafnian
  - icon: ':heavy_check_mark:'
    path: math/set/and_or_convolution.hpp
    title: Bitwise AND/OR Convolution
  - icon: ':heavy_check_mark:'
    path: math/set/set_power_series.hpp
    title: Set Power Series
  - icon: ':question:'
    path: math/set/subset_convolution.hpp
    title: Subset Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_set_power_series.test.cpp
    title: test/yosupo/exp_of_set_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo/subset_convolution.test.cpp
    title: test/yosupo/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/set/zeta_moebius_transform.hpp\"\n#include <bit>\n\
    #include <cassert>\n#include <vector>\n\ntemplate <typename T>\nvoid superset_fzt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j] += a[j | i];\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid superset_fmt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j] -= a[j | i];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid subset_fzt(std::vector<T>& a)\
    \ {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j | i] += a[j];\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid subset_fmt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j | i] -= a[j];\n   \
    \     }\n    }\n}\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <vector>\n\ntemplate\
    \ <typename T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j] += a[j | i];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid superset_fmt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j] -= a[j | i];\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid subset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j | i] += a[j];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid subset_fmt(std::vector<T>& a)\
    \ {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j | i] -= a[j];\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/set/zeta_moebius_transform.hpp
  requiredBy:
  - math/linalg/hafnian.hpp
  - math/set/set_power_series.hpp
  - math/set/subset_convolution.hpp
  - math/set/and_or_convolution.hpp
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/exp_of_set_power_series.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/subset_convolution.test.cpp
documentation_of: math/set/zeta_moebius_transform.hpp
layout: document
redirect_from:
- /library/math/set/zeta_moebius_transform.hpp
- /library/math/set/zeta_moebius_transform.hpp.html
title: math/set/zeta_moebius_transform.hpp
---
