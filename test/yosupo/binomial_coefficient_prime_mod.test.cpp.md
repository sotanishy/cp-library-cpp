---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/arbitrary_modint.hpp
    title: Arbitrary Mod int
  - icon: ':question:'
    path: math/combination.cpp
    title: Combination
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/yosupo/binomial_coefficient_prime_mod.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <bits/stdc++.h>\n\n#line 5 \"math/arbitrary_modint.hpp\"\n\n/**\n\
    \ * @brief Arbitrary Mod int\n */\nclass ArbitraryModint {\n    using mint = ArbitraryModint;\n\
    \n   public:\n    static int& mod() {\n        static int mod_ = 1;\n        return\
    \ mod_;\n    }\n\n    static void set_mod(int mod_) {\n        assert(mod_ > 0);\n\
    \        mod() = mod_;\n    }\n\n    ArbitraryModint(long long y = 0)\n      \
    \  : x(y >= 0 ? y % mod() : (y % mod() + mod()) % mod()) {}\n\n    int val() const\
    \ { return x; }\n\n    mint& operator+=(const mint& r) {\n        if ((x += r.x)\
    \ >= mod()) x -= mod();\n        return *this;\n    }\n    mint& operator-=(const\
    \ mint& r) {\n        if ((x += mod() - r.x) >= mod()) x -= mod();\n        return\
    \ *this;\n    }\n    mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL\
    \ * x * r.x % mod());\n        return *this;\n    }\n    mint& operator/=(const\
    \ mint& r) { return *this *= r.inv(); }\n\n    bool operator==(const mint& r)\
    \ const { return x == r.x; }\n\n    mint operator+() const { return *this; }\n\
    \    mint operator-() const { return mint(-x); }\n\n    friend mint operator+(const\
    \ mint& l, const mint& r) { return mint(l) += r; }\n    friend mint operator-(const\
    \ mint& l, const mint& r) { return mint(l) -= r; }\n    friend mint operator*(const\
    \ mint& l, const mint& r) { return mint(l) *= r; }\n    friend mint operator/(const\
    \ mint& l, const mint& r) { return mint(l) /= r; }\n\n    mint inv() const {\n\
    \        int a = x, b = mod(), u = 1, v = 0;\n        while (b > 0) {\n      \
    \      int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return mint(u);\n    }\n\n    mint pow(long\
    \ long n) const {\n        mint ret(1), mul(x);\n        while (n > 0) {\n   \
    \         if (n & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return ret;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& r) {\n        return os << r.x;\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& r) {\n        long long t;\n        is >>\
    \ t;\n        r = mint(t);\n        return is;\n    }\n\n   private:\n    int\
    \ x;\n};\n#line 3 \"math/combination.cpp\"\n\ntemplate <typename mint>\nclass\
    \ Combination {\n   public:\n    Combination() = default;\n    Combination(int\
    \ n) : fact_(n + 1), fact_inv_(n + 1) {\n        fact_[0] = 1;\n        for (int\
    \ i = 1; i <= n; ++i) fact_[i] = fact_[i - 1] * i;\n        fact_inv_[n]=fact_[n].inv();\n\
    \        for (int i = n; i > 0; --i) fact_inv_[i - 1] = fact_inv_[i] * i;\n  \
    \  }\n\n    mint perm(int n, int k) const {\n        if (k < 0 || n < k) return\
    \ 0;\n        return fact_[n] * fact_inv_[n - k];\n    }\n\n    mint comb(int\
    \ n, int k) const {\n        if (k < 0 || n < k) return 0;\n        return fact_[n]\
    \ * fact_inv_[k] * fact_inv_[n - k];\n    }\n\n    mint fact(int n) const { return\
    \ fact_[n]; }\n    mint fact_inv(int n) const { return fact_inv_[n]; }\n\n   private:\n\
    \    std::vector<mint> fact_, fact_inv_;\n};\n\ntemplate <typename T>\nT comb(long\
    \ long n, int k) {\n    if (k < 0 || n < k) return 0;\n    T num = 1, den = 1;\n\
    \    for (int i = 1; i <= k; ++i) {\n        num = num * (n - i + 1);\n      \
    \  den = den * i;\n    }\n    return num / den;\n}\n#line 7 \"test/yosupo/binomial_coefficient_prime_mod.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nusing mint = ArbitraryModint;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int T, m;\n    cin >> T >> m;\n    mint::set_mod(m);\n    Combination<mint>\
    \ comb(min(m, (int)1e7) - 1);\n\n    while (T--) {\n        int n, k;\n      \
    \  cin >> n >> k;\n        cout << comb.comb(n, k) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/arbitrary_modint.hpp\"\n\
    #include \"../../math/combination.cpp\"\nusing namespace std;\nusing ll = long\
    \ long;\n\nusing mint = ArbitraryModint;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int T, m;\n    cin >> T >> m;\n    mint::set_mod(m);\n\
    \    Combination<mint> comb(min(m, (int)1e7) - 1);\n\n    while (T--) {\n    \
    \    int n, k;\n        cin >> n >> k;\n        cout << comb.comb(n, k) << \"\\\
    n\";\n    }\n}"
  dependsOn:
  - math/arbitrary_modint.hpp
  - math/combination.cpp
  isVerificationFile: true
  path: test/yosupo/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:49:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/binomial_coefficient_prime_mod.test.cpp
- /verify/test/yosupo/binomial_coefficient_prime_mod.test.cpp.html
title: test/yosupo/binomial_coefficient_prime_mod.test.cpp
---
