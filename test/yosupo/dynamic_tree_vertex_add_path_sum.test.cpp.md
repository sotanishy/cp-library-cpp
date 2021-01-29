---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/link_cut_tree.cpp
    title: Link/Cut Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#line 2 \"tree/link_cut_tree.cpp\"\n#include <algorithm>\n#include <memory>\n\
    #include <vector>\n\ntemplate <typename M, typename M::T (*flip)(typename M::T)>\n\
    class LinkCutTree {\n    using T = typename M::T;\n\npublic:\n    LinkCutTree()\
    \ = default;\n    explicit LinkCutTree(int n) {\n        for (int i = 0; i < n;\
    \ ++i) {\n            vertex.push_back(std::make_shared<Node>(M::id));\n     \
    \   }\n    }\n\n    void link(int v, int p) {\n        evert(v);\n        expose(vertex[p]);\n\
    \        vertex[v]->par = vertex[p];\n        vertex[p]->right = vertex[v];\n\
    \        recalc(vertex[p]);\n    }\n\n    void cut(int v) {\n        expose(vertex[v]);\n\
    \        auto p = vertex[v]->left;\n        vertex[v]->left = p->par = nullptr;\n\
    \        recalc(vertex[v]);\n    }\n\n    void evert(int v) {\n        expose(vertex[v]);\n\
    \        reverse(vertex[v]);\n    }\n\n    T get(int v) const {\n        return\
    \ vertex[v]->val;\n    }\n\n    void set(int v, const T& x) {\n        expose(vertex[v]);\n\
    \        vertex[v]->val = x;\n        recalc(vertex[v]);\n    }\n\n    T fold(int\
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
    \    }\n            }\n        }\n    }\n};\n#line 4 \"test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    struct AddMonoid {\n    using T = ll;\n    static constexpr T id = 0;\n    static\
    \ T op(T a, T b) {\n        return a + b;\n    }\n};\n\nll flip(ll a) { return\
    \ a; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    LinkCutTree<AddMonoid, flip> lct(N);\n\
    \    for (int i = 0; i < N; ++i) {\n        int a;\n        cin >> a;\n      \
    \  lct.set(i, a);\n    }\n    for (int i = 0; i < N - 1; ++i) {\n        int u,\
    \ v;\n        cin >> u >> v;\n        lct.link(u, v);\n    }\n    for (int i =\
    \ 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n\
    \            int u, v, w, x;\n            cin >> u >> v >> w >> x;\n         \
    \   lct.evert(u);\n            lct.cut(v);\n            lct.link(w, x);\n    \
    \    } else if (t == 1) {\n            int p, x;\n            cin >> p >> x;\n\
    \            lct.set(p, lct.get(p) + x);\n        } else {\n            int u,\
    \ v;\n            cin >> u >> v;\n            cout << lct.fold(u, v) << \"\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include \"../../tree/link_cut_tree.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing ll = long long;\n\nstruct AddMonoid {\n    using T =\
    \ ll;\n    static constexpr T id = 0;\n    static T op(T a, T b) {\n        return\
    \ a + b;\n    }\n};\n\nll flip(ll a) { return a; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    LinkCutTree<AddMonoid,\
    \ flip> lct(N);\n    for (int i = 0; i < N; ++i) {\n        int a;\n        cin\
    \ >> a;\n        lct.set(i, a);\n    }\n    for (int i = 0; i < N - 1; ++i) {\n\
    \        int u, v;\n        cin >> u >> v;\n        lct.link(u, v);\n    }\n \
    \   for (int i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n       \
    \ if (t == 0) {\n            int u, v, w, x;\n            cin >> u >> v >> w >>\
    \ x;\n            lct.evert(u);\n            lct.cut(v);\n            lct.link(w,\
    \ x);\n        } else if (t == 1) {\n            int p, x;\n            cin >>\
    \ p >> x;\n            lct.set(p, lct.get(p) + x);\n        } else {\n       \
    \     int u, v;\n            cin >> u >> v;\n            cout << lct.fold(u, v)\
    \ << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - tree/link_cut_tree.cpp
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 17:56:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp
---
