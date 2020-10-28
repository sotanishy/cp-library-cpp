---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/link_cut_tree.cpp
    title: Link/Cut Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Reversible Splay Tree
    links: []
  bundledCode: "#line 2 \"data-structure/reversible_splay_tree.cpp\"\n#include <algorithm>\n\
    #include <memory>\n\n/*\n * @brief Reversible Splay Tree\n */\ntemplate <typename\
    \ M, typename M::T (*flip)(typename M::T)>\nclass ReversibleSplayTree {\n    using\
    \ T = typename M::T;\n\nprotected:\n    struct Node;\n\npublic:\n    using node_ptr\
    \ = std::shared_ptr<Node>;\n\n    node_ptr make_node(const T& x) const {\n   \
    \     return std::make_shared<Node>(x);\n    }\n\n    void reverse(const node_ptr&\
    \ t) const {\n        std::swap(t->left, t->right);\n        t->sum = flip(t->sum);\n\
    \        t->rev ^= true;\n    }\n\nprotected:\n    struct Node {\n        node_ptr\
    \ left, right, par;\n        T val, sum;\n        int sz;\n        bool rev;\n\
    \n        Node() : left(nullptr), right(nullptr), par(nullptr), sz(1), rev(false)\
    \ {}\n        Node(const T& x) : Node() {\n            val = sum = x;\n      \
    \  }\n    };\n\n    bool is_root(const node_ptr& t) const {\n        return !t->par\
    \ || (t->par->left != t && t->par->right != t);\n    }\n\n    void recalc(const\
    \ node_ptr& t) const {\n        t->sz = 1;\n        t->sum = t->val;\n       \
    \ if (t->left) {\n            t->sz += t->left->sz;\n            t->sum = M::op(t->left->sum,\
    \ t->sum);\n        }\n        if (t->right) {\n            t->sz += t->right->sz;\n\
    \            t->sum = M::op(t->sum, t->right->sum);\n        }\n    }\n\n    void\
    \ rotate_left(node_ptr t) const {\n        auto x = t->par, y = x->par;\n    \
    \    x->right = t->left;\n        if (x->right) x->right->par = x;\n        t->left\
    \ = x;\n        x->par = t;\n        recalc(x);\n        recalc(t);\n        t->par\
    \ = y;\n        if (y) {\n            if (y->left == x) y->left = t;\n       \
    \     if (y->right == x) y->right = t;\n            recalc(y);\n        }\n  \
    \  }\n\n    void rotate_right(node_ptr t) const {\n        auto x = t->par, y\
    \ = x->par;\n        x->left = t->right;\n        if (x->left) x->left->par =\
    \ x;\n        t->right = x;\n        x->par = t;\n        recalc(x);\n       \
    \ recalc(t);\n        t->par = y;\n        if (y) {\n            if (y->left ==\
    \ x) y->left = t;\n            if (y->right == x) y->right = t;\n            recalc(y);\n\
    \        }\n    }\n\n    void push(const node_ptr& t) const {\n        if (t->rev)\
    \ {\n            if (t->left) reverse(t->left);\n            if (t->right) reverse(t->right);\n\
    \            t->rev = false;\n        }\n    }\n\n    void splay(node_ptr t) const\
    \ {\n        push(t);\n        while (!is_root(t)) {\n            auto x = t->par;\n\
    \            if (is_root(x)) {\n                push(x);\n                push(t);\n\
    \                if (x->left == t) rotate_right(t);\n                else rotate_left(t);\n\
    \            } else {\n                auto y = x->par;\n                push(y);\n\
    \                push(x);\n                push(t);\n                if (y->left\
    \ == x) {\n                    if (x->left == t) {\n                        rotate_right(x);\n\
    \                        rotate_right(t);\n                    } else {\n    \
    \                    rotate_left(t);\n                        rotate_right(t);\n\
    \                    }\n                } else {\n                    if (x->right\
    \ == t) {\n                        rotate_left(x);\n                        rotate_left(t);\n\
    \                    } else {\n                        rotate_right(t);\n    \
    \                    rotate_left(t);\n                    }\n                }\n\
    \            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <memory>\n\n/*\n * @brief Reversible\
    \ Splay Tree\n */\ntemplate <typename M, typename M::T (*flip)(typename M::T)>\n\
    class ReversibleSplayTree {\n    using T = typename M::T;\n\nprotected:\n    struct\
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
    \            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/reversible_splay_tree.cpp
  requiredBy:
  - tree/link_cut_tree.cpp
  timestamp: '2020-10-28 12:21:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
documentation_of: data-structure/reversible_splay_tree.cpp
layout: document
redirect_from:
- /library/data-structure/reversible_splay_tree.cpp
- /library/data-structure/reversible_splay_tree.cpp.html
title: Reversible Splay Tree
---
