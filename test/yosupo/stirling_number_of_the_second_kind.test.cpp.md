---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':x:'
    path: math/combination.cpp
    title: Combination
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  - icon: ':x:'
    path: math/stirling_second.hpp
    title: Stirling Number of the Second Kind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
  bundledCode: "#line 1 \"test/yosupo/stirling_number_of_the_second_kind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n\n#line 2 \"math/modint.cpp\"\n#include <iostream>\n#include <algorithm>\n\
    \n/**\n * @brief Mod int\n */\ntemplate <int mod>\nclass Modint {\n    using mint\
    \ = Modint;\n    static_assert(mod > 0, \"Modulus must be positive\");\n\npublic:\n\
    \    static constexpr int get_mod() noexcept { return mod; }\n\n    constexpr\
    \ Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod)\
    \ {}\n\n    constexpr int value() const noexcept { return x; }\n\n    constexpr\
    \ mint& operator+=(const mint& r) noexcept { if ((x += r.x) >= mod) x -= mod;\
    \ return *this; }\n    constexpr mint& operator-=(const mint& r) noexcept { if\
    \ ((x += mod - r.x) >= mod) x -= mod; return *this; }\n    constexpr mint& operator*=(const\
    \ mint& r) noexcept { x = static_cast<int>(1LL * x * r.x % mod); return *this;\
    \ }\n    constexpr mint& operator/=(const mint& r) noexcept { *this *= r.inv();\
    \ return *this; }\n\n    constexpr mint operator-() const noexcept { return mint(-x);\
    \ }\n\n    constexpr mint operator+(const mint& r) const noexcept { return mint(*this)\
    \ += r; }\n    constexpr mint operator-(const mint& r) const noexcept { return\
    \ mint(*this) -= r; }\n    constexpr mint operator*(const mint& r) const noexcept\
    \ { return mint(*this) *= r; }\n    constexpr mint operator/(const mint& r) const\
    \ noexcept { return mint(*this) /= r; }\n\n    constexpr bool operator==(const\
    \ mint& r) const noexcept { return x == r.x; }\n    constexpr bool operator!=(const\
    \ mint& r) const noexcept { return x != r.x; }\n\n    constexpr mint inv() const\
    \ noexcept {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0)\
    \ {\n            int t = a / b;\n            std::swap(a -= t * b, b);\n     \
    \       std::swap(u -= t * v, v);\n        }\n        return mint(u);\n    }\n\
    \n    constexpr mint pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend std::ostream& operator<<(std::ostream& os, const mint& r) {\n       \
    \ return os << r.x;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& r) {\n        long long t;\n        is >> t;\n        r = mint(t);\n\
    \        return is;\n    }\n\nprivate:\n    int x;\n};\n#line 2 \"math/stirling_second.hpp\"\
    \n#include <vector>\n#line 3 \"convolution/ntt.hpp\"\n\nconstexpr int get_primitive_root(int\
    \ mod) {\n    if (mod == 167772161) return 3;\n    if (mod == 469762049) return\
    \ 3;\n    if (mod == 754974721) return 11;\n    if (mod == 998244353) return 3;\n\
    \    if (mod == 1224736769) return 3;\n}\n\ntemplate <typename T>\nvoid bit_reverse(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int i = 0, j = 1; j < n - 1; ++j) {\n\
    \        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n        if (i < j) std::swap(a[i],\
    \ a[j]);\n    }\n}\n\ntemplate <typename mint>\nvoid ntt(std::vector<mint>& a,\
    \ bool ordered = false) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    int n = a.size();\n  \
    \  for (int m = n; m > 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n        for (int s = 0; s < n / m; ++s) {\n            mint w =\
    \ 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint l =\
    \ a[s * m + i];\n                mint r = a[s * m + i + m / 2];\n            \
    \    a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n\
    \                w *= omega;\n            }\n        }\n    }\n    if (ordered)\
    \ bit_reverse(a);\n}\n\ntemplate <typename mint>\nvoid intt(std::vector<mint>&\
    \ a, bool ordered = false) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    if (ordered) bit_reverse(a);\n\
    \    int n = a.size();\n    for (int m = 2; m <= n; m <<= 1) {\n        mint omega\
    \ = primitive_root.pow((mod - 1) / m).inv();\n        for (int s = 0; s < n /\
    \ m; ++s) {\n            mint w = 1;\n            for (int i = 0; i < m / 2; ++i)\
    \ {\n                mint l = a[s * m + i];\n                mint r = a[s * m\
    \ + i + m / 2] * w;\n                a[s * m + i] = l + r;\n                a[s\
    \ * m + i + m / 2] = l - r;\n                w *= omega;\n            }\n    \
    \    }\n    }\n}\n\ntemplate <typename mint>\nstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int size = a.size() + b.size() - 1;\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    ntt(a);\n    ntt(b);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n   \
    \ intt(a);\n    a.resize(size);\n    mint n_inv = mint(n).inv();\n    for (int\
    \ i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}\n#line 3 \"math/combination.cpp\"\
    \n\ntemplate <typename mint>\nclass Combination {\n   public:\n    Combination()\
    \ = default;\n    Combination(int n) : fact_(n + 1), fact_inv_(n + 1) {\n    \
    \    fact_[0] = 1;\n        for (int i = 1; i <= n; ++i) fact_[i] = fact_[i -\
    \ 1] * i;\n        fact_inv_[n]=fact_[n].inv();\n        for (int i = n; i > 0;\
    \ --i) fact_inv_[i - 1] = fact_inv_[i] * i;\n    }\n\n    mint perm(int n, int\
    \ k) const {\n        if (k < 0 || n < k) return 0;\n        return fact_[n] *\
    \ fact_inv_[n - k];\n    }\n\n    mint comb(int n, int k) const {\n        if\
    \ (k < 0 || n < k) return 0;\n        return fact_[n] * fact_inv_[k] * fact_inv_[n\
    \ - k];\n    }\n\n    mint fact(int n) const { return fact_[n]; }\n    mint fact_inv(int\
    \ n) const { return fact_inv_[n]; }\n\n   private:\n    std::vector<mint> fact_,\
    \ fact_inv_;\n};\n\ntemplate <typename T>\nT comb(long long n, int k) {\n    if\
    \ (k < 0 || n < k) return 0;\n    T num = 1, den = 1;\n    for (int i = 1; i <=\
    \ k; ++i) {\n        num = num * (n - i + 1);\n        den = den * i;\n    }\n\
    \    return num / den;\n}\n#line 5 \"math/stirling_second.hpp\"\n\ntemplate <typename\
    \ T>\nstd::vector<T> stirling_second_table(int n) {\n    T f = 1;\n    for (int\
    \ i = 1; i <= n; ++i) f *= i;\n    f = T(1) / f;\n    std::vector<T> a(n + 1),\
    \ b(n + 1);\n    for (int i = n; i >= 0; --i) {\n        a[i] = f * (i % 2 ? -1\
    \ : 1);\n        b[i] = f * T(i).pow(n);\n        f *= i;\n    }\n    auto c =\
    \ convolution(a, b);\n    return std::vector(c.begin(), c.begin() + n + 1);\n\
    }\n\ntemplate <typename T>\nT stirling_second(int n, int k) {\n    Combination<T>\
    \ comb(n);\n    T res = 0;\n    for (int i = 0; i <= k; ++i) {\n        T tmp\
    \ = comb.comb(k, i) * T(i).pow(n);\n        if ((k - i) & 1) res -= tmp;\n   \
    \     else res += tmp;\n    }\n    res /= comb.fact(k);\n    return res;\n}\n\
    #line 6 \"test/yosupo/stirling_number_of_the_second_kind.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\nusing mint =\
    \ Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n    auto ans\
    \ = stirling_second_table<mint>(N);\n    for (int i = 0; i <= N; ++i) {\n    \
    \    cout << ans[i] << (i < N ? \" \" : \"\\n\");\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n\n#include \"../../math/modint.cpp\"\n#include \"../../math/stirling_second.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    using mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n \
    \   auto ans = stirling_second_table<mint>(N);\n    for (int i = 0; i <= N; ++i)\
    \ {\n        cout << ans[i] << (i < N ? \" \" : \"\\n\");\n    }\n}\n"
  dependsOn:
  - math/modint.cpp
  - math/stirling_second.hpp
  - convolution/ntt.hpp
  - math/combination.cpp
  isVerificationFile: true
  path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  requiredBy: []
  timestamp: '2023-09-02 12:26:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/stirling_number_of_the_second_kind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp.html
title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
---
