---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
    title: test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/segtree/lazy_segment_tree.md
    document_title: Segment Tree with Lazy Propagation
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/lazy_segment_tree.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n\n/*\n * @brief Segment Tree with Lazy Propagation\n\
    \ * @docs docs/data-structure/segtree/lazy_segment_tree.md\n */\ntemplate <typename\
    \ M, typename O, typename M::T (*act)(typename M::T, typename O::T)>\nclass LazySegmentTree\
    \ {\n    using T = typename M::T;\n    using E = typename O::T;\n\npublic:\n \
    \   LazySegmentTree() = default;\n    explicit LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n,\
    \ M::id)) {}\n    explicit LazySegmentTree(const std::vector<T>& v) {\n      \
    \  size = 1;\n        height = 0;\n        while (size < (int) v.size()) size\
    \ <<= 1, ++height;\n        node.resize(2 * size, M::id);\n        lazy.resize(2\
    \ * size, O::id);\n        std::copy(v.begin(), v.end(), node.begin() + size);\n\
    \        for (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2\
    \ * i + 1]);\n    }\n\n    T operator[](int k) {\n        return fold(k, k + 1);\n\
    \    }\n\n    void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size);\
    \ }\n\n    T fold(int l, int r) { return fold(l, r, 1, 0, size); }\n\nprivate:\n\
    \    int size, height;\n    std::vector<T> node;\n    std::vector<E> lazy;\n\n\
    \    void push(int k) {\n        if (lazy[k] == O::id) return;\n        if (k\
    \ < size) {\n            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);\n        \
    \    lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n        }\n        node[k]\
    \ = act(node[k], lazy[k]);\n        lazy[k] = O::id;\n    }\n\n    void update(int\
    \ a, int b, const E& x, int k, int l, int r) {\n        push(k);\n        if (r\
    \ <= a || b <= l) return;\n        if (a <= l && r <= b) {\n            lazy[k]\
    \ = O::op(lazy[k], x);\n            push(k);\n            return;\n        }\n\
    \        int m = (l + r) / 2;\n        update(a, b, x, 2 * k, l, m);\n       \
    \ update(a, b, x, 2 * k + 1, m, r);\n        node[k] = M::op(node[2 * k], node[2\
    \ * k + 1]);\n    }\n\n    T fold(int a, int b, int k, int l, int r) {\n     \
    \   push(k);\n        if (r <= a || b <= l) return M::id;\n        if (a <= l\
    \ && r <= b) return node[k];\n        int m = (l + r) / 2;\n        return M::op(fold(a,\
    \ b, 2 * k, l, m),\n                     fold(a, b, 2 * k + 1, m, r));\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n/*\n * @brief Segment\
    \ Tree with Lazy Propagation\n * @docs docs/data-structure/segtree/lazy_segment_tree.md\n\
    \ */\ntemplate <typename M, typename O, typename M::T (*act)(typename M::T, typename\
    \ O::T)>\nclass LazySegmentTree {\n    using T = typename M::T;\n    using E =\
    \ typename O::T;\n\npublic:\n    LazySegmentTree() = default;\n    explicit LazySegmentTree(int\
    \ n) : LazySegmentTree(std::vector<T>(n, M::id)) {}\n    explicit LazySegmentTree(const\
    \ std::vector<T>& v) {\n        size = 1;\n        height = 0;\n        while\
    \ (size < (int) v.size()) size <<= 1, ++height;\n        node.resize(2 * size,\
    \ M::id);\n        lazy.resize(2 * size, O::id);\n        std::copy(v.begin(),\
    \ v.end(), node.begin() + size);\n        for (int i = size - 1; i > 0; --i) node[i]\
    \ = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int k) {\n\
    \        return fold(k, k + 1);\n    }\n\n    void update(int l, int r, const\
    \ E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int l, int r) { return\
    \ fold(l, r, 1, 0, size); }\n\nprivate:\n    int size, height;\n    std::vector<T>\
    \ node;\n    std::vector<E> lazy;\n\n    void push(int k) {\n        if (lazy[k]\
    \ == O::id) return;\n        if (k < size) {\n            lazy[2 * k] = O::op(lazy[2\
    \ * k], lazy[k]);\n            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n\
    \        }\n        node[k] = act(node[k], lazy[k]);\n        lazy[k] = O::id;\n\
    \    }\n\n    void update(int a, int b, const E& x, int k, int l, int r) {\n \
    \       push(k);\n        if (r <= a || b <= l) return;\n        if (a <= l &&\
    \ r <= b) {\n            lazy[k] = O::op(lazy[k], x);\n            push(k);\n\
    \            return;\n        }\n        int m = (l + r) / 2;\n        update(a,\
    \ b, x, 2 * k, l, m);\n        update(a, b, x, 2 * k + 1, m, r);\n        node[k]\
    \ = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n    T fold(int a, int b, int\
    \ k, int l, int r) {\n        push(k);\n        if (r <= a || b <= l) return M::id;\n\
    \        if (a <= l && r <= b) return node[k];\n        int m = (l + r) / 2;\n\
    \        return M::op(fold(a, b, 2 * k, l, m),\n                     fold(a, b,\
    \ 2 * k + 1, m, r));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-11-03 02:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
documentation_of: data-structure/segtree/lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/data-structure/segtree/lazy_segment_tree.cpp
- /library/data-structure/segtree/lazy_segment_tree.cpp.html
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
    - 時間計算量: $O(\lg n)$
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(\lg n)$

## Note

作用が区間の長さに比例するとき (e.g. 区間加算)，作用の分配則は成り立たないが，これはモノイドを $T \times \mathbb{N}$ に拡張して区間の長さを持たせ，適切に $*$ を定義することで対処できる．

また，作用素が単位元を持たない半群であるとき（e.g. 区間更新）は，適当な値を集合に添加してそれを単位元として扱うことができる．

## Reference

- [遅延評価セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/30/224339)
- [遅延伝播セグメント木について](https://beet-aizu.hatenablog.com/entry/2017/12/01/225955)
- [SegmentTreeに載る代数的構造について](https://qiita.com/keymoon/items/0f929a19ed30f34ae6e8)
- [遅延伝搬segment木についてもっと詳しく](https://kimiyuki.net/blog/2018/11/03/lazy-propagation-segment-tree/)


## TODO

- 二分探索の実装
- 非再帰