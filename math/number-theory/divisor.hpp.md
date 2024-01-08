---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/number-theory/divisor.hpp\"\n#include <vector>\n\n\
    std::vector<long long> divisor(long long n) {\n    std::vector<long long> ret1,\
    \ ret2;\n    for (long long i = 1; i * i <= n; ++i) {\n        if (i * i == n)\
    \ {\n            ret1.push_back(i);\n        } else if (n % i == 0) {\n      \
    \      ret1.push_back(i);\n            ret2.push_back(n / i);\n        }\n   \
    \ }\n    ret1.insert(ret1.end(), ret2.rbegin(), ret2.rend());\n    return ret1;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\nstd::vector<long long> divisor(long long\
    \ n) {\n    std::vector<long long> ret1, ret2;\n    for (long long i = 1; i *\
    \ i <= n; ++i) {\n        if (i * i == n) {\n            ret1.push_back(i);\n\
    \        } else if (n % i == 0) {\n            ret1.push_back(i);\n          \
    \  ret2.push_back(n / i);\n        }\n    }\n    ret1.insert(ret1.end(), ret2.rbegin(),\
    \ ret2.rend());\n    return ret1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/divisor.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/divisor.hpp
layout: document
title: Divisor
---

## Description

$n$ の約数を試し割り法で全て求める．

## Operations

- `vector<long long> divisor(long long n)`
    - $n$ の約数を昇順で返す
    - 時間計算量: $O(\sqrt{n})$