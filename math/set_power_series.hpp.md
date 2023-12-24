---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/and_or_convolution.hpp
    title: "Bitwise AND/OR Convolution (Subset/Superset Fast Zeta/M\xF6bius Transform)"
  - icon: ':question:'
    path: convolution/subset_convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/matrix/hafnian.hpp
    title: math/matrix/hafnian.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_set_power_series.test.cpp
    title: test/yosupo/exp_of_set_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/hafnian_of_matrix.test.cpp
    title: test/yosupo/hafnian_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/set_power_series.hpp\"\n#include <vector>\n\n#line\
    \ 2 \"convolution/subset_convolution.hpp\"\n#include <array>\n#line 3 \"convolution/and_or_convolution.hpp\"\
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
    \ a.end(), res.begin() + (1 << i));\n        }\n        return res;\n    }\n};\n"
  code: "#include <vector>\n\n#include \"../convolution/subset_convolution.hpp\"\n\
    \ntemplate <typename mint, int N>\nclass SetPowerSeries : public std::vector<mint>\
    \ {\n    using SPS = SetPowerSeries<mint, N>;\n    using Poly = std::array<mint,\
    \ N + 1>;\n\n   public:\n    using std::vector<mint>::vector;\n    using std::vector<mint>::operator=;\n\
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
    \ a.end(), res.begin() + (1 << i));\n        }\n        return res;\n    }\n};"
  dependsOn:
  - convolution/subset_convolution.hpp
  - convolution/and_or_convolution.hpp
  isVerificationFile: false
  path: math/set_power_series.hpp
  requiredBy:
  - math/matrix/hafnian.hpp
  timestamp: '2023-12-24 17:02:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/exp_of_set_power_series.test.cpp
  - test/yosupo/hafnian_of_matrix.test.cpp
documentation_of: math/set_power_series.hpp
layout: document
redirect_from:
- /library/math/set_power_series.hpp
- /library/math/set_power_series.hpp.html
title: math/set_power_series.hpp
---
