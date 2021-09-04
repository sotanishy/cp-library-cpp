---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C.is_prime.test.cpp
    title: test/aoj/ALDS1_1_C.is_prime.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_A.test.cpp
    title: test/aoj/NTL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime.cpp\"\n#include <map>\n#include <vector>\n\n\
    /*\n * Primality Test\n */\nbool is_prime(long long n) {\n    if (n <= 1) return\
    \ false;\n    if (n <= 3) return true;\n    if (n % 2 == 0 || n % 3 == 0) return\
    \ false;\n    if (n < 9) return true;\n    for (long long i = 5; i * i <= n; i\
    \ += 6) {\n        if (n % i == 0 || n % (i + 2) == 0) return false;\n    }\n\
    \    return true;\n}\n\n/*\n * Prime Table\n */\nstd::vector<bool> prime_table(int\
    \ n) {\n    std::vector<bool> prime(n + 1, true);\n    prime[0] = prime[1] = false;\n\
    \    for (int j = 4; j <= n; j += 2) prime[j] = false;\n    for (int i = 3; i\
    \ * i <= n; i += 2) {\n        if (!prime[i]) continue;\n        for (int j =\
    \ i * i; j <= n; j += 2 * i) prime[j] = false;\n    }\n    return prime;\n}\n\n\
    /*\n * Prime Factorization\n */\nstd::map<long long, int> prime_factor(long long\
    \ n) {\n    std::map<long long, int> ret;\n    if (n % 2 == 0) {\n        int\
    \ cnt = 0;\n        while (n % 2 == 0) {\n            ++cnt;\n            n /=\
    \ 2;\n        }\n        ret[2] = cnt;\n    }\n    for (long long i = 3; i * i\
    \ <= n; i += 2) {\n        if (n % i == 0) {\n            int cnt = 0;\n     \
    \       while (n % i == 0) {\n                ++cnt;\n                n /= i;\n\
    \            }\n            ret[i] = cnt;\n        }\n    }\n    if (n != 1) ret[n]\
    \ = 1;\n    return ret;\n}\n"
  code: "#pragma once\n#include <map>\n#include <vector>\n\n/*\n * Primality Test\n\
    \ */\nbool is_prime(long long n) {\n    if (n <= 1) return false;\n    if (n <=\
    \ 3) return true;\n    if (n % 2 == 0 || n % 3 == 0) return false;\n    if (n\
    \ < 9) return true;\n    for (long long i = 5; i * i <= n; i += 6) {\n       \
    \ if (n % i == 0 || n % (i + 2) == 0) return false;\n    }\n    return true;\n\
    }\n\n/*\n * Prime Table\n */\nstd::vector<bool> prime_table(int n) {\n    std::vector<bool>\
    \ prime(n + 1, true);\n    prime[0] = prime[1] = false;\n    for (int j = 4; j\
    \ <= n; j += 2) prime[j] = false;\n    for (int i = 3; i * i <= n; i += 2) {\n\
    \        if (!prime[i]) continue;\n        for (int j = i * i; j <= n; j += 2\
    \ * i) prime[j] = false;\n    }\n    return prime;\n}\n\n/*\n * Prime Factorization\n\
    \ */\nstd::map<long long, int> prime_factor(long long n) {\n    std::map<long\
    \ long, int> ret;\n    if (n % 2 == 0) {\n        int cnt = 0;\n        while\
    \ (n % 2 == 0) {\n            ++cnt;\n            n /= 2;\n        }\n       \
    \ ret[2] = cnt;\n    }\n    for (long long i = 3; i * i <= n; i += 2) {\n    \
    \    if (n % i == 0) {\n            int cnt = 0;\n            while (n % i ==\
    \ 0) {\n                ++cnt;\n                n /= i;\n            }\n     \
    \       ret[i] = cnt;\n        }\n    }\n    if (n != 1) ret[n] = 1;\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.cpp
  requiredBy: []
  timestamp: '2021-02-06 03:15:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_A.test.cpp
  - test/aoj/ALDS1_1_C.is_prime.test.cpp
documentation_of: math/prime.cpp
layout: document
title: Prime Number Algorithms
---

## Description

素数に関するアルゴリズム詰め合わせ

## Primality Test

$n$ を試し割り法で素数判定する．

- `bool is_prime(long long n)`
    - $n$ を素数判定する
    - 時間計算量: $O(\sqrt{n})$

## Prime Table

***NOT VERIFIED***

エラトステネスの篩を用いて，$n$ 以下の整数の素数表を構築する．

- `vector<bool> prime_table(int n)`
    - $n$ 以下の整数の素数表を構築する
    - 時間計算量: $O(n\ln\ln n)$

## Prime Factorization

$n$ を試し割り法で素因数分解する．

- `map<long long, int> prime_factor(long long n)`
    - $n$ を素因数分解し，素因数とその個数の map を返す．
    - 時間計算量: $O(\sqrt{n})$