---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
    title: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Persistent Segment Tree
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/persistent_segment_tree.cpp\"\n#include\
    \ <vector>\n#include <memory>\n\n/*\n * @brief Persistent Segment Tree\n */\n\
    template <typename M>\nclass PersistentSegmentTree {\n    using T = typename M::T;\n\
    \npublic:\n    PersistentSegmentTree() = default;\n    explicit PersistentSegmentTree(int\
    \ n): PersistentSegmentTree(std::vector<T>(n, M::id)) {}\n    explicit PersistentSegmentTree(const\
    \ std::vector<T>& v) : root(std::make_shared<Node>()) {\n        size = 1;\n \
    \       while (size < (int) v.size()) size <<= 1;\n        build(v, root, 0, size);\n\
    \    }\n\n    T operator[](int k) const {\n        return fold(k, k + 1);\n  \
    \  }\n\n    PersistentSegmentTree update(int k, const T& x) const {\n        return\
    \ PersistentSegmentTree(update(k, x, root, 0, size), size);\n    }\n\n    T fold(int\
    \ l, int r) const {\n        return fold(l, r, root, 0, size);\n    }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        T val;\n        node_ptr left, right;\n        Node() : val(M::id),\
    \ left(nullptr), right(nullptr) {}\n        Node(const T& val, const node_ptr&\
    \ left, const node_ptr& right) : val(val), left(left), right(right) {}\n    };\n\
    \n    node_ptr root;\n    int size;\n\n    PersistentSegmentTree(const node_ptr&\
    \ root, int size) : root(root), size(size) {}\n\n    void build(const std::vector<T>&\
    \ v, const node_ptr& n, int l, int r) const {\n        if (r - l == 1) {\n   \
    \         n->val = l < (int) v.size() ? v[l] : M::id;\n            return;\n \
    \       }\n        int m = (l + r) / 2;\n        n->left = std::make_shared<Node>();\n\
    \        build(v, n->left, l, m);\n        n->right = std::make_shared<Node>();\n\
    \        build(v, n->right, m, r);\n        n->val = M::op(n->left->val, n->right->val);\n\
    \    }\n\n    node_ptr update(int k, const T& x, const node_ptr& n, int l, int\
    \ r) const {\n        if (r - l == 1) {\n            return std::make_shared<Node>(x,\
    \ nullptr, nullptr);\n        }\n        int m = (l + r) / 2;\n        if (k <\
    \ m) {\n            auto left = update(k, x, n->left, l, m);\n            T val\
    \ = M::op(left->val, n->right->val);\n            return std::make_shared<Node>(val,\
    \ left, n->right);\n        } else {\n            auto right = update(k, x, n->right,\
    \ m, r);\n            T val = M::op(n->left->val, right->val);\n            return\
    \ std::make_shared<Node>(val, n->left, right);\n        }\n    }\n\n    T fold(int\
    \ a, int b, const node_ptr& n, int l, int r) const {\n        if (r <= a || b\
    \ <= l) return M::id;\n        if (a <= l && r <= b) return n->val;\n        int\
    \ m = (l + r) / 2;\n        T vl = fold(a, b, n->left, l, m);\n        T vr =\
    \ fold(a, b, n->right, m, r);\n        return M::op(vl, vr);\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <memory>\n\n/*\n * @brief Persistent\
    \ Segment Tree\n */\ntemplate <typename M>\nclass PersistentSegmentTree {\n  \
    \  using T = typename M::T;\n\npublic:\n    PersistentSegmentTree() = default;\n\
    \    explicit PersistentSegmentTree(int n): PersistentSegmentTree(std::vector<T>(n,\
    \ M::id)) {}\n    explicit PersistentSegmentTree(const std::vector<T>& v) : root(std::make_shared<Node>())\
    \ {\n        size = 1;\n        while (size < (int) v.size()) size <<= 1;\n  \
    \      build(v, root, 0, size);\n    }\n\n    T operator[](int k) const {\n  \
    \      return fold(k, k + 1);\n    }\n\n    PersistentSegmentTree update(int k,\
    \ const T& x) const {\n        return PersistentSegmentTree(update(k, x, root,\
    \ 0, size), size);\n    }\n\n    T fold(int l, int r) const {\n        return\
    \ fold(l, r, root, 0, size);\n    }\n\nprivate:\n    struct Node;\n    using node_ptr\
    \ = std::shared_ptr<Node>;\n\n    struct Node {\n        T val;\n        node_ptr\
    \ left, right;\n        Node() : val(M::id), left(nullptr), right(nullptr) {}\n\
    \        Node(const T& val, const node_ptr& left, const node_ptr& right) : val(val),\
    \ left(left), right(right) {}\n    };\n\n    node_ptr root;\n    int size;\n\n\
    \    PersistentSegmentTree(const node_ptr& root, int size) : root(root), size(size)\
    \ {}\n\n    void build(const std::vector<T>& v, const node_ptr& n, int l, int\
    \ r) const {\n        if (r - l == 1) {\n            n->val = l < (int) v.size()\
    \ ? v[l] : M::id;\n            return;\n        }\n        int m = (l + r) / 2;\n\
    \        n->left = std::make_shared<Node>();\n        build(v, n->left, l, m);\n\
    \        n->right = std::make_shared<Node>();\n        build(v, n->right, m, r);\n\
    \        n->val = M::op(n->left->val, n->right->val);\n    }\n\n    node_ptr update(int\
    \ k, const T& x, const node_ptr& n, int l, int r) const {\n        if (r - l ==\
    \ 1) {\n            return std::make_shared<Node>(x, nullptr, nullptr);\n    \
    \    }\n        int m = (l + r) / 2;\n        if (k < m) {\n            auto left\
    \ = update(k, x, n->left, l, m);\n            T val = M::op(left->val, n->right->val);\n\
    \            return std::make_shared<Node>(val, left, n->right);\n        } else\
    \ {\n            auto right = update(k, x, n->right, m, r);\n            T val\
    \ = M::op(n->left->val, right->val);\n            return std::make_shared<Node>(val,\
    \ n->left, right);\n        }\n    }\n\n    T fold(int a, int b, const node_ptr&\
    \ n, int l, int r) const {\n        if (r <= a || b <= l) return M::id;\n    \
    \    if (a <= l && r <= b) return n->val;\n        int m = (l + r) / 2;\n    \
    \    T vl = fold(a, b, n->left, l, m);\n        T vr = fold(a, b, n->right, m,\
    \ r);\n        return M::op(vl, vr);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/persistent_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-10-26 15:26:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
documentation_of: data-structure/segtree/persistent_segment_tree.cpp
layout: document
redirect_from:
- /library/data-structure/segtree/persistent_segment_tree.cpp
- /library/data-structure/segtree/persistent_segment_tree.cpp.html
title: Persistent Segment Tree
---
