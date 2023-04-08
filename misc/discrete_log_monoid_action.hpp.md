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
  bundledCode: "#line 2 \"misc/discrete_log_monoid_action.hpp\"\n#include <unordered_set>\n\
    \ntemplate <typename M, typename S, S (*act)(typename M::T, S)>\nint discrete_log_monoid_action(typename\
    \ M::T x, S s, S t, long long N) {\n    using T = typename M::T;\n\n    // baby-step\n\
    \    const int m = sqrt(N) + 1;\n    std::unordered_set<S> babies;\n    S baby\
    \ = t;\n    for (int i = 1; i <= m; ++i) {\n        baby = act(x, baby);\n   \
    \     babies.insert(baby);\n    }\n\n    // giant-step\n    T xm = M::id(), y\
    \ = x;\n    int m_ = m;\n    while (m_) {\n        if (m_ & 1) xm = M::op(xm,\
    \ y);\n        y = M::op(y, y);\n        m_ >>= 1;\n    }\n\n    S giant = s;\n\
    \    bool first = true;\n    for (int i = 0; i <= N / m; ++i) {\n        if (babies.count(act(xm,\
    \ giant))) {\n            S u = giant;\n            for (int j = 0; j < m; ++j)\
    \ {\n                if (u == t) {\n                    return m * i + j;\n  \
    \              }\n                u = act(x, u);\n            }\n            if\
    \ (!first) return -1;\n            first = false;\n        }\n        giant =\
    \ act(xm, giant);\n    }\n    return -1;\n}\n"
  code: "#pragma once\n#include <unordered_set>\n\ntemplate <typename M, typename\
    \ S, S (*act)(typename M::T, S)>\nint discrete_log_monoid_action(typename M::T\
    \ x, S s, S t, long long N) {\n    using T = typename M::T;\n\n    // baby-step\n\
    \    const int m = sqrt(N) + 1;\n    std::unordered_set<S> babies;\n    S baby\
    \ = t;\n    for (int i = 1; i <= m; ++i) {\n        baby = act(x, baby);\n   \
    \     babies.insert(baby);\n    }\n\n    // giant-step\n    T xm = M::id(), y\
    \ = x;\n    int m_ = m;\n    while (m_) {\n        if (m_ & 1) xm = M::op(xm,\
    \ y);\n        y = M::op(y, y);\n        m_ >>= 1;\n    }\n\n    S giant = s;\n\
    \    bool first = true;\n    for (int i = 0; i <= N / m; ++i) {\n        if (babies.count(act(xm,\
    \ giant))) {\n            S u = giant;\n            for (int j = 0; j < m; ++j)\
    \ {\n                if (u == t) {\n                    return m * i + j;\n  \
    \              }\n                u = act(x, u);\n            }\n            if\
    \ (!first) return -1;\n            first = false;\n        }\n        giant =\
    \ act(xm, giant);\n    }\n    return -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/discrete_log_monoid_action.hpp
  requiredBy: []
  timestamp: '2023-04-08 13:57:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/discrete_log_monoid_action.hpp
layout: document
title: Discrete Logarithm of Monoid Action
---

## Description

モノイド作用に関する離散対数問題を解く．すなわち，モノイド $M$ が集合 $S$ に作用しているとき，$x \in X, s,t\in S$ と正整数 $N$ に対して $x^n s = t$ かつ $0 \leq n \lt N$ となる $n$ が存在するか判定し，あればそのうち最小のものを求める．

## Operations

- `int discrete_log_monoid_action(T x, S s, S t, long long N)`
    - $x^n s=t$ かつ $0 \leq n \lt N$ となる $n$ が存在すればそのうち最小のものを，存在しなければ $-1$ を返す
    - 時間計算量: $\mathrm{expected}\,O(\sqrt{N})$

## Note

集合 `S` は `std::hash` を実装している必要がある．

## Reference

- [モノイド作用に関する離散対数問題](https://maspypy.com/%e3%83%a2%e3%83%8e%e3%82%a4%e3%83%89%e4%bd%9c%e7%94%a8%e3%81%ab%e9%96%a2%e3%81%99%e3%82%8b%e9%9b%a2%e6%95%a3%e5%af%be%e6%95%b0%e5%95%8f%e9%a1%8c)
- verify: [https://atcoder.jp/contests/abc270/submissions/40150377](https://atcoder.jp/contests/abc270/submissions/40150377)
