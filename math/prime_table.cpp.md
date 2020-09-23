---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/prime_table.md
    document_title: Prime Table
    links: []
  bundledCode: "#line 1 \"math/prime_table.cpp\"\n#include <bits/stdc++.h>\n\n/*\n\
    \ * @brief Prime Table\n * @docs docs/math/prime_table.md\n */\nstd::vector<bool>\
    \ prime_table(int n) {\n    std::vector<bool> prime(n + 1, true);\n    prime[0]\
    \ = prime[1] = false;\n    for (int j = 4; j <= n; j += 2) prime[j] = false;\n\
    \    for (int i = 3; i * i <= n; i += 2) {\n        if (!prime[i]) continue;\n\
    \        for (int j = i * i; j <= n; j += 2 * i) prime[j] = false;\n    }\n  \
    \  return prime;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Prime Table\n * @docs docs/math/prime_table.md\n\
    \ */\nstd::vector<bool> prime_table(int n) {\n    std::vector<bool> prime(n +\
    \ 1, true);\n    prime[0] = prime[1] = false;\n    for (int j = 4; j <= n; j +=\
    \ 2) prime[j] = false;\n    for (int i = 3; i * i <= n; i += 2) {\n        if\
    \ (!prime[i]) continue;\n        for (int j = i * i; j <= n; j += 2 * i) prime[j]\
    \ = false;\n    }\n    return prime;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_table.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:09:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime_table.cpp
layout: document
redirect_from:
- /library/math/prime_table.cpp
- /library/math/prime_table.cpp.html
title: Prime Table
---
# Prime Table

エラトステネスの篩を用いて，$n$ 以下の整数の素数表を構築する．

- `vector<bool> prime_table(int n)`
    - $n$ 以下の整数の素数表を構築する
    - 時間計算量: $O(n\ln\ln n)