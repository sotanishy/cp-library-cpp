---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: Mod int
  - icon: ':heavy_check_mark:'
    path: tree/link_cut_tree.hpp
    title: tree/link_cut_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n\n#include <bits/stdc++.h>\n\n#line 4 \"math/modint.hpp\"\n\n/**\n * @brief\
    \ Mod int\n */\ntemplate <int m>\nclass Modint {\n    using mint = Modint;\n \
    \   static_assert(m > 0, \"Modulus must be positive\");\n\n   public:\n    static\
    \ constexpr int mod() { return m; }\n\n    constexpr Modint(long long y = 0) :\
    \ x(y >= 0 ? y % m : (y % m + m) % m) {}\n\n    constexpr int val() const { return\
    \ x; }\n\n    constexpr mint& operator+=(const mint& r) {\n        if ((x += r.x)\
    \ >= m) x -= m;\n        return *this;\n    }\n    constexpr mint& operator-=(const\
    \ mint& r) {\n        if ((x += m - r.x) >= m) x -= m;\n        return *this;\n\
    \    }\n    constexpr mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL\
    \ * x * r.x % m);\n        return *this;\n    }\n    constexpr mint& operator/=(const\
    \ mint& r) { return *this *= r.inv(); }\n\n    constexpr bool operator==(const\
    \ mint& r) const { return x == r.x; }\n\n    constexpr mint operator+() const\
    \ { return *this; }\n    constexpr mint operator-() const { return mint(-x); }\n\
    \n    constexpr friend mint operator+(const mint& l, const mint& r) {\n      \
    \  return mint(l) += r;\n    }\n    constexpr friend mint operator-(const mint&\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(const mint& l, const mint& r) {\n        return mint(l) *= r;\n\
    \    }\n    constexpr friend mint operator/(const mint& l, const mint& r) {\n\
    \        return mint(l) /= r;\n    }\n\n    constexpr mint inv() const {\n   \
    \     int a = x, b = m, u = 1, v = 0;\n        while (b > 0) {\n            int\
    \ t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u -=\
    \ t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const {\n        mint ret(1), mul(x);\n        while (n > 0)\
    \ {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\n   private:\n    int x;\n};\n#line 5 \"tree/link_cut_tree.hpp\"\n\n\
    template <typename M, typename M::T (*flip)(typename M::T)>\nclass LinkCutTree\
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
    \            }\n        }\n    }\n};\n#line 8 \"test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nstruct AffineMonoid\
    \ {\n    using T = pair<pair<mint, mint>, pair<mint, mint>>;\n    static constexpr\
    \ T id = {{1, 0}, {1, 0}};\n    static T op(T a, T b) {\n        return {\n  \
    \          {a.first.first * b.first.first,\n             a.first.second * b.first.first\
    \ + b.first.second},\n            {b.second.first * a.second.first,\n        \
    \     b.second.second * a.second.first + a.second.second},\n        };\n    }\n\
    };\n\nAffineMonoid::T flip(AffineMonoid::T a) {\n    swap(a.first, a.second);\n\
    \    return a;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n   \
    \ cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    LinkCutTree<AffineMonoid,\
    \ flip> lct(N);\n    for (int i = 0; i < N; ++i) {\n        int a, b;\n      \
    \  cin >> a >> b;\n        lct.set(i, {{a, b}, {a, b}});\n    }\n    for (int\
    \ i = 0; i < N - 1; ++i) {\n        int u, v;\n        cin >> u >> v;\n      \
    \  lct.link(u, v);\n    }\n    for (int i = 0; i < Q; ++i) {\n        int t;\n\
    \        cin >> t;\n        if (t == 0) {\n            int u, v, w, x;\n     \
    \       cin >> u >> v >> w >> x;\n            lct.evert(u);\n            lct.cut(v);\n\
    \            lct.link(w, x);\n        } else if (t == 1) {\n            int p,\
    \ c, d;\n            cin >> p >> c >> d;\n            lct.set(p, {{c, d}, {c,\
    \ d}});\n        } else {\n            int u, v, x;\n            cin >> u >> v\
    \ >> x;\n            auto f = lct.fold(u, v);\n            cout << f.first.first\
    \ * x + f.first.second << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/modint.hpp\"\n#include \"\
    ../../tree/link_cut_tree.hpp\"\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct AffineMonoid {\n    using T = pair<pair<mint, mint>, pair<mint, mint>>;\n\
    \    static constexpr T id = {{1, 0}, {1, 0}};\n    static T op(T a, T b) {\n\
    \        return {\n            {a.first.first * b.first.first,\n             a.first.second\
    \ * b.first.first + b.first.second},\n            {b.second.first * a.second.first,\n\
    \             b.second.second * a.second.first + a.second.second},\n        };\n\
    \    }\n};\n\nAffineMonoid::T flip(AffineMonoid::T a) {\n    swap(a.first, a.second);\n\
    \    return a;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n   \
    \ cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    LinkCutTree<AffineMonoid,\
    \ flip> lct(N);\n    for (int i = 0; i < N; ++i) {\n        int a, b;\n      \
    \  cin >> a >> b;\n        lct.set(i, {{a, b}, {a, b}});\n    }\n    for (int\
    \ i = 0; i < N - 1; ++i) {\n        int u, v;\n        cin >> u >> v;\n      \
    \  lct.link(u, v);\n    }\n    for (int i = 0; i < Q; ++i) {\n        int t;\n\
    \        cin >> t;\n        if (t == 0) {\n            int u, v, w, x;\n     \
    \       cin >> u >> v >> w >> x;\n            lct.evert(u);\n            lct.cut(v);\n\
    \            lct.link(w, x);\n        } else if (t == 1) {\n            int p,\
    \ c, d;\n            cin >> p >> c >> d;\n            lct.set(p, {{c, d}, {c,\
    \ d}});\n        } else {\n            int u, v, x;\n            cin >> u >> v\
    \ >> x;\n            auto f = lct.fold(u, v);\n            cout << f.first.first\
    \ * x + f.first.second << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - math/modint.hpp
  - tree/link_cut_tree.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
- /verify/test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp.html
title: test/yosupo/dynamic_tree_vertex_set_path_composite.test.cpp
---
