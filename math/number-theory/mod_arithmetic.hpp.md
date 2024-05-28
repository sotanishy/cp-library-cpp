---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/euler_totient.hpp
    title: Euler's Totient Function
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tetration_mod.test.cpp
    title: test/yosupo/tetration_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/number-theory/mod_arithmetic.hpp\"\n#include <vector>\n\
    #include <cmath>\n#include <numeric>\n#include <unordered_map>\n\n#line 4 \"math/number-theory/euler_totient.hpp\"\
    \n\nlong long euler_totient(long long n) {\n    long long ret = n;\n    if (n\
    \ % 2 == 0) {\n        ret -= ret / 2;\n        while (n % 2 == 0) n /= 2;\n \
    \   }\n    for (long long i = 3; i * i <= n; i += 2) {\n        if (n % i == 0)\
    \ {\n            ret -= ret / i;\n            while (n % i == 0) n /= i;\n   \
    \     }\n    }\n    if (n != 1) ret -= ret / n;\n    return ret;\n}\n\nstd::vector<int>\
    \ euler_totient_table(int n) {\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(),\
    \ ret.end(), 0);\n    for (int i = 2; i <= n; ++i) {\n        if (ret[i] == i)\
    \ {\n            for (int j = i; j <= n; j += i) {\n                ret[j] = ret[j]\
    \ / i * (i - 1);\n            }\n        }\n    }\n    return ret;\n}\n\ntemplate\
    \ <typename mint>\nstd::pair<std::vector<mint>, std::vector<mint>> totient_summatory_table(\n\
    \    long long n) {\n    if (n == 0) return {{0}, {0}};\n    const int b = std::min(n,\
    \ (long long)1e4);\n    std::vector<mint> small(n / b + 1), large(b + 1);\n\n\
    \    std::vector<int> totient(n / b + 1);\n    std::iota(totient.begin(), totient.end(),\
    \ 0);\n    for (int i = 2; i <= n / b; ++i) {\n        if (totient[i] != i) continue;\n\
    \        for (int j = i; j <= n / b; j += i) {\n            totient[j] = totient[j]\
    \ / i * (i - 1);\n        }\n    }\n    for (int i = 0; i < n / b; ++i) small[i\
    \ + 1] = small[i] + totient[i + 1];\n\n    for (int i = 1; i <= b; ++i) {\n  \
    \      mint k = n / i;\n        large[i] = k * (k + 1) / 2;\n    }\n    for (long\
    \ long i = b; i >= 1; --i) {\n        for (long long l = 2; l <= n / i;) {\n \
    \           long long q = n / (i * l), r = n / (i * q) + 1;\n            large[i]\
    \ -=\n                (i * l <= b ? large[i * l] : small[n / (i * l)]) * (r -\
    \ l);\n            l = r;\n        }\n    }\n    return {small, large};\n}\n#line\
    \ 8 \"math/number-theory/mod_arithmetic.hpp\"\n\n/*\n * Modular Exponentiation\n\
    \ */\nlong long mod_pow(long long a, long long e, int mod) {\n    long long ret\
    \ = 1;\n    while (e > 0) {\n        if (e & 1) ret = ret * a % mod;\n       \
    \ a = a * a % mod;\n        e >>= 1;\n    }\n    return ret;\n}\n\nlong long mod_inv(long\
    \ long a, int mod) { return mod_pow(a, mod - 2, mod); }\n\n/*\n * Discrete Logarithm\n\
    \ */\nint mod_log(long long a, long long b, int mod) {\n    // make a and mod\
    \ coprime\n    a %= mod;\n    b %= mod;\n    long long k = 1, add = 0, g;\n  \
    \  while ((g = std::gcd(a, mod)) > 1) {\n        if (b == k) return add;\n   \
    \     if (b % g) return -1;\n        b /= g;\n        mod /= g;\n        ++add;\n\
    \        k = k * a / g % mod;\n    }\n\n    // baby-step\n    const int m = std::sqrt(mod)\
    \ + 1;\n    std::unordered_map<long long, int> baby_index;\n    long long baby\
    \ = b;\n    for (int i = 0; i <= m; ++i) {\n        baby_index[baby] = i;\n  \
    \      baby = baby * a % mod;\n    }\n\n    // giant-step\n    long long am =\
    \ 1;\n    for (int i = 0; i < m; ++i) am = am * a % mod;\n    long long giant\
    \ = k;\n    for (int i = 1; i <= m; ++i) {\n        giant = giant * am % mod;\n\
    \        if (baby_index.contains(giant)) {\n            return i * m - baby_index[giant]\
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
    \  }\n    return inv;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cmath>\n#include <numeric>\n#include\
    \ <unordered_map>\n\n#include \"euler_totient.hpp\"\n\n/*\n * Modular Exponentiation\n\
    \ */\nlong long mod_pow(long long a, long long e, int mod) {\n    long long ret\
    \ = 1;\n    while (e > 0) {\n        if (e & 1) ret = ret * a % mod;\n       \
    \ a = a * a % mod;\n        e >>= 1;\n    }\n    return ret;\n}\n\nlong long mod_inv(long\
    \ long a, int mod) { return mod_pow(a, mod - 2, mod); }\n\n/*\n * Discrete Logarithm\n\
    \ */\nint mod_log(long long a, long long b, int mod) {\n    // make a and mod\
    \ coprime\n    a %= mod;\n    b %= mod;\n    long long k = 1, add = 0, g;\n  \
    \  while ((g = std::gcd(a, mod)) > 1) {\n        if (b == k) return add;\n   \
    \     if (b % g) return -1;\n        b /= g;\n        mod /= g;\n        ++add;\n\
    \        k = k * a / g % mod;\n    }\n\n    // baby-step\n    const int m = std::sqrt(mod)\
    \ + 1;\n    std::unordered_map<long long, int> baby_index;\n    long long baby\
    \ = b;\n    for (int i = 0; i <= m; ++i) {\n        baby_index[baby] = i;\n  \
    \      baby = baby * a % mod;\n    }\n\n    // giant-step\n    long long am =\
    \ 1;\n    for (int i = 0; i < m; ++i) am = am * a % mod;\n    long long giant\
    \ = k;\n    for (int i = 1; i <= m; ++i) {\n        giant = giant * am % mod;\n\
    \        if (baby_index.contains(giant)) {\n            return i * m - baby_index[giant]\
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
    \  }\n    return inv;\n}"
  dependsOn:
  - math/number-theory/euler_totient.hpp
  isVerificationFile: false
  path: math/number-theory/mod_arithmetic.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_B.test.cpp
  - test/yosupo/sqrt_mod.test.cpp
  - test/yosupo/tetration_mod.test.cpp
  - test/yosupo/discrete_logarithm_mod.test.cpp
documentation_of: math/number-theory/mod_arithmetic.hpp
layout: document
title: Modular Arithmetic
---

## Description

モジュラ計算アルゴリズム詰め合わせ

## Modular Exponentiation

$a^e \mod mod$ を二分累乗法で計算する．

また，$mod$ が素数であるとき，Fermat の小定理を利用して $n$ の法 $mod$ での逆元を計算することができる．(拡張 Euclid 互除法を用いた逆元の計算では $mod$ が素数である必要がなく，定数倍速いため，基本的にはそちらを用いる)

- `long long mod_pow(long long a, long long e, int mod)`
    - $a^e \mod mod$ を計算する
    - 時間計算量: $O(\log e)$

- `long long mod_inv(long long a, int mod)`
    - $a$ の $\mod mod$ での逆元を計算する
    - 時間計算量: $O(\log mod)$

## Discrete Logarithm

離散対数を計算する．すなわち，$a^x \equiv b \mod mod$ を満たす $x$ を求める．

Baby-step giant-step 法を用いている．

- `int mod_log(long long a, long long b, int mod)`
    - $a^x \equiv b \mod mod$ を満たす $x$ を求める．存在しない場合は $-1$ を返す．
    - 時間計算量: $O(\sqrt{mod})$

## Quadratic Residue

平方剰余を計算する．すなわち，$r^2 \equiv n \mod mod$ を満たす $r$ を求める．

Tonelli-Shanks のアルゴリズムを用いている．時間計算量はよくわからない．

- `long long mod_sqrt(long long n, int mod)`
    - $r^2 \equiv n \mod mod$ を満たす $r$ を求める．$n = 0$ のときは $0$ を返す．$n$ と $mod$ が互いに素でないときと $r$ が存在しないときは$-1$ を返す．


## Modular Tetration

$a \uparrow \uparrow b \mod mod$ を再帰的に計算する．

- `long long mod_tetration(long long a, long long b, int mod)`
  - $a \uparrow \uparrow b \mod mod$ を計算する
  - 時間計算量: $O(\sqrt{mod})$

## Table of Modular Inverses

$1, 2, \dots, n$ の $\mathrm{mod}\, mod$ での逆元を計算する．

- `vector<int> mod_inv_table(int n, int mod)`
  - $1, 2, \dots, n$ の $\mathrm{mod}\,mod$ での逆元を計算する．
  - 時間計算量: $O(n)$