---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/matrix/hafnian.hpp
    title: Hafnian
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  - icon: ':x:'
    path: set/set_power_series.hpp
    title: Set Power Series
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
    PROBLEM: https://judge.yosupo.jp/problem/hafnian_of_matrix
    links:
    - https://judge.yosupo.jp/problem/hafnian_of_matrix
  bundledCode: "#line 1 \"test/yosupo/hafnian_of_matrix.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n\n#include <bits/stdc++.h>\n\
    \n#line 4 \"math/matrix/hafnian.hpp\"\n\n#line 6 \"set/set_power_series.hpp\"\n\
    \n#line 4 \"set/subset_convolution.hpp\"\n\n#line 2 \"set/zeta_moebius_transform.hpp\"\
    \n#include <bit>\n#line 5 \"set/zeta_moebius_transform.hpp\"\n\ntemplate <typename\
    \ T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
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
    \ int)i)];\n    }\n    return ret;\n}\n#line 8 \"set/set_power_series.hpp\"\n\n\
    /**\n * @brief Set Power Series\n */\n\ntemplate <typename mint, int N>\nclass\
    \ SetPowerSeries : public std::vector<mint> {\n    using SPS = SetPowerSeries<mint,\
    \ N>;\n    using Poly = std::array<mint, N + 1>;\n\n   public:\n    using std::vector<mint>::vector;\n\
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
    \        return res;\n    }\n};\n#line 6 \"math/matrix/hafnian.hpp\"\n\ntemplate\
    \ <typename T, int N>\nT hafnian(std::vector<std::vector<T>> mat) {\n    const\
    \ int n = mat.size();\n    assert(n % 2 == 0);\n    const int n2 = n / 2;\n\n\
    \    // cyc[S]: number of alternating cycles using all edges in S\n    SetPowerSeries<T,\
    \ N> cyc(1 << n2);\n\n    for (int i = 0; i < n2; ++i) {\n        int ui = 2 *\
    \ i, vi = 2 * i + 1;\n        // ui-vi=ui\n        cyc[1 << i] += mat[ui][vi];\n\
    \n        // dp[S][v]: number of alternating paths between ui and v\n        //\
    \ using all edges in S\n        std::vector dp(1 << i, std::vector<T>(2 * i));\n\
    \        for (int j = 0; j < i; ++j) {\n            int uj = 2 * j, vj = 2 * j\
    \ + 1;\n            dp[1 << j][uj] += mat[ui][vj];  // ui-vj=uj\n            dp[1\
    \ << j][vj] += mat[ui][uj];  // ui-uj=vj\n        }\n\n        for (int S = 0;\
    \ S < (1 << i); ++S) {\n            for (int j = 0; j < i; ++j) {\n          \
    \      int uj = 2 * j, vj = 2 * j + 1;\n                cyc[S | (1 << i)] +=\n\
    \                    dp[S][uj] * mat[vi][uj];  // ui-...=uj-vi=ui\n          \
    \      cyc[S | (1 << i)] +=\n                    dp[S][vj] * mat[vi][vj];  //\
    \ ui-...=vj-vi=ui\n\n                for (int k = 0; k < i; ++k) {\n         \
    \           if (!(S >> k & 1)) {\n                        int uk = 2 * k, vk =\
    \ 2 * k + 1;\n                        int nS = S | (1 << k);\n\n             \
    \           dp[nS][uk] +=\n                            dp[S][uj] * mat[uj][vk];\
    \  // ui-...=uj-vk=uk\n                        dp[nS][uk] +=\n               \
    \             dp[S][vj] * mat[vj][vk];  // ui-...=vj-vk=uk\n                 \
    \       dp[nS][vk] +=\n                            dp[S][uj] * mat[uj][uk];  //\
    \ ui-...=uj-uk=vk\n                        dp[nS][vk] +=\n                   \
    \         dp[S][vj] * mat[vj][uk];  // ui-...=vj-uk=vk\n                    }\n\
    \                }\n            }\n        }\n    }\n    return cyc.exp().back();\n\
    }\n#line 4 \"math/modint.cpp\"\n\n/**\n * @brief Mod int\n */\ntemplate <int mod>\n\
    class Modint {\n    using mint = Modint;\n    static_assert(mod > 0, \"Modulus\
    \ must be positive\");\n\npublic:\n    static constexpr int get_mod() noexcept\
    \ { return mod; }\n\n    constexpr Modint(long long y = 0) noexcept : x(y >= 0\
    \ ? y % mod : (y % mod + mod) % mod) {}\n\n    constexpr int value() const noexcept\
    \ { return x; }\n\n    constexpr mint& operator+=(const mint& r) noexcept { if\
    \ ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr mint& operator-=(const\
    \ mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod; return *this; }\n\
    \    constexpr mint& operator*=(const mint& r) noexcept { x = static_cast<int>(1LL\
    \ * x * r.x % mod); return *this; }\n    constexpr mint& operator/=(const mint&\
    \ r) noexcept { *this *= r.inv(); return *this; }\n\n    constexpr mint operator-()\
    \ const noexcept { return mint(-x); }\n\n    constexpr mint operator+(const mint&\
    \ r) const noexcept { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const noexcept { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const noexcept { return mint(*this) *= r; }\n    constexpr mint operator/(const\
    \ mint& r) const noexcept { return mint(*this) /= r; }\n\n    constexpr bool operator==(const\
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
    \        return is;\n    }\n\nprivate:\n    int x;\n};\n#line 7 \"test/yosupo/hafnian_of_matrix.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nint main() {\n  \
    \  ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N;\n  \
    \  cin >> N;\n    vector a(N, vector<mint>(N));\n    for (int i = 0; i < N; ++i)\
    \ {\n        for (int j = 0; j < N; ++j) cin >> a[i][j];\n    }\n    cout << hafnian<mint,\
    \ 19>(a) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/hafnian_of_matrix\"\n\n\
    #include <bits/stdc++.h>\n\n#include \"../../math/matrix/hafnian.hpp\"\n#include\
    \ \"../../math/modint.cpp\"\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N;\n    cin >> N;\n    vector a(N, vector<mint>(N));\n    for (int i\
    \ = 0; i < N; ++i) {\n        for (int j = 0; j < N; ++j) cin >> a[i][j];\n  \
    \  }\n    cout << hafnian<mint, 19>(a) << endl;\n}\n"
  dependsOn:
  - math/matrix/hafnian.hpp
  - set/set_power_series.hpp
  - set/subset_convolution.hpp
  - set/zeta_moebius_transform.hpp
  - math/modint.cpp
  isVerificationFile: true
  path: test/yosupo/hafnian_of_matrix.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 12:55:13+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/hafnian_of_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/hafnian_of_matrix.test.cpp
- /verify/test/yosupo/hafnian_of_matrix.test.cpp.html
title: test/yosupo/hafnian_of_matrix.test.cpp
---
