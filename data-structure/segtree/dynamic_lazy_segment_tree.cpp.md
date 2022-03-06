---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_F.dynamic_lazy_segment_tree.test.cpp
    title: test/aoj/DSL_2_F.dynamic_lazy_segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Dynamic Segment Tree with Lazy Propagation
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/dynamic_lazy_segment_tree.cpp\"\n\
    #include <memory>\n\n/*\n * @brief Dynamic Segment Tree with Lazy Propagation\n\
    \ */\ntemplate <typename M, typename O, typename M::T (*act)(typename M::T, typename\
    \ O::T)>\nclass DynamicLazySegmentTree {\n    using T = typename M::T;\n    using\
    \ E = typename O::T;\n\npublic:\n    DynamicLazySegmentTree() = default;\n   \
    \ explicit DynamicLazySegmentTree(long long n) : root(std::make_unique<Node>())\
    \ {\n        size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T operator[](long\
    \ long k) const {\n        return fold(k, k + 1);\n    }\n\n    void update(long\
    \ long l, long long r, const E& x) const { update(l, r, x, root, 0, size); }\n\
    \n    T fold(long long l, long long r) const { return fold(l, r, root, 0, size);\
    \ }\n\nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        E lazy;\n        std::unique_ptr<Node>\
    \ left, right;\n        Node() : val(M::id()), lazy(O::id()), left(nullptr), right(nullptr)\
    \ {}\n    };\n\n    const node_ptr root;\n    long long size;\n\n    void push(const\
    \ node_ptr& n) const {\n        if (n->lazy == O::id()) return;\n        if (!n->left)\
    \ n->left = std::make_unique<Node>();\n        n->left->lazy = O::op(n->left->lazy,\
    \ n->lazy);\n        if (!n->right) n->right = std::make_unique<Node>();\n   \
    \     n->right->lazy = O::op(n->right->lazy, n->lazy);\n        n->val = act(n->val,\
    \ n->lazy);\n        n->lazy = O::id();\n    }\n\n    void update(long long a,\
    \ long long b, const E& x, const node_ptr& n, long long l, long long r) const\
    \ {\n        push(n);\n        if (r <= a || b <= l) return;\n        if (a <=\
    \ l && r <= b) {\n            n->lazy = O::op(n->lazy, x);\n            push(n);\n\
    \            return;\n        }\n        long long m = (l + r) / 2;\n        if\
    \ (!n->left) n->left = std::make_unique<Node>();\n        update(a, b, x, n->left,\
    \ l, m);\n        if (!n->right) n->right = std::make_unique<Node>();\n      \
    \  update(a, b, x, n->right, m, r);\n        n->val = M::op(n->left->val, n->right->val);\n\
    \    }\n\n    T fold(long long a, long long b, const node_ptr& n, long long l,\
    \ long long r) const {\n        push(n);\n        if (r <= a || b <= l) return\
    \ M::id();\n        if (a <= l && r <= b) return n->val;\n        long long m\
    \ = (l + r) / 2;\n        T vl = n->left ? fold(a, b, n->left, l, m) : M::id();\n\
    \        T vr = n->right ? fold(a, b, n->right, m, r) : M::id();\n        return\
    \ M::op(vl, vr);\n    }\n};\n"
  code: "#pragma once\n#include <memory>\n\n/*\n * @brief Dynamic Segment Tree with\
    \ Lazy Propagation\n */\ntemplate <typename M, typename O, typename M::T (*act)(typename\
    \ M::T, typename O::T)>\nclass DynamicLazySegmentTree {\n    using T = typename\
    \ M::T;\n    using E = typename O::T;\n\npublic:\n    DynamicLazySegmentTree()\
    \ = default;\n    explicit DynamicLazySegmentTree(long long n) : root(std::make_unique<Node>())\
    \ {\n        size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T operator[](long\
    \ long k) const {\n        return fold(k, k + 1);\n    }\n\n    void update(long\
    \ long l, long long r, const E& x) const { update(l, r, x, root, 0, size); }\n\
    \n    T fold(long long l, long long r) const { return fold(l, r, root, 0, size);\
    \ }\n\nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        E lazy;\n        std::unique_ptr<Node>\
    \ left, right;\n        Node() : val(M::id()), lazy(O::id()), left(nullptr), right(nullptr)\
    \ {}\n    };\n\n    const node_ptr root;\n    long long size;\n\n    void push(const\
    \ node_ptr& n) const {\n        if (n->lazy == O::id()) return;\n        if (!n->left)\
    \ n->left = std::make_unique<Node>();\n        n->left->lazy = O::op(n->left->lazy,\
    \ n->lazy);\n        if (!n->right) n->right = std::make_unique<Node>();\n   \
    \     n->right->lazy = O::op(n->right->lazy, n->lazy);\n        n->val = act(n->val,\
    \ n->lazy);\n        n->lazy = O::id();\n    }\n\n    void update(long long a,\
    \ long long b, const E& x, const node_ptr& n, long long l, long long r) const\
    \ {\n        push(n);\n        if (r <= a || b <= l) return;\n        if (a <=\
    \ l && r <= b) {\n            n->lazy = O::op(n->lazy, x);\n            push(n);\n\
    \            return;\n        }\n        long long m = (l + r) / 2;\n        if\
    \ (!n->left) n->left = std::make_unique<Node>();\n        update(a, b, x, n->left,\
    \ l, m);\n        if (!n->right) n->right = std::make_unique<Node>();\n      \
    \  update(a, b, x, n->right, m, r);\n        n->val = M::op(n->left->val, n->right->val);\n\
    \    }\n\n    T fold(long long a, long long b, const node_ptr& n, long long l,\
    \ long long r) const {\n        push(n);\n        if (r <= a || b <= l) return\
    \ M::id();\n        if (a <= l && r <= b) return n->val;\n        long long m\
    \ = (l + r) / 2;\n        T vl = n->left ? fold(a, b, n->left, l, m) : M::id();\n\
    \        T vr = n->right ? fold(a, b, n->right, m, r) : M::id();\n        return\
    \ M::op(vl, vr);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/dynamic_lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2022-03-06 20:10:50+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_F.dynamic_lazy_segment_tree.test.cpp
documentation_of: data-structure/segtree/dynamic_lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/data-structure/segtree/dynamic_lazy_segment_tree.cpp
- /library/data-structure/segtree/dynamic_lazy_segment_tree.cpp.html
title: Dynamic Segment Tree with Lazy Propagation
---
