---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.cpp
    title: Prime Number Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/carmichael.cpp\"\n#include <cmath>\n#include <numeric>\n\
    #line 2 \"math/prime.cpp\"\n#include <map>\n#line 4 \"math/prime.cpp\"\n#include\
    \ <vector>\n\n/*\n * Primality Test\n */\nbool is_prime(long long n) {\n    if\
    \ (n <= 1) return false;\n    if (n <= 3) return true;\n    if (n % 2 == 0 ||\
    \ n % 3 == 0) return false;\n    if (n < 9) return true;\n    for (long long i\
    \ = 5; i * i <= n; i += 6) {\n        if (n % i == 0 || n % (i + 2) == 0) return\
    \ false;\n    }\n    return true;\n}\n\n/*\n * Prime Table\n */\nstd::vector<bool>\
    \ prime_table(int n) {\n    std::vector<bool> prime(n + 1, true);\n    prime[0]\
    \ = prime[1] = false;\n    for (int j = 4; j <= n; j += 2) prime[j] = false;\n\
    \    for (int i = 3; i * i <= n; i += 2) {\n        if (!prime[i]) continue;\n\
    \        for (int j = i * i; j <= n; j += 2 * i) prime[j] = false;\n    }\n  \
    \  return prime;\n}\n\n/*\n * Table of Minimum Prime Factors\n */\nstd::vector<int>\
    \ min_factor_table(int n) {\n    std::vector<int> factor(n + 1);\n    std::iota(factor.begin(),\
    \ factor.end(), 0);\n    for (int i = 2; i * i <= n; ++i) {\n        if (factor[i]\
    \ == i) {\n            for (int j = i * i; j <= n; j += i) {\n               \
    \ if (factor[j] == j) {\n                    factor[j] = i;\n                }\n\
    \            }\n        }\n    }\n    return factor;\n}\n\n/*\n * Prime Factorization\n\
    \ */\nstd::map<long long, int> prime_factor(long long n) {\n    std::map<long\
    \ long, int> ret;\n    if (n % 2 == 0) {\n        int cnt = 0;\n        while\
    \ (n % 2 == 0) {\n            ++cnt;\n            n /= 2;\n        }\n       \
    \ ret[2] = cnt;\n    }\n    for (long long i = 3; i * i <= n; i += 2) {\n    \
    \    if (n % i == 0) {\n            int cnt = 0;\n            while (n % i ==\
    \ 0) {\n                ++cnt;\n                n /= i;\n            }\n     \
    \       ret[i] = cnt;\n        }\n    }\n    if (n != 1) ret[n] = 1;\n    return\
    \ ret;\n}\n#line 5 \"math/carmichael.cpp\"\n\nlong long carmichael(long long n)\
    \ {\n    long long ret = 1;\n    for (auto [p, e] : prime_factor(n)) {\n     \
    \   long long lambda = std::pow(p, e - 1) * (p - 1);\n        if (p == 2 && e\
    \ >= 3) lambda /= 2;\n        ret = ret / std::gcd(ret, lambda) * lambda;\n  \
    \  }\n    return ret;\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <numeric>\n#include \"prime.cpp\"\
    \n\nlong long carmichael(long long n) {\n    long long ret = 1;\n    for (auto\
    \ [p, e] : prime_factor(n)) {\n        long long lambda = std::pow(p, e - 1) *\
    \ (p - 1);\n        if (p == 2 && e >= 3) lambda /= 2;\n        ret = ret / std::gcd(ret,\
    \ lambda) * lambda;\n    }\n    return ret;\n}"
  dependsOn:
  - math/prime.cpp
  isVerificationFile: false
  path: math/carmichael.cpp
  requiredBy: []
  timestamp: '2021-12-04 19:51:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/carmichael.cpp
layout: document
title: Carmichael Function
---

## Description

Carmichael 関数 $\lambda(n)$ の値を求める．これは，$n$ と互いに素である $n$ 以下の自然数 $a$ 全てに対して$a^m \equiv 1 \mod n$ を満たすような最小の自然数 $m$ を与える．

Euler の定理より $m = \phi(n)$ は上の条件を満たすが，それが最小の $m$ であるとは限らない．最小の $m$ が $\lambda(n)$ である．

## Operations

- `long long carmichael(long long n)`
    - $\lambda(n)$ を求める
    - 時間計算量: $O(\sqrt{n})$