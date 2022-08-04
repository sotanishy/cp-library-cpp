---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euler_totient.cpp
    title: Euler's Totient Function
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
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"test/yosupo/sqrt_mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n\n#line 2 \"math/mod_arithmetic.cpp\"\n#include <cmath>\n#include <numeric>\n\
    #include <unordered_map>\n#line 3 \"math/euler_totient.cpp\"\n#include <vector>\n\
    \nlong long euler_totient(long long n) {\n    long long ret = n;\n    if (n %\
    \ 2 == 0) {\n        ret -= ret / 2;\n        while (n % 2 == 0) n /= 2;\n   \
    \ }\n    for (long long i = 3; i * i <= n; i += 2) {\n        if (n % i == 0)\
    \ {\n            ret -= ret / i;\n            while (n % i == 0) n /= i;\n   \
    \     }\n    }\n    if (n != 1) ret -= ret / n;\n    return ret;\n}\n\nstd::vector<int>\
    \ euler_totient_table(int n) {\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(),\
    \ ret.end(), 0);\n    for (int i = 2; i <= n; ++i) {\n        if (ret[i] == i)\
    \ {\n            for (int j = i; j <= n; j += i) {\n                ret[j] = ret[j]\
    \ / i * (i - 1);\n            }\n        }\n    }\n    return ret;\n}\n#line 6\
    \ \"math/mod_arithmetic.cpp\"\n\n/*\n * Modular Exponentiation\n */\nlong long\
    \ mod_pow(long long a, long long e, int mod) {\n    long long ret = 1;\n    while\
    \ (e > 0) {\n        if (e & 1) ret = ret * a % mod;\n        a = a * a % mod;\n\
    \        e >>= 1;\n    }\n    return ret;\n}\n\nlong long mod_inv(long long a,\
    \ int mod) {\n    return mod_pow(a, mod - 2, mod);\n}\n\n/*\n * Discrete Logarithm\n\
    \ */\nint mod_log(long long a, long long b, int mod) {\n    // make a and mod\
    \ coprime\n    a %= mod;\n    b %= mod;\n    long long k = 1, add = 0, g;\n  \
    \  while ((g = std::gcd(a, mod)) > 1) {\n        if (b == k) return add;\n   \
    \     if (b % g) return -1;\n        b /= g;\n        mod /= g;\n        ++add;\n\
    \        k = k * a / g % mod;\n    }\n\n    // baby-step\n    const int m = sqrt(mod)\
    \ + 1;\n    std::unordered_map<long long, int> baby_index;\n    long long baby\
    \ = b;\n    for (int i = 0; i <= m; ++i) {\n        baby_index[baby] = i;\n  \
    \      baby = baby * a % mod;\n    }\n\n    // giant-step\n    long long am =\
    \ 1;\n    for (int i = 0; i < m; ++i) am = am * a % mod;\n    long long giant\
    \ = k;\n    for (int i = 1; i <= m; ++i) {\n        giant = giant * am % mod;\n\
    \        if (baby_index.count(giant)) {\n            return i * m - baby_index[giant]\
    \ + add;\n        }\n    }\n    return -1;\n}\n\n/*\n * Quadratic Residue\n */\n\
    long long mod_sqrt(long long n, int mod) {\n    if (n == 0) return 0;\n    if\
    \ (mod == 2) return 1;\n    if (std::gcd(n, mod) != 1) return -1;\n    if (mod_pow(n,\
    \ (mod - 1) / 2, mod) == mod - 1) return -1;\n\n    int Q = mod - 1, S = 0;\n\
    \    while (!(Q & 1)) Q >>= 1, ++S;\n    long long z = 2;\n    while (true) {\n\
    \        if (mod_pow(z, (mod - 1) / 2, mod) == mod - 1) break;\n        ++z;\n\
    \    }\n    int M = S;\n    long long c = mod_pow(z, Q, mod);\n    long long t\
    \ = mod_pow(n, Q, mod);\n    long long R = mod_pow(n, (Q + 1) / 2, mod);\n   \
    \ while (t != 1) {\n        int i = 0;\n        long long s = t;\n        while\
    \ (s != 1) {\n            s = s * s % mod;\n            ++i;\n        }\n    \
    \    long long b = mod_pow(c, 1 << (M - i - 1), mod);\n        M = i;\n      \
    \  c = b * b % mod;\n        t = t * c % mod;\n        R = R * b % mod;\n    }\n\
    \    return R;\n}\n\n/**\n * Modular Tetration\n */\nlong long mod_tetration(long\
    \ long a, long long b, int mod) {\n    if (mod == 1) return 0;\n    if (a == 0)\
    \ return 1 - (b % 2);\n    if (a == 1 || b == 0) return 1;\n\n    auto pow = [&](long\
    \ long a, long long e, int mod) {\n        if (a >= mod) a = a % mod + mod;\n\
    \        long long ret = 1;\n        while (e > 0) {\n            if (e & 1) {\n\
    \                ret = ret * a;\n                if (ret >= mod) ret = ret % mod\
    \ + mod;\n            }\n            a = a * a;\n            if (a >= mod) a =\
    \ a % mod + mod;\n            e >>= 1;\n        }\n        return ret;\n    };\n\
    \n    auto rec = [&](auto& rec, long long b, int mod) -> long long {\n       \
    \ if (b == 1) return a;\n        if (mod == 1) return 1;\n        return pow(a,\
    \ rec(rec, b - 1, euler_totient(mod)), mod);\n    };\n\n    return rec(rec, b,\
    \ mod) % mod;\n}\n\n/**\n * Table of Modular Inverses\n */\nstd::vector<int> mod_inv_table(int\
    \ n, int mod) {\n    std::vector<int> inv(n + 1, 1);\n    for (int i = 2; i <=\
    \ n; ++i) {\n        inv[i] = mod - 1LL * inv[mod % i] * (mod / i) % mod;\n  \
    \  }\n    return inv;\n}\n#line 4 \"test/yosupo/sqrt_mod.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int T;\n    cin >> T;\n    for (int i = 0; i < T;\
    \ ++i) {\n        int Y, P;\n        cin >> Y >> P;\n        cout << mod_sqrt(Y,\
    \ P) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ \"../../math/mod_arithmetic.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int T;\n    cin >> T;\n    for (int i = 0; i < T; ++i) {\n        int Y,\
    \ P;\n        cin >> Y >> P;\n        cout << mod_sqrt(Y, P) << \"\\n\";\n   \
    \ }\n}"
  dependsOn:
  - math/mod_arithmetic.cpp
  - math/euler_totient.cpp
  isVerificationFile: true
  path: test/yosupo/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2022-08-04 12:02:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sqrt_mod.test.cpp
- /verify/test/yosupo/sqrt_mod.test.cpp.html
title: test/yosupo/sqrt_mod.test.cpp
---
