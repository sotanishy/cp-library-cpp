---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bst/lazy_treap.cpp
    title: Treap with Lazy Propagation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F.lazy_treap.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\n\n#line\
    \ 2 \"data-structure/bst/lazy_treap.cpp\"\n#include <cassert>\n#include <memory>\n\
    #include <random>\n#include <utility>\n\n/*\n * @brief Treap with Lazy Propagation\n\
    \ * @docs docs/data-structure/bst/lazy_treap.md\n */\ntemplate <typename M, typename\
    \ O, typename M::T (*act)(typename M::T, typename O::T)>\nclass LazyTreap {\n\
    \    using T = typename M::T;\n    using E = typename O::T;\n\npublic:\n    LazyTreap()\
    \ = default;\n\n    static LazyTreap join(LazyTreap l, LazyTreap r) {\n      \
    \  return LazyTreap(join(std::move(l.root), std::move(r.root)));\n    }\n\n  \
    \  std::pair<LazyTreap, LazyTreap> split(int k) {\n        auto p = split(std::move(root),\
    \ k);\n        return {LazyTreap(std::move(p.first)), LazyTreap(std::move(p.second))};\n\
    \    }\n\n    void update(int l, int r, const T& x) {\n        assert(0 <= l &&\
    \ l < r && r <= size());\n        node_ptr a, b, c;\n        std::tie(a, b) =\
    \ split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b), r -\
    \ l);\n        b->lazy = O::op(b->lazy, x);\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    T fold(int l, int r) {\n       \
    \ assert(0 <= l && l < r && r <= size());\n        node_ptr a, b, c;\n       \
    \ std::tie(a, b) = split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b),\
    \ r - l);\n        auto ret = b->sum;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n        return ret;\n    }\n\n    void reverse(int\
    \ l, int r) {\n        assert(0 <= l && l < r && r <= size());\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a),\
    \ std::move(b)), std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n\
    \        auto s = split(std::move(root), k);\n        root = join(join(std::move(s.first),\
    \ std::make_unique<Node>(x)), std::move(s.second));\n    }\n\n    void erase(int\
    \ k) {\n        auto p = split(std::move(root), k - 1);\n        auto q = split(std::move(p.second),\
    \ 1);\n        return join(std::move(p.first), std::move(q.second));\n    }\n\n\
    \    void push_front(const T& x) {\n        root = join(std::make_unique<Node>(x),\
    \ std::move(root));\n    }\n\n    void push_back(const T& x) {\n        root =\
    \ join(std::move(root), std::make_unique<Node>(x));\n    }\n\n    void pop_front()\
    \ {\n        root = split(std::move(root), 1).second;\n    }\n\n    void pop_back()\
    \ {\n        root = split(std::move(root), size() - 1).first;\n    }\n\n    int\
    \ size() const {\n        return size(root);\n    }\n\n    bool empty() const\
    \ {\n        return size() == 0;\n    }\n\nprivate:\n    struct Node;\n    using\
    \ node_ptr = std::unique_ptr<Node>;\n\n    static unsigned int rand() {\n    \
    \    static std::random_device rd;\n        static std::mt19937 rng(rd());\n \
    \       return rng();\n    }\n\n    struct Node {\n        node_ptr left, right;\n\
    \        T val, sum;\n        E lazy;\n        unsigned int pri;\n        int\
    \ sz;\n        bool rev;\n\n        Node() : Node(M::id) {}\n        Node(const\
    \ T& x) : left(nullptr), right(nullptr), val(x), sum(val), lazy(O::id), pri(rand()),\
    \ sz(1), rev(false) {}\n    };\n\n    node_ptr root;\n\n    explicit LazyTreap(node_ptr\
    \ root) : root(std::move(root)) {}\n\n    static int size(const node_ptr& t) {\n\
    \        return t ? t->sz : 0;\n    }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ void push(const node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left,\
    \ t->right);\n            if (t->left) t->left->rev ^= true;\n            if (t->right)\
    \ t->right->rev ^= true;\n            t->rev = false;\n        }\n        if (t->lazy\
    \ != O::id) {\n            t->val = act(t->val, t->lazy);\n            if (t->left)\
    \ {\n                t->left->lazy = O::op(t->left->lazy, t->lazy);\n        \
    \        t->left->sum = act(t->left->sum, t->lazy);\n            }\n         \
    \   if (t->right) {\n                t->right->lazy = O::op(t->right->lazy, t->lazy);\n\
    \                t->right->sum = act(t->right->sum, t->lazy);\n            }\n\
    \            t->lazy = O::id;\n        }\n        recalc(t);\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        push(l);\n        push(r);\n        if (l->pri >\
    \ r->pri) {\n            l->right = join(std::move(l->right), std::move(r));\n\
    \            recalc(l);\n            return l;\n        } else {\n           \
    \ r->left = join(std::move(l), std::move(r->left));\n            recalc(r);\n\
    \            return r;\n        }\n    }\n\n    static std::pair<node_ptr, node_ptr>\
    \ split(node_ptr t, int k) {\n        assert(0 <= k && k <= size(t));\n      \
    \  push(t);\n        if (k == 0) return {nullptr, std::move(t)};\n        if (k\
    \ == size(t)) return {std::move(t), nullptr};\n        if (k <= size(t->left))\
    \ {\n            auto s = split(std::move(t->left), k);\n            t->left =\
    \ std::move(s.second);\n            recalc(t);\n            return {std::move(s.first),\
    \ std::move(t)};\n        } else {\n            auto s = split(std::move(t->right),\
    \ k - size(t->left) - 1);\n            t->right = std::move(s.first);\n      \
    \      recalc(t);\n            return {std::move(t), std::move(s.second)};\n \
    \       }\n    }\n};\n#line 4 \"test/aoj/DSL_2_F.lazy_treap.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nstruct M {\n    using T = int;\n  \
    \  static constexpr T id = (1u << 31) - 1;\n    static T op(T a, T b) {\n    \
    \    return min(a, b);\n    }\n};\n\nstruct O {\n    using T = int;\n    static\
    \ constexpr T id = (1u << 31) - 1;\n    static T op(T a, T b) {\n        return\
    \ b;\n    }\n};\n\nM::T act(M::T a, O::T b) {\n    return b;\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n, q;\n\
    \    cin >> n >> q;\n    LazyTreap<M, O, act> st;\n    for (int i = 0; i < n;\
    \ ++i) st.push_back(M::id);\n    for (int i = 0; i < q; i++) {\n        int type,\
    \ s, t;\n        cin >> type >> s >> t;\n        if (type == 0) {\n          \
    \  int x;\n            cin >> x;\n            st.update(s, t + 1, x);\n      \
    \  } else {\n            cout << st.fold(s, t + 1) << \"\\n\";\n        }\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include \"../../data-structure/bst/lazy_treap.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct M {\n    using T = int;\n    static constexpr T\
    \ id = (1u << 31) - 1;\n    static T op(T a, T b) {\n        return min(a, b);\n\
    \    }\n};\n\nstruct O {\n    using T = int;\n    static constexpr T id = (1u\
    \ << 31) - 1;\n    static T op(T a, T b) {\n        return b;\n    }\n};\n\nM::T\
    \ act(M::T a, O::T b) {\n    return b;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    LazyTreap<M, O, act>\
    \ st;\n    for (int i = 0; i < n; ++i) st.push_back(M::id);\n    for (int i =\
    \ 0; i < q; i++) {\n        int type, s, t;\n        cin >> type >> s >> t;\n\
    \        if (type == 0) {\n            int x;\n            cin >> x;\n       \
    \     st.update(s, t + 1, x);\n        } else {\n            cout << st.fold(s,\
    \ t + 1) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/bst/lazy_treap.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.lazy_treap.test.cpp
  requiredBy: []
  timestamp: '2020-11-03 02:54:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.lazy_treap.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.lazy_treap.test.cpp
- /verify/test/aoj/DSL_2_F.lazy_treap.test.cpp.html
title: test/aoj/DSL_2_F.lazy_treap.test.cpp
---
