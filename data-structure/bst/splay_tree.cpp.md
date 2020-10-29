---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.splay_tree.test.cpp
    title: test/aoj/1508.splay_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/bst/splay_tree.md
    document_title: Splay Tree
    links: []
  bundledCode: "#line 2 \"data-structure/bst/splay_tree.cpp\"\n#include <cassert>\n\
    #include <memory>\n#include <utility>\n\n/*\n * @brief Splay Tree\n * @docs docs/data-structure/bst/splay_tree.md\n\
    \ */\ntemplate <typename M>\nclass SplayTree {\n    using T = typename M::T;\n\
    \npublic:\n    SplayTree() = default;\n\n    static SplayTree join(SplayTree l,\
    \ SplayTree r) {\n        return SplayTree(join(std::move(l.root), std::move(r.root)));\n\
    \    }\n\n    std::pair<SplayTree, SplayTree> split(int k) {\n        auto p =\
    \ split(std::move(root), k);\n        return {SplayTree(std::move(p.first)), SplayTree(std::move(p.second))};\n\
    \    }\n\n    void set(int k, const T& x) {\n        root = splay(std::move(root),\
    \ k);\n        root->val = x;\n        recalc(root);\n    }\n\n    T fold(int\
    \ l, int r) {\n        auto a = split(std::move(root), l);\n        auto b = split(std::move(a.second),\
    \ r - l);\n        auto ret = b.first ? b.first->sum : M::id;\n        root =\
    \ join(std::move(a.first), join(std::move(b.first), std::move(b.second)));\n \
    \       return ret;\n    }\n\n    void reverse(int l, int r) {\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto p = split(std::move(root), k);\n        root = join(join(std::move(p.first),\
    \ std::make_unique<Node>(x)), std::move(p.second));\n    }\n\n    void erase(int\
    \ k) {\n        root = splay(std::move(root), k);\n        root = join(std::move(root->left),\
    \ std::move(root->right));\n    }\n\n    void push_front(const T& x) {\n     \
    \   root = join(std::make_unique<Node>(x), std::move(root));\n    }\n\n    void\
    \ push_back(const T& x) {\n        root = join(std::move(root), std::make_unique<Node>(x));\n\
    \    }\n\n    void pop_front() {\n        root = split(std::move(root), 1).second;\n\
    \    }\n\n    void pop_back() {\n        root = split(std::move(root), size()\
    \ - 1).first;\n    }\n\n    int size() const {\n        return size(root);\n \
    \   }\n\n    bool empty() const {\n        return size() == 0;\n    }\n\nprotected:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node\
    \ {\n        node_ptr left, right;\n        T val, sum;\n        int sz;\n   \
    \     bool rev;\n\n        Node() : Node(M::id) {}\n        Node(const T& x) :\
    \ left(nullptr), right(nullptr), val(x), sum(x), sz(1), rev(false) {}\n    };\n\
    \n    node_ptr root;\n\n    explicit SplayTree(node_ptr root) : root(std::move(root))\
    \ {}\n\n    static int size(const node_ptr& t) {\n        return t ? t->sz : 0;\n\
    \    }\n\n    static void recalc(const node_ptr& t) {\n        if (!t) return;\n\
    \        t->sz = size(t->left) + 1 + size(t->right);\n        t->sum = t->val;\n\
    \        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n        if (t->right)\
    \ t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static void push(const\
    \ node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left, t->right);\n\
    \            if (t->left) t->left->rev ^= true;\n            if (t->right) t->right->rev\
    \ ^= true;\n            t->rev = false;\n            // if (t->left) reverse(t->left);\n\
    \            // if (t->right) reverse(t->right);\n            // t->rev = false;\n\
    \        }\n    }\n\n    static node_ptr join(node_ptr l, node_ptr r) {\n    \
    \    if (!l) return r;\n        if (!r) return l;\n        l = splay(std::move(l),\
    \ size(l) - 1);\n        l->right = std::move(r);\n        recalc(l);\n      \
    \  return l;\n    }\n\n    static std::pair<node_ptr, node_ptr> split(node_ptr\
    \ t, int k) {\n        assert(0 <= k && k <= size(t));\n        if (k == 0) return\
    \ {nullptr, std::move(t)};\n        if (k == size(t)) return {std::move(t), nullptr};\n\
    \        t = splay(std::move(t), k - 1);\n        auto r = std::move(t->right);\n\
    \        t->right = nullptr;\n        recalc(t);\n        return {std::move(t),\
    \ std::move(r)};\n    }\n\n    static node_ptr rotate_left(node_ptr t) {\n   \
    \     node_ptr s = std::move(t->right);\n        t->right = std::move(s->left);\n\
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
    \ (llsize < k) {\n                t->left->right = splay(std::move(t->left->right),\
    \ k - llsize - 1);\n                t->left = rotate_left(std::move(t->left));\n\
    \            }\n            return rotate_right(std::move(t));\n        } else\
    \ {\n            push(t->right);\n            k -= lsize + 1;\n            int\
    \ rlsize = size(t->right->left);\n            if (k < rlsize) {\n            \
    \    t->right->left = splay(std::move(t->right->left), k);\n                t->right\
    \ = rotate_right(std::move(t->right));\n            } else if (rlsize < k) {\n\
    \                t->right->right = splay(std::move(t->right->right), k - rlsize\
    \ - 1);\n                t = rotate_left(std::move(t));\n            }\n     \
    \       return rotate_left(std::move(t));\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <utility>\n\
    \n/*\n * @brief Splay Tree\n * @docs docs/data-structure/bst/splay_tree.md\n */\n\
    template <typename M>\nclass SplayTree {\n    using T = typename M::T;\n\npublic:\n\
    \    SplayTree() = default;\n\n    static SplayTree join(SplayTree l, SplayTree\
    \ r) {\n        return SplayTree(join(std::move(l.root), std::move(r.root)));\n\
    \    }\n\n    std::pair<SplayTree, SplayTree> split(int k) {\n        auto p =\
    \ split(std::move(root), k);\n        return {SplayTree(std::move(p.first)), SplayTree(std::move(p.second))};\n\
    \    }\n\n    void set(int k, const T& x) {\n        root = splay(std::move(root),\
    \ k);\n        root->val = x;\n        recalc(root);\n    }\n\n    T fold(int\
    \ l, int r) {\n        auto a = split(std::move(root), l);\n        auto b = split(std::move(a.second),\
    \ r - l);\n        auto ret = b.first ? b.first->sum : M::id;\n        root =\
    \ join(std::move(a.first), join(std::move(b.first), std::move(b.second)));\n \
    \       return ret;\n    }\n\n    void reverse(int l, int r) {\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto p = split(std::move(root), k);\n        root = join(join(std::move(p.first),\
    \ std::make_unique<Node>(x)), std::move(p.second));\n    }\n\n    void erase(int\
    \ k) {\n        root = splay(std::move(root), k);\n        root = join(std::move(root->left),\
    \ std::move(root->right));\n    }\n\n    void push_front(const T& x) {\n     \
    \   root = join(std::make_unique<Node>(x), std::move(root));\n    }\n\n    void\
    \ push_back(const T& x) {\n        root = join(std::move(root), std::make_unique<Node>(x));\n\
    \    }\n\n    void pop_front() {\n        root = split(std::move(root), 1).second;\n\
    \    }\n\n    void pop_back() {\n        root = split(std::move(root), size()\
    \ - 1).first;\n    }\n\n    int size() const {\n        return size(root);\n \
    \   }\n\n    bool empty() const {\n        return size() == 0;\n    }\n\nprotected:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node\
    \ {\n        node_ptr left, right;\n        T val, sum;\n        int sz;\n   \
    \     bool rev;\n\n        Node() : Node(M::id) {}\n        Node(const T& x) :\
    \ left(nullptr), right(nullptr), val(x), sum(x), sz(1), rev(false) {}\n    };\n\
    \n    node_ptr root;\n\n    explicit SplayTree(node_ptr root) : root(std::move(root))\
    \ {}\n\n    static int size(const node_ptr& t) {\n        return t ? t->sz : 0;\n\
    \    }\n\n    static void recalc(const node_ptr& t) {\n        if (!t) return;\n\
    \        t->sz = size(t->left) + 1 + size(t->right);\n        t->sum = t->val;\n\
    \        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n        if (t->right)\
    \ t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static void push(const\
    \ node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left, t->right);\n\
    \            if (t->left) t->left->rev ^= true;\n            if (t->right) t->right->rev\
    \ ^= true;\n            t->rev = false;\n            // if (t->left) reverse(t->left);\n\
    \            // if (t->right) reverse(t->right);\n            // t->rev = false;\n\
    \        }\n    }\n\n    static node_ptr join(node_ptr l, node_ptr r) {\n    \
    \    if (!l) return r;\n        if (!r) return l;\n        l = splay(std::move(l),\
    \ size(l) - 1);\n        l->right = std::move(r);\n        recalc(l);\n      \
    \  return l;\n    }\n\n    static std::pair<node_ptr, node_ptr> split(node_ptr\
    \ t, int k) {\n        assert(0 <= k && k <= size(t));\n        if (k == 0) return\
    \ {nullptr, std::move(t)};\n        if (k == size(t)) return {std::move(t), nullptr};\n\
    \        t = splay(std::move(t), k - 1);\n        auto r = std::move(t->right);\n\
    \        t->right = nullptr;\n        recalc(t);\n        return {std::move(t),\
    \ std::move(r)};\n    }\n\n    static node_ptr rotate_left(node_ptr t) {\n   \
    \     node_ptr s = std::move(t->right);\n        t->right = std::move(s->left);\n\
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
    \ (llsize < k) {\n                t->left->right = splay(std::move(t->left->right),\
    \ k - llsize - 1);\n                t->left = rotate_left(std::move(t->left));\n\
    \            }\n            return rotate_right(std::move(t));\n        } else\
    \ {\n            push(t->right);\n            k -= lsize + 1;\n            int\
    \ rlsize = size(t->right->left);\n            if (k < rlsize) {\n            \
    \    t->right->left = splay(std::move(t->right->left), k);\n                t->right\
    \ = rotate_right(std::move(t->right));\n            } else if (rlsize < k) {\n\
    \                t->right->right = splay(std::move(t->right->right), k - rlsize\
    \ - 1);\n                t = rotate_left(std::move(t));\n            }\n     \
    \       return rotate_left(std::move(t));\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bst/splay_tree.cpp
  requiredBy: []
  timestamp: '2020-10-29 10:57:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1508.splay_tree.test.cpp
documentation_of: data-structure/bst/splay_tree.cpp
layout: document
redirect_from:
- /library/data-structure/bst/splay_tree.cpp
- /library/data-structure/bst/splay_tree.cpp.html
title: Splay Tree
---
# Splay Tree

Splay tree は，平衡二分探索木の一種である．ノードを根に持ってくるスプレーという操作を利用して様々な操作を実現している．同じ要素への連続アクセスが高速であるという特徴がある．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Member functions

- `static SplayTree join(SplayTree l, SplayTree r)`
    - `l` と `r` を融合させた splay tree を返す
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `pair<SplayTree, SplayTree> split(int k)`
    - splay tree を $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void set(int k, T x)`
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
    - 先頭/末尾に $x$ を追加する/の要素を削除する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - treap が空か判定する
    - 時間計算量: $O(1)$