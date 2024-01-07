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
  bundledCode: "#line 2 \"dp/monotone_minima.hpp\"\n#include <vector>\n\ntemplate\
    \ <typename F>\nstd::vector<int> monotone_minima(int n, int m, const F& f) {\n\
    \    std::vector<int> idx(n, -1);\n\n    auto calc = [&](const auto& calc, int\
    \ l, int r, int optl,\n                    int optr) -> void {\n        if (l\
    \ > r) return;\n        int m = std::midpoint(l, r);\n        auto mi = f(m, optl);\n\
    \        idx[m] = optl;\n        for (int i = optl + 1; i <= optr; ++i) {\n  \
    \          auto v = f(m, i);\n            if (mi > v) {\n                mi =\
    \ v;\n                idx[m] = i;\n            }\n        }\n        calc(calc,\
    \ l, m - 1, optl, idx[m]);\n        calc(calc, m + 1, r, idx[m], optr);\n    };\n\
    \n    calc(calc, 0, n - 1, 0, m - 1);\n    return idx;\n}\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename F>\nstd::vector<int>\
    \ monotone_minima(int n, int m, const F& f) {\n    std::vector<int> idx(n, -1);\n\
    \n    auto calc = [&](const auto& calc, int l, int r, int optl,\n            \
    \        int optr) -> void {\n        if (l > r) return;\n        int m = std::midpoint(l,\
    \ r);\n        auto mi = f(m, optl);\n        idx[m] = optl;\n        for (int\
    \ i = optl + 1; i <= optr; ++i) {\n            auto v = f(m, i);\n           \
    \ if (mi > v) {\n                mi = v;\n                idx[m] = i;\n      \
    \      }\n        }\n        calc(calc, l, m - 1, optl, idx[m]);\n        calc(calc,\
    \ m + 1, r, idx[m], optr);\n    };\n\n    calc(calc, 0, n - 1, 0, m - 1);\n  \
    \  return idx;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/monotone_minima.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/monotone_minima.hpp
layout: document
title: Monotone Minima
---

## Description

Monotone minima は，monotone 行列の各行の argmin を高速に求めるアルゴリズムである．

$n \times m$ 行列 $A$ が monotone であるとは，

$\mathrm{argmin} A_{i,\ast} \leq \mathrm{argmin} A_{i+1,\ast}$ が成り立つことである．

$A$ が更に totally monotone ($A$ の任意の部分行列が monotone) であれば，SMAWK algorithm という更に高速なアルゴリズムが存在する．

- `vector<int> monotone_minima(int n, int m, F f)`
    - $A_{i,j}=f(i,j)$ である $n \times m$ 行列 $A$ の各行の argmin を求める
    - 時間計算量: $O((n + m)\log n)$

## Reference

- [Totally Monotone Matrix Searching (SMAWK algorithm)](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/)