---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/divisor.md
    document_title: Divisors
    links: []
  bundledCode: "#line 1 \"math/divisor.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Divisors\n * @docs docs/math/divisor.md\n */\nstd::vector<long long> divisor(long\
    \ long n) {\n    std::vector<long long> ret1, ret2;\n    for (long long i = 1;\
    \ i * i <= n; i++) {\n        if (i * i == n) {\n            ret1.push_back(i);\n\
    \        } else if (n % i == 0) {\n            ret1.push_back(i);\n          \
    \  ret2.push_back(n / i);\n        }\n    }\n    ret1.insert(ret1.end(), ret2.rbegin(),\
    \ ret2.rend());\n    return ret1;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Divisors\n * @docs docs/math/divisor.md\n\
    \ */\nstd::vector<long long> divisor(long long n) {\n    std::vector<long long>\
    \ ret1, ret2;\n    for (long long i = 1; i * i <= n; i++) {\n        if (i * i\
    \ == n) {\n            ret1.push_back(i);\n        } else if (n % i == 0) {\n\
    \            ret1.push_back(i);\n            ret2.push_back(n / i);\n        }\n\
    \    }\n    ret1.insert(ret1.end(), ret2.rbegin(), ret2.rend());\n    return ret1;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/divisor.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisor.cpp
layout: document
redirect_from:
- /library/math/divisor.cpp
- /library/math/divisor.cpp.html
title: Divisors
---
# Divisor

$n$ の約数を試し割り法で全て求める．

- `vector<long long> divisor(long long n)`
    - $n$ の約数を昇順で返す
    - 時間計算量: $O(\sqrt{n})$