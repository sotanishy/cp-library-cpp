---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: Mod Exponentiation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/mod_log.md
    document_title: Discrete Logarithm
    links: []
  bundledCode: "#line 2 \"math/mod_log.cpp\"\n#include <cmath>\n#include <unordered_map>\n\
    #include <vector>\n#line 2 \"math/mod_pow.cpp\"\n\n/*\n * @brief Mod Exponentiation\n\
    \ * @docs docs/math/mod_pow.md\n */\nlong long mod_pow(long long a, long long\
    \ p, long long mod) {\n    long long ret = 1;\n    while (p > 0) {\n        if\
    \ (p & 1) ret = ret * a % mod;\n        a = a * a % mod;\n        p >>= 1;\n \
    \   }\n    return ret;\n}\n\nlong long mod_inv(long long a, long long mod) {\n\
    \    return mod_pow(a, mod - 2, mod);\n}\n#line 6 \"math/mod_log.cpp\"\n\n/*\n\
    \ * @brief Discrete Logarithm\n * @docs docs/math/mod_log.md\n */\nint mod_log(long\
    \ long a, long long b, int p) {\n    int m = sqrt(p) + 1;\n    std::vector<long\
    \ long> baby(m);\n    std::unordered_map<long long, int> baby_index;\n    long\
    \ long x = 1;\n    for (int i = 0; i < m; ++i) {\n        baby[i] = x;\n     \
    \   baby_index[x] = i;\n        x = x * a % p;\n    }\n\n    std::vector<long\
    \ long> giant(m);\n    long long c = mod_inv(mod_pow(a, m, p), p);\n    x = 1;\n\
    \    for (int i = 0; i < m; ++i) {\n        giant[i] = x;\n        x = x * c %\
    \ p;\n    }\n\n    for (int i = 0; i < m; ++i) {\n        long long y = b * giant[i]\
    \ % p;\n        if (baby_index.count(y) > 0) {\n            return i * m + baby_index[y];\n\
    \        }\n    }\n    return -1;\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <unordered_map>\n#include <vector>\n\
    #include \"mod_pow.cpp\"\n\n/*\n * @brief Discrete Logarithm\n * @docs docs/math/mod_log.md\n\
    \ */\nint mod_log(long long a, long long b, int p) {\n    int m = sqrt(p) + 1;\n\
    \    std::vector<long long> baby(m);\n    std::unordered_map<long long, int> baby_index;\n\
    \    long long x = 1;\n    for (int i = 0; i < m; ++i) {\n        baby[i] = x;\n\
    \        baby_index[x] = i;\n        x = x * a % p;\n    }\n\n    std::vector<long\
    \ long> giant(m);\n    long long c = mod_inv(mod_pow(a, m, p), p);\n    x = 1;\n\
    \    for (int i = 0; i < m; ++i) {\n        giant[i] = x;\n        x = x * c %\
    \ p;\n    }\n\n    for (int i = 0; i < m; ++i) {\n        long long y = b * giant[i]\
    \ % p;\n        if (baby_index.count(y) > 0) {\n            return i * m + baby_index[y];\n\
    \        }\n    }\n    return -1;\n}"
  dependsOn:
  - math/mod_pow.cpp
  isVerificationFile: false
  path: math/mod_log.cpp
  requiredBy: []
  timestamp: '2020-10-24 15:32:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_log.cpp
layout: document
redirect_from:
- /library/math/mod_log.cpp
- /library/math/mod_log.cpp.html
title: Discrete Logarithm
---
# Discrete Logarithm

離散対数を計算する．すなわち，$a^x = b (\mod p)$ を満たす $x$ を求める．

Baby-step giant-step 法を用いている．

- `int mod_log(long long a, long long b, long long p)`
    - $a^x = b (\mod p)$ を満たす $x$ を求める．存在しない場合は $-1$ を返す．
    - 時間計算量: $O(\sqrt{p})$