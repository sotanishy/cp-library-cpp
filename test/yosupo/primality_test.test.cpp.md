---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/fast_prime.cpp
    title: Fast Prime Number Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/yosupo/primality_test.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/primality_test\"\n\n#include <bits/stdc++.h>\n\
    \n#line 6 \"math/fast_prime.cpp\"\n\nnamespace fast_prime {\n\nclass LargeModint\
    \ {\n    using mint = LargeModint;\n\npublic:\n    static long long& get_mod()\
    \ noexcept {\n        static long long mod = 1;\n        return mod;\n    }\n\n\
    \    static void set_mod(long long mod) {\n        get_mod() = mod;\n    }\n\n\
    \    LargeModint(long long y = 0) noexcept : x(y >= 0 ? y % get_mod() : (y % get_mod()\
    \ + get_mod()) % get_mod()) {}\n\n    long long value() const noexcept { return\
    \ x; }\n\n    mint& operator+=(const mint& r) noexcept { if ((x += r.x) >= get_mod())\
    \ x -= get_mod(); return *this; }\n    mint& operator-=(const mint& r) noexcept\
    \ { if ((x += get_mod() - r.x) >= get_mod()) x -= get_mod(); return *this; }\n\
    \    mint& operator*=(const mint& r) noexcept { x = static_cast<long long>((__int128_t)\
    \ x * r.x % get_mod()); return *this; }\n\n    mint operator-() const noexcept\
    \ { return mint(-x); }\n\n    mint operator+(const mint& r) const noexcept { return\
    \ mint(*this) += r; }\n    mint operator-(const mint& r) const noexcept { return\
    \ mint(*this) -= r; }\n    mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n\n    bool operator==(const mint& r) const noexcept { return\
    \ x == r.x; }\n    bool operator!=(const mint& r) const noexcept { return x !=\
    \ r.x; }\n\n    mint pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\nprivate:\n\
    \    long long x;\n};\n\nusing mint = LargeModint;\n\nbool is_prime(long long\
    \ n) {\n    if (n == 2) return true;\n    if (n == 1 || n % 2 == 0) return false;\n\
    \n    mint::set_mod(n);\n    int s = 0;\n    long long d = n - 1;\n    while (!(d\
    \ & 1)) d >>= 1, ++s;\n    // https://miller-rabin.appspot.com/\n    for (mint\
    \ a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\n        if (a ==\
    \ 0) break;\n        mint y = a.pow(d);\n        if (y == 1) continue;\n     \
    \   bool probably_prime = false;\n        for (int r = 0; r < s; ++r) {\n    \
    \        if (y == n - 1) {\n                probably_prime = true;\n         \
    \       break;\n            }\n            y *= y;\n        }\n        if (!probably_prime)\
    \ return false;\n    }\n    return true;\n}\n\nunsigned long long randll(long\
    \ long lb, long long ub) {\n    static std::random_device rd;\n    static std::mt19937_64\
    \ rng(rd());\n    std::uniform_int_distribution<long long> rand(lb, ub - 1);\n\
    \    return rand(rng);\n}\n\nlong long pollards_rho(long long n) {\n    if (n\
    \ % 2 == 0) return 2;\n    if (is_prime(n)) return n;\n\n    mint::set_mod(n);\n\
    \    while (true) {\n        mint x = randll(2, n);\n        mint y = x;\n   \
    \     mint c = randll(1, n);\n        long long d = 1;\n        while (d == 1)\
    \ {\n            x = x * x + c;\n            y = y * y + c;\n            y = y\
    \ * y + c;\n            d = std::gcd((x - y).value(), n);\n        }\n       \
    \ if (d < n) return d;\n    }\n}\n\nstd::vector<long long> prime_factor(long long\
    \ n) {\n    if (n <= 1) return {};\n    long long p = pollards_rho(n);\n    if\
    \ (p == n) return {p};\n    auto l = prime_factor(p);\n    auto r = prime_factor(n\
    \ / p);\n    std::copy(r.begin(), r.end(), std::back_inserter(l));\n    return\
    \ l;\n}\n\n} // namespace fast_prime\n#line 6 \"test/yosupo/primality_test.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int Q;\n    cin >> Q;\n    while (Q--) {\n     \
    \   long long N;\n        cin >> N;\n        cout << (fast_prime::is_prime(N)\
    \ ? \"Yes\" : \"No\") << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../math/fast_prime.cpp\"\nusing namespace std;\n\
    using ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int Q;\n    cin >> Q;\n    while (Q--) {\n     \
    \   long long N;\n        cin >> N;\n        cout << (fast_prime::is_prime(N)\
    \ ? \"Yes\" : \"No\") << \"\\n\";\n    }\n}"
  dependsOn:
  - math/fast_prime.cpp
  isVerificationFile: true
  path: test/yosupo/primality_test.test.cpp
  requiredBy: []
  timestamp: '2023-11-18 20:26:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/primality_test.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/primality_test.test.cpp
- /verify/test/yosupo/primality_test.test.cpp.html
title: test/yosupo/primality_test.test.cpp
---
