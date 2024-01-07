---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
    title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/link_cut_tree.hpp\"\n#include <algorithm>\n#include\
    \ <memory>\n#include <vector>\n\ntemplate <typename M, typename M::T (*flip)(typename\
    \ M::T)>\nclass LinkCutTree {\n    using T = M::T;\n\n   public:\n    LinkCutTree()\
    \ = default;\n    explicit LinkCutTree(int n) {\n        for (int i = 0; i < n;\
    \ ++i) {\n            vertex.push_back(std::make_shared<Node>(M::id));\n     \
    \   }\n    }\n\n    void link(int v, int p) {\n        evert(v);\n        expose(vertex[p]);\n\
    \        vertex[v]->par = vertex[p];\n        vertex[p]->right = vertex[v];\n\
    \        recalc(vertex[p]);\n    }\n\n    void cut(int v) {\n        expose(vertex[v]);\n\
    \        auto p = vertex[v]->left;\n        vertex[v]->left = p->par = nullptr;\n\
    \        recalc(vertex[v]);\n    }\n\n    void evert(int v) {\n        expose(vertex[v]);\n\
    \        reverse(vertex[v]);\n    }\n\n    T get(int v) const { return vertex[v]->val;\
    \ }\n\n    void set(int v, const T& x) {\n        expose(vertex[v]);\n       \
    \ vertex[v]->val = x;\n        recalc(vertex[v]);\n    }\n\n    T fold(int u,\
    \ int v) {\n        evert(u);\n        expose(vertex[v]);\n        return vertex[v]->sum;\n\
    \    }\n\n   private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        node_ptr left, right, par;\n        T val, sum;\n\
    \        int sz;\n        bool rev;\n\n        Node(const T& x)\n            :\
    \ left(nullptr),\n              right(nullptr),\n              par(nullptr),\n\
    \              val(x),\n              sum(x),\n              sz(1),\n        \
    \      rev(false) {}\n    };\n\n    std::vector<node_ptr> vertex;\n\n    static\
    \ void expose(node_ptr v) {\n        node_ptr prev = nullptr;\n        for (auto\
    \ cur = v; cur; cur = cur->par) {\n            splay(cur);\n            cur->right\
    \ = prev;\n            recalc(cur);\n            prev = cur;\n        }\n    \
    \    splay(v);\n    }\n\n    // splay tree\n\n    static int size(const node_ptr&\
    \ t) { return t ? t->sz : 0; }\n\n    static void recalc(const node_ptr& t) {\n\
    \        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ void push(const node_ptr& t) {\n        if (t->rev) {\n            if (t->left)\
    \ reverse(t->left);\n            if (t->right) reverse(t->right);\n          \
    \  t->rev = false;\n        }\n    }\n\n    static void reverse(const node_ptr&\
    \ t) {\n        std::swap(t->left, t->right);\n        t->sum = flip(t->sum);\n\
    \        t->rev ^= true;\n    }\n\n    static void rotate_left(node_ptr t) {\n\
    \        node_ptr s = t->right;\n        t->right = s->left;\n        if (s->left)\
    \ s->left->par = t;\n        s->par = t->par;\n        if (t->par) {\n       \
    \     if (t->par->left == t) {\n                t->par->left = s;\n          \
    \  }\n            if (t->par->right == t) {\n                t->par->right = s;\n\
    \            }\n        }\n        s->left = t;\n        t->par = s;\n       \
    \ recalc(t);\n        recalc(s);\n    }\n\n    static void rotate_right(node_ptr\
    \ t) {\n        node_ptr s = t->left;\n        t->left = s->right;\n        if\
    \ (s->right) s->right->par = t;\n        s->par = t->par;\n        if (t->par)\
    \ {\n            if (t->par->left == t) {\n                t->par->left = s;\n\
    \            }\n            if (t->par->right == t) {\n                t->par->right\
    \ = s;\n            }\n        }\n        s->right = t;\n        t->par = s;\n\
    \        recalc(t);\n        recalc(s);\n    }\n\n    static bool is_root(const\
    \ node_ptr& t) {\n        return !t->par || (t->par->left != t && t->par->right\
    \ != t);\n    }\n\n    static void splay(node_ptr t) {\n        push(t);\n   \
    \     while (!is_root(t)) {\n            auto p = t->par;\n            if (is_root(p))\
    \ {\n                push(p);\n                push(t);\n                if (t\
    \ == p->left)\n                    rotate_right(p);\n                else\n  \
    \                  rotate_left(p);\n            } else {\n                auto\
    \ g = p->par;\n                push(g);\n                push(p);\n          \
    \      push(t);\n                if (t == p->left) {\n                    if (p\
    \ == g->left) {\n                        rotate_right(g);\n                  \
    \      rotate_right(p);\n                    } else {\n                      \
    \  rotate_right(p);\n                        rotate_left(g);\n               \
    \     }\n                } else {\n                    if (p == g->left) {\n \
    \                       rotate_left(p);\n                        rotate_right(g);\n\
    \                    } else {\n                        rotate_left(g);\n     \
    \                   rotate_left(p);\n                    }\n                }\n\
    \            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <memory>\n#include <vector>\n\
    \ntemplate <typename M, typename M::T (*flip)(typename M::T)>\nclass LinkCutTree\
    \ {\n    using T = M::T;\n\n   public:\n    LinkCutTree() = default;\n    explicit\
    \ LinkCutTree(int n) {\n        for (int i = 0; i < n; ++i) {\n            vertex.push_back(std::make_shared<Node>(M::id));\n\
    \        }\n    }\n\n    void link(int v, int p) {\n        evert(v);\n      \
    \  expose(vertex[p]);\n        vertex[v]->par = vertex[p];\n        vertex[p]->right\
    \ = vertex[v];\n        recalc(vertex[p]);\n    }\n\n    void cut(int v) {\n \
    \       expose(vertex[v]);\n        auto p = vertex[v]->left;\n        vertex[v]->left\
    \ = p->par = nullptr;\n        recalc(vertex[v]);\n    }\n\n    void evert(int\
    \ v) {\n        expose(vertex[v]);\n        reverse(vertex[v]);\n    }\n\n   \
    \ T get(int v) const { return vertex[v]->val; }\n\n    void set(int v, const T&\
    \ x) {\n        expose(vertex[v]);\n        vertex[v]->val = x;\n        recalc(vertex[v]);\n\
    \    }\n\n    T fold(int u, int v) {\n        evert(u);\n        expose(vertex[v]);\n\
    \        return vertex[v]->sum;\n    }\n\n   private:\n    struct Node;\n    using\
    \ node_ptr = std::shared_ptr<Node>;\n\n    struct Node {\n        node_ptr left,\
    \ right, par;\n        T val, sum;\n        int sz;\n        bool rev;\n\n   \
    \     Node(const T& x)\n            : left(nullptr),\n              right(nullptr),\n\
    \              par(nullptr),\n              val(x),\n              sum(x),\n \
    \             sz(1),\n              rev(false) {}\n    };\n\n    std::vector<node_ptr>\
    \ vertex;\n\n    static void expose(node_ptr v) {\n        node_ptr prev = nullptr;\n\
    \        for (auto cur = v; cur; cur = cur->par) {\n            splay(cur);\n\
    \            cur->right = prev;\n            recalc(cur);\n            prev =\
    \ cur;\n        }\n        splay(v);\n    }\n\n    // splay tree\n\n    static\
    \ int size(const node_ptr& t) { return t ? t->sz : 0; }\n\n    static void recalc(const\
    \ node_ptr& t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 +\
    \ size(t->right);\n        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum,\
    \ t->sum);\n        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n   \
    \ }\n\n    static void push(const node_ptr& t) {\n        if (t->rev) {\n    \
    \        if (t->left) reverse(t->left);\n            if (t->right) reverse(t->right);\n\
    \            t->rev = false;\n        }\n    }\n\n    static void reverse(const\
    \ node_ptr& t) {\n        std::swap(t->left, t->right);\n        t->sum = flip(t->sum);\n\
    \        t->rev ^= true;\n    }\n\n    static void rotate_left(node_ptr t) {\n\
    \        node_ptr s = t->right;\n        t->right = s->left;\n        if (s->left)\
    \ s->left->par = t;\n        s->par = t->par;\n        if (t->par) {\n       \
    \     if (t->par->left == t) {\n                t->par->left = s;\n          \
    \  }\n            if (t->par->right == t) {\n                t->par->right = s;\n\
    \            }\n        }\n        s->left = t;\n        t->par = s;\n       \
    \ recalc(t);\n        recalc(s);\n    }\n\n    static void rotate_right(node_ptr\
    \ t) {\n        node_ptr s = t->left;\n        t->left = s->right;\n        if\
    \ (s->right) s->right->par = t;\n        s->par = t->par;\n        if (t->par)\
    \ {\n            if (t->par->left == t) {\n                t->par->left = s;\n\
    \            }\n            if (t->par->right == t) {\n                t->par->right\
    \ = s;\n            }\n        }\n        s->right = t;\n        t->par = s;\n\
    \        recalc(t);\n        recalc(s);\n    }\n\n    static bool is_root(const\
    \ node_ptr& t) {\n        return !t->par || (t->par->left != t && t->par->right\
    \ != t);\n    }\n\n    static void splay(node_ptr t) {\n        push(t);\n   \
    \     while (!is_root(t)) {\n            auto p = t->par;\n            if (is_root(p))\
    \ {\n                push(p);\n                push(t);\n                if (t\
    \ == p->left)\n                    rotate_right(p);\n                else\n  \
    \                  rotate_left(p);\n            } else {\n                auto\
    \ g = p->par;\n                push(g);\n                push(p);\n          \
    \      push(t);\n                if (t == p->left) {\n                    if (p\
    \ == g->left) {\n                        rotate_right(g);\n                  \
    \      rotate_right(p);\n                    } else {\n                      \
    \  rotate_right(p);\n                        rotate_left(g);\n               \
    \     }\n                } else {\n                    if (p == g->left) {\n \
    \                       rotate_left(p);\n                        rotate_right(g);\n\
    \                    } else {\n                        rotate_left(g);\n     \
    \                   rotate_left(p);\n                    }\n                }\n\
    \            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/link_cut_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
documentation_of: tree/link_cut_tree.hpp
layout: document
redirect_from:
- /library/tree/link_cut_tree.hpp
- /library/tree/link_cut_tree.hpp.html
title: tree/link_cut_tree.hpp
---
