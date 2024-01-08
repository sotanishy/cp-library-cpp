---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree_2d.hpp
    title: 2D Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/sortable_segment_tree.hpp
    title: Sortable Segment Tree
  - icon: ':x:'
    path: graph/manhattan_mst.hpp
    title: Manhattan Minimum Spanning Tree
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/manhattanmst.test.cpp
    title: test/yosupo/manhattanmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
    title: test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_sort_range_composite.test.cpp
    title: test/yosupo/point_set_range_sort_range_composite.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/segment_tree.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <vector>\n\ntemplate <typename M>\nclass SegmentTree\
    \ {\n    using T = M::T;\n\n   public:\n    SegmentTree() = default;\n    explicit\
    \ SegmentTree(int n) : SegmentTree(std::vector<T>(n, M::id())) {}\n    explicit\
    \ SegmentTree(const std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\
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
    \    std::vector<T> node;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <vector>\n\n\
    template <typename M>\nclass SegmentTree {\n    using T = M::T;\n\n   public:\n\
    \    SegmentTree() = default;\n    explicit SegmentTree(int n) : SegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    explicit SegmentTree(const std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\
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
    \    std::vector<T> node;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/segment_tree.hpp
  requiredBy:
  - data-structure/segtree/sortable_segment_tree.hpp
  - data-structure/segtree/segment_tree_2d.hpp
  - graph/manhattan_mst.hpp
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/point_set_range_sort_range_composite.test.cpp
  - test/yosupo/point_add_rectangle_sum.2d_segtree.test.cpp
  - test/yosupo/manhattanmst.test.cpp
  - test/yosupo/vertex_set_path_composite.test.cpp
documentation_of: data-structure/segtree/segment_tree.hpp
layout: document
title: Segment Tree
---

## Description

セグメント木は，モノイド $(T, \cdot, e)$ の列に対する一点更新と区間取得を提供するデータ構造である．

空間計算量: $O(n)$

## Operations

- `SegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ のセグメント木を構築する
    - 時間計算量: $O(n)$
- `SegmentTree(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`のセグメント木を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(1)$
- `void update(int k, T x)`
    - $k$ 番目の要素を $x$ に更新する
    - 時間計算量: $O(\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(\log n)$
- `int find_first(int l, F cond)`
    - `fold(l, r)` が条件 `cond` を満たすような最小の $r (> l)$ 返す．列の単調性を仮定する．そのような $r$ が存在しない場合は `-1` を返す
    - 時間計算量: $O(\log n)$
- `int find_last(int r, F cond)`
    - `fold(l, r)` が条件 `cond` を満たすような最大の $l (< r)$ 返す．列の単調性を仮定する．そのような $l$ が存在しない場合は `-1` を返す
    - 時間計算量: $O(\log n)$

## Reference

- [セグメント木について](https://beet-aizu.hatenablog.com/entry/2017/09/10/132258)
- [セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/29/204841)
- [競技プログラマのための抽象セグメント木実装のすすめ](https://beet-aizu.hatenablog.com/entry/2019/11/27/124437)
- [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)