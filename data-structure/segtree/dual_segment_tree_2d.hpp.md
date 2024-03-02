---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segtree/dual_segment_tree.hpp
    title: Dual Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
    title: test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: 2D Dual Segment Tree
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/dual_segment_tree_2d.hpp\"\n#include\
    \ <algorithm>\n#include <bit>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\n#line 4 \"data-structure/segtree/dual_segment_tree.hpp\"\n\ntemplate\
    \ <typename M>\nclass DualSegmentTree {\n    using T = typename M::T;\n\n   public:\n\
    \    DualSegmentTree() = default;\n    explicit DualSegmentTree(int n)\n     \
    \   : size(std::bit_ceil((unsigned int)n)),\n          height(std::bit_width((unsigned\
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
    \ y) - ys[k].begin();\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n#include \"dual_segment_tree.hpp\"\n\n\
    /**\n * @brief 2D Dual Segment Tree\n */\ntemplate <typename X, typename Y, typename\
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
    \ y) - ys[k].begin();\n    }\n};\n"
  dependsOn:
  - data-structure/segtree/dual_segment_tree.hpp
  isVerificationFile: false
  path: data-structure/segtree/dual_segment_tree_2d.hpp
  requiredBy: []
  timestamp: '2024-03-02 20:34:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
documentation_of: data-structure/segtree/dual_segment_tree_2d.hpp
layout: document
redirect_from:
- /library/data-structure/segtree/dual_segment_tree_2d.hpp
- /library/data-structure/segtree/dual_segment_tree_2d.hpp.html
title: 2D Dual Segment Tree
---
