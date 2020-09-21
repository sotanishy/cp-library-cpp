---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/combination.md
    document_title: Combination
    links: []
  bundledCode: "#line 1 \"math/combination.cpp\"\n#include <bits/stdc++.h>\n\n/*\n\
    \ * @brief Combination\n * @docs docs/math/combination.md\n */\nclass Combination\
    \ {\n    static long long C(int n, int r, long long mod) {\n        long long\
    \ num = 1, den = 1;\n        for (int i = 1; i <= r; i++) {\n            num =\
    \ num * (n - i + 1) % mod;\n            den = den * i % mod;\n        }\n    \
    \    return num * mod_inv(den, mod) % mod;\n    }\n\n    Combination(int n, long\
    \ long mod) : mod(mod), fact(n + 1), fact_inv(n + 1) {\n        fact[0] = fact_inv[0]\
    \ = 1;\n        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % mod;\n\
    \        fact_inv[n] = mod_inv(n, mod);\n        for (int i = n; i > 0; i--) fact_inv[i-1]\
    \ = fact_inv[i] * i % mod;\n    }\n\n    long long P(int n, int r) const {\n \
    \       if (r < 0 || n < r) return 0;\n        return fact[n] * fact_inv[n - r]\
    \ % mod;\n    }\n\n    long long C(int n, int r) const {\n        if (r < 0 ||\
    \ n < r) return 0;\n        return fact[n] * fact_inv[r] % mod * fact_inv[n -\
    \ r] % mod;\n    }\n\nprivate:\n    long long mod;\n    std::vector<long long>\
    \ fact, fact_inv;\n\n    static long long mod_inv(long long a, long long mod)\
    \ {\n        long long b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n  \
    \          t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return (u % mod + mod) % mod;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Combination\n * @docs docs/math/combination.md\n\
    \ */\nclass Combination {\n    static long long C(int n, int r, long long mod)\
    \ {\n        long long num = 1, den = 1;\n        for (int i = 1; i <= r; i++)\
    \ {\n            num = num * (n - i + 1) % mod;\n            den = den * i % mod;\n\
    \        }\n        return num * mod_inv(den, mod) % mod;\n    }\n\n    Combination(int\
    \ n, long long mod) : mod(mod), fact(n + 1), fact_inv(n + 1) {\n        fact[0]\
    \ = fact_inv[0] = 1;\n        for (int i = 1; i <= n; i++) fact[i] = fact[i-1]\
    \ * i % mod;\n        fact_inv[n] = mod_inv(n, mod);\n        for (int i = n;\
    \ i > 0; i--) fact_inv[i-1] = fact_inv[i] * i % mod;\n    }\n\n    long long P(int\
    \ n, int r) const {\n        if (r < 0 || n < r) return 0;\n        return fact[n]\
    \ * fact_inv[n - r] % mod;\n    }\n\n    long long C(int n, int r) const {\n \
    \       if (r < 0 || n < r) return 0;\n        return fact[n] * fact_inv[r] %\
    \ mod * fact_inv[n - r] % mod;\n    }\n\nprivate:\n    long long mod;\n    std::vector<long\
    \ long> fact, fact_inv;\n\n    static long long mod_inv(long long a, long long\
    \ mod) {\n        long long b = mod, u = 1, v = 0, t;\n        while (b > 0) {\n\
    \            t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return (u % mod + mod) % mod;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/combination.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.cpp
layout: document
redirect_from:
- /library/math/combination.cpp
- /library/math/combination.cpp.html
title: Combination
---
# Combination

組み合わせ $n \choose r$ および順列 $_n P _r$ を $\mod mod$ で計算する．これらの値を何度も計算する必要があるときは non-static メンバーを，1度でいいときは static メンバーを使用する．また，$n$ の値が配列に入らないほど大きいが $r$ の値は十分小さいときも static メンバーを使用する．

空間計算量: $O(n)$

## Constructor

- `Combination(int n, long long mod)`
    - $n$ 以下の整数の階乗及びその逆元を前計算する
    - 時間計算量: $O(n)$

## Member functions

- `static long long C(int n, int r, long long mod)`
    - $n \choose r$ を計算する．
    - 時間計算量: $O(r)$

- `long long P(int n, int r)`
    - $_n P _r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$

- `long long C(int n, int r)`
    - $n \choose r$ を計算する．$r < 0$ または $n < r$ のときは0を返す
    - 時間計算量: $O(1)$