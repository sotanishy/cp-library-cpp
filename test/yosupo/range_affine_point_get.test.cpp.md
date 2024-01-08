---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/dual_segment_tree.hpp
    title: Dual Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/yosupo/range_affine_point_get.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n#include <bits/stdc++.h>\n\
    \n#line 2 \"data-structure/segtree/dual_segment_tree.hpp\"\n#include <bit>\n#line\
    \ 4 \"data-structure/segtree/dual_segment_tree.hpp\"\n\ntemplate <typename M>\n\
    class DualSegmentTree {\n    using T = typename M::T;\n\n   public:\n    DualSegmentTree()\
    \ = default;\n    explicit DualSegmentTree(int n)\n        : size(std::bit_ceil((unsigned\
    \ int)n)),\n          height(std::bit_width((unsigned int)size) - 1),\n      \
    \    lazy(2 * size, M::id()) {}\n\n    T operator[](int k) {\n        k += size;\n\
    \        propagate(k);\n        return lazy[k];\n    }\n\n    void update(int\
    \ l, int r, const T& x) {\n        l += size;\n        r += size;\n        propagate(l);\n\
    \        propagate(r - 1);\n        for (; l < r; l >>= 1, r >>= 1) {\n      \
    \      if (l & 1) lazy[l] = M::op(lazy[l], x), ++l;\n            if (r & 1) --r,\
    \ lazy[r] = M::op(lazy[r], x);\n        }\n    }\n\n   private:\n    int size,\
    \ height;\n    std::vector<T> lazy;\n\n    void push(int k) {\n        if (lazy[k]\
    \ == M::id()) return;\n        lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);\n  \
    \      lazy[2 * k + 1] = M::op(lazy[2 * k + 1], lazy[k]);\n        lazy[k] = M::id();\n\
    \    }\n\n    void propagate(int k) {\n        for (int i = height; i > 0; --i)\
    \ push(k >> i);\n    }\n};\n#line 4 \"math/modint.hpp\"\n\n/**\n * @brief Mod\
    \ int\n */\ntemplate <int m>\nclass Modint {\n    using mint = Modint;\n    static_assert(m\
    \ > 0, \"Modulus must be positive\");\n\n   public:\n    static constexpr int\
    \ mod() { return m; }\n\n    constexpr Modint(long long y = 0) : x(y >= 0 ? y\
    \ % m : (y % m + m) % m) {}\n\n    constexpr int val() const { return x; }\n\n\
    \    constexpr mint& operator+=(const mint& r) {\n        if ((x += r.x) >= m)\
    \ x -= m;\n        return *this;\n    }\n    constexpr mint& operator-=(const\
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
    \    }\n\n   private:\n    int x;\n};\n#line 7 \"test/yosupo/range_affine_point_get.test.cpp\"\
    \nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nstruct AffineMonoid\
    \ {\n    using T = std::pair<mint, mint>;\n    static T id() { return {1, 0};\
    \ }\n    static T op(T a, T b) {\n        return {a.first * b.first, a.second\
    \ * b.first + b.second};\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<mint> a(N);\n\
    \    for (auto& x : a) cin >> x;\n    DualSegmentTree<AffineMonoid> st(N);\n \
    \   for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n       \
    \ if (t == 0) {\n            int l, r, b, c;\n            cin >> l >> r >> b >>\
    \ c;\n            st.update(l, r, {b, c});\n        } else {\n            int\
    \ i;\n            cin >> i;\n            auto f = st[i];\n            cout <<\
    \ (f.first * a[i] + f.second) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/segtree/dual_segment_tree.hpp\"\
    \n#include \"../../math/modint.hpp\"\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct AffineMonoid {\n    using T = std::pair<mint, mint>;\n    static T id()\
    \ { return {1, 0}; }\n    static T op(T a, T b) {\n        return {a.first * b.first,\
    \ a.second * b.first + b.second};\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<mint> a(N);\n\
    \    for (auto& x : a) cin >> x;\n    DualSegmentTree<AffineMonoid> st(N);\n \
    \   for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n       \
    \ if (t == 0) {\n            int l, r, b, c;\n            cin >> l >> r >> b >>\
    \ c;\n            st.update(l, r, {b, c});\n        } else {\n            int\
    \ i;\n            cin >> i;\n            auto f = st[i];\n            cout <<\
    \ (f.first * a[i] + f.second) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/dual_segment_tree.hpp
  - math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_point_get.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_point_get.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_point_get.test.cpp
- /verify/test/yosupo/range_affine_point_get.test.cpp.html
title: test/yosupo/range_affine_point_get.test.cpp
---
