---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/and_or_convolution.hpp
    title: "Bitwise AND/OR Convolution (Subset/Superset Fast Zeta/M\xF6bius Transform)"
  - icon: ':question:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':question:'
    path: math/set_power_series.hpp
    title: math/set_power_series.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix/hafnian.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"math/set_power_series.hpp\"\n\n#line 2 \"convolution/subset_convolution.hpp\"\
    \n#include <array>\n#line 3 \"convolution/and_or_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nvoid fzt(std::vector<T>& a, bool subset) {\n    int k = 31 - __builtin_clz(a.size());\n\
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
    #line 5 \"math/matrix/hafnian.hpp\"\n\ntemplate <typename T, int N>\nT hafnian(std::vector<std::vector<T>>\
    \ mat) {\n    const int n = mat.size();\n    assert(n % 2 == 0);\n    const int\
    \ n2 = n / 2;\n\n    // cyc[S]: number of alternating cycles using all edges in\
    \ S\n    SetPowerSeries<T, N> cyc(1 << n2);\n\n    for (int i = 0; i < n2; ++i)\
    \ {\n        int ui = 2 * i, vi = 2 * i + 1;\n        // ui-vi=ui\n        cyc[1\
    \ << i] += mat[ui][vi];\n\n        // dp[S][v]: number of alternating paths between\
    \ ui and v\n        // using all edges in S\n        std::vector dp(1 << i, std::vector<mint>(2\
    \ * i));\n        for (int j = 0; j < i; ++j) {\n            int uj = 2 * j, vj\
    \ = 2 * j + 1;\n            dp[1 << j][uj] += mat[ui][vj];  // ui-vj=uj\n    \
    \        dp[1 << j][vj] += mat[ui][uj];  // ui-uj=vj\n        }\n\n        for\
    \ (int S = 0; S < (1 << i); ++S) {\n            for (int j = 0; j < i; ++j) {\n\
    \                int uj = 2 * j, vj = 2 * j + 1;\n                cyc[S | (1 <<\
    \ i)] +=\n                    dp[S][uj] * mat[vi][uj];  // ui-...=uj-vi=ui\n \
    \               cyc[S | (1 << i)] +=\n                    dp[S][vj] * mat[vi][vj];\
    \  // ui-...=vj-vi=ui\n\n                for (int k = 0; k < i; ++k) {\n     \
    \               if (!(S >> k & 1)) {\n                        int uk = 2 * k,\
    \ vk = 2 * k + 1;\n                        int nS = S | (1 << k);\n\n        \
    \                dp[nS][uk] +=\n                            dp[S][uj] * mat[uj][vk];\
    \  // ui-...=uj-vk=uk\n                        dp[nS][uk] +=\n               \
    \             dp[S][vj] * mat[vj][vk];  // ui-...=vj-vk=uk\n                 \
    \       dp[nS][vk] +=\n                            dp[S][uj] * mat[uj][uk];  //\
    \ ui-...=uj-uk=vk\n                        dp[nS][vk] +=\n                   \
    \         dp[S][vj] * mat[vj][uk];  // ui-...=vj-uk=vk\n                    }\n\
    \                }\n            }\n        }\n    }\n    return cyc.exp().back();\n\
    }\n"
  code: "#include <cassert>\n#include <vector>\n\n#include \"../set_power_series.hpp\"\
    \n\ntemplate <typename T, int N>\nT hafnian(std::vector<std::vector<T>> mat) {\n\
    \    const int n = mat.size();\n    assert(n % 2 == 0);\n    const int n2 = n\
    \ / 2;\n\n    // cyc[S]: number of alternating cycles using all edges in S\n \
    \   SetPowerSeries<T, N> cyc(1 << n2);\n\n    for (int i = 0; i < n2; ++i) {\n\
    \        int ui = 2 * i, vi = 2 * i + 1;\n        // ui-vi=ui\n        cyc[1 <<\
    \ i] += mat[ui][vi];\n\n        // dp[S][v]: number of alternating paths between\
    \ ui and v\n        // using all edges in S\n        std::vector dp(1 << i, std::vector<mint>(2\
    \ * i));\n        for (int j = 0; j < i; ++j) {\n            int uj = 2 * j, vj\
    \ = 2 * j + 1;\n            dp[1 << j][uj] += mat[ui][vj];  // ui-vj=uj\n    \
    \        dp[1 << j][vj] += mat[ui][uj];  // ui-uj=vj\n        }\n\n        for\
    \ (int S = 0; S < (1 << i); ++S) {\n            for (int j = 0; j < i; ++j) {\n\
    \                int uj = 2 * j, vj = 2 * j + 1;\n                cyc[S | (1 <<\
    \ i)] +=\n                    dp[S][uj] * mat[vi][uj];  // ui-...=uj-vi=ui\n \
    \               cyc[S | (1 << i)] +=\n                    dp[S][vj] * mat[vi][vj];\
    \  // ui-...=vj-vi=ui\n\n                for (int k = 0; k < i; ++k) {\n     \
    \               if (!(S >> k & 1)) {\n                        int uk = 2 * k,\
    \ vk = 2 * k + 1;\n                        int nS = S | (1 << k);\n\n        \
    \                dp[nS][uk] +=\n                            dp[S][uj] * mat[uj][vk];\
    \  // ui-...=uj-vk=uk\n                        dp[nS][uk] +=\n               \
    \             dp[S][vj] * mat[vj][vk];  // ui-...=vj-vk=uk\n                 \
    \       dp[nS][vk] +=\n                            dp[S][uj] * mat[uj][uk];  //\
    \ ui-...=uj-uk=vk\n                        dp[nS][vk] +=\n                   \
    \         dp[S][vj] * mat[vj][uk];  // ui-...=vj-uk=vk\n                    }\n\
    \                }\n            }\n        }\n    }\n    return cyc.exp().back();\n\
    }"
  dependsOn:
  - math/set_power_series.hpp
  - convolution/subset_convolution.hpp
  - convolution/and_or_convolution.hpp
  isVerificationFile: false
  path: math/matrix/hafnian.hpp
  requiredBy: []
  timestamp: '2023-12-24 17:02:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/hafnian_of_matrix.test.cpp
documentation_of: math/matrix/hafnian.hpp
layout: document
redirect_from:
- /library/math/matrix/hafnian.hpp
- /library/math/matrix/hafnian.hpp.html
title: math/matrix/hafnian.hpp
---
