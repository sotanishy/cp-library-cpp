---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sliding_window_aggregation.hpp\"\n#include\
    \ <cassert>\n#include <stack>\n#include <utility>\n\ntemplate <typename S>\nclass\
    \ SlidingWindowAggregation {\n    using T = typename S::T;\n\n   public:\n   \
    \ void push(const T& x) {\n        if (back.empty())\n            back.emplace(x,\
    \ x);\n        else\n            back.emplace(x, S::op(back.top().second, x));\n\
    \    }\n\n    void pop() {\n        assert(!empty());\n        if (front.empty())\
    \ {\n            T x = back.top().first;\n            back.pop();\n          \
    \  front.emplace(x, x);\n            while (!back.empty()) {\n               \
    \ x = back.top().first;\n                back.pop();\n                front.emplace(x,\
    \ S::op(x, front.top().second));\n            }\n        }\n        front.pop();\n\
    \    }\n\n    bool empty() const { return front.empty() && back.empty(); }\n\n\
    \    T fold() const {\n        assert(!empty());\n        if (front.empty()) return\
    \ back.top().second;\n        if (back.empty()) return front.top().second;\n \
    \       return S::op(front.top().second, back.top().second);\n    }\n\n   private:\n\
    \    std::stack<std::pair<T, T>> front, back;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <stack>\n#include <utility>\n\n\
    template <typename S>\nclass SlidingWindowAggregation {\n    using T = typename\
    \ S::T;\n\n   public:\n    void push(const T& x) {\n        if (back.empty())\n\
    \            back.emplace(x, x);\n        else\n            back.emplace(x, S::op(back.top().second,\
    \ x));\n    }\n\n    void pop() {\n        assert(!empty());\n        if (front.empty())\
    \ {\n            T x = back.top().first;\n            back.pop();\n          \
    \  front.emplace(x, x);\n            while (!back.empty()) {\n               \
    \ x = back.top().first;\n                back.pop();\n                front.emplace(x,\
    \ S::op(x, front.top().second));\n            }\n        }\n        front.pop();\n\
    \    }\n\n    bool empty() const { return front.empty() && back.empty(); }\n\n\
    \    T fold() const {\n        assert(!empty());\n        if (front.empty()) return\
    \ back.top().second;\n        if (back.empty()) return front.top().second;\n \
    \       return S::op(front.top().second, back.top().second);\n    }\n\n   private:\n\
    \    std::stack<std::pair<T, T>> front, back;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sliding_window_aggregation.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/queue_operate_all_composite.test.cpp
documentation_of: data-structure/sliding_window_aggregation.hpp
layout: document
title: Sliding Window Aggregation
---

## Description

Sliding window aggregation は，半群 $(T, \cdot)$ を扱い，要素の総和の計算が可能なキューである．スタックを2つ用いてキューをシミュレートする．

## Operations

- `void push(T x)`
    - $x$ をキューの末尾に追加する
    - 時間計算量: $O(1)$
- `void pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `bool empty()`
    - キューが空かどうか判定する
    - 時間計算量: $O(1)$
- `T fold()`
    - キューの要素全体の演算結果を返す
    - 時間計算量: $O(1)$

## Reference

- [Sliding Window Aggregation](https://scrapbox.io/data-structures/Sliding_Window_Aggregation)
- [Constant-Time Sliding Window Aggregation](http://hirzels.com/martin/papers/tr15-rc25574-daba.pdf)