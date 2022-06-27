---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: math/polynomial.cpp
    title: Polynomial
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_first_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_first_kind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/polynomial.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n#line 3 \"convolution/ntt.hpp\"\n\nconstexpr int get_primitive_root(int\
    \ mod) {\n    if (mod == 167772161) return 3;\n    if (mod == 469762049) return\
    \ 3;\n    if (mod == 754974721) return 11;\n    if (mod == 998244353) return 3;\n\
    \    if (mod == 1224736769) return 3;\n}\n\ntemplate <typename T>\nvoid bit_reverse(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int i = 0, j = 1; j < n - 1; ++j) {\n\
    \        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n        if (i < j) std::swap(a[i],\
    \ a[j]);\n    }\n}\n\ntemplate <typename mint>\nvoid ntt(std::vector<mint>& a,\
    \ bool ordered = true) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    int n = a.size();\n  \
    \  for (int m = n; m > 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n        for (int s = 0; s < n / m; ++s) {\n            mint w =\
    \ 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint l =\
    \ a[s * m + i];\n                mint r = a[s * m + i + m / 2];\n            \
    \    a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n\
    \                w *= omega;\n            }\n        }\n    }\n    if (ordered)\
    \ bit_reverse(a);\n}\n\ntemplate <typename mint>\nvoid intt(std::vector<mint>&\
    \ a, bool ordered = true) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    if (ordered) bit_reverse(a);\n\
    \    int n = a.size();\n    for (int m = 2; m <= n; m <<= 1) {\n        mint omega\
    \ = primitive_root.pow((mod - 1) / m).inv();\n        for (int s = 0; s < n /\
    \ m; ++s) {\n            mint w = 1;\n            for (int i = 0; i < m / 2; ++i)\
    \ {\n                mint l = a[s * m + i];\n                mint r = a[s * m\
    \ + i + m / 2] * w;\n                a[s * m + i] = l + r;\n                a[s\
    \ * m + i + m / 2] = l - r;\n                w *= omega;\n            }\n    \
    \    }\n    }\n}\n\ntemplate <typename mint>\nstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int size = a.size() + b.size() - 1;\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    ntt(a, false);\n    ntt(b, false);\n    for (int i = 0; i < n; ++i) a[i]\
    \ *= b[i];\n    intt(a, false);\n    a.resize(size);\n    mint n_inv = mint(n).inv();\n\
    \    for (int i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}\n#line 6\
    \ \"math/polynomial.cpp\"\n\ntemplate <typename mint>\nclass Polynomial : public\
    \ std::vector<mint> {\n    using Poly = Polynomial;\n\npublic:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::operator=;\n\n    Poly pre(int size) const { return\
    \ Poly(this->begin(), this->begin() + std::min((int) this->size(), size)); }\n\
    \n    Poly rev(int deg = -1) const {\n        Poly ret(*this);\n        if (deg\
    \ != -1) ret.resize(deg, 0);\n        return Poly(ret.rbegin(), ret.rend());\n\
    \    }\n\n    Poly& operator+=(const Poly& rhs) {\n        if (this->size() <\
    \ rhs.size()) this->resize(rhs.size());\n        for (int i = 0; i < (int) rhs.size();\
    \ ++i) (*this)[i] += rhs[i];\n        return *this;\n    }\n\n    Poly& operator+=(const\
    \ mint& rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ += rhs;\n        return *this;\n    }\n\n    Poly& operator-=(const Poly& rhs)\
    \ {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n      \
    \  for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] -= rhs[i];\n        return\
    \ *this;\n    }\n\n    Poly& operator-=(const mint& rhs) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= rhs;\n        return *this;\n    }\n\
    \n    Poly& operator*=(const Poly& rhs) {\n        *this = convolution(*this,\
    \ rhs);\n        // // naive convolution O(N^2)\n        // std::vector<mint>\
    \ res(this->size() + rhs.size() - 1);\n        // for (int i = 0; i < (int) this->size();\
    \ ++i) {\n        //     for (int j = 0; j < (int) rhs.size(); ++j) {\n      \
    \  //         res[i + j] += (*this)[i] * rhs[j];\n        //     }\n        //\
    \ }\n        // *this = res;\n        return *this;\n    }\n\n    Poly& operator*=(const\
    \ mint& rhs) {\n        for (int i = 0; i < (int) this->size(); ++i) (*this)[i]\
    \ *= rhs;\n        return *this;\n    }\n\n    Poly& operator/=(const Poly& rhs)\
    \ {\n        if(this->size() < rhs.size()) {\n            this->clear();\n   \
    \         return *this;\n        }\n        int n = this->size() - rhs.size()\
    \ + 1;\n        return *this = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);\n\
    \    }\n\n    Poly& operator%=(const Poly& rhs) {\n        *this -= *this / rhs\
    \ * rhs;\n        while (!this->empty() && this->back() == 0) this->pop_back();\n\
    \        return *this;\n    }\n\n    Poly& operator-() const {\n        Poly ret(this->size());\n\
    \        for (int i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];\n\
    \        return ret;\n    }\n\n    Poly operator+(const Poly& rhs) const { return\
    \ Poly(*this) += rhs; }\n    Poly operator+(const mint& rhs) const { return Poly(*this)\
    \ += rhs; }\n    Poly operator-(const Poly& rhs) const { return Poly(*this) -=\
    \ rhs; }\n    Poly operator-(const mint& rhs) const { return Poly(*this) -= rhs;\
    \ }\n    Poly operator*(const Poly& rhs) const { return Poly(*this) *= rhs; }\n\
    \    Poly operator*(const mint& rhs) const { return Poly(*this) *= rhs; }\n  \
    \  Poly operator/(const Poly& rhs) const { return Poly(*this) /= rhs; }\n    Poly\
    \ operator%(const Poly& rhs) const { return Poly(*this) %= rhs; }\n\n    Poly\
    \ operator<<(int n) const {\n        Poly ret(*this);\n        ret.insert(ret.begin(),\
    \ n, 0);\n        return ret;\n    }\n\n    Poly operator>>(int n) const {\n \
    \       if (this->size() <= n) return {};\n        Poly ret(*this);\n        ret.erase(ret.begin(),\
    \ ret.begin() + n);\n        return ret;\n    }\n\n\n    mint operator()(const\
    \ mint& x) {\n        mint y = 0, powx = 1;\n        for (int i = 0; i < (int)\
    \ this->size(); ++i) {\n            y += (*this)[i] * powx;\n            powx\
    \ *= x;\n        }\n        return y;\n    }\n\n    Poly inv(int deg = -1) const\
    \ {\n        assert((*this)[0] != mint(0));\n        if (deg == -1) deg = this->size();\n\
    \        Poly ret({mint(1) / (*this)[0]});\n        for (int i = 1; i < deg; i\
    \ <<= 1) {\n            ret = (ret * mint(2) - ret * ret * this->pre(i << 1)).pre(i\
    \ << 1);\n        }\n        return ret;\n    }\n\n    Poly exp(int deg = -1)\
    \ const {\n        assert((*this)[0] == mint(0));\n        if (deg == -1) deg\
    \ = this->size();\n        Poly ret({mint(1)});\n        for (int i = 1; i < deg;\
    \ i <<= 1) {\n            ret = (ret * (this->pre(i << 1) + mint(1) - ret.log(i\
    \ << 1))).pre(i << 1);\n        }\n        return ret;\n    }\n\n    Poly log(int\
    \ deg = -1) const {\n        assert((*this)[0] == mint(1));\n        if (deg ==\
    \ -1) deg = this->size();\n        return (this->diff() * this->inv(deg)).pre(deg\
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
    \n    Poly taylor_shift(long long c) const {\n        const int n = this->size();\n\
    \        std::vector<mint> fact(n, 1), fact_inv(n, 1);\n        for (int i = 1;\
    \ i < n; ++i) fact[i] = fact[i-1] * i;\n        fact_inv[n-1] = mint(1) / fact[n-1];\n\
    \        for (int i = n - 1; i > 0; --i) fact_inv[i-1] = fact_inv[i] * i;\n\n\
    \        auto ret = *this;\n        Poly e(n+1);\n        e[0] = 1;\n        mint\
    \ p = c;\n        for (int i = 1; i < n; ++i) {\n            ret[i] *= fact[i];\n\
    \            e[i] = p * fact_inv[i];\n            p *= c;\n        }\n       \
    \ ret = (ret.rev() * e).pre(n).rev();\n        for (int i = n - 1; i >= 0; --i)\
    \ {\n            ret[i] *= fact_inv[i];\n        }\n        return ret;\n    }\n\
    };\n#line 3 \"math/stirling_first.hpp\"\n\ntemplate <typename T>\nPolynomial<T>\
    \ stirling_first_table(int n) {\n    if (n == 0) return {1};\n    Polynomial<T>\
    \ ret = stirling_first_table<T>(n / 2);\n    ret *= ret.taylor_shift(-(n / 2));\n\
    \    if (n % 2) ret = (ret << 1) + ret * (-(n - 1));  // ret *= (x - (n - 1))\n\
    \    return ret;\n}\n"
  code: "#pragma once\n#include \"polynomial.cpp\"\n\ntemplate <typename T>\nPolynomial<T>\
    \ stirling_first_table(int n) {\n    if (n == 0) return {1};\n    Polynomial<T>\
    \ ret = stirling_first_table<T>(n / 2);\n    ret *= ret.taylor_shift(-(n / 2));\n\
    \    if (n % 2) ret = (ret << 1) + ret * (-(n - 1));  // ret *= (x - (n - 1))\n\
    \    return ret;\n}"
  dependsOn:
  - math/polynomial.cpp
  - convolution/ntt.hpp
  isVerificationFile: false
  path: math/stirling_first.hpp
  requiredBy: []
  timestamp: '2022-04-28 21:35:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/stirling_number_of_the_first_kind.test.cpp
documentation_of: math/stirling_first.hpp
layout: document
title: Stirling Number of the First Kind
---

## Description

第1種 Stirling 数 $s(n,k)$ は，以下の恒等式で定義される数である．

$$
x(x-1)\cdots(x-(n-1)) = \sum_{k=0}^n s(n,k) x^k
$$

$s(n,k)$ の絶対値 (${n \brack k}$ と書く) は，$n$ 要素の置換のうち，$k$ 個のサイクルに分解されるものの個数である．

## Operations

- `vector<T> stirling_first_table(int n)`
    - $s(n,k)$ を各 $k=0,1,\dots,n$ について計算する
    - 時間計算量: $O(n\log n)$

## Notes

第1種 Stirling 数について以下の式が成り立つ．

$$
s(n,k) = (-1)^{(n-k)} {n \brack k}
$$

$$
{n\brack k} = {n-1\brack k-1} + (n-1){n-1 \brack k}
$$

## Reference

- [「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)

