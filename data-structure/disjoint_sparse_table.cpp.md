---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data-structure/disjoint_sparse_table.md
    document_title: Disjoint Sparse Table
    links: []
  bundledCode: "#line 2 \"data-structure/disjoint_sparse_table.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\n/*\n * @brief Disjoint Sparse Table\n * @docs docs/data-structure/disjoint_sparse_table.md\n\
    \ */\ntemplate <typename S>\nclass DisjointSparseTable {\n    using T = typename\
    \ S::T;\n\npublic:\n    DisjointSparseTable() = default;\n    explicit DisjointSparseTable(const\
    \ std::vector<T>& v) {\n        int n = v.size(), b = 0;\n        while ((1 <<\
    \ b) < n) ++b;\n        lookup.resize(b + 1, std::vector<T>(n));\n        std::copy(v.begin(),\
    \ v.end(), lookup[0].begin());\n        for (int i = 1; i <= b; ++i) {\n     \
    \       int len = 1 << i;\n            for (int l = 0; l + len / 2 < n; l += len)\
    \ {\n                int m = l + len / 2;\n                lookup[i][m - 1] =\
    \ v[m - 1];\n                for (int j = m - 2; j >= l; --j) {\n            \
    \        lookup[i][j] = S::op(lookup[i][j + 1], v[j]);\n                }\n  \
    \              lookup[i][m] = v[m];\n                for (int j = m + 1; j < std::min(l\
    \ + len, n); ++j) {\n                    lookup[i][j] = S::op(lookup[i][j - 1],\
    \ v[j]);\n                }\n            }\n        }\n    }\n\n    T fold(int\
    \ l, int r) const {\n        if (r - l == 1) return lookup[0][l];\n        int\
    \ i = 32 - __builtin_clz(l ^ (r - 1));\n        return S::op(lookup[i][l], lookup[i][r\
    \ - 1]);\n    }\n\nprivate:\n    std::vector<std::vector<T>> lookup;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n/*\n * @brief Disjoint\
    \ Sparse Table\n * @docs docs/data-structure/disjoint_sparse_table.md\n */\ntemplate\
    \ <typename S>\nclass DisjointSparseTable {\n    using T = typename S::T;\n\n\
    public:\n    DisjointSparseTable() = default;\n    explicit DisjointSparseTable(const\
    \ std::vector<T>& v) {\n        int n = v.size(), b = 0;\n        while ((1 <<\
    \ b) < n) ++b;\n        lookup.resize(b + 1, std::vector<T>(n));\n        std::copy(v.begin(),\
    \ v.end(), lookup[0].begin());\n        for (int i = 1; i <= b; ++i) {\n     \
    \       int len = 1 << i;\n            for (int l = 0; l + len / 2 < n; l += len)\
    \ {\n                int m = l + len / 2;\n                lookup[i][m - 1] =\
    \ v[m - 1];\n                for (int j = m - 2; j >= l; --j) {\n            \
    \        lookup[i][j] = S::op(lookup[i][j + 1], v[j]);\n                }\n  \
    \              lookup[i][m] = v[m];\n                for (int j = m + 1; j < std::min(l\
    \ + len, n); ++j) {\n                    lookup[i][j] = S::op(lookup[i][j - 1],\
    \ v[j]);\n                }\n            }\n        }\n    }\n\n    T fold(int\
    \ l, int r) const {\n        if (r - l == 1) return lookup[0][l];\n        int\
    \ i = 32 - __builtin_clz(l ^ (r - 1));\n        return S::op(lookup[i][l], lookup[i][r\
    \ - 1]);\n    }\n\nprivate:\n    std::vector<std::vector<T>> lookup;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/disjoint_sparse_table.cpp
  requiredBy: []
  timestamp: '2020-11-03 02:25:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: data-structure/disjoint_sparse_table.cpp
layout: document
redirect_from:
- /library/data-structure/disjoint_sparse_table.cpp
- /library/data-structure/disjoint_sparse_table.cpp.html
title: Disjoint Sparse Table
---
## Description

Disjoint sparse table は，半群 $(T, \cdot)$ の静的な列の区間和を高速に計算するデータ構造である．スパーステーブルと違って二項演算 $\cdot$ に冪等性を要求しない．

空間計算量: $O(n \lg n)$

## Operations

- `DisjointSparseTable(vector<T> v)`
    - `v`の要素から disjoint sparse table を構築する
    - 時間計算量: $O(n \lg n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(1)$

## Reference

- [[Tutorial] Disjoint Sparse Table](https://discuss.codechef.com/t/tutorial-disjoint-sparse-table/17404)
- [Disjoint Sparse Table と セグ木に関するポエム](https://noshi91.hatenablog.com/entry/2018/05/08/183946)