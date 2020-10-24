---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: Mod Exponentiation
  - icon: ':heavy_check_mark:'
    path: math/mod_sqrt.cpp
    title: Quadratic Residue
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/yosupo/sqrt_mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n\n#line 2 \"math/mod_sqrt.cpp\"\n#include <numeric>\n#line 2 \"math/mod_pow.cpp\"\
    \n\n/*\n * @brief Mod Exponentiation\n * @docs docs/math/mod_pow.md\n */\nlong\
    \ long mod_pow(long long a, long long p, long long mod) {\n    long long ret =\
    \ 1;\n    while (p > 0) {\n        if (p & 1) ret = ret * a % mod;\n        a\
    \ = a * a % mod;\n        p >>= 1;\n    }\n    return ret;\n}\n\nlong long mod_inv(long\
    \ long a, long long mod) {\n    return mod_pow(a, mod - 2, mod);\n}\n#line 4 \"\
    math/mod_sqrt.cpp\"\n\n/*\n * @brief Quadratic Residue\n */\nlong long mod_sqrt(long\
    \ long n, long long p) {\n    if (n == 0) return 0;\n    if (p == 2) return 1;\n\
    \    if (std::gcd(n, p) != 1) return -1;\n    if (mod_pow(n, (p - 1) / 2, p) ==\
    \ p - 1) return -1;\n    int Q = p - 1, S = 0;\n    while (!(Q & 1)) Q >>= 1,\
    \ ++S;\n    long long z = 2;\n    while (true) {\n        if (mod_pow(z, (p -\
    \ 1) / 2, p) == p - 1) break;\n        ++z;\n    }\n    int M = S;\n    long long\
    \ c = mod_pow(z, Q, p);\n    long long t = mod_pow(n, Q, p);\n    long long R\
    \ = mod_pow(n, (Q + 1) / 2, p);\n    while (t != 1) {\n        int i = 0;\n  \
    \      long long s = t;\n        while (s != 1) {\n            s = s * s % p;\n\
    \            ++i;\n        }\n        long long b = mod_pow(c, 1 << (M - i - 1),\
    \ p);\n        M = i;\n        c = b * b % p;\n        t = t * c % p;\n      \
    \  R = R * b % p;\n    }\n    return R;\n}\n#line 4 \"test/yosupo/sqrt_mod.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int T;\n    cin >> T;\n    for (int i = 0; i < T;\
    \ ++i) {\n        int Y, P;\n        cin >> Y >> P;\n        cout << mod_sqrt(Y,\
    \ P) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ \"../../math/mod_sqrt.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int T;\n    cin >> T;\n    for (int i = 0; i < T; ++i) {\n        int Y,\
    \ P;\n        cin >> Y >> P;\n        cout << mod_sqrt(Y, P) << \"\\n\";\n   \
    \ }\n}"
  dependsOn:
  - math/mod_sqrt.cpp
  - math/mod_pow.cpp
  isVerificationFile: true
  path: test/yosupo/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 02:15:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sqrt_mod.test.cpp
- /verify/test/yosupo/sqrt_mod.test.cpp.html
title: test/yosupo/sqrt_mod.test.cpp
---
