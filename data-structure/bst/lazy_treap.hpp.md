---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
    title: test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/bst/lazy_treap.hpp\"\n#include <cassert>\n\
    #include <random>\n#include <tuple>\n#include <utility>\n\ntemplate <typename\
    \ M, typename O,\n          typename M::T (*act)(typename M::T, typename O::T)>\n\
    class LazyTreap {\n    using T = M::T;\n    using E = O::T;\n\n   public:\n  \
    \  LazyTreap() = default;\n\n    static LazyTreap join(LazyTreap l, LazyTreap\
    \ r) {\n        return LazyTreap(join(std::move(l.root), std::move(r.root)));\n\
    \    }\n\n    std::pair<LazyTreap, LazyTreap> split(int k) {\n        assert(0\
    \ <= k && k <= size());\n        auto p = split(std::move(root), k);\n       \
    \ return {LazyTreap(std::move(p.first)), LazyTreap(std::move(p.second))};\n  \
    \  }\n\n    void update(int l, int r, const E& x) {\n        assert(0 <= l &&\
    \ l < r && r <= size());\n        node_ptr a, b, c;\n        std::tie(a, b) =\
    \ split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b), r -\
    \ l);\n        b->lazy = O::op(b->lazy, x);\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    T fold(int l, int r) {\n       \
    \ assert(0 <= l && l < r && r <= size());\n        node_ptr a, b, c;\n       \
    \ std::tie(a, b) = split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b),\
    \ r - l);\n        auto ret = b->sum;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n        return ret;\n    }\n\n    void reverse(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= size());\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto s = split(std::move(root), k);\n        root = join(join(std::move(s.first),\
    \ new Node(x)), std::move(s.second));\n    }\n\n    void erase(int k) {\n    \
    \    auto p = split(std::move(root), k);\n        auto q = split(std::move(p.second),\
    \ 1);\n        root = join(std::move(p.first), std::move(q.second));\n    }\n\n\
    \    void push_front(const T& x) { root = join(new Node(x), std::move(root));\
    \ }\n\n    void push_back(const T& x) { root = join(std::move(root), new Node(x));\
    \ }\n\n    void pop_front() { root = split(std::move(root), 1).second; }\n\n \
    \   void pop_back() { root = split(std::move(root), size() - 1).first; }\n\n \
    \   int size() const { return size(root); }\n\n    bool empty() const { return\
    \ size() == 0; }\n\n   private:\n    struct Node;\n    using node_ptr = Node*;\n\
    \n    static unsigned int rand() {\n        static std::random_device rd;\n  \
    \      static std::mt19937 rng(rd());\n        return rng();\n    }\n\n    struct\
    \ Node {\n        node_ptr left, right;\n        T val, sum;\n        E lazy;\n\
    \        unsigned int pri;\n        int sz;\n        bool rev;\n\n        Node()\
    \ : Node(M::id()) {}\n        Node(const T& x)\n            : left(nullptr),\n\
    \              right(nullptr),\n              val(x),\n              sum(val),\n\
    \              lazy(O::id()),\n              pri(rand()),\n              sz(1),\n\
    \              rev(false) {}\n    };\n\n    node_ptr root = nullptr;\n\n    explicit\
    \ LazyTreap(node_ptr root) : root(std::move(root)) {}\n\n    static int size(const\
    \ node_ptr& t) { return t ? t->sz : 0; }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ void push(const node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left,\
    \ t->right);\n            if (t->left) t->left->rev ^= true;\n            if (t->right)\
    \ t->right->rev ^= true;\n            t->rev = false;\n        }\n        if (t->lazy\
    \ != O::id()) {\n            t->val = act(t->val, t->lazy);\n            if (t->left)\
    \ {\n                t->left->lazy = O::op(t->left->lazy, t->lazy);\n        \
    \        t->left->sum = act(t->left->sum, t->lazy);\n            }\n         \
    \   if (t->right) {\n                t->right->lazy = O::op(t->right->lazy, t->lazy);\n\
    \                t->right->sum = act(t->right->sum, t->lazy);\n            }\n\
    \            t->lazy = O::id();\n        }\n        recalc(t);\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        push(l);\n        push(r);\n        if (l->pri >\
    \ r->pri) {\n            l->right = join(std::move(l->right), std::move(r));\n\
    \            recalc(l);\n            return l;\n        } else {\n           \
    \ r->left = join(std::move(l), std::move(r->left));\n            recalc(r);\n\
    \            return r;\n        }\n    }\n\n    static std::pair<node_ptr, node_ptr>\
    \ split(node_ptr t, int k) {\n        if (!t) return {nullptr, nullptr};\n   \
    \     push(t);\n        if (k <= size(t->left)) {\n            auto s = split(std::move(t->left),\
    \ k);\n            t->left = std::move(s.second);\n            recalc(t);\n  \
    \          return {std::move(s.first), std::move(t)};\n        } else {\n    \
    \        auto s = split(std::move(t->right), k - size(t->left) - 1);\n       \
    \     t->right = std::move(s.first);\n            recalc(t);\n            return\
    \ {std::move(t), std::move(s.second)};\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <random>\n#include <tuple>\n#include\
    \ <utility>\n\ntemplate <typename M, typename O,\n          typename M::T (*act)(typename\
    \ M::T, typename O::T)>\nclass LazyTreap {\n    using T = M::T;\n    using E =\
    \ O::T;\n\n   public:\n    LazyTreap() = default;\n\n    static LazyTreap join(LazyTreap\
    \ l, LazyTreap r) {\n        return LazyTreap(join(std::move(l.root), std::move(r.root)));\n\
    \    }\n\n    std::pair<LazyTreap, LazyTreap> split(int k) {\n        assert(0\
    \ <= k && k <= size());\n        auto p = split(std::move(root), k);\n       \
    \ return {LazyTreap(std::move(p.first)), LazyTreap(std::move(p.second))};\n  \
    \  }\n\n    void update(int l, int r, const E& x) {\n        assert(0 <= l &&\
    \ l < r && r <= size());\n        node_ptr a, b, c;\n        std::tie(a, b) =\
    \ split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b), r -\
    \ l);\n        b->lazy = O::op(b->lazy, x);\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    T fold(int l, int r) {\n       \
    \ assert(0 <= l && l < r && r <= size());\n        node_ptr a, b, c;\n       \
    \ std::tie(a, b) = split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b),\
    \ r - l);\n        auto ret = b->sum;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n        return ret;\n    }\n\n    void reverse(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= size());\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto s = split(std::move(root), k);\n        root = join(join(std::move(s.first),\
    \ new Node(x)), std::move(s.second));\n    }\n\n    void erase(int k) {\n    \
    \    auto p = split(std::move(root), k);\n        auto q = split(std::move(p.second),\
    \ 1);\n        root = join(std::move(p.first), std::move(q.second));\n    }\n\n\
    \    void push_front(const T& x) { root = join(new Node(x), std::move(root));\
    \ }\n\n    void push_back(const T& x) { root = join(std::move(root), new Node(x));\
    \ }\n\n    void pop_front() { root = split(std::move(root), 1).second; }\n\n \
    \   void pop_back() { root = split(std::move(root), size() - 1).first; }\n\n \
    \   int size() const { return size(root); }\n\n    bool empty() const { return\
    \ size() == 0; }\n\n   private:\n    struct Node;\n    using node_ptr = Node*;\n\
    \n    static unsigned int rand() {\n        static std::random_device rd;\n  \
    \      static std::mt19937 rng(rd());\n        return rng();\n    }\n\n    struct\
    \ Node {\n        node_ptr left, right;\n        T val, sum;\n        E lazy;\n\
    \        unsigned int pri;\n        int sz;\n        bool rev;\n\n        Node()\
    \ : Node(M::id()) {}\n        Node(const T& x)\n            : left(nullptr),\n\
    \              right(nullptr),\n              val(x),\n              sum(val),\n\
    \              lazy(O::id()),\n              pri(rand()),\n              sz(1),\n\
    \              rev(false) {}\n    };\n\n    node_ptr root = nullptr;\n\n    explicit\
    \ LazyTreap(node_ptr root) : root(std::move(root)) {}\n\n    static int size(const\
    \ node_ptr& t) { return t ? t->sz : 0; }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ void push(const node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left,\
    \ t->right);\n            if (t->left) t->left->rev ^= true;\n            if (t->right)\
    \ t->right->rev ^= true;\n            t->rev = false;\n        }\n        if (t->lazy\
    \ != O::id()) {\n            t->val = act(t->val, t->lazy);\n            if (t->left)\
    \ {\n                t->left->lazy = O::op(t->left->lazy, t->lazy);\n        \
    \        t->left->sum = act(t->left->sum, t->lazy);\n            }\n         \
    \   if (t->right) {\n                t->right->lazy = O::op(t->right->lazy, t->lazy);\n\
    \                t->right->sum = act(t->right->sum, t->lazy);\n            }\n\
    \            t->lazy = O::id();\n        }\n        recalc(t);\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        push(l);\n        push(r);\n        if (l->pri >\
    \ r->pri) {\n            l->right = join(std::move(l->right), std::move(r));\n\
    \            recalc(l);\n            return l;\n        } else {\n           \
    \ r->left = join(std::move(l), std::move(r->left));\n            recalc(r);\n\
    \            return r;\n        }\n    }\n\n    static std::pair<node_ptr, node_ptr>\
    \ split(node_ptr t, int k) {\n        if (!t) return {nullptr, nullptr};\n   \
    \     push(t);\n        if (k <= size(t->left)) {\n            auto s = split(std::move(t->left),\
    \ k);\n            t->left = std::move(s.second);\n            recalc(t);\n  \
    \          return {std::move(s.first), std::move(t)};\n        } else {\n    \
    \        auto s = split(std::move(t->right), k - size(t->left) - 1);\n       \
    \     t->right = std::move(s.first);\n            recalc(t);\n            return\
    \ {std::move(t), std::move(s.second)};\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bst/lazy_treap.hpp
  requiredBy: []
  timestamp: '2024-01-08 11:43:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
documentation_of: data-structure/bst/lazy_treap.hpp
layout: document
title: Treap with Lazy Propagation
---

## Description

遅延伝搬 treap は，区間更新が可能な treap である．扱える代数的構造は遅延伝搬セグメント木と同様なので，そちらを参照．遅延伝搬セグメント木が提供する操作に加えて挿入，削除，併合，分割，区間反転が可能である．

基本的には非可換のモノイドも扱えるが，`reverse` 操作をする場合は可換性が必要である．非可換も実装を少しいじれば扱えるがめんどくさいので実装していない．

空間計算量: $O(n)$

## Operations

- `static Treap join(Treap l, Treap r)`
    - `l` と `r` を併合する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `pair<Treap, Treap> split(int k)`
    - $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる．
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void reverse(int l, int r)`
    - 区間 $[l, r)$ を反転する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void insert(int k, T x)`
    - $k$ 番目に $x$ を挿入する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void erase(int k)`
    - $k$ 番目の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `void push_front(T x)`
- `void push_back(T x)`
- `void pop_front()`
- `void pop_back()`
    - 先頭/末尾に $x$ を追加する/の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\log n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 空か判定する
    - 時間計算量: $O(1)$

## Note

本当は`std::unique_ptr`を使いたいんだがなぜかGitHub上でめちゃくちゃ遅くなるので生ポインタを使っている．`std::unique_ptr`にしてコンパイルが通るような書き方はしているので生ポインタによる怖いことは起きないと思う．