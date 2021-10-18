---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
    title: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/dynamic_segment_tree.cpp\"\n#include\
    \ <memory>\n\ntemplate <typename M>\nclass DynamicSegmentTree {\n    using T =\
    \ typename M::T;\n\npublic:\n    DynamicSegmentTree() = default;\n    explicit\
    \ DynamicSegmentTree(long long n) : root(std::make_unique<Node>()) {\n       \
    \ size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T operator[](long\
    \ long k) const {\n        return fold(k, k + 1);\n    }\n\n    void update(long\
    \ long k, const T& x) const { update(k, x, root, 0, size); }\n\n    T fold(long\
    \ long l, long long r) const { return fold(l, r, root, 0, size); }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node\
    \ {\n        T val;\n        node_ptr left, right;\n        Node() : val(M::id),\
    \ left(nullptr), right(nullptr) {}\n    };\n\n    const node_ptr root;\n    long\
    \ long size;\n\n    void update(long long k, const T& x, const node_ptr& n, long\
    \ long l, long long r) const {\n        if (r - l == 1) {\n            n->val\
    \ = x;\n            return;\n        }\n        long long m = (l + r) / 2;\n \
    \       if (k < m) {\n            if (!n->left) n->left = std::make_unique<Node>();\n\
    \            update(k, x, n->left, l, m);\n            n->val = M::op(n->left->val,\
    \ n->right ? n->right->val : M::id);\n        } else {\n            if (!n->right)\
    \ n->right = std::make_unique<Node>();\n            update(k, x, n->right, m,\
    \ r);\n            n->val = M::op(n->left ? n->left->val : M::id, n->right->val);\n\
    \        }\n    }\n\n    T fold(long long a, long long b, const node_ptr& n, long\
    \ long l, long long r) const {\n        if (r <= a || b <= l) return M::id;\n\
    \        if (a <= l && r <= b) return n->val;\n        long long m = (l + r) /\
    \ 2;\n        T vl = n->left ? fold(a, b, n->left, l, m) : M::id;\n        T vr\
    \ = n->right ? fold(a, b, n->right, m, r) : M::id;\n        return M::op(vl, vr);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <memory>\n\ntemplate <typename M>\nclass DynamicSegmentTree\
    \ {\n    using T = typename M::T;\n\npublic:\n    DynamicSegmentTree() = default;\n\
    \    explicit DynamicSegmentTree(long long n) : root(std::make_unique<Node>())\
    \ {\n        size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T operator[](long\
    \ long k) const {\n        return fold(k, k + 1);\n    }\n\n    void update(long\
    \ long k, const T& x) const { update(k, x, root, 0, size); }\n\n    T fold(long\
    \ long l, long long r) const { return fold(l, r, root, 0, size); }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node\
    \ {\n        T val;\n        node_ptr left, right;\n        Node() : val(M::id),\
    \ left(nullptr), right(nullptr) {}\n    };\n\n    const node_ptr root;\n    long\
    \ long size;\n\n    void update(long long k, const T& x, const node_ptr& n, long\
    \ long l, long long r) const {\n        if (r - l == 1) {\n            n->val\
    \ = x;\n            return;\n        }\n        long long m = (l + r) / 2;\n \
    \       if (k < m) {\n            if (!n->left) n->left = std::make_unique<Node>();\n\
    \            update(k, x, n->left, l, m);\n            n->val = M::op(n->left->val,\
    \ n->right ? n->right->val : M::id);\n        } else {\n            if (!n->right)\
    \ n->right = std::make_unique<Node>();\n            update(k, x, n->right, m,\
    \ r);\n            n->val = M::op(n->left ? n->left->val : M::id, n->right->val);\n\
    \        }\n    }\n\n    T fold(long long a, long long b, const node_ptr& n, long\
    \ long l, long long r) const {\n        if (r <= a || b <= l) return M::id;\n\
    \        if (a <= l && r <= b) return n->val;\n        long long m = (l + r) /\
    \ 2;\n        T vl = n->left ? fold(a, b, n->left, l, m) : M::id;\n        T vr\
    \ = n->right ? fold(a, b, n->right, m, r) : M::id;\n        return M::op(vl, vr);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/dynamic_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-01-29 22:05:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
documentation_of: data-structure/segtree/dynamic_segment_tree.cpp
layout: document
title: Dynamic Segment Tree
---

## Description

動的セグメント木は，モノイド $(T, \cdot, e)$ の列に対する一点更新と区間取得を提供するデータ構造である．必要なノードだけを動的に構築することで， $n$ が非常に大きい場合でも効率的に値を管理することができる．

空間計算量: $O(m\log n)$．$m$ は追加した要素の数

## Operations

- `DynamicSegmentTree(long long n)`
    - サイズ`n`で要素がすべて単位元 $e$ の動的セグメント木を構築する
    - 時間計算量: $O(\log n)$
- `T operator[](long long k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log n)$
- `void update(long long k, T x)`
    - $k$ 番目の要素を $x$ に更新する
    - 時間計算量: $O(\log n)$
- `T fold(long long l, long long r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(\log n)$