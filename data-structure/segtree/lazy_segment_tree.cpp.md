---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/permutation_tree.hpp
    title: Permutation Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
    title: test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/common_interval_decomposition_tree.test.cpp
    title: test/yosupo/common_interval_decomposition_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/lazy_segment_tree.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n\ntemplate <typename M, typename O, typename\
    \ M::T (*act)(typename M::T, typename O::T)>\nclass LazySegmentTree {\n    using\
    \ T = typename M::T;\n    using E = typename O::T;\n\npublic:\n    LazySegmentTree()\
    \ = default;\n    explicit LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    explicit LazySegmentTree(const std::vector<T>& v) {\n    \
    \    size = 1;\n        while (size < (int) v.size()) size <<= 1;\n        node.resize(2\
    \ * size, M::id());\n        lazy.resize(2 * size, O::id());\n        std::copy(v.begin(),\
    \ v.end(), node.begin() + size);\n        for (int i = size - 1; i > 0; --i) node[i]\
    \ = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int k) {\n\
    \        return fold(k, k + 1);\n    }\n\n    void update(int l, int r, const\
    \ E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int l, int r) { return\
    \ fold(l, r, 1, 0, size); }\n\n    template <typename F>\n    int find_first(int\
    \ l, F cond) {\n        T v = M::id();\n        return find_first(l, size, 1,\
    \ 0, size, v, cond);\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) {\n        T v = M::id();\n        return find_last(0, r, 1, 0, size,\
    \ v, cond);\n    }\n\nprivate:\n    int size;\n    std::vector<T> node;\n    std::vector<E>\
    \ lazy;\n\n    void push(int k) {\n        if (lazy[k] == O::id()) return;\n \
    \       if (k < size) {\n            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);\n\
    \            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n        }\n \
    \       node[k] = act(node[k], lazy[k]);\n        lazy[k] = O::id();\n    }\n\n\
    \    void update(int a, int b, const E& x, int k, int l, int r) {\n        push(k);\n\
    \        if (r <= a || b <= l) return;\n        if (a <= l && r <= b) {\n    \
    \        lazy[k] = O::op(lazy[k], x);\n            push(k);\n            return;\n\
    \        }\n        int m = (l + r) / 2;\n        update(a, b, x, 2 * k, l, m);\n\
    \        update(a, b, x, 2 * k + 1, m, r);\n        node[k] = M::op(node[2 * k],\
    \ node[2 * k + 1]);\n    }\n\n    T fold(int a, int b, int k, int l, int r) {\n\
    \        push(k);\n        if (r <= a || b <= l) return M::id();\n        if (a\
    \ <= l && r <= b) return node[k];\n        int m = (l + r) / 2;\n        return\
    \ M::op(fold(a, b, 2 * k, l, m),\n                     fold(a, b, 2 * k + 1, m,\
    \ r));\n    }\n\n    template <typename F>\n    int find_first(int a, int b, int\
    \ k, int l, int r, T& v, F cond) {\n        push(k);\n        if (r <= a) return\
    \ -1;\n        if (b <= l) return l;\n        if (a <= l && r <= b && !cond(M::op(v,\
    \ node[k]))) {\n            v = M::op(v, node[k]);\n            return -1;\n \
    \       }\n        if (r - l == 1) return r;\n        int m = (l + r) / 2;\n \
    \       int res = find_first(a, b, 2 * k, l, m, v, cond);\n        if (res !=\
    \ -1) return res;\n        return find_first(a, b, 2 * k + 1, m, r, v, cond);\n\
    \    }\n\n    template <typename F>\n    int find_last(int a, int b, int k, int\
    \ l, int r, T& v, F cond) {\n        push(k);\n        if (b <= l) return -1;\n\
    \        if (r <= a) return r;\n        if (a <= l && r <= b && !cond(M::op(node[k],\
    \ v))) {\n            v = M::op(node[k], v);\n            return -1;\n       \
    \ }\n        if (r - l == 1) return l;\n        int m = (l + r) / 2;\n       \
    \ int res = find_last(a, b, 2 * k + 1, m, r, v, cond);\n        if (res != -1)\
    \ return res;\n        return find_last(a, b, 2 * k, l, m, v, cond);\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ M, typename O, typename M::T (*act)(typename M::T, typename O::T)>\nclass LazySegmentTree\
    \ {\n    using T = typename M::T;\n    using E = typename O::T;\n\npublic:\n \
    \   LazySegmentTree() = default;\n    explicit LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    explicit LazySegmentTree(const std::vector<T>& v) {\n    \
    \    size = 1;\n        while (size < (int) v.size()) size <<= 1;\n        node.resize(2\
    \ * size, M::id());\n        lazy.resize(2 * size, O::id());\n        std::copy(v.begin(),\
    \ v.end(), node.begin() + size);\n        for (int i = size - 1; i > 0; --i) node[i]\
    \ = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int k) {\n\
    \        return fold(k, k + 1);\n    }\n\n    void update(int l, int r, const\
    \ E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int l, int r) { return\
    \ fold(l, r, 1, 0, size); }\n\n    template <typename F>\n    int find_first(int\
    \ l, F cond) {\n        T v = M::id();\n        return find_first(l, size, 1,\
    \ 0, size, v, cond);\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) {\n        T v = M::id();\n        return find_last(0, r, 1, 0, size,\
    \ v, cond);\n    }\n\nprivate:\n    int size;\n    std::vector<T> node;\n    std::vector<E>\
    \ lazy;\n\n    void push(int k) {\n        if (lazy[k] == O::id()) return;\n \
    \       if (k < size) {\n            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);\n\
    \            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n        }\n \
    \       node[k] = act(node[k], lazy[k]);\n        lazy[k] = O::id();\n    }\n\n\
    \    void update(int a, int b, const E& x, int k, int l, int r) {\n        push(k);\n\
    \        if (r <= a || b <= l) return;\n        if (a <= l && r <= b) {\n    \
    \        lazy[k] = O::op(lazy[k], x);\n            push(k);\n            return;\n\
    \        }\n        int m = (l + r) / 2;\n        update(a, b, x, 2 * k, l, m);\n\
    \        update(a, b, x, 2 * k + 1, m, r);\n        node[k] = M::op(node[2 * k],\
    \ node[2 * k + 1]);\n    }\n\n    T fold(int a, int b, int k, int l, int r) {\n\
    \        push(k);\n        if (r <= a || b <= l) return M::id();\n        if (a\
    \ <= l && r <= b) return node[k];\n        int m = (l + r) / 2;\n        return\
    \ M::op(fold(a, b, 2 * k, l, m),\n                     fold(a, b, 2 * k + 1, m,\
    \ r));\n    }\n\n    template <typename F>\n    int find_first(int a, int b, int\
    \ k, int l, int r, T& v, F cond) {\n        push(k);\n        if (r <= a) return\
    \ -1;\n        if (b <= l) return l;\n        if (a <= l && r <= b && !cond(M::op(v,\
    \ node[k]))) {\n            v = M::op(v, node[k]);\n            return -1;\n \
    \       }\n        if (r - l == 1) return r;\n        int m = (l + r) / 2;\n \
    \       int res = find_first(a, b, 2 * k, l, m, v, cond);\n        if (res !=\
    \ -1) return res;\n        return find_first(a, b, 2 * k + 1, m, r, v, cond);\n\
    \    }\n\n    template <typename F>\n    int find_last(int a, int b, int k, int\
    \ l, int r, T& v, F cond) {\n        push(k);\n        if (b <= l) return -1;\n\
    \        if (r <= a) return r;\n        if (a <= l && r <= b && !cond(M::op(node[k],\
    \ v))) {\n            v = M::op(node[k], v);\n            return -1;\n       \
    \ }\n        if (r - l == 1) return l;\n        int m = (l + r) / 2;\n       \
    \ int res = find_last(a, b, 2 * k + 1, m, r, v, cond);\n        if (res != -1)\
    \ return res;\n        return find_last(a, b, 2 * k, l, m, v, cond);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/lazy_segment_tree.cpp
  requiredBy:
  - tree/permutation_tree.hpp
  timestamp: '2022-06-30 16:20:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/yosupo/common_interval_decomposition_tree.test.cpp
  - test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: data-structure/segtree/lazy_segment_tree.cpp
layout: document
title: Segment Tree with Lazy Propagation
---

## Description

遅延伝搬セグメント木は，モノイド $(T, \cdot, e_M)$ の列と，作用素モノイド $(E, \circ, e_O)$ による作用 $*: T \times E \rightarrow T$ を扱うデータ構造である．区間更新と区間取得を提供する．

作用 $*$ は $T$ の準自己同型である．すなわち，以下の性質が成り立つ．
- $\forall a \in T, a * e_O = a$
- $\forall a \in T, f, g \in E, a * (f \circ g) = (a * f) * g$
- $\forall a, b \in T, f \in E, (a \cdot b) * f = (a * f) \cdot (b * f)$

空間計算量: $O(n)$

## Operations

- `LazySegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e_M$ の遅延伝搬セグメント木を構築する
    - 時間計算量: $O(n)$
- `LazySegmentTree(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の遅延伝搬セグメント木を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
    - 時間計算量: $O(\log n)$
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる
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

## Note

作用が区間の長さに比例するとき (e.g. 区間加算)，作用の分配則は成り立たないが，これはモノイドを $T \times \mathbb{N}$ に拡張して区間の長さを持たせ，適切に $*$ を定義することで対処できる．

また，作用素が単位元を持たない半群であるとき（e.g. 区間更新）は，適当な値を集合に添加してそれを単位元として扱うことができる．

作用素の分配則が成り立たない場合，Segment tree beats を用いて高速に計算できる場合がある．

## Reference

- [遅延評価セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/30/224339)
- [遅延伝播セグメント木について](https://beet-aizu.hatenablog.com/entry/2017/12/01/225955)
- [SegmentTreeに載る代数的構造について](https://qiita.com/keymoon/items/0f929a19ed30f34ae6e8)
- [遅延伝搬segment木についてもっと詳しく](https://kimiyuki.net/blog/2018/11/03/lazy-propagation-segment-tree/)
