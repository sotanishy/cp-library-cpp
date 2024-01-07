---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/bst/treap.hpp
    title: Treap
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_reverse_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_reverse_range_sum.treap.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 6 \"data-structure/bst/treap.hpp\"\n\ntemplate <typename\
    \ M>\nclass Treap {\n    using T = typename M::T;\n\n   public:\n    Treap() =\
    \ default;\n\n    static Treap join(Treap l, Treap r) {\n        return Treap(join(std::move(l.root),\
    \ std::move(r.root)));\n    }\n\n    std::pair<Treap, Treap> split(int k) {\n\
    \        auto p = split(std::move(root), k);\n        return {Treap(std::move(p.first)),\
    \ Treap(std::move(p.second))};\n    }\n\n    void update(int k, const T& x) const\
    \ { update(root, k, x); }\n\n    T fold(int l, int r) {\n        assert(0 <= l\
    \ && l <= r && r <= size());\n        if (l == r) return M::id();\n        node_ptr\
    \ a, b, c;\n        std::tie(a, b) = split(std::move(root), l);\n        std::tie(b,\
    \ c) = split(std::move(b), r - l);\n        auto ret = b->sum;\n        root =\
    \ join(join(std::move(a), std::move(b)), std::move(c));\n        return ret;\n\
    \    }\n\n    void reverse(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= size());\n        if (l == r) return;\n        node_ptr a, b, c;\n    \
    \    std::tie(a, b) = split(std::move(root), l);\n        std::tie(b, c) = split(std::move(b),\
    \ r - l);\n        b->rev ^= true;\n        root = join(join(std::move(a), std::move(b)),\
    \ std::move(c));\n    }\n\n    void insert(int k, const T& x) {\n        auto\
    \ s = split(std::move(root), k);\n        root = join(join(std::move(s.first),\
    \ std::make_unique<Node>(x)),\n                    std::move(s.second));\n   \
    \ }\n\n    void erase(int k) {\n        auto p = split(std::move(root), k);\n\
    \        auto q = split(std::move(p.second), 1);\n        return join(std::move(p.first),\
    \ std::move(q.second));\n    }\n\n    void push_front(const T& x) {\n        root\
    \ = join(std::make_unique<Node>(x), std::move(root));\n    }\n\n    void push_back(const\
    \ T& x) {\n        root = join(std::move(root), std::make_unique<Node>(x));\n\
    \    }\n\n    void pop_front() { root = split(std::move(root), 1).second; }\n\n\
    \    void pop_back() { root = split(std::move(root), size() - 1).first; }\n\n\
    \    int size() const { return size(root); }\n\n    bool empty() const { return\
    \ size() == 0; }\n\n   private:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    static unsigned int rand() {\n        static std::random_device rd;\n  \
    \      static std::mt19937 rng(rd());\n        return rng();\n    }\n\n    struct\
    \ Node {\n        node_ptr left, right;\n        T val, sum;\n        unsigned\
    \ int pri;\n        int sz;\n        bool rev;\n\n        Node() : Node(M::id())\
    \ {}\n        Node(const T& x)\n            : left(nullptr),\n              right(nullptr),\n\
    \              val(x),\n              sum(val),\n              pri(rand()),\n\
    \              sz(1),\n              rev(false) {}\n    };\n\n    node_ptr root;\n\
    \n    explicit Treap(node_ptr root) : root(std::move(root)) {}\n\n    static int\
    \ size(const node_ptr& t) { return t ? t->sz : 0; }\n\n    static void recalc(const\
    \ node_ptr& t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 +\
    \ size(t->right);\n        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum,\
    \ t->sum);\n        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n   \
    \ }\n\n    static void push(const node_ptr& t) {\n        if (t->rev) {\n    \
    \        std::swap(t->left, t->right);\n            if (t->left) t->left->rev\
    \ ^= true;\n            if (t->right) t->right->rev ^= true;\n            t->rev\
    \ = false;\n        }\n    }\n\n    static node_ptr join(node_ptr l, node_ptr\
    \ r) {\n        if (!l) return r;\n        if (!r) return l;\n        push(l);\n\
    \        push(r);\n        if (l->pri > r->pri) {\n            l->right = join(std::move(l->right),\
    \ std::move(r));\n            recalc(l);\n            return l;\n        } else\
    \ {\n            r->left = join(std::move(l), std::move(r->left));\n         \
    \   recalc(r);\n            return r;\n        }\n    }\n\n    static std::pair<node_ptr,\
    \ node_ptr> split(node_ptr t, int k) {\n        assert(0 <= k && k <= size(t));\n\
    \        if (k == 0) return {nullptr, std::move(t)};\n        if (k == size(t))\
    \ return {std::move(t), nullptr};\n        push(t);\n        if (k <= size(t->left))\
    \ {\n            auto s = split(std::move(t->left), k);\n            t->left =\
    \ std::move(s.second);\n            recalc(t);\n            return {std::move(s.first),\
    \ std::move(t)};\n        } else {\n            auto s = split(std::move(t->right),\
    \ k - size(t->left) - 1);\n            t->right = std::move(s.first);\n      \
    \      recalc(t);\n            return {std::move(t), std::move(s.second)};\n \
    \       }\n    }\n\n    static void update(const node_ptr& t, int k, const T&\
    \ x) {\n        push(t);\n        int lsize = size(t->left);\n        if (k <\
    \ lsize) {\n            update(t->left, k, x);\n        } else if (lsize < k)\
    \ {\n            update(t->right, k - lsize - 1, x);\n        } else {\n     \
    \       t->val = x;\n        }\n        recalc(t);\n    }\n};\n#line 6 \"test/yosupo/range_reverse_range_sum.treap.test.cpp\"\
    \nusing namespace std;\n\nstruct AddMonoid {\n    using T = long long;\n    static\
    \ T id() { return 0; }\n    static T op(T a, T b) { return a + b; }\n};\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    Treap<AddMonoid> st;\n    for (int i = 0; i <\
    \ N; ++i) {\n        long long x;\n        cin >> x;\n        st.push_back(x);\n\
    \    }\n    for (int i = 0; i < Q; i++) {\n        int t, l, r;\n        cin >>\
    \ t >> l >> r;\n        if (t == 0) {\n            st.reverse(l, r);\n       \
    \ } else {\n            cout << st.fold(l, r) << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/bst/treap.hpp\"\
    \nusing namespace std;\n\nstruct AddMonoid {\n    using T = long long;\n    static\
    \ T id() { return 0; }\n    static T op(T a, T b) { return a + b; }\n};\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    Treap<AddMonoid> st;\n    for (int i = 0; i <\
    \ N; ++i) {\n        long long x;\n        cin >> x;\n        st.push_back(x);\n\
    \    }\n    for (int i = 0; i < Q; i++) {\n        int t, l, r;\n        cin >>\
    \ t >> l >> r;\n        if (t == 0) {\n            st.reverse(l, r);\n       \
    \ } else {\n            cout << st.fold(l, r) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/bst/treap.hpp
  isVerificationFile: true
  path: test/yosupo/range_reverse_range_sum.treap.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 01:52:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_reverse_range_sum.treap.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_reverse_range_sum.treap.test.cpp
- /verify/test/yosupo/range_reverse_range_sum.treap.test.cpp.html
title: test/yosupo/range_reverse_range_sum.treap.test.cpp
---
