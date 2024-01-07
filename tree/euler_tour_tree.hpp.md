---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_subtree_add_subtree_sum.test.cpp
    title: test/yosupo/dynamic_tree_subtree_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/euler_tour_tree.hpp\"\n#include <cassert>\n#include\
    \ <memory>\n#include <unordered_map>\n#include <utility>\n#include <vector>\n\n\
    template <typename M, typename O,\n          typename M::T (*act)(typename M::T,\
    \ typename O::T)>\nclass EulerTourTree {\n    using T = M::T;\n    using E = O::T;\n\
    \n   public:\n    EulerTourTree() = default;\n    explicit EulerTourTree(int n)\
    \ {\n        ptr.resize(n);\n        for (int i = 0; i < n; ++i) {\n         \
    \   ptr[i][i] = std::make_shared<Node>(i, i);\n        }\n    }\n\n    void link(int\
    \ u, int v) {\n        assert(!same(u, v));\n        auto tu = reroot(get_node(u,\
    \ u));\n        auto tv = reroot(get_node(v, v));\n        join(join(tu, get_node(u,\
    \ v)), join(tv, get_node(v, u)));\n    }\n\n    void cut(int u, int v) {\n   \
    \     assert(ptr[u].find(v) != ptr[u].end());\n        auto [a, b, c] = split(get_node(u,\
    \ v), get_node(v, u));\n        join(a, c);\n        ptr[u].erase(v);\n      \
    \  ptr[v].erase(u);\n    }\n\n    bool same(int u, int v) { return same(get_node(u,\
    \ u), get_node(v, v)); }\n\n    T get(int v) {\n        auto t = get_node(v, v);\n\
    \        splay(t);\n        return t->val;\n    }\n\n    void update(int v, const\
    \ T& x) {\n        auto t = get_node(v, v);\n        splay(t);\n        t->val\
    \ = x;\n        recalc(t);\n    }\n\n    void update(int v, int p, const E& x)\
    \ {\n        cut(p, v);\n        auto t = get_node(v, v);\n        splay(t);\n\
    \        t->lazy = O::op(t->lazy, x);\n        link(p, v);\n    }\n\n    T fold(int\
    \ v, int p = -1) {\n        if (p != -1) cut(p, v);\n        auto t = get_node(v,\
    \ v);\n        splay(t);\n        T ret = t->sum;\n        if (p != -1) link(p,\
    \ v);\n        return ret;\n    }\n\n   private:\n    struct Node;\n    using\
    \ node_ptr = std::shared_ptr<Node>;\n\n    struct Node {\n        node_ptr ch[2]\
    \ = {nullptr, nullptr};\n        node_ptr par = nullptr;\n        int from, to,\
    \ sz;\n        T val = M::id(), sum = M::id();\n        E lazy = O::id();\n  \
    \      Node(int from, int to) : from(from), to(to), sz(from == to) {}\n    };\n\
    \n    std::vector<std::unordered_map<int, node_ptr>> ptr;\n\n    node_ptr get_node(int\
    \ u, int v) {\n        if (ptr[u].find(v) == ptr[u].end())\n            ptr[u][v]\
    \ = std::make_shared<Node>(u, v);\n        return ptr[u][v];\n    }\n\n    static\
    \ node_ptr root(node_ptr t) {\n        if (!t) return nullptr;\n        while\
    \ (t->par) t = t->par;\n        return t;\n    }\n\n    static bool same(node_ptr\
    \ s, node_ptr t) {\n        if (s) splay(s);\n        if (t) splay(t);\n     \
    \   return root(s) == root(t);\n    }\n\n    static node_ptr reroot(node_ptr t)\
    \ {\n        auto s = split(t);\n        return join(s.second, s.first);\n   \
    \ }\n\n    // splay tree\n\n    static int size(const node_ptr& t) { return t\
    \ ? t->sz : 0; }\n\n    static node_ptr recalc(const node_ptr& t) {\n        if\
    \ (!t) return t;\n        t->sz = size(t->ch[0]) + (t->from == t->to) + size(t->ch[1]);\n\
    \        t->sum = t->val;\n        if (t->ch[0]) t->sum = M::op(t->ch[0]->sum,\
    \ t->sum);\n        if (t->ch[1]) t->sum = M::op(t->sum, t->ch[1]->sum);\n   \
    \     return t;\n    }\n\n    static void push(const node_ptr& t) {\n        if\
    \ (t->lazy != O::id()) {\n            t->val = act(t->val, t->lazy);\n       \
    \     if (t->ch[0]) {\n                t->ch[0]->lazy = O::op(t->ch[0]->lazy,\
    \ t->lazy);\n                t->ch[0]->sum = act(t->ch[0]->sum, t->lazy);\n  \
    \          }\n            if (t->ch[1]) {\n                t->ch[1]->lazy = O::op(t->ch[1]->lazy,\
    \ t->lazy);\n                t->ch[1]->sum = act(t->ch[1]->sum, t->lazy);\n  \
    \          }\n            t->lazy = O::id();\n        }\n        recalc(t);\n\
    \    }\n\n    static node_ptr join(node_ptr l, node_ptr r) {\n        if (!l)\
    \ return r;\n        if (!r) return l;\n        while (l->ch[1]) l = l->ch[1];\n\
    \        splay(l);\n        l->ch[1] = r;\n        r->par = l;\n        return\
    \ recalc(l);\n    }\n\n    static std::pair<node_ptr, node_ptr> split(node_ptr\
    \ t) {\n        splay(t);\n        auto s = t->ch[0];\n        t->ch[0] = nullptr;\n\
    \        if (s) s->par = nullptr;\n        return {s, recalc(t)};\n    }\n\n \
    \   static std::pair<node_ptr, node_ptr> split2(node_ptr t) {\n        splay(t);\n\
    \        auto l = t->ch[0];\n        auto r = t->ch[1];\n        t->ch[0] = nullptr;\n\
    \        if (l) l->par = nullptr;\n        t->ch[1] = nullptr;\n        if (r)\
    \ r->par = nullptr;\n        return {l, r};\n    }\n\n    static std::tuple<node_ptr,\
    \ node_ptr, node_ptr> split(node_ptr s,\n                                    \
    \                      node_ptr t) {\n        auto [a, b] = split2(s);\n     \
    \   if (same(a, t)) {\n            auto [c, d] = split2(t);\n            return\
    \ {c, d, b};\n        } else {\n            auto [c, d] = split2(t);\n       \
    \     return {a, c, d};\n        }\n    }\n\n    static void rotate(node_ptr t,\
    \ bool b) {\n        node_ptr p = t->par, g = p->par;\n        p->ch[1 - b] =\
    \ t->ch[b];\n        if (p->ch[1 - b]) t->ch[b]->par = p;\n        t->ch[b] =\
    \ p;\n        p->par = t;\n        recalc(p);\n        recalc(t);\n        t->par\
    \ = g;\n        if (t->par) {\n            if (g->ch[0] == p)\n              \
    \  g->ch[0] = t;\n            else\n                g->ch[1] = t;\n          \
    \  recalc(g);\n        }\n    }\n\n    static void splay(node_ptr t) {\n     \
    \   push(t);\n        while (t->par) {\n            auto p = t->par, g = p->par;\n\
    \            if (!g) {\n                push(p);\n                push(t);\n \
    \               rotate(t, p->ch[0] == t);\n            } else {\n            \
    \    push(g);\n                push(p);\n                push(t);\n          \
    \      bool b = g->ch[0] == p;\n                if (p->ch[1 - b] == t) {\n   \
    \                 rotate(p, b);\n                    rotate(t, b);\n         \
    \       } else {\n                    rotate(t, 1 - b);\n                    rotate(t,\
    \ b);\n                }\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename M, typename O,\n \
    \         typename M::T (*act)(typename M::T, typename O::T)>\nclass EulerTourTree\
    \ {\n    using T = M::T;\n    using E = O::T;\n\n   public:\n    EulerTourTree()\
    \ = default;\n    explicit EulerTourTree(int n) {\n        ptr.resize(n);\n  \
    \      for (int i = 0; i < n; ++i) {\n            ptr[i][i] = std::make_shared<Node>(i,\
    \ i);\n        }\n    }\n\n    void link(int u, int v) {\n        assert(!same(u,\
    \ v));\n        auto tu = reroot(get_node(u, u));\n        auto tv = reroot(get_node(v,\
    \ v));\n        join(join(tu, get_node(u, v)), join(tv, get_node(v, u)));\n  \
    \  }\n\n    void cut(int u, int v) {\n        assert(ptr[u].find(v) != ptr[u].end());\n\
    \        auto [a, b, c] = split(get_node(u, v), get_node(v, u));\n        join(a,\
    \ c);\n        ptr[u].erase(v);\n        ptr[v].erase(u);\n    }\n\n    bool same(int\
    \ u, int v) { return same(get_node(u, u), get_node(v, v)); }\n\n    T get(int\
    \ v) {\n        auto t = get_node(v, v);\n        splay(t);\n        return t->val;\n\
    \    }\n\n    void update(int v, const T& x) {\n        auto t = get_node(v, v);\n\
    \        splay(t);\n        t->val = x;\n        recalc(t);\n    }\n\n    void\
    \ update(int v, int p, const E& x) {\n        cut(p, v);\n        auto t = get_node(v,\
    \ v);\n        splay(t);\n        t->lazy = O::op(t->lazy, x);\n        link(p,\
    \ v);\n    }\n\n    T fold(int v, int p = -1) {\n        if (p != -1) cut(p, v);\n\
    \        auto t = get_node(v, v);\n        splay(t);\n        T ret = t->sum;\n\
    \        if (p != -1) link(p, v);\n        return ret;\n    }\n\n   private:\n\
    \    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        node_ptr ch[2] = {nullptr, nullptr};\n        node_ptr par = nullptr;\n\
    \        int from, to, sz;\n        T val = M::id(), sum = M::id();\n        E\
    \ lazy = O::id();\n        Node(int from, int to) : from(from), to(to), sz(from\
    \ == to) {}\n    };\n\n    std::vector<std::unordered_map<int, node_ptr>> ptr;\n\
    \n    node_ptr get_node(int u, int v) {\n        if (ptr[u].find(v) == ptr[u].end())\n\
    \            ptr[u][v] = std::make_shared<Node>(u, v);\n        return ptr[u][v];\n\
    \    }\n\n    static node_ptr root(node_ptr t) {\n        if (!t) return nullptr;\n\
    \        while (t->par) t = t->par;\n        return t;\n    }\n\n    static bool\
    \ same(node_ptr s, node_ptr t) {\n        if (s) splay(s);\n        if (t) splay(t);\n\
    \        return root(s) == root(t);\n    }\n\n    static node_ptr reroot(node_ptr\
    \ t) {\n        auto s = split(t);\n        return join(s.second, s.first);\n\
    \    }\n\n    // splay tree\n\n    static int size(const node_ptr& t) { return\
    \ t ? t->sz : 0; }\n\n    static node_ptr recalc(const node_ptr& t) {\n      \
    \  if (!t) return t;\n        t->sz = size(t->ch[0]) + (t->from == t->to) + size(t->ch[1]);\n\
    \        t->sum = t->val;\n        if (t->ch[0]) t->sum = M::op(t->ch[0]->sum,\
    \ t->sum);\n        if (t->ch[1]) t->sum = M::op(t->sum, t->ch[1]->sum);\n   \
    \     return t;\n    }\n\n    static void push(const node_ptr& t) {\n        if\
    \ (t->lazy != O::id()) {\n            t->val = act(t->val, t->lazy);\n       \
    \     if (t->ch[0]) {\n                t->ch[0]->lazy = O::op(t->ch[0]->lazy,\
    \ t->lazy);\n                t->ch[0]->sum = act(t->ch[0]->sum, t->lazy);\n  \
    \          }\n            if (t->ch[1]) {\n                t->ch[1]->lazy = O::op(t->ch[1]->lazy,\
    \ t->lazy);\n                t->ch[1]->sum = act(t->ch[1]->sum, t->lazy);\n  \
    \          }\n            t->lazy = O::id();\n        }\n        recalc(t);\n\
    \    }\n\n    static node_ptr join(node_ptr l, node_ptr r) {\n        if (!l)\
    \ return r;\n        if (!r) return l;\n        while (l->ch[1]) l = l->ch[1];\n\
    \        splay(l);\n        l->ch[1] = r;\n        r->par = l;\n        return\
    \ recalc(l);\n    }\n\n    static std::pair<node_ptr, node_ptr> split(node_ptr\
    \ t) {\n        splay(t);\n        auto s = t->ch[0];\n        t->ch[0] = nullptr;\n\
    \        if (s) s->par = nullptr;\n        return {s, recalc(t)};\n    }\n\n \
    \   static std::pair<node_ptr, node_ptr> split2(node_ptr t) {\n        splay(t);\n\
    \        auto l = t->ch[0];\n        auto r = t->ch[1];\n        t->ch[0] = nullptr;\n\
    \        if (l) l->par = nullptr;\n        t->ch[1] = nullptr;\n        if (r)\
    \ r->par = nullptr;\n        return {l, r};\n    }\n\n    static std::tuple<node_ptr,\
    \ node_ptr, node_ptr> split(node_ptr s,\n                                    \
    \                      node_ptr t) {\n        auto [a, b] = split2(s);\n     \
    \   if (same(a, t)) {\n            auto [c, d] = split2(t);\n            return\
    \ {c, d, b};\n        } else {\n            auto [c, d] = split2(t);\n       \
    \     return {a, c, d};\n        }\n    }\n\n    static void rotate(node_ptr t,\
    \ bool b) {\n        node_ptr p = t->par, g = p->par;\n        p->ch[1 - b] =\
    \ t->ch[b];\n        if (p->ch[1 - b]) t->ch[b]->par = p;\n        t->ch[b] =\
    \ p;\n        p->par = t;\n        recalc(p);\n        recalc(t);\n        t->par\
    \ = g;\n        if (t->par) {\n            if (g->ch[0] == p)\n              \
    \  g->ch[0] = t;\n            else\n                g->ch[1] = t;\n          \
    \  recalc(g);\n        }\n    }\n\n    static void splay(node_ptr t) {\n     \
    \   push(t);\n        while (t->par) {\n            auto p = t->par, g = p->par;\n\
    \            if (!g) {\n                push(p);\n                push(t);\n \
    \               rotate(t, p->ch[0] == t);\n            } else {\n            \
    \    push(g);\n                push(p);\n                push(t);\n          \
    \      bool b = g->ch[0] == p;\n                if (p->ch[1 - b] == t) {\n   \
    \                 rotate(p, b);\n                    rotate(t, b);\n         \
    \       } else {\n                    rotate(t, 1 - b);\n                    rotate(t,\
    \ b);\n                }\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: tree/euler_tour_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:08:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  - test/yosupo/dynamic_tree_subtree_add_subtree_sum.test.cpp
documentation_of: tree/euler_tour_tree.hpp
layout: document
title: Euler Tour Tree
---

## Description

Euler tour tree は，森を管理するデータ構造である．以下の機能を提供する:
- 辺の追加
- 辺の削除
- 頂点の値の更新
- 部分木に対する作用
- 部分木の頂点の値 (可換モノイド) の総和

オイラーツアーを平衡二分探索木で管理することでこれらの操作を実現する．この実装では splay tree を用いている．

空間計算量: $O(n)$

## Operations

- `EulerTourTree(int n)`
    - 頂点数 $n$ で初期化する
    - 時間計算量: $O(n)$
- `void link(int u, int v)`
    - 辺 $uv$ を追加する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void cut(int u, int v)`
    - 辺 $uv$ を削除する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void get(int v)`
    - 頂点 $v$ の値を取得する
    - 時間計算量: $O(1)$
- `void update(int v, T x)`
    - 頂点 $v$ の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void update(int v, int p, E x)`
    - 頂点 $p$ を $v$ の親としたときの $v$ の部分木に $x$ を作用させる
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `T fold(int v, int p)`
    - $p$ を親として，$v$ を根とする部分木上の頂点の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$

## Reference

- [プログラミングコンテストでのデータ構造 2　～動的木編～](https://www.slideshare.net/iwiwi/2-12188845)
- [Euler Tour Tree](https://kopricky.github.io/code/DataStructure_OnGraph/euler_tour_tree.html)
- [Euler Tour Trees](https://web.stanford.edu/class/archive/cs/cs166/cs166.1146/lectures/04/Small04.pdf)
- [【競技プログラミング】online dynamic connectivity(削除可能union-find)の作り方を詳しく解説！！！](https://qiita.com/hotman78/items/78cd3aa50b05a57738d4)
