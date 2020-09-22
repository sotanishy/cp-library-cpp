---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.sparse_table.test.cpp
    title: test/aoj/DSL_3_D.sparse_table.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/sparse_table.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 1 \"data-structure/sparse_table.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Sparse Table\n * @docs docs/data-structure/sparse_table.md\n */\n\
    template <typename S>\nclass SparseTable {\n    using T = typename S::T;\n\npublic:\n\
    \    SparseTable() = default;\n    explicit SparseTable(const std::vector<T>&\
    \ v) {\n        int n = v.size(), b = 0;\n        while ((1 << b) <= n) ++b;\n\
    \        lookup.resize(b, std::vector<T>(n));\n        std::copy(v.begin(), v.end(),\
    \ lookup[0].begin());\n        for (int i = 1; i < b; ++i) {\n            for\
    \ (int j = 0; j + (1 << i) <= n; ++j) {\n                lookup[i][j] = S::op(lookup[i\
    \ - 1][j], lookup[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n   \
    \ }\n\n    T fold(int l, int r) const {\n        int i = 31 - __builtin_clz(r\
    \ - l);\n        return S::op(lookup[i][l], lookup[i][r - (1 << i)]);\n    }\n\
    \nprivate:\n    std::vector<std::vector<T>> lookup;\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Sparse Table\n * @docs docs/data-structure/sparse_table.md\n\
    \ */\ntemplate <typename S>\nclass SparseTable {\n    using T = typename S::T;\n\
    \npublic:\n    SparseTable() = default;\n    explicit SparseTable(const std::vector<T>&\
    \ v) {\n        int n = v.size(), b = 0;\n        while ((1 << b) <= n) ++b;\n\
    \        lookup.resize(b, std::vector<T>(n));\n        std::copy(v.begin(), v.end(),\
    \ lookup[0].begin());\n        for (int i = 1; i < b; ++i) {\n            for\
    \ (int j = 0; j + (1 << i) <= n; ++j) {\n                lookup[i][j] = S::op(lookup[i\
    \ - 1][j], lookup[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n   \
    \ }\n\n    T fold(int l, int r) const {\n        int i = 31 - __builtin_clz(r\
    \ - l);\n        return S::op(lookup[i][l], lookup[i][r - (1 << i)]);\n    }\n\
    \nprivate:\n    std::vector<std::vector<T>> lookup;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sparse_table.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_3_D.sparse_table.test.cpp
documentation_of: data-structure/sparse_table.cpp
layout: document
redirect_from:
- /library/data-structure/sparse_table.cpp
- /library/data-structure/sparse_table.cpp.html
title: Sparse Table
---
# Sparse Table

スパーステーブルは，冪等半群 $(T, \cdot)$ の静的な列 $(a_0, a_1, \dots, a_{n-1})$ に対する区間クエリを高速に処理するデータ構造である．

冪等な二項演算とは， $\forall a \in T, a \cdot a = a$ が成り立つような写像 $\cdot: T \times T \rightarrow T$ である．冪等な二項演算には，max, min, gcd, bitwise and, bitwise or などがある．

空間計算量: $O(n \lg n)$

## Template parameters

- `S`
    - 冪等半群 $(T, \cdot)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T op(T, T)`: 結合的かつ冪等な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `SparseTable(const vector<T>& v)`
    - `v`の要素からスパーステーブルを構築する
    - 時間計算量: $O(n \lg n)$

## Member functions

- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ を計算する．
    - 時間計算量: $O(1)$