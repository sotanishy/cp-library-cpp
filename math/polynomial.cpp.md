---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/ntt.cpp
    title: Number Theoretic Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/polynomial.md
    document_title: Polynomial
    links: []
  bundledCode: "#line 2 \"math/polynomial.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n#line 3 \"math/ntt.cpp\"\n\n/*\n * @brief Number Theoretic\
    \ Transform\n * @docs docs/math/ntt.md\n */\ntemplate <typename mint>\nclass NTT\
    \ {\npublic:\n    NTT() = delete;\n\n    static std::vector<mint> convolve(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n        int size = a.size()\
    \ + b.size() - 1;\n        int n = 1;\n        while (n < size) n <<= 1;\n   \
    \     std::vector<mint> na(a.begin(), a.end()), nb(b.begin(), b.end());\n    \
    \    na.resize(n);\n        nb.resize(n);\n        ntt(na, false);\n        ntt(nb,\
    \ false);\n        for (int i = 0; i < n; ++i) na[i] *= nb[i];\n        intt(na,\
    \ false);\n        na.resize(size);\n        mint n_inv = mint(n).inv();\n   \
    \     for (int i = 0; i < size; ++i) na[i] *= n_inv;\n        return na;\n   \
    \ }\n\n    static void ntt(std::vector<mint>& a, bool ordered = true) {\n    \
    \    int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n          \
    \  mint omega = primitive_root.pow((mod - 1) / m);\n            for (int s = 0;\
    \ s < n / m; ++s) {\n                mint w = 1;\n                for (int i =\
    \ 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n         \
    \           mint r = a[s * m + i + m / 2];\n                    a[s * m + i] =\
    \ l + r;\n                    a[s * m + i + m / 2] = (l - r) * w;\n          \
    \          w *= omega;\n                }\n            }\n        }\n        if\
    \ (ordered) bit_reverse(a);\n    }\n\n    static void intt(std::vector<mint>&\
    \ a, bool ordered = true) {\n        if (ordered) bit_reverse(a);\n        int\
    \ n = a.size();\n        for (int m = 2; m <= n; m <<= 1) {\n            mint\
    \ omega = primitive_root.pow((mod - 1) / m).inv();\n            for (int s = 0;\
    \ s < n / m; ++s) {\n                mint w = 1;\n                for (int i =\
    \ 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n         \
    \           mint r = a[s * m + i + m / 2] * w;\n                    a[s * m +\
    \ i] = l + r;\n                    a[s * m + i + m / 2] = l - r;\n           \
    \         w *= omega;\n                }\n            }\n        }\n    }\n\n\
    private:\n    static constexpr mint get_primitive_root(int mod) {\n        if\
    \ (mod == 167772161) return 3;\n        if (mod == 469762049) return 3;\n    \
    \    if (mod == 754974721) return 11;\n        if (mod == 998244353) return 3;\n\
    \        if (mod == 1224736769) return 3;\n    }\n\n    static constexpr int mod\
    \ = mint::get_mod();\n    static constexpr mint primitive_root = get_primitive_root(mod);\n\
    \n    static void bit_reverse(std::vector<mint>& a) {\n        int n = a.size();\n\
    \        for (int i = 0, j = 1; j < n - 1; ++j) {\n            for (int k = n\
    \ >> 1; k > (i ^= k); k >>= 1);\n            if (i < j) std::swap(a[i], a[j]);\n\
    \        }\n    }\n};\n#line 6 \"math/polynomial.cpp\"\n\n/*\n * @brief Polynomial\n\
    \ * @docs docs/math/polynomial.md\n */\ntemplate <typename mint>\nclass Polynomial\
    \ : public std::vector<mint> {\n    using Poly = Polynomial;\n\npublic:\n    using\
    \ std::vector<mint>::vector;\n    using std::vector<mint>::operator=;\n\n    Poly&\
    \ operator+=(const Poly& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];\n  \
    \      return *this;\n    }\n\n    Poly& operator+=(const mint& rhs) {\n     \
    \   if (this->empty()) this->resize(1);\n        (*this)[0] += rhs;\n        return\
    \ *this;\n    }\n\n    Poly& operator-=(const Poly& rhs) {\n        if (this->size()\
    \ < rhs.size()) this->resize(rhs.size());\n        for (int i = 0; i < (int) rhs.size();\
    \ ++i) (*this)[i] -= rhs[i];\n        return *this;\n    }\n\n    Poly& operator-=(const\
    \ mint& rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= rhs;\n        return *this;\n    }\n\n    Poly& operator*=(const Poly& rhs)\
    \ {\n        *this = NTT<mint>::convolve(*this, rhs);\n        return *this;\n\
    \    }\n\n    Poly& operator*=(const mint& rhs) {\n        for (int i = 0; i <\
    \ (int) this->size(); ++i) (*this)[i] *= rhs;\n        return *this;\n    }\n\n\
    \    Poly& operator-() const {\n        Poly ret(this->size());\n        for (int\
    \ i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];\n        return ret;\n\
    \    }\n\n    Poly operator+(const Poly& rhs) const { return Poly(*this) += rhs;\
    \ }\n    Poly operator+(const mint& rhs) const { return Poly(*this) += rhs; }\n\
    \    Poly operator-(const Poly& rhs) const { return Poly(*this) -= rhs; }\n  \
    \  Poly operator-(const mint& rhs) const { return Poly(*this) -= rhs; }\n    Poly\
    \ operator*(const Poly& rhs) const { return Poly(*this) *= rhs; }\n    Poly operator*(const\
    \ mint& rhs) const { return Poly(*this) *= rhs; }\n\n    Poly inv(int deg = -1)\
    \ const {\n        assert((*this)[0] != mint(0));\n        if (deg == -1) deg\
    \ = this->size();\n        Poly ret({mint(1) / (*this)[0]});\n        for (int\
    \ i = 1; i < deg; i <<= 1) {\n            ret = (ret * mint(2) - ret * ret * this->pre(i\
    \ << 1)).pre(i << 1);\n        }\n        return ret;\n    }\n\n    Poly exp(int\
    \ deg = -1) const {\n        assert((*this)[0] == mint(0));\n        if (deg ==\
    \ -1) deg = this->size();\n        Poly ret({mint(1)});\n        for (int i =\
    \ 1; i < deg; i <<= 1) {\n            ret = (ret * (this->pre(i << 1) + mint(1)\
    \ - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret;\n    }\n\n\
    \    Poly log(int deg = -1) const {\n        assert((*this)[0] == mint(1));\n\
    \        if (deg == -1) deg = this->size();\n        return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n    }\n\n    Poly pow(long long k, int deg = -1) const {\n\
    \        if (deg == -1) deg = this->size();\n        Poly ret(*this);\n      \
    \  int cnt = 0;\n        while (cnt < (int) ret.size() && ret[cnt] == mint(0))\
    \ ++cnt;\n        if (cnt * k >= deg) return Poly(deg, mint(0));\n        ret.erase(ret.begin(),\
    \ ret.begin() + cnt);\n        deg -= cnt * k;\n        ret = ((ret * mint(ret[0]).inv()).log(deg)\
    \ * mint(k)).pre(deg).exp(deg) * mint(ret[0]).pow(k);\n        ret.insert(ret.begin(),\
    \ cnt * k, mint(0));\n        return ret;\n    }\n\n    Poly diff() const {\n\
    \        Poly ret(std::max(0, (int) this->size() - 1));\n        for (int i =\
    \ 1; i <= (int) ret.size(); ++i) ret[i - 1] = (*this)[i] * mint(i);\n        return\
    \ ret;\n    }\n\n    Poly integral() const {\n        Poly ret(this->size() +\
    \ 1);\n        ret[0] = mint(0);\n        for (int i = 0; i < (int) ret.size()\
    \ - 1; ++i) ret[i + 1] = (*this)[i] / mint(i + 1);\n        return ret;\n    }\n\
    \nprivate:\n    Poly pre(int size) const { return Poly(this->begin(), this->begin()\
    \ + std::min((int) this->size(), size)); }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"ntt.cpp\"\n\n/*\n * @brief Polynomial\n * @docs docs/math/polynomial.md\n\
    \ */\ntemplate <typename mint>\nclass Polynomial : public std::vector<mint> {\n\
    \    using Poly = Polynomial;\n\npublic:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::operator=;\n\n    Poly& operator+=(const Poly& rhs)\
    \ {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n      \
    \  for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];\n        return\
    \ *this;\n    }\n\n    Poly& operator+=(const mint& rhs) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += rhs;\n        return *this;\n    }\n\
    \n    Poly& operator-=(const Poly& rhs) {\n        if (this->size() < rhs.size())\
    \ this->resize(rhs.size());\n        for (int i = 0; i < (int) rhs.size(); ++i)\
    \ (*this)[i] -= rhs[i];\n        return *this;\n    }\n\n    Poly& operator-=(const\
    \ mint& rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= rhs;\n        return *this;\n    }\n\n    Poly& operator*=(const Poly& rhs)\
    \ {\n        *this = NTT<mint>::convolve(*this, rhs);\n        return *this;\n\
    \    }\n\n    Poly& operator*=(const mint& rhs) {\n        for (int i = 0; i <\
    \ (int) this->size(); ++i) (*this)[i] *= rhs;\n        return *this;\n    }\n\n\
    \    Poly& operator-() const {\n        Poly ret(this->size());\n        for (int\
    \ i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];\n        return ret;\n\
    \    }\n\n    Poly operator+(const Poly& rhs) const { return Poly(*this) += rhs;\
    \ }\n    Poly operator+(const mint& rhs) const { return Poly(*this) += rhs; }\n\
    \    Poly operator-(const Poly& rhs) const { return Poly(*this) -= rhs; }\n  \
    \  Poly operator-(const mint& rhs) const { return Poly(*this) -= rhs; }\n    Poly\
    \ operator*(const Poly& rhs) const { return Poly(*this) *= rhs; }\n    Poly operator*(const\
    \ mint& rhs) const { return Poly(*this) *= rhs; }\n\n    Poly inv(int deg = -1)\
    \ const {\n        assert((*this)[0] != mint(0));\n        if (deg == -1) deg\
    \ = this->size();\n        Poly ret({mint(1) / (*this)[0]});\n        for (int\
    \ i = 1; i < deg; i <<= 1) {\n            ret = (ret * mint(2) - ret * ret * this->pre(i\
    \ << 1)).pre(i << 1);\n        }\n        return ret;\n    }\n\n    Poly exp(int\
    \ deg = -1) const {\n        assert((*this)[0] == mint(0));\n        if (deg ==\
    \ -1) deg = this->size();\n        Poly ret({mint(1)});\n        for (int i =\
    \ 1; i < deg; i <<= 1) {\n            ret = (ret * (this->pre(i << 1) + mint(1)\
    \ - ret.log(i << 1))).pre(i << 1);\n        }\n        return ret;\n    }\n\n\
    \    Poly log(int deg = -1) const {\n        assert((*this)[0] == mint(1));\n\
    \        if (deg == -1) deg = this->size();\n        return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n    }\n\n    Poly pow(long long k, int deg = -1) const {\n\
    \        if (deg == -1) deg = this->size();\n        Poly ret(*this);\n      \
    \  int cnt = 0;\n        while (cnt < (int) ret.size() && ret[cnt] == mint(0))\
    \ ++cnt;\n        if (cnt * k >= deg) return Poly(deg, mint(0));\n        ret.erase(ret.begin(),\
    \ ret.begin() + cnt);\n        deg -= cnt * k;\n        ret = ((ret * mint(ret[0]).inv()).log(deg)\
    \ * mint(k)).pre(deg).exp(deg) * mint(ret[0]).pow(k);\n        ret.insert(ret.begin(),\
    \ cnt * k, mint(0));\n        return ret;\n    }\n\n    Poly diff() const {\n\
    \        Poly ret(std::max(0, (int) this->size() - 1));\n        for (int i =\
    \ 1; i <= (int) ret.size(); ++i) ret[i - 1] = (*this)[i] * mint(i);\n        return\
    \ ret;\n    }\n\n    Poly integral() const {\n        Poly ret(this->size() +\
    \ 1);\n        ret[0] = mint(0);\n        for (int i = 0; i < (int) ret.size()\
    \ - 1; ++i) ret[i + 1] = (*this)[i] / mint(i + 1);\n        return ret;\n    }\n\
    \nprivate:\n    Poly pre(int size) const { return Poly(this->begin(), this->begin()\
    \ + std::min((int) this->size(), size)); }\n};"
  dependsOn:
  - math/ntt.cpp
  isVerificationFile: false
  path: math/polynomial.cpp
  requiredBy: []
  timestamp: '2020-12-06 15:01:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
documentation_of: math/polynomial.cpp
layout: document
redirect_from:
- /library/math/polynomial.cpp
- /library/math/polynomial.cpp.html
title: Polynomial
---
## Description

係数が`Modint`である多項式を扱う．

空間計算量: $O(n)$

## Operations

- `Polynomial inv(int deg)`
    - $\frac{1}{f(x)}$ を $deg - 1$ 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `Polynomial exp(int deg)`
    - $\exp(f(x))$ を $deg - 1$ 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `Polynomial log(int deg)`
    - $\log(f(x))$ を $deg - 1$ 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$
- `Polynomial pow(long long k, int deg)`
    - $(f(x))^k$ を $deg - 1$ 次の項まで計算する．
    - 時間計算量: $O(n \lg n)$

## Reference

- [【競技プログラミング】形式的冪級数の応用テクニック(前編)](https://qiita.com/hotman78/items/f0e6d2265badd84d429a)

