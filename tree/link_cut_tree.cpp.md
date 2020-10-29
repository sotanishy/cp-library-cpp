---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"tree/link_cut_tree.cpp\"\n#include <algorithm>\n#include\
    \ <memory>\n#include <vector>\n\n/*\n * @brief Link/Cut Tree\n * @docs docs/tree/link_cut_tree.md\n\
    \ */\ntemplate <typename M, typename M::T (*flip)(typename M::T)>\nclass LinkCutTree\
    \ {\n    using T = typename M::T;\n\npublic:\n    LinkCutTree() = default;\n \
    \   explicit LinkCutTree(int n) {\n        for (int i = 0; i < n; ++i) {\n   \
    \         vertex.push_back(std::make_shared<Node>(M::id));\n        }\n    }\n\
    \n    void link(int v, int p) {\n        evert(v);\n        expose(vertex[p]);\n\
    \        vertex[v]->par = vertex[p];\n        vertex[p]->right = vertex[v];\n\
    \        recalc(vertex[p]);\n    }\n\n    void cut(int v) {\n        expose(vertex[v]);\n\
    \        auto p = vertex[v]->left;\n        vertex[v]->left = p->par = nullptr;\n\
    \        recalc(vertex[v]);\n    }\n\n    void evert(int v) {\n        expose(vertex[v]);\n\
    \        reverse(vertex[v]);\n    }\n\n    T get(int v) {\n        return vertex[v]->val;\n\
    \    }\n\n    void set(int v, const T& x) {\n        expose(vertex[v]);\n    \
    \    vertex[v]->val = x;\n        recalc(vertex[v]);\n    }\n\n    T fold(int\
    \ u, int v) {\n        evert(u);\n        expose(vertex[v]);\n        return vertex[v]->sum;\n\
    \    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        node_ptr left, right, par;\n        T val, sum;\n\
    \        int sz;\n        bool rev;\n\n        Node(const T& x)\n            :\
    \ left(nullptr), right(nullptr), par(nullptr),\n              val(x), sum(x),\
    \ sz(1), rev(false) {}\n    };\n\n    std::vector<node_ptr> vertex;\n\n    static\
    \ void expose(node_ptr v) {\n        node_ptr prev = nullptr;\n        for (auto\
    \ cur = v; cur; cur = cur->par) {\n            splay(cur);\n            cur->right\
    \ = prev;\n            recalc(cur);\n            prev = cur;\n        }\n    \
    \    splay(v);\n    }\n\n    // splay tree\n\n    static int size(const node_ptr&\
    \ t) {\n        return t ? t->sz : 0;\n    }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
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
    \ == p->left) rotate_right(p);\n                else rotate_left(p);\n       \
    \     } else {\n                auto g = p->par;\n                push(g);\n \
    \               push(p);\n                push(t);\n                if (t == p->left)\
    \ {\n                    if (p == g->left) {\n                        rotate_right(g);\n\
    \                        rotate_right(p);\n                    } else {\n    \
    \                    rotate_right(p);\n                        rotate_left(g);\n\
    \                    }\n                } else {\n                    if (p ==\
    \ g->left) {\n                        rotate_left(p);\n                      \
    \  rotate_right(g);\n                    } else {\n                        rotate_left(g);\n\
    \                        rotate_left(p);\n                    }\n            \
    \    }\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <memory>\n#include <vector>\n\
    \n/*\n * @brief Link/Cut Tree\n * @docs docs/tree/link_cut_tree.md\n */\ntemplate\
    \ <typename M, typename M::T (*flip)(typename M::T)>\nclass LinkCutTree {\n  \
    \  using T = typename M::T;\n\npublic:\n    LinkCutTree() = default;\n    explicit\
    \ LinkCutTree(int n) {\n        for (int i = 0; i < n; ++i) {\n            vertex.push_back(std::make_shared<Node>(M::id));\n\
    \        }\n    }\n\n    void link(int v, int p) {\n        evert(v);\n      \
    \  expose(vertex[p]);\n        vertex[v]->par = vertex[p];\n        vertex[p]->right\
    \ = vertex[v];\n        recalc(vertex[p]);\n    }\n\n    void cut(int v) {\n \
    \       expose(vertex[v]);\n        auto p = vertex[v]->left;\n        vertex[v]->left\
    \ = p->par = nullptr;\n        recalc(vertex[v]);\n    }\n\n    void evert(int\
    \ v) {\n        expose(vertex[v]);\n        reverse(vertex[v]);\n    }\n\n   \
    \ T get(int v) {\n        return vertex[v]->val;\n    }\n\n    void set(int v,\
    \ const T& x) {\n        expose(vertex[v]);\n        vertex[v]->val = x;\n   \
    \     recalc(vertex[v]);\n    }\n\n    T fold(int u, int v) {\n        evert(u);\n\
    \        expose(vertex[v]);\n        return vertex[v]->sum;\n    }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        node_ptr left, right, par;\n        T val, sum;\n        int sz;\n\
    \        bool rev;\n\n        Node(const T& x)\n            : left(nullptr), right(nullptr),\
    \ par(nullptr),\n              val(x), sum(x), sz(1), rev(false) {}\n    };\n\n\
    \    std::vector<node_ptr> vertex;\n\n    static void expose(node_ptr v) {\n \
    \       node_ptr prev = nullptr;\n        for (auto cur = v; cur; cur = cur->par)\
    \ {\n            splay(cur);\n            cur->right = prev;\n            recalc(cur);\n\
    \            prev = cur;\n        }\n        splay(v);\n    }\n\n    // splay\
    \ tree\n\n    static int size(const node_ptr& t) {\n        return t ? t->sz :\
    \ 0;\n    }\n\n    static void recalc(const node_ptr& t) {\n        if (!t) return;\n\
    \        t->sz = size(t->left) + 1 + size(t->right);\n        t->sum = t->val;\n\
    \        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n        if (t->right)\
    \ t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static void push(const\
    \ node_ptr& t) {\n        if (t->rev) {\n            if (t->left) reverse(t->left);\n\
    \            if (t->right) reverse(t->right);\n            t->rev = false;\n \
    \       }\n    }\n\n    static void reverse(const node_ptr& t) {\n        std::swap(t->left,\
    \ t->right);\n        t->sum = flip(t->sum);\n        t->rev ^= true;\n    }\n\
    \n    static void rotate_left(node_ptr t) {\n        node_ptr s = t->right;\n\
    \        t->right = s->left;\n        if (s->left) s->left->par = t;\n       \
    \ s->par = t->par;\n        if (t->par) {\n            if (t->par->left == t)\
    \ {\n                t->par->left = s;\n            }\n            if (t->par->right\
    \ == t) {\n                t->par->right = s;\n            }\n        }\n    \
    \    s->left = t;\n        t->par = s;\n        recalc(t);\n        recalc(s);\n\
    \    }\n\n    static void rotate_right(node_ptr t) {\n        node_ptr s = t->left;\n\
    \        t->left = s->right;\n        if (s->right) s->right->par = t;\n     \
    \   s->par = t->par;\n        if (t->par) {\n            if (t->par->left == t)\
    \ {\n                t->par->left = s;\n            }\n            if (t->par->right\
    \ == t) {\n                t->par->right = s;\n            }\n        }\n    \
    \    s->right = t;\n        t->par = s;\n        recalc(t);\n        recalc(s);\n\
    \    }\n\n    static bool is_root(const node_ptr& t) {\n        return !t->par\
    \ || (t->par->left != t && t->par->right != t);\n    }\n\n    static void splay(node_ptr\
    \ t) {\n        push(t);\n        while (!is_root(t)) {\n            auto p =\
    \ t->par;\n            if (is_root(p)) {\n                push(p);\n         \
    \       push(t);\n                if (t == p->left) rotate_right(p);\n       \
    \         else rotate_left(p);\n            } else {\n                auto g =\
    \ p->par;\n                push(g);\n                push(p);\n              \
    \  push(t);\n                if (t == p->left) {\n                    if (p ==\
    \ g->left) {\n                        rotate_right(g);\n                     \
    \   rotate_right(p);\n                    } else {\n                        rotate_right(p);\n\
    \                        rotate_left(g);\n                    }\n            \
    \    } else {\n                    if (p == g->left) {\n                     \
    \   rotate_left(p);\n                        rotate_right(g);\n              \
    \      } else {\n                        rotate_left(g);\n                   \
    \     rotate_left(p);\n                    }\n                }\n            }\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/link_cut_tree.cpp
  requiredBy: []
  timestamp: '2020-10-30 00:16:07+09:00'
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
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Member functions

- `void link(int u, int v)`
    - 木 $u$ と木 $v$ を連結する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void cut(int v)`
    - 木 $v$ を親から切る
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void evert(int v)`
    - $v$ を木の根にする
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void get(int v)`
    - $v$ の値を取得する
    - 時間計算量: $O(1)$
- `void set(int v, T x)`
    - 頂点 $v$ の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `T fold(int u, int v)`
    - $uv$ パス上の頂点の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$