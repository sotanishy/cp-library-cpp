---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/number-theory/fast_prime.hpp
    title: Fast Prime Number Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/primitive_root.test.cpp
    title: test/yosupo/primitive_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/number-theory/primitive_root.hpp\"\n#include <random>\n\
    \n#line 2 \"math/number-theory/fast_prime.hpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#line 5 \"math/number-theory/fast_prime.hpp\"\n#include <vector>\n\
    \nnamespace fast_prime {\n\nclass LargeModint {\n    using mint = LargeModint;\n\
    \n   public:\n    static long long& get_mod() {\n        static long long mod\
    \ = 1;\n        return mod;\n    }\n\n    static void set_mod(long long mod) {\
    \ get_mod() = mod; }\n\n    LargeModint(long long y = 0)\n        : x(y >= 0 ?\
    \ y % get_mod() : (y % get_mod() + get_mod()) % get_mod()) {}\n\n    long long\
    \ val() const { return x; }\n\n    mint& operator+=(const mint& r) {\n       \
    \ if ((x += r.x) >= get_mod()) x -= get_mod();\n        return *this;\n    }\n\
    \    mint& operator-=(const mint& r) {\n        if ((x += get_mod() - r.x) >=\
    \ get_mod()) x -= get_mod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& r) {\n        x = static_cast<long long>((__int128_t)x * r.x % get_mod());\n\
    \        return *this;\n    }\n\n    mint operator-() const { return mint(-x);\
    \ }\n\n    mint operator+(const mint& r) const { return mint(*this) += r; }\n\
    \    mint operator-(const mint& r) const { return mint(*this) -= r; }\n    mint\
    \ operator*(const mint& r) const { return mint(*this) *= r; }\n\n    bool operator==(const\
    \ mint& r) const { return x == r.x; }\n\n    mint pow(long long n) const {\n \
    \       mint ret(1), mul(x);\n        while (n > 0) {\n            if (n & 1)\
    \ ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n    \
    \    return ret;\n    }\n\n   private:\n    long long x;\n};\n\nusing mint = LargeModint;\n\
    \nbool is_prime(long long n) {\n    if (n == 2) return true;\n    if (n == 1 ||\
    \ n % 2 == 0) return false;\n\n    mint::set_mod(n);\n    int s = 0;\n    long\
    \ long d = n - 1;\n    while (!(d & 1)) d >>= 1, ++s;\n    // https://miller-rabin.appspot.com/\n\
    \    for (mint a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n   \
    \     if (a == 0) break;\n        mint y = a.pow(d);\n        if (y == 1) continue;\n\
    \        bool probably_prime = false;\n        for (int r = 0; r < s; ++r) {\n\
    \            if (y == n - 1) {\n                probably_prime = true;\n     \
    \           break;\n            }\n            y *= y;\n        }\n        if\
    \ (!probably_prime) return false;\n    }\n    return true;\n}\n\nunsigned long\
    \ long randll(long long lb, long long ub) {\n    static std::random_device rd;\n\
    \    static std::mt19937_64 rng(rd());\n    std::uniform_int_distribution<long\
    \ long> rand(lb, ub - 1);\n    return rand(rng);\n}\n\nlong long pollards_rho(long\
    \ long n) {\n    if (n % 2 == 0) return 2;\n    if (is_prime(n)) return n;\n\n\
    \    mint::set_mod(n);\n    while (true) {\n        mint x = randll(2, n);\n \
    \       mint y = x;\n        mint c = randll(1, n);\n        long long d = 1;\n\
    \        while (d == 1) {\n            x = x * x + c;\n            y = y * y +\
    \ c;\n            y = y * y + c;\n            d = std::gcd((x - y).val(), n);\n\
    \        }\n        if (d < n) return d;\n    }\n}\n\nstd::vector<long long> prime_factor(long\
    \ long n) {\n    if (n <= 1) return {};\n    long long p = pollards_rho(n);\n\
    \    if (p == n) return {p};\n    auto l = prime_factor(p);\n    auto r = prime_factor(n\
    \ / p);\n    std::ranges::copy(r, std::back_inserter(l));\n    return l;\n}\n\n\
    }  // namespace fast_prime\n#line 5 \"math/number-theory/primitive_root.hpp\"\n\
    \nlong long primitive_root(long long p) {\n    auto prime = fast_prime::prime_factor(p\
    \ - 1);\n\n    using mint = fast_prime::LargeModint;\n    mint::set_mod(p);\n\n\
    \    std::random_device rd;\n    std::mt19937_64 rng(rd());\n    std::uniform_int_distribution<long\
    \ long> rand(1, p - 1);\n    while (true) {\n        long long x = rand(rng);\n\
    \        mint a = x;\n        bool ok = true;\n        for (auto pi : prime) {\n\
    \            if (a.pow((p - 1) / pi) == 1) {\n                ok = false;\n  \
    \              break;\n            }\n        }\n        if (ok) return a.val();\n\
    \    }\n}\n"
  code: "#pragma once\n#include <random>\n\n#include \"fast_prime.hpp\"\n\nlong long\
    \ primitive_root(long long p) {\n    auto prime = fast_prime::prime_factor(p -\
    \ 1);\n\n    using mint = fast_prime::LargeModint;\n    mint::set_mod(p);\n\n\
    \    std::random_device rd;\n    std::mt19937_64 rng(rd());\n    std::uniform_int_distribution<long\
    \ long> rand(1, p - 1);\n    while (true) {\n        long long x = rand(rng);\n\
    \        mint a = x;\n        bool ok = true;\n        for (auto pi : prime) {\n\
    \            if (a.pow((p - 1) / pi) == 1) {\n                ok = false;\n  \
    \              break;\n            }\n        }\n        if (ok) return a.val();\n\
    \    }\n}\n"
  dependsOn:
  - math/number-theory/fast_prime.hpp
  isVerificationFile: false
  path: math/number-theory/primitive_root.hpp
  requiredBy: []
  timestamp: '2024-03-02 20:34:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/primitive_root.test.cpp
documentation_of: math/number-theory/primitive_root.hpp
layout: document
title: Primitive Root
---

## Description

素数 $p$ を法とする原子根を求める．

- `long long primitive_root(long long p)`
    - 素数 $p$ を法とする原子根を求める
    - 時間計算量: $\mathrm{expected}\ O(n^{\frac{1}{4}} \log n)$

## Reference

- [原子根のアルゴリズム - 37zigenのHP](https://37zigen.com/primitive-root/)