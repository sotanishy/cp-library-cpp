---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segtree/dual_segment_tree.hpp
    title: Dual Segment Tree
  - icon: ':x:'
    path: data-structure/segtree/dual_segment_tree_2d.hpp
    title: 2D Dual Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_add_point_get
    links:
    - https://judge.yosupo.jp/problem/rectangle_add_point_get
  bundledCode: "#line 1 \"test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\n\
    \n#include <bits/stdc++.h>\n\n#line 3 \"data-structure/segtree/dual_segment_tree_2d.hpp\"\
    \n#include <bit>\n#line 7 \"data-structure/segtree/dual_segment_tree_2d.hpp\"\n\
    \n#line 4 \"data-structure/segtree/dual_segment_tree.hpp\"\n\ntemplate <typename\
    \ M>\nclass DualSegmentTree {\n    using T = typename M::T;\n\n   public:\n  \
    \  DualSegmentTree() = default;\n    explicit DualSegmentTree(int n)\n       \
    \ : size(std::bit_ceil((unsigned int)n)),\n          height(std::bit_width((unsigned\
    \ int)size) - 1),\n          lazy(2 * size, M::id()) {}\n\n    T operator[](int\
    \ k) {\n        k += size;\n        propagate(k);\n        return lazy[k];\n \
    \   }\n\n    void update(int l, int r, const T& x) {\n        if (l >= r) return;\n\
    \        l += size;\n        r += size;\n        propagate(l);\n        propagate(r\
    \ - 1);\n        for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) lazy[l]\
    \ = M::op(lazy[l], x), ++l;\n            if (r & 1) --r, lazy[r] = M::op(lazy[r],\
    \ x);\n        }\n    }\n\n   private:\n    int size, height;\n    std::vector<T>\
    \ lazy;\n\n    void push(int k) {\n        if (lazy[k] == M::id()) return;\n \
    \       lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);\n        lazy[2 * k + 1] =\
    \ M::op(lazy[2 * k + 1], lazy[k]);\n        lazy[k] = M::id();\n    }\n\n    void\
    \ propagate(int k) {\n        for (int i = height; i > 0; --i) push(k >> i);\n\
    \    }\n};\n#line 9 \"data-structure/segtree/dual_segment_tree_2d.hpp\"\n\n/**\n\
    \ * @brief 2D Dual Segment Tree\n */\ntemplate <typename X, typename Y, typename\
    \ M>\nclass DualSegmentTree2D {\n    using T = M::T;\n\n   public:\n    DualSegmentTree2D()\
    \ = default;\n    explicit DualSegmentTree2D(const std::vector<std::pair<X, Y>>&\
    \ pts) {\n        for (auto& [x, y] : pts) {\n            xs.push_back(x);\n \
    \       }\n        std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n\n        const int n = xs.size();\n        size = std::bit_ceil((unsigned\
    \ int)n);\n        ys.resize(2 * size);\n        seg.resize(2 * size);\n\n   \
    \     for (auto& [x, y] : pts) {\n            ys[size + getx(x)].push_back(y);\n\
    \        }\n\n        for (int i = size + n - 1; i > 0; --i) {\n            if\
    \ (i >= size) {\n                std::ranges::sort(ys[i]);\n            } else\
    \ {\n                std::ranges::merge(ys[2 * i], ys[2 * i + 1],\n          \
    \                         std::back_inserter(ys[i]));\n            }\n       \
    \     ys[i].erase(std::ranges::unique(ys[i]).begin(), ys[i].end());\n        }\n\
    \        for (int i = 1; i < size + n; ++i) {\n            seg[i] = DualSegmentTree<M>(ys[i].size());\n\
    \        }\n    }\n\n    T get(X x, Y y) {\n        int kx = getx(x);\n      \
    \  assert(kx < (int)xs.size() && xs[kx] == x);\n        T ret = M::id();\n   \
    \     for (kx += size; kx > 0; kx >>= 1) {\n            int ky = gety(kx, y);\n\
    \            assert(ky < (int)ys[kx].size() && ys[kx][ky] == y);\n           \
    \ ret = M::op(ret, seg[kx][ky]);\n        }\n        return ret;\n    }\n\n  \
    \  void update(X sx, X tx, Y sy, Y ty, T val) {\n        for (int l = size + getx(sx),\
    \ r = size + getx(tx); l < r;\n             l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) {\n                seg[l].update(gety(l, sy), gety(l, ty), val);\n \
    \               ++l;\n            }\n            if (r & 1) {\n              \
    \  --r;\n                seg[r].update(gety(r, sy), gety(r, ty), val);\n     \
    \       }\n        }\n    }\n\n   private:\n    int size;\n    std::vector<X>\
    \ xs;\n    std::vector<std::vector<Y>> ys;\n    std::vector<DualSegmentTree<M>>\
    \ seg;\n\n    int getx(X x) const { return std::ranges::lower_bound(xs, x) - xs.begin();\
    \ }\n    int gety(int k, Y y) const {\n        return std::ranges::lower_bound(ys[k],\
    \ y) - ys[k].begin();\n    }\n};\n#line 6 \"test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\n\nstruct AddMonoid {\n    using\
    \ T = ll;\n    static T id() { return 0; }\n    static T op(T a, T b) { return\
    \ a + b; }\n};\n\nstruct Query {\n    int t, x, y, l, d, r, u, w;\n    Query(int\
    \ t, int l, int d, int r, int u, int w)\n        : t(t), l(l), d(d), r(r), u(u),\
    \ w(w) {}\n    Query(int t, int x, int y) : t(t), x(x), y(y) {}\n};\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<int> l(N), d(N), r(N), u(N), w(N);\n    for\
    \ (int i = 0; i < N; ++i) {\n        cin >> l[i] >> d[i] >> r[i] >> u[i] >> w[i];\n\
    \    }\n    vector<pair<int, int>> pts;\n    vector<Query> queries;\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            int l, d, r, u, w;\n            cin >> l >> d >> r >> u >> w;\n\
    \            queries.emplace_back(t, l, d, r, u, w);\n        } else {\n     \
    \       int x, y;\n            cin >> x >> y;\n            pts.push_back({x, y});\n\
    \            queries.emplace_back(t, x, y);\n        }\n    }\n    DualSegmentTree2D<int,\
    \ int, AddMonoid> st(pts);\n    for (int i = 0; i < N; ++i) {\n        st.update(l[i],\
    \ r[i], d[i], u[i], w[i]);\n    }\n\n    for (auto& q : queries) {\n        if\
    \ (q.t == 0) {\n            st.update(q.l, q.r, q.d, q.u, q.w);\n        } else\
    \ {\n            cout << st.get(q.x, q.y) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_add_point_get\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/segtree/dual_segment_tree_2d.hpp\"\
    \nusing namespace std;\nusing ll = long long;\n\n\nstruct AddMonoid {\n    using\
    \ T = ll;\n    static T id() { return 0; }\n    static T op(T a, T b) { return\
    \ a + b; }\n};\n\nstruct Query {\n    int t, x, y, l, d, r, u, w;\n    Query(int\
    \ t, int l, int d, int r, int u, int w)\n        : t(t), l(l), d(d), r(r), u(u),\
    \ w(w) {}\n    Query(int t, int x, int y) : t(t), x(x), y(y) {}\n};\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<int> l(N), d(N), r(N), u(N), w(N);\n    for\
    \ (int i = 0; i < N; ++i) {\n        cin >> l[i] >> d[i] >> r[i] >> u[i] >> w[i];\n\
    \    }\n    vector<pair<int, int>> pts;\n    vector<Query> queries;\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            int l, d, r, u, w;\n            cin >> l >> d >> r >> u >> w;\n\
    \            queries.emplace_back(t, l, d, r, u, w);\n        } else {\n     \
    \       int x, y;\n            cin >> x >> y;\n            pts.push_back({x, y});\n\
    \            queries.emplace_back(t, x, y);\n        }\n    }\n    DualSegmentTree2D<int,\
    \ int, AddMonoid> st(pts);\n    for (int i = 0; i < N; ++i) {\n        st.update(l[i],\
    \ r[i], d[i], u[i], w[i]);\n    }\n\n    for (auto& q : queries) {\n        if\
    \ (q.t == 0) {\n            st.update(q.l, q.r, q.d, q.u, q.w);\n        } else\
    \ {\n            cout << st.get(q.x, q.y) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/dual_segment_tree_2d.hpp
  - data-structure/segtree/dual_segment_tree.hpp
  isVerificationFile: true
  path: test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
  requiredBy: []
  timestamp: '2024-03-02 20:34:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
- /verify/test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp.html
title: test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
---
