---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.slide_min.test.cpp
    title: test/aoj/DSL_3_D.slide_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/slide_min.hpp\"\n#include <deque>\n#include\
    \ <functional>\n#include <utility>\n\ntemplate <typename T, typename Compare =\
    \ std::less<>>\nclass SlideMin {\n   public:\n    void push(T x) {\n        while\
    \ (!dq.empty() && !cmp(dq.back().first, x)) dq.pop_back();\n        dq.emplace_back(x,\
    \ r++);\n    }\n\n    void pop() {\n        if (dq.front().second == l) dq.pop_front();\n\
    \        ++l;\n    }\n\n    T get() const { return dq.front().first; }\n\n   private:\n\
    \    int l = 0, r = 0;\n    std::deque<std::pair<T, int>> dq;\n    Compare cmp;\n\
    };\n"
  code: "#pragma once\n#include <deque>\n#include <functional>\n#include <utility>\n\
    \ntemplate <typename T, typename Compare = std::less<>>\nclass SlideMin {\n  \
    \ public:\n    void push(T x) {\n        while (!dq.empty() && !cmp(dq.back().first,\
    \ x)) dq.pop_back();\n        dq.emplace_back(x, r++);\n    }\n\n    void pop()\
    \ {\n        if (dq.front().second == l) dq.pop_front();\n        ++l;\n    }\n\
    \n    T get() const { return dq.front().first; }\n\n   private:\n    int l = 0,\
    \ r = 0;\n    std::deque<std::pair<T, int>> dq;\n    Compare cmp;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slide_min.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.slide_min.test.cpp
documentation_of: data-structure/slide_min.hpp
layout: document
title: Sliding Window Minimum
---

## Description

スライド最小値は，全順序集合 $T$ を扱い，要素の最小値を求めることができるキューである．

## Operations

- `void push(T x)`
    - $x$ をキューの末尾に追加する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `void pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $O(1)$
- `T get()`
    - キューの要素全体の最小値/最大値を返す
    - 時間計算量: $O(1)$