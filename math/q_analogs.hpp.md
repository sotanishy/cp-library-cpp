---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/q_analogs.hpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename mint>\nclass qAnalogs {\n   public:\n    qAnalogs() = default;\n\
    \    explicit qAnalogs(mint q, int n)\n        : q(q), num(n + 1), fact_(n + 1),\
    \ fact_inv_(n + 1) {\n        for (int k = 1; k <= n; ++k) {\n            num[k]\
    \ = num[k - 1] * q + 1;\n        }\n        fact_[0] = 1;\n        for (int k\
    \ = 1; k <= n; ++k) {\n            fact_[k] = fact_[k - 1] * num[k];\n       \
    \ }\n        fact_inv_[n] = mint(1) / fact_[n];\n        for (int k = n; k > 0;\
    \ --k) {\n            fact_inv_[k - 1] = fact_inv_[k] * num[k];\n        }\n \
    \   }\n\n    mint number(int n) {\n        assert(0 <= n && n < (int)num.size());\n\
    \        return num[n];\n    }\n\n    mint fact(int n) {\n        assert(0 <=\
    \ n && n < (int)fact_.size());\n        return fact_[n];\n    }\n\n    mint fact_inv(int\
    \ n) {\n        assert(0 <= n && n < (int)fact_inv_.size());\n        return fact_inv_[n];\n\
    \    }\n\n    mint binom(int n, int k) {\n        assert(0 <= n && n < (int)fact_.size());\n\
    \        if (k < 0 || n < k) return 0;\n        return fact_[n] * fact_inv_[k]\
    \ * fact_inv_[n - k];\n    }\n\n   private:\n    const mint q;\n    std::vector<mint>\
    \ num, fact_, fact_inv_;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ mint>\nclass qAnalogs {\n   public:\n    qAnalogs() = default;\n    explicit\
    \ qAnalogs(mint q, int n)\n        : q(q), num(n + 1), fact_(n + 1), fact_inv_(n\
    \ + 1) {\n        for (int k = 1; k <= n; ++k) {\n            num[k] = num[k -\
    \ 1] * q + 1;\n        }\n        fact_[0] = 1;\n        for (int k = 1; k <=\
    \ n; ++k) {\n            fact_[k] = fact_[k - 1] * num[k];\n        }\n      \
    \  fact_inv_[n] = mint(1) / fact_[n];\n        for (int k = n; k > 0; --k) {\n\
    \            fact_inv_[k - 1] = fact_inv_[k] * num[k];\n        }\n    }\n\n \
    \   mint number(int n) {\n        assert(0 <= n && n < (int)num.size());\n   \
    \     return num[n];\n    }\n\n    mint fact(int n) {\n        assert(0 <= n &&\
    \ n < (int)fact_.size());\n        return fact_[n];\n    }\n\n    mint fact_inv(int\
    \ n) {\n        assert(0 <= n && n < (int)fact_inv_.size());\n        return fact_inv_[n];\n\
    \    }\n\n    mint binom(int n, int k) {\n        assert(0 <= n && n < (int)fact_.size());\n\
    \        if (k < 0 || n < k) return 0;\n        return fact_[n] * fact_inv_[k]\
    \ * fact_inv_[n - k];\n    }\n\n   private:\n    const mint q;\n    std::vector<mint>\
    \ num, fact_, fact_inv_;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/q_analogs.hpp
  requiredBy: []
  timestamp: '2024-01-06 12:43:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/q_analogs.hpp
layout: document
title: q-Analogs
---

## Description

$q$-数, $q$-階乗, $q$-二項係数を計算する．

空間計算量: $O(n)$

## Operations

- `qAnalogs(mint q, int n)`
    - $n$ 以下の非負整数の $q$-数， $q$-階乗及びその逆元を前計算する
    - 時間計算量: $O(n)$
- `T number(int n)`
    - $[n]_q$ を返す
    - 時間計算量: $O(1)$
- `T fact(int n)`
    - $[n]_q!$ を返す
    - 時間計算量: $O(1)$
- `T fact_inv(int n)`
    - $[n]_q!$ の逆元を返す
    - 時間計算量: $O(1)$
- `T binom(int n, int k)`
    - $\binom{n}{k}_q$ を返す
    - 時間計算量: $O(1)$

## Reference

- [ABC278 Ex - make 1 解説](https://atcoder.jp/contests/abc278/editorial/5210)
- verify: [https://atcoder.jp/contests/abc278/submissions/49047601](https://atcoder.jp/contests/abc278/submissions/49047601)