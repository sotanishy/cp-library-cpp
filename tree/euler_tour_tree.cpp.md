---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
    title: test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/euler_tour_tree.md
    document_title: Euler Tour Tree
    links: []
  bundledCode: "#line 2 \"tree/euler_tour_tree.cpp\"\n#include <cassert>\n#include\
    \ <memory>\n#include <unordered_map>\n#include <utility>\n#include <vector>\n\n\
    /*\n * @brief Euler Tour Tree\n * @docs docs/tree/euler_tour_tree.md\n */\ntemplate\
    \ <typename M>\nclass EulerTourTree {\n    using T = typename M::T;\n\npublic:\n\
    \    EulerTourTree() = default;\n    explicit EulerTourTree(int n) {\n       \
    \ ptr.resize(n);\n        for (int i = 0; i < n; ++i) {\n            ptr[i][i]\
    \ = std::make_shared<Node>(i, i);\n        }\n    }\n\n    void link(int u, int\
    \ v) {\n        assert(!same(u, v));\n        auto tu = reroot(get_node(u, u));\n\
    \        auto tv = reroot(get_node(v, v));\n        join(join(tu, get_node(u,\
    \ v)), join(tv, get_node(v, u)));\n    }\n\n    void cut(int u, int v) {\n   \
    \     assert(ptr[u].find(v) != ptr[u].end());\n        node_ptr a, b, c;\n   \
    \     std::tie(a, b, c) = split(get_node(u, v), get_node(v, u));\n        join(a,\
    \ c);\n        ptr[u].erase(v);\n        ptr[v].erase(u);\n    }\n\n    bool same(int\
    \ u, int v) {\n        return same(get_node(u, u), get_node(v, v));\n    }\n\n\
    \    T get(int v) {\n        return get_node(v, v)->val;\n    }\n\n    void update(int\
    \ v, const T& x) {\n        auto t = get_node(v, v);\n        splay(t);\n    \
    \    t->val = x;\n        recalc(t);\n    }\n\n    T fold(int v, int p = -1) {\n\
    \        if (p != -1) cut(p, v);\n        auto t = get_node(v, v);\n        splay(t);\n\
    \        T ret = t->sum;\n        if (p != -1) link(p, v);\n        return ret;\n\
    \    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        node_ptr ch[2] = {nullptr, nullptr};\n        node_ptr\
    \ par = nullptr;\n        int from, to, sz;\n        T val = M::id, sum = M::id;\n\
    \        Node(int from, int to) : from(from), to(to), sz(from == to) {}\n    };\n\
    \n    std::vector<std::unordered_map<int, node_ptr>> ptr;\n\n    node_ptr get_node(int\
    \ u, int v) {\n        if (ptr[u].find(v) == ptr[u].end()) ptr[u][v] = std::make_shared<Node>(u,\
    \ v);\n        return ptr[u][v];\n    }\n\n    static node_ptr root(node_ptr t)\
    \ {\n        if (!t) return nullptr;\n        while (t->par) t = t->par;\n   \
    \     return t;\n    }\n\n    static bool same(node_ptr s, node_ptr t) {\n   \
    \     if (s) splay(s);\n        if (t) splay(t);\n        return root(s) == root(t);\n\
    \    }\n\n    static node_ptr reroot(node_ptr t) {\n        auto s = split(t);\n\
    \        return join(s.second, s.first);\n    }\n\n    // splay tree\n\n    static\
    \ int size(const node_ptr& t) {\n        return t ? t->sz : 0;\n    }\n\n    static\
    \ node_ptr recalc(const node_ptr& t) {\n        if (!t) return t;\n        t->sz\
    \ = size(t->ch[0]) + (t->from == t->to) + size(t->ch[1]);\n        t->sum = t->val;\n\
    \        if (t->ch[0]) t->sum = M::op(t->ch[0]->sum, t->sum);\n        if (t->ch[1])\
    \ t->sum = M::op(t->sum, t->ch[1]->sum);\n        return t;\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        while (l->ch[1]) l = l->ch[1];\n        splay(l);\n\
    \        l->ch[1] = r;\n        r->par = l;\n        return recalc(l);\n    }\n\
    \n    static std::pair<node_ptr, node_ptr> split(node_ptr t) {\n        splay(t);\n\
    \        auto s = t->ch[0];\n        t->ch[0] = nullptr;\n        if (s) s->par\
    \ = nullptr;\n        return {s, recalc(t)};\n    }\n\n    static std::pair<node_ptr,node_ptr>\
    \ split2(node_ptr t) {\n        splay(t);\n        auto l = t->ch[0];\n      \
    \  auto r = t->ch[1];\n        t->ch[0] = nullptr;\n        if (l) l->par = nullptr;\n\
    \        t->ch[1] = nullptr;\n        if (r) r->par = nullptr;\n        return\
    \ {l, r};\n    }\n\n    static std::tuple<node_ptr, node_ptr, node_ptr> split(node_ptr\
    \ s, node_ptr t) {\n        node_ptr a, b, c, d;\n        std::tie(a, b) = split2(s);\n\
    \        if (same(a, t)) {\n            std::tie(c, d) = split2(t);\n        \
    \    return {c, d, b};\n        } else {\n            std::tie(c, d) = split2(t);\n\
    \            return {a, c, d};\n        }\n    }\n\n    static void rotate(node_ptr\
    \ t, bool b) {\n        node_ptr s = t->ch[1 - b], p = t->par;\n        t->ch[1\
    \ - b] = s->ch[b];\n        if (t->ch[1 - b]) t->ch[1 - b]->par = t;\n       \
    \ s->ch[b] = t;\n        t->par = s;\n        recalc(t);\n        recalc(s);\n\
    \        s->par = p;\n        if (p) {\n            if (p->ch[0] == t) p->ch[0]\
    \ = s;\n            else p->ch[1] = s;\n        }\n    }\n\n    static void splay(node_ptr\
    \ t) {\n        if (!t) return;\n        while (t->par) {\n            auto p\
    \ = t->par, g = p->par;\n            if (!g) {\n                rotate(p, t ==\
    \ p->ch[0]);\n            } else {\n                if (t == p->ch[0]) {\n   \
    \                 if (p == g->ch[0]) {\n                        rotate(g, 1);\n\
    \                        rotate(p, 1);\n                    } else {\n       \
    \                 rotate(p, 1);\n                        rotate(g, 0);\n     \
    \               }\n                } else {\n                    if (p == g->ch[0])\
    \ {\n                        rotate(p, 0);\n                        rotate(g,\
    \ 1);\n                    } else {\n                        rotate(g, 0);\n \
    \                       rotate(p, 0);\n                    }\n               \
    \ }\n            }\n        }\n    }\n};\n\n/*\ntemplate <typename M>\nclass EulerTourTree\
    \ {\n    using T = typename M::T;\n\npublic:\n    EulerTourTree() = default;\n\
    \    explicit EulerTourTree(int n) {\n        for (int i = 0; i < n; ++i) {\n\
    \            vertex.push_back(std::make_shared<Node>(i, i, M::id));\n        }\n\
    \    }\n\n    void link(int u, int v) {\n        reroot(u);\n        reroot(v);\n\
    \        auto uv = std::make_shared<Node>(u, v, M::id);\n        auto vu = std::make_shared<Node>(v,\
    \ u, M::id);\n        splay(vertex[u]);\n        splay(vertex[v]);\n        join(join(vertex[u],\
    \ uv), join(vertex[v], vu));\n        edge[std::minmax(u, v)] = {uv, vu};\n  \
    \  }\n\n    void cut(int u, int v) {\n        auto p = edge[std::minmax(u, v)];\n\
    \        node_ptr a, b, c, d;\n        std::tie(a, b) = split(p.first);\n    \
    \    auto r = p.second;\n        while (r->par) r = r->par;\n        if (r ==\
    \ a) {\n            std::tie(c, d) = split(p.second);\n            join(c, b->right);\n\
    \            while (d->left) d = d->left;\n            if (d->par) d->par->left\
    \ = nullptr;\n            d->par = nullptr;\n        } else {\n            std::tie(c,\
    \ d) = split(p.second);\n            join(a, d->right);\n            while (c->left)\
    \ c = c->left;\n            if (c->par) c->par->left = nullptr;\n            c->par\
    \ = nullptr;\n        }\n        edge.erase(std::minmax(u, v));\n    }\n\n   \
    \ void reroot(int v) {\n        node_ptr a, b;\n        std::tie(a, b) = split(vertex[v]);\n\
    \        join(b, a);\n    }\n\n    T get(int v) const {\n        return vertex[v]->val;\n\
    \    }\n\n    void set(int v, const T& x) {\n        splay(vertex[v]);\n     \
    \   vertex[v]->val = x;\n        recalc(vertex[v]);\n    }\n\n    T fold(int v,\
    \ int p) {\n        if (p == -1) {\n            splay(vertex[v]);\n          \
    \  return vertex[v]->sum;\n        }\n        auto e = edge[std::minmax(v, p)];\n\
    \        node_ptr a, b, c, d;\n        std::tie(a, b) = split(e.first);\n    \
    \    auto r = e.second;\n        while (r->par) r = r->par;\n        T ret;\n\
    \        if (r == a) {\n            std::tie(c, d) = split(e.second);\n      \
    \      ret = d->sum;\n            join(join(c, d), b);\n        } else {\n   \
    \         std::tie(c, d) = split(e.second);\n            ret = c->sum;\n     \
    \       join(a, join(c, d));\n        }\n        return ret;\n    }\n\n    //\
    \ void print(int v) {\n    //     auto r = vertex[v];\n    //     while (r->par)\
    \ r = r->par;\n    //     print(r);\n    //     cout << endl;\n    // }\n\n  \
    \  // void print2(int v) {\n    //     auto r = vertex[v];\n    //     while (r->par)\
    \ r = r->par;\n    //     print2(r, 0);\n    //     cout << endl;\n    // }\n\n\
    private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n  \
    \  // void print(node_ptr t) {\n    //     if (!t) return;\n    //     print(t->left);\n\
    \    //     cout << \"(\" << t->from << \" \" << t->to << \") \";\n    //    \
    \ print(t->right);\n    // }\n\n    // void print2(node_ptr t, int depth) {\n\
    \    //     if (!t) return;\n    //     for (int i = 0; i < depth; ++i) cout <<\
    \ \" \";\n    //     cout << \"(\" << t->from << \" \" << t->to << \")\" << t->sum\
    \ << endl;\n    //     print2(t->left, depth + 1);\n    //     for (int i = 0;\
    \ i < depth; ++i) cout << \" \";\n    //     cout << \"(\" << t->from << \" \"\
    \ << t->to << \")\" << endl;\n    //     print2(t->right, depth + 1);\n    //\
    \     for (int i = 0; i < depth; ++i) cout << \" \";\n    //     cout << \"(\"\
    \ << t->from << \" \" << t->to << \")\" << endl;\n    // }\n\n    struct Node\
    \ {\n        node_ptr left, right, par;\n        T val, sum;\n        int from,\
    \ to, sz;\n        Node(int from, int to, const T& x)\n            : left(nullptr),\
    \ right(nullptr), par(nullptr),\n              val(x), sum(x), from(from), to(to),\
    \ sz(from == to) {}\n    };\n\n    std::vector<node_ptr> vertex;\n    std::map<std::pair<int,\
    \ int>, std::pair<node_ptr, node_ptr>> edge;\n\n    // splay tree\n\n    static\
    \ int size(const node_ptr& t) {\n        return t ? t->sz : 0;\n    }\n\n    static\
    \ void recalc(const node_ptr& t) {\n        if (!t) return;\n        t->sz = size(t->left)\
    \ + 1 + size(t->right);\n        t->sum = t->val;\n        if (t->left) t->sum\
    \ = M::op(t->left->sum, t->sum);\n        if (t->right) t->sum = M::op(t->sum,\
    \ t->right->sum);\n    }\n\n    static node_ptr join(node_ptr l, node_ptr r) {\n\
    \        if (!l) return r;\n        if (!r) return l;\n        while (l->right)\
    \ l = l->right;\n        splay(l);\n        l->right = r;\n        r->par = l;\n\
    \        recalc(l);\n        return l;\n    }\n\n    static std::pair<node_ptr,\
    \ node_ptr> split(node_ptr t) {\n        splay(t);\n        auto s = t->left;\n\
    \        t->left = nullptr;\n        if (s) s->par = nullptr;\n        recalc(t);\n\
    \        return {s, t};\n    }\n\n    static void rotate_left(node_ptr t) {\n\
    \        node_ptr s = t->right;\n        t->right = s->left;\n        if (s->left)\
    \ s->left->par = t;\n        s->par = t->par;\n        if (t->par) {\n       \
    \     if (t->par->left == t) {\n                t->par->left = s;\n          \
    \  } else {\n                t->par->right = s;\n            }\n        }\n  \
    \      s->left = t;\n        t->par = s;\n        recalc(t);\n        recalc(s);\n\
    \    }\n\n    static void rotate_right(node_ptr t) {\n        node_ptr s = t->left;\n\
    \        t->left = s->right;\n        if (s->right) s->right->par = t;\n     \
    \   s->par = t->par;\n        if (t->par) {\n            if (t->par->right ==\
    \ t) {\n                t->par->right = s;\n            } else {\n           \
    \     t->par->left = s;\n            }\n        }\n        s->right = t;\n   \
    \     t->par = s;\n        recalc(t);\n        recalc(s);\n    }\n\n    static\
    \ void splay(node_ptr t) {\n        if (!t) return;\n        while (t->par) {\n\
    \            auto p = t->par, g = p->par;\n            if (!g) {\n           \
    \     if (t == p->left) rotate_right(p);\n                else rotate_left(p);\n\
    \            } else {\n                if (t == p->left) {\n                 \
    \   if (p == g->left) {\n                        rotate_right(g);\n          \
    \              rotate_right(p);\n                    } else {\n              \
    \          rotate_right(p);\n                        rotate_left(g);\n       \
    \             }\n                } else {\n                    if (p == g->left)\
    \ {\n                        rotate_left(p);\n                        rotate_right(g);\n\
    \                    } else {\n                        rotate_left(g);\n     \
    \                   rotate_left(p);\n                    }\n                }\n\
    \            }\n        }\n    }\n};\n*/\n"
  code: "#pragma once\n#include <cassert>\n#include <memory>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n\n/*\n * @brief Euler Tour Tree\n * @docs\
    \ docs/tree/euler_tour_tree.md\n */\ntemplate <typename M>\nclass EulerTourTree\
    \ {\n    using T = typename M::T;\n\npublic:\n    EulerTourTree() = default;\n\
    \    explicit EulerTourTree(int n) {\n        ptr.resize(n);\n        for (int\
    \ i = 0; i < n; ++i) {\n            ptr[i][i] = std::make_shared<Node>(i, i);\n\
    \        }\n    }\n\n    void link(int u, int v) {\n        assert(!same(u, v));\n\
    \        auto tu = reroot(get_node(u, u));\n        auto tv = reroot(get_node(v,\
    \ v));\n        join(join(tu, get_node(u, v)), join(tv, get_node(v, u)));\n  \
    \  }\n\n    void cut(int u, int v) {\n        assert(ptr[u].find(v) != ptr[u].end());\n\
    \        node_ptr a, b, c;\n        std::tie(a, b, c) = split(get_node(u, v),\
    \ get_node(v, u));\n        join(a, c);\n        ptr[u].erase(v);\n        ptr[v].erase(u);\n\
    \    }\n\n    bool same(int u, int v) {\n        return same(get_node(u, u), get_node(v,\
    \ v));\n    }\n\n    T get(int v) {\n        return get_node(v, v)->val;\n   \
    \ }\n\n    void update(int v, const T& x) {\n        auto t = get_node(v, v);\n\
    \        splay(t);\n        t->val = x;\n        recalc(t);\n    }\n\n    T fold(int\
    \ v, int p = -1) {\n        if (p != -1) cut(p, v);\n        auto t = get_node(v,\
    \ v);\n        splay(t);\n        T ret = t->sum;\n        if (p != -1) link(p,\
    \ v);\n        return ret;\n    }\n\nprivate:\n    struct Node;\n    using node_ptr\
    \ = std::shared_ptr<Node>;\n\n    struct Node {\n        node_ptr ch[2] = {nullptr,\
    \ nullptr};\n        node_ptr par = nullptr;\n        int from, to, sz;\n    \
    \    T val = M::id, sum = M::id;\n        Node(int from, int to) : from(from),\
    \ to(to), sz(from == to) {}\n    };\n\n    std::vector<std::unordered_map<int,\
    \ node_ptr>> ptr;\n\n    node_ptr get_node(int u, int v) {\n        if (ptr[u].find(v)\
    \ == ptr[u].end()) ptr[u][v] = std::make_shared<Node>(u, v);\n        return ptr[u][v];\n\
    \    }\n\n    static node_ptr root(node_ptr t) {\n        if (!t) return nullptr;\n\
    \        while (t->par) t = t->par;\n        return t;\n    }\n\n    static bool\
    \ same(node_ptr s, node_ptr t) {\n        if (s) splay(s);\n        if (t) splay(t);\n\
    \        return root(s) == root(t);\n    }\n\n    static node_ptr reroot(node_ptr\
    \ t) {\n        auto s = split(t);\n        return join(s.second, s.first);\n\
    \    }\n\n    // splay tree\n\n    static int size(const node_ptr& t) {\n    \
    \    return t ? t->sz : 0;\n    }\n\n    static node_ptr recalc(const node_ptr&\
    \ t) {\n        if (!t) return t;\n        t->sz = size(t->ch[0]) + (t->from ==\
    \ t->to) + size(t->ch[1]);\n        t->sum = t->val;\n        if (t->ch[0]) t->sum\
    \ = M::op(t->ch[0]->sum, t->sum);\n        if (t->ch[1]) t->sum = M::op(t->sum,\
    \ t->ch[1]->sum);\n        return t;\n    }\n\n    static node_ptr join(node_ptr\
    \ l, node_ptr r) {\n        if (!l) return r;\n        if (!r) return l;\n   \
    \     while (l->ch[1]) l = l->ch[1];\n        splay(l);\n        l->ch[1] = r;\n\
    \        r->par = l;\n        return recalc(l);\n    }\n\n    static std::pair<node_ptr,\
    \ node_ptr> split(node_ptr t) {\n        splay(t);\n        auto s = t->ch[0];\n\
    \        t->ch[0] = nullptr;\n        if (s) s->par = nullptr;\n        return\
    \ {s, recalc(t)};\n    }\n\n    static std::pair<node_ptr,node_ptr> split2(node_ptr\
    \ t) {\n        splay(t);\n        auto l = t->ch[0];\n        auto r = t->ch[1];\n\
    \        t->ch[0] = nullptr;\n        if (l) l->par = nullptr;\n        t->ch[1]\
    \ = nullptr;\n        if (r) r->par = nullptr;\n        return {l, r};\n    }\n\
    \n    static std::tuple<node_ptr, node_ptr, node_ptr> split(node_ptr s, node_ptr\
    \ t) {\n        node_ptr a, b, c, d;\n        std::tie(a, b) = split2(s);\n  \
    \      if (same(a, t)) {\n            std::tie(c, d) = split2(t);\n          \
    \  return {c, d, b};\n        } else {\n            std::tie(c, d) = split2(t);\n\
    \            return {a, c, d};\n        }\n    }\n\n    static void rotate(node_ptr\
    \ t, bool b) {\n        node_ptr s = t->ch[1 - b], p = t->par;\n        t->ch[1\
    \ - b] = s->ch[b];\n        if (t->ch[1 - b]) t->ch[1 - b]->par = t;\n       \
    \ s->ch[b] = t;\n        t->par = s;\n        recalc(t);\n        recalc(s);\n\
    \        s->par = p;\n        if (p) {\n            if (p->ch[0] == t) p->ch[0]\
    \ = s;\n            else p->ch[1] = s;\n        }\n    }\n\n    static void splay(node_ptr\
    \ t) {\n        if (!t) return;\n        while (t->par) {\n            auto p\
    \ = t->par, g = p->par;\n            if (!g) {\n                rotate(p, t ==\
    \ p->ch[0]);\n            } else {\n                if (t == p->ch[0]) {\n   \
    \                 if (p == g->ch[0]) {\n                        rotate(g, 1);\n\
    \                        rotate(p, 1);\n                    } else {\n       \
    \                 rotate(p, 1);\n                        rotate(g, 0);\n     \
    \               }\n                } else {\n                    if (p == g->ch[0])\
    \ {\n                        rotate(p, 0);\n                        rotate(g,\
    \ 1);\n                    } else {\n                        rotate(g, 0);\n \
    \                       rotate(p, 0);\n                    }\n               \
    \ }\n            }\n        }\n    }\n};\n\n/*\ntemplate <typename M>\nclass EulerTourTree\
    \ {\n    using T = typename M::T;\n\npublic:\n    EulerTourTree() = default;\n\
    \    explicit EulerTourTree(int n) {\n        for (int i = 0; i < n; ++i) {\n\
    \            vertex.push_back(std::make_shared<Node>(i, i, M::id));\n        }\n\
    \    }\n\n    void link(int u, int v) {\n        reroot(u);\n        reroot(v);\n\
    \        auto uv = std::make_shared<Node>(u, v, M::id);\n        auto vu = std::make_shared<Node>(v,\
    \ u, M::id);\n        splay(vertex[u]);\n        splay(vertex[v]);\n        join(join(vertex[u],\
    \ uv), join(vertex[v], vu));\n        edge[std::minmax(u, v)] = {uv, vu};\n  \
    \  }\n\n    void cut(int u, int v) {\n        auto p = edge[std::minmax(u, v)];\n\
    \        node_ptr a, b, c, d;\n        std::tie(a, b) = split(p.first);\n    \
    \    auto r = p.second;\n        while (r->par) r = r->par;\n        if (r ==\
    \ a) {\n            std::tie(c, d) = split(p.second);\n            join(c, b->right);\n\
    \            while (d->left) d = d->left;\n            if (d->par) d->par->left\
    \ = nullptr;\n            d->par = nullptr;\n        } else {\n            std::tie(c,\
    \ d) = split(p.second);\n            join(a, d->right);\n            while (c->left)\
    \ c = c->left;\n            if (c->par) c->par->left = nullptr;\n            c->par\
    \ = nullptr;\n        }\n        edge.erase(std::minmax(u, v));\n    }\n\n   \
    \ void reroot(int v) {\n        node_ptr a, b;\n        std::tie(a, b) = split(vertex[v]);\n\
    \        join(b, a);\n    }\n\n    T get(int v) const {\n        return vertex[v]->val;\n\
    \    }\n\n    void set(int v, const T& x) {\n        splay(vertex[v]);\n     \
    \   vertex[v]->val = x;\n        recalc(vertex[v]);\n    }\n\n    T fold(int v,\
    \ int p) {\n        if (p == -1) {\n            splay(vertex[v]);\n          \
    \  return vertex[v]->sum;\n        }\n        auto e = edge[std::minmax(v, p)];\n\
    \        node_ptr a, b, c, d;\n        std::tie(a, b) = split(e.first);\n    \
    \    auto r = e.second;\n        while (r->par) r = r->par;\n        T ret;\n\
    \        if (r == a) {\n            std::tie(c, d) = split(e.second);\n      \
    \      ret = d->sum;\n            join(join(c, d), b);\n        } else {\n   \
    \         std::tie(c, d) = split(e.second);\n            ret = c->sum;\n     \
    \       join(a, join(c, d));\n        }\n        return ret;\n    }\n\n    //\
    \ void print(int v) {\n    //     auto r = vertex[v];\n    //     while (r->par)\
    \ r = r->par;\n    //     print(r);\n    //     cout << endl;\n    // }\n\n  \
    \  // void print2(int v) {\n    //     auto r = vertex[v];\n    //     while (r->par)\
    \ r = r->par;\n    //     print2(r, 0);\n    //     cout << endl;\n    // }\n\n\
    private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n  \
    \  // void print(node_ptr t) {\n    //     if (!t) return;\n    //     print(t->left);\n\
    \    //     cout << \"(\" << t->from << \" \" << t->to << \") \";\n    //    \
    \ print(t->right);\n    // }\n\n    // void print2(node_ptr t, int depth) {\n\
    \    //     if (!t) return;\n    //     for (int i = 0; i < depth; ++i) cout <<\
    \ \" \";\n    //     cout << \"(\" << t->from << \" \" << t->to << \")\" << t->sum\
    \ << endl;\n    //     print2(t->left, depth + 1);\n    //     for (int i = 0;\
    \ i < depth; ++i) cout << \" \";\n    //     cout << \"(\" << t->from << \" \"\
    \ << t->to << \")\" << endl;\n    //     print2(t->right, depth + 1);\n    //\
    \     for (int i = 0; i < depth; ++i) cout << \" \";\n    //     cout << \"(\"\
    \ << t->from << \" \" << t->to << \")\" << endl;\n    // }\n\n    struct Node\
    \ {\n        node_ptr left, right, par;\n        T val, sum;\n        int from,\
    \ to, sz;\n        Node(int from, int to, const T& x)\n            : left(nullptr),\
    \ right(nullptr), par(nullptr),\n              val(x), sum(x), from(from), to(to),\
    \ sz(from == to) {}\n    };\n\n    std::vector<node_ptr> vertex;\n    std::map<std::pair<int,\
    \ int>, std::pair<node_ptr, node_ptr>> edge;\n\n    // splay tree\n\n    static\
    \ int size(const node_ptr& t) {\n        return t ? t->sz : 0;\n    }\n\n    static\
    \ void recalc(const node_ptr& t) {\n        if (!t) return;\n        t->sz = size(t->left)\
    \ + 1 + size(t->right);\n        t->sum = t->val;\n        if (t->left) t->sum\
    \ = M::op(t->left->sum, t->sum);\n        if (t->right) t->sum = M::op(t->sum,\
    \ t->right->sum);\n    }\n\n    static node_ptr join(node_ptr l, node_ptr r) {\n\
    \        if (!l) return r;\n        if (!r) return l;\n        while (l->right)\
    \ l = l->right;\n        splay(l);\n        l->right = r;\n        r->par = l;\n\
    \        recalc(l);\n        return l;\n    }\n\n    static std::pair<node_ptr,\
    \ node_ptr> split(node_ptr t) {\n        splay(t);\n        auto s = t->left;\n\
    \        t->left = nullptr;\n        if (s) s->par = nullptr;\n        recalc(t);\n\
    \        return {s, t};\n    }\n\n    static void rotate_left(node_ptr t) {\n\
    \        node_ptr s = t->right;\n        t->right = s->left;\n        if (s->left)\
    \ s->left->par = t;\n        s->par = t->par;\n        if (t->par) {\n       \
    \     if (t->par->left == t) {\n                t->par->left = s;\n          \
    \  } else {\n                t->par->right = s;\n            }\n        }\n  \
    \      s->left = t;\n        t->par = s;\n        recalc(t);\n        recalc(s);\n\
    \    }\n\n    static void rotate_right(node_ptr t) {\n        node_ptr s = t->left;\n\
    \        t->left = s->right;\n        if (s->right) s->right->par = t;\n     \
    \   s->par = t->par;\n        if (t->par) {\n            if (t->par->right ==\
    \ t) {\n                t->par->right = s;\n            } else {\n           \
    \     t->par->left = s;\n            }\n        }\n        s->right = t;\n   \
    \     t->par = s;\n        recalc(t);\n        recalc(s);\n    }\n\n    static\
    \ void splay(node_ptr t) {\n        if (!t) return;\n        while (t->par) {\n\
    \            auto p = t->par, g = p->par;\n            if (!g) {\n           \
    \     if (t == p->left) rotate_right(p);\n                else rotate_left(p);\n\
    \            } else {\n                if (t == p->left) {\n                 \
    \   if (p == g->left) {\n                        rotate_right(g);\n          \
    \              rotate_right(p);\n                    } else {\n              \
    \          rotate_right(p);\n                        rotate_left(g);\n       \
    \             }\n                } else {\n                    if (p == g->left)\
    \ {\n                        rotate_left(p);\n                        rotate_right(g);\n\
    \                    } else {\n                        rotate_left(g);\n     \
    \                   rotate_left(p);\n                    }\n                }\n\
    \            }\n        }\n    }\n};\n*/"
  dependsOn: []
  isVerificationFile: false
  path: tree/euler_tour_tree.cpp
  requiredBy: []
  timestamp: '2020-11-11 19:45:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp
documentation_of: tree/euler_tour_tree.cpp
layout: document
redirect_from:
- /library/tree/euler_tour_tree.cpp
- /library/tree/euler_tour_tree.cpp.html
title: Euler Tour Tree
---
## Description

Euler tour 木は，森を管理するデータ構造である．以下の機能を提供する:
- 辺の追加
- 辺の削除
- 頂点の値の更新
- 部分木の頂点の値 (可換モノイド) の総和

オイラーツアーを平衡二分探索木で管理することでこれらの操作を実現する．

空間計算量: $O(n)$

## Operations

- `EulerTourTree(int n)`
    - 頂点数 $n$ の森を構築する
    - 時間計算量: $O(n)$
- `void link(int u, int v)`
    - 辺 $uv$ を追加する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void cut(int u, int v)`
    - 辺 $uv$
    - 木 $v$ を親から切る
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void get(int v)`
    - $v$ の値を取得する
    - 時間計算量: $O(1)$
- `void update(int v, T x)`
    - 頂点 $v$ の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `T fold(int v, int p)`
    - $p$ を親として，$v$ を根とする部分木上の頂点の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$

## Reference

- [プログラミングコンテストでのデータ構造 2　～動的木編～](https://www.slideshare.net/iwiwi/2-12188845)
- [Euler Tour Tree](https://kopricky.github.io/code/DataStructure_OnGraph/euler_tour_tree.html)
- [Euler Tour Trees](https://web.stanford.edu/class/archive/cs/cs166/cs166.1146/lectures/04/Small04.pdf)
- [【競技プログラミング】online dynamic connectivity(削除可能union-find)の作り方を詳しく解説！！！](https://qiita.com/hotman78/items/78cd3aa50b05a57738d4)

## TODO

- 遅延伝搬
- online dynamic connectivity