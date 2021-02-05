---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_arithmetic.cpp
    title: Modular Arithmetic
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#line 2 \"math/mod_arithmetic.cpp\"\
    \n#include <cmath>\n#include <numeric>\n#include <unordered_map>\n\n/*\n * Modular\
    \ Exponentiation\n */\nlong long mod_pow(long long a, long long p, int mod) {\n\
    \    long long ret = 1;\n    while (p > 0) {\n        if (p & 1) ret = ret * a\
    \ % mod;\n        a = a * a % mod;\n        p >>= 1;\n    }\n    return ret;\n\
    }\n\nlong long mod_inv(long long a, int mod) {\n    return mod_pow(a, mod - 2,\
    \ mod);\n}\n\n/*\n * Discrete Logarithm\n */\nint mod_log(long long a, long long\
    \ b, int mod) {\n    // make a and mod coprime\n    a %= mod;\n    b %= mod;\n\
    \    long long k = 1, add = 0, g;\n    while ((g = std::gcd(a, mod)) > 1) {\n\
    \        if (b == k) return add;\n        if (b % g) return -1;\n        b /=\
    \ g;\n        mod /= g;\n        ++add;\n        k = k * a / g % mod;\n    }\n\
    \n    // baby-step\n    const int m = sqrt(mod) + 1;\n    std::unordered_map<long\
    \ long, int> baby_index;\n    long long baby = b;\n    for (int i = 0; i <= m;\
    \ ++i) {\n        baby_index[baby] = i;\n        baby = baby * a % mod;\n    }\n\
    \n    // giant-step\n    long long am = 1;\n    for (int i = 0; i < m; ++i) am\
    \ = am * a % mod;\n    long long giant = k;\n    for (int i = 1; i <= m; ++i)\
    \ {\n        giant = giant * am % mod;\n        if (baby_index.count(giant)) {\n\
    \            return i * m - baby_index[giant] + add;\n        }\n    }\n    return\
    \ -1;\n}\n\n/*\n * Quadratic Residue\n */\nlong long mod_sqrt(long long n, int\
    \ mod) {\n    if (n == 0) return 0;\n    if (mod == 2) return 1;\n    if (std::gcd(n,\
    \ mod) != 1) return -1;\n    if (mod_pow(n, (mod - 1) / 2, mod) == mod - 1) return\
    \ -1;\n\n    int Q = mod - 1, S = 0;\n    while (!(Q & 1)) Q >>= 1, ++S;\n   \
    \ long long z = 2;\n    while (true) {\n        if (mod_pow(z, (mod - 1) / 2,\
    \ mod) == mod - 1) break;\n        ++z;\n    }\n    int M = S;\n    long long\
    \ c = mod_pow(z, Q, mod);\n    long long t = mod_pow(n, Q, mod);\n    long long\
    \ R = mod_pow(n, (Q + 1) / 2, mod);\n    while (t != 1) {\n        int i = 0;\n\
    \        long long s = t;\n        while (s != 1) {\n            s = s * s % mod;\n\
    \            ++i;\n        }\n        long long b = mod_pow(c, 1 << (M - i - 1),\
    \ mod);\n        M = i;\n        c = b * b % mod;\n        t = t * c % mod;\n\
    \        R = R * b % mod;\n    }\n    return R;\n}\n#line 4 \"test/yosupo/discrete_logarithm_mod.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int T;\n    cin >> T;\n    for (int i = 0; i < T;\
    \ ++i) {\n        int X, Y, M;\n        cin >> X >> Y >> M;\n        cout << mod_log(X,\
    \ Y, M) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include \"../../math/mod_arithmetic.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int T;\n    cin >> T;\n    for (int i = 0; i < T; ++i) {\n        int X,\
    \ Y, M;\n        cin >> X >> Y >> M;\n        cout << mod_log(X, Y, M) << \"\\\
    n\";\n    }\n}"
  dependsOn:
  - math/mod_arithmetic.cpp
  isVerificationFile: true
  path: test/yosupo/discrete_logarithm_mod.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 03:15:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/discrete_logarithm_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp
- /verify/test/yosupo/discrete_logarithm_mod.test.cpp.html
title: test/yosupo/discrete_logarithm_mod.test.cpp
---
