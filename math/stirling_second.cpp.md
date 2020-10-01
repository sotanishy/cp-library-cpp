---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/combination.cpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Stirling Number of the Second Kind
    links: []
  bundledCode: "#line 2 \"math/stirling_second.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"math/combination.cpp\"\n\n/*\n * @brief Combination\n * @docs docs/math/combination.md\n\
    \ */\ntemplate <typename T>\nclass Combination {\n    static T comb(int n, int\
    \ r) {\n        T num = 1, den = 1;\n        for (int i = 1; i <= r; ++i) {\n\
    \            num = num * (n - i + 1);\n            den = den * i;\n        }\n\
    \        return num / den;\n    }\n\n    Combination() = default;\n    Combination(int\
    \ n) : fact(n + 1), fact_inv(n + 1) {\n        fact[0] = 1;\n        for (int\
    \ i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;\n        fact_inv[n] = 1 / fact[n];\n\
    \        for (int i = n; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\n    }\n\
    \n    T fact(int n) const {\n        return fact[n];\n    }\n\n    T fact_inv(int\
    \ n) const {\n        return fact_inv[n];\n    }\n\n    T perm(int n, int r) const\
    \ {\n        if (r < 0 || n < r) return 0;\n        return fact[n] * fact_inv[n\
    \ - r];\n    }\n\n    T comb(int n, int r) const {\n        if (r < 0 || n < r)\
    \ return 0;\n        return fact[n] * fact_inv[r] * fact_inv[n - r];\n    }\n\n\
    private:\n    std::vector<T> fact, fact_inv;\n};\n#line 4 \"math/stirling_second.cpp\"\
    \n\n/*\n * @brief Stirling Number of the Second Kind\n */\ntemplate <typename\
    \ T>\nT stirling_second(int n, int k) {\n    Combination<T> comb(n);\n    T res\
    \ = 0;\n    for (int i = 0; i <= k; ++i) {\n        T tmp = comb.comb(k, i) *\
    \ T(i).pow(n);\n        if ((k - i) & 1) res -= tmp;\n        else res += tmp;\n\
    \    }\n    for (int i = 1; i <= k; ++i) res /= i;\n    return res;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include \"combination.cpp\"\n\n\
    /*\n * @brief Stirling Number of the Second Kind\n */\ntemplate <typename T>\n\
    T stirling_second(int n, int k) {\n    Combination<T> comb(n);\n    T res = 0;\n\
    \    for (int i = 0; i <= k; ++i) {\n        T tmp = comb.comb(k, i) * T(i).pow(n);\n\
    \        if ((k - i) & 1) res -= tmp;\n        else res += tmp;\n    }\n    for\
    \ (int i = 1; i <= k; ++i) res /= i;\n    return res;\n}"
  dependsOn:
  - math/combination.cpp
  isVerificationFile: false
  path: math/stirling_second.cpp
  requiredBy: []
  timestamp: '2020-10-01 22:29:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/stirling_second.cpp
layout: document
redirect_from:
- /library/math/stirling_second.cpp
- /library/math/stirling_second.cpp.html
title: Stirling Number of the Second Kind
---
