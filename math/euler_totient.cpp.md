---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/euler_totient.cpp\"\n#include <numeric>\n#include <vector>\n\
    \nlong long euler_totient(long long n) {\n    long long ret = n;\n    if (n %\
    \ 2 == 0) {\n        ret -= ret / 2;\n        while (n % 2 == 0) n /= 2;\n   \
    \ }\n    for (long long i = 3; i * i <= n; i += 2) {\n        if (n % i == 0)\
    \ {\n            ret -= ret / i;\n            while (n % i == 0) n /= i;\n   \
    \     }\n    }\n    if (n != 1) ret -= ret / n;\n    return ret;\n}\n\nstd::vector<int>\
    \ euler_totient_table(int n) {\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(),\
    \ ret.end(), 0);\n    for (int i = 2; i <= n; ++i) {\n        if (ret[i] == i)\
    \ {\n            for (int j = i; j <= n; j += i) {\n                ret[j] = ret[j]\
    \ / i * (i - 1);\n            }\n        }\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n\nlong long euler_totient(long\
    \ long n) {\n    long long ret = n;\n    if (n % 2 == 0) {\n        ret -= ret\
    \ / 2;\n        while (n % 2 == 0) n /= 2;\n    }\n    for (long long i = 3; i\
    \ * i <= n; i += 2) {\n        if (n % i == 0) {\n            ret -= ret / i;\n\
    \            while (n % i == 0) n /= i;\n        }\n    }\n    if (n != 1) ret\
    \ -= ret / n;\n    return ret;\n}\n\nstd::vector<int> euler_totient_table(int\
    \ n) {\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(), ret.end(),\
    \ 0);\n    for (int i = 2; i <= n; ++i) {\n        if (ret[i] == i) {\n      \
    \      for (int j = i; j <= n; j += i) {\n                ret[j] = ret[j] / i\
    \ * (i - 1);\n            }\n        }\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler_totient.cpp
  requiredBy: []
  timestamp: '2021-10-07 16:56:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
documentation_of: math/euler_totient.cpp
layout: document
title: Euler's Totient Function
---

## Description

Euler の totient 関数 $\phi(n)$ の値を求める．これは $n$ 以下の自然数のうち $n$ と互いに素であるものの個数である．

## Operations

- `long long euler_totient(long long n)`
    - $\phi(n)$ を求める
    - 時間計算量: $O(\sqrt{n})$
- `vector<int> euler_totient_table(int n)`
    - $n$ 以下の正整数 $i$ について $\phi(i)$ を求める
    - 時間計算量: $O(n \log\log n)$