---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/lazy_segment_tree.hpp
    title: Segment Tree with Lazy Propagation
  - icon: ':question:'
    path: math/modint.hpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#include <bits/stdc++.h>\n\
    \n#line 3 \"data-structure/segtree/lazy_segment_tree.hpp\"\n#include <bit>\n#line\
    \ 6 \"data-structure/segtree/lazy_segment_tree.hpp\"\n\ntemplate <typename M,\
    \ typename O,\n          typename M::T (*act)(typename M::T, typename O::T)>\n\
    class LazySegmentTree {\n    using T = M::T;\n    using E = O::T;\n\n   public:\n\
    \    LazySegmentTree() = default;\n    explicit LazySegmentTree(int n)\n     \
    \   : LazySegmentTree(std::vector<T>(n, M::id())) {}\n    explicit LazySegmentTree(const\
    \ std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\n          node(2\
    \ * size, M::id()),\n          lazy(2 * size, O::id()) {\n        std::ranges::copy(v,\
    \ node.begin() + size);\n        for (int i = size - 1; i > 0; --i) {\n      \
    \      node[i] = M::op(node[2 * i], node[2 * i + 1]);\n        }\n    }\n\n  \
    \  T operator[](int k) { return fold(k, k + 1); }\n\n    void update(int l, int\
    \ r, const E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int l, int r)\
    \ { return fold(l, r, 1, 0, size); }\n\n    template <typename F>\n    int find_first(int\
    \ l, F cond) {\n        T v = M::id();\n        return find_first(l, size, 1,\
    \ 0, size, v, cond);\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) {\n        T v = M::id();\n        return find_last(0, r, 1, 0, size,\
    \ v, cond);\n    }\n\n   private:\n    int size;\n    std::vector<T> node;\n \
    \   std::vector<E> lazy;\n\n    void push(int k) {\n        if (lazy[k] == O::id())\
    \ return;\n        if (k < size) {\n            lazy[2 * k] = O::op(lazy[2 * k],\
    \ lazy[k]);\n            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n\
    \        }\n        node[k] = act(node[k], lazy[k]);\n        lazy[k] = O::id();\n\
    \    }\n\n    void update(int a, int b, const E& x, int k, int l, int r) {\n \
    \       push(k);\n        if (r <= a || b <= l) return;\n        if (a <= l &&\
    \ r <= b) {\n            lazy[k] = O::op(lazy[k], x);\n            push(k);\n\
    \            return;\n        }\n        int m = std::midpoint(l, r);\n      \
    \  update(a, b, x, 2 * k, l, m);\n        update(a, b, x, 2 * k + 1, m, r);\n\
    \        node[k] = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n    T fold(int\
    \ a, int b, int k, int l, int r) {\n        push(k);\n        if (r <= a || b\
    \ <= l) return M::id();\n        if (a <= l && r <= b) return node[k];\n     \
    \   int m = std::midpoint(l, r);\n        return M::op(fold(a, b, 2 * k, l, m),\
    \ fold(a, b, 2 * k + 1, m, r));\n    }\n\n    template <typename F>\n    int find_first(int\
    \ a, int b, int k, int l, int r, T& v, F cond) {\n        push(k);\n        if\
    \ (r <= a) return -1;\n        if (b <= l) return l;\n        if (a <= l && r\
    \ <= b && !cond(M::op(v, node[k]))) {\n            v = M::op(v, node[k]);\n  \
    \          return -1;\n        }\n        if (r - l == 1) return r;\n        int\
    \ m = std::midpoint(l, r);\n        int res = find_first(a, b, 2 * k, l, m, v,\
    \ cond);\n        if (res != -1) return res;\n        return find_first(a, b,\
    \ 2 * k + 1, m, r, v, cond);\n    }\n\n    template <typename F>\n    int find_last(int\
    \ a, int b, int k, int l, int r, T& v, F cond) {\n        push(k);\n        if\
    \ (b <= l) return -1;\n        if (r <= a) return r;\n        if (a <= l && r\
    \ <= b && !cond(M::op(node[k], v))) {\n            v = M::op(node[k], v);\n  \
    \          return -1;\n        }\n        if (r - l == 1) return l;\n        int\
    \ m = std::midpoint(l, r);\n        int res = find_last(a, b, 2 * k + 1, m, r,\
    \ v, cond);\n        if (res != -1) return res;\n        return find_last(a, b,\
    \ 2 * k, l, m, v, cond);\n    }\n};\n#line 4 \"math/modint.hpp\"\n\n/**\n * @brief\
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
    \    }\n\n   private:\n    int x;\n};\n#line 7 \"test/yosupo/range_affine_range_sum.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nstruct M {\n    using\
    \ T = pair<mint, mint>;\n    static T id() { return {0, 0}; }\n    static T op(T\
    \ a, T b) { return {a.first + b.first, a.second + b.second}; }\n};\n\nstruct O\
    \ {\n    using T = pair<mint, mint>;\n    static T id() { return {1, 0}; }\n \
    \   static T op(T a, T b) {\n        return {a.first * b.first, a.second * b.first\
    \ + b.second};\n    }\n};\n\nM::T act(M::T a, O::T b) {\n    return {a.first *\
    \ b.first + a.second * b.second, a.second};\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<pair<mint, mint>>\
    \ a(N, {0, 1});\n    for (int i = 0; i < N; i++) cin >> a[i].first;\n    LazySegmentTree<M,\
    \ O, act> st(a);\n    for (int i = 0; i < Q; i++) {\n        int t;\n        cin\
    \ >> t;\n        if (t == 0) {\n            int l, r, b, c;\n            cin >>\
    \ l >> r >> b >> c;\n            st.update(l, r, {b, c});\n        } else {\n\
    \            int l, r;\n            cin >> l >> r;\n            cout << st.fold(l,\
    \ r).first << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/segtree/lazy_segment_tree.hpp\"\
    \n#include \"../../math/modint.hpp\"\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct M {\n    using T = pair<mint, mint>;\n    static T id() { return {0,\
    \ 0}; }\n    static T op(T a, T b) { return {a.first + b.first, a.second + b.second};\
    \ }\n};\n\nstruct O {\n    using T = pair<mint, mint>;\n    static T id() { return\
    \ {1, 0}; }\n    static T op(T a, T b) {\n        return {a.first * b.first, a.second\
    \ * b.first + b.second};\n    }\n};\n\nM::T act(M::T a, O::T b) {\n    return\
    \ {a.first * b.first + a.second * b.second, a.second};\n}\n\nint main() {\n  \
    \  ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int N, Q;\n    cin\
    \ >> N >> Q;\n    vector<pair<mint, mint>> a(N, {0, 1});\n    for (int i = 0;\
    \ i < N; i++) cin >> a[i].first;\n    LazySegmentTree<M, O, act> st(a);\n    for\
    \ (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n        if (t\
    \ == 0) {\n            int l, r, b, c;\n            cin >> l >> r >> b >> c;\n\
    \            st.update(l, r, {b, c});\n        } else {\n            int l, r;\n\
    \            cin >> l >> r;\n            cout << st.fold(l, r).first << \"\\n\"\
    ;\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/lazy_segment_tree.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
