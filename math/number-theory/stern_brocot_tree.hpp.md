---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1208.test.cpp
    title: test/aoj/1208.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Stern Brocot Tree
    links: []
  bundledCode: "#line 2 \"math/number-theory/stern_brocot_tree.hpp\"\n#include <utility>\n\
    \n/**\n * @brief Stern Brocot Tree\n */\ntemplate <typename F>\nstd::pair<std::pair<long\
    \ long, long long>, std::pair<long long, long long>>\nstern_brocot_tree_search(long\
    \ long n, F cond) {\n    long long a = 0, b = 1, c = 1, d = 0;\n    while (true)\
    \ {\n        long long num = a + c, den = b + d;\n        if (num > n || den >\
    \ n) break;\n        if (cond(num, den)) {\n            long long k = 2;\n   \
    \         while ((num = a + c * k) <= n && (den = b + d * k) <= n &&\n       \
    \            cond(num, den))\n                k *= 2;\n            k /= 2;\n \
    \           a += c * k;\n            b += d * k;\n        } else {\n         \
    \   long long k = 2;\n            while ((num = a * k + c) <= n && (den = b *\
    \ k + d) <= n &&\n                   !cond(num, den))\n                k *= 2;\n\
    \            k /= 2;\n            c += a * k;\n            d += b * k;\n     \
    \   }\n    }\n    return {{a, b}, {c, d}};\n}\n"
  code: "#pragma once\n#include <utility>\n\n/**\n * @brief Stern Brocot Tree\n */\n\
    template <typename F>\nstd::pair<std::pair<long long, long long>, std::pair<long\
    \ long, long long>>\nstern_brocot_tree_search(long long n, F cond) {\n    long\
    \ long a = 0, b = 1, c = 1, d = 0;\n    while (true) {\n        long long num\
    \ = a + c, den = b + d;\n        if (num > n || den > n) break;\n        if (cond(num,\
    \ den)) {\n            long long k = 2;\n            while ((num = a + c * k)\
    \ <= n && (den = b + d * k) <= n &&\n                   cond(num, den))\n    \
    \            k *= 2;\n            k /= 2;\n            a += c * k;\n         \
    \   b += d * k;\n        } else {\n            long long k = 2;\n            while\
    \ ((num = a * k + c) <= n && (den = b * k + d) <= n &&\n                   !cond(num,\
    \ den))\n                k *= 2;\n            k /= 2;\n            c += a * k;\n\
    \            d += b * k;\n        }\n    }\n    return {{a, b}, {c, d}};\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/stern_brocot_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1208.test.cpp
documentation_of: math/number-theory/stern_brocot_tree.hpp
layout: document
title: Stern-Brocot Tree
---

## Description

Stern-Brocot tree は，有理数の探索に用いられる二分木である．

## Operations

- `pair<pair<long long, long long>, pair<long long, long long>> stern_brocot_tree_search(long long n, F cond)`
    - 分母及び分子が $n$ 以下の既約分数 $p/q$ のうち，条件 $\mathrm{cond}(p/q)$ を満たす最大のもの $a/b$ と満たさない最小のもの $c/d$ を返す． $\mathrm{cond}(p/q)$ の単調性を仮定する．
    - 時間計算量: $O(f(n)\log n)$, $f(n)$ は $\mathrm{cond}(p/q)$ の計算量


## Reference

- [ABC294 F - Sugar Water 2 解説](https://atcoder.jp/contests/abc294/editorial/6017)
- verify: [https://yukicoder.me/submissions/857736](https://yukicoder.me/submissions/857736)