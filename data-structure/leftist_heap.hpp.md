---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: dp/hu_tucker.hpp
    title: Hu-Tucker Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_arborescence.hpp
    title: Minimum Spanning Arborescence
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2415.test.cpp
    title: test/aoj/2415.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/leftist_heap.hpp\"\n#include <algorithm>\n\
    #include <memory>\n#include <utility>\n\ntemplate <typename T>\nclass LeftistHeap\
    \ {\n   public:\n    LeftistHeap() = default;\n\n    static LeftistHeap meld(LeftistHeap\
    \ a, LeftistHeap b) {\n        return LeftistHeap(meld(std::move(a.root), std::move(b.root)));\n\
    \    }\n\n    std::pair<int, T> top() const {\n        push(root);\n        return\
    \ {root->id, root->val};\n    }\n\n    void pop() {\n        push(root);\n   \
    \     root = meld(std::move(root->left), std::move(root->right));\n    }\n\n \
    \   void push(int id, T x) {\n        root = meld(std::move(root), std::make_unique<Node>(id,\
    \ x));\n    }\n\n    bool empty() const { return root == nullptr; }\n\n    void\
    \ add(T x) { root->lazy += x; }\n\n   private:\n    struct Node;\n    using node_ptr\
    \ = std::unique_ptr<Node>;\n\n    struct Node {\n        node_ptr left, right;\n\
    \        int s;\n        int id;\n        T val, lazy;\n        Node(int id, T\
    \ x) : id(id), val(x), lazy(0) {}\n    };\n\n    node_ptr root = nullptr;\n\n\
    \    explicit LeftistHeap(node_ptr root) : root(std::move(root)) {}\n\n    static\
    \ node_ptr meld(node_ptr a, node_ptr b) {\n        if (!a) return b;\n       \
    \ if (!b) return a;\n        push(a);\n        push(b);\n        if (a->val >\
    \ b->val) std::swap(a, b);\n        a->right = meld(std::move(a->right), std::move(b));\n\
    \        if (!a->left || a->left->s < a->right->s) std::swap(a->left, a->right);\n\
    \        a->s = (a->right ? a->right->s : 0) + 1;\n        return a;\n    }\n\n\
    \    static void push(const node_ptr& t) {\n        if (t->left) t->left->lazy\
    \ += t->lazy;\n        if (t->right) t->right->lazy += t->lazy;\n        t->val\
    \ += t->lazy;\n        t->lazy = 0;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <memory>\n#include <utility>\n\
    \ntemplate <typename T>\nclass LeftistHeap {\n   public:\n    LeftistHeap() =\
    \ default;\n\n    static LeftistHeap meld(LeftistHeap a, LeftistHeap b) {\n  \
    \      return LeftistHeap(meld(std::move(a.root), std::move(b.root)));\n    }\n\
    \n    std::pair<int, T> top() const {\n        push(root);\n        return {root->id,\
    \ root->val};\n    }\n\n    void pop() {\n        push(root);\n        root =\
    \ meld(std::move(root->left), std::move(root->right));\n    }\n\n    void push(int\
    \ id, T x) {\n        root = meld(std::move(root), std::make_unique<Node>(id,\
    \ x));\n    }\n\n    bool empty() const { return root == nullptr; }\n\n    void\
    \ add(T x) { root->lazy += x; }\n\n   private:\n    struct Node;\n    using node_ptr\
    \ = std::unique_ptr<Node>;\n\n    struct Node {\n        node_ptr left, right;\n\
    \        int s;\n        int id;\n        T val, lazy;\n        Node(int id, T\
    \ x) : id(id), val(x), lazy(0) {}\n    };\n\n    node_ptr root = nullptr;\n\n\
    \    explicit LeftistHeap(node_ptr root) : root(std::move(root)) {}\n\n    static\
    \ node_ptr meld(node_ptr a, node_ptr b) {\n        if (!a) return b;\n       \
    \ if (!b) return a;\n        push(a);\n        push(b);\n        if (a->val >\
    \ b->val) std::swap(a, b);\n        a->right = meld(std::move(a->right), std::move(b));\n\
    \        if (!a->left || a->left->s < a->right->s) std::swap(a->left, a->right);\n\
    \        a->s = (a->right ? a->right->s : 0) + 1;\n        return a;\n    }\n\n\
    \    static void push(const node_ptr& t) {\n        if (t->left) t->left->lazy\
    \ += t->lazy;\n        if (t->right) t->right->lazy += t->lazy;\n        t->val\
    \ += t->lazy;\n        t->lazy = 0;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/leftist_heap.hpp
  requiredBy:
  - dp/hu_tucker.hpp
  - graph/minimum_spanning_arborescence.hpp
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/directedmst.test.cpp
  - test/aoj/2415.test.cpp
documentation_of: data-structure/leftist_heap.hpp
layout: document
title: Leftist Heap
---

## Description

Leftist heap は，meldable heap (マージ可能ヒープ) の一種である．

## Operations

- `static LeftistHeap meld(LeftistHeap a, LeftistHeap b)`
    - $a$ と $b$ を併合する
    - 時間計算量: $O(\log n)$
- `pair<int, T> top()`
    - 最小値とその id を返す
    - 時間計算量: $O(1)$
- `void pop()`
    - 最小値を削除する
    - 時間計算量: $O(\log n)$
- `void push(int id, T x)`
    - 値 $x$ を持つ要素 $id$ を追加する
    - 時間計算量: $O(\log n)$
- `void add(T x)`
    - 全ての要素の値に $x$ を加算する
    - 時間計算量: $O(1)$

## Reference

- [Leftist Heap & Skew Heap](http://hos.ac/blog/#blog0001)