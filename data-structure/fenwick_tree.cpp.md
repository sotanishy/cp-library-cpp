---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/fenwick_tree.md
    document_title: Fenwick Tree
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick_tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n/*\n * @brief Fenwick Tree\n * @docs docs/data-structure/fenwick_tree.md\n\
    \ */\ntemplate <typename M>\nclass FenwickTree {\n    using T = typename M::T;\n\
    \npublic:\n    explicit FenwickTree(int n) : n(n), data(n + 1, M::id) {}\n\n \
    \   T prefix_fold(int i) const {\n        T ret = M::id;\n        for (; i > 0;\
    \ i -= i & -i) ret = M::op(ret, data[i]);\n        return ret;\n    }\n\n    void\
    \ update(int i, T x) {\n        for (i++; i <= n; i += i & -i) data[i] = M::op(data[i],\
    \ x);\n    }\n\n    int find_first(const std::function<bool(T)>& cond) const {\n\
    \        int k = 1;\n        while (k * 2 <= n) k <<= 1;\n        int i = 0;\n\
    \        T x = M::id;\n        for (; k > 0; k >>= 1) {\n            if (i + k\
    \ <= n && !cond(M::op(x, data[i + k]))) {\n                x = M::op(x, data[i\
    \ + k]);\n                i += k;\n            }\n        }\n        return i\
    \ - 1;\n    }\n\nprivate:\n    int n;\n    std::vector<T> data;\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Fenwick Tree\n\
    \ * @docs docs/data-structure/fenwick_tree.md\n */\ntemplate <typename M>\nclass\
    \ FenwickTree {\n    using T = typename M::T;\n\npublic:\n    explicit FenwickTree(int\
    \ n) : n(n), data(n + 1, M::id) {}\n\n    T prefix_fold(int i) const {\n     \
    \   T ret = M::id;\n        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);\n\
    \        return ret;\n    }\n\n    void update(int i, T x) {\n        for (i++;\
    \ i <= n; i += i & -i) data[i] = M::op(data[i], x);\n    }\n\n    int find_first(const\
    \ std::function<bool(T)>& cond) const {\n        int k = 1;\n        while (k\
    \ * 2 <= n) k <<= 1;\n        int i = 0;\n        T x = M::id;\n        for (;\
    \ k > 0; k >>= 1) {\n            if (i + k <= n && !cond(M::op(x, data[i + k])))\
    \ {\n                x = M::op(x, data[i + k]);\n                i += k;\n   \
    \         }\n        }\n        return i - 1;\n    }\n\nprivate:\n    int n;\n\
    \    std::vector<T> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_B.test.cpp
documentation_of: data-structure/fenwick_tree.cpp
layout: document
redirect_from:
- /library/data-structure/fenwick_tree.cpp
- /library/data-structure/fenwick_tree.cpp.html
title: Fenwick Tree
---
# Fenwick Tree

Fenwick tree，または binary indexed tree は，可換モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，一点更新と接頭辞へのクエリを処理できるデータ構造である．

セグメント木より制約が強く，操作が限られているが，実装が簡潔で定数倍速い．

空間計算量: $O(n)$

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `FenwickTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の Fenwick tree を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T prefix_fold(int i)`
    - $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ を計算する
    - 時間計算量: $O(\lg n)$
- `void update(int i, T x)`
    - $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$
- `int find_first(const function<bool(T)>& cond)`
    - $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ が条件 `cond` を満たすような最小の $i$ を返す．列の単調性を仮定する．そのような $i$ が存在しない場合は $n$ を返す．
    - 時間計算量: $O(\lg n)$