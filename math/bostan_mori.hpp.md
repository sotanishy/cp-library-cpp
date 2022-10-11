---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: math/polynomial.cpp
    title: Polynomial
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/bostan_mori.hpp\"\n#include <vector>\n#line 3 \"convolution/ntt.hpp\"\
    \n\nconstexpr int get_primitive_root(int mod) {\n    if (mod == 167772161) return\
    \ 3;\n    if (mod == 469762049) return 3;\n    if (mod == 754974721) return 11;\n\
    \    if (mod == 998244353) return 3;\n    if (mod == 1224736769) return 3;\n}\n\
    \ntemplate <typename T>\nvoid bit_reverse(std::vector<T>& a) {\n    int n = a.size();\n\
    \    for (int i = 0, j = 1; j < n - 1; ++j) {\n        for (int k = n >> 1; k\
    \ > (i ^= k); k >>= 1);\n        if (i < j) std::swap(a[i], a[j]);\n    }\n}\n\
    \ntemplate <typename mint>\nvoid ntt(std::vector<mint>& a, bool ordered = true)\
    \ {\n    constexpr int mod = mint::get_mod();\n    constexpr mint primitive_root\
    \ = get_primitive_root(mod);\n\n    int n = a.size();\n    for (int m = n; m >\
    \ 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod - 1) / m);\n   \
    \     for (int s = 0; s < n / m; ++s) {\n            mint w = 1;\n           \
    \ for (int i = 0; i < m / 2; ++i) {\n                mint l = a[s * m + i];\n\
    \                mint r = a[s * m + i + m / 2];\n                a[s * m + i]\
    \ = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n            \
    \    w *= omega;\n            }\n        }\n    }\n    if (ordered) bit_reverse(a);\n\
    }\n\ntemplate <typename mint>\nvoid intt(std::vector<mint>& a, bool ordered =\
    \ true) {\n    constexpr int mod = mint::get_mod();\n    constexpr mint primitive_root\
    \ = get_primitive_root(mod);\n\n    if (ordered) bit_reverse(a);\n    int n =\
    \ a.size();\n    for (int m = 2; m <= n; m <<= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m).inv();\n        for (int s = 0; s < n / m; ++s) {\n            mint\
    \ w = 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint\
    \ l = a[s * m + i];\n                mint r = a[s * m + i + m / 2] * w;\n    \
    \            a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = l -\
    \ r;\n                w *= omega;\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename mint>\nstd::vector<mint> convolution(std::vector<mint> a, std::vector<mint>\
    \ b) {\n    int size = a.size() + b.size() - 1;\n    int n = 1;\n    while (n\
    \ < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n    ntt(a, false);\n \
    \   ntt(b, false);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    intt(a,\
    \ false);\n    a.resize(size);\n    mint n_inv = mint(n).inv();\n    for (int\
    \ i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}\n#line 2 \"math/polynomial.cpp\"\
    \n#include <algorithm>\n#include <cassert>\n#line 6 \"math/polynomial.cpp\"\n\n\
    template <typename mint>\nclass Polynomial : public std::vector<mint> {\n    using\
    \ Poly = Polynomial;\n\npublic:\n    using std::vector<mint>::vector;\n    using\
    \ std::vector<mint>::operator=;\n\n    Poly pre(int size) const { return Poly(this->begin(),\
    \ this->begin() + std::min((int) this->size(), size)); }\n\n    Poly rev(int deg\
    \ = -1) const {\n        Poly ret(*this);\n        if (deg != -1) ret.resize(deg,\
    \ 0);\n        return Poly(ret.rbegin(), ret.rend());\n    }\n\n    Poly& operator+=(const\
    \ Poly& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];\n  \
    \      return *this;\n    }\n\n    Poly& operator+=(const mint& rhs) {\n     \
    \   if (this->empty()) this->resize(1);\n        (*this)[0] += rhs;\n        return\
    \ *this;\n    }\n\n    Poly& operator-=(const Poly& rhs) {\n        if (this->size()\
    \ < rhs.size()) this->resize(rhs.size());\n        for (int i = 0; i < (int) rhs.size();\
    \ ++i) (*this)[i] -= rhs[i];\n        return *this;\n    }\n\n    Poly& operator-=(const\
    \ mint& rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= rhs;\n        return *this;\n    }\n\n    Poly& operator*=(const Poly& rhs)\
    \ {\n        *this = convolution(*this, rhs);\n        // // naive convolution\
    \ O(N^2)\n        // std::vector<mint> res(this->size() + rhs.size() - 1);\n \
    \       // for (int i = 0; i < (int) this->size(); ++i) {\n        //     for\
    \ (int j = 0; j < (int) rhs.size(); ++j) {\n        //         res[i + j] += (*this)[i]\
    \ * rhs[j];\n        //     }\n        // }\n        // *this = res;\n       \
    \ return *this;\n    }\n\n    Poly& operator*=(const mint& rhs) {\n        for\
    \ (int i = 0; i < (int) this->size(); ++i) (*this)[i] *= rhs;\n        return\
    \ *this;\n    }\n\n    Poly& operator/=(const Poly& rhs) {\n        if(this->size()\
    \ < rhs.size()) {\n            this->clear();\n            return *this;\n   \
    \     }\n        int n = this->size() - rhs.size() + 1;\n        return *this\
    \ = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);\n    }\n\n    Poly& operator%=(const\
    \ Poly& rhs) {\n        *this -= *this / rhs * rhs;\n        while (!this->empty()\
    \ && this->back() == 0) this->pop_back();\n        return *this;\n    }\n\n  \
    \  Poly& operator-() const {\n        Poly ret(this->size());\n        for (int\
    \ i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];\n        return ret;\n\
    \    }\n\n    Poly operator+(const Poly& rhs) const { return Poly(*this) += rhs;\
    \ }\n    Poly operator+(const mint& rhs) const { return Poly(*this) += rhs; }\n\
    \    Poly operator-(const Poly& rhs) const { return Poly(*this) -= rhs; }\n  \
    \  Poly operator-(const mint& rhs) const { return Poly(*this) -= rhs; }\n    Poly\
    \ operator*(const Poly& rhs) const { return Poly(*this) *= rhs; }\n    Poly operator*(const\
    \ mint& rhs) const { return Poly(*this) *= rhs; }\n    Poly operator/(const Poly&\
    \ rhs) const { return Poly(*this) /= rhs; }\n    Poly operator%(const Poly& rhs)\
    \ const { return Poly(*this) %= rhs; }\n\n    Poly operator<<(int n) const {\n\
    \        Poly ret(*this);\n        ret.insert(ret.begin(), n, 0);\n        return\
    \ ret;\n    }\n\n    Poly operator>>(int n) const {\n        if (this->size()\
    \ <= n) return {};\n        Poly ret(*this);\n        ret.erase(ret.begin(), ret.begin()\
    \ + n);\n        return ret;\n    }\n\n\n    mint operator()(const mint& x) {\n\
    \        mint y = 0, powx = 1;\n        for (int i = 0; i < (int) this->size();\
    \ ++i) {\n            y += (*this)[i] * powx;\n            powx *= x;\n      \
    \  }\n        return y;\n    }\n\n    Poly inv(int deg = -1) const {\n       \
    \ assert((*this)[0] != mint(0));\n        if (deg == -1) deg = this->size();\n\
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
    \        if (k == 0) return {1};\n        if (deg == -1) deg = this->size();\n\
    \        Poly ret(*this);\n        int cnt = 0;\n        while (cnt < (int) ret.size()\
    \ && ret[cnt] == mint(0)) ++cnt;\n        if (cnt * k >= deg) return Poly(deg,\
    \ mint(0));\n        ret.erase(ret.begin(), ret.begin() + cnt);\n        deg -=\
    \ cnt * k;\n        ret = ((ret * mint(ret[0]).inv()).log(deg) * mint(k)).pre(deg).exp(deg)\
    \ * mint(ret[0]).pow(k);\n        ret.insert(ret.begin(), cnt * k, mint(0));\n\
    \        return ret;\n    }\n\n    Poly diff() const {\n        Poly ret(std::max(0,\
    \ (int) this->size() - 1));\n        for (int i = 1; i <= (int) ret.size(); ++i)\
    \ ret[i - 1] = (*this)[i] * mint(i);\n        return ret;\n    }\n\n    Poly integral()\
    \ const {\n        Poly ret(this->size() + 1);\n        ret[0] = mint(0);\n  \
    \      for (int i = 0; i < (int) ret.size() - 1; ++i) ret[i + 1] = (*this)[i]\
    \ / mint(i + 1);\n        return ret;\n    }\n\n    Poly taylor_shift(long long\
    \ c) const {\n        const int n = this->size();\n        std::vector<mint> fact(n,\
    \ 1), fact_inv(n, 1);\n        for (int i = 1; i < n; ++i) fact[i] = fact[i-1]\
    \ * i;\n        fact_inv[n-1] = mint(1) / fact[n-1];\n        for (int i = n -\
    \ 1; i > 0; --i) fact_inv[i-1] = fact_inv[i] * i;\n\n        auto ret = *this;\n\
    \        Poly e(n+1);\n        e[0] = 1;\n        mint p = c;\n        for (int\
    \ i = 1; i < n; ++i) {\n            ret[i] *= fact[i];\n            e[i] = p *\
    \ fact_inv[i];\n            p *= c;\n        }\n        ret = (ret.rev() * e).pre(n).rev();\n\
    \        for (int i = n - 1; i >= 0; --i) {\n            ret[i] *= fact_inv[i];\n\
    \        }\n        return ret;\n    }\n};\n#line 5 \"math/bostan_mori.hpp\"\n\
    \ntemplate <typename T>\nT bostan_mori_division(Polynomial<T> p, Polynomial<T>\
    \ q, long long n) {\n    auto take = [&](const std::vector<T>& p, int s) {\n \
    \       std::vector<T> r((p.size() + 1) / 2);\n        for (int i = 0; i < (int)\
    \ r.size(); ++i) {\n            if (2 * i + s < (int) p.size()) {\n          \
    \      r[i] = p[2 * i + s];\n            }\n        }\n        return r;\n   \
    \ };\n\n    while (n > 0) {\n        auto qm = q;\n        for (int i = 1; i <\
    \ (int) qm.size(); i += 2) qm[i] = -qm[i];\n        p = take(p * qm, n & 1);\n\
    \        q = take(q * qm, 0);\n        n >>= 1;\n    }\n\n    return p[0] / q[0];\n\
    }\n\ntemplate <typename T>\nT bostan_mori_recurrence(const std::vector<T>& a,\
    \ const std::vector<T>& c, long long n) {\n    const int d = c.size();\n    if\
    \ (n < d) return a[n];\n\n    std::vector<T> q(d + 1);\n    q[0] = 1;\n    for\
    \ (int i = 0; i < d; ++i) q[i + 1] = -c[i];\n    auto p = convolution(a, q);\n\
    \    p.resize(d);\n\n    auto take = [&](const std::vector<T>& p, int s) {\n \
    \       std::vector<T> r((p.size() + 1) / 2);\n        for (int i = 0; i < (int)\
    \ r.size(); ++i) {\n            r[i] = p[2 * i + s];\n        }\n        return\
    \ r;\n    };\n\n    while (n > 0) {\n        auto qm = q;\n        for (int i\
    \ = 1; i < (int) qm.size(); i += 2) qm[i] = -qm[i];\n        p = take(convolution(p,\
    \ qm), n & 1);\n        q = take(convolution(q, qm), 0);\n        n >>= 1;\n \
    \   }\n\n    return p[0] / q[0];\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../convolution/ntt.hpp\"\n#include\
    \ \"../math/polynomial.cpp\"\n\ntemplate <typename T>\nT bostan_mori_division(Polynomial<T>\
    \ p, Polynomial<T> q, long long n) {\n    auto take = [&](const std::vector<T>&\
    \ p, int s) {\n        std::vector<T> r((p.size() + 1) / 2);\n        for (int\
    \ i = 0; i < (int) r.size(); ++i) {\n            if (2 * i + s < (int) p.size())\
    \ {\n                r[i] = p[2 * i + s];\n            }\n        }\n        return\
    \ r;\n    };\n\n    while (n > 0) {\n        auto qm = q;\n        for (int i\
    \ = 1; i < (int) qm.size(); i += 2) qm[i] = -qm[i];\n        p = take(p * qm,\
    \ n & 1);\n        q = take(q * qm, 0);\n        n >>= 1;\n    }\n\n    return\
    \ p[0] / q[0];\n}\n\ntemplate <typename T>\nT bostan_mori_recurrence(const std::vector<T>&\
    \ a, const std::vector<T>& c, long long n) {\n    const int d = c.size();\n  \
    \  if (n < d) return a[n];\n\n    std::vector<T> q(d + 1);\n    q[0] = 1;\n  \
    \  for (int i = 0; i < d; ++i) q[i + 1] = -c[i];\n    auto p = convolution(a,\
    \ q);\n    p.resize(d);\n\n    auto take = [&](const std::vector<T>& p, int s)\
    \ {\n        std::vector<T> r((p.size() + 1) / 2);\n        for (int i = 0; i\
    \ < (int) r.size(); ++i) {\n            r[i] = p[2 * i + s];\n        }\n    \
    \    return r;\n    };\n\n    while (n > 0) {\n        auto qm = q;\n        for\
    \ (int i = 1; i < (int) qm.size(); i += 2) qm[i] = -qm[i];\n        p = take(convolution(p,\
    \ qm), n & 1);\n        q = take(convolution(q, qm), 0);\n        n >>= 1;\n \
    \   }\n\n    return p[0] / q[0];\n}"
  dependsOn:
  - convolution/ntt.hpp
  - math/polynomial.cpp
  isVerificationFile: false
  path: math/bostan_mori.hpp
  requiredBy: []
  timestamp: '2022-10-01 22:18:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: math/bostan_mori.hpp
layout: document
title: Bostan-Mori Algorithm
---

## Description

Bostan-Mori algorithm は，$d$ 階線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．

## Operations

- `T bostan_mori_division(Polynomial<T> p, Polynomial<T> q, long long n)`
    - $p(x)/q(x)$ の第 $n$ 項を求める．
    - 時間計算量: $O(\mathsf{M}(k) \log n)$, $\mathsf{M(k)}$ は$k$次多項式乗算の計算量 (FFT なら $O(k\log k)$)
- `T bostan_mori_recurrence(vector<T> a, vector<T> c, long long n)`
    - 初めの $k$ 項 $a_0, \dots, a_{k-1}$ と漸化式 $a_n = c_0 a_{n-1} + \dots + c_{k-1} a_{n-k}$ によって定まる数列 $(a_n)$ の第 $n$ 項を求める．
    - 時間計算量: 同上

## Reference

- [線形漸化的数列のN項目の計算 - Qiita](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a)
