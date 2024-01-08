---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/counting_primes.test.cpp
    title: test/yosupo/counting_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/number-theory/prime_count.hpp\"\n#include <cmath>\n\
    #include <vector>\n\nlong long prime_count(long long n) {\n    int s = (int)std::sqrt(n);\n\
    \    std::vector<long long> small(n / s + 1), large(s + 1);\n    for (int i =\
    \ 1; i <= n / s; ++i) small[i] = i - 1;\n    for (int i = 1; i <= s; ++i) large[i]\
    \ = n / i - 1;\n    for (long long i = 2; i <= s; ++i) {\n        if (small[i\
    \ - 1] == small[i]) continue;  // i is not prime\n        long long pi = small[i\
    \ - 1];\n        for (long long j = 1; j <= s && n / j >= i * i; ++j) {\n    \
    \        long long x = i * j <= s ? large[i * j] : small[n / (i * j)];\n     \
    \       if (j <= s) {\n                large[j] -= x - pi;\n            }\n  \
    \          if (n / j <= n / s) {\n                small[n / j] -= x - pi;\n  \
    \          }\n        }\n        for (long long j = n / s - 1; j >= i * i; --j)\
    \ {\n            small[j] -= small[j / i] - pi;\n        }\n    }\n    return\
    \ large[1];\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\nlong long prime_count(long\
    \ long n) {\n    int s = (int)std::sqrt(n);\n    std::vector<long long> small(n\
    \ / s + 1), large(s + 1);\n    for (int i = 1; i <= n / s; ++i) small[i] = i -\
    \ 1;\n    for (int i = 1; i <= s; ++i) large[i] = n / i - 1;\n    for (long long\
    \ i = 2; i <= s; ++i) {\n        if (small[i - 1] == small[i]) continue;  // i\
    \ is not prime\n        long long pi = small[i - 1];\n        for (long long j\
    \ = 1; j <= s && n / j >= i * i; ++j) {\n            long long x = i * j <= s\
    \ ? large[i * j] : small[n / (i * j)];\n            if (j <= s) {\n          \
    \      large[j] -= x - pi;\n            }\n            if (n / j <= n / s) {\n\
    \                small[n / j] -= x - pi;\n            }\n        }\n        for\
    \ (long long j = n / s - 1; j >= i * i; --j) {\n            small[j] -= small[j\
    \ / i] - pi;\n        }\n    }\n    return large[1];\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/prime_count.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/counting_primes.test.cpp
documentation_of: math/number-theory/prime_count.hpp
layout: document
title: Prime Counting Function
---

## Description

素数計数関数 $\pi(n)$ を計算する．

- `long long prime_count(long long n)`
    - $n$ 以下の素数の個数を計算する
    - 時間計算量: $O(n^{3/4}/\log n)$

## Reference

- [眠れない夜は素数の個数でも数えましょう](https://rsk0315.hatenablog.com/entry/2021/05/18/015511)