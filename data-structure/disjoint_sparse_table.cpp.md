---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/disjoint_sparse_table.md
    document_title: Disjoint Sparse Table
    links: []
  bundledCode: "#line 1 \"data-structure/disjoint_sparse_table.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Disjoint Sparse Table\n * @docs docs/data-structure/disjoint_sparse_table.md\n\
    \ */\ntemplate <typename S>\nclass DisjointSparseTable {\n    using T = typename\
    \ S::T;\n\npublic:\n    explicit DisjointSparseTable(const std::vector<T>& v)\
    \ {\n        int n = v.size(), b = 0;\n        while ((1 << b) < n) b++;\n   \
    \     lookup.resize(b + 1, std::vector<T>(n));\n        std::copy(v.begin(), v.end(),\
    \ lookup[0].begin());\n        for (int i = 1; i <= b; i++) {\n            int\
    \ len = 1 << i;\n            for (int l = 0; l + len / 2 < n; l += len) {\n  \
    \              int m = l + len / 2;\n                lookup[i][m - 1] = v[m -\
    \ 1];\n                for (int j = 1; j < len / 2; j++) {\n                 \
    \   lookup[i][m - 1 - j] = S::op(v[m - 1 - j], lookup[i][m - j]);\n          \
    \      }\n                lookup[i][m] = v[m];\n                for (int j = 1;\
    \ m + j < std::min(l + len, n); j++) {\n                    lookup[i][m + j] =\
    \ S::op(lookup[i][m + j - 1], v[m + j]);\n                }\n            }\n \
    \       }\n    }\n\n    T fold(int l, int r) const {\n        if (r - l == 1)\
    \ return lookup[0][l];\n        int i = 32 - __builtin_clz(l ^ (r - 1));\n   \
    \     return S::op(lookup[i][l], lookup[i][r - 1]);\n    }\n\nprivate:\n    std::vector<std::vector<T>>\
    \ lookup;\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Disjoint Sparse Table\n * @docs\
    \ docs/data-structure/disjoint_sparse_table.md\n */\ntemplate <typename S>\nclass\
    \ DisjointSparseTable {\n    using T = typename S::T;\n\npublic:\n    explicit\
    \ DisjointSparseTable(const std::vector<T>& v) {\n        int n = v.size(), b\
    \ = 0;\n        while ((1 << b) < n) b++;\n        lookup.resize(b + 1, std::vector<T>(n));\n\
    \        std::copy(v.begin(), v.end(), lookup[0].begin());\n        for (int i\
    \ = 1; i <= b; i++) {\n            int len = 1 << i;\n            for (int l =\
    \ 0; l + len / 2 < n; l += len) {\n                int m = l + len / 2;\n    \
    \            lookup[i][m - 1] = v[m - 1];\n                for (int j = 1; j <\
    \ len / 2; j++) {\n                    lookup[i][m - 1 - j] = S::op(v[m - 1 -\
    \ j], lookup[i][m - j]);\n                }\n                lookup[i][m] = v[m];\n\
    \                for (int j = 1; m + j < std::min(l + len, n); j++) {\n      \
    \              lookup[i][m + j] = S::op(lookup[i][m + j - 1], v[m + j]);\n   \
    \             }\n            }\n        }\n    }\n\n    T fold(int l, int r) const\
    \ {\n        if (r - l == 1) return lookup[0][l];\n        int i = 32 - __builtin_clz(l\
    \ ^ (r - 1));\n        return S::op(lookup[i][l], lookup[i][r - 1]);\n    }\n\n\
    private:\n    std::vector<std::vector<T>> lookup;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/disjoint_sparse_table.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: data-structure/disjoint_sparse_table.cpp
layout: document
redirect_from:
- /library/data-structure/disjoint_sparse_table.cpp
- /library/data-structure/disjoint_sparse_table.cpp.html
title: Disjoint Sparse Table
---
# Disjoint Sparse Table

Disjoint sparse table は，半群 $(T, \cdot)$ の静的な列 $(a_0, a_1, \dots, a_{n-1})$ に対する区間クエリを高速に処理するデータ構造である．

二項演算 $\cdot$ が冪等であるとき，スパーステーブルの方が定数倍速いと思われる．

空間計算量: $O(n \lg n)$

## Template parameters

- `S`
    - 半群 $(T, \cdot)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `DisjointSparseTable(const vector<T>& v)`
    - `v`の要素から disjoint sparse table を構築する
    - 時間計算量: $O(n \lg n)$

## Member functions

- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ を計算する
    - 時間計算量: $O(1)$