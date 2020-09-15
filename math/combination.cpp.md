---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/combination.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct Combination {\n    long long mod;\n    vector<long\
    \ long> fact, fact_inv;\n\nprivate:\n    static pair<long long, long long> extgcd(long\
    \ long a, long long b) {\n        long long s = a, sx = 1, sy = 0, t = b, tx =\
    \ 0, ty = 1;\n        while (t) {\n            long long q = s / t;\n        \
    \    s -= t * q;\n            swap(s, t);\n            sx -= tx * q;\n       \
    \     swap(sx, tx);\n            sy -= ty * q;\n            swap(sy, ty);\n  \
    \      }\n        return {sx, sy};\n    }\n\n    static long long mod_inv(long\
    \ long a, long long mod) {\n        long long inv = extgcd(a, mod).first;\n  \
    \      return (inv % mod + mod) % mod;\n    }\n\npublic:\n    static long long\
    \ C(int n, int r, long long mod) {\n        long long num = 1, den = 1;\n    \
    \    for (int i = 1; i <= r; i++) {\n            num = num * (n - i + 1) % mod;\n\
    \            den = den * i % mod;\n        }\n        return num * mod_inv(den,\
    \ mod) % mod;\n    }\n\n    Combination(int n, long long mod) : mod(mod), fact(n+1),\
    \ fact_inv(n+1) {\n        fact[0] = fact_inv[0] = 1;\n        for (int i = 1;\
    \ i <= n; i++) fact[i] = fact[i-1] * i % mod;\n        fact_inv[n] = mod_inv(n,\
    \ mod);\n        for (int i = n; i > 0; i--) fact_inv[i-1] = fact_inv[i] * i %\
    \ mod;\n    }\n\n    long long P(int n, int r) const {\n        if (r < 0 || n\
    \ < r) return 0;\n        return fact[n] * fact_inv[n - r] % mod;\n    }\n\n \
    \   long long C(int n, int r) const {\n        if (r < 0 || n < r) return 0;\n\
    \        return fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod;\n    }\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct Combination {\n\
    \    long long mod;\n    vector<long long> fact, fact_inv;\n\nprivate:\n    static\
    \ pair<long long, long long> extgcd(long long a, long long b) {\n        long\
    \ long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;\n        while (t) {\n  \
    \          long long q = s / t;\n            s -= t * q;\n            swap(s,\
    \ t);\n            sx -= tx * q;\n            swap(sx, tx);\n            sy -=\
    \ ty * q;\n            swap(sy, ty);\n        }\n        return {sx, sy};\n  \
    \  }\n\n    static long long mod_inv(long long a, long long mod) {\n        long\
    \ long inv = extgcd(a, mod).first;\n        return (inv % mod + mod) % mod;\n\
    \    }\n\npublic:\n    static long long C(int n, int r, long long mod) {\n   \
    \     long long num = 1, den = 1;\n        for (int i = 1; i <= r; i++) {\n  \
    \          num = num * (n - i + 1) % mod;\n            den = den * i % mod;\n\
    \        }\n        return num * mod_inv(den, mod) % mod;\n    }\n\n    Combination(int\
    \ n, long long mod) : mod(mod), fact(n+1), fact_inv(n+1) {\n        fact[0] =\
    \ fact_inv[0] = 1;\n        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] *\
    \ i % mod;\n        fact_inv[n] = mod_inv(n, mod);\n        for (int i = n; i\
    \ > 0; i--) fact_inv[i-1] = fact_inv[i] * i % mod;\n    }\n\n    long long P(int\
    \ n, int r) const {\n        if (r < 0 || n < r) return 0;\n        return fact[n]\
    \ * fact_inv[n - r] % mod;\n    }\n\n    long long C(int n, int r) const {\n \
    \       if (r < 0 || n < r) return 0;\n        return fact[n] * fact_inv[r] %\
    \ mod * fact_inv[n - r] % mod;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/combination.cpp
  requiredBy: []
  timestamp: '2020-09-10 20:23:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.cpp
layout: document
redirect_from:
- /library/math/combination.cpp
- /library/math/combination.cpp.html
title: math/combination.cpp
---
