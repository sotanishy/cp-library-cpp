---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/dual_segment_tree.md
    document_title: Dual Segment Tree
    links: []
  bundledCode: "#line 1 \"data-structure/dual_segment_tree.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Dual Segment Tree\n * @docs docs/data-structure/dual_segment_tree.md\n\
    \ */\ntemplate <typename M>\nclass DualSegmentTree {\n    using T = typename M::T;\n\
    \npublic:\n    explicit DualSegmentTree(int n) {\n        size = 1;\n        height\
    \ = 1;\n        while (size < n) size <<= 1, height++;\n        lazy.resize(2\
    \ * size, M::id);\n    }\n\n    T operator[](int k) {\n        k += size;\n  \
    \      propagate(k);\n        return lazy[k];\n    }\n\n    void update(int l,\
    \ int r, const T& x) {\n        l += size;\n        r += size;\n        propagate(l);\n\
    \        propagate(r - 1);\n        for (; l < r; l >>= 1, r >>= 1) {\n      \
    \      if (l & 1) lazy[l] = M::op(lazy[l], x), l++;\n            if (r & 1) --r,\
    \ lazy[r] = M::op(lazy[r], x);\n        }\n    }\n\nprivate:\n    int size, height;\n\
    \    std::vector<T> lazy;\n\n    void push(int k) {\n        if (lazy[k] == M::id)\
    \ return;\n        lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);\n        lazy[2\
    \ * k + 1] = M::op(lazy[2 * k + 1], lazy[k]);\n        lazy[k] = M::id;\n    }\n\
    \n    void propagate(int k) {\n        for (int i = height; i > 0; i--) push(k\
    \ >> i);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Dual Segment Tree\n * @docs docs/data-structure/dual_segment_tree.md\n\
    \ */\ntemplate <typename M>\nclass DualSegmentTree {\n    using T = typename M::T;\n\
    \npublic:\n    explicit DualSegmentTree(int n) {\n        size = 1;\n        height\
    \ = 1;\n        while (size < n) size <<= 1, height++;\n        lazy.resize(2\
    \ * size, M::id);\n    }\n\n    T operator[](int k) {\n        k += size;\n  \
    \      propagate(k);\n        return lazy[k];\n    }\n\n    void update(int l,\
    \ int r, const T& x) {\n        l += size;\n        r += size;\n        propagate(l);\n\
    \        propagate(r - 1);\n        for (; l < r; l >>= 1, r >>= 1) {\n      \
    \      if (l & 1) lazy[l] = M::op(lazy[l], x), l++;\n            if (r & 1) --r,\
    \ lazy[r] = M::op(lazy[r], x);\n        }\n    }\n\nprivate:\n    int size, height;\n\
    \    std::vector<T> lazy;\n\n    void push(int k) {\n        if (lazy[k] == M::id)\
    \ return;\n        lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);\n        lazy[2\
    \ * k + 1] = M::op(lazy[2 * k + 1], lazy[k]);\n        lazy[k] = M::id;\n    }\n\
    \n    void propagate(int k) {\n        for (int i = height; i > 0; i--) push(k\
    \ >> i);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_E.test.cpp
documentation_of: data-structure/dual_segment_tree.cpp
layout: document
redirect_from:
- /library/data-structure/dual_segment_tree.cpp
- /library/data-structure/dual_segment_tree.cpp.html
title: Dual Segment Tree
---
# Dual Segment Tree

双対セグメント木は，作用素モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，列に対する区間更新と一点クエリを処理できるデータ構造である．これは遅延伝搬セグメント木から作用素のみを取り出した構造である．

一点更新・区間クエリはセグメント木を使用する．

区間更新・区間クエリは遅延伝搬セグメント木を使用する．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `DualSegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の双対セグメント木を構築する
    - 時間計算量: $O(n)$

## Methods

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(1)$
- `void update(int l, int r, const T& x)`
    - $i \in [l, r)$ について $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$