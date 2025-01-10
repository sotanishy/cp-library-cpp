---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/divisor_zeta_moebius_transform.hpp
    title: "Multiple/Divisor Fast Zeta/M\xF6bius Transform"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lcm_convolution.test.cpp
    title: test/yosupo/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: GCD/LCM Convolution
    links: []
  bundledCode: "#line 2 \"convolution/gcd_lcm_convolution.hpp\"\n#include <vector>\n\
    \n#line 3 \"convolution/divisor_zeta_moebius_transform.hpp\"\n\ntemplate <typename\
    \ T>\nvoid divisor_fzt(std::vector<T>& a) {\n    const int n = a.size();\n   \
    \ std::vector<bool> sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n     \
    \   if (!sieve[p]) continue;\n        for (int k = 1; k * p < n; ++k) {\n    \
    \        sieve[k * p] = false;\n            a[k * p] += a[k];\n        }\n   \
    \ }\n}\n\ntemplate <typename T>\nvoid divisor_fmt(std::vector<T>& a) {\n    const\
    \ int n = a.size();\n    std::vector<bool> sieve(n, true);\n    for (int p = 2;\
    \ p < n; ++p) {\n        if (!sieve[p]) continue;\n        for (int k = (n - 1)\
    \ / p; k > 0; --k) {\n            sieve[k * p] = false;\n            a[k * p]\
    \ -= a[k];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid multiple_fzt(std::vector<T>&\
    \ a) {\n    const int n = a.size();\n    std::vector<bool> sieve(n, true);\n \
    \   for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n        for\
    \ (int k = (n - 1) / p; k > 0; --k) {\n            sieve[k * p] = false;\n   \
    \         a[k] += a[k * p];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ multiple_fmt(std::vector<T>& a) {\n    const int n = a.size();\n    std::vector<bool>\
    \ sieve(n, true);\n    for (int p = 2; p < n; ++p) {\n        if (!sieve[p]) continue;\n\
    \        for (int k = 1; k * p < n; ++k) {\n            sieve[k * p] = false;\n\
    \            a[k] -= a[k * p];\n        }\n    }\n}\n#line 5 \"convolution/gcd_lcm_convolution.hpp\"\
    \n\n/**\n * @brief GCD/LCM Convolution\n */\n\ntemplate <typename T>\nstd::vector<T>\
    \ gcd_convolution(std::vector<T> a, std::vector<T> b) {\n    const int n = std::max(a.size(),\
    \ b.size());\n    a.resize(n);\n    b.resize(n);\n    multiple_fzt(a);\n    multiple_fzt(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    multiple_fmt(a);\n    return\
    \ a;\n}\n\ntemplate <typename T>\nstd::vector<T> lcm_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    const int n = std::max(a.size(), b.size());\n  \
    \  a.resize(n);\n    b.resize(n);\n    divisor_fzt(a);\n    divisor_fzt(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a);\n    return\
    \ a;\n}\n"
  code: "#pragma once\n#include <vector>\n\n#include \"divisor_zeta_moebius_transform.hpp\"\
    \n\n/**\n * @brief GCD/LCM Convolution\n */\n\ntemplate <typename T>\nstd::vector<T>\
    \ gcd_convolution(std::vector<T> a, std::vector<T> b) {\n    const int n = std::max(a.size(),\
    \ b.size());\n    a.resize(n);\n    b.resize(n);\n    multiple_fzt(a);\n    multiple_fzt(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    multiple_fmt(a);\n    return\
    \ a;\n}\n\ntemplate <typename T>\nstd::vector<T> lcm_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    const int n = std::max(a.size(), b.size());\n  \
    \  a.resize(n);\n    b.resize(n);\n    divisor_fzt(a);\n    divisor_fzt(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    divisor_fmt(a);\n    return\
    \ a;\n}"
  dependsOn:
  - convolution/divisor_zeta_moebius_transform.hpp
  isVerificationFile: false
  path: convolution/gcd_lcm_convolution.hpp
  requiredBy: []
  timestamp: '2024-01-07 22:37:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lcm_convolution.test.cpp
  - test/yosupo/gcd_convolution.test.cpp
documentation_of: convolution/gcd_lcm_convolution.hpp
layout: document
redirect_from:
- /library/convolution/gcd_lcm_convolution.hpp
- /library/convolution/gcd_lcm_convolution.hpp.html
title: GCD/LCM Convolution
---
