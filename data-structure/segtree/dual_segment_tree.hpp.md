---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/dual_segment_tree_2d.hpp
    title: 2D Dual Segment Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_point_get.test.cpp
    title: test/yosupo/range_affine_point_get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
    title: test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/dual_segment_tree.hpp\"\n#include\
    \ <bit>\n#include <vector>\n\ntemplate <typename M>\nclass DualSegmentTree {\n\
    \    using T = typename M::T;\n\n   public:\n    DualSegmentTree() = default;\n\
    \    explicit DualSegmentTree(int n)\n        : size(std::bit_ceil((unsigned int)n)),\n\
    \          height(std::bit_width((unsigned int)size) - 1),\n          lazy(2 *\
    \ size, M::id()) {}\n\n    T operator[](int k) {\n        k += size;\n       \
    \ propagate(k);\n        return lazy[k];\n    }\n\n    void update(int l, int\
    \ r, const T& x) {\n        if (l >= r) return;\n        l += size;\n        r\
    \ += size;\n        propagate(l);\n        propagate(r - 1);\n        for (; l\
    \ < r; l >>= 1, r >>= 1) {\n            if (l & 1) lazy[l] = M::op(lazy[l], x),\
    \ ++l;\n            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);\n        }\n\
    \    }\n\n   private:\n    int size, height;\n    std::vector<T> lazy;\n\n   \
    \ void push(int k) {\n        if (lazy[k] == M::id()) return;\n        lazy[2\
    \ * k] = M::op(lazy[2 * k], lazy[k]);\n        lazy[2 * k + 1] = M::op(lazy[2\
    \ * k + 1], lazy[k]);\n        lazy[k] = M::id();\n    }\n\n    void propagate(int\
    \ k) {\n        for (int i = height; i > 0; --i) push(k >> i);\n    }\n};\n"
  code: "#pragma once\n#include <bit>\n#include <vector>\n\ntemplate <typename M>\n\
    class DualSegmentTree {\n    using T = typename M::T;\n\n   public:\n    DualSegmentTree()\
    \ = default;\n    explicit DualSegmentTree(int n)\n        : size(std::bit_ceil((unsigned\
    \ int)n)),\n          height(std::bit_width((unsigned int)size) - 1),\n      \
    \    lazy(2 * size, M::id()) {}\n\n    T operator[](int k) {\n        k += size;\n\
    \        propagate(k);\n        return lazy[k];\n    }\n\n    void update(int\
    \ l, int r, const T& x) {\n        if (l >= r) return;\n        l += size;\n \
    \       r += size;\n        propagate(l);\n        propagate(r - 1);\n       \
    \ for (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) lazy[l] = M::op(lazy[l],\
    \ x), ++l;\n            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);\n       \
    \ }\n    }\n\n   private:\n    int size, height;\n    std::vector<T> lazy;\n\n\
    \    void push(int k) {\n        if (lazy[k] == M::id()) return;\n        lazy[2\
    \ * k] = M::op(lazy[2 * k], lazy[k]);\n        lazy[2 * k + 1] = M::op(lazy[2\
    \ * k + 1], lazy[k]);\n        lazy[k] = M::id();\n    }\n\n    void propagate(int\
    \ k) {\n        for (int i = height; i > 0; --i) push(k >> i);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/dual_segment_tree.hpp
  requiredBy:
  - data-structure/segtree/dual_segment_tree_2d.hpp
  timestamp: '2024-03-02 18:46:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rectangle_add_point_get.2d_dual_segtree.test.cpp
  - test/yosupo/range_affine_point_get.test.cpp
documentation_of: data-structure/segtree/dual_segment_tree.hpp
layout: document
title: Dual Segment Tree
---

## Description

双対セグメント木は，作用素モノイド $(T, \cdot, e)$ の列に対する区間更新と一点取得を提供するデータ構造である．

空間計算量: $O(n)$

## Operations

- `DualSegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の双対セグメント木を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log n)$
- `void update(int l, int r, T x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる
    - 時間計算量: $O(\log n)$

## Note

この実装は正しくは双対セグメント木ではなく，遅延伝搬セグメント木を半分にしたものである．本来の双対セグメント木では遅延伝搬をせずに，一点取得クエリの際に上に取りに行く．しかしこれは作用素モノイドに可換則を要求するため使い勝手が悪いので，ここでは便宜上遅延伝搬セグメント木を半分にしたものを双対セグメント木と呼んでいる．

## Reference

- [双対セグメント木という概念について](https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/)
- [双対セグメント木](https://hackmd.io/@tatyam-prime/DualSegmentTree)