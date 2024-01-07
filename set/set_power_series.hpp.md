---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: set/subset_convolution.hpp
    title: Subset Convolution
  - icon: ':x:'
    path: set/zeta_moebius_transform.hpp
    title: "Fast Zeta/M\xF6bius Transform"
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/matrix/hafnian.hpp
    title: Hafnian
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/exp_of_set_power_series.test.cpp
    title: test/yosupo/exp_of_set_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Set Power Series
    links: []
  bundledCode: "#line 2 \"set/set_power_series.hpp\"\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <vector>\n\n#line 4 \"set/subset_convolution.hpp\"\
    \n\n#line 2 \"set/zeta_moebius_transform.hpp\"\n#include <bit>\n#line 5 \"set/zeta_moebius_transform.hpp\"\
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
    \        return res;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <vector>\n\n#include \"subset_convolution.hpp\"\n\n/**\n * @brief Set\
    \ Power Series\n */\n\ntemplate <typename mint, int N>\nclass SetPowerSeries :\
    \ public std::vector<mint> {\n    using SPS = SetPowerSeries<mint, N>;\n    using\
    \ Poly = std::array<mint, N + 1>;\n\n   public:\n    using std::vector<mint>::vector;\n\
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
    \        return res;\n    }\n};"
  dependsOn:
  - set/subset_convolution.hpp
  - set/zeta_moebius_transform.hpp
  isVerificationFile: false
  path: set/set_power_series.hpp
  requiredBy:
  - math/matrix/hafnian.hpp
  timestamp: '2024-01-07 12:55:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/exp_of_set_power_series.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
documentation_of: set/set_power_series.hpp
layout: document
redirect_from:
- /library/set/set_power_series.hpp
- /library/set/set_power_series.hpp.html
title: Set Power Series
---
