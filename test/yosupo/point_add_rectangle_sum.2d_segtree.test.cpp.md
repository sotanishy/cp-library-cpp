---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree.cpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree_2d.hpp
    title: 2D Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#line 2 \"data-structure/segtree/segment_tree_2d.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n#line 4 \"data-structure/segtree/segment_tree.cpp\"\
    \n\ntemplate <typename M>\nclass SegmentTree {\n    using T = typename M::T;\n\
    \npublic:\n    SegmentTree() = default;\n    explicit SegmentTree(int n): SegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    explicit SegmentTree(const std::vector<T>& v) {\n        size\
    \ = 1;\n        while (size < (int) v.size()) size <<= 1;\n        node.resize(2\
    \ * size, M::id());\n        std::copy(v.begin(), v.end(), node.begin() + size);\n\
    \        for (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2\
    \ * i + 1]);\n    }\n\n    T operator[](int k) const {\n        return node[k\
    \ + size];\n    }\n\n    void update(int k, const T& x) {\n        k += size;\n\
    \        node[k] = x;\n        while (k >>= 1) node[k] = M::op(node[2 * k], node[2\
    \ * k + 1]);\n    }\n\n    T fold(int l, int r) const {\n        T vl = M::id(),\
    \ vr = M::id();\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) vl = M::op(vl, node[l++]);\n            if (r & 1) vr\
    \ = M::op(node[--r], vr);\n        }\n        return M::op(vl, vr);\n    }\n\n\
    \    template <typename F>\n    int find_first(int l, F cond) const {\n      \
    \  T vl = M::id();\n        int r = size;\n        for (l += size, r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n                T nxt\
    \ = M::op(vl, node[l]);\n                if (cond(nxt)) {\n                  \
    \  while (l < size) {\n                        nxt = M::op(vl, node[2 * l]);\n\
    \                        if (cond(nxt)) l = 2 * l;\n                        else\
    \ vl = nxt, l = 2 * l + 1;\n                    }\n                    return\
    \ l - size;\n                }\n                vl = nxt;\n                ++l;\n\
    \            }\n        }\n        return -1;\n    }\n\n    template <typename\
    \ F>\n    int find_last(int r, F cond) const {\n        T vr = M::id();\n    \
    \    int l = 0;\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n\
    \            if (r & 1) {\n                --r;\n                T nxt = M::op(node[r],\
    \ vr);\n                if (cond(nxt)) {\n                    while (r < size)\
    \ {\n                        nxt = M::op(node[2 * r + 1], vr);\n             \
    \           if (cond(nxt)) r = 2 * r + 1;\n                        else vr = nxt,\
    \ r = 2 * r;\n                    }\n                    return r - size;\n  \
    \              }\n                vr = nxt;\n            }\n        }\n      \
    \  return -1;\n    }\n\nprivate:\n    int size;\n    std::vector<T> node;\n};\n\
    #line 7 \"data-structure/segtree/segment_tree_2d.hpp\"\n\ntemplate <typename X,\
    \ typename Y, typename M>\nclass SegmentTree2D {\n    using T = typename M::T;\n\
    \npublic:\n    SegmentTree2D() = default;\n    explicit SegmentTree2D(const std::vector<std::pair<X,\
    \ Y>>& pts) {\n        for (auto& [x, y] : pts) {\n            xs.push_back(x);\n\
    \        }\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n\n        const int n = xs.size();\n        size = 1;\n\
    \        while (size < n) size <<= 1;\n        ys.resize(2 * size);\n        seg.resize(2\
    \ * size);\n\n        for (auto& [x, y] : pts) {\n            ys[size + getx(x)].push_back(y);\n\
    \        }\n\n        for (int i = 0; i < n; ++i) {\n            std::sort(ys[size\
    \ + i].begin(), ys[size + i].end());\n            ys[size + i].erase(std::unique(ys[size\
    \ + i].begin(), ys[size + i].end()), ys[size + i].end());\n        }\n       \
    \ for (int i = size - 1; i > 0; --i) {\n            std::merge(ys[2*i].begin(),\
    \ ys[2*i].end(), ys[2*i+1].begin(), ys[2*i+1].end(), std::back_inserter(ys[i]));\n\
    \            ys[i].erase(std::unique(ys[i].begin(), ys[i].end()), ys[i].end());\n\
    \        }\n        for (int i = 0; i < size + n; ++i) {\n            seg[i] =\
    \ SegmentTree<M>(ys[i].size());\n        }\n    }\n\n    T get(X x, Y y) const\
    \ {\n        int kx = getx(x);\n        assert(kx < (int) xs.size() && xs[kx]\
    \ == x);\n        kx += size;\n        int ky = gety(kx, y);\n        assert(ky\
    \ < (int) ys[kx].size() && ys[kx][ky] == y);\n        return seg[kx][ky];\n  \
    \  }\n\n    void update(X x, Y y, T val) {\n        int kx = getx(x);\n      \
    \  assert(kx < (int) xs.size() && xs[kx] == x);\n        kx += size;\n       \
    \ int ky = gety(kx, y);\n        assert(ky < (int) ys[kx].size() && ys[kx][ky]\
    \ == y);\n        seg[kx].update(ky, val);\n        while (kx >>= 1) {\n     \
    \       ky = gety(kx, y);\n            int kl = gety(2*kx, y), kr = gety(2*kx+1,\
    \ y);\n            T vl = (kl < (int) ys[2*kx].size() && ys[2*kx][kl] == y ? seg[2*kx][kl]\
    \ : M::id());\n            T vr = (kr < (int) ys[2*kx+1].size() && ys[2*kx+1][kr]\
    \ == y ? seg[2*kx+1][kr] : M::id());\n            seg[kx].update(ky, M::op(vl,\
    \ vr));\n        }\n    }\n\n    T fold(X sx, X tx, Y sy, Y ty) const {\n    \
    \    T ret = M::id();\n        for (int l = size + getx(sx), r = size + getx(tx);\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n                ret =\
    \ M::op(ret, seg[l].fold(gety(l, sy), gety(l, ty)));\n                ++l;\n \
    \           }\n            if (r & 1) {\n                --r;\n              \
    \  ret = M::op(ret, seg[r].fold(gety(r, sy), gety(r, ty)));\n            }\n \
    \       }\n        return ret;\n    }\n\nprivate:\n    int size;\n    std::vector<X>\
    \ xs;\n    std::vector<std::vector<Y>> ys;\n    std::vector<SegmentTree<M>> seg;\n\
    \n    int getx(X x) const { return std::lower_bound(xs.begin(), xs.end(), x) -\
    \ xs.begin(); }\n    int gety(int k, Y y) const { return std::lower_bound(ys[k].begin(),\
    \ ys[k].end(), y) - ys[k].begin(); }\n};\n#line 4 \"test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    struct AddMonoid {\n    using T = ll;\n    static T id() { return 0; }\n    static\
    \ T op(T a, T b) { return a + b; }\n};\n\nstruct Query {\n    int t, x, y, w,\
    \ l, d, r, u;\n    Query(int t, int x, int y, int w) : t(t), x(x), y(y), w(w)\
    \ {}\n    Query(int t, int l, int d, int r, int u) : t(t), l(l), d(d), r(r), u(u)\
    \ {}\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<int> x(N), y(N), w(N);\n    vector<pair<int,\
    \ int>> pts;\n    for (int i = 0; i < N; ++i) {\n        cin >> x[i] >> y[i] >>\
    \ w[i];\n        pts.push_back({x[i], y[i]});\n    }\n    vector<Query> queries;\n\
    \    for (int i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n      \
    \  if (t == 0) {\n            int x, y, w;\n            cin >> x >> y >> w;\n\
    \            queries.emplace_back(t, x, y, w);\n            pts.push_back({x,\
    \ y});\n        } else {\n            int l, d, r, u;\n            cin >> l >>\
    \ d >> r >> u;\n            queries.emplace_back(t, l, d, r, u);\n        }\n\
    \    }\n    SegmentTree2D<int, int, AddMonoid> st(pts);\n    for (int i = 0; i\
    \ < N; ++i) {\n        st.update(x[i], y[i], st.get(x[i], y[i]) + w[i]);\n   \
    \ }\n\n    for (auto& q : queries) {\n        if (q.t == 0) {\n            st.update(q.x,\
    \ q.y, st.get(q.x, q.y) + q.w);\n        } else {\n            cout << st.fold(q.l,\
    \ q.r, q.d, q.u) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../data-structure/segtree/segment_tree_2d.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\nstruct AddMonoid\
    \ {\n    using T = ll;\n    static T id() { return 0; }\n    static T op(T a,\
    \ T b) { return a + b; }\n};\n\nstruct Query {\n    int t, x, y, w, l, d, r, u;\n\
    \    Query(int t, int x, int y, int w) : t(t), x(x), y(y), w(w) {}\n    Query(int\
    \ t, int l, int d, int r, int u) : t(t), l(l), d(d), r(r), u(u) {}\n};\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int N, Q;\n    cin >> N >> Q;\n    vector<int> x(N), y(N), w(N);\n    vector<pair<int,\
    \ int>> pts;\n    for (int i = 0; i < N; ++i) {\n        cin >> x[i] >> y[i] >>\
    \ w[i];\n        pts.push_back({x[i], y[i]});\n    }\n    vector<Query> queries;\n\
    \    for (int i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n      \
    \  if (t == 0) {\n            int x, y, w;\n            cin >> x >> y >> w;\n\
    \            queries.emplace_back(t, x, y, w);\n            pts.push_back({x,\
    \ y});\n        } else {\n            int l, d, r, u;\n            cin >> l >>\
    \ d >> r >> u;\n            queries.emplace_back(t, l, d, r, u);\n        }\n\
    \    }\n    SegmentTree2D<int, int, AddMonoid> st(pts);\n    for (int i = 0; i\
    \ < N; ++i) {\n        st.update(x[i], y[i], st.get(x[i], y[i]) + w[i]);\n   \
    \ }\n\n    for (auto& q : queries) {\n        if (q.t == 0) {\n            st.update(q.x,\
    \ q.y, st.get(q.x, q.y) + q.w);\n        } else {\n            cout << st.fold(q.l,\
    \ q.r, q.d, q.u) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/segment_tree_2d.hpp
  - data-structure/segtree/segment_tree.cpp
  isVerificationFile: true
  path: test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
  requiredBy: []
  timestamp: '2022-12-25 16:38:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
- /verify/test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp.html
title: test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
---
