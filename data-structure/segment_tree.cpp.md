---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/segment_tree.md
    document_title: Segment Tree
    links: []
  bundledCode: "#line 1 \"data-structure/segment_tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/*\n * @brief Segment Tree\n * @docs docs/data-structure/segment_tree.md\n\
    \ */\ntemplate <typename M>\nclass SegmentTree {\n    using T = typename M::T;\n\
    \npublic:\n    SegmentTree() = default;\n    explicit SegmentTree(int n): SegmentTree(vector<T>(n,\
    \ M::id)) {}\n    explicit SegmentTree(const vector<T>& v) {\n        size = 1;\n\
    \        while (size < (int) v.size()) size <<= 1;\n        node.resize(2 * size,\
    \ M::id);\n        copy(v.begin(), v.end(), node.begin() + size);\n        for\
    \ (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2 * i + 1]);\n\
    \    }\n\n    T operator[](int k) const {\n        return node[k + size];\n  \
    \  }\n\n    void update(int k, const T& x) {\n        k += size;\n        node[k]\
    \ = x;\n        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);\n\
    \    }\n\n    T fold(int l, int r) const {\n        T vl = M::id, vr = M::id;\n\
    \        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) vl = M::op(vl, node[l++]);\n            if (r & 1) vr = M::op(node[--r],\
    \ vr);\n        }\n        return M::op(vl, vr);\n    }\n\n    int find_first(int\
    \ l, const function<bool(T)>& cond) const {\n        T vl = M::id;\n        int\
    \ r = size;\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n \
    \           if (l & 1) {\n                T nxt = M::op(vl, node[l]);\n      \
    \          if (cond(nxt)) {\n                    while (l < size) {\n        \
    \                nxt = M::op(vl, node[2 * l]);\n                        if (cond(nxt))\
    \ l = 2 * l;\n                        else vl = nxt, l = 2 * l + 1;\n        \
    \            }\n                    return l - size;\n                }\n    \
    \            vl = nxt;\n                ++l;\n            }\n        }\n     \
    \   return -1;\n    }\n\n    int find_last(int r, const function<bool(T)>& cond)\
    \ const {\n        T vr = M::id;\n        int l = 0;\n        for (l += size,\
    \ r += size; l < r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n          \
    \      --r;\n                T nxt = M::op(node[r], vr);\n                if (cond(nxt))\
    \ {\n                    while (r < size) {\n                        nxt = M::op(node[2\
    \ * r + 1], vr);\n                        if (cond(nxt)) r = 2 * r + 1;\n    \
    \                    else vr = nxt, r = 2 * r;\n                    }\n      \
    \              return r - size;\n                }\n                vr = nxt;\n\
    \            }\n        }\n        return -1;\n    }\n\nprivate:\n    int size;\n\
    \    vector<T> node;\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Segment Tree\n\
    \ * @docs docs/data-structure/segment_tree.md\n */\ntemplate <typename M>\nclass\
    \ SegmentTree {\n    using T = typename M::T;\n\npublic:\n    SegmentTree() =\
    \ default;\n    explicit SegmentTree(int n): SegmentTree(vector<T>(n, M::id))\
    \ {}\n    explicit SegmentTree(const vector<T>& v) {\n        size = 1;\n    \
    \    while (size < (int) v.size()) size <<= 1;\n        node.resize(2 * size,\
    \ M::id);\n        copy(v.begin(), v.end(), node.begin() + size);\n        for\
    \ (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2 * i + 1]);\n\
    \    }\n\n    T operator[](int k) const {\n        return node[k + size];\n  \
    \  }\n\n    void update(int k, const T& x) {\n        k += size;\n        node[k]\
    \ = x;\n        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);\n\
    \    }\n\n    T fold(int l, int r) const {\n        T vl = M::id, vr = M::id;\n\
    \        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) vl = M::op(vl, node[l++]);\n            if (r & 1) vr = M::op(node[--r],\
    \ vr);\n        }\n        return M::op(vl, vr);\n    }\n\n    int find_first(int\
    \ l, const function<bool(T)>& cond) const {\n        T vl = M::id;\n        int\
    \ r = size;\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n \
    \           if (l & 1) {\n                T nxt = M::op(vl, node[l]);\n      \
    \          if (cond(nxt)) {\n                    while (l < size) {\n        \
    \                nxt = M::op(vl, node[2 * l]);\n                        if (cond(nxt))\
    \ l = 2 * l;\n                        else vl = nxt, l = 2 * l + 1;\n        \
    \            }\n                    return l - size;\n                }\n    \
    \            vl = nxt;\n                ++l;\n            }\n        }\n     \
    \   return -1;\n    }\n\n    int find_last(int r, const function<bool(T)>& cond)\
    \ const {\n        T vr = M::id;\n        int l = 0;\n        for (l += size,\
    \ r += size; l < r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n          \
    \      --r;\n                T nxt = M::op(node[r], vr);\n                if (cond(nxt))\
    \ {\n                    while (r < size) {\n                        nxt = M::op(node[2\
    \ * r + 1], vr);\n                        if (cond(nxt)) r = 2 * r + 1;\n    \
    \                    else vr = nxt, r = 2 * r;\n                    }\n      \
    \              return r - size;\n                }\n                vr = nxt;\n\
    \            }\n        }\n        return -1;\n    }\n\nprivate:\n    int size;\n\
    \    vector<T> node;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment_tree.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
documentation_of: data-structure/segment_tree.cpp
layout: document
redirect_from:
- /library/data-structure/segment_tree.cpp
- /library/data-structure/segment_tree.cpp.html
title: Segment Tree
---
# Segment Tree

セグメント木は，モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，列に対する一点更新と区間クエリを処理できるデータ構造である．

区間更新・一点クエリは双対セグメント木を使用する．

区間更新・区間クエリは遅延伝搬セグメント木を使用する．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `SegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ のセグメント木を構築する
    - 時間計算量: $O(n)$
- `SegmentTree(const vector<T>& v)`
    - `v`の要素からサイズ`n = v.size()`のセグメント木を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(1)$
- `void update(int k, const T& x)`
    - $a_k$ を $x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ を計算する．$l = r$ ならば $e$ を返す．
    - 時間計算量: $O(\lg n)$
- `int find_first(int l, const function<bool(T)>& cond)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ が条件 `cond` を満たすような最小の $r (> l)$ 返す．列の単調性を仮定する．そのような $r$ が存在しない場合は `-1` を返す．
    - 時間計算量: $O(\lg n)$
- `int find_last(int r, const function<bool(T)>& cond)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ が条件 `cond` を満たすような最大の $l (< r)$ 返す．列の単調性を仮定する．そのような $l$ が存在しない場合は `-1` を返す．
    - 時間計算量: $O(\lg n)$