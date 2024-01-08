---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.splay_tree.test.cpp
    title: test/aoj/1508.splay_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_reverse_range_sum.splay_tree.test.cpp
    title: test/yosupo/range_reverse_range_sum.splay_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/bst/splay_tree.hpp\"\n#include <cassert>\n\
    #include <memory>\n#include <utility>\n\ntemplate <typename M>\nclass SplayTree\
    \ {\n    using T = typename M::T;\n\n   public:\n    SplayTree() = default;\n\n\
    \    static SplayTree join(SplayTree l, SplayTree r) {\n        return SplayTree(join(std::move(l.root),\
    \ std::move(r.root)));\n    }\n\n    std::pair<SplayTree, SplayTree> split(int\
    \ k) {\n        auto p = split(std::move(root), k);\n        return {SplayTree(std::move(p.first)),\
    \ SplayTree(std::move(p.second))};\n    }\n\n    void update(int k, const T& x)\
    \ {\n        root = splay(std::move(root), k);\n        root->val = x;\n     \
    \   recalc(root);\n    }\n\n    T fold(int l, int r) {\n        assert(0 <= l\
    \ && l <= r && r <= size());\n        if (l == r) return M::id();\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        auto ret = b->sum;\n        root =\
    \ join(join(std::move(a), std::move(b)), std::move(c));\n        return ret;\n\
    \    }\n\n    void reverse(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= size());\n        if (l == r) return;\n        node_ptr a, b, c;\n    \
    \    std::tie(a, b) = split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b),\
    \ r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a), std::move(b)),\
    \ std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n        auto\
    \ p = split(std::move(root), k);\n        root = join(join(std::move(p.first),\
    \ std::make_unique<Node>(x)),\n                    std::move(p.second));\n   \
    \ }\n\n    void erase(int k) {\n        root = splay(std::move(root), k);\n  \
    \      root = join(std::move(root->left), std::move(root->right));\n    }\n\n\
    \    void push_front(const T& x) {\n        root = join(std::make_unique<Node>(x),\
    \ std::move(root));\n    }\n\n    void push_back(const T& x) {\n        root =\
    \ join(std::move(root), std::make_unique<Node>(x));\n    }\n\n    void pop_front()\
    \ { root = split(std::move(root), 1).second; }\n\n    void pop_back() { root =\
    \ split(std::move(root), size() - 1).first; }\n\n    int size() const { return\
    \ size(root); }\n\n    bool empty() const { return size() == 0; }\n\n   private:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node\
    \ {\n        node_ptr left, right;\n        T val, sum;\n        int sz;\n   \
    \     bool rev;\n\n        Node() : Node(M::id()) {}\n        Node(const T& x)\n\
    \            : left(nullptr),\n              right(nullptr),\n              val(x),\n\
    \              sum(x),\n              sz(1),\n              rev(false) {}\n  \
    \  };\n\n    node_ptr root;\n\n    explicit SplayTree(node_ptr root) : root(std::move(root))\
    \ {}\n\n    static int size(const node_ptr& t) { return t ? t->sz : 0; }\n\n \
    \   static void recalc(const node_ptr& t) {\n        if (!t) return;\n       \
    \ t->sz = size(t->left) + 1 + size(t->right);\n        t->sum = t->val;\n    \
    \    if (t->left) t->sum = M::op(t->left->sum, t->sum);\n        if (t->right)\
    \ t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static void push(const\
    \ node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left, t->right);\n\
    \            if (t->left) t->left->rev ^= true;\n            if (t->right) t->right->rev\
    \ ^= true;\n            t->rev = false;\n        }\n    }\n\n    static node_ptr\
    \ join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n        if (!r) return\
    \ l;\n        l = splay(std::move(l), size(l) - 1);\n        l->right = std::move(r);\n\
    \        recalc(l);\n        return l;\n    }\n\n    static std::pair<node_ptr,\
    \ node_ptr> split(node_ptr t, int k) {\n        assert(0 <= k && k <= size(t));\n\
    \        if (k == 0) return {nullptr, std::move(t)};\n        if (k == size(t))\
    \ return {std::move(t), nullptr};\n        t = splay(std::move(t), k - 1);\n \
    \       auto r = std::move(t->right);\n        t->right = nullptr;\n        recalc(t);\n\
    \        return {std::move(t), std::move(r)};\n    }\n\n    static node_ptr rotate_left(node_ptr\
    \ t) {\n        node_ptr s = std::move(t->right);\n        t->right = std::move(s->left);\n\
    \        s->left = std::move(t);\n        recalc(s->left);\n        recalc(s);\n\
    \        return s;\n    }\n\n    static node_ptr rotate_right(node_ptr t) {\n\
    \        node_ptr s = std::move(t->left);\n        t->left = std::move(s->right);\n\
    \        s->right = std::move(t);\n        recalc(s->right);\n        recalc(s);\n\
    \        return s;\n    }\n\n    static node_ptr splay(node_ptr t, int k) {\n\
    \        assert(0 <= k && k <= size(t));\n        push(t);\n        int lsize\
    \ = size(t->left);\n        if (k == lsize) return t;\n        if (k < lsize)\
    \ {\n            push(t->left);\n            int llsize = size(t->left->left);\n\
    \            if (k < llsize) {\n                t->left->left = splay(std::move(t->left->left),\
    \ k);\n                t = rotate_right(std::move(t));\n            } else if\
    \ (llsize < k) {\n                t->left->right =\n                    splay(std::move(t->left->right),\
    \ k - llsize - 1);\n                t->left = rotate_left(std::move(t->left));\n\
    \            }\n            return rotate_right(std::move(t));\n        } else\
    \ {\n            push(t->right);\n            k -= lsize + 1;\n            int\
    \ rlsize = size(t->right->left);\n            if (k < rlsize) {\n            \
    \    t->right->left = splay(std::move(t->right->left), k);\n                t->right\
    \ = rotate_right(std::move(t->right));\n            } else if (rlsize < k) {\n\
    \                t->right->right =\n                    splay(std::move(t->right->right),\
    \ k - rlsize - 1);\n                t = rotate_left(std::move(t));\n         \
    \   }\n            return rotate_left(std::move(t));\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <utility>\n\
    \ntemplate <typename M>\nclass SplayTree {\n    using T = typename M::T;\n\n \
    \  public:\n    SplayTree() = default;\n\n    static SplayTree join(SplayTree\
    \ l, SplayTree r) {\n        return SplayTree(join(std::move(l.root), std::move(r.root)));\n\
    \    }\n\n    std::pair<SplayTree, SplayTree> split(int k) {\n        auto p =\
    \ split(std::move(root), k);\n        return {SplayTree(std::move(p.first)), SplayTree(std::move(p.second))};\n\
    \    }\n\n    void update(int k, const T& x) {\n        root = splay(std::move(root),\
    \ k);\n        root->val = x;\n        recalc(root);\n    }\n\n    T fold(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= size());\n        if (l\
    \ == r) return M::id();\n        node_ptr a, b, c;\n        std::tie(a, b) = split(std::move(root),\
    \ l);\n        std::tie(b, c) = split(std::move(b), r - l);\n        auto ret\
    \ = b->sum;\n        root = join(join(std::move(a), std::move(b)), std::move(c));\n\
    \        return ret;\n    }\n\n    void reverse(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= size());\n        if (l == r) return;\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto p = split(std::move(root), k);\n        root = join(join(std::move(p.first),\
    \ std::make_unique<Node>(x)),\n                    std::move(p.second));\n   \
    \ }\n\n    void erase(int k) {\n        root = splay(std::move(root), k);\n  \
    \      root = join(std::move(root->left), std::move(root->right));\n    }\n\n\
    \    void push_front(const T& x) {\n        root = join(std::make_unique<Node>(x),\
    \ std::move(root));\n    }\n\n    void push_back(const T& x) {\n        root =\
    \ join(std::move(root), std::make_unique<Node>(x));\n    }\n\n    void pop_front()\
    \ { root = split(std::move(root), 1).second; }\n\n    void pop_back() { root =\
    \ split(std::move(root), size() - 1).first; }\n\n    int size() const { return\
    \ size(root); }\n\n    bool empty() const { return size() == 0; }\n\n   private:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node\
    \ {\n        node_ptr left, right;\n        T val, sum;\n        int sz;\n   \
    \     bool rev;\n\n        Node() : Node(M::id()) {}\n        Node(const T& x)\n\
    \            : left(nullptr),\n              right(nullptr),\n              val(x),\n\
    \              sum(x),\n              sz(1),\n              rev(false) {}\n  \
    \  };\n\n    node_ptr root;\n\n    explicit SplayTree(node_ptr root) : root(std::move(root))\
    \ {}\n\n    static int size(const node_ptr& t) { return t ? t->sz : 0; }\n\n \
    \   static void recalc(const node_ptr& t) {\n        if (!t) return;\n       \
    \ t->sz = size(t->left) + 1 + size(t->right);\n        t->sum = t->val;\n    \
    \    if (t->left) t->sum = M::op(t->left->sum, t->sum);\n        if (t->right)\
    \ t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static void push(const\
    \ node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left, t->right);\n\
    \            if (t->left) t->left->rev ^= true;\n            if (t->right) t->right->rev\
    \ ^= true;\n            t->rev = false;\n        }\n    }\n\n    static node_ptr\
    \ join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n        if (!r) return\
    \ l;\n        l = splay(std::move(l), size(l) - 1);\n        l->right = std::move(r);\n\
    \        recalc(l);\n        return l;\n    }\n\n    static std::pair<node_ptr,\
    \ node_ptr> split(node_ptr t, int k) {\n        assert(0 <= k && k <= size(t));\n\
    \        if (k == 0) return {nullptr, std::move(t)};\n        if (k == size(t))\
    \ return {std::move(t), nullptr};\n        t = splay(std::move(t), k - 1);\n \
    \       auto r = std::move(t->right);\n        t->right = nullptr;\n        recalc(t);\n\
    \        return {std::move(t), std::move(r)};\n    }\n\n    static node_ptr rotate_left(node_ptr\
    \ t) {\n        node_ptr s = std::move(t->right);\n        t->right = std::move(s->left);\n\
    \        s->left = std::move(t);\n        recalc(s->left);\n        recalc(s);\n\
    \        return s;\n    }\n\n    static node_ptr rotate_right(node_ptr t) {\n\
    \        node_ptr s = std::move(t->left);\n        t->left = std::move(s->right);\n\
    \        s->right = std::move(t);\n        recalc(s->right);\n        recalc(s);\n\
    \        return s;\n    }\n\n    static node_ptr splay(node_ptr t, int k) {\n\
    \        assert(0 <= k && k <= size(t));\n        push(t);\n        int lsize\
    \ = size(t->left);\n        if (k == lsize) return t;\n        if (k < lsize)\
    \ {\n            push(t->left);\n            int llsize = size(t->left->left);\n\
    \            if (k < llsize) {\n                t->left->left = splay(std::move(t->left->left),\
    \ k);\n                t = rotate_right(std::move(t));\n            } else if\
    \ (llsize < k) {\n                t->left->right =\n                    splay(std::move(t->left->right),\
    \ k - llsize - 1);\n                t->left = rotate_left(std::move(t->left));\n\
    \            }\n            return rotate_right(std::move(t));\n        } else\
    \ {\n            push(t->right);\n            k -= lsize + 1;\n            int\
    \ rlsize = size(t->right->left);\n            if (k < rlsize) {\n            \
    \    t->right->left = splay(std::move(t->right->left), k);\n                t->right\
    \ = rotate_right(std::move(t->right));\n            } else if (rlsize < k) {\n\
    \                t->right->right =\n                    splay(std::move(t->right->right),\
    \ k - rlsize - 1);\n                t = rotate_left(std::move(t));\n         \
    \   }\n            return rotate_left(std::move(t));\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bst/splay_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:52:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_reverse_range_sum.splay_tree.test.cpp
  - test/aoj/1508.splay_tree.test.cpp
documentation_of: data-structure/bst/splay_tree.hpp
layout: document
title: Splay Tree
---

## Descriptions

Splay tree は，平衡二分探索木の一種である．ノードを根に持ってくる splay という操作を利用して様々な操作を実現している．同じ要素への連続アクセスが高速であるという特徴がある．モノイドを扱い，セグメント木が提供する操作に加えて挿入，削除，併合，分割，区間反転が可能である．

空間計算量: $O(n)$

## Operations

- `static SplayTree join(SplayTree l, SplayTree r)`
    - `l` と `r` を併合する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `pair<SplayTree, SplayTree> split(int k)`
    - $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void update(int k, T x)`
    - $k$ 番目の要素の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void reverse(int l, int r)`
    - 区間 $[l, r)$ を反転する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void insert(int k, T x)`
    - $k$ 番目に $x$ を挿入する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void erase(int k)`
    - $k$ 番目の要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void push_front(T x)`
- `void push_back(T x)`
- `void pop_front()`
- `void pop_back()`
    - 先頭/末尾への要素の追加/削除
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 空か判定する
    - 時間計算量: $O(1)$

## Reference

- [プログラミングコンテストでのデータ構造 2　～平衡二分探索木編～](https://www.slideshare.net/iwiwi/2-12188757)
- [Splay tree](https://en.wikipedia.org/wiki/Splay_tree)
- [Self-adjusting Binary Search Trees](https://www.cs.cmu.edu/~sleator/papers/self-adjusting.pdf)