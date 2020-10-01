---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
    title: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dynamic_segment_tree.md
    document_title: Dynamic Segment Tree
    links: []
  bundledCode: "#line 1 \"data-structure/dynamic_segment_tree.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Dynamic Segment Tree\n * @docs docs/data-structure/dynamic_segment_tree.md\n\
    \ */\ntemplate <typename M>\nclass DynamicSegmentTree {\n    using T = typename\
    \ M::T;\n\npublic:\n    DynamicSegmentTree() = default;\n    explicit DynamicSegmentTree(long\
    \ long n) : root(std::make_unique<Node>()) {\n        size = 1;\n        while\
    \ (size < n) size <<= 1;\n    }\n\n    T operator[](long long k) const {\n   \
    \     return fold(k, k + 1);\n    }\n\n    void update(long long k, const T& x)\
    \ const { update(k, x, root, 0, size); }\n\n    T fold(long long l, long long\
    \ r) const { return fold(l, r, root, 0, size); }\n\nprivate:\n    struct Node\
    \ {\n        std::unique_ptr<Node> left, right;\n        T val;\n        Node()\
    \ : left(nullptr), right(nullptr), val(M::id) {}\n    };\n\n    std::unique_ptr<Node>\
    \ const root;\n    long long size;\n\n    void update(long long k, const T& x,\
    \ std::unique_ptr<Node> const& n, long long l, long long r) const {\n        if\
    \ (r - l == 1) {\n            n->val = x;\n            return;\n        }\n  \
    \      long long m = (l + r) / 2;\n        if (k < m) {\n            if (!n->left)\
    \ n->left = std::make_unique<Node>();\n            update(k, x, n->left, l, m);\n\
    \            n->val = M::op(n->left->val, n->right ? n->right->val : M::id);\n\
    \        } else {\n            if (!n->right) n->right = std::make_unique<Node>();\n\
    \            update(k, x, n->right, m, r);\n            n->val = M::op(n->left\
    \ ? n->left->val : M::id, n->right->val);\n        }\n    }\n\n    T fold(long\
    \ long a, long long b, std::unique_ptr<Node> const& n, long long l, long long\
    \ r) const {\n        if (r <= a || b <= l) return M::id;\n        if (a <= l\
    \ && r <= b) return n->val;\n        long long m = (l + r) / 2;\n        T vl\
    \ = n->left ? fold(a, b, n->left, l, m) : M::id;\n        T vr = n->right ? fold(a,\
    \ b, n->right, m, r) : M::id;\n        return M::op(vl, vr);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Dynamic Segment Tree\n * @docs\
    \ docs/data-structure/dynamic_segment_tree.md\n */\ntemplate <typename M>\nclass\
    \ DynamicSegmentTree {\n    using T = typename M::T;\n\npublic:\n    DynamicSegmentTree()\
    \ = default;\n    explicit DynamicSegmentTree(long long n) : root(std::make_unique<Node>())\
    \ {\n        size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T operator[](long\
    \ long k) const {\n        return fold(k, k + 1);\n    }\n\n    void update(long\
    \ long k, const T& x) const { update(k, x, root, 0, size); }\n\n    T fold(long\
    \ long l, long long r) const { return fold(l, r, root, 0, size); }\n\nprivate:\n\
    \    struct Node {\n        std::unique_ptr<Node> left, right;\n        T val;\n\
    \        Node() : left(nullptr), right(nullptr), val(M::id) {}\n    };\n\n   \
    \ std::unique_ptr<Node> const root;\n    long long size;\n\n    void update(long\
    \ long k, const T& x, std::unique_ptr<Node> const& n, long long l, long long r)\
    \ const {\n        if (r - l == 1) {\n            n->val = x;\n            return;\n\
    \        }\n        long long m = (l + r) / 2;\n        if (k < m) {\n       \
    \     if (!n->left) n->left = std::make_unique<Node>();\n            update(k,\
    \ x, n->left, l, m);\n            n->val = M::op(n->left->val, n->right ? n->right->val\
    \ : M::id);\n        } else {\n            if (!n->right) n->right = std::make_unique<Node>();\n\
    \            update(k, x, n->right, m, r);\n            n->val = M::op(n->left\
    \ ? n->left->val : M::id, n->right->val);\n        }\n    }\n\n    T fold(long\
    \ long a, long long b, std::unique_ptr<Node> const& n, long long l, long long\
    \ r) const {\n        if (r <= a || b <= l) return M::id;\n        if (a <= l\
    \ && r <= b) return n->val;\n        long long m = (l + r) / 2;\n        T vl\
    \ = n->left ? fold(a, b, n->left, l, m) : M::id;\n        T vr = n->right ? fold(a,\
    \ b, n->right, m, r) : M::id;\n        return M::op(vl, vr);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-10-01 22:29:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
documentation_of: data-structure/dynamic_segment_tree.cpp
layout: document
redirect_from:
- /library/data-structure/dynamic_segment_tree.cpp
- /library/data-structure/dynamic_segment_tree.cpp.html
title: Dynamic Segment Tree
---
# Dynamic Segment Tree

動的セグメント木は，モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，列に対する一点更新と区間クエリを処理できるデータ構造である．

必要なノードだけを構築することで， $n$ が非常に大きい場合でも効率的に値を管理することができる．$n$ が十分小さいとき (およそ $10^6$ 以下) は，通常のセグメント木を使用する．

空間計算量: $O(m\lg n)$．$m$ は追加した要素の数である

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `DynamicSegmentTree(long long n)`
    - サイズ`n`で要素がすべて単位元 $e$ の動的セグメント木を構築する
    - 時間計算量: $O(\lg n)$

## Member functions

- `T operator[](long long k)`
    - $a_k$ を返す
    - 時間計算量: $O(\lg n)$
- `void update(long long k, T x)`
    - $a_k$ を $x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(long long l, long long r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ を計算する．$l = r$ ならば $e$ を返す．
    - 時間計算量: $O(\lg n)$