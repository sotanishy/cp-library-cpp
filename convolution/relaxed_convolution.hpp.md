---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/relaxed_convolution.hpp\"\n#include <bit>\n\
    #include <vector>\n\n#line 3 \"convolution/ntt.hpp\"\n\nconstexpr int get_primitive_root(int\
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
    \ b) {\n    const int size = a.size() + b.size() - 1;\n    const int n = std::bit_ceil(size);\n\
    \    a.resize(n);\n    b.resize(n);\n    ntt(a);\n    ntt(b);\n    for (int i\
    \ = 0; i < n; ++i) a[i] *= b[i];\n    intt(a);\n    a.resize(size);\n    mint\
    \ n_inv = mint(n).inv();\n    for (int i = 0; i < size; ++i) a[i] *= n_inv;\n\
    \    return a;\n}\n#line 6 \"convolution/relaxed_convolution.hpp\"\n\ntemplate\
    \ <typename mint>\nclass RelaxedConvolution {\n   public:\n    mint get(mint a,\
    \ mint b) {\n        f.push_back(a);\n        g.push_back(b);\n        ++n;\n\
    \        int m = 1 << std::countr_zero((unsigned int)n + 1);\n        int s =\
    \ 0, x = 1;\n        while (x <= m) {\n            calc(n - x, n, s, s + x);\n\
    \            if (n + 1 == m && x == m >> 1) break;\n            calc(s, s + x,\
    \ n - x, n);\n            s += x;\n            x <<= 1;\n        }\n        return\
    \ h[n - 1];\n    }\n\n   private:\n    int n = 0;\n    std::vector<mint> f, g,\
    \ h;\n\n    void calc(int lf, int rf, int lg, int rg) {\n        if ((int)h.size()\
    \ < rf + rg - 1) {\n            h.resize(rf + rg - 1);\n        }\n        auto\
    \ res =\n            convolution(std::vector<mint>(f.begin() + lf, f.begin() +\
    \ rf),\n                        std::vector<mint>(g.begin() + lg, g.begin() +\
    \ rg));\n        for (int i = 0; i < (int)res.size(); ++i) {\n            h[lf\
    \ + lg + i] += res[i];\n        }\n    }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <vector>\n\n#include \"ntt.hpp\"\n\
    \ntemplate <typename mint>\nclass RelaxedConvolution {\n   public:\n    mint get(mint\
    \ a, mint b) {\n        f.push_back(a);\n        g.push_back(b);\n        ++n;\n\
    \        int m = 1 << std::countr_zero((unsigned int)n + 1);\n        int s =\
    \ 0, x = 1;\n        while (x <= m) {\n            calc(n - x, n, s, s + x);\n\
    \            if (n + 1 == m && x == m >> 1) break;\n            calc(s, s + x,\
    \ n - x, n);\n            s += x;\n            x <<= 1;\n        }\n        return\
    \ h[n - 1];\n    }\n\n   private:\n    int n = 0;\n    std::vector<mint> f, g,\
    \ h;\n\n    void calc(int lf, int rf, int lg, int rg) {\n        if ((int)h.size()\
    \ < rf + rg - 1) {\n            h.resize(rf + rg - 1);\n        }\n        auto\
    \ res =\n            convolution(std::vector<mint>(f.begin() + lf, f.begin() +\
    \ rf),\n                        std::vector<mint>(g.begin() + lg, g.begin() +\
    \ rg));\n        for (int i = 0; i < (int)res.size(); ++i) {\n            h[lf\
    \ + lg + i] += res[i];\n        }\n    }\n};"
  dependsOn:
  - convolution/ntt.hpp
  isVerificationFile: false
  path: convolution/relaxed_convolution.hpp
  requiredBy: []
  timestamp: '2024-01-07 22:37:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/relaxed_convolution.hpp
layout: document
title: Relaxed Convolution
---

## Description

Relaxed convolution は，畳み込みをオンラインで処理するアルゴリズムである．すなわち，数列 $F, G$ の項が前から順番に与えられたとき，それらの畳み込み $H=F*G$ の各項を前から順番に返す．

## Operations

- `mint get(mint a, mint b)`
    - $F_n=a,G_n=b$ が与えられたとき， $H_n=\sum_{k=0}^n F_k G_{n-k}$ を返す．
    - 時間計算量: $\mathrm{amortized}\, O(N (\log N)^2)$

## Reference

- [オンライン畳み込み - Qiita](https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c)
- verify: [https://atcoder.jp/contests/abc315/submissions/44768767](https://atcoder.jp/contests/abc315/submissions/44768767)