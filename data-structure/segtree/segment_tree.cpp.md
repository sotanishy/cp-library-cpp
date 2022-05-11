---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/segment_tree.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <typename M>\nclass SegmentTree {\n    using T =\
    \ typename M::T;\n\npublic:\n    SegmentTree() = default;\n    explicit SegmentTree(int\
    \ n): SegmentTree(std::vector<T>(n, M::id())) {}\n    explicit SegmentTree(const\
    \ std::vector<T>& v) {\n        size = 1;\n        while (size < (int) v.size())\
    \ size <<= 1;\n        node.resize(2 * size, M::id());\n        std::copy(v.begin(),\
    \ v.end(), node.begin() + size);\n        for (int i = size - 1; i > 0; --i) node[i]\
    \ = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int k) const\
    \ {\n        return node[k + size];\n    }\n\n    void update(int k, const T&\
    \ x) {\n        k += size;\n        node[k] = x;\n        while (k >>= 1) node[k]\
    \ = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n    T fold(int l, int r) const\
    \ {\n        T vl = M::id(), vr = M::id();\n        for (l += size, r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) vl = M::op(vl, node[l++]);\n\
    \            if (r & 1) vr = M::op(node[--r], vr);\n        }\n        return\
    \ M::op(vl, vr);\n    }\n\n    template <typename F>\n    int find_first(int l,\
    \ F cond) const {\n        T vl = M::id();\n        int r = size;\n        for\
    \ (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n\
    \                T nxt = M::op(vl, node[l]);\n                if (cond(nxt)) {\n\
    \                    while (l < size) {\n                        nxt = M::op(vl,\
    \ node[2 * l]);\n                        if (cond(nxt)) l = 2 * l;\n         \
    \               else vl = nxt, l = 2 * l + 1;\n                    }\n       \
    \             return l - size;\n                }\n                vl = nxt;\n\
    \                ++l;\n            }\n        }\n        return -1;\n    }\n\n\
    \    template <typename F>\n    int find_last(int r, F cond) const {\n       \
    \ T vr = M::id();\n        int l = 0;\n        for (l += size, r += size; l <\
    \ r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n                --r;\n   \
    \             T nxt = M::op(node[r], vr);\n                if (cond(nxt)) {\n\
    \                    while (r < size) {\n                        nxt = M::op(node[2\
    \ * r + 1], vr);\n                        if (cond(nxt)) r = 2 * r + 1;\n    \
    \                    else vr = nxt, r = 2 * r;\n                    }\n      \
    \              return r - size;\n                }\n                vr = nxt;\n\
    \            }\n        }\n        return -1;\n    }\n\nprivate:\n    int size;\n\
    \    std::vector<T> node;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ M>\nclass SegmentTree {\n    using T = typename M::T;\n\npublic:\n    SegmentTree()\
    \ = default;\n    explicit SegmentTree(int n): SegmentTree(std::vector<T>(n, M::id()))\
    \ {}\n    explicit SegmentTree(const std::vector<T>& v) {\n        size = 1;\n\
    \        while (size < (int) v.size()) size <<= 1;\n        node.resize(2 * size,\
    \ M::id());\n        std::copy(v.begin(), v.end(), node.begin() + size);\n   \
    \     for (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2 *\
    \ i + 1]);\n    }\n\n    T operator[](int k) const {\n        return node[k +\
    \ size];\n    }\n\n    void update(int k, const T& x) {\n        k += size;\n\
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
    \  return -1;\n    }\n\nprivate:\n    int size;\n    std::vector<T> node;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/segment_tree.cpp
  requiredBy: []
  timestamp: '2022-03-06 20:10:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
  - test/yosupo/vertex_set_path_composite.test.cpp
documentation_of: data-structure/segtree/segment_tree.cpp
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