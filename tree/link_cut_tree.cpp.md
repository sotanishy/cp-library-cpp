---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bst/reversible_splay_tree.cpp
    title: (deprecated) Reversible Splay Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/link_cut_tree.md
    document_title: Link/Cut Tree
    links: []
  bundledCode: "#line 2 \"data-structure/bst/reversible_splay_tree.cpp\"\n#include\
    \ <algorithm>\n#include <memory>\n\n/*\n * @brief (deprecated) Reversible Splay\
    \ Tree\n */\ntemplate <typename M, typename M::T (*flip)(typename M::T)>\nclass\
    \ ReversibleSplayTree {\n    using T = typename M::T;\n\nprotected:\n    struct\
    \ Node;\n\npublic:\n    using node_ptr = std::shared_ptr<Node>;\n\n    node_ptr\
    \ make_node(const T& x) const {\n        return std::make_shared<Node>(x);\n \
    \   }\n\n    void reverse(const node_ptr& t) const {\n        std::swap(t->left,\
    \ t->right);\n        t->sum = flip(t->sum);\n        t->rev ^= true;\n    }\n\
    \nprotected:\n    struct Node {\n        node_ptr left, right, par;\n        T\
    \ val, sum;\n        int sz;\n        bool rev;\n\n        Node() : left(nullptr),\
    \ right(nullptr), par(nullptr), sz(1), rev(false) {}\n        Node(const T& x)\
    \ : Node() {\n            val = sum = x;\n        }\n    };\n\n    bool is_root(const\
    \ node_ptr& t) const {\n        return !t->par || (t->par->left != t && t->par->right\
    \ != t);\n    }\n\n    void recalc(const node_ptr& t) const {\n        t->sz =\
    \ 1;\n        t->sum = t->val;\n        if (t->left) {\n            t->sz += t->left->sz;\n\
    \            t->sum = M::op(t->left->sum, t->sum);\n        }\n        if (t->right)\
    \ {\n            t->sz += t->right->sz;\n            t->sum = M::op(t->sum, t->right->sum);\n\
    \        }\n    }\n\n    void rotate_left(node_ptr t) const {\n        auto x\
    \ = t->par, y = x->par;\n        x->right = t->left;\n        if (x->right) x->right->par\
    \ = x;\n        t->left = x;\n        x->par = t;\n        recalc(x);\n      \
    \  recalc(t);\n        t->par = y;\n        if (y) {\n            if (y->left\
    \ == x) y->left = t;\n            if (y->right == x) y->right = t;\n         \
    \   recalc(y);\n        }\n    }\n\n    void rotate_right(node_ptr t) const {\n\
    \        auto x = t->par, y = x->par;\n        x->left = t->right;\n        if\
    \ (x->left) x->left->par = x;\n        t->right = x;\n        x->par = t;\n  \
    \      recalc(x);\n        recalc(t);\n        t->par = y;\n        if (y) {\n\
    \            if (y->left == x) y->left = t;\n            if (y->right == x) y->right\
    \ = t;\n            recalc(y);\n        }\n    }\n\n    void push(const node_ptr&\
    \ t) const {\n        if (t->rev) {\n            if (t->left) reverse(t->left);\n\
    \            if (t->right) reverse(t->right);\n            t->rev = false;\n \
    \       }\n    }\n\n    void splay(node_ptr t) const {\n        push(t);\n   \
    \     while (!is_root(t)) {\n            auto x = t->par;\n            if (is_root(x))\
    \ {\n                push(x);\n                push(t);\n                if (x->left\
    \ == t) rotate_right(t);\n                else rotate_left(t);\n            }\
    \ else {\n                auto y = x->par;\n                push(y);\n       \
    \         push(x);\n                push(t);\n                if (y->left == x)\
    \ {\n                    if (x->left == t) {\n                        rotate_right(x);\n\
    \                        rotate_right(t);\n                    } else {\n    \
    \                    rotate_left(t);\n                        rotate_right(t);\n\
    \                    }\n                } else {\n                    if (x->right\
    \ == t) {\n                        rotate_left(x);\n                        rotate_left(t);\n\
    \                    } else {\n                        rotate_right(t);\n    \
    \                    rotate_left(t);\n                    }\n                }\n\
    \            }\n        }\n    }\n};\n#line 3 \"tree/link_cut_tree.cpp\"\n\n/*\n\
    \ * @brief Link/Cut Tree\n * @docs docs/tree/link_cut_tree.md\n */\ntemplate <typename\
    \ M, typename M::T (*flip)(typename M::T)>\nclass LinkCutTree : ReversibleSplayTree<M,\
    \ flip> {\n    using T = typename M::T;\n    using RST = ReversibleSplayTree<M,\
    \ flip>;\n\npublic:\n    using node_ptr = typename RST::node_ptr;\n\n    using\
    \ RST::make_node;\n\n    void link(node_ptr v, node_ptr p) const {\n        evert(v);\n\
    \        access(p);\n        v->par = p;\n        p->right = v;\n        recalc(p);\n\
    \    }\n\n    void cut(node_ptr v) const {\n        access(v);\n        auto p\
    \ = v->left;\n        v->left = p->par = nullptr;\n        recalc(v);\n    }\n\
    \n    void evert(node_ptr v) const {\n        access(v);\n        reverse(v);\n\
    \    }\n\n    void update(node_ptr v, const T& x) const {\n        access(v);\n\
    \        v->val = x;\n        recalc(v);\n    }\n\n    T fold(node_ptr u, node_ptr\
    \ v) const {\n        evert(u);\n        access(v);\n        return v->sum;\n\
    \    }\n\nprivate:\n    using RST::reverse;\n    using RST::recalc;\n    using\
    \ RST::splay;\n\n    void access(node_ptr v) const {\n        node_ptr prev =\
    \ nullptr;\n        for (auto cur = v; cur; cur = cur->par) {\n            splay(cur);\n\
    \            cur->right = prev;\n            recalc(cur);\n            prev =\
    \ cur;\n        }\n        splay(v);\n    }\n};\n"
  code: "#pragma once\n#include \"../data-structure/bst/reversible_splay_tree.cpp\"\
    \n\n/*\n * @brief Link/Cut Tree\n * @docs docs/tree/link_cut_tree.md\n */\ntemplate\
    \ <typename M, typename M::T (*flip)(typename M::T)>\nclass LinkCutTree : ReversibleSplayTree<M,\
    \ flip> {\n    using T = typename M::T;\n    using RST = ReversibleSplayTree<M,\
    \ flip>;\n\npublic:\n    using node_ptr = typename RST::node_ptr;\n\n    using\
    \ RST::make_node;\n\n    void link(node_ptr v, node_ptr p) const {\n        evert(v);\n\
    \        access(p);\n        v->par = p;\n        p->right = v;\n        recalc(p);\n\
    \    }\n\n    void cut(node_ptr v) const {\n        access(v);\n        auto p\
    \ = v->left;\n        v->left = p->par = nullptr;\n        recalc(v);\n    }\n\
    \n    void evert(node_ptr v) const {\n        access(v);\n        reverse(v);\n\
    \    }\n\n    void update(node_ptr v, const T& x) const {\n        access(v);\n\
    \        v->val = x;\n        recalc(v);\n    }\n\n    T fold(node_ptr u, node_ptr\
    \ v) const {\n        evert(u);\n        access(v);\n        return v->sum;\n\
    \    }\n\nprivate:\n    using RST::reverse;\n    using RST::recalc;\n    using\
    \ RST::splay;\n\n    void access(node_ptr v) const {\n        node_ptr prev =\
    \ nullptr;\n        for (auto cur = v; cur; cur = cur->par) {\n            splay(cur);\n\
    \            cur->right = prev;\n            recalc(cur);\n            prev =\
    \ cur;\n        }\n        splay(v);\n    }\n};\n"
  dependsOn:
  - data-structure/bst/reversible_splay_tree.cpp
  isVerificationFile: false
  path: tree/link_cut_tree.cpp
  requiredBy: []
  timestamp: '2020-10-29 10:57:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  - test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: tree/link_cut_tree.cpp
layout: document
redirect_from:
- /library/tree/link_cut_tree.cpp
- /library/tree/link_cut_tree.cpp.html
title: Link/Cut Tree
---
# Link/Cut Tree

Link/cut 木は，森を管理するデータ構造である．以下のクエリを処理できる:
- 辺の追加
- 辺の削除
- 根の変更
- 頂点の値の更新
- パス上の頂点の値の fold

木をパスに分解し，それぞれのパスに splay 木を用いることでこれらの操作を実現する．

空間計算量: $O(n)$

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Member functions

- `void link(node_ptr u, node_ptr v)`
    - 木 $u$ と木 $v$ を連結する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void cut(node_ptr v)`
    - 木 $v$ を親から切る
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void evert(node_ptr v)`
    - $v$ を木の根にする
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void update(node_ptr v, T x)`
    - 頂点 $v$ の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `T fold(node_ptr u, node_ptr v)`
    - $uv$ パス上の頂点の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$