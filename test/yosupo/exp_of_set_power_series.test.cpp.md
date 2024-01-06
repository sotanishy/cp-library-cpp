---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/and_or_convolution.hpp
    title: "Bitwise AND/OR Convolution (Subset/Superset Fast Zeta/M\xF6bius Transform)"
  - icon: ':heavy_check_mark:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: Mod int
  - icon: ':heavy_check_mark:'
    path: math/set_power_series.hpp
    title: math/set_power_series.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_set_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_set_power_series
  bundledCode: "#line 1 \"test/yosupo/exp_of_set_power_series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 4 \"math/modint.cpp\"\n\n/**\n * @brief Mod int\n */\n\
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
    \    }\n\nprivate:\n    int x;\n};\n#line 2 \"math/set_power_series.hpp\"\n\n\
    #line 3 \"convolution/and_or_convolution.hpp\"\n\ntemplate <typename T>\nvoid\
    \ fzt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
    \    for (int i = 0; i < k; ++i) {\n        for (int j = 0; j < (1 << k); ++j)\
    \ {\n            if ((j >> i & 1) == subset) a[j] += a[j ^ (1 << i)];\n      \
    \  }\n    }\n}\n\ntemplate <typename T>\nvoid fmt(std::vector<T>& a, bool subset)\
    \ {\n    int k = 31 - __builtin_clz(a.size());\n    for (int i = 0; i < k; ++i)\
    \ {\n        for (int j = 0; j < (1 << k); ++j) {\n            if ((j >> i & 1)\
    \ == subset) a[j] -= a[j ^ (1 << i)];\n        }\n    }\n}\n\ntemplate <typename\
    \ T>\nstd::vector<T> or_convolution(std::vector<T> a, std::vector<T> b) {\n  \
    \  int size = std::max(a.size(), b.size());\n    int n = 1;\n    while (n < size)\
    \ n <<= 1;\n    a.resize(n);\n    b.resize(n);\n    fzt(a, true);\n    fzt(b,\
    \ true);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    fmt(a, true);\n \
    \   return a;\n}\n\ntemplate <typename T>\nstd::vector<T> and_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    int size = std::max(a.size(), b.size());\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    fzt(a, false);\n    fzt(b, false);\n    for (int i = 0; i < n; ++i) a[i]\
    \ *= b[i];\n    fmt(a, false);\n    return a;\n}\n#line 5 \"convolution/subset_convolution.hpp\"\
    \n\ntemplate <typename T, std::size_t N>\nstd::array<T, N>& operator+=(std::array<T,\
    \ N>& lhs, const std::array<T, N>& rhs) {\n    for (int i = 0; i < (int) N; ++i)\
    \ lhs[i] += rhs[i];\n    return lhs;\n}\n\ntemplate <typename T, std::size_t N>\n\
    std::array<T, N>& operator-=(std::array<T, N>& lhs, const std::array<T, N>& rhs)\
    \ {\n    for (int i = 0; i < (int) N; ++i) lhs[i] -= rhs[i];\n    return lhs;\n\
    }\n\ntemplate <typename T, int N>\nstd::vector<T> subset_convolution(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    using Poly = std::array<T, N + 1>;\n    int\
    \ size = std::max(a.size(), b.size());\n    int n = 1;\n    while (n < size) n\
    \ <<= 1;\n\n    // convert to polynomials\n    std::vector<Poly> pa(n), pb(n);\n\
    \    for (int i = 0; i < (int) a.size(); ++i) {\n        pa[i][__builtin_popcount(i)]\
    \ = a[i];\n    }\n    for (int i = 0; i < (int) b.size(); ++i) {\n        pb[i][__builtin_popcount(i)]\
    \ = b[i];\n    }\n\n    // bitwise or convolution\n    fzt(pa, true);\n    fzt(pb,\
    \ true);\n    for (int i = 0; i < n; ++i) {\n        Poly pc;\n        for (int\
    \ j = 0; j <= N; ++j) {\n            for (int k = 0; k <= N - j; ++k) {\n    \
    \            pc[j + k] += pa[i][j] * pb[i][k];\n            }\n        }\n   \
    \     pa[i].swap(pc);\n    }\n    fmt(pa, true);\n\n    // convert back\n    std::vector<T>\
    \ ret(n);\n    for (int i = 0; i < n; ++i) {\n        ret[i] = pa[i][__builtin_popcount(i)];\n\
    \    }\n    return ret;\n}\n\n#line 4 \"math/set_power_series.hpp\"\n\ntemplate\
    \ <typename mint, int N>\nclass SetPowerSeries : public std::vector<mint> {\n\
    \    using SPS = SetPowerSeries<mint, N>;\n    using Poly = std::array<mint, N\
    \ + 1>;\n\n   public:\n    using std::vector<mint>::vector;\n    using std::vector<mint>::operator=;\n\
    \n    // -- binary operation with scalar ---\n    SPS& operator+=(const mint&\
    \ rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] += rhs;\n\
    \        return *this;\n    }\n\n    SPS& operator-=(const mint& rhs) {\n    \
    \    if (this->empty()) this->resize(1);\n        (*this)[0] -= rhs;\n       \
    \ return *this;\n    }\n\n    SPS& operator*=(const mint& rhs) {\n        for\
    \ (auto& x : *this) x *= rhs;\n        return *this;\n    }\n\n    SPS& operator/=(const\
    \ mint& rhs) { return *this *= rhs.inv(); }\n\n    SPS operator+(const mint& rhs)\
    \ const { return SPS(*this) += rhs; }\n    SPS operator-(const mint& rhs) const\
    \ { return SPS(*this) -= rhs; }\n    SPS operator*(const mint& rhs) const { return\
    \ SPS(*this) *= rhs; }\n    SPS operator/(const mint& rhs) const { return SPS(*this)\
    \ /= rhs; }\n\n    // --- binary operation with SPS ---\n\n    SPS& operator+=(const\
    \ SPS& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] += rhs[i];\n   \
    \     return *this;\n    }\n\n    SPS& operator-=(const SPS& rhs) {\n        if\
    \ (this->size() < rhs.size()) this->resize(rhs.size());\n        for (int i =\
    \ 0; i < (int)rhs.size(); ++i) (*this)[i] -= rhs[i];\n        return *this;\n\
    \    }\n\n    SPS& operator*=(const SPS& rhs) {\n        *this = subset_convolution<mint,\
    \ N>(*this, rhs);\n        return *this;\n    }\n\n    SPS operator+(const SPS&\
    \ rhs) const { return SPS(*this) += rhs; }\n    SPS operator-(const SPS& rhs)\
    \ const { return SPS(*this) -= rhs; }\n    SPS operator*(const SPS& rhs) const\
    \ { return SPS(*this) *= rhs; }\n\n    // --- compositions ---\n    SPS exp()\
    \ const {\n        assert((*this)[0] == mint(0));\n        int n = 0;\n      \
    \  while (1 << n < (int)this->size()) ++n;\n        SPS res(1 << n);\n       \
    \ res[0] = 1;\n        for (int i = 0; i < n; ++i) {\n            SPS a(this->begin()\
    \ + (1 << i), this->begin() + (1 << (i + 1)));\n            SPS b(res.begin(),\
    \ res.begin() + (1 << i));\n            a *= b;\n            std::copy(a.begin(),\
    \ a.end(), res.begin() + (1 << i));\n        }\n        return res;\n    }\n};\n\
    #line 7 \"test/yosupo/exp_of_set_power_series.test.cpp\"\nusing namespace std;\n\
    using ll = long long;\n\nusing mint = Modint<998244353>;\n\nint main() {\n   \
    \ int N;\n    cin >> N;\n    SetPowerSeries<mint, 20> b(1 << N);\n    for (int\
    \ i = 0; i < 1 << N; ++i) cin >> b[i];\n    auto c = b.exp();\n    for (int i\
    \ = 0; i < 1 << N; ++i)\n        cout << c[i] << (i < (1 << N) - 1 ? \" \" : \"\
    \\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/modint.cpp\"\n#include \"\
    ../../math/set_power_series.hpp\"\nusing namespace std;\nusing ll = long long;\n\
    \nusing mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n\
    \    SetPowerSeries<mint, 20> b(1 << N);\n    for (int i = 0; i < 1 << N; ++i)\
    \ cin >> b[i];\n    auto c = b.exp();\n    for (int i = 0; i < 1 << N; ++i)\n\
    \        cout << c[i] << (i < (1 << N) - 1 ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - math/modint.cpp
  - math/set_power_series.hpp
  - convolution/subset_convolution.hpp
  - convolution/and_or_convolution.hpp
  isVerificationFile: true
  path: test/yosupo/exp_of_set_power_series.test.cpp
  requiredBy: []
  timestamp: '2023-12-24 17:02:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/exp_of_set_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/exp_of_set_power_series.test.cpp
- /verify/test/yosupo/exp_of_set_power_series.test.cpp.html
title: test/yosupo/exp_of_set_power_series.test.cpp
---
