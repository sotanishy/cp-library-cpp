---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree.cpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/segtree/segment_tree_2d.hpp\"\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n#line 4 \"data-structure/segtree/segment_tree.cpp\"\
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
    #line 5 \"data-structure/segtree/segment_tree_2d.hpp\"\n\ntemplate <typename X,\
    \ typename Y, typename M>\nclass SegmentTree2D {\n    using T = typename M::T;\n\
    \npublic:\n    SegmentTree2D() = default;\n    explicit SegmentTree2D(const std::vector<std::pair<X,\
    \ Y>>& pts) {\n        for (auto& [x, y] : pts) {\n            xs.push_back(x);\n\
    \        }\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n\n        const int n = xs.size();\n        size = 1;\n\
    \        while (size < n) size <<= 1;\n        ys.resize(2 * size);\n        seg.resize(2\
    \ * size);\n\n        for (auto& [x, y] : pts) {\n            int k = std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n            ys[size + k].push_back(y);\n       \
    \ }\n\n        for (int i = 0; i < n; ++i) {\n            std::sort(ys[size +\
    \ i].begin(), ys[size + i].end());\n            ys[size + i].erase(std::unique(ys[size\
    \ + i].begin(), ys[size + i].end()), ys[size + i].end());\n        }\n       \
    \ for (int i = size - 1; i > 0; --i) {\n            std::merge(ys[2*i].begin(),\
    \ ys[2*i].end(), ys[2*i+1].begin(), ys[2*i+1].end(), std::back_inserter(ys[i]));\n\
    \        }\n        for (int i = 0; i < size + n; ++i) {\n            seg[i] =\
    \ SegmentTree<M>(ys[i].size());\n        }\n    }\n\n    void update(X x, Y y,\
    \ T val) {\n        int k = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin()\
    \ + size;\n        while (k) {\n            int i = std::lower_bound(ys[k].begin(),\
    \ ys[k].end(), y) - ys[k].begin();\n            seg[k].update(i, val);\n     \
    \       k >>= 1;\n        }\n    }\n\n    T fold(X sx, X tx, Y sy, Y ty) const\
    \ {\n        T ret = M::id();\n        int l = std::lower_bound(xs.begin(), xs.end(),\
    \ sx) - xs.begin();\n        int r = std::lower_bound(xs.begin(), xs.end(), tx)\
    \ - xs.begin();\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) {\n                int hi = std::lower_bound(ys[l].begin(),\
    \ ys[l].end(), ty) - ys[l].begin();\n                int lo = std::lower_bound(ys[l].begin(),\
    \ ys[l].end(), sy) - ys[l].begin();\n                ret = M::op(ret, seg[l].fold(lo,\
    \ hi));\n                ++l;\n            }\n            if (r & 1) {\n     \
    \           --r;\n                int hi = std::lower_bound(ys[r].begin(), ys[r].end(),\
    \ ty) - ys[r].begin();\n                int lo = std::lower_bound(ys[r].begin(),\
    \ ys[r].end(), sy) - ys[r].begin();\n                ret = M::op(ret, seg[r].fold(lo,\
    \ hi));\n            }\n        }\n        return ret;\n    }\n\nprivate:\n  \
    \  int size;\n    std::vector<X> xs;\n    std::vector<std::vector<Y>> ys;\n  \
    \  std::vector<SegmentTree<M>> seg;\n};\n"
  code: "#include <algorithm>\n#include <utility>\n#include <vector>\n#include \"\
    segment_tree.cpp\"\n\ntemplate <typename X, typename Y, typename M>\nclass SegmentTree2D\
    \ {\n    using T = typename M::T;\n\npublic:\n    SegmentTree2D() = default;\n\
    \    explicit SegmentTree2D(const std::vector<std::pair<X, Y>>& pts) {\n     \
    \   for (auto& [x, y] : pts) {\n            xs.push_back(x);\n        }\n    \
    \    std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n\n        const int n = xs.size();\n        size = 1;\n\
    \        while (size < n) size <<= 1;\n        ys.resize(2 * size);\n        seg.resize(2\
    \ * size);\n\n        for (auto& [x, y] : pts) {\n            int k = std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n            ys[size + k].push_back(y);\n       \
    \ }\n\n        for (int i = 0; i < n; ++i) {\n            std::sort(ys[size +\
    \ i].begin(), ys[size + i].end());\n            ys[size + i].erase(std::unique(ys[size\
    \ + i].begin(), ys[size + i].end()), ys[size + i].end());\n        }\n       \
    \ for (int i = size - 1; i > 0; --i) {\n            std::merge(ys[2*i].begin(),\
    \ ys[2*i].end(), ys[2*i+1].begin(), ys[2*i+1].end(), std::back_inserter(ys[i]));\n\
    \        }\n        for (int i = 0; i < size + n; ++i) {\n            seg[i] =\
    \ SegmentTree<M>(ys[i].size());\n        }\n    }\n\n    void update(X x, Y y,\
    \ T val) {\n        int k = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin()\
    \ + size;\n        while (k) {\n            int i = std::lower_bound(ys[k].begin(),\
    \ ys[k].end(), y) - ys[k].begin();\n            seg[k].update(i, val);\n     \
    \       k >>= 1;\n        }\n    }\n\n    T fold(X sx, X tx, Y sy, Y ty) const\
    \ {\n        T ret = M::id();\n        int l = std::lower_bound(xs.begin(), xs.end(),\
    \ sx) - xs.begin();\n        int r = std::lower_bound(xs.begin(), xs.end(), tx)\
    \ - xs.begin();\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) {\n                int hi = std::lower_bound(ys[l].begin(),\
    \ ys[l].end(), ty) - ys[l].begin();\n                int lo = std::lower_bound(ys[l].begin(),\
    \ ys[l].end(), sy) - ys[l].begin();\n                ret = M::op(ret, seg[l].fold(lo,\
    \ hi));\n                ++l;\n            }\n            if (r & 1) {\n     \
    \           --r;\n                int hi = std::lower_bound(ys[r].begin(), ys[r].end(),\
    \ ty) - ys[r].begin();\n                int lo = std::lower_bound(ys[r].begin(),\
    \ ys[r].end(), sy) - ys[r].begin();\n                ret = M::op(ret, seg[r].fold(lo,\
    \ hi));\n            }\n        }\n        return ret;\n    }\n\nprivate:\n  \
    \  int size;\n    std::vector<X> xs;\n    std::vector<std::vector<Y>> ys;\n  \
    \  std::vector<SegmentTree<M>> seg;\n};"
  dependsOn:
  - data-structure/segtree/segment_tree.cpp
  isVerificationFile: false
  path: data-structure/segtree/segment_tree_2d.hpp
  requiredBy: []
  timestamp: '2022-08-28 10:49:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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
    - 矩形領域 $[sx, tx) \times [sy, ty)$ 内の点の重みの積を取得する
    - 時間計算量: $O((\log n)^2)$

## Reference

- verify: [https://atcoder.jp/contests/abc266/submissions/34414646](https://atcoder.jp/contests/abc266/submissions/34414646)