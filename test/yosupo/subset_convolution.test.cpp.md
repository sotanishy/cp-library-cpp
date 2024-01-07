---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  - icon: ':x:'
    path: set/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':x:'
    path: set/zeta_moebius_transform.hpp
    title: "Fast Zeta/M\xF6bius Transform"
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
    \ \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n#line 2 \"set/subset_convolution.hpp\"\
    \n#include <array>\n#include <vector>\n\n#line 2 \"set/zeta_moebius_transform.hpp\"\
    \n#include <bit>\n#include <cassert>\n#line 5 \"set/zeta_moebius_transform.hpp\"\
    \n\ntemplate <typename T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    int k = std::bit_width(a.size());\n    for (int i = 0; i < k; ++i) {\n  \
    \      for (int j = 0; j < (1 << k); ++j) {\n            if (!(j >> i & 1)) a[j]\
    \ += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid superset_fmt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    int k = std::bit_width(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if (!(j >> i & 1)) a[j] -= a[j ^ (1 << i)];\n        }\n    }\n\
    }\n\ntemplate <typename T>\nvoid subset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    int k = std::bit_width(a.size());\n    for (int i = 0; i < k; ++i) {\n  \
    \      for (int j = 0; j < (1 << k); ++j) {\n            if (j >> i & 1) a[j]\
    \ += a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename T>\nvoid subset_fmt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    int k = std::bit_width(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if (j >> i & 1) a[j] -= a[j ^ (1 << i)];\n        }\n    }\n\
    }\n#line 6 \"set/subset_convolution.hpp\"\n\ntemplate <typename T, std::size_t\
    \ N>\nstd::array<T, N>& operator+=(std::array<T, N>& lhs,\n                  \
    \           const std::array<T, N>& rhs) {\n    for (int i = 0; i < (int)N; ++i)\
    \ lhs[i] += rhs[i];\n    return lhs;\n}\n\ntemplate <typename T, std::size_t N>\n\
    std::array<T, N>& operator-=(std::array<T, N>& lhs,\n                        \
    \     const std::array<T, N>& rhs) {\n    for (int i = 0; i < (int)N; ++i) lhs[i]\
    \ -= rhs[i];\n    return lhs;\n}\n\ntemplate <typename T, int N>\nstd::vector<T>\
    \ subset_convolution(const std::vector<T>& a,\n                              \
    \    const std::vector<T>& b) {\n    using Poly = std::array<T, N + 1>;\n    const\
    \ int n = std::bit_ceil(std::max(a.size(), b.size()));\n\n    // convert to polynomials\n\
    \    std::vector<Poly> pa(n), pb(n);\n    for (int i = 0; i < (int)a.size(); ++i)\
    \ {\n        pa[i][std::popcount((unsigned int)i)] = a[i];\n    }\n    for (int\
    \ i = 0; i < (int)b.size(); ++i) {\n        pb[i][std::popcount((unsigned int)i)]\
    \ = b[i];\n    }\n\n    // bitwise or convolution\n    subset_fzt(pa);\n    subset_fzt(pb);\n\
    \    for (int i = 0; i < n; ++i) {\n        Poly pc;\n        for (int j = 0;\
    \ j <= N; ++j) {\n            for (int k = 0; k <= N - j; ++k) {\n           \
    \     pc[j + k] += pa[i][j] * pb[i][k];\n            }\n        }\n        pa[i].swap(pc);\n\
    \    }\n    subset_fmt(pa);\n\n    // convert back\n    std::vector<T> ret(n);\n\
    \    for (int i = 0; i < n; ++i) {\n        ret[i] = pa[i][std::popcount((unsigned\
    \ int)i)];\n    }\n    return ret;\n}\n#line 4 \"test/yosupo/subset_convolution.test.cpp\"\
    \n\n#include <bits/stdc++.h>\n\n#line 4 \"math/modint.cpp\"\n\n/**\n * @brief\
    \ Mod int\n */\ntemplate <int mod>\nclass Modint {\n    using mint = Modint;\n\
    \    static_assert(mod > 0, \"Modulus must be positive\");\n\npublic:\n    static\
    \ constexpr int get_mod() noexcept { return mod; }\n\n    constexpr Modint(long\
    \ long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n  \
    \  constexpr int value() const noexcept { return x; }\n\n    constexpr mint& operator+=(const\
    \ mint& r) noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr\
    \ mint& operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -=\
    \ mod; return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept\
    \ { x = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr\
    \ mint& operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\
    \n    constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
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
    \    }\n\nprivate:\n    int x;\n};\n#line 8 \"test/yosupo/subset_convolution.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 <<\
    \ N);\n    for (int i = 0; i < 1 << N; ++i) cin >> a[i];\n    for (int i = 0;\
    \ i < 1 << N; ++i) cin >> b[i];\n    auto c = subset_convolution<mint, 20>(a,\
    \ b);\n    for (int i = 0; i < 1 << N; ++i)\n        cout << c[i] << (i < (1 <<\
    \ N) - 1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include \"../../set/subset_convolution.hpp\"\n\n#include <bits/stdc++.h>\n\n\
    #include \"../../math/modint.cpp\"\nusing namespace std;\nusing ll = long long;\n\
    \nusing mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n\
    \    vector<mint> a(1 << N), b(1 << N);\n    for (int i = 0; i < 1 << N; ++i)\
    \ cin >> a[i];\n    for (int i = 0; i < 1 << N; ++i) cin >> b[i];\n    auto c\
    \ = subset_convolution<mint, 20>(a, b);\n    for (int i = 0; i < 1 << N; ++i)\n\
    \        cout << c[i] << (i < (1 << N) - 1 ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - set/subset_convolution.hpp
  - set/zeta_moebius_transform.hpp
  - math/modint.cpp
  isVerificationFile: true
  path: test/yosupo/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 12:55:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/subset_convolution.test.cpp
- /verify/test/yosupo/subset_convolution.test.cpp.html
title: test/yosupo/subset_convolution.test.cpp
---
