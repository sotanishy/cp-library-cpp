---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/deque_operate_all_composite.test.cpp
    title: test/yosupo/deque_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/foldable_deque.hpp\"\n#include <cassert>\n\
    #include <stack>\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ S>\nclass FoldableDeque {\n    using T = typename S::T;\n\npublic:\n    void\
    \ push_front(const T& x) {\n        if (front.empty()) front.emplace(x, x);\n\
    \        else front.emplace(x, S::op(x, front.top().second));\n    }\n\n    void\
    \ push_back(const T& x) {\n        if (back.empty()) back.emplace(x, x);\n   \
    \     else back.emplace(x, S::op(back.top().second, x));\n    }\n\n    void pop_front()\
    \ {\n        assert(!empty());\n        if (front.empty()) {\n            std::vector<T>\
    \ xs;\n            while (!back.empty()) {\n                xs.push_back(back.top().first);\n\
    \                back.pop();\n            }\n            int n = xs.size();\n\
    \            for (int i = n / 2; i < n; ++i) push_front(xs[i]);\n            for\
    \ (int i = n / 2 - 1; i >= 0; --i) push_back(xs[i]);\n        }\n        front.pop();\n\
    \    }\n\n    void pop_back() {\n        assert(!empty());\n        if (back.empty())\
    \ {\n            std::vector<T> xs;\n            while (!front.empty()) {\n  \
    \              xs.push_back(front.top().first);\n                front.pop();\n\
    \            }\n            int n = xs.size();\n            for (int i = n / 2\
    \ - 1; i >= 0; --i) push_front(xs[i]);\n            for (int i = n / 2; i < n;\
    \ ++i) push_back(xs[i]);\n        }\n        back.pop();\n    }\n\n    bool empty()\
    \ const {\n        return front.empty() && back.empty();\n    }\n\n    T fold()\
    \ const {\n        assert(!empty());\n        if (front.empty()) return back.top().second;\n\
    \        if (back.empty()) return front.top().second;\n        return S::op(front.top().second,\
    \ back.top().second);\n    }\n\nprivate:\n    std::stack<std::pair<T, T>> front,\
    \ back;\n};\n\n"
  code: "#pragma once\n#include <cassert>\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename S>\nclass FoldableDeque {\n    using T\
    \ = typename S::T;\n\npublic:\n    void push_front(const T& x) {\n        if (front.empty())\
    \ front.emplace(x, x);\n        else front.emplace(x, S::op(x, front.top().second));\n\
    \    }\n\n    void push_back(const T& x) {\n        if (back.empty()) back.emplace(x,\
    \ x);\n        else back.emplace(x, S::op(back.top().second, x));\n    }\n\n \
    \   void pop_front() {\n        assert(!empty());\n        if (front.empty())\
    \ {\n            std::vector<T> xs;\n            while (!back.empty()) {\n   \
    \             xs.push_back(back.top().first);\n                back.pop();\n \
    \           }\n            int n = xs.size();\n            for (int i = n / 2;\
    \ i < n; ++i) push_front(xs[i]);\n            for (int i = n / 2 - 1; i >= 0;\
    \ --i) push_back(xs[i]);\n        }\n        front.pop();\n    }\n\n    void pop_back()\
    \ {\n        assert(!empty());\n        if (back.empty()) {\n            std::vector<T>\
    \ xs;\n            while (!front.empty()) {\n                xs.push_back(front.top().first);\n\
    \                front.pop();\n            }\n            int n = xs.size();\n\
    \            for (int i = n / 2 - 1; i >= 0; --i) push_front(xs[i]);\n       \
    \     for (int i = n / 2; i < n; ++i) push_back(xs[i]);\n        }\n        back.pop();\n\
    \    }\n\n    bool empty() const {\n        return front.empty() && back.empty();\n\
    \    }\n\n    T fold() const {\n        assert(!empty());\n        if (front.empty())\
    \ return back.top().second;\n        if (back.empty()) return front.top().second;\n\
    \        return S::op(front.top().second, back.top().second);\n    }\n\nprivate:\n\
    \    std::stack<std::pair<T, T>> front, back;\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/foldable_deque.hpp
  requiredBy: []
  timestamp: '2022-08-29 11:20:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/deque_operate_all_composite.test.cpp
documentation_of: data-structure/foldable_deque.hpp
layout: document
title: Foldable Deque
---

## Description

Stack 2つで deque をシミュレートする技法で，半群要素の総積の計算が可能な deque を作ることができる． Sliding window aggregation の deque 版である．

## Operations

- `void push_front(T x)`
    - $x$ を deque の先頭に追加する
    - 時間計算量: $O(1)$
- `void push_back(T x)`
    - $x$ を deque の末尾に追加する
    - 時間計算量: $O(1)$
- `void pop_front()`
    - deque の先頭要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `void pop_back()`
    - deque の先頭要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `bool empty()`
    - deque が空かどうか判定する
    - 時間計算量: $O(1)$
- `T fold()`
    - deque の要素の総積を返す
    - 時間計算量: $O(1)$

## Reference

- [Amortize analysis of Deque with 2 Stack - slideshare](https://www.slideshare.net/catupper/amortize-analysis-of-deque-with-2-stack)
