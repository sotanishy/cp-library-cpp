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
  bundledCode: "#line 1 \"math/number-theory/moebius.hpp\"\n#include <cmath>\n#include\
    \ <vector>\n\nint moebius(long long n) {\n    long long ret = 1;\n    if (n %\
    \ 4 == 0) return 0;\n    if (n % 2 == 0) {\n        ret *= -1;\n        n /= 2;\n\
    \    }\n    for (long long i = 3; i * i <= n; i += 2) {\n        if (n % (i *\
    \ i) == 0) return 0;\n        if (n % i == 0) {\n            ret *= -1;\n    \
    \        ret /= i;\n        }\n    }\n    if (n != 1) ret *= -1;\n    return ret;\n\
    }\n\nstd::vector<int> moebius_table(int n) {\n    std::vector<bool> prime(n +\
    \ 1, true);\n    std::vector<int> ret(n + 1, 1);\n    for (int i = 2; i <= n;\
    \ ++i) {\n        if (!prime[i]) continue;\n        for (int j = i; j <= n; j\
    \ += i) {\n            if (j > i) prime[j] = false;\n            if ((j / i) %\
    \ i == 0) ret[j] = 0;\n            else ret[j] *= -1;\n        }\n    }\n    return\
    \ ret;\n}\n\nstd::pair<std::vector<int>, std::vector<int>> mertens_table(long\
    \ long n) {\n    if (n == 0) return {{0}, {0}};\n    const int b = 1e4;\n    std::vector<int>\
    \ small(n/b + 1, 1), large(b + 1, 1);\n    small[0] = large[0] = 0;\n\n    std::vector<bool>\
    \ prime(n/b + 1, true);\n    for (int i = 2; i <= n/b; ++i) {\n        if (!prime[i])\
    \ continue;\n        for (int j = i; j <= n/b; j += i) {\n            if (j >\
    \ i) prime[j] = false;\n            if ((j / i) % i == 0) small[j] = 0;\n    \
    \        else small[j] *= -1;\n        }\n    }\n    for (int i = 1; i < n/b;\
    \ ++i) small[i+1] += small[i];\n\n    for (long long i = b; i >= 1; --i) {\n \
    \       for (long long l = 2; l <= n/i; ) {\n            long long q = n/(i*l),\
    \ r = n/(i*q) + 1;\n            large[i] -= (i*l <= b ? large[i*l] : small[n/(i*l)])\
    \ * (r - l);\n            l = r;\n        }\n    }\n    return {small, large};\n\
    }\n"
  code: "#include <cmath>\n#include <vector>\n\nint moebius(long long n) {\n    long\
    \ long ret = 1;\n    if (n % 4 == 0) return 0;\n    if (n % 2 == 0) {\n      \
    \  ret *= -1;\n        n /= 2;\n    }\n    for (long long i = 3; i * i <= n; i\
    \ += 2) {\n        if (n % (i * i) == 0) return 0;\n        if (n % i == 0) {\n\
    \            ret *= -1;\n            ret /= i;\n        }\n    }\n    if (n !=\
    \ 1) ret *= -1;\n    return ret;\n}\n\nstd::vector<int> moebius_table(int n) {\n\
    \    std::vector<bool> prime(n + 1, true);\n    std::vector<int> ret(n + 1, 1);\n\
    \    for (int i = 2; i <= n; ++i) {\n        if (!prime[i]) continue;\n      \
    \  for (int j = i; j <= n; j += i) {\n            if (j > i) prime[j] = false;\n\
    \            if ((j / i) % i == 0) ret[j] = 0;\n            else ret[j] *= -1;\n\
    \        }\n    }\n    return ret;\n}\n\nstd::pair<std::vector<int>, std::vector<int>>\
    \ mertens_table(long long n) {\n    if (n == 0) return {{0}, {0}};\n    const\
    \ int b = 1e4;\n    std::vector<int> small(n/b + 1, 1), large(b + 1, 1);\n   \
    \ small[0] = large[0] = 0;\n\n    std::vector<bool> prime(n/b + 1, true);\n  \
    \  for (int i = 2; i <= n/b; ++i) {\n        if (!prime[i]) continue;\n      \
    \  for (int j = i; j <= n/b; j += i) {\n            if (j > i) prime[j] = false;\n\
    \            if ((j / i) % i == 0) small[j] = 0;\n            else small[j] *=\
    \ -1;\n        }\n    }\n    for (int i = 1; i < n/b; ++i) small[i+1] += small[i];\n\
    \n    for (long long i = b; i >= 1; --i) {\n        for (long long l = 2; l <=\
    \ n/i; ) {\n            long long q = n/(i*l), r = n/(i*q) + 1;\n            large[i]\
    \ -= (i*l <= b ? large[i*l] : small[n/(i*l)]) * (r - l);\n            l = r;\n\
    \        }\n    }\n    return {small, large};\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/moebius.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/moebius.hpp
layout: document
redirect_from:
- /library/math/number-theory/moebius.hpp
- /library/math/number-theory/moebius.hpp.html
title: math/number-theory/moebius.hpp
---
