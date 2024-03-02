---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
    title: test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/segment_tree_2d.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <cassert>\n#include <utility>\n#include <vector>\n\n\
    #line 5 \"data-structure/segtree/segment_tree.hpp\"\n\ntemplate <typename M>\n\
    class SegmentTree {\n    using T = M::T;\n\n   public:\n    SegmentTree() = default;\n\
    \    explicit SegmentTree(int n) : SegmentTree(std::vector<T>(n, M::id())) {}\n\
    \    explicit SegmentTree(const std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\
    \ node(2 * size, M::id()) {\n        std::ranges::copy(v, node.begin() + size);\n\
    \        for (int i = size - 1; i > 0; --i) {\n            node[i] = M::op(node[2\
    \ * i], node[2 * i + 1]);\n        }\n    }\n\n    T operator[](int k) const {\
    \ return node[k + size]; }\n\n    void update(int k, const T& x) {\n        k\
    \ += size;\n        node[k] = x;\n        while (k >>= 1) node[k] = M::op(node[2\
    \ * k], node[2 * k + 1]);\n    }\n\n    T fold(int l, int r) const {\n       \
    \ T vl = M::id(), vr = M::id();\n        for (l += size, r += size; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) vl = M::op(vl, node[l++]);\n         \
    \   if (r & 1) vr = M::op(node[--r], vr);\n        }\n        return M::op(vl,\
    \ vr);\n    }\n\n    template <typename F>\n    int find_first(int l, F cond)\
    \ const {\n        T v = M::id();\n        for (l += size; l > 0; l >>= 1) {\n\
    \            if (l & 1) {\n                T nv = M::op(v, node[l]);\n       \
    \         if (cond(nv)) {\n                    while (l < size) {\n          \
    \              nv = M::op(v, node[2 * l]);\n                        if (cond(nv))\
    \ {\n                            l = 2 * l;\n                        } else {\n\
    \                            v = nv, l = 2 * l + 1;\n                        }\n\
    \                    }\n                    return l + 1 - size;\n           \
    \     }\n                v = nv;\n                ++l;\n            }\n      \
    \  }\n        return -1;\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) const {\n        T v = M::id();\n        for (r += size; r > 0; r\
    \ >>= 1) {\n            if (r & 1) {\n                --r;\n                T\
    \ nv = M::op(node[r], v);\n                if (cond(nv)) {\n                 \
    \   while (r < size) {\n                        nv = M::op(node[2 * r + 1], v);\n\
    \                        if (cond(nv)) {\n                            r = 2 *\
    \ r + 1;\n                        } else {\n                            v = nv,\
    \ r = 2 * r;\n                        }\n                    }\n             \
    \       return r - size;\n                }\n                v = nv;\n       \
    \     }\n        }\n        return -1;\n    }\n\n   private:\n    int size;\n\
    \    std::vector<T> node;\n};\n#line 9 \"data-structure/segtree/segment_tree_2d.hpp\"\
    \n\ntemplate <typename X, typename Y, typename M>\nclass SegmentTree2D {\n   \
    \ using T = M::T;\n\n   public:\n    SegmentTree2D() = default;\n    explicit\
    \ SegmentTree2D(const std::vector<std::pair<X, Y>>& pts) {\n        for (auto&\
    \ [x, y] : pts) {\n            xs.push_back(x);\n        }\n        std::ranges::sort(xs);\n\
    \        xs.erase(std::ranges::unique(xs).begin(), xs.end());\n\n        const\
    \ int n = xs.size();\n        size = std::bit_ceil((unsigned int)n);\n       \
    \ ys.resize(2 * size);\n        seg.resize(2 * size);\n\n        for (auto& [x,\
    \ y] : pts) {\n            ys[size + getx(x)].push_back(y);\n        }\n\n   \
    \     for (int i = size + n - 1; i > 0; --i) {\n            if (i >= size) {\n\
    \                std::ranges::sort(ys[i]);\n            } else {\n           \
    \     std::ranges::merge(ys[2 * i], ys[2 * i + 1],\n                         \
    \          std::back_inserter(ys[i]));\n            }\n            ys[i].erase(std::ranges::unique(ys[i]).begin(),\
    \ ys[i].end());\n        }\n        for (int i = 1; i < size + n; ++i) {\n   \
    \         seg[i] = SegmentTree<M>(ys[i].size());\n        }\n    }\n\n    T get(X\
    \ x, Y y) const {\n        int kx = getx(x);\n        assert(kx < (int)xs.size()\
    \ && xs[kx] == x);\n        kx += size;\n        int ky = gety(kx, y);\n     \
    \   assert(ky < (int)ys[kx].size() && ys[kx][ky] == y);\n        return seg[kx][ky];\n\
    \    }\n\n    void update(X x, Y y, T val) {\n        int kx = getx(x);\n    \
    \    assert(kx < (int)xs.size() && xs[kx] == x);\n        kx += size;\n      \
    \  int ky = gety(kx, y);\n        assert(ky < (int)ys[kx].size() && ys[kx][ky]\
    \ == y);\n        seg[kx].update(ky, val);\n        while (kx >>= 1) {\n     \
    \       ky = gety(kx, y);\n            int kl = gety(2 * kx, y), kr = gety(2 *\
    \ kx + 1, y);\n            T vl = (kl < (int)ys[2 * kx].size() && ys[2 * kx][kl]\
    \ == y\n                        ? seg[2 * kx][kl]\n                        : M::id());\n\
    \            T vr = (kr < (int)ys[2 * kx + 1].size() && ys[2 * kx + 1][kr] ==\
    \ y\n                        ? seg[2 * kx + 1][kr]\n                        :\
    \ M::id());\n            seg[kx].update(ky, M::op(vl, vr));\n        }\n    }\n\
    \n    T fold(X sx, X tx, Y sy, Y ty) const {\n        T ret = M::id();\n     \
    \   for (int l = size + getx(sx), r = size + getx(tx); l < r;\n             l\
    \ >>= 1, r >>= 1) {\n            if (l & 1) {\n                ret = M::op(ret,\
    \ seg[l].fold(gety(l, sy), gety(l, ty)));\n                ++l;\n            }\n\
    \            if (r & 1) {\n                --r;\n                ret = M::op(ret,\
    \ seg[r].fold(gety(r, sy), gety(r, ty)));\n            }\n        }\n        return\
    \ ret;\n    }\n\n   private:\n    int size;\n    std::vector<X> xs;\n    std::vector<std::vector<Y>>\
    \ ys;\n    std::vector<SegmentTree<M>> seg;\n\n    int getx(X x) const { return\
    \ std::ranges::lower_bound(xs, x) - xs.begin(); }\n    int gety(int k, Y y) const\
    \ {\n        return std::ranges::lower_bound(ys[k], y) - ys[k].begin();\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n#include \"segment_tree.hpp\"\n\ntemplate\
    \ <typename X, typename Y, typename M>\nclass SegmentTree2D {\n    using T = M::T;\n\
    \n   public:\n    SegmentTree2D() = default;\n    explicit SegmentTree2D(const\
    \ std::vector<std::pair<X, Y>>& pts) {\n        for (auto& [x, y] : pts) {\n \
    \           xs.push_back(x);\n        }\n        std::ranges::sort(xs);\n    \
    \    xs.erase(std::ranges::unique(xs).begin(), xs.end());\n\n        const int\
    \ n = xs.size();\n        size = std::bit_ceil((unsigned int)n);\n        ys.resize(2\
    \ * size);\n        seg.resize(2 * size);\n\n        for (auto& [x, y] : pts)\
    \ {\n            ys[size + getx(x)].push_back(y);\n        }\n\n        for (int\
    \ i = size + n - 1; i > 0; --i) {\n            if (i >= size) {\n            \
    \    std::ranges::sort(ys[i]);\n            } else {\n                std::ranges::merge(ys[2\
    \ * i], ys[2 * i + 1],\n                                   std::back_inserter(ys[i]));\n\
    \            }\n            ys[i].erase(std::ranges::unique(ys[i]).begin(), ys[i].end());\n\
    \        }\n        for (int i = 1; i < size + n; ++i) {\n            seg[i] =\
    \ SegmentTree<M>(ys[i].size());\n        }\n    }\n\n    T get(X x, Y y) const\
    \ {\n        int kx = getx(x);\n        assert(kx < (int)xs.size() && xs[kx] ==\
    \ x);\n        kx += size;\n        int ky = gety(kx, y);\n        assert(ky <\
    \ (int)ys[kx].size() && ys[kx][ky] == y);\n        return seg[kx][ky];\n    }\n\
    \n    void update(X x, Y y, T val) {\n        int kx = getx(x);\n        assert(kx\
    \ < (int)xs.size() && xs[kx] == x);\n        kx += size;\n        int ky = gety(kx,\
    \ y);\n        assert(ky < (int)ys[kx].size() && ys[kx][ky] == y);\n        seg[kx].update(ky,\
    \ val);\n        while (kx >>= 1) {\n            ky = gety(kx, y);\n         \
    \   int kl = gety(2 * kx, y), kr = gety(2 * kx + 1, y);\n            T vl = (kl\
    \ < (int)ys[2 * kx].size() && ys[2 * kx][kl] == y\n                        ? seg[2\
    \ * kx][kl]\n                        : M::id());\n            T vr = (kr < (int)ys[2\
    \ * kx + 1].size() && ys[2 * kx + 1][kr] == y\n                        ? seg[2\
    \ * kx + 1][kr]\n                        : M::id());\n            seg[kx].update(ky,\
    \ M::op(vl, vr));\n        }\n    }\n\n    T fold(X sx, X tx, Y sy, Y ty) const\
    \ {\n        T ret = M::id();\n        for (int l = size + getx(sx), r = size\
    \ + getx(tx); l < r;\n             l >>= 1, r >>= 1) {\n            if (l & 1)\
    \ {\n                ret = M::op(ret, seg[l].fold(gety(l, sy), gety(l, ty)));\n\
    \                ++l;\n            }\n            if (r & 1) {\n             \
    \   --r;\n                ret = M::op(ret, seg[r].fold(gety(r, sy), gety(r, ty)));\n\
    \            }\n        }\n        return ret;\n    }\n\n   private:\n    int\
    \ size;\n    std::vector<X> xs;\n    std::vector<std::vector<Y>> ys;\n    std::vector<SegmentTree<M>>\
    \ seg;\n\n    int getx(X x) const { return std::ranges::lower_bound(xs, x) - xs.begin();\
    \ }\n    int gety(int k, Y y) const {\n        return std::ranges::lower_bound(ys[k],\
    \ y) - ys[k].begin();\n    }\n};"
  dependsOn:
  - data-structure/segtree/segment_tree.hpp
  isVerificationFile: false
  path: data-structure/segtree/segment_tree_2d.hpp
  requiredBy: []
  timestamp: '2024-03-02 18:46:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
documentation_of: data-structure/segtree/segment_tree_2d.hpp
layout: document
title: 2D Segment Tree
---

## Description

2D セグメント木は，モノイド $(T, \cdot, e)$ の重みを持つ2次元平面上の点集合に対する一点更新と矩形領域積取得を提供するデータ構造である．

この実装では，重みをもたせる点を先読みして初期化時に渡す必要がある．

空間計算量: $O(n)$

## Operations

- `SegmentTree2D(vector<pair<X, Y>> pts)`
    - `pts` の点に対する 2D セグメント木を初期化する
    - 時間計算量: $O(n\log n)$
- `void update(X x, Y y, T val)`
    - 点 $(x, y)$ の重みを $val$ に更新する
    - 時間計算量: $O((\log n)^2)$
- `T fold(X sx, X tx, Y sy, Y ty)`
    - 矩形領域 $[s_x, t_x) \times [s_y, t_y)$ 内の点の重みの積を取得する
    - 時間計算量: $O((\log n)^2)$
