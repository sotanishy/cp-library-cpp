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
    path: test/yosupo/bernoulli_number.test.cpp
    title: test/yosupo/bernoulli_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/bernoulli.hpp\"\n#include <vector>\n\n#line 2 \"convolution/ntt.hpp\"\
    \n#include <bit>\n#line 4 \"convolution/ntt.hpp\"\n\nconstexpr int get_primitive_root(int\
    \ mod) {\n    if (mod == 167772161) return 3;\n    if (mod == 469762049) return\
    \ 3;\n    if (mod == 754974721) return 11;\n    if (mod == 998244353) return 3;\n\
    \    if (mod == 1224736769) return 3;\n}\n\ntemplate <typename mint>\nvoid ntt(std::vector<mint>&\
    \ a) {\n    constexpr int mod = mint::mod();\n    constexpr mint primitive_root\
    \ = get_primitive_root(mod);\n\n    const int n = a.size();\n    for (int m =\
    \ n; m > 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod - 1) / m);\n\
    \        for (int s = 0; s < n / m; ++s) {\n            mint w = 1;\n        \
    \    for (int i = 0; i < m / 2; ++i) {\n                mint l = a[s * m + i];\n\
    \                mint r = a[s * m + i + m / 2];\n                a[s * m + i]\
    \ = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n            \
    \    w *= omega;\n            }\n        }\n    }\n}\n\ntemplate <typename mint>\n\
    void intt(std::vector<mint>& a) {\n    constexpr int mod = mint::mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    const int n = a.size();\n\
    \    for (int m = 2; m <= n; m <<= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m).inv();\n        for (int s = 0; s < n / m; ++s) {\n            mint\
    \ w = 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint\
    \ l = a[s * m + i];\n                mint r = a[s * m + i + m / 2] * w;\n    \
    \            a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = l -\
    \ r;\n                w *= omega;\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename mint>\nstd::vector<mint> convolution(std::vector<mint> a, std::vector<mint>\
    \ b) {\n    const int size = a.size() + b.size() - 1;\n    const int n = std::bit_ceil((unsigned\
    \ int)size);\n    a.resize(n);\n    b.resize(n);\n    ntt(a);\n    ntt(b);\n \
    \   for (int i = 0; i < n; ++i) a[i] *= b[i];\n    intt(a);\n    a.resize(size);\n\
    \    mint n_inv = mint(n).inv();\n    for (int i = 0; i < size; ++i) a[i] *= n_inv;\n\
    \    return a;\n}\n#line 2 \"math/polynomial.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#line 5 \"math/polynomial.cpp\"\n\n#line 7 \"math/polynomial.cpp\"\
    \n\ntemplate <typename mint>\nclass Polynomial : public std::vector<mint> {\n\
    \    using Poly = Polynomial;\n\n   public:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::operator=;\n\n    Poly pre(int size) const {\n \
    \       return Poly(this->begin(),\n                    this->begin() + std::min((int)this->size(),\
    \ size));\n    }\n\n    Poly rev(int deg = -1) const {\n        auto ret = *this;\n\
    \        if (deg != -1) ret.resize(deg, 0);\n        return Poly(ret.rbegin(),\
    \ ret.rend());\n    }\n\n    void trim() {\n        while (!this->empty() && this->back()\
    \ == 0) this->pop_back();\n    }\n\n    // --- unary operation ---\n\n    Poly&\
    \ operator-() const {\n        auto ret = *this;\n        for (auto& x : ret)\
    \ x = -x;\n        return ret;\n    }\n\n    // -- binary operation with scalar\
    \ ---\n\n    Poly& operator+=(const mint& rhs) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += rhs;\n        return *this;\n    }\n\n    Poly& operator-=(const\
    \ mint& rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= rhs;\n        return *this;\n    }\n\n    Poly& operator*=(const mint& rhs)\
    \ {\n        for (auto& x : *this) x *= rhs;\n        return *this;\n    }\n\n\
    \    Poly& operator/=(const mint& rhs) { return *this *= rhs.inv(); }\n\n    Poly\
    \ operator+(const mint& rhs) const { return Poly(*this) += rhs; }\n    Poly operator-(const\
    \ mint& rhs) const { return Poly(*this) -= rhs; }\n    Poly operator*(const mint&\
    \ rhs) const { return Poly(*this) *= rhs; }\n    Poly operator/(const mint& rhs)\
    \ const { return Poly(*this) /= rhs; }\n\n    // --- binary operation with polynomial\
    \ ---\n\n    Poly& operator+=(const Poly& rhs) {\n        if (this->size() < rhs.size())\
    \ this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size(); ++i)\
    \ (*this)[i] += rhs[i];\n        return *this;\n    }\n\n    Poly& operator-=(const\
    \ Poly& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] -= rhs[i];\n   \
    \     return *this;\n    }\n\n    Poly& operator*=(const Poly& rhs) {\n      \
    \  *this = convolution(*this, rhs);\n        return *this;\n        // // naive\
    \ convolution O(N^2)\n        // std::vector<mint> res(this->size() + rhs.size()\
    \ - 1);\n        // for (int i = 0; i < (int)this->size(); ++i) {\n        //\
    \     for (int j = 0; j < (int)rhs.size(); ++j) {\n        //         res[i +\
    \ j] += (*this)[i] * rhs[j];\n        //     }\n        // }\n        // return\
    \ *this = res;\n    }\n\n    Poly& operator/=(const Poly& rhs) {\n        if (this->size()\
    \ < rhs.size()) {\n            this->clear();\n            return *this;\n   \
    \     }\n        int n = this->size() - rhs.size() + 1;\n        return *this\
    \ = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);\n    }\n\n    Poly& operator%=(const\
    \ Poly& rhs) {\n        *this -= *this / rhs * rhs;\n        trim();\n       \
    \ return *this;\n    }\n\n    std::pair<Poly, Poly> divmod(const Poly& rhs) {\n\
    \        auto q = *this / rhs;\n        auto r = *this - q * rhs;\n        r.trim();\n\
    \        return {q, r};\n    }\n\n    Poly operator+(const Poly& rhs) const {\
    \ return Poly(*this) += rhs; }\n    Poly operator-(const Poly& rhs) const { return\
    \ Poly(*this) -= rhs; }\n    Poly operator*(const Poly& rhs) const { return Poly(*this)\
    \ *= rhs; }\n    Poly operator/(const Poly& rhs) const { return Poly(*this) /=\
    \ rhs; }\n    Poly operator%(const Poly& rhs) const { return Poly(*this) %= rhs;\
    \ }\n\n    // --- shift operation ---\n\n    Poly operator<<(int n) const {\n\
    \        auto ret = *this;\n        ret.insert(ret.begin(), n, 0);\n        return\
    \ ret;\n    }\n\n    Poly operator>>(int n) const {\n        if ((int)this->size()\
    \ <= n) return {};\n        auto ret = *this;\n        ret.erase(ret.begin(),\
    \ ret.begin() + n);\n        return ret;\n    }\n\n    // --- evaluation ---\n\
    \n    mint operator()(const mint& x) {\n        mint y = 0, powx = 1;\n      \
    \  for (int i = 0; i < (int)this->size(); ++i) {\n            for (auto c : *this)\
    \ {\n                y += c * powx;\n                powx *= x;\n            }\n\
    \            return y;\n        }\n    }\n\n    // --- other operations ---\n\n\
    \    Poly inv(int deg = -1) const {\n        assert((*this)[0] != mint(0));\n\
    \        if (deg == -1) deg = this->size();\n        Poly res = {(*this)[0].inv()};\n\
    \        for (int d = 1; d < deg; d <<= 1) {\n            auto f = pre(2 * d);\n\
    \            auto g = res;\n            f.resize(2 * d);\n            g.resize(2\
    \ * d);\n\n            // g_{n+1} = g_n * (2 - g_n * f) mod x^{2^{n+1}}\n\n  \
    \          ntt(f);\n            ntt(g);\n            for (int i = 0; i < 2 * d;\
    \ ++i) f[i] *= g[i];\n            intt(f);\n\n            for (int i = 0; i <\
    \ d; ++i) f[i] = 0;\n\n            ntt(f);\n            for (int i = 0; i < 2\
    \ * d; ++i) f[i] *= g[i];\n            intt(f);\n\n            res.resize(2 *\
    \ d);\n            auto coef = mint(2 * d).inv().pow(2);\n            for (int\
    \ i = d; i < 2 * d; ++i) res[i] = -f[i] * coef;\n        }\n        return res.pre(deg);\n\
    \    }\n\n    Poly exp(int deg = -1) const {\n        assert((*this)[0] == mint(0));\n\
    \        if (deg == -1) deg = this->size();\n        Poly ret = {mint(1)};\n \
    \       for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (this->pre(i\
    \ << 1) + mint(1) - ret.log(i << 1)))\n                      .pre(i << 1);\n \
    \       }\n        return ret;\n    }\n\n    Poly log(int deg = -1) const {\n\
    \        assert((*this)[0] == mint(1));\n        if (deg == -1) deg = this->size();\n\
    \        return (diff() * inv(deg)).pre(deg - 1).integral();\n    }\n\n    Poly\
    \ pow(long long k, int deg = -1) const {\n        if (k == 0) return {1};\n  \
    \      if (deg == -1) deg = this->size();\n        auto ret = *this;\n       \
    \ int cnt0 = 0;\n        while (cnt0 < (int)ret.size() && ret[cnt0] == 0) ++cnt0;\n\
    \        if (cnt0 > (deg - 1) / k) return {};\n        ret = ret >> cnt0;\n  \
    \      deg -= cnt0 * k;\n        ret = ((ret / ret[0]).log(deg) * k).exp(deg)\
    \ * ret[0].pow(k);\n        ret = ret << (cnt0 * k);\n        return ret;\n  \
    \  }\n\n    Poly diff() const {\n        Poly ret(std::max(0, (int)this->size()\
    \ - 1));\n        for (int i = 1; i <= (int)ret.size(); ++i)\n            ret[i\
    \ - 1] = (*this)[i] * mint(i);\n        return ret;\n    }\n\n    Poly integral()\
    \ const {\n        Poly ret(this->size() + 1);\n        ret[0] = mint(0);\n  \
    \      for (int i = 0; i < (int)ret.size() - 1; ++i)\n            ret[i + 1] =\
    \ (*this)[i] / mint(i + 1);\n        return ret;\n    }\n\n    Poly taylor_shift(long\
    \ long c) const {\n        const int n = this->size();\n        std::vector<mint>\
    \ fact(n, 1), fact_inv(n, 1);\n        for (int i = 1; i < n; ++i) fact[i] = fact[i\
    \ - 1] * i;\n        fact_inv[n - 1] = mint(1) / fact[n - 1];\n        for (int\
    \ i = n - 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\n\n        auto ret\
    \ = *this;\n        Poly e(n + 1);\n        e[0] = 1;\n        mint p = c;\n \
    \       for (int i = 1; i < n; ++i) {\n            ret[i] *= fact[i];\n      \
    \      e[i] = p * fact_inv[i];\n            p *= c;\n        }\n        ret =\
    \ (ret.rev() * e).pre(n).rev();\n        for (int i = n - 1; i >= 0; --i) {\n\
    \            ret[i] *= fact_inv[i];\n        }\n        return ret;\n    }\n};\n\
    #line 6 \"math/bernoulli.hpp\"\n\ntemplate <typename mint>\nstd::vector<mint>\
    \ bernoulli_number_table(int n) {\n    std::vector<mint> fact(n + 2), fact_inv(n\
    \ + 2);\n    fact[0] = 1;\n    for (int i = 1; i <= n + 1; ++i) fact[i] = fact[i\
    \ - 1] * i;\n    fact_inv[n + 1] = fact[n + 1].inv();\n    for (int i = n + 1;\
    \ i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\n    Polynomial<mint> den(n +\
    \ 1);\n    for (int k = 0; k <= n; ++k) den[k] = fact_inv[k + 1];\n    auto res\
    \ = den.inv();\n    std::vector<mint> ret(n + 1);\n    for (int k = 0; k <= n;\
    \ ++k) {\n        ret[k] = k < (int)res.size() ? res[k] * fact[k] : 0;\n    }\n\
    \    return ret;\n}\n\ntemplate <typename mint>\nmint sum_of_powers(long long\
    \ n, int p) {\n    if (p == 0) return n;\n\n    std::vector<mint> fact(p + 2),\
    \ fact_inv(p + 2);\n    fact[0] = 1;\n    for (int i = 1; i <= p + 1; ++i) fact[i]\
    \ = fact[i - 1] * i;\n    fact_inv[p + 1] = fact[p + 1].inv();\n    for (int i\
    \ = p + 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\n\n    auto bern = bernoulli_number_table<mint>(p);\n\
    \    mint res = 0;\n    mint pown = n;\n    for (int j = p; j >= 0; --j) {\n \
    \       auto term = fact_inv[p + 1 - j] * fact_inv[j] * bern[j] * pown;\n    \
    \    res += j % 2 == 0 ? term : -term;\n        pown *= n;\n    }\n    res *=\
    \ fact[p];\n    return res;\n}\n\ntemplate <typename mint>\nstd::vector<mint>\
    \ sum_of_powers_table(long long n, int p) {\n    std::vector<mint> fact(p + 2),\
    \ fact_inv(p + 2);\n    fact[0] = 1;\n    for (int i = 1; i <= p + 1; ++i) fact[i]\
    \ = fact[i - 1] * i;\n    fact_inv[p + 1] = fact[p + 1].inv();\n    for (int i\
    \ = p + 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\n\n    auto bern = bernoulli_number_table<mint>(p\
    \ + 1);\n    std::vector<mint> f(p + 2), g(p + 2);\n    mint pown = 1;\n    for\
    \ (int k = 0; k <= p + 1; ++k) {\n        f[k] = mint(k % 2 == 0 ? 1 : -1) * bern[k]\
    \ * fact_inv[k];\n        g[k] = pown * fact_inv[k];\n        pown *= n;\n   \
    \ }\n    auto h = convolution(f, g);\n\n    std::vector<mint> res(p + 1);\n  \
    \  res[0] = n;\n    for (int k = 1; k <= p; ++k) {\n        res[k] = fact[k] *\
    \ (h[k + 1] - f[k + 1]);\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <vector>\n\n#include \"../convolution/ntt.hpp\"\n\
    #include \"polynomial.cpp\"\n\ntemplate <typename mint>\nstd::vector<mint> bernoulli_number_table(int\
    \ n) {\n    std::vector<mint> fact(n + 2), fact_inv(n + 2);\n    fact[0] = 1;\n\
    \    for (int i = 1; i <= n + 1; ++i) fact[i] = fact[i - 1] * i;\n    fact_inv[n\
    \ + 1] = fact[n + 1].inv();\n    for (int i = n + 1; i > 0; --i) fact_inv[i -\
    \ 1] = fact_inv[i] * i;\n    Polynomial<mint> den(n + 1);\n    for (int k = 0;\
    \ k <= n; ++k) den[k] = fact_inv[k + 1];\n    auto res = den.inv();\n    std::vector<mint>\
    \ ret(n + 1);\n    for (int k = 0; k <= n; ++k) {\n        ret[k] = k < (int)res.size()\
    \ ? res[k] * fact[k] : 0;\n    }\n    return ret;\n}\n\ntemplate <typename mint>\n\
    mint sum_of_powers(long long n, int p) {\n    if (p == 0) return n;\n\n    std::vector<mint>\
    \ fact(p + 2), fact_inv(p + 2);\n    fact[0] = 1;\n    for (int i = 1; i <= p\
    \ + 1; ++i) fact[i] = fact[i - 1] * i;\n    fact_inv[p + 1] = fact[p + 1].inv();\n\
    \    for (int i = p + 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\n\n  \
    \  auto bern = bernoulli_number_table<mint>(p);\n    mint res = 0;\n    mint pown\
    \ = n;\n    for (int j = p; j >= 0; --j) {\n        auto term = fact_inv[p + 1\
    \ - j] * fact_inv[j] * bern[j] * pown;\n        res += j % 2 == 0 ? term : -term;\n\
    \        pown *= n;\n    }\n    res *= fact[p];\n    return res;\n}\n\ntemplate\
    \ <typename mint>\nstd::vector<mint> sum_of_powers_table(long long n, int p) {\n\
    \    std::vector<mint> fact(p + 2), fact_inv(p + 2);\n    fact[0] = 1;\n    for\
    \ (int i = 1; i <= p + 1; ++i) fact[i] = fact[i - 1] * i;\n    fact_inv[p + 1]\
    \ = fact[p + 1].inv();\n    for (int i = p + 1; i > 0; --i) fact_inv[i - 1] =\
    \ fact_inv[i] * i;\n\n    auto bern = bernoulli_number_table<mint>(p + 1);\n \
    \   std::vector<mint> f(p + 2), g(p + 2);\n    mint pown = 1;\n    for (int k\
    \ = 0; k <= p + 1; ++k) {\n        f[k] = mint(k % 2 == 0 ? 1 : -1) * bern[k]\
    \ * fact_inv[k];\n        g[k] = pown * fact_inv[k];\n        pown *= n;\n   \
    \ }\n    auto h = convolution(f, g);\n\n    std::vector<mint> res(p + 1);\n  \
    \  res[0] = n;\n    for (int k = 1; k <= p; ++k) {\n        res[k] = fact[k] *\
    \ (h[k + 1] - f[k + 1]);\n    }\n    return res;\n}\n"
  dependsOn:
  - convolution/ntt.hpp
  - math/polynomial.cpp
  isVerificationFile: false
  path: math/bernoulli.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bernoulli_number.test.cpp
documentation_of: math/bernoulli.hpp
layout: document
title: Bernoulli Number
---

## Description

Bernoulli 数 $B_k$ は，以下の恒等式で定義される数である．

$$
\frac{x}{e^x-1} = \sum_{k=0} \frac{B_k}{k!}x^k
$$

Bernoulli 数は，最初の $n$ 個の正整数の $p$ 乗和を与える Faulhaber の公式に現れる．

$$
\sum_{k=1}^n k^p = \frac{1}{p+1} \sum_{j=0}^p (-1)^j \binom{p+1}{j} B_j n^{p-j+1}
$$

## Operations

- `vector<T> bernoulli_table(int n)`
    - $B_k$ を各 $k=0,1,\dots,n$ について計算する
    - 時間計算量: $O(n\log n)$
- `T sum_of_powers(long long n, int p)`
    - $\sum_{k=1}^n k^p$ を計算する
    - 時間計算量: $O(p \log p)$
- `vector<T> sum_of_powers_table(long long n, int p)`
    - $\sum_{k=1}^n k^r$ を各 $r = 0,1,\dots,p$ について 計算する
    - 時間計算量: $O(p \log p)$

## Reference

- verify: [https://atcoder.jp/contests/oupc2023-day1/submissions/49058484](https://atcoder.jp/contests/oupc2023-day1/submissions/49058484)

