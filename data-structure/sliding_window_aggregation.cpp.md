---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/sliding_window_aggregation.md
    document_title: Sliding Window Aggregation
    links: []
  bundledCode: "#line 1 \"data-structure/sliding_window_aggregation.cpp\"\n#include\
    \ <bits/stdc++.h>\n\n/*\n * @brief Sliding Window Aggregation\n * @docs docs/data-structure/sliding_window_aggregation.md\n\
    \ */\ntemplate <typename M>\nclass SlidingWindowAggregation {\n    using T = typename\
    \ M::T;\n\npublic:\n    void push(T x) {\n        if (back.empty()) back.emplace(x,\
    \ x);\n        else back.emplace(x, M::op(back.top().second, x));\n    }\n\n \
    \   void pop() {\n        if (front.empty()) {\n            if (back.empty())\
    \ return;\n            T x = back.top().first;\n            back.pop();\n    \
    \        front.emplace(x, x);\n            while (!back.empty()) {\n         \
    \       x = back.top().first;\n                back.pop();\n                front.emplace(x,\
    \ M::op(x, front.top().second));\n            }\n        }\n        front.pop();\n\
    \    }\n\n    T fold() const {\n        T ret = M::id;\n        if (!front.empty())\
    \ ret = M::op(ret, front.top().second);\n        if (!back.empty()) ret = M::op(ret,\
    \ back.top().second);\n        return ret;\n    }\n\nprivate:\n    std::stack<std::pair<T,\
    \ T>> front, back;\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Sliding Window Aggregation\n *\
    \ @docs docs/data-structure/sliding_window_aggregation.md\n */\ntemplate <typename\
    \ M>\nclass SlidingWindowAggregation {\n    using T = typename M::T;\n\npublic:\n\
    \    void push(T x) {\n        if (back.empty()) back.emplace(x, x);\n       \
    \ else back.emplace(x, M::op(back.top().second, x));\n    }\n\n    void pop()\
    \ {\n        if (front.empty()) {\n            if (back.empty()) return;\n   \
    \         T x = back.top().first;\n            back.pop();\n            front.emplace(x,\
    \ x);\n            while (!back.empty()) {\n                x = back.top().first;\n\
    \                back.pop();\n                front.emplace(x, M::op(x, front.top().second));\n\
    \            }\n        }\n        front.pop();\n    }\n\n    T fold() const {\n\
    \        T ret = M::id;\n        if (!front.empty()) ret = M::op(ret, front.top().second);\n\
    \        if (!back.empty()) ret = M::op(ret, back.top().second);\n        return\
    \ ret;\n    }\n\nprivate:\n    std::stack<std::pair<T, T>> front, back;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sliding_window_aggregation.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/queue_operate_all_composite.test.cpp
documentation_of: data-structure/sliding_window_aggregation.cpp
layout: document
redirect_from:
- /library/data-structure/sliding_window_aggregation.cpp
- /library/data-structure/sliding_window_aggregation.cpp.html
title: Sliding Window Aggregation
---
# Sliding Window Aggregation

Sliding window aggregation は，モノイド $(T, \cdot, e)$ を扱い，要素全体の演算が可能なキューである．スタックを2つ用いてキューをシミュレートする．

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Member functions

- `void push(T x)`
    - $x$ をキューの末尾に追加する
    - 時間計算量: $O(1)$
- `void pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `T fold()`
    - キューの要素全体の演算結果を返す．キューが空の場合は $e$ を返す
    - 時間計算量: $O(1)$