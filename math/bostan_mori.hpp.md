---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}\n#line 4 \"math/bostan_mori.hpp\"\
    \n\ntemplate <typename T>\nT bostan_mori(const std::vector<T>& a, const std::vector<T>&\
    \ c, long long n) {\n    const int d = c.size();\n    if (n < d) return a[n];\n\
    \n    std::vector<T> q(d + 1);\n    q[0] = 1;\n    for (int i = 0; i < d; ++i)\
    \ q[i + 1] = -c[i];\n    auto p = convolution(a, q);\n    p.resize(d);\n\n   \
    \ auto take = [&](const std::vector<T>& p, int s) {\n        std::vector<T> r((p.size()\
    \ + 1) / 2);\n        for (int i = 0; i < (int) r.size(); ++i) {\n           \
    \ r[i] = p[2 * i + s];\n        }\n        return r;\n    };\n\n    while (n >\
    \ 0) {\n        auto qm = q;\n        for (int i = 1; i < (int) qm.size(); i +=\
    \ 2) qm[i] = -qm[i];\n        p = take(convolution(p, qm), n & 1);\n        q\
    \ = take(convolution(q, qm), 0);\n        n >>= 1;\n    }\n\n    return p[0] /\
    \ q[0];\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../convolution/ntt.hpp\"\n\n\
    template <typename T>\nT bostan_mori(const std::vector<T>& a, const std::vector<T>&\
    \ c, long long n) {\n    const int d = c.size();\n    if (n < d) return a[n];\n\
    \n    std::vector<T> q(d + 1);\n    q[0] = 1;\n    for (int i = 0; i < d; ++i)\
    \ q[i + 1] = -c[i];\n    auto p = convolution(a, q);\n    p.resize(d);\n\n   \
    \ auto take = [&](const std::vector<T>& p, int s) {\n        std::vector<T> r((p.size()\
    \ + 1) / 2);\n        for (int i = 0; i < (int) r.size(); ++i) {\n           \
    \ r[i] = p[2 * i + s];\n        }\n        return r;\n    };\n\n    while (n >\
    \ 0) {\n        auto qm = q;\n        for (int i = 1; i < (int) qm.size(); i +=\
    \ 2) qm[i] = -qm[i];\n        p = take(convolution(p, qm), n & 1);\n        q\
    \ = take(convolution(q, qm), 0);\n        n >>= 1;\n    }\n\n    return p[0] /\
    \ q[0];\n}"
  dependsOn:
  - convolution/ntt.hpp
  isVerificationFile: false
  path: math/bostan_mori.hpp
  requiredBy: []
  timestamp: '2022-03-31 14:37:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: math/bostan_mori.hpp
layout: document
title: Bostan-Mori Algorithm
---

## Description

Bostan-Mori algorithm は，$d$ 階線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．

## Operations

- `T bostan_mori(vector<T> a, vector<T> c, long long n)`
    - 初めの $k$ 項 $a_0, \dots, a_{k-1}$ と漸化式 $a_n = c_0 a_{n-1} + \dots + c_{k-1} a_{n-k}$ によって定まる数列 $(a_n)$ の第 $n$ 項を求める．
    - 時間計算量: $O(\mathsf{M}(k) \log n)$, $\mathsf{M(k)}$ は$k$次多項式乗算の計算量 (FFT なら $O(k\log k)$)

## Reference

- [線形漸化的数列のN項目の計算 - Qiita](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a)
