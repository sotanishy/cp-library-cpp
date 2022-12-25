---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tree/range_contour_aggregation.hpp
    title: Range Contour Aggregation
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_subsequences.test.cpp
    title: test/yosupo/number_of_subsequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/fenwick_tree.cpp\"\n#include <functional>\n\
    #include <vector>\n\ntemplate <typename M>\nclass FenwickTree {\n    using T =\
    \ typename M::T;\n\npublic:\n    FenwickTree() = default;\n    explicit FenwickTree(int\
    \ n) : n(n), data(n + 1, M::id()) {}\n\n    T prefix_fold(int i) const {\n   \
    \     T ret = M::id();\n        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);\n\
    \        return ret;\n    }\n\n    void update(int i, const T& x) {\n        for\
    \ (++i; i <= n; i += i & -i) data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const\
    \ T& x) const {\n        if (x <= M::id()) return 0;\n        int k = 1;\n   \
    \     while (k * 2 <= n) k <<= 1;\n        int i = 0;\n        T v = M::id();\n\
    \        for (; k > 0; k >>= 1) {\n            if (i + k > n) continue;\n    \
    \        T nv = M::op(v, data[i + k]);\n            if (nv < x) {\n          \
    \      v = nv;\n                i += k;\n            }\n        }\n        return\
    \ i;\n    }\n\nprivate:\n    int n;\n    std::vector<T> data;\n};\n"
  code: "#pragma once\n#include <functional>\n#include <vector>\n\ntemplate <typename\
    \ M>\nclass FenwickTree {\n    using T = typename M::T;\n\npublic:\n    FenwickTree()\
    \ = default;\n    explicit FenwickTree(int n) : n(n), data(n + 1, M::id()) {}\n\
    \n    T prefix_fold(int i) const {\n        T ret = M::id();\n        for (; i\
    \ > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return ret;\n    }\n\n\
    \    void update(int i, const T& x) {\n        for (++i; i <= n; i += i & -i)\
    \ data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const T& x) const\
    \ {\n        if (x <= M::id()) return 0;\n        int k = 1;\n        while (k\
    \ * 2 <= n) k <<= 1;\n        int i = 0;\n        T v = M::id();\n        for\
    \ (; k > 0; k >>= 1) {\n            if (i + k > n) continue;\n            T nv\
    \ = M::op(v, data[i + k]);\n            if (nv < x) {\n                v = nv;\n\
    \                i += k;\n            }\n        }\n        return i;\n    }\n\
    \nprivate:\n    int n;\n    std::vector<T> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick_tree.cpp
  requiredBy:
  - tree/range_contour_aggregation.hpp
  timestamp: '2022-12-25 14:40:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.test.cpp
  - test/yosupo/number_of_subsequences.test.cpp
  - test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: data-structure/fenwick_tree.cpp
layout: document
title: Fenwick Tree
---

## Description

Fenwick tree，または binary indexed tree (BIT) は，可換モノイド $(T, \cdot, e)$ の列に対する一点更新と接頭辞和の取得を提供するデータ構造である．

セグメント木より制約が強く，操作が限られているが，実装が簡潔で定数倍速い．浮動小数点の演算をするときは，セグメント木よりも誤差が大きくなる傾向があるので注意が必要である．

空間計算量: $O(n)$

## Operations

- `FenwickTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の Fenwick tree を構築する
    - 時間計算量: $O(n)$
- `T prefix_fold(int i)`
    - 区間 $[0, i)$ の値を fold する
    - 時間計算量: $O(\log n)$
- `void update(int i, T x)`
    - $i$ 番目の要素を $x$ と演算した値に更新する
    - 時間計算量: $O(\log n)$
- `int lower_bound(T x)`
- `int lower_bound(T x, Compare cmp)`
    - `cmp(prefix_fold(i), x) == false` となる最初の $i$ を返す．そのような $i$ が存在しない場合は $n$ を返す．`cmp` を指定しない場合は `<` で比較される．列の単調性を仮定する．
    - 時間計算量: $O(\log n)$

## Reference

- [Binary Indexed Tree のはなし](http://hos.ac/slides/20140319_bit.pdf)