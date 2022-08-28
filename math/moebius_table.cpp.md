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
    document_title: Table of Moebius Function
    links: []
  bundledCode: "#line 1 \"math/moebius_table.cpp\"\n#include <vector>\n#line 2 \"\
    math/prime.cpp\"\n#include <map>\n#include <numeric>\n#line 5 \"math/prime.cpp\"\
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
    #line 3 \"math/moebius_table.cpp\"\n\n/*\n * @brief Table of Moebius Function\n\
    \ */\nstd::vector<int> moebius_table(int n) {\n    std::vector<bool> prime(n +\
    \ 1, true);\n    std::vector<int> ret(n + 1, 1);\n    for (int i = 2; i <= n;\
    \ ++i) {\n        if (!prime[i]) continue;\n        for (int j = i; j <= n; j\
    \ += i) {\n            if (j > i) prime[j] = false;\n            if ((j / i) %\
    \ i == 0) ret[j] = 0;\n            else ret[j] *= -1;\n        }\n    }\n    return\
    \ ret;\n}\n"
  code: "#include <vector>\n#include \"prime.cpp\"\n\n/*\n * @brief Table of Moebius\
    \ Function\n */\nstd::vector<int> moebius_table(int n) {\n    std::vector<bool>\
    \ prime(n + 1, true);\n    std::vector<int> ret(n + 1, 1);\n    for (int i = 2;\
    \ i <= n; ++i) {\n        if (!prime[i]) continue;\n        for (int j = i; j\
    \ <= n; j += i) {\n            if (j > i) prime[j] = false;\n            if ((j\
    \ / i) % i == 0) ret[j] = 0;\n            else ret[j] *= -1;\n        }\n    }\n\
    \    return ret;\n}"
  dependsOn:
  - math/prime.cpp
  isVerificationFile: false
  path: math/moebius_table.cpp
  requiredBy: []
  timestamp: '2022-08-28 10:49:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/moebius_table.cpp
layout: document
redirect_from:
- /library/math/moebius_table.cpp
- /library/math/moebius_table.cpp.html
title: Table of Moebius Function
---
