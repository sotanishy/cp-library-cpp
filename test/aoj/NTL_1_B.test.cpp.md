---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_arithmetic.cpp
    title: Modular Arithmetic
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#line 2 \"math/mod_arithmetic.cpp\"\n#include <cmath>\n#include <numeric>\n\
    #include <unordered_map>\n\n/*\n * @brief Modular Arithmetic\n * @docs docs/math/mod_arithmetic.md\n\
    \ */\n\n/*\n * Modular Exponentiation\n */\nlong long mod_pow(long long a, long\
    \ long p, int mod) {\n    long long ret = 1;\n    while (p > 0) {\n        if\
    \ (p & 1) ret = ret * a % mod;\n        a = a * a % mod;\n        p >>= 1;\n \
    \   }\n    return ret;\n}\n\nlong long mod_inv(long long a, int mod) {\n    return\
    \ mod_pow(a, mod - 2, mod);\n}\n\n/*\n * Discrete Logarithm\n */\nint mod_log(long\
    \ long a, long long b, int mod) {\n    // make a and mod coprime\n    a %= mod;\n\
    \    b %= mod;\n    long long k = 1, add = 0, g;\n    while ((g = std::gcd(a,\
    \ mod)) > 1) {\n        if (b == k) return add;\n        if (b % g) return -1;\n\
    \        b /= g;\n        mod /= g;\n        ++add;\n        k = k * a / g % mod;\n\
    \    }\n\n    // baby-step\n    const int m = sqrt(mod) + 1;\n    std::unordered_map<long\
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
    \        R = R * b % mod;\n    }\n    return R;\n}\n#line 4 \"test/aoj/NTL_1_B.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int m, n;\n    cin >> m >> n;\n    cout << mod_pow(m,\
    \ n, 1e9 + 7) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include \"../../math/mod_arithmetic.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int m, n;\n    cin >> m >> n;\n    cout << mod_pow(m, n, 1e9 + 7) << endl;\n\
    }"
  dependsOn:
  - math/mod_arithmetic.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-10-25 21:55:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
