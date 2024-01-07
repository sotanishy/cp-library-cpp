---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree.cpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/sortable_segment_tree.hpp
    title: Sortable Segment Tree
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_sort_range_composite.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \n\n#include <bits/stdc++.h>\n\n#line 4 \"data-structure/segtree/segment_tree.cpp\"\
    \n\ntemplate <typename M>\nclass SegmentTree {\n    using T = typename M::T;\n\
    \n   public:\n    SegmentTree() = default;\n    explicit SegmentTree(int n) :\
    \ SegmentTree(std::vector<T>(n, M::id())) {}\n    explicit SegmentTree(const std::vector<T>&\
    \ v) {\n        size = 1;\n        while (size < (int)v.size()) size <<= 1;\n\
    \        node.resize(2 * size, M::id());\n        std::copy(v.begin(), v.end(),\
    \ node.begin() + size);\n        for (int i = size - 1; i > 0; --i)\n        \
    \    node[i] = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int\
    \ k) const { return node[k + size]; }\n\n    void update(int k, const T& x) {\n\
    \        k += size;\n        node[k] = x;\n        while (k >>= 1) node[k] = M::op(node[2\
    \ * k], node[2 * k + 1]);\n    }\n\n    T fold(int l, int r) const {\n       \
    \ T vl = M::id(), vr = M::id();\n        for (l += size, r += size; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) vl = M::op(vl, node[l++]);\n         \
    \   if (r & 1) vr = M::op(node[--r], vr);\n        }\n        return M::op(vl,\
    \ vr);\n    }\n\n    template <typename F>\n    int find_first(int l, F cond)\
    \ const {\n        T v = M::id();\n        for (l += size; l > 0; l >>= 1) {\n\
    \            if (l & 1) {\n                T nv = M::op(v, node[l]);\n       \
    \         if (cond(nv)) {\n                    while (l < size) {\n          \
    \              nv = M::op(v, node[2 * l]);\n                        if (cond(nv))\n\
    \                            l = 2 * l;\n                        else\n      \
    \                      v = nv, l = 2 * l + 1;\n                    }\n       \
    \             return l + 1 - size;\n                }\n                v = nv;\n\
    \                ++l;\n            }\n        }\n        return -1;\n    }\n\n\
    \    template <typename F>\n    int find_last(int r, F cond) const {\n       \
    \ T v = M::id();\n        for (r += size; r > 0; r >>= 1) {\n            if (r\
    \ & 1) {\n                --r;\n                T nv = M::op(node[r], v);\n  \
    \              if (cond(nv)) {\n                    while (r < size) {\n     \
    \                   nv = M::op(node[2 * r + 1], v);\n                        if\
    \ (cond(nv))\n                            r = 2 * r + 1;\n                   \
    \     else\n                            v = nv, r = 2 * r;\n                 \
    \   }\n                    return r - size;\n                }\n             \
    \   v = nv;\n            }\n        }\n        return -1;\n    }\n\n   private:\n\
    \    int size;\n    std::vector<T> node;\n};\n#line 6 \"data-structure/segtree/sortable_segment_tree.hpp\"\
    \n\n#line 8 \"data-structure/segtree/sortable_segment_tree.hpp\"\n\ntemplate <typename\
    \ M>\nclass SortableSegmentTree {\n    using T = typename M::T;\n\n   public:\n\
    \    SortableSegmentTree() = default;\n    explicit SortableSegmentTree(long long\
    \ max_key,\n                                 const std::vector<std::pair<long\
    \ long, T>>& kv)\n        : n(kv.size()), max_key(max_key), st_all(n), st_sorted(n),\
    \ rev(n) {\n        for (int k = 0; k < n; ++k) {\n            auto [key, val]\
    \ = kv[k];\n            st_sorted[k] = std::make_unique<Node>();\n           \
    \ st_sorted[k]->update(key, val, 0, max_key);\n            st_all.update(k, val);\n\
    \            left.insert(k);\n        }\n        left.insert(n);\n    }\n\n  \
    \  void update(int k, long long key, const T& val) {\n        split(k), split(k\
    \ + 1);\n        st_sorted[k] = std::make_unique<Node>();\n        st_sorted[k]->update(key,\
    \ val, 0, max_key);\n        st_all.update(k, val);\n    }\n\n    T fold(int l,\
    \ int r) {\n        split(l), split(r);\n        return st_all.fold(l, r);\n \
    \   }\n\n    void sort(int l, int r, bool descending = false) {\n        if (r\
    \ - l <= 1) return;\n        split(l), split(r);\n        auto it = ++left.find(l);\n\
    \        while (it != left.end() && *it < r) {\n            st_sorted[l] =\n \
    \               join(std::move(st_sorted[l]), std::move(st_sorted[*it]));\n  \
    \          st_all.update(*it, M::id());\n            rev[*it] = false;\n     \
    \       it = left.erase(it);\n        }\n        if (st_sorted[l]) {\n       \
    \     st_all.update(l, !descending ? st_sorted[l]->val_forward\n             \
    \                            : st_sorted[l]->val_backward);\n            rev[l]\
    \ = descending;\n        }\n    }\n\n   private:\n    struct Node;\n    using\
    \ node_ptr = std::unique_ptr<Node>;\n\n    struct Node {\n        int sz;\n  \
    \      T val_forward, val_backward;\n        node_ptr left, right;\n        Node()\n\
    \            : sz(0),\n              val_forward(M::id()),\n              val_backward(M::id()),\n\
    \              left(nullptr),\n              right(nullptr) {}\n\n        void\
    \ recalc() {\n            int sl = left ? left->sz : 0;\n            int sr =\
    \ right ? right->sz : 0;\n            sz = sl + sr;\n            T vl_forward\
    \ = left ? left->val_forward : M::id();\n            T vr_forward = right ? right->val_forward\
    \ : M::id();\n            val_forward = M::op(vl_forward, vr_forward);\n     \
    \       T vl_backward = left ? left->val_backward : M::id();\n            T vr_backward\
    \ = right ? right->val_backward : M::id();\n            val_backward = M::op(vr_backward,\
    \ vl_backward);\n        }\n\n        void update(long long key, const T& x, long\
    \ long l, long long r) {\n            if (r - l == 1) {\n                sz =\
    \ 1;\n                val_forward = val_backward = x;\n                return;\n\
    \            }\n            long long m = (l + r) / 2;\n            if (key <\
    \ m) {\n                if (!left) left = std::make_unique<Node>();\n        \
    \        left->update(key, x, l, m);\n            } else {\n                if\
    \ (!right) right = std::make_unique<Node>();\n                right->update(key,\
    \ x, m, r);\n            }\n            recalc();\n        }\n    };\n\n    static\
    \ std::pair<node_ptr, node_ptr> split(node_ptr t, int k) {\n        if (k == 0)\
    \ return {nullptr, std::move(t)};\n        if (k == t->sz) return {std::move(t),\
    \ nullptr};\n        int szl = t->left ? t->left->sz : 0;\n        auto t2 = std::make_unique<Node>();\n\
    \        if (k < szl) {\n            std::tie(t2->left, t->left) = split(std::move(t->left),\
    \ k);\n            std::swap(t, t2);\n        } else {\n            std::tie(t->right,\
    \ t2->right) = split(std::move(t->right), k - szl);\n        }\n        t->recalc(),\
    \ t2->recalc();\n        return {std::move(t), std::move(t2)};\n    }\n\n    static\
    \ node_ptr join(node_ptr t1, node_ptr t2) {\n        if (!t1) return t2;\n   \
    \     if (!t2) return t1;\n        t1->left = join(std::move(t1->left), std::move(t2->left));\n\
    \        t1->right = join(std::move(t1->right), std::move(t2->right));\n     \
    \   t1->recalc();\n        return t1;\n    }\n\n    int n;\n    long long max_key;\n\
    \    std::set<int> left;\n    SegmentTree<M> st_all;\n    std::vector<node_ptr>\
    \ st_sorted;\n    std::vector<bool> rev;\n\n    void split(int k) {\n        int\
    \ l = *--left.upper_bound(k);\n        if (l == k) return;\n        if (!rev[l])\
    \ {\n            std::tie(st_sorted[l], st_sorted[k]) =\n                split(std::move(st_sorted[l]),\
    \ k - l);\n        } else {\n            std::tie(st_sorted[k], st_sorted[l])\
    \ =\n                split(std::move(st_sorted[l]), l + st_sorted[l]->sz - k);\n\
    \            rev[k] = true;\n        }\n        left.insert(k);\n        if (st_sorted[l])\
    \ {\n            st_all.update(l, !rev[l] ? st_sorted[l]->val_forward\n      \
    \                               : st_sorted[l]->val_backward);\n        }\n  \
    \      if (st_sorted[k]) {\n            st_all.update(k, !rev[k] ? st_sorted[k]->val_forward\n\
    \                                     : st_sorted[k]->val_backward);\n       \
    \ }\n    }\n};\n#line 4 \"math/modint.cpp\"\n\n/**\n * @brief Mod int\n */\ntemplate\
    \ <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod >\
    \ 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
    \ noexcept { return mod; }\n\n    constexpr Modint(long long y = 0) noexcept :\
    \ x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n    constexpr int value()\
    \ const noexcept { return x; }\n\n    constexpr mint& operator+=(const mint& r)\
    \ noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr mint&\
    \ operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod;\
    \ return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept { x\
    \ = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr mint&\
    \ operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\n \
    \   constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
    \ mint operator+(const mint& r) const noexcept { return mint(*this) += r; }\n\
    \    constexpr mint operator-(const mint& r) const noexcept { return mint(*this)\
    \ -= r; }\n    constexpr mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n    constexpr mint operator/(const mint& r) const noexcept\
    \ { return mint(*this) /= r; }\n\n    constexpr bool operator==(const mint& r)\
    \ const noexcept { return x == r.x; }\n    constexpr bool operator!=(const mint&\
    \ r) const noexcept { return x != r.x; }\n\n    constexpr mint inv() const noexcept\
    \ {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0) {\n    \
    \        int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n        while\
    \ (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n   \
    \         n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\nprivate:\n    int x;\n};\n#line 9 \"test/yosupo/point_set_range_sort_range_composite.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nstruct AffineMonoid\
    \ {\n    using T = pair<mint, mint>;\n    static T id() { return {1, 0}; }\n \
    \   static T op(T a, T b) {\n        return {a.first * b.first, a.second * b.first\
    \ + b.second};\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<pair<long long,\
    \ pair<mint, mint>>> kv(N);\n    for (int i = 0; i < N; ++i) {\n        int p,\
    \ a, b;\n        cin >> p >> a >> b;\n        kv[i] = {p, {a, b}};\n    }\n  \
    \  SortableSegmentTree<AffineMonoid> st(1e9 + 1, kv);\n    for (int i = 0; i <\
    \ Q; i++) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n      \
    \      int i, p, a, b;\n            cin >> i >> p >> a >> b;\n            st.update(i,\
    \ p, {a, b});\n        } else if (t == 1) {\n            int l, r, x;\n      \
    \      cin >> l >> r >> x;\n            auto [a, b] = st.fold(l, r);\n       \
    \     cout << (a * x + b) << \"\\n\";\n        } else if (t == 2) {\n        \
    \    int l, r;\n            cin >> l >> r;\n            st.sort(l, r);\n     \
    \   } else {\n            int l, r;\n            cin >> l >> r;\n            st.sort(l,\
    \ r, true);\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/segtree/segment_tree.cpp\"\
    \n#include \"../../data-structure/segtree/sortable_segment_tree.hpp\"\n#include\
    \ \"../../math/modint.cpp\"\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct AffineMonoid {\n    using T = pair<mint, mint>;\n    static T id() {\
    \ return {1, 0}; }\n    static T op(T a, T b) {\n        return {a.first * b.first,\
    \ a.second * b.first + b.second};\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<pair<long long,\
    \ pair<mint, mint>>> kv(N);\n    for (int i = 0; i < N; ++i) {\n        int p,\
    \ a, b;\n        cin >> p >> a >> b;\n        kv[i] = {p, {a, b}};\n    }\n  \
    \  SortableSegmentTree<AffineMonoid> st(1e9 + 1, kv);\n    for (int i = 0; i <\
    \ Q; i++) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n      \
    \      int i, p, a, b;\n            cin >> i >> p >> a >> b;\n            st.update(i,\
    \ p, {a, b});\n        } else if (t == 1) {\n            int l, r, x;\n      \
    \      cin >> l >> r >> x;\n            auto [a, b] = st.fold(l, r);\n       \
    \     cout << (a * x + b) << \"\\n\";\n        } else if (t == 2) {\n        \
    \    int l, r;\n            cin >> l >> r;\n            st.sort(l, r);\n     \
    \   } else {\n            int l, r;\n            cin >> l >> r;\n            st.sort(l,\
    \ r, true);\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/segment_tree.cpp
  - data-structure/segtree/sortable_segment_tree.hpp
  - math/modint.cpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_sort_range_composite.test.cpp
  requiredBy: []
  timestamp: '2023-06-13 22:58:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_sort_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_sort_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_sort_range_composite.test.cpp.html
title: test/yosupo/point_set_range_sort_range_composite.test.cpp
---
