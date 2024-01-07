---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: set/set_power_series.hpp
    title: Set Power Series
  - icon: ':question:'
    path: set/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':question:'
    path: set/zeta_moebius_transform.hpp
    title: "Fast Zeta/M\xF6bius Transform"
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
  bundledCode: "#line 2 \"math/matrix/hafnian.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"set/set_power_series.hpp\"\n#include <algorithm>\n#include\
    \ <array>\n#line 6 \"set/set_power_series.hpp\"\n\n#line 4 \"set/subset_convolution.hpp\"\
    \n\n#line 2 \"set/zeta_moebius_transform.hpp\"\n#include <bit>\n#line 5 \"set/zeta_moebius_transform.hpp\"\
    \n\ntemplate <typename T>\nvoid superset_fzt(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
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
    set/subset_convolution.hpp\"\n\ntemplate <typename T, std::size_t N>\nstd::array<T,\
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
    \ return ret;\n}\n#line 8 \"set/set_power_series.hpp\"\n\n/**\n * @brief Set Power\
    \ Series\n */\n\ntemplate <typename mint, int N>\nclass SetPowerSeries : public\
    \ std::vector<mint> {\n    using SPS = SetPowerSeries<mint, N>;\n    using Poly\
    \ = std::array<mint, N + 1>;\n\n   public:\n    using std::vector<mint>::vector;\n\
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
    }\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n#include \"../../set/set_power_series.hpp\"\
    \n\ntemplate <typename T, int N>\nT hafnian(std::vector<std::vector<T>> mat) {\n\
    \    const int n = mat.size();\n    assert(n % 2 == 0);\n    const int n2 = n\
    \ / 2;\n\n    // cyc[S]: number of alternating cycles using all edges in S\n \
    \   SetPowerSeries<T, N> cyc(1 << n2);\n\n    for (int i = 0; i < n2; ++i) {\n\
    \        int ui = 2 * i, vi = 2 * i + 1;\n        // ui-vi=ui\n        cyc[1 <<\
    \ i] += mat[ui][vi];\n\n        // dp[S][v]: number of alternating paths between\
    \ ui and v\n        // using all edges in S\n        std::vector dp(1 << i, std::vector<T>(2\
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
  - set/set_power_series.hpp
  - set/subset_convolution.hpp
  - set/zeta_moebius_transform.hpp
  isVerificationFile: false
  path: math/matrix/hafnian.hpp
  requiredBy: []
  timestamp: '2024-01-07 16:57:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/hafnian_of_matrix.test.cpp
documentation_of: math/matrix/hafnian.hpp
layout: document
title: Hafnian
---

## Description

偶数次対称行列のハフニアンを求める． $2n \times 2n$ 対称行列 $A$ のハフニアンは次式で定義される．
$$
\operatorname{haf}(A) = \sum_{\rho \in P_{2n}^2} \prod_{\{i,j\} \in \rho} A_{i,j}
$$
ここで， $P_{2n}^n$ は $\{1,2,\dots,2n\}$ の大きさ $2$ の部分集合への分割の全体である．

これは， $A$ を隣接行列として持つ無向グラフの完全マッチングの個数である．

## Operations

- `T hafnian(vector<vector<T>> mat)`
    - 与えられた偶数次対称行列のハフニアンを求める
    - 時間計算量: $O(n^2 2^{n/2})$

## Reference

- [Hafnian of Matrix - @tko919, HackMD](https://hackmd.io/@tko919/HyTPhjWco)
- [集合べき級数関連 (4) 問題例 - maspyのHP](https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b)