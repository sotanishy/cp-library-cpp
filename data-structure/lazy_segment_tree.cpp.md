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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/lazy_segment_tree.md
    document_title: Segment Tree with Lazy Propagation
    links: []
  bundledCode: "#line 1 \"data-structure/lazy_segment_tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/*\n * @brief Segment Tree with Lazy Propagation\n * @docs\
    \ docs/data-structure/lazy_segment_tree.md\n */\ntemplate <typename M, typename\
    \ O, typename M::T (*act)(typename M::T, typename O::T)>\nclass LazySegmentTree\
    \ {\n    using T = typename M::T;\n    using E = typename O::T;\n\npublic:\n \
    \   explicit LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, M::id)) {}\n\
    \    explicit LazySegmentTree(const vector<T>& v) {\n        size = 1;\n     \
    \   height = 0;\n        while (size < (int) v.size()) size <<= 1, height++;\n\
    \        node.resize(2 * size, M::id);\n        lazy.resize(2 * size, O::id);\n\
    \        copy(v.begin(), v.end(), node.begin() + size);\n        for (int i =\
    \ size - 1; i > 0; i--) node[i] = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\
    \n    T operator[](int k) {\n        return fold(k, k + 1);\n    }\n\n    void\
    \ update(int l, int r, const E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int\
    \ l, int r) { return fold(l, r, 1, 0, size); }\n\nprivate:\n    int size, height;\n\
    \    vector<T> node;\n    vector<E> lazy;\n\n    void push(int k) {\n        if\
    \ (lazy[k] == O::id) return;\n        if (k < size) {\n            lazy[2 * k]\
    \ = O::op(lazy[2 * k], lazy[k]);\n            lazy[2 * k + 1] = O::op(lazy[2 *\
    \ k + 1], lazy[k]);\n        }\n        node[k] = act(node[k], lazy[k]);\n   \
    \     lazy[k] = O::id;\n    }\n\n    void update(int a, int b, const E& x, int\
    \ k, int l, int r) {\n        push(k);\n        if (r <= a || b <= l) return;\n\
    \        if (a <= l && r <= b) {\n            lazy[k] = O::op(lazy[k], x);\n \
    \           push(k);\n            return;\n        }\n        int m = (l + r)\
    \ / 2;\n        update(a, b, x, 2 * k, l, m);\n        update(a, b, x, 2 * k +\
    \ 1, m, r);\n        node[k] = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n\
    \    T fold(int a, int b, int k, int l, int r) {\n        push(k);\n        if\
    \ (r <= a || b <= l) return M::id;\n        if (a <= l && r <= b) return node[k];\n\
    \        int m = (l + r) / 2;\n        return M::op(fold(a, b, 2 * k, l, m),\n\
    \                     fold(a, b, 2 * k + 1, m, r));\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Segment Tree\
    \ with Lazy Propagation\n * @docs docs/data-structure/lazy_segment_tree.md\n */\n\
    template <typename M, typename O, typename M::T (*act)(typename M::T, typename\
    \ O::T)>\nclass LazySegmentTree {\n    using T = typename M::T;\n    using E =\
    \ typename O::T;\n\npublic:\n    explicit LazySegmentTree(int n) : LazySegmentTree(vector<T>(n,\
    \ M::id)) {}\n    explicit LazySegmentTree(const vector<T>& v) {\n        size\
    \ = 1;\n        height = 0;\n        while (size < (int) v.size()) size <<= 1,\
    \ height++;\n        node.resize(2 * size, M::id);\n        lazy.resize(2 * size,\
    \ O::id);\n        copy(v.begin(), v.end(), node.begin() + size);\n        for\
    \ (int i = size - 1; i > 0; i--) node[i] = M::op(node[2 * i], node[2 * i + 1]);\n\
    \    }\n\n    T operator[](int k) {\n        return fold(k, k + 1);\n    }\n\n\
    \    void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size); }\n\n\
    \    T fold(int l, int r) { return fold(l, r, 1, 0, size); }\n\nprivate:\n   \
    \ int size, height;\n    vector<T> node;\n    vector<E> lazy;\n\n    void push(int\
    \ k) {\n        if (lazy[k] == O::id) return;\n        if (k < size) {\n     \
    \       lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);\n            lazy[2 * k + 1]\
    \ = O::op(lazy[2 * k + 1], lazy[k]);\n        }\n        node[k] = act(node[k],\
    \ lazy[k]);\n        lazy[k] = O::id;\n    }\n\n    void update(int a, int b,\
    \ const E& x, int k, int l, int r) {\n        push(k);\n        if (r <= a ||\
    \ b <= l) return;\n        if (a <= l && r <= b) {\n            lazy[k] = O::op(lazy[k],\
    \ x);\n            push(k);\n            return;\n        }\n        int m = (l\
    \ + r) / 2;\n        update(a, b, x, 2 * k, l, m);\n        update(a, b, x, 2\
    \ * k + 1, m, r);\n        node[k] = M::op(node[2 * k], node[2 * k + 1]);\n  \
    \  }\n\n    T fold(int a, int b, int k, int l, int r) {\n        push(k);\n  \
    \      if (r <= a || b <= l) return M::id;\n        if (a <= l && r <= b) return\
    \ node[k];\n        int m = (l + r) / 2;\n        return M::op(fold(a, b, 2 *\
    \ k, l, m),\n                     fold(a, b, 2 * k + 1, m, r));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-22 01:15:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F.test.cpp
  - test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
documentation_of: data-structure/lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/data-structure/lazy_segment_tree.cpp
- /library/data-structure/lazy_segment_tree.cpp.html
title: Segment Tree with Lazy Propagation
---
# Segment Tree with Lazy Propagation

遅延伝搬セグメント木は，モノイド $(T, \cdot, e_M)$ の列 $(a_0, a_1, \dots, a_{n-1})$ と，作用素モノイド $(E, \circ, e_O)$ による作用 $*$ を扱うデータ構造である．区間更新と区間クエリを処理することができる．

作用 $*: T \times E \rightarrow T$ は $T$ の準自己同型である．すなわち，以下の性質が成り立つ．
- $\forall a \in T, a * e_O = a$
- $\forall a \in T, f, g \in E, a * (f \circ g) = (a * f) * g$
- $\forall a, b \in T, f \in E, (a \cdot b) * f = (a * f) \cdot (b * f)$

作用が区間の長さに比例するとき (e.g. 区間加算)，作用の分配則は成り立たないが，これはモノイドを $T \times \mathbb{N}$ に拡張して区間の長さを持たせ，適切に $*$ を定義することで対処できる．

一点更新・区間クエリはセグメント木を使用する．

区間更新・一点クエリは双対セグメント木を使用する．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e_M)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e_M$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$
- `O`
    - 作用素モノイド $(E, \circ, e_O)$. 以下のメンバーが定義されている:
        - `E`: 集合 $E$ の型
        - `E id`: 単位元 $e_O$
        - `E op(E, E)`: 結合的な二項演算 $\circ: E \times E \rightarrow E$
- `T act(T, E)`
    - 作用 $*: T \times E \rightarrow T$.

## Constructor

- `LazySegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e_M$ の遅延伝搬セグメント木を構築する
    - 時間計算量: $O(n)$
- `LazySegmentTree(const vector<T>& v)`
    - `v`の要素からサイズ`n = v.size()`の遅延伝搬セグメント木を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(\lg n)$
- `void update(int l, int r, const E& x)`
    - $i \in [l, r)$ について $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}\$ を計算する
    - 時間計算量: $O(\lg n)$