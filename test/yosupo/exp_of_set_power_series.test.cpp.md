---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: Mod int
  - icon: ':heavy_check_mark:'
    path: math/set/set_power_series.hpp
    title: Set Power Series
  - icon: ':heavy_check_mark:'
    path: math/set/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':heavy_check_mark:'
    path: math/set/zeta_moebius_transform.hpp
    title: math/set/zeta_moebius_transform.hpp
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
    \ <bits/stdc++.h>\n\n#line 4 \"math/modint.hpp\"\n\n/**\n * @brief Mod int\n */\n\
    template <int m>\nclass Modint {\n    using mint = Modint;\n    static_assert(m\
    \ > 0, \"Modulus must be positive\");\n\n   public:\n    static constexpr int\
    \ mod() { return m; }\n\n    constexpr Modint(long long y = 0) : x(y >= 0 ? y\
    \ % m : (y % m + m) % m) {}\n\n    constexpr int val() const { return x; }\n\n\
    \    constexpr mint& operator+=(const mint& r) {\n        if ((x += r.x) >= m)\
    \ x -= m;\n        return *this;\n    }\n    constexpr mint& operator-=(const\
    \ mint& r) {\n        if ((x += m - r.x) >= m) x -= m;\n        return *this;\n\
    \    }\n    constexpr mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL\
    \ * x * r.x % m);\n        return *this;\n    }\n    constexpr mint& operator/=(const\
    \ mint& r) { return *this *= r.inv(); }\n\n    constexpr bool operator==(const\
    \ mint& r) const { return x == r.x; }\n\n    constexpr mint operator+() const\
    \ { return *this; }\n    constexpr mint operator-() const { return mint(-x); }\n\
    \n    constexpr friend mint operator+(const mint& l, const mint& r) {\n      \
    \  return mint(l) += r;\n    }\n    constexpr friend mint operator-(const mint&\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(const mint& l, const mint& r) {\n        return mint(l) *= r;\n\
    \    }\n    constexpr friend mint operator/(const mint& l, const mint& r) {\n\
    \        return mint(l) /= r;\n    }\n\n    constexpr mint inv() const {\n   \
    \     int a = x, b = m, u = 1, v = 0;\n        while (b > 0) {\n            int\
    \ t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u -=\
    \ t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const {\n        mint ret(1), mul(x);\n        while (n > 0)\
    \ {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\n   private:\n    int x;\n};\n#line 6 \"math/set/set_power_series.hpp\"\
    \n\n#line 4 \"math/set/subset_convolution.hpp\"\n\n#line 2 \"math/set/zeta_moebius_transform.hpp\"\
    \n#include <bit>\n#line 5 \"math/set/zeta_moebius_transform.hpp\"\n\ntemplate\
    \ <typename T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j] += a[j | i];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid superset_fmt(std::vector<T>&\
    \ a) {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j] -= a[j | i];\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid subset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for\
    \ (int j = 0; j < n; ++j) {\n            if (!(j & i)) a[j | i] += a[j];\n   \
    \     }\n    }\n}\n\ntemplate <typename T>\nvoid subset_fmt(std::vector<T>& a)\
    \ {\n    assert(std::has_single_bit(a.size()));\n    const int n = a.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; ++j) {\n\
    \            if (!(j & i)) a[j | i] -= a[j];\n        }\n    }\n}\n#line 6 \"\
    math/set/subset_convolution.hpp\"\n\ntemplate <typename T, std::size_t N>\nstd::array<T,\
    \ N>& operator+=(std::array<T, N>& lhs,\n                             const std::array<T,\
    \ N>& rhs) {\n    for (int i = 0; i < (int)N; ++i) lhs[i] += rhs[i];\n    return\
    \ lhs;\n}\n\ntemplate <typename T, std::size_t N>\nstd::array<T, N>& operator-=(std::array<T,\
    \ N>& lhs,\n                             const std::array<T, N>& rhs) {\n    for\
    \ (int i = 0; i < (int)N; ++i) lhs[i] -= rhs[i];\n    return lhs;\n}\n\ntemplate\
    \ <typename T, int N>\nstd::vector<T> subset_convolution(const std::vector<T>&\
    \ a,\n                                  const std::vector<T>& b) {\n    using\
    \ Poly = std::array<T, N + 1>;\n    const int n = std::bit_ceil(std::max(a.size(),\
    \ b.size()));\n\n    // convert to polynomials\n    std::vector<Poly> pa(n), pb(n);\n\
    \    for (int i = 0; i < (int)a.size(); ++i) {\n        pa[i][std::popcount((unsigned\
    \ int)i)] = a[i];\n    }\n    for (int i = 0; i < (int)b.size(); ++i) {\n    \
    \    pb[i][std::popcount((unsigned int)i)] = b[i];\n    }\n\n    // bitwise or\
    \ convolution\n    subset_fzt(pa);\n    subset_fzt(pb);\n    for (int i = 0; i\
    \ < n; ++i) {\n        Poly pc;\n        for (int j = 0; j <= N; ++j) {\n    \
    \        for (int k = 0; k <= N - j; ++k) {\n                pc[j + k] += pa[i][j]\
    \ * pb[i][k];\n            }\n        }\n        pa[i].swap(pc);\n    }\n    subset_fmt(pa);\n\
    \n    // convert back\n    std::vector<T> ret(n);\n    for (int i = 0; i < n;\
    \ ++i) {\n        ret[i] = pa[i][std::popcount((unsigned int)i)];\n    }\n   \
    \ return ret;\n}\n#line 8 \"math/set/set_power_series.hpp\"\n\n/**\n * @brief\
    \ Set Power Series\n */\n\ntemplate <typename mint, int N>\nclass SetPowerSeries\
    \ : public std::vector<mint> {\n    using SPS = SetPowerSeries<mint, N>;\n   \
    \ using Poly = std::array<mint, N + 1>;\n\n   public:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::operator=;\n\n    // -- binary operation with scalar\
    \ ---\n\n    SPS& operator+=(const mint& rhs) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += rhs;\n        return *this;\n    }\n\n    SPS& operator-=(const\
    \ mint& rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= rhs;\n        return *this;\n    }\n\n    SPS& operator*=(const mint& rhs)\
    \ {\n        for (auto& x : *this) x *= rhs;\n        return *this;\n    }\n\n\
    \    SPS& operator/=(const mint& rhs) { return *this *= rhs.inv(); }\n\n    SPS\
    \ operator+(const mint& rhs) const { return SPS(*this) += rhs; }\n    SPS operator-(const\
    \ mint& rhs) const { return SPS(*this) -= rhs; }\n    SPS operator*(const mint&\
    \ rhs) const { return SPS(*this) *= rhs; }\n    SPS operator/(const mint& rhs)\
    \ const { return SPS(*this) /= rhs; }\n\n    // --- binary operation with SPS\
    \ ---\n\n    SPS& operator+=(const SPS& rhs) {\n        if (this->size() < rhs.size())\
    \ this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size(); ++i)\
    \ (*this)[i] += rhs[i];\n        return *this;\n    }\n\n    SPS& operator-=(const\
    \ SPS& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] -= rhs[i];\n   \
    \     return *this;\n    }\n\n    SPS& operator*=(const SPS& rhs) {\n        *this\
    \ = subset_convolution<mint, N>(*this, rhs);\n        return *this;\n    }\n\n\
    \    SPS operator+(const SPS& rhs) const { return SPS(*this) += rhs; }\n    SPS\
    \ operator-(const SPS& rhs) const { return SPS(*this) -= rhs; }\n    SPS operator*(const\
    \ SPS& rhs) const { return SPS(*this) *= rhs; }\n\n    // --- compositions ---\n\
    \n    SPS exp() const {\n        assert((*this)[0] == mint(0));\n        const\
    \ int n = std::bit_width(std::bit_ceil(this->size())) - 1;\n        SPS res(1\
    \ << n);\n        res[0] = 1;\n        for (int i = 0; i < n; ++i) {\n       \
    \     SPS a(this->begin() + (1 << i), this->begin() + (1 << (i + 1)));\n     \
    \       SPS b(res.begin(), res.begin() + (1 << i));\n            a *= b;\n   \
    \         std::copy(a.begin(), a.end(), res.begin() + (1 << i));\n        }\n\
    \        return res;\n    }\n};\n#line 7 \"test/yosupo/exp_of_set_power_series.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    int N;\n    cin >> N;\n    SetPowerSeries<mint, 20> b(1 <<\
    \ N);\n    for (int i = 0; i < 1 << N; ++i) cin >> b[i];\n    auto c = b.exp();\n\
    \    for (int i = 0; i < 1 << N; ++i)\n        cout << c[i] << (i < (1 << N) -\
    \ 1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/modint.hpp\"\n#include \"\
    ../../math/set/set_power_series.hpp\"\nusing namespace std;\nusing ll = long long;\n\
    \nusing mint = Modint<998244353>;\n\nint main() {\n    int N;\n    cin >> N;\n\
    \    SetPowerSeries<mint, 20> b(1 << N);\n    for (int i = 0; i < 1 << N; ++i)\
    \ cin >> b[i];\n    auto c = b.exp();\n    for (int i = 0; i < 1 << N; ++i)\n\
    \        cout << c[i] << (i < (1 << N) - 1 ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - math/modint.hpp
  - math/set/set_power_series.hpp
  - math/set/subset_convolution.hpp
  - math/set/zeta_moebius_transform.hpp
  isVerificationFile: true
  path: test/yosupo/exp_of_set_power_series.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/exp_of_set_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/exp_of_set_power_series.test.cpp
- /verify/test/yosupo/exp_of_set_power_series.test.cpp.html
title: test/yosupo/exp_of_set_power_series.test.cpp
---
