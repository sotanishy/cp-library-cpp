---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: math/bostan_mori.hpp
    title: Bostan-Mori Algorithm
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#line 2 \"math/modint.cpp\"\n#include <iostream>\n#include <algorithm>\n\n\
    /**\n * @brief Mod int\n */\ntemplate <int mod>\nclass Modint {\n    using mint\
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
    \        return is;\n    }\n\nprivate:\n    int x;\n};\n#line 2 \"math/bostan_mori.hpp\"\
    \n#include <vector>\n#line 3 \"convolution/ntt.hpp\"\n\nconstexpr int get_primitive_root(int\
    \ mod) {\n    if (mod == 167772161) return 3;\n    if (mod == 469762049) return\
    \ 3;\n    if (mod == 754974721) return 11;\n    if (mod == 998244353) return 3;\n\
    \    if (mod == 1224736769) return 3;\n}\n\ntemplate <typename T>\nvoid bit_reverse(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int i = 0, j = 1; j < n - 1; ++j) {\n\
    \        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n        if (i < j) std::swap(a[i],\
    \ a[j]);\n    }\n}\n\ntemplate <typename mint>\nvoid ntt(std::vector<mint>& a,\
    \ bool ordered = true) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    int n = a.size();\n  \
    \  for (int m = n; m > 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n        for (int s = 0; s < n / m; ++s) {\n            mint w =\
    \ 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint l =\
    \ a[s * m + i];\n                mint r = a[s * m + i + m / 2];\n            \
    \    a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n\
    \                w *= omega;\n            }\n        }\n    }\n    if (ordered)\
    \ bit_reverse(a);\n}\n\ntemplate <typename mint>\nvoid intt(std::vector<mint>&\
    \ a, bool ordered = true) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
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
    \    ntt(a, false);\n    ntt(b, false);\n    for (int i = 0; i < n; ++i) a[i]\
    \ *= b[i];\n    intt(a, false);\n    a.resize(size);\n    mint n_inv = mint(n).inv();\n\
    \    for (int i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}\n#line 4\
    \ \"math/bostan_mori.hpp\"\n\ntemplate <typename T>\nT bostan_mori(const std::vector<T>&\
    \ a, const std::vector<T>& c, long long n) {\n    const int d = c.size();\n  \
    \  if (n < d) return a[n];\n\n    std::vector<T> q(d + 1);\n    q[0] = 1;\n  \
    \  for (int i = 0; i < d; ++i) q[i + 1] = -c[i];\n    auto p = convolution(a,\
    \ q);\n    p.resize(d);\n\n    auto take = [&](const std::vector<T>& p, int s)\
    \ {\n        std::vector<T> r((p.size() + 1) / 2);\n        for (int i = 0; i\
    \ < (int) r.size(); ++i) {\n            r[i] = p[2 * i + s];\n        }\n    \
    \    return r;\n    };\n\n    while (n > 0) {\n        auto qm = q;\n        for\
    \ (int i = 1; i < (int) qm.size(); i += 2) qm[i] = -qm[i];\n        p = take(convolution(p,\
    \ qm), n & 1);\n        q = take(convolution(q, qm), 0);\n        n >>= 1;\n \
    \   }\n\n    return p[0] / q[0];\n}\n#line 5 \"test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int d;\n    long long k;\n    cin >> d >> k;\n    vector<mint> a(d), c(d);\n\
    \    for (auto& x : a) cin >> x;\n    for (auto& x : c) cin >> x;\n    cout <<\
    \ bostan_mori(a, c, k) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include \"../../math/modint.cpp\"\n#include \"../../math/bostan_mori.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int d;\n    long long k;\n    cin >> d >> k;\n    vector<mint> a(d), c(d);\n\
    \    for (auto& x : a) cin >> x;\n    for (auto& x : c) cin >> x;\n    cout <<\
    \ bostan_mori(a, c, k) << endl;\n}\n"
  dependsOn:
  - math/modint.cpp
  - math/bostan_mori.hpp
  - convolution/ntt.hpp
  isVerificationFile: true
  path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  requiredBy: []
  timestamp: '2022-06-27 16:41:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
- /verify/test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp.html
title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
---
