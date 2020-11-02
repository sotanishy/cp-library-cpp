---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.slide_min.test.cpp
    title: test/aoj/DSL_3_D.slide_min.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/slide_min.md
    document_title: Sliding Window Minimum
    links: []
  bundledCode: "#line 2 \"data-structure/slide_min.cpp\"\n#include <deque>\n#include\
    \ <functional>\n#include <utility>\n\n/*\n * @brief Sliding Window Minimum\n *\
    \ @docs docs/data-structure/slide_min.md\n */\ntemplate <typename T, typename\
    \ Compare = std::less<>>\nclass SlideMin {\npublic:\n    void push(T x) {\n  \
    \      while (!dq.empty() && !cmp(dq.back().first, x)) dq.pop_back();\n      \
    \  dq.emplace_back(x, r++);\n    }\n\n    void pop() {\n        if (dq.front().second\
    \ == l) dq.pop_front();\n        ++l;\n    }\n\n    T get() const {\n        return\
    \ dq.front().first;\n    }\n\nprivate:\n    int l = 0, r = 0;\n    std::deque<std::pair<T,\
    \ int>> dq;\n    Compare cmp;\n};\n"
  code: "#pragma once\n#include <deque>\n#include <functional>\n#include <utility>\n\
    \n/*\n * @brief Sliding Window Minimum\n * @docs docs/data-structure/slide_min.md\n\
    \ */\ntemplate <typename T, typename Compare = std::less<>>\nclass SlideMin {\n\
    public:\n    void push(T x) {\n        while (!dq.empty() && !cmp(dq.back().first,\
    \ x)) dq.pop_back();\n        dq.emplace_back(x, r++);\n    }\n\n    void pop()\
    \ {\n        if (dq.front().second == l) dq.pop_front();\n        ++l;\n    }\n\
    \n    T get() const {\n        return dq.front().first;\n    }\n\nprivate:\n \
    \   int l = 0, r = 0;\n    std::deque<std::pair<T, int>> dq;\n    Compare cmp;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slide_min.cpp
  requiredBy: []
  timestamp: '2020-11-03 02:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.slide_min.test.cpp
documentation_of: data-structure/slide_min.cpp
layout: document
redirect_from:
- /library/data-structure/slide_min.cpp
- /library/data-structure/slide_min.cpp.html
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