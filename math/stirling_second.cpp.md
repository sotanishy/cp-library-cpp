---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/combination.cpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Stirling Number of the Second Kind
    links: []
  bundledCode: "#line 2 \"math/combination.cpp\"\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass Combination {\npublic:\n    Combination() = default;\n    Combination(int\
    \ n) : fact_(n + 1), fact_inv_(n + 1) {\n        fact_[0] = 1;\n        for (int\
    \ i = 1; i <= n; ++i) fact_[i] = fact_[i - 1] * i;\n        fact_inv_[n] = T(1)\
    \ / fact_[n];\n        for (int i = n; i > 0; --i) fact_inv_[i - 1] = fact_inv_[i]\
    \ * i;\n    }\n\n    T perm(int n, int r) const {\n        if (r < 0 || n < r)\
    \ return 0;\n        return fact_[n] * fact_inv_[n - r];\n    }\n\n    T comb(int\
    \ n, int r) const {\n        if (r < 0 || n < r) return 0;\n        return fact_[n]\
    \ * fact_inv_[r] * fact_inv_[n - r];\n    }\n\n    T fact(int n) const { return\
    \ fact_[n]; }\n    T fact_inv(int n) const { return fact_inv_[n]; }\n\nprivate:\n\
    \    std::vector<T> fact_, fact_inv_;\n};\n\ntemplate <typename T>\nT comb(int\
    \ n, int r) {\n    T num = 1, den = 1;\n    for (int i = 1; i <= r; ++i) {\n \
    \       num = num * (n - i + 1);\n        den = den * i;\n    }\n    return num\
    \ / den;\n}\n#line 3 \"math/stirling_second.cpp\"\n\n/*\n * @brief Stirling Number\
    \ of the Second Kind\n */\ntemplate <typename T>\nT stirling_second(int n, int\
    \ k) {\n    Combination<T> comb(n);\n    T res = 0;\n    for (int i = 0; i <=\
    \ k; ++i) {\n        T tmp = comb.comb(k, i) * T(i).pow(n);\n        if ((k -\
    \ i) & 1) res -= tmp;\n        else res += tmp;\n    }\n    for (int i = 1; i\
    \ <= k; ++i) res /= i;\n    return res;\n}\n"
  code: "#pragma once\n#include \"combination.cpp\"\n\n/*\n * @brief Stirling Number\
    \ of the Second Kind\n */\ntemplate <typename T>\nT stirling_second(int n, int\
    \ k) {\n    Combination<T> comb(n);\n    T res = 0;\n    for (int i = 0; i <=\
    \ k; ++i) {\n        T tmp = comb.comb(k, i) * T(i).pow(n);\n        if ((k -\
    \ i) & 1) res -= tmp;\n        else res += tmp;\n    }\n    for (int i = 1; i\
    \ <= k; ++i) res /= i;\n    return res;\n}"
  dependsOn:
  - math/combination.cpp
  isVerificationFile: false
  path: math/stirling_second.cpp
  requiredBy: []
  timestamp: '2021-09-08 22:33:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/stirling_second.cpp
layout: document
redirect_from:
- /library/math/stirling_second.cpp
- /library/math/stirling_second.cpp.html
title: Stirling Number of the Second Kind
---
