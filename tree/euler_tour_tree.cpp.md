---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Euler Tour Tree
    links: []
  bundledCode: "#line 2 \"tree/euler_tour_tree.cpp\"\n#include <cassert>\n#include\
    \ <map>\n#include <memory>\n#include <utility>\n#include <vector>\n\n// TODO:\
    \ implement subtree fold in O(log n) (is it even possible?)\n// there are two\
    \ approaches that may work\n// 1: find the parent of the node, cut, fold, and\
    \ link again\n// 2: retain the first and the last occurrence of the vertex, split\
    \ and fold\n\n/*\n * @brief Euler Tour Tree\n */\ntemplate <typename M>\nclass\
    \ EulerTourTree {\n    using T = typename M::T;\n\npublic:\n    EulerTourTree()\
    \ = default;\n    explicit EulerTourTree(int n) {\n        for (int i = 0; i <\
    \ n; ++i) {\n            vertex.push_back(std::make_shared<Node>(i, i, M::id));\n\
    \        }\n    }\n\n    void link(int u, int v) {\n        reroot(u);\n     \
    \   reroot(v);\n        auto uv = std::make_shared<Node>(u, v, M::id);\n     \
    \   auto vu = std::make_shared<Node>(v, u, M::id);\n        splay(vertex[u]);\n\
    \        splay(vertex[v]);\n        join(join(vertex[u], uv), join(vertex[v],\
    \ vu));\n        edge[std::minmax(u, v)] = {uv, vu};\n    }\n\n    void cut(int\
    \ u, int v) {\n        auto p = edge[std::minmax(u, v)];\n        node_ptr a,\
    \ b, c, d;\n        std::tie(a, b) = split(p.first);\n        auto r = p.second;\n\
    \        while (r->par) r = r->par;\n        if (r == a) {\n            std::tie(c,\
    \ d) = split(p.second);\n            join(c, b->right);\n            while (d->left)\
    \ d = d->left;\n            if (d->par) d->par->left = nullptr;\n            d->par\
    \ = nullptr;\n        } else {\n            std::tie(c, d) = split(p.second);\n\
    \            join(a, d->right);\n            while (c->left) c = c->left;\n  \
    \          if (c->par) c->par->left = nullptr;\n            c->par = nullptr;\n\
    \        }\n        edge.erase(std::minmax(u, v));\n    }\n\n    void reroot(int\
    \ v) {\n        node_ptr a, b;\n        std::tie(a, b) = split(vertex[v]);\n \
    \       join(b, a);\n    }\n\n    T get(int v) const {\n        return vertex[v]->val;\n\
    \    }\n\n    void set(int v, const T& x) {\n        splay(vertex[v]);\n     \
    \   vertex[v]->val = x;\n        recalc(vertex[v]);\n    }\n\n    // T fold(int\
    \ v) {\n    //     int p = parent(v);\n    //     if (p != -1) cut(p, v);\n  \
    \  //     splay(vertex[v]);\n    //     auto ret = vertex[v]->sum;\n    //   \
    \  if (p != -1) link(p, v);\n    //     return ret;\n    // }\n\n    // int parent(int\
    \ v) {\n    //     auto t = vertex[v];\n    //     splay(t);\n    //     if (!t->left)\
    \ return -1;\n    //     t = t->left;\n    //     while (t->right) t = t->right;\n\
    \    //     return t->from == v ? t->to : t->from;\n    // }\n\n    // void print(int\
    \ v) {\n    //     auto r = vertex[v];\n    //     while (r->par) r = r->par;\n\
    \    //     print(r);\n    //     cout << endl;\n    // }\n\n    // void print2(int\
    \ v) {\n    //     auto r = vertex[v];\n    //     while (r->par) r = r->par;\n\
    \    //     print2(r, 0);\n    //     cout << endl;\n    // }\n\nprivate:\n  \
    \  struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    // void print(node_ptr\
    \ t) {\n    //     if (!t) return;\n    //     print(t->left);\n    //     cout\
    \ << \"(\" << t->from << \" \" << t->to << \") \";\n    //     print(t->right);\n\
    \    // }\n\n    // void print2(node_ptr t, int depth) {\n    //     if (!t) return;\n\
    \    //     for (int i = 0; i < depth; ++i) cout << \" \";\n    //     cout <<\
    \ \"(\" << t->from << \" \" << t->to << \")\" << t->sum << endl;\n    //     print2(t->left,\
    \ depth + 1);\n    //     for (int i = 0; i < depth; ++i) cout << \" \";\n   \
    \ //     cout << \"(\" << t->from << \" \" << t->to << \")\" << endl;\n    //\
    \     print2(t->right, depth + 1);\n    //     for (int i = 0; i < depth; ++i)\
    \ cout << \" \";\n    //     cout << \"(\" << t->from << \" \" << t->to << \"\
    )\" << endl;\n    // }\n\n    struct Node {\n        node_ptr left, right, par;\n\
    \        T val, sum;\n        int from, to, sz;\n        Node(int from, int to,\
    \ const T& x)\n            : left(nullptr), right(nullptr), par(nullptr),\n  \
    \            val(x), sum(x), from(from), to(to), sz(from == to) {}\n    };\n\n\
    \    std::vector<node_ptr> vertex;\n    std::map<std::pair<int, int>, std::pair<node_ptr,\
    \ node_ptr>> edge;\n\n    // splay tree\n\n    static int size(const node_ptr&\
    \ t) {\n        return t ? t->sz : 0;\n    }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        while (l->right) l = l->right;\n        splay(l);\n\
    \        l->right = r;\n        r->par = l;\n        recalc(l);\n        return\
    \ l;\n    }\n\n    static std::pair<node_ptr, node_ptr> split(node_ptr t) {\n\
    \        splay(t);\n        auto s = t->left;\n        t->left = nullptr;\n  \
    \      if (s) s->par = nullptr;\n        recalc(t);\n        return {s, t};\n\
    \    }\n\n    static void rotate_left(node_ptr t) {\n        node_ptr s = t->right;\n\
    \        t->right = s->left;\n        if (s->left) s->left->par = t;\n       \
    \ s->par = t->par;\n        if (t->par) {\n            if (t->par->left == t)\
    \ {\n                t->par->left = s;\n            } else {\n               \
    \ t->par->right = s;\n            }\n        }\n        s->left = t;\n       \
    \ t->par = s;\n        recalc(t);\n        recalc(s);\n    }\n\n    static void\
    \ rotate_right(node_ptr t) {\n        node_ptr s = t->left;\n        t->left =\
    \ s->right;\n        if (s->right) s->right->par = t;\n        s->par = t->par;\n\
    \        if (t->par) {\n            if (t->par->right == t) {\n              \
    \  t->par->right = s;\n            } else {\n                t->par->left = s;\n\
    \            }\n        }\n        s->right = t;\n        t->par = s;\n      \
    \  recalc(t);\n        recalc(s);\n    }\n\n    static void splay(node_ptr t)\
    \ {\n        if (!t) return;\n        while (t->par) {\n            auto p = t->par,\
    \ g = p->par;\n            if (!g) {\n                if (t == p->left) rotate_right(p);\n\
    \                else rotate_left(p);\n            } else {\n                if\
    \ (t == p->left) {\n                    if (p == g->left) {\n                \
    \        rotate_right(g);\n                        rotate_right(p);\n        \
    \            } else {\n                        rotate_right(p);\n            \
    \            rotate_left(g);\n                    }\n                } else {\n\
    \                    if (p == g->left) {\n                        rotate_left(p);\n\
    \                        rotate_right(g);\n                    } else {\n    \
    \                    rotate_left(g);\n                        rotate_left(p);\n\
    \                    }\n                }\n            }\n        }\n    }\n};\n\
    \n// using ll = long long;\n\n// struct AddMonoid {\n//     using T = ll;\n//\
    \     static constexpr T id = 0;\n//     static T op(T a, T b) {\n//         return\
    \ a + b;\n//     }\n// };\n\n// int main() {\n//     ios_base::sync_with_stdio(false);\n\
    //     cin.tie(nullptr);\n\n//     int N, Q;\n//     cin >> N >> Q;\n//     EulerTourTree<AddMonoid>\
    \ ett(N);\n//     for (int i = 0; i < N; ++i) {\n//         int a;\n//       \
    \  cin >> a;\n//         ett.set(i, a);\n//     }\n//     for (int i = 0; i <\
    \ N - 1; ++i) {\n//         int u, v;\n//         cin >> u >> v;\n//         ett.link(u,\
    \ v);\n//     }\n//     while (Q--) {\n//         int t;\n//         cin >> t;\n\
    //         if (t == 0) {\n//             int u, v, w, x;\n//             cin >>\
    \ u >> v >> w >> x;\n//             ett.cut(u, v);\n//             ett.link(w,\
    \ x);\n//         } else if (t == 1) {\n//             int p, x;\n//         \
    \    cin >> p >> x;\n//             ett.set(p, ett.get(p) + x);\n//         }\
    \ else {\n//             int v, p;\n//             cin >> v >> p;\n//        \
    \     cout << ett.fold(v) << endl;\n//         }\n//     }\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <map>\n#include <memory>\n#include\
    \ <utility>\n#include <vector>\n\n// TODO: implement subtree fold in O(log n)\
    \ (is it even possible?)\n// there are two approaches that may work\n// 1: find\
    \ the parent of the node, cut, fold, and link again\n// 2: retain the first and\
    \ the last occurrence of the vertex, split and fold\n\n/*\n * @brief Euler Tour\
    \ Tree\n */\ntemplate <typename M>\nclass EulerTourTree {\n    using T = typename\
    \ M::T;\n\npublic:\n    EulerTourTree() = default;\n    explicit EulerTourTree(int\
    \ n) {\n        for (int i = 0; i < n; ++i) {\n            vertex.push_back(std::make_shared<Node>(i,\
    \ i, M::id));\n        }\n    }\n\n    void link(int u, int v) {\n        reroot(u);\n\
    \        reroot(v);\n        auto uv = std::make_shared<Node>(u, v, M::id);\n\
    \        auto vu = std::make_shared<Node>(v, u, M::id);\n        splay(vertex[u]);\n\
    \        splay(vertex[v]);\n        join(join(vertex[u], uv), join(vertex[v],\
    \ vu));\n        edge[std::minmax(u, v)] = {uv, vu};\n    }\n\n    void cut(int\
    \ u, int v) {\n        auto p = edge[std::minmax(u, v)];\n        node_ptr a,\
    \ b, c, d;\n        std::tie(a, b) = split(p.first);\n        auto r = p.second;\n\
    \        while (r->par) r = r->par;\n        if (r == a) {\n            std::tie(c,\
    \ d) = split(p.second);\n            join(c, b->right);\n            while (d->left)\
    \ d = d->left;\n            if (d->par) d->par->left = nullptr;\n            d->par\
    \ = nullptr;\n        } else {\n            std::tie(c, d) = split(p.second);\n\
    \            join(a, d->right);\n            while (c->left) c = c->left;\n  \
    \          if (c->par) c->par->left = nullptr;\n            c->par = nullptr;\n\
    \        }\n        edge.erase(std::minmax(u, v));\n    }\n\n    void reroot(int\
    \ v) {\n        node_ptr a, b;\n        std::tie(a, b) = split(vertex[v]);\n \
    \       join(b, a);\n    }\n\n    T get(int v) const {\n        return vertex[v]->val;\n\
    \    }\n\n    void set(int v, const T& x) {\n        splay(vertex[v]);\n     \
    \   vertex[v]->val = x;\n        recalc(vertex[v]);\n    }\n\n    // T fold(int\
    \ v) {\n    //     int p = parent(v);\n    //     if (p != -1) cut(p, v);\n  \
    \  //     splay(vertex[v]);\n    //     auto ret = vertex[v]->sum;\n    //   \
    \  if (p != -1) link(p, v);\n    //     return ret;\n    // }\n\n    // int parent(int\
    \ v) {\n    //     auto t = vertex[v];\n    //     splay(t);\n    //     if (!t->left)\
    \ return -1;\n    //     t = t->left;\n    //     while (t->right) t = t->right;\n\
    \    //     return t->from == v ? t->to : t->from;\n    // }\n\n    // void print(int\
    \ v) {\n    //     auto r = vertex[v];\n    //     while (r->par) r = r->par;\n\
    \    //     print(r);\n    //     cout << endl;\n    // }\n\n    // void print2(int\
    \ v) {\n    //     auto r = vertex[v];\n    //     while (r->par) r = r->par;\n\
    \    //     print2(r, 0);\n    //     cout << endl;\n    // }\n\nprivate:\n  \
    \  struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    // void print(node_ptr\
    \ t) {\n    //     if (!t) return;\n    //     print(t->left);\n    //     cout\
    \ << \"(\" << t->from << \" \" << t->to << \") \";\n    //     print(t->right);\n\
    \    // }\n\n    // void print2(node_ptr t, int depth) {\n    //     if (!t) return;\n\
    \    //     for (int i = 0; i < depth; ++i) cout << \" \";\n    //     cout <<\
    \ \"(\" << t->from << \" \" << t->to << \")\" << t->sum << endl;\n    //     print2(t->left,\
    \ depth + 1);\n    //     for (int i = 0; i < depth; ++i) cout << \" \";\n   \
    \ //     cout << \"(\" << t->from << \" \" << t->to << \")\" << endl;\n    //\
    \     print2(t->right, depth + 1);\n    //     for (int i = 0; i < depth; ++i)\
    \ cout << \" \";\n    //     cout << \"(\" << t->from << \" \" << t->to << \"\
    )\" << endl;\n    // }\n\n    struct Node {\n        node_ptr left, right, par;\n\
    \        T val, sum;\n        int from, to, sz;\n        Node(int from, int to,\
    \ const T& x)\n            : left(nullptr), right(nullptr), par(nullptr),\n  \
    \            val(x), sum(x), from(from), to(to), sz(from == to) {}\n    };\n\n\
    \    std::vector<node_ptr> vertex;\n    std::map<std::pair<int, int>, std::pair<node_ptr,\
    \ node_ptr>> edge;\n\n    // splay tree\n\n    static int size(const node_ptr&\
    \ t) {\n        return t ? t->sz : 0;\n    }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        while (l->right) l = l->right;\n        splay(l);\n\
    \        l->right = r;\n        r->par = l;\n        recalc(l);\n        return\
    \ l;\n    }\n\n    static std::pair<node_ptr, node_ptr> split(node_ptr t) {\n\
    \        splay(t);\n        auto s = t->left;\n        t->left = nullptr;\n  \
    \      if (s) s->par = nullptr;\n        recalc(t);\n        return {s, t};\n\
    \    }\n\n    static void rotate_left(node_ptr t) {\n        node_ptr s = t->right;\n\
    \        t->right = s->left;\n        if (s->left) s->left->par = t;\n       \
    \ s->par = t->par;\n        if (t->par) {\n            if (t->par->left == t)\
    \ {\n                t->par->left = s;\n            } else {\n               \
    \ t->par->right = s;\n            }\n        }\n        s->left = t;\n       \
    \ t->par = s;\n        recalc(t);\n        recalc(s);\n    }\n\n    static void\
    \ rotate_right(node_ptr t) {\n        node_ptr s = t->left;\n        t->left =\
    \ s->right;\n        if (s->right) s->right->par = t;\n        s->par = t->par;\n\
    \        if (t->par) {\n            if (t->par->right == t) {\n              \
    \  t->par->right = s;\n            } else {\n                t->par->left = s;\n\
    \            }\n        }\n        s->right = t;\n        t->par = s;\n      \
    \  recalc(t);\n        recalc(s);\n    }\n\n    static void splay(node_ptr t)\
    \ {\n        if (!t) return;\n        while (t->par) {\n            auto p = t->par,\
    \ g = p->par;\n            if (!g) {\n                if (t == p->left) rotate_right(p);\n\
    \                else rotate_left(p);\n            } else {\n                if\
    \ (t == p->left) {\n                    if (p == g->left) {\n                \
    \        rotate_right(g);\n                        rotate_right(p);\n        \
    \            } else {\n                        rotate_right(p);\n            \
    \            rotate_left(g);\n                    }\n                } else {\n\
    \                    if (p == g->left) {\n                        rotate_left(p);\n\
    \                        rotate_right(g);\n                    } else {\n    \
    \                    rotate_left(g);\n                        rotate_left(p);\n\
    \                    }\n                }\n            }\n        }\n    }\n};\n\
    \n// using ll = long long;\n\n// struct AddMonoid {\n//     using T = ll;\n//\
    \     static constexpr T id = 0;\n//     static T op(T a, T b) {\n//         return\
    \ a + b;\n//     }\n// };\n\n// int main() {\n//     ios_base::sync_with_stdio(false);\n\
    //     cin.tie(nullptr);\n\n//     int N, Q;\n//     cin >> N >> Q;\n//     EulerTourTree<AddMonoid>\
    \ ett(N);\n//     for (int i = 0; i < N; ++i) {\n//         int a;\n//       \
    \  cin >> a;\n//         ett.set(i, a);\n//     }\n//     for (int i = 0; i <\
    \ N - 1; ++i) {\n//         int u, v;\n//         cin >> u >> v;\n//         ett.link(u,\
    \ v);\n//     }\n//     while (Q--) {\n//         int t;\n//         cin >> t;\n\
    //         if (t == 0) {\n//             int u, v, w, x;\n//             cin >>\
    \ u >> v >> w >> x;\n//             ett.cut(u, v);\n//             ett.link(w,\
    \ x);\n//         } else if (t == 1) {\n//             int p, x;\n//         \
    \    cin >> p >> x;\n//             ett.set(p, ett.get(p) + x);\n//         }\
    \ else {\n//             int v, p;\n//             cin >> v >> p;\n//        \
    \     cout << ett.fold(v) << endl;\n//         }\n//     }\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree/euler_tour_tree.cpp
  requiredBy: []
  timestamp: '2020-10-30 00:16:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/euler_tour_tree.cpp
layout: document
redirect_from:
- /library/tree/euler_tour_tree.cpp
- /library/tree/euler_tour_tree.cpp.html
title: Euler Tour Tree
---
