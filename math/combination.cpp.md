---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/stirling_second.cpp
    title: Stirling Number of the Second Kind
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/combination.md
    document_title: Combination
    links: []
  bundledCode: "#line 2 \"math/combination.cpp\"\n#include <vector>\n\n/*\n * @brief\
    \ Combination\n * @docs docs/math/combination.md\n */\ntemplate <typename T>\n\
    class Combination {\npublic:\n    Combination() = default;\n    Combination(int\
    \ n) : fact(n + 1), fact_inv(n + 1) {\n        fact[0] = 1;\n        for (int\
    \ i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;\n        fact_inv[n] = T(1) /\
    \ fact[n];\n        for (int i = n; i > 0; --i) fact_inv[i - 1] = fact_inv[i]\
    \ * i;\n    }\n\n    T perm(int n, int r) const {\n        if (r < 0 || n < r)\
    \ return 0;\n        return fact[n] * fact_inv[n - r];\n    }\n\n    T comb(int\
    \ n, int r) const {\n        if (r < 0 || n < r) return 0;\n        return fact[n]\
    \ * fact_inv[r] * fact_inv[n - r];\n    }\n\nprivate:\n    std::vector<T> fact,\
    \ fact_inv;\n};\n\ntemplate <typename T>\nT comb(int n, int r) {\n    T num =\
    \ 1, den = 1;\n    for (int i = 1; i <= r; ++i) {\n        num = num * (n - i\
    \ + 1);\n        den = den * i;\n    }\n    return num / den;\n}\n"
  code: "#pragma once\n#include <vector>\n\n/*\n * @brief Combination\n * @docs docs/math/combination.md\n\
    \ */\ntemplate <typename T>\nclass Combination {\npublic:\n    Combination() =\
    \ default;\n    Combination(int n) : fact(n + 1), fact_inv(n + 1) {\n        fact[0]\
    \ = 1;\n        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;\n    \
    \    fact_inv[n] = T(1) / fact[n];\n        for (int i = n; i > 0; --i) fact_inv[i\
    \ - 1] = fact_inv[i] * i;\n    }\n\n    T perm(int n, int r) const {\n       \
    \ if (r < 0 || n < r) return 0;\n        return fact[n] * fact_inv[n - r];\n \
    \   }\n\n    T comb(int n, int r) const {\n        if (r < 0 || n < r) return\
    \ 0;\n        return fact[n] * fact_inv[r] * fact_inv[n - r];\n    }\n\nprivate:\n\
    \    std::vector<T> fact, fact_inv;\n};\n\ntemplate <typename T>\nT comb(int n,\
    \ int r) {\n    T num = 1, den = 1;\n    for (int i = 1; i <= r; ++i) {\n    \
    \    num = num * (n - i + 1);\n        den = den * i;\n    }\n    return num /\
    \ den;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/combination.cpp
  requiredBy:
  - math/stirling_second.cpp
  timestamp: '2020-10-24 23:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.cpp
layout: document
redirect_from:
- /library/math/combination.cpp
- /library/math/combination.cpp.html
title: Combination
---
## Description

組み合わせ $n \choose r$ および順列 $_n P _r$ を $\mod mod$ で計算する．これらの値を何度も計算する必要があるときは non-static メンバーを，1度でいいときは static メンバーを使用する．また，$n$ の値が配列に入らないほど大きいが $r$ の値は十分小さいときも static メンバーを使用する．

空間計算量: $O(n)$

## Operations

- `Combination(int n)`
    - $n$ 以下の整数の階乗及びその逆元を前計算する
    - 時間計算量: $O(n)$
- `static T comb(int n, int r)`
    - $n \choose r$ を計算する．
    - 時間計算量: $O(r)$
- `T perm(int n, int r)`
    - $_n P _r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$
- `T comb(int n, int r)`
    - $n \choose r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$