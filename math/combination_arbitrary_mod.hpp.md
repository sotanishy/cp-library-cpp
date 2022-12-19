---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.cpp
    title: Prime Number Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/combination_arbitrary_mod.hpp\"\n#include <vector>\n\
    #line 2 \"math/prime.cpp\"\n#include <map>\n#include <numeric>\n#line 5 \"math/prime.cpp\"\
    \n\n/*\n * Primality Test\n */\nbool is_prime(long long n) {\n    if (n <= 1)\
    \ return false;\n    if (n <= 3) return true;\n    if (n % 2 == 0 || n % 3 ==\
    \ 0) return false;\n    if (n < 9) return true;\n    for (long long i = 5; i *\
    \ i <= n; i += 6) {\n        if (n % i == 0 || n % (i + 2) == 0) return false;\n\
    \    }\n    return true;\n}\n\n/*\n * Prime Table\n */\nstd::vector<bool> prime_table(int\
    \ n) {\n    std::vector<bool> prime(n + 1, true);\n    prime[0] = prime[1] = false;\n\
    \    for (int j = 4; j <= n; j += 2) prime[j] = false;\n    for (int i = 3; i\
    \ * i <= n; i += 2) {\n        if (!prime[i]) continue;\n        for (int j =\
    \ i * i; j <= n; j += 2 * i) prime[j] = false;\n    }\n    return prime;\n}\n\n\
    /*\n * Table of Minimum Prime Factors\n */\nstd::vector<int> min_factor_table(int\
    \ n) {\n    std::vector<int> factor(n + 1);\n    std::iota(factor.begin(), factor.end(),\
    \ 0);\n    for (int i = 2; i * i <= n; ++i) {\n        if (factor[i] == i) {\n\
    \            for (int j = i * i; j <= n; j += i) {\n                if (factor[j]\
    \ == j) {\n                    factor[j] = i;\n                }\n           \
    \ }\n        }\n    }\n    return factor;\n}\n\n/*\n * Prime Factorization\n */\n\
    std::map<long long, int> prime_factor(long long n) {\n    std::map<long long,\
    \ int> ret;\n    if (n % 2 == 0) {\n        int cnt = 0;\n        while (n % 2\
    \ == 0) {\n            ++cnt;\n            n /= 2;\n        }\n        ret[2]\
    \ = cnt;\n    }\n    for (long long i = 3; i * i <= n; i += 2) {\n        if (n\
    \ % i == 0) {\n            int cnt = 0;\n            while (n % i == 0) {\n  \
    \              ++cnt;\n                n /= i;\n            }\n            ret[i]\
    \ = cnt;\n        }\n    }\n    if (n != 1) ret[n] = 1;\n    return ret;\n}\n\
    #line 4 \"math/combination_arbitrary_mod.hpp\"\n\ntemplate <typename mint>\nstd::vector<mint>\
    \ combination_arbitrary_modint(int n) {\n    if (n == 0) return {1};\n    const\
    \ int m = mint::mod();\n\n    // preprocess prime\n    auto is_prime = prime_table(n);\n\
    \    std::vector<int> prime;\n    for (int i = 2; i <= n; ++i) {\n        if (is_prime[i])\
    \ {\n            prime.push_back(i);\n        }\n    }\n\n    int l = 0;\n   \
    \ std::vector<int> maxfact(n+1, -1);\n    std::vector<int> ps;\n    for (int p\
    \ : prime) {\n        if (m % p == 0) {\n            ps.push_back(p);\n      \
    \      for (int i = p; i <= n; i += p) {\n                maxfact[i] = l;\n  \
    \          }\n            ++l;\n        }\n    }\n\n    std::vector<std::vector<mint>>\
    \ pow(l);\n    for (int i = 0; i < l; ++i) {\n        pow[i].resize(n / (ps[i]\
    \ - 1) + 1);\n        pow[i][0] = 1;\n        for (int j = 1; j < (int) pow[i].size();\
    \ ++j) {\n            pow[i][j] = pow[i][j-1] * ps[i];\n        }\n    }\n\n \
    \   // calculate comb\n    std::vector<mint> comb(n+1);\n    comb[0] = 1;\n  \
    \  mint s = 1;\n    std::vector<int> t(l);\n    for (int k = 1; k <= n; ++k) {\n\
    \        int den = k;\n        while (maxfact[den] != -1) {\n            --t[maxfact[den]];\n\
    \            den /= ps[maxfact[den]];\n        }\n        int num = n - k + 1;\n\
    \        while (maxfact[num] != -1) {\n            ++t[maxfact[num]];\n      \
    \      num /= ps[maxfact[num]];\n        }\n        s = s / den * num;\n     \
    \   comb[k] = s;\n        for (int i = 0; i < l; ++i) {\n            comb[k] *=\
    \ pow[i][t[i]];\n        }\n    }\n\n    return comb;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"prime.cpp\"\n\ntemplate <typename\
    \ mint>\nstd::vector<mint> combination_arbitrary_modint(int n) {\n    if (n ==\
    \ 0) return {1};\n    const int m = mint::mod();\n\n    // preprocess prime\n\
    \    auto is_prime = prime_table(n);\n    std::vector<int> prime;\n    for (int\
    \ i = 2; i <= n; ++i) {\n        if (is_prime[i]) {\n            prime.push_back(i);\n\
    \        }\n    }\n\n    int l = 0;\n    std::vector<int> maxfact(n+1, -1);\n\
    \    std::vector<int> ps;\n    for (int p : prime) {\n        if (m % p == 0)\
    \ {\n            ps.push_back(p);\n            for (int i = p; i <= n; i += p)\
    \ {\n                maxfact[i] = l;\n            }\n            ++l;\n      \
    \  }\n    }\n\n    std::vector<std::vector<mint>> pow(l);\n    for (int i = 0;\
    \ i < l; ++i) {\n        pow[i].resize(n / (ps[i] - 1) + 1);\n        pow[i][0]\
    \ = 1;\n        for (int j = 1; j < (int) pow[i].size(); ++j) {\n            pow[i][j]\
    \ = pow[i][j-1] * ps[i];\n        }\n    }\n\n    // calculate comb\n    std::vector<mint>\
    \ comb(n+1);\n    comb[0] = 1;\n    mint s = 1;\n    std::vector<int> t(l);\n\
    \    for (int k = 1; k <= n; ++k) {\n        int den = k;\n        while (maxfact[den]\
    \ != -1) {\n            --t[maxfact[den]];\n            den /= ps[maxfact[den]];\n\
    \        }\n        int num = n - k + 1;\n        while (maxfact[num] != -1) {\n\
    \            ++t[maxfact[num]];\n            num /= ps[maxfact[num]];\n      \
    \  }\n        s = s / den * num;\n        comb[k] = s;\n        for (int i = 0;\
    \ i < l; ++i) {\n            comb[k] *= pow[i][t[i]];\n        }\n    }\n\n  \
    \  return comb;\n}"
  dependsOn:
  - math/prime.cpp
  isVerificationFile: false
  path: math/combination_arbitrary_mod.hpp
  requiredBy: []
  timestamp: '2022-12-12 15:48:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination_arbitrary_mod.hpp
layout: document
title: Combination
---

## Description

二項係数を任意の mod で計算する．

- `vector<mint> combination_arbitrary_mod(int n)`
    - $\binom{n}{k}\quad (k=0,\dots,n)$ を mod $m$ で計算する
    - 時間計算量: $O(n\log m / \log\log m)$

## Reference

- [任意 mod で二項係数を列挙する](https://qiita.com/suisen_cp/items/d0ab7e728b98bbec818f)
- verify: [https://atcoder.jp/contests/abc281/submissions/37229804](https://atcoder.jp/contests/abc281/submissions/37229804)