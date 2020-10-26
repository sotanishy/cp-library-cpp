---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ntt.cpp
    title: Number Theoretic Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/formal_power_series.md
    document_title: Formal Power Series
    links: []
  bundledCode: "#line 2 \"math/formal_power_series.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n#line 3 \"math/ntt.cpp\"\n\n/*\n * @brief Number\
    \ Theoretic Transform\n * @docs docs/math/ntt.md\n */\ntemplate <typename mint>\n\
    class NTT {\npublic:\n    NTT() = delete;\n\n    static std::vector<mint> convolution(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n        int size = a.size()\
    \ + b.size() - 1;\n        int n = 1;\n        while (n < size) n <<= 1;\n   \
    \     std::vector<mint> na(n), nb(n);\n        for (int i = 0; i < (int) a.size();\
    \ ++i) na[i] = a[i];\n        for (int i = 0; i < (int) b.size(); ++i) nb[i] =\
    \ b[i];\n        untt(na);\n        untt(nb);\n        for (int i = 0; i < n;\
    \ ++i) na[i] *= nb[i];\n        iuntt(na);\n        na.resize(size);\n       \
    \ mint n_inv = mint(n).inv();\n        for (int i = 0; i < size; ++i) na[i] *=\
    \ n_inv;\n        return na;\n    }\n\nprivate:\n    static constexpr mint get_primitive_root(int\
    \ mod) {\n        if (mod == 167772161) return 3;\n        if (mod == 469762049)\
    \ return 3;\n        if (mod == 754974721) return 11;\n        if (mod == 998244353)\
    \ return 3;\n        if (mod == 1224736769) return 3;\n    }\n\n    static constexpr\
    \ int mod = mint::get_mod();\n    static constexpr mint primitive_root = get_primitive_root(mod);\n\
    \n    static void untt(std::vector<mint>& a) {\n        int n = a.size();\n  \
    \      for (int m = n; m > 1; m >>= 1) {\n            mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n            for (int s = 0; s < n / m; ++s) {\n                mint\
    \ w = 1;\n                for (int i = 0; i < m / 2; ++i) {\n                \
    \    mint l = a[s * m + i];\n                    mint r = a[s * m + i + m / 2];\n\
    \                    a[s * m + i] = l + r;\n                    a[s * m + i +\
    \ m / 2] = (l - r) * w;\n                    w *= omega;\n                }\n\
    \            }\n        }\n    }\n\n    static void iuntt(std::vector<mint>& a)\
    \ {\n        int n = a.size();\n        for (int m = 2; m <= n; m <<= 1) {\n \
    \           mint omega = primitive_root.pow((mod - 1) / m).inv();\n          \
    \  for (int s = 0; s < n / m; ++s) {\n                mint w = 1;\n          \
    \      for (int i = 0; i < m / 2; ++i) {\n                    mint l = a[s * m\
    \ + i];\n                    mint r = a[s * m + i + m / 2] * w;\n            \
    \        a[s * m + i] = l + r;\n                    a[s * m + i + m / 2] = l -\
    \ r;\n                    w *= omega;\n                }\n            }\n    \
    \    }\n    }\n};\n#line 6 \"math/formal_power_series.cpp\"\n\n/*\n * @brief Formal\
    \ Power Series\n * @docs docs/math/formal_power_series.md\n */\ntemplate <typename\
    \ mint>\nclass FormalPowerSeries : public std::vector<mint> {\n    using FPS =\
    \ FormalPowerSeries;\n\npublic:\n    using std::vector<mint>::vector;\n    using\
    \ std::vector<mint>::operator=;\n\n    FPS& operator+=(const FPS& rhs) {\n   \
    \     if (this->size() < rhs.size()) this->resize(rhs.size());\n        for (int\
    \ i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];\n        return *this;\n\
    \    }\n\n    FPS& operator+=(const mint& rhs) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += rhs;\n        return *this;\n    }\n\n    FPS& operator-=(const\
    \ FPS& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] -= rhs[i];\n  \
    \      return *this;\n    }\n\n    FPS& operator-=(const mint& rhs) {\n      \
    \  if (this->empty()) this->resize(1);\n        (*this)[0] -= rhs;\n        return\
    \ *this;\n    }\n\n    FPS& operator*=(const FPS& rhs) {\n        *this = NTT<mint>::convolution(*this,\
    \ rhs);\n        return *this;\n    }\n\n    FPS& operator*=(const mint& rhs)\
    \ {\n        for (int i = 0; i < (int) this->size(); ++i) (*this)[i] *= rhs;\n\
    \        return *this;\n    }\n\n    FPS& operator-() const {\n        FPS ret(this->size());\n\
    \        for (int i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];\n\
    \        return ret;\n    }\n\n    FPS operator+(const FPS& rhs) const { return\
    \ FPS(*this) += rhs; }\n    FPS operator+(const mint& rhs) const { return FPS(*this)\
    \ += rhs; }\n    FPS operator-(const FPS& rhs) const { return FPS(*this) -= rhs;\
    \ }\n    FPS operator-(const mint& rhs) const { return FPS(*this) -= rhs; }\n\
    \    FPS operator*(const FPS& rhs) const { return FPS(*this) *= rhs; }\n    FPS\
    \ operator*(const mint& rhs) const { return FPS(*this) *= rhs; }\n\n    FPS inv(int\
    \ deg = -1) const {\n        assert((*this)[0] != mint(0));\n        if (deg ==\
    \ -1) deg = this->size();\n        FPS ret({mint(1) / (*this)[0]});\n        for\
    \ (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * mint(2) - ret * ret\
    \ * this->pre(i << 1)).pre(i << 1);\n        }\n        return ret;\n    }\n\n\
    \    FPS exp(int deg = -1) const {\n        assert((*this)[0] == mint(0));\n \
    \       if (deg == -1) deg = this->size();\n        FPS ret({mint(1)});\n    \
    \    for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (this->pre(i\
    \ << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return\
    \ ret;\n    }\n\n    FPS log(int deg = -1) const {\n        assert((*this)[0]\
    \ == mint(1));\n        if (deg == -1) deg = this->size();\n        return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n    }\n\n    FPS pow(long long k,\
    \ int deg = -1) const {\n        if (deg == -1) deg = this->size();\n        FPS\
    \ ret(*this);\n        int cnt = 0;\n        while (cnt < (int) ret.size() &&\
    \ ret[cnt] == mint(0)) ++cnt;\n        if (cnt * k >= deg) return FPS(deg, mint(0));\n\
    \        ret.erase(ret.begin(), ret.begin() + cnt);\n        deg -= cnt * k;\n\
    \        ret = ((ret * mint(ret[0]).inv()).log(deg) * mint(k)).pre(deg).exp(deg)\
    \ * mint(ret[0]).pow(k);\n        ret.insert(ret.begin(), cnt * k, mint(0));\n\
    \        return ret;\n    }\n\n    FPS diff() const {\n        FPS ret(std::max(0,\
    \ (int) this->size() - 1));\n        for (int i = 1; i <= (int) ret.size(); ++i)\
    \ ret[i - 1] = (*this)[i] * mint(i);\n        return ret;\n    }\n\n    FPS integral()\
    \ const {\n        FPS ret(this->size() + 1);\n        ret[0] = mint(0);\n   \
    \     for (int i = 0; i < (int) ret.size() - 1; ++i) ret[i + 1] = (*this)[i] /\
    \ mint(i + 1);\n        return ret;\n    }\n\nprivate:\n    FPS pre(int size)\
    \ const { return FPS(this->begin(), this->begin() + std::min((int) this->size(),\
    \ size)); }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"ntt.cpp\"\n\n/*\n * @brief Formal Power Series\n * @docs docs/math/formal_power_series.md\n\
    \ */\ntemplate <typename mint>\nclass FormalPowerSeries : public std::vector<mint>\
    \ {\n    using FPS = FormalPowerSeries;\n\npublic:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::operator=;\n\n    FPS& operator+=(const FPS& rhs)\
    \ {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n      \
    \  for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];\n        return\
    \ *this;\n    }\n\n    FPS& operator+=(const mint& rhs) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += rhs;\n        return *this;\n    }\n\
    \n    FPS& operator-=(const FPS& rhs) {\n        if (this->size() < rhs.size())\
    \ this->resize(rhs.size());\n        for (int i = 0; i < (int) rhs.size(); ++i)\
    \ (*this)[i] -= rhs[i];\n        return *this;\n    }\n\n    FPS& operator-=(const\
    \ mint& rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= rhs;\n        return *this;\n    }\n\n    FPS& operator*=(const FPS& rhs)\
    \ {\n        *this = NTT<mint>::convolution(*this, rhs);\n        return *this;\n\
    \    }\n\n    FPS& operator*=(const mint& rhs) {\n        for (int i = 0; i <\
    \ (int) this->size(); ++i) (*this)[i] *= rhs;\n        return *this;\n    }\n\n\
    \    FPS& operator-() const {\n        FPS ret(this->size());\n        for (int\
    \ i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];\n        return ret;\n\
    \    }\n\n    FPS operator+(const FPS& rhs) const { return FPS(*this) += rhs;\
    \ }\n    FPS operator+(const mint& rhs) const { return FPS(*this) += rhs; }\n\
    \    FPS operator-(const FPS& rhs) const { return FPS(*this) -= rhs; }\n    FPS\
    \ operator-(const mint& rhs) const { return FPS(*this) -= rhs; }\n    FPS operator*(const\
    \ FPS& rhs) const { return FPS(*this) *= rhs; }\n    FPS operator*(const mint&\
    \ rhs) const { return FPS(*this) *= rhs; }\n\n    FPS inv(int deg = -1) const\
    \ {\n        assert((*this)[0] != mint(0));\n        if (deg == -1) deg = this->size();\n\
    \        FPS ret({mint(1) / (*this)[0]});\n        for (int i = 1; i < deg; i\
    \ <<= 1) {\n            ret = (ret * mint(2) - ret * ret * this->pre(i << 1)).pre(i\
    \ << 1);\n        }\n        return ret;\n    }\n\n    FPS exp(int deg = -1) const\
    \ {\n        assert((*this)[0] == mint(0));\n        if (deg == -1) deg = this->size();\n\
    \        FPS ret({mint(1)});\n        for (int i = 1; i < deg; i <<= 1) {\n  \
    \          ret = (ret * (this->pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i\
    \ << 1);\n        }\n        return ret;\n    }\n\n    FPS log(int deg = -1) const\
    \ {\n        assert((*this)[0] == mint(1));\n        if (deg == -1) deg = this->size();\n\
    \        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();\n   \
    \ }\n\n    FPS pow(long long k, int deg = -1) const {\n        if (deg == -1)\
    \ deg = this->size();\n        FPS ret(*this);\n        int cnt = 0;\n       \
    \ while (cnt < (int) ret.size() && ret[cnt] == mint(0)) ++cnt;\n        if (cnt\
    \ * k >= deg) return FPS(deg, mint(0));\n        ret.erase(ret.begin(), ret.begin()\
    \ + cnt);\n        deg -= cnt * k;\n        ret = ((ret * mint(ret[0]).inv()).log(deg)\
    \ * mint(k)).pre(deg).exp(deg) * mint(ret[0]).pow(k);\n        ret.insert(ret.begin(),\
    \ cnt * k, mint(0));\n        return ret;\n    }\n\n    FPS diff() const {\n \
    \       FPS ret(std::max(0, (int) this->size() - 1));\n        for (int i = 1;\
    \ i <= (int) ret.size(); ++i) ret[i - 1] = (*this)[i] * mint(i);\n        return\
    \ ret;\n    }\n\n    FPS integral() const {\n        FPS ret(this->size() + 1);\n\
    \        ret[0] = mint(0);\n        for (int i = 0; i < (int) ret.size() - 1;\
    \ ++i) ret[i + 1] = (*this)[i] / mint(i + 1);\n        return ret;\n    }\n\n\
    private:\n    FPS pre(int size) const { return FPS(this->begin(), this->begin()\
    \ + std::min((int) this->size(), size)); }\n};"
  dependsOn:
  - math/ntt.cpp
  isVerificationFile: false
  path: math/formal_power_series.cpp
  requiredBy: []
  timestamp: '2020-10-26 13:50:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
documentation_of: math/formal_power_series.cpp
layout: document
redirect_from:
- /library/math/formal_power_series.cpp
- /library/math/formal_power_series.cpp.html
title: Formal Power Series
---
# Formal Power Series

形式的べき級数を扱う．

空間計算量: $O(n)$

## Template parameter

- `mint`
    - `Modint`

## Member functions

- `FPS inv(int deg)`
    - $\frac{1}{f(x)}$ を `deg - 1` 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `FPS exp(int deg)`
    - $\exp(f(x))$ を `deg - 1` 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `FPS log(int deg)`
    - $\log(f(x))$ を `deg - 1` 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `FPS pow(long long k, int deg)`
    - $(f(x))^k$ を `deg - 1` 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$

## Reference

- [【競技プログラミング】形式的冪級数の応用テクニック(前編)](https://qiita.com/hotman78/items/f0e6d2265badd84d429a)

