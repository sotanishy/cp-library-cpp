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
  bundledCode: "#line 2 \"misc/majority.hpp\"\n#include <optional>\n#include <vector>\n\
    \ntemplate <typename T>\nstd::optional<T> majority(const std::vector<T>& v) {\n\
    \    T m;\n    int cnt = 0;\n    for (auto x : v) {\n        if (cnt == 0) {\n\
    \            m = x;\n            ++cnt;\n        } else if (m == x) {\n      \
    \      ++cnt;\n        } else {\n            --cnt;\n        }\n    }\n    cnt\
    \ = 0;\n    for (auto x : v) {\n        if (m == x) {\n            ++cnt;\n  \
    \      }\n    }\n    return cnt > (int)v.size() / 2 ? std::optional<T>(m) : std::nullopt;\n\
    }\n"
  code: "#pragma once\n#include <optional>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstd::optional<T> majority(const std::vector<T>& v) {\n    T m;\n    int\
    \ cnt = 0;\n    for (auto x : v) {\n        if (cnt == 0) {\n            m = x;\n\
    \            ++cnt;\n        } else if (m == x) {\n            ++cnt;\n      \
    \  } else {\n            --cnt;\n        }\n    }\n    cnt = 0;\n    for (auto\
    \ x : v) {\n        if (m == x) {\n            ++cnt;\n        }\n    }\n    return\
    \ cnt > (int)v.size() / 2 ? std::optional<T>(m) : std::nullopt;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/majority.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/majority.hpp
layout: document
title: Boyer-Moore Majority Vote Algorithm
---

## Description

数列の過半数を占める要素を求める．

- `optional<T> majority(vector<T> v)`
    - 数列 `v` の過半数を占める要素を求める
    - 時間計算量: $O(n)$

## Reference

- [Boyer–Moore majority vote algorithm - Wikipedia](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)
- verify: [https://atcoder.jp/contests/abc272/submissions/35557503](https://atcoder.jp/contests/abc272/submissions/35557503)
