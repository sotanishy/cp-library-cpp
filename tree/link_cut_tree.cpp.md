---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp.cpp
    title: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Link/Cut Tree
    links: []
  bundledCode: "#line 2 \"tree/link_cut_tree.cpp\"\n#include <algorithm>\n#include\
    \ <memory>\n\n/*\n * @brief Link/Cut Tree\n */\ntemplate <typename M>\nclass LinkCutTree\
    \ {\n    using T = typename M::T;\n    struct Node;\n\npublic:\n    using node_ptr\
    \ = std::shared_ptr<Node>;\n\n    node_ptr make_node(const T& x) const {\n   \
    \     return std::make_shared<Node>(x);\n    }\n\n    void link(node_ptr v, node_ptr\
    \ p) const {\n        make_root(v);\n        access(p);\n        v->par = p;\n\
    \        p->right = v;\n        update(p);\n    }\n\n    void cut(node_ptr v)\
    \ const {\n        access(v);\n        auto p = v->left;\n        v->left = p->par\
    \ = nullptr;\n        update(v);\n    }\n\n    void make_root(node_ptr v) const\
    \ {\n        access(v);\n        reverse(v);\n        push(v);\n    }\n\n    void\
    \ update(node_ptr v, const T& x) {\n        access(v);\n        v->val = x;\n\
    \        update(v);\n    }\n\n    T fold(node_ptr u, node_ptr v) {\n        make_root(u);\n\
    \        access(v);\n        return v->sum;\n    }\n\nprivate:\n    struct Node\
    \ {\n        node_ptr left, right, par;\n        T val, sum;\n        int sz;\n\
    \        bool rev;\n\n        Node() : left(nullptr), right(nullptr), par(nullptr),\
    \ sz(1), rev(false) {}\n        Node(const T& x) : Node() {\n            val =\
    \ sum = x;\n        }\n    };\n\n    void access(node_ptr v) const {\n       \
    \ node_ptr prev = nullptr;\n        for (auto cur = v; cur; cur = cur->par) {\n\
    \            splay(cur);\n            cur->right = prev;\n            update(cur);\n\
    \            prev = cur;\n        }\n        splay(v);\n    }\n\n    void update(const\
    \ node_ptr& t) const {\n        t->sz = 1;\n        t->sum = t->val;\n       \
    \ if (t->left) {\n            t->sz += t->left->sz;\n            t->sum = M::op(t->left->sum,\
    \ t->sum);\n        }\n        if (t->right) {\n            t->sz += t->right->sz;\n\
    \            t->sum = M::op(t->sum, t->right->sum);\n        }\n    }\n\n    void\
    \ push(const node_ptr& t) const {\n        if (t->rev) {\n            if (t->left)\
    \ reverse(t->left);\n            if (t->right) reverse(t->right);\n          \
    \  t->rev = false;\n        }\n    }\n\n    void reverse(const node_ptr& t) const\
    \ {\n        std::swap(t->left, t->right);\n        t->rev ^= true;\n    }\n\n\
    \    void splay(node_ptr t) const {\n        push(t);\n        while (!is_root(t))\
    \ {\n            auto x = t->par;\n            if (is_root(x)) {\n           \
    \     push(x);\n                push(t);\n                if (x->left == t) rotate_right(t);\n\
    \                else rotate_left(t);\n            } else {\n                auto\
    \ y = x->par;\n                push(y);\n                push(x);\n          \
    \      push(t);\n                if (y->left == x) {\n                    if (x->left\
    \ == t) {\n                        rotate_right(x);\n                        rotate_right(t);\n\
    \                    } else {\n                        rotate_left(t);\n     \
    \                   rotate_right(t);\n                    }\n                }\
    \ else {\n                    if (x->right == t) {\n                        rotate_left(x);\n\
    \                        rotate_left(t);\n                    } else {\n     \
    \                   rotate_right(t);\n                        rotate_left(t);\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    bool is_root(const node_ptr& t) const {\n        return !t->par || (t->par->left\
    \ != t && t->par->right != t);\n    }\n\n    void rotate_left(node_ptr t) const\
    \ {\n        auto x = t->par, y = x->par;\n        x->right = t->left;\n     \
    \   if (x->right) x->right->par = x;\n        t->left = x;\n        x->par = t;\n\
    \        update(x);\n        update(t);\n        t->par = y;\n        if (y) {\n\
    \            if (y->left == x) y->left = t;\n            if (y->right == x) y->right\
    \ = t;\n            update(y);\n        }\n    }\n\n    void rotate_right(node_ptr\
    \ t) const {\n        auto x = t->par, y = x->par;\n        x->left = t->right;\n\
    \        if (x->left) x->left->par = x;\n        t->right = x;\n        x->par\
    \ = t;\n        update(x);\n        update(t);\n        t->par = y;\n        if\
    \ (y) {\n            if (y->left == x) y->left = t;\n            if (y->right\
    \ == x) y->right = t;\n            update(y);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <memory>\n\n/*\n * @brief Link/Cut\
    \ Tree\n */\ntemplate <typename M>\nclass LinkCutTree {\n    using T = typename\
    \ M::T;\n    struct Node;\n\npublic:\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    node_ptr make_node(const T& x) const {\n        return std::make_shared<Node>(x);\n\
    \    }\n\n    void link(node_ptr v, node_ptr p) const {\n        make_root(v);\n\
    \        access(p);\n        v->par = p;\n        p->right = v;\n        update(p);\n\
    \    }\n\n    void cut(node_ptr v) const {\n        access(v);\n        auto p\
    \ = v->left;\n        v->left = p->par = nullptr;\n        update(v);\n    }\n\
    \n    void make_root(node_ptr v) const {\n        access(v);\n        reverse(v);\n\
    \        push(v);\n    }\n\n    void update(node_ptr v, const T& x) {\n      \
    \  access(v);\n        v->val = x;\n        update(v);\n    }\n\n    T fold(node_ptr\
    \ u, node_ptr v) {\n        make_root(u);\n        access(v);\n        return\
    \ v->sum;\n    }\n\nprivate:\n    struct Node {\n        node_ptr left, right,\
    \ par;\n        T val, sum;\n        int sz;\n        bool rev;\n\n        Node()\
    \ : left(nullptr), right(nullptr), par(nullptr), sz(1), rev(false) {}\n      \
    \  Node(const T& x) : Node() {\n            val = sum = x;\n        }\n    };\n\
    \n    void access(node_ptr v) const {\n        node_ptr prev = nullptr;\n    \
    \    for (auto cur = v; cur; cur = cur->par) {\n            splay(cur);\n    \
    \        cur->right = prev;\n            update(cur);\n            prev = cur;\n\
    \        }\n        splay(v);\n    }\n\n    void update(const node_ptr& t) const\
    \ {\n        t->sz = 1;\n        t->sum = t->val;\n        if (t->left) {\n  \
    \          t->sz += t->left->sz;\n            t->sum = M::op(t->left->sum, t->sum);\n\
    \        }\n        if (t->right) {\n            t->sz += t->right->sz;\n    \
    \        t->sum = M::op(t->sum, t->right->sum);\n        }\n    }\n\n    void\
    \ push(const node_ptr& t) const {\n        if (t->rev) {\n            if (t->left)\
    \ reverse(t->left);\n            if (t->right) reverse(t->right);\n          \
    \  t->rev = false;\n        }\n    }\n\n    void reverse(const node_ptr& t) const\
    \ {\n        std::swap(t->left, t->right);\n        t->rev ^= true;\n    }\n\n\
    \    void splay(node_ptr t) const {\n        push(t);\n        while (!is_root(t))\
    \ {\n            auto x = t->par;\n            if (is_root(x)) {\n           \
    \     push(x);\n                push(t);\n                if (x->left == t) rotate_right(t);\n\
    \                else rotate_left(t);\n            } else {\n                auto\
    \ y = x->par;\n                push(y);\n                push(x);\n          \
    \      push(t);\n                if (y->left == x) {\n                    if (x->left\
    \ == t) {\n                        rotate_right(x);\n                        rotate_right(t);\n\
    \                    } else {\n                        rotate_left(t);\n     \
    \                   rotate_right(t);\n                    }\n                }\
    \ else {\n                    if (x->right == t) {\n                        rotate_left(x);\n\
    \                        rotate_left(t);\n                    } else {\n     \
    \                   rotate_right(t);\n                        rotate_left(t);\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    bool is_root(const node_ptr& t) const {\n        return !t->par || (t->par->left\
    \ != t && t->par->right != t);\n    }\n\n    void rotate_left(node_ptr t) const\
    \ {\n        auto x = t->par, y = x->par;\n        x->right = t->left;\n     \
    \   if (x->right) x->right->par = x;\n        t->left = x;\n        x->par = t;\n\
    \        update(x);\n        update(t);\n        t->par = y;\n        if (y) {\n\
    \            if (y->left == x) y->left = t;\n            if (y->right == x) y->right\
    \ = t;\n            update(y);\n        }\n    }\n\n    void rotate_right(node_ptr\
    \ t) const {\n        auto x = t->par, y = x->par;\n        x->left = t->right;\n\
    \        if (x->left) x->left->par = x;\n        t->right = x;\n        x->par\
    \ = t;\n        update(x);\n        update(t);\n        t->par = y;\n        if\
    \ (y) {\n            if (y->left == x) y->left = t;\n            if (y->right\
    \ == x) y->right = t;\n            update(y);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/link_cut_tree.cpp
  requiredBy: []
  timestamp: '2020-10-26 00:14:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp.cpp
documentation_of: tree/link_cut_tree.cpp
layout: document
redirect_from:
- /library/tree/link_cut_tree.cpp
- /library/tree/link_cut_tree.cpp.html
title: Link/Cut Tree
---
