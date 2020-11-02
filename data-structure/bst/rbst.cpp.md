---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.rbst.test.cpp
    title: test/aoj/1508.rbst.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/bst/rbst.md
    document_title: Randomized Binary Search Tree
    links: []
  bundledCode: "#line 2 \"data-structure/bst/rbst.cpp\"\n#include <cassert>\n#include\
    \ <memory>\n#include <random>\n#include <utility>\n\n/*\n * @brief Randomized\
    \ Binary Search Tree\n * @docs docs/data-structure/bst/rbst.md\n */\ntemplate\
    \ <typename M>\nclass RBST {\n    using T = typename M::T;\n\npublic:\n    RBST()\
    \ = default;\n\n    static RBST join(RBST l, RBST r) {\n        return RBST(join(std::move(l.root),\
    \ std::move(r.root)));\n    }\n\n    std::pair<RBST, RBST> split(int k) {\n  \
    \      auto p = split(std::move(root), k);\n        return {RBST(std::move(p.first)),\
    \ RBST(std::move(p.second))};\n    }\n\n    void update(int k, const T& x) const\
    \ {\n        update(root, k, x);\n    }\n\n    T fold(int l, int r) {\n      \
    \  assert(0 <= l && l < r && r <= size());\n        node_ptr a, b, c;\n      \
    \  std::tie(a, b) = split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b),\
    \ r - l);\n        auto ret = b->sum;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n        return ret;\n    }\n\n    void reverse(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= size());\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto s = split(std::move(root), k);\n        root = join(join(std::move(s.first),\
    \ std::make_unique<Node>(x)), std::move(s.second));\n    }\n\n    void erase(int\
    \ k) {\n        auto p = split(std::move(root), k - 1);\n        auto q = split(std::move(p.second),\
    \ 1);\n        return join(std::move(p.first), std::move(q.second));\n    }\n\n\
    \    void push_front(const T& x) {\n        root = join(std::make_unique<Node>(x),\
    \ std::move(root));\n    }\n\n    void push_back(const T& x) {\n        root =\
    \ join(std::move(root), std::make_unique<Node>(x));\n    }\n\n    void pop_front()\
    \ {\n        root = split(std::move(root), 1).second;\n    }\n\n    void pop_back()\
    \ {\n        root = split(std::move(root), size() - 1).first;\n    }\n\n    int\
    \ size() const {\n        return size(root);\n    }\n\n    bool empty() const\
    \ {\n        return size() == 0;\n    }\n\nprivate:\n    struct Node;\n    using\
    \ node_ptr = std::unique_ptr<Node>;\n\n    static unsigned int rand() {\n    \
    \    static std::random_device rd;\n        static std::mt19937 rng(rd());\n \
    \       return rng();\n    }\n\n    struct Node {\n        node_ptr left, right;\n\
    \        T val, sum;\n        int sz;\n        bool rev;\n\n        Node() : Node(M::id)\
    \ {}\n        Node(const T& x) : left(nullptr), right(nullptr), val(x), sum(val),\
    \ sz(1), rev(false) {}\n    };\n\n    node_ptr root;\n\n    explicit RBST(node_ptr\
    \ root) : root(std::move(root)) {}\n\n    static int size(const node_ptr& t) {\n\
    \        return t ? t->sz : 0;\n    }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ void push(const node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left,\
    \ t->right);\n            if (t->left) t->left->rev ^= true;\n            if (t->right)\
    \ t->right->rev ^= true;\n            t->rev = false;\n        }\n    }\n\n  \
    \  static node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n\
    \        if (!r) return l;\n        push(l);\n        push(r);\n        if ((int)\
    \ (rand() % (size(l) + size(r))) < size(l)) {\n            l->right = join(std::move(l->right),\
    \ std::move(r));\n            recalc(l);\n            return l;\n        } else\
    \ {\n            r->left = join(std::move(l), std::move(r->left));\n         \
    \   recalc(r);\n            return r;\n        }\n    }\n\n    static std::pair<node_ptr,\
    \ node_ptr> split(node_ptr t, int k) {\n        assert(0 <= k && k <= size(t));\n\
    \        if (k == 0) return {nullptr, std::move(t)};\n        if (k == size(t))\
    \ return {std::move(t), nullptr};\n        push(t);\n        if (k <= size(t->left))\
    \ {\n            auto s = split(std::move(t->left), k);\n            t->left =\
    \ std::move(s.second);\n            recalc(t);\n            return {std::move(s.first),\
    \ std::move(t)};\n        } else {\n            auto s = split(std::move(t->right),\
    \ k - size(t->left) - 1);\n            t->right = std::move(s.first);\n      \
    \      recalc(t);\n            return {std::move(t), std::move(s.second)};\n \
    \       }\n    }\n\n    static void update(const node_ptr& t, int k, const T&\
    \ x) {\n        push(t);\n        int lsize = size(t->left);\n        if (k <\
    \ lsize) {\n            update(t->left, k, x);\n        } else if (lsize < k)\
    \ {\n            update(t->right, k - lsize - 1, x);\n        } else {\n     \
    \       t->val = x;\n        }\n        recalc(t);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <random>\n\
    #include <utility>\n\n/*\n * @brief Randomized Binary Search Tree\n * @docs docs/data-structure/bst/rbst.md\n\
    \ */\ntemplate <typename M>\nclass RBST {\n    using T = typename M::T;\n\npublic:\n\
    \    RBST() = default;\n\n    static RBST join(RBST l, RBST r) {\n        return\
    \ RBST(join(std::move(l.root), std::move(r.root)));\n    }\n\n    std::pair<RBST,\
    \ RBST> split(int k) {\n        auto p = split(std::move(root), k);\n        return\
    \ {RBST(std::move(p.first)), RBST(std::move(p.second))};\n    }\n\n    void update(int\
    \ k, const T& x) const {\n        update(root, k, x);\n    }\n\n    T fold(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= size());\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        auto ret = b->sum;\n        root =\
    \ join(join(std::move(a), std::move(b)), std::move(c));\n        return ret;\n\
    \    }\n\n    void reverse(int l, int r) {\n        assert(0 <= l && l < r &&\
    \ r <= size());\n        node_ptr a, b, c;\n        std::tie(a, b) = split(std::move(root),\
    \ l);\n        std::tie(b, c) = split(std::move(b), r - l);\n        b->rev ^=\
    \ true;\n        root = join(join(std::move(a), std::move(b)), std::move(c));\n\
    \    }\n\n    void insert(int k, const T& x) {\n        auto s = split(std::move(root),\
    \ k);\n        root = join(join(std::move(s.first), std::make_unique<Node>(x)),\
    \ std::move(s.second));\n    }\n\n    void erase(int k) {\n        auto p = split(std::move(root),\
    \ k - 1);\n        auto q = split(std::move(p.second), 1);\n        return join(std::move(p.first),\
    \ std::move(q.second));\n    }\n\n    void push_front(const T& x) {\n        root\
    \ = join(std::make_unique<Node>(x), std::move(root));\n    }\n\n    void push_back(const\
    \ T& x) {\n        root = join(std::move(root), std::make_unique<Node>(x));\n\
    \    }\n\n    void pop_front() {\n        root = split(std::move(root), 1).second;\n\
    \    }\n\n    void pop_back() {\n        root = split(std::move(root), size()\
    \ - 1).first;\n    }\n\n    int size() const {\n        return size(root);\n \
    \   }\n\n    bool empty() const {\n        return size() == 0;\n    }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    static unsigned\
    \ int rand() {\n        static std::random_device rd;\n        static std::mt19937\
    \ rng(rd());\n        return rng();\n    }\n\n    struct Node {\n        node_ptr\
    \ left, right;\n        T val, sum;\n        int sz;\n        bool rev;\n\n  \
    \      Node() : Node(M::id) {}\n        Node(const T& x) : left(nullptr), right(nullptr),\
    \ val(x), sum(val), sz(1), rev(false) {}\n    };\n\n    node_ptr root;\n\n   \
    \ explicit RBST(node_ptr root) : root(std::move(root)) {}\n\n    static int size(const\
    \ node_ptr& t) {\n        return t ? t->sz : 0;\n    }\n\n    static void recalc(const\
    \ node_ptr& t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 +\
    \ size(t->right);\n        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum,\
    \ t->sum);\n        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n   \
    \ }\n\n    static void push(const node_ptr& t) {\n        if (t->rev) {\n    \
    \        std::swap(t->left, t->right);\n            if (t->left) t->left->rev\
    \ ^= true;\n            if (t->right) t->right->rev ^= true;\n            t->rev\
    \ = false;\n        }\n    }\n\n    static node_ptr join(node_ptr l, node_ptr\
    \ r) {\n        if (!l) return r;\n        if (!r) return l;\n        push(l);\n\
    \        push(r);\n        if ((int) (rand() % (size(l) + size(r))) < size(l))\
    \ {\n            l->right = join(std::move(l->right), std::move(r));\n       \
    \     recalc(l);\n            return l;\n        } else {\n            r->left\
    \ = join(std::move(l), std::move(r->left));\n            recalc(r);\n        \
    \    return r;\n        }\n    }\n\n    static std::pair<node_ptr, node_ptr> split(node_ptr\
    \ t, int k) {\n        assert(0 <= k && k <= size(t));\n        if (k == 0) return\
    \ {nullptr, std::move(t)};\n        if (k == size(t)) return {std::move(t), nullptr};\n\
    \        push(t);\n        if (k <= size(t->left)) {\n            auto s = split(std::move(t->left),\
    \ k);\n            t->left = std::move(s.second);\n            recalc(t);\n  \
    \          return {std::move(s.first), std::move(t)};\n        } else {\n    \
    \        auto s = split(std::move(t->right), k - size(t->left) - 1);\n       \
    \     t->right = std::move(s.first);\n            recalc(t);\n            return\
    \ {std::move(t), std::move(s.second)};\n        }\n    }\n\n    static void update(const\
    \ node_ptr& t, int k, const T& x) {\n        push(t);\n        int lsize = size(t->left);\n\
    \        if (k < lsize) {\n            update(t->left, k, x);\n        } else\
    \ if (lsize < k) {\n            update(t->right, k - lsize - 1, x);\n        }\
    \ else {\n            t->val = x;\n        }\n        recalc(t);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bst/rbst.cpp
  requiredBy: []
  timestamp: '2020-10-30 15:38:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1508.rbst.test.cpp
documentation_of: data-structure/bst/rbst.cpp
layout: document
redirect_from:
- /library/data-structure/bst/rbst.cpp
- /library/data-structure/bst/rbst.cpp.html
title: Randomized Binary Search Tree
---
## Description

Randomized binary search tree は，平衡二分探索木の一種である．ツリープとほとんど同じだが，ノードにランダムな優先度を与えるのではなく，木を併合するときに木の根を部分木のサイズに比例する確率でランダムに決める．モノイドを扱い，セグメント木が提供する操作に加えて挿入，削除，併合，分割，区間反転が可能である．

空間計算量: $O(n)$

## Operations

- `static RBST join(RBST l, RBST r)`
    - `l` と `r` を併合する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `pair<RBST, RBST> split(int k)`
    - $[0, k)$ と $[k, n)$ に分割する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void update(int k, T x)`
    - $k$ 番目の要素の値を $x$ に変更する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void reverse(int l, int r)`
    - 区間 $[l, r)$ を反転する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void insert(int k, T x)`
    - $k$ 番目に $x$ を挿入する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void erase(int k)`
    - $k$ 番目の要素を削除する
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `void push_front(T x)`
- `void push_back(T x)`
- `void pop_front()`
- `void pop_back()`
    - 先頭/末尾への要素の追加/削除
    - 時間計算量: $\mathrm{expected}\ O(\lg n)$
- `int size()`
    - 要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 空か判定する
    - 時間計算量: $O(1)$

## Reference

- [プログラミングコンテストでのデータ構造 2　～平衡二分探索木編～](https://www.slideshare.net/iwiwi/2-12188757)

## TODO

- 遅延評価
- 永続化