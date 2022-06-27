---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/and_or_convolution.hpp
    title: "Bitwise AND/OR Convolution (Subset/Superset Fast Zeta/M\xF6bius Transform)"
  - icon: ':x:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/yosupo/subset_convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n#line 2 \"math/modint.cpp\"\
    \n#include <iostream>\n#include <algorithm>\n\n\n/**\n * @brief Mod int\n */\n\
    template <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod\
    \ > 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
    \ noexcept { return mod; }\n\n    constexpr Modint(long long y = 0) noexcept :\
    \ x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n    constexpr int value()\
    \ const noexcept { return x; }\n\n    constexpr mint& operator+=(const mint& r)\
    \ noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr mint&\
    \ operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod;\
    \ return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept { x\
    \ = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr mint&\
    \ operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\n \
    \   constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
    \ mint operator+(const mint& r) const noexcept { return mint(*this) += r; }\n\
    \    constexpr mint operator-(const mint& r) const noexcept { return mint(*this)\
    \ -= r; }\n    constexpr mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n    constexpr mint operator/(const mint& r) const noexcept\
    \ { return mint(*this) /= r; }\n\n    constexpr bool operator==(const mint& r)\
    \ const noexcept { return x == r.x; }\n    constexpr bool operator!=(const mint&\
    \ r) const noexcept { return x != r.x; }\n\n    constexpr mint inv() const noexcept\
    \ {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0) {\n    \
    \        int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n        while\
    \ (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n   \
    \         n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\nprivate:\n    int x;\n};\n#line 2 \"convolution/subset_convolution.hpp\"\
    \n#include <array>\n#include <vector>\n#line 3 \"convolution/and_or_convolution.hpp\"\
    \n\ntemplate <typename T>\nvoid fzt(std::vector<T>& a, bool subset) {\n    int\
    \ k = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i) {\n     \
    \   for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1) == subset)\
    \ a[j] += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid\
    \ fmt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if ((j >> i & 1) == subset) a[j] -= a[j ^ (1 << i)];\n      \
    \  }\n    }\n}\n\ntemplate <typename T>\nstd::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int size = std::max(a.size(), b.size());\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    fzt(a, true);\n    fzt(b, true);\n    for (int i = 0; i < n; ++i) a[i] *=\
    \ b[i];\n    fmt(a, true);\n    return a;\n}\n\ntemplate <typename T>\nstd::vector<T>\
    \ and_convolution(std::vector<T> a, std::vector<T> b) {\n    int size = std::max(a.size(),\
    \ b.size());\n    int n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n\
    \    b.resize(n);\n    fzt(a, false);\n    fzt(b, false);\n    for (int i = 0;\
    \ i < n; ++i) a[i] *= b[i];\n    fmt(a, false);\n    return a;\n}\n#line 5 \"\
    convolution/subset_convolution.hpp\"\n\ntemplate <typename T, std::size_t N>\n\
    std::array<T, N>& operator+=(std::array<T, N>& lhs, const std::array<T, N>& rhs)\
    \ {\n    for (int i = 0; i < (int) N; ++i) lhs[i] += rhs[i];\n    return lhs;\n\
    }\n\ntemplate <typename T, std::size_t N>\nstd::array<T, N>& operator-=(std::array<T,\
    \ N>& lhs, const std::array<T, N>& rhs) {\n    for (int i = 0; i < (int) N; ++i)\
    \ lhs[i] -= rhs[i];\n    return lhs;\n}\n\ntemplate <typename T, int N>\nstd::vector<T>\
    \ subset_convolution(const std::vector<T>& a, const std::vector<T>& b) {\n   \
    \ using Poly = std::array<T, N + 1>;\n    int size = std::max(a.size(), b.size());\n\
    \    int n = 1;\n    while (n < size) n <<= 1;\n\n    // convert to polynomials\n\
    \    std::vector<Poly> pa(n), pb(n);\n    for (int i = 0; i < (int) a.size();\
    \ ++i) {\n        pa[i][__builtin_popcount(i)] = a[i];\n    }\n    for (int i\
    \ = 0; i < (int) b.size(); ++i) {\n        pb[i][__builtin_popcount(i)] = b[i];\n\
    \    }\n\n    // bitwise or convolution\n    fzt(pa, true);\n    fzt(pb, true);\n\
    \    for (int i = 0; i < n; ++i) {\n        Poly pc;\n        for (int j = 0;\
    \ j <= N; ++j) {\n            for (int k = 0; k <= N - j; ++k) {\n           \
    \     pc[j + k] += pa[i][j] * pb[i][k];\n            }\n        }\n        pa[i].swap(pc);\n\
    \    }\n    fmt(pa, true);\n\n    // convert back\n    std::vector<T> ret(n);\n\
    \    for (int i = 0; i < n; ++i) {\n        ret[i] = pa[i][__builtin_popcount(i)];\n\
    \    }\n    return ret;\n}\n\n#line 5 \"test/yosupo/subset_convolution.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    using mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n \
    \   vector<mint> a(1<<N), b(1<<N);\n    for (int i = 0; i < 1 << N; ++i) cin >>\
    \ a[i];\n    for (int i = 0; i < 1 << N; ++i) cin >> b[i];\n    auto c = subset_convolution<mint,\
    \ 20>(a, b);\n    for (int i = 0; i < 1 << N; ++i) cout << c[i] << (i < (1<<N)-1\
    \ ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include \"../../math/modint.cpp\"\n#include \"../../convolution/subset_convolution.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    using mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n \
    \   vector<mint> a(1<<N), b(1<<N);\n    for (int i = 0; i < 1 << N; ++i) cin >>\
    \ a[i];\n    for (int i = 0; i < 1 << N; ++i) cin >> b[i];\n    auto c = subset_convolution<mint,\
    \ 20>(a, b);\n    for (int i = 0; i < 1 << N; ++i) cout << c[i] << (i < (1<<N)-1\
    \ ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - math/modint.cpp
  - convolution/subset_convolution.hpp
  - convolution/and_or_convolution.hpp
  isVerificationFile: true
  path: test/yosupo/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-06-27 14:39:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/subset_convolution.test.cpp
- /verify/test/yosupo/subset_convolution.test.cpp.html
title: test/yosupo/subset_convolution.test.cpp
---
