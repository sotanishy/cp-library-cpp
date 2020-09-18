---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C.is_prime.test.cpp
    title: test/aoj/ALDS1_1_C.is_prime.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/is_prime.md
    document_title: Primality Test
    links: []
  bundledCode: "#line 1 \"math/is_prime.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/*\n * @brief Primality Test\n * @docs docs/math/is_prime.md\n */\n\
    bool is_prime(long long n) {\n    if (n <= 1) return false;\n    if (n <= 3) return\
    \ true;\n    if (n % 2 == 0 || n % 3 == 0) return false;\n    if (n < 9) return\
    \ true;\n    for (long long i = 5; i * i <= n; i += 6) {\n        if (n % i ==\
    \ 0 || n % (i + 2) == 0) return false;\n    }\n    return true;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Primality\
    \ Test\n * @docs docs/math/is_prime.md\n */\nbool is_prime(long long n) {\n  \
    \  if (n <= 1) return false;\n    if (n <= 3) return true;\n    if (n % 2 == 0\
    \ || n % 3 == 0) return false;\n    if (n < 9) return true;\n    for (long long\
    \ i = 5; i * i <= n; i += 6) {\n        if (n % i == 0 || n % (i + 2) == 0) return\
    \ false;\n    }\n    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.cpp
  requiredBy: []
  timestamp: '2020-09-18 16:59:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_1_C.is_prime.test.cpp
documentation_of: math/is_prime.cpp
layout: document
redirect_from:
- /library/math/is_prime.cpp
- /library/math/is_prime.cpp.html
title: Primality Test
---
# Primality Test

$n$ を試し割り法で素数判定する．

- `bool is_prime(long long n)`
    - $n$ を素数判定する
    - 時間計算量: $O(\sqrt{n})$