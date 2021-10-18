---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convert_base.cpp\"\n#include <vector>\n\nstd::vector<int>\
    \ convert_base(int n, int base) {\n    int q = n / base, r = n % base;\n    if\
    \ (q == 0) return {r};\n    auto ret = convert_base(q, base);\n    ret.push_back(r);\n\
    \    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n\nstd::vector<int> convert_base(int n, int\
    \ base) {\n    int q = n / base, r = n % base;\n    if (q == 0) return {r};\n\
    \    auto ret = convert_base(q, base);\n    ret.push_back(r);\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/convert_base.cpp
  requiredBy: []
  timestamp: '2021-02-06 00:41:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convert_base.cpp
layout: document
title: Base Conversion
---

## Description

10進数の整数 $n$ を $base$ 進数に変換する

## Operations

- `vector<int> convert_base(int n, int base)`
    - 時間計算量: $O(\log_{base} n)$