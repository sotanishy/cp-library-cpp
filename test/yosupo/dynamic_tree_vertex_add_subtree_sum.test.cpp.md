---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/euler_tour_tree.hpp
    title: Euler Tour Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#line 7 \"tree/euler_tour_tree.hpp\"\n\ntemplate\
    \ <typename M, typename O,\n          typename M::T (*act)(typename M::T, typename\
    \ O::T)>\nclass EulerTourTree {\n    using T = M::T;\n    using E = O::T;\n\n\
    \   public:\n    EulerTourTree() = default;\n    explicit EulerTourTree(int n)\
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
    \ b);\n                }\n            }\n        }\n    }\n};\n#line 7 \"test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nstruct AddMonoid {\n    using\
    \ T = ll;\n    static T id() { return 0; }\n    static T op(T a, T b) { return\
    \ a + b; }\n};\n\nll act(ll a, ll b) { return a + b; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    EulerTourTree<AddMonoid,\
    \ AddMonoid, act> ett(N);\n    for (int i = 0; i < N; ++i) {\n        int a;\n\
    \        cin >> a;\n        ett.update(i, a);\n    }\n    for (int i = 0; i <\
    \ N - 1; ++i) {\n        int u, v;\n        cin >> u >> v;\n        ett.link(u,\
    \ v);\n    }\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int u, v, w, x;\n            cin >> u >> v >> w >> x;\n\
    \            ett.cut(u, v);\n            ett.link(w, x);\n        } else if (t\
    \ == 1) {\n            int p, x;\n            cin >> p >> x;\n            ett.update(p,\
    \ ett.get(p) + x);\n        } else {\n            int v, p;\n            cin >>\
    \ v >> p;\n            cout << ett.fold(v, p) << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../tree/euler_tour_tree.hpp\"\n\
    using namespace std;\nusing ll = long long;\n\nstruct AddMonoid {\n    using T\
    \ = ll;\n    static T id() { return 0; }\n    static T op(T a, T b) { return a\
    \ + b; }\n};\n\nll act(ll a, ll b) { return a + b; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    EulerTourTree<AddMonoid,\
    \ AddMonoid, act> ett(N);\n    for (int i = 0; i < N; ++i) {\n        int a;\n\
    \        cin >> a;\n        ett.update(i, a);\n    }\n    for (int i = 0; i <\
    \ N - 1; ++i) {\n        int u, v;\n        cin >> u >> v;\n        ett.link(u,\
    \ v);\n    }\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int u, v, w, x;\n            cin >> u >> v >> w >> x;\n\
    \            ett.cut(u, v);\n            ett.link(w, x);\n        } else if (t\
    \ == 1) {\n            int p, x;\n            cin >> p >> x;\n            ett.update(p,\
    \ ett.get(p) + x);\n        } else {\n            int v, p;\n            cin >>\
    \ v >> p;\n            cout << ett.fold(v, p) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - tree/euler_tour_tree.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 01:08:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
---
