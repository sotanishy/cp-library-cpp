---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bst/lazy_treap.hpp
    title: Treap with Lazy Propagation
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#line 6 \"data-structure/bst/lazy_treap.hpp\"\n\
    \ntemplate <typename M, typename O,\n          typename M::T (*act)(typename M::T,\
    \ typename O::T)>\nclass LazyTreap {\n    using T = M::T;\n    using E = O::T;\n\
    \n   public:\n    LazyTreap() = default;\n\n    static LazyTreap join(LazyTreap\
    \ l, LazyTreap r) {\n        return LazyTreap(join(std::move(l.root), std::move(r.root)));\n\
    \    }\n\n    std::pair<LazyTreap, LazyTreap> split(int k) {\n        assert(0\
    \ <= k && k <= size());\n        auto p = split(std::move(root), k);\n       \
    \ return {LazyTreap(std::move(p.first)), LazyTreap(std::move(p.second))};\n  \
    \  }\n\n    void update(int l, int r, const E& x) {\n        assert(0 <= l &&\
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
    \ new Node(x)), std::move(s.second));\n    }\n\n    void erase(int k) {\n    \
    \    auto p = split(std::move(root), k);\n        auto q = split(std::move(p.second),\
    \ 1);\n        root = join(std::move(p.first), std::move(q.second));\n    }\n\n\
    \    void push_front(const T& x) { root = join(new Node(x), std::move(root));\
    \ }\n\n    void push_back(const T& x) { root = join(std::move(root), new Node(x));\
    \ }\n\n    void pop_front() { root = split(std::move(root), 1).second; }\n\n \
    \   void pop_back() { root = split(std::move(root), size() - 1).first; }\n\n \
    \   int size() const { return size(root); }\n\n    bool empty() const { return\
    \ size() == 0; }\n\n   private:\n    struct Node;\n    using node_ptr = Node*;\n\
    \n    static unsigned int rand() {\n        static std::random_device rd;\n  \
    \      static std::mt19937 rng(rd());\n        return rng();\n    }\n\n    struct\
    \ Node {\n        node_ptr left, right;\n        T val, sum;\n        E lazy;\n\
    \        unsigned int pri;\n        int sz;\n        bool rev;\n\n        Node()\
    \ : Node(M::id()) {}\n        Node(const T& x)\n            : left(nullptr),\n\
    \              right(nullptr),\n              val(x),\n              sum(val),\n\
    \              lazy(O::id()),\n              pri(rand()),\n              sz(1),\n\
    \              rev(false) {}\n    };\n\n    node_ptr root = nullptr;\n\n    explicit\
    \ LazyTreap(node_ptr root) : root(std::move(root)) {}\n\n    static int size(const\
    \ node_ptr& t) { return t ? t->sz : 0; }\n\n    static void recalc(const node_ptr&\
    \ t) {\n        if (!t) return;\n        t->sz = size(t->left) + 1 + size(t->right);\n\
    \        t->sum = t->val;\n        if (t->left) t->sum = M::op(t->left->sum, t->sum);\n\
    \        if (t->right) t->sum = M::op(t->sum, t->right->sum);\n    }\n\n    static\
    \ void push(const node_ptr& t) {\n        if (t->rev) {\n            std::swap(t->left,\
    \ t->right);\n            if (t->left) t->left->rev ^= true;\n            if (t->right)\
    \ t->right->rev ^= true;\n            t->rev = false;\n        }\n        if (t->lazy\
    \ != O::id()) {\n            t->val = act(t->val, t->lazy);\n            if (t->left)\
    \ {\n                t->left->lazy = O::op(t->left->lazy, t->lazy);\n        \
    \        t->left->sum = act(t->left->sum, t->lazy);\n            }\n         \
    \   if (t->right) {\n                t->right->lazy = O::op(t->right->lazy, t->lazy);\n\
    \                t->right->sum = act(t->right->sum, t->lazy);\n            }\n\
    \            t->lazy = O::id();\n        }\n        recalc(t);\n    }\n\n    static\
    \ node_ptr join(node_ptr l, node_ptr r) {\n        if (!l) return r;\n       \
    \ if (!r) return l;\n        push(l);\n        push(r);\n        if (l->pri >\
    \ r->pri) {\n            l->right = join(std::move(l->right), std::move(r));\n\
    \            recalc(l);\n            return l;\n        } else {\n           \
    \ r->left = join(std::move(l), std::move(r->left));\n            recalc(r);\n\
    \            return r;\n        }\n    }\n\n    static std::pair<node_ptr, node_ptr>\
    \ split(node_ptr t, int k) {\n        if (!t) return {nullptr, nullptr};\n   \
    \     push(t);\n        if (k <= size(t->left)) {\n            auto s = split(std::move(t->left),\
    \ k);\n            t->left = std::move(s.second);\n            recalc(t);\n  \
    \          return {std::move(s.first), std::move(t)};\n        } else {\n    \
    \        auto s = split(std::move(t->right), k - size(t->left) - 1);\n       \
    \     t->right = std::move(s.first);\n            recalc(t);\n            return\
    \ {std::move(t), std::move(s.second)};\n        }\n    }\n};\n#line 4 \"math/modint.hpp\"\
    \n\n/**\n * @brief Mod int\n */\ntemplate <int m>\nclass Modint {\n    using mint\
    \ = Modint;\n    static_assert(m > 0, \"Modulus must be positive\");\n\n   public:\n\
    \    static constexpr int mod() { return m; }\n\n    constexpr Modint(long long\
    \ y = 0) : x(y >= 0 ? y % m : (y % m + m) % m) {}\n\n    constexpr int val() const\
    \ { return x; }\n\n    constexpr mint& operator+=(const mint& r) {\n        if\
    \ ((x += r.x) >= m) x -= m;\n        return *this;\n    }\n    constexpr mint&\
    \ operator-=(const mint& r) {\n        if ((x += m - r.x) >= m) x -= m;\n    \
    \    return *this;\n    }\n    constexpr mint& operator*=(const mint& r) {\n \
    \       x = static_cast<int>(1LL * x * r.x % m);\n        return *this;\n    }\n\
    \    constexpr mint& operator/=(const mint& r) { return *this *= r.inv(); }\n\n\
    \    constexpr bool operator==(const mint& r) const { return x == r.x; }\n\n \
    \   constexpr mint operator+() const { return *this; }\n    constexpr mint operator-()\
    \ const { return mint(-x); }\n\n    constexpr friend mint operator+(const mint&\
    \ l, const mint& r) {\n        return mint(l) += r;\n    }\n    constexpr friend\
    \ mint operator-(const mint& l, const mint& r) {\n        return mint(l) -= r;\n\
    \    }\n    constexpr friend mint operator*(const mint& l, const mint& r) {\n\
    \        return mint(l) *= r;\n    }\n    constexpr friend mint operator/(const\
    \ mint& l, const mint& r) {\n        return mint(l) /= r;\n    }\n\n    constexpr\
    \ mint inv() const {\n        int a = x, b = m, u = 1, v = 0;\n        while (b\
    \ > 0) {\n            int t = a / b;\n            std::swap(a -= t * b, b);\n\
    \            std::swap(u -= t * v, v);\n        }\n        return mint(u);\n \
    \   }\n\n    constexpr mint pow(long long n) const {\n        mint ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend std::ostream& operator<<(std::ostream& os, const mint& r) {\n       \
    \ return os << r.x;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& r) {\n        long long t;\n        is >> t;\n        r = mint(t);\n\
    \        return is;\n    }\n\n   private:\n    int x;\n};\n#line 8 \"test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nstruct M {\n    using\
    \ T = pair<mint, mint>;\n    static T id() { return {0, 0}; }\n    static T op(T\
    \ a, T b) { return {a.first + b.first, a.second + b.second}; }\n};\n\nstruct O\
    \ {\n    using T = pair<mint, mint>;\n    static T id() { return {1, 0}; }\n \
    \   static T op(T a, T b) {\n        return {a.first * b.first, a.second * b.first\
    \ + b.second};\n    }\n};\n\nM::T act(M::T a, O::T b) {\n    return {a.first *\
    \ b.first + a.second * b.second, a.second};\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    LazyTreap<M, O, act>\
    \ st;\n    for (int i = 0; i < N; ++i) {\n        int a;\n        cin >> a;\n\
    \        st.push_back({a, 1});\n    }\n    while (Q--) {\n        int t;\n   \
    \     cin >> t;\n        if (t == 0) {\n            int i, x;\n            cin\
    \ >> i >> x;\n            st.insert(i, {x, 1});\n        } else if (t == 1) {\n\
    \            int i;\n            cin >> i;\n            st.erase(i);\n       \
    \ } else if (t == 2) {\n            int l, r;\n            cin >> l >> r;\n  \
    \          st.reverse(l, r);\n        } else if (t == 3) {\n            int l,\
    \ r, b, c;\n            cin >> l >> r >> b >> c;\n            st.update(l, r,\
    \ {b, c});\n        } else {\n            int l, r;\n            cin >> l >> r;\n\
    \            cout << st.fold(l, r).first << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/bst/lazy_treap.hpp\"\
    \n#include \"../../math/modint.hpp\"\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct M {\n    using T = pair<mint, mint>;\n    static T id() { return {0,\
    \ 0}; }\n    static T op(T a, T b) { return {a.first + b.first, a.second + b.second};\
    \ }\n};\n\nstruct O {\n    using T = pair<mint, mint>;\n    static T id() { return\
    \ {1, 0}; }\n    static T op(T a, T b) {\n        return {a.first * b.first, a.second\
    \ * b.first + b.second};\n    }\n};\n\nM::T act(M::T a, O::T b) {\n    return\
    \ {a.first * b.first + a.second * b.second, a.second};\n}\n\nint main() {\n  \
    \  ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int N, Q;\n    cin\
    \ >> N >> Q;\n    LazyTreap<M, O, act> st;\n    for (int i = 0; i < N; ++i) {\n\
    \        int a;\n        cin >> a;\n        st.push_back({a, 1});\n    }\n   \
    \ while (Q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n  \
    \          int i, x;\n            cin >> i >> x;\n            st.insert(i, {x,\
    \ 1});\n        } else if (t == 1) {\n            int i;\n            cin >> i;\n\
    \            st.erase(i);\n        } else if (t == 2) {\n            int l, r;\n\
    \            cin >> l >> r;\n            st.reverse(l, r);\n        } else if\
    \ (t == 3) {\n            int l, r, b, c;\n            cin >> l >> r >> b >> c;\n\
    \            st.update(l, r, {b, c});\n        } else {\n            int l, r;\n\
    \            cin >> l >> r;\n            cout << st.fold(l, r).first << \"\\n\"\
    ;\n        }\n    }\n}"
  dependsOn:
  - data-structure/bst/lazy_treap.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 11:43:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
- /verify/test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp.html
title: test/yosupo/dynamic_sequence_range_affine_range_sum.treap.test.cpp
---
