---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_floor_of_linear.test.cpp
    title: test/yosupo/sum_of_floor_of_linear.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/floor_sum.md
    document_title: Floor Sum
    links: []
  bundledCode: "#line 1 \"math/floor_sum.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/*\n * @brief Floor Sum\n * @docs docs/math/floor_sum.md\n */\nlong\
    \ long floor_sum(long long n, long long m, long long a, long long b) {\n    long\
    \ long sum = 0;\n    if (a >= m) {\n        sum += (a / m) * n * (n - 1) / 2;\n\
    \        a %= m;\n    }\n    if (b >= m) {\n        sum += (b / m) * n;\n    \
    \    b %= m;\n    }\n    long long y = (a * n + b) / m;\n    if (y == 0) return\
    \ sum;\n    long long x = (m * y - b + a - 1) / a;\n    sum += (n - x) * y + floor_sum(y,\
    \ a, m, a * x - m * y + b);\n    return sum;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Floor Sum\n\
    \ * @docs docs/math/floor_sum.md\n */\nlong long floor_sum(long long n, long long\
    \ m, long long a, long long b) {\n    long long sum = 0;\n    if (a >= m) {\n\
    \        sum += (a / m) * n * (n - 1) / 2;\n        a %= m;\n    }\n    if (b\
    \ >= m) {\n        sum += (b / m) * n;\n        b %= m;\n    }\n    long long\
    \ y = (a * n + b) / m;\n    if (y == 0) return sum;\n    long long x = (m * y\
    \ - b + a - 1) / a;\n    sum += (n - x) * y + floor_sum(y, a, m, a * x - m * y\
    \ + b);\n    return sum;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_sum.cpp
  requiredBy: []
  timestamp: '2020-09-18 16:59:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sum_of_floor_of_linear.test.cpp
documentation_of: math/floor_sum.cpp
layout: document
redirect_from:
- /library/math/floor_sum.cpp
- /library/math/floor_sum.cpp.html
title: Floor Sum
---
# Floor Sum

一次関数の床関数の和
$$
\sum_{i=0}^{N-1} \left\lfloor \frac{A*i + B}{M} \right\rfloor
$$
を再帰的に計算する．

計算量はユークリッドの互除法と同様に対数時間となるが，どの変数に依存するのかは考えていないのでよくわからない(考えろ)．

- `long long floor_sum(long long n, long long m, long long a, long long b)`