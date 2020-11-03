---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.sqrt_tree.test.cpp
    title: test/yosupo/staticrmq.sqrt_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/sqrt_tree.md
    document_title: Sqrt Tree
    links: []
  bundledCode: "#line 2 \"data-structure/sqrt_tree.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\n/*\n * @brief Sqrt Tree\n * @docs docs/data-structure/sqrt_tree.md\n\
    \ */\ntemplate <typename M>\nclass SqrtTree {\n    using T = typename M::T;\n\n\
    public:\n    SqrtTree() = default;\n    explicit SqrtTree(const std::vector<T>&\
    \ vs) : n(vs.size()), v(vs) {\n        int size = 1;\n        lg = 0;\n      \
    \  while (size < (int) v.size()) size <<= 1, ++lg;\n        bitlen.resize(size);\n\
    \        for (int i = 1; i < size; ++i) bitlen[i] = bitlen[i >> 1] + 1;\n    \
    \    on_layer.resize(lg + 1);\n        for (int i = lg; i > 1; i = (i + 1) / 2)\
    \ {\n            on_layer[i] = layer_lg.size();\n            layer_lg.push_back(i);\n\
    \        }\n        for (int i = lg - 1; i >= 0; --i) on_layer[i] = std::max(on_layer[i],\
    \ on_layer[i + 1]);\n        v.resize(size);\n        pref.resize(layer_lg.size(),\
    \ std::vector<T>(size));\n        suf.resize(layer_lg.size(), std::vector<T>(size));\n\
    \        btwn.resize(layer_lg.size(), std::vector<T>(size));\n        build(0,\
    \ 0, n);\n    }\n\n    T fold(int l, int r) const {\n        --r;\n        if\
    \ (l == r) return v[l];\n        if (l + 1 == r) return M::op(v[l], v[r]);\n \
    \       int layer = on_layer[bitlen[l ^ r]];\n        int b_sz = 1 << ((layer_lg[layer]\
    \ + 1) / 2);\n        int b_cnt = 1 << (layer_lg[layer] / 2);\n        int a =\
    \ (l >> layer_lg[layer]) << layer_lg[layer];\n        int lblock = (l - a) / b_sz\
    \ + 1;\n        int rblock = (r - a) / b_sz - 1;\n        T val = suf[layer][l];\n\
    \        if (lblock <= rblock) {\n            val = M::op(val, btwn[layer][a +\
    \ lblock * b_cnt + rblock]);\n        }\n        val = M::op(val, pref[layer][r]);\n\
    \        return val;\n    }\n\nprivate:\n    int n, lg;\n    std::vector<int>\
    \ bitlen, layer_lg, on_layer;\n    std::vector<T> v;\n    std::vector<std::vector<T>>\
    \ pref, suf, btwn;\n\n    void build(int layer, int l, int r) {\n        if (layer\
    \ >= (int) layer_lg.size()) return;\n        int b_sz = 1 << ((layer_lg[layer]\
    \ + 1) / 2);\n        for (int a = l; a < r; a += b_sz) {\n            int b =\
    \ std::min(a + b_sz, r);\n            // build a block\n            pref[layer][a]\
    \ = v[a];\n            for (int i = a + 1; i < b; ++i) {\n                pref[layer][i]\
    \ = M::op(pref[layer][i - 1], v[i]);\n            }\n            suf[layer][b\
    \ - 1] = v[b - 1];\n            for (int i = b - 2; i >= a; --i) {\n         \
    \       suf[layer][i] = M::op(v[i], suf[layer][i + 1]);\n            }\n     \
    \       build(layer + 1, a, b);\n        }\n        // build btwn\n        int\
    \ b_cnt = 1 << (layer_lg[layer] / 2);\n        for (int i = 0; i < b_cnt; ++i)\
    \ {\n            T val = M::id;\n            for (int j = i; j < b_cnt; ++j) {\n\
    \                val = M::op(val, suf[layer][l + j * b_sz]);\n               \
    \ btwn[layer][l + i * b_cnt + j] = val;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n/*\n * @brief Sqrt\
    \ Tree\n * @docs docs/data-structure/sqrt_tree.md\n */\ntemplate <typename M>\n\
    class SqrtTree {\n    using T = typename M::T;\n\npublic:\n    SqrtTree() = default;\n\
    \    explicit SqrtTree(const std::vector<T>& vs) : n(vs.size()), v(vs) {\n   \
    \     int size = 1;\n        lg = 0;\n        while (size < (int) v.size()) size\
    \ <<= 1, ++lg;\n        bitlen.resize(size);\n        for (int i = 1; i < size;\
    \ ++i) bitlen[i] = bitlen[i >> 1] + 1;\n        on_layer.resize(lg + 1);\n   \
    \     for (int i = lg; i > 1; i = (i + 1) / 2) {\n            on_layer[i] = layer_lg.size();\n\
    \            layer_lg.push_back(i);\n        }\n        for (int i = lg - 1; i\
    \ >= 0; --i) on_layer[i] = std::max(on_layer[i], on_layer[i + 1]);\n        v.resize(size);\n\
    \        pref.resize(layer_lg.size(), std::vector<T>(size));\n        suf.resize(layer_lg.size(),\
    \ std::vector<T>(size));\n        btwn.resize(layer_lg.size(), std::vector<T>(size));\n\
    \        build(0, 0, n);\n    }\n\n    T fold(int l, int r) const {\n        --r;\n\
    \        if (l == r) return v[l];\n        if (l + 1 == r) return M::op(v[l],\
    \ v[r]);\n        int layer = on_layer[bitlen[l ^ r]];\n        int b_sz = 1 <<\
    \ ((layer_lg[layer] + 1) / 2);\n        int b_cnt = 1 << (layer_lg[layer] / 2);\n\
    \        int a = (l >> layer_lg[layer]) << layer_lg[layer];\n        int lblock\
    \ = (l - a) / b_sz + 1;\n        int rblock = (r - a) / b_sz - 1;\n        T val\
    \ = suf[layer][l];\n        if (lblock <= rblock) {\n            val = M::op(val,\
    \ btwn[layer][a + lblock * b_cnt + rblock]);\n        }\n        val = M::op(val,\
    \ pref[layer][r]);\n        return val;\n    }\n\nprivate:\n    int n, lg;\n \
    \   std::vector<int> bitlen, layer_lg, on_layer;\n    std::vector<T> v;\n    std::vector<std::vector<T>>\
    \ pref, suf, btwn;\n\n    void build(int layer, int l, int r) {\n        if (layer\
    \ >= (int) layer_lg.size()) return;\n        int b_sz = 1 << ((layer_lg[layer]\
    \ + 1) / 2);\n        for (int a = l; a < r; a += b_sz) {\n            int b =\
    \ std::min(a + b_sz, r);\n            // build a block\n            pref[layer][a]\
    \ = v[a];\n            for (int i = a + 1; i < b; ++i) {\n                pref[layer][i]\
    \ = M::op(pref[layer][i - 1], v[i]);\n            }\n            suf[layer][b\
    \ - 1] = v[b - 1];\n            for (int i = b - 2; i >= a; --i) {\n         \
    \       suf[layer][i] = M::op(v[i], suf[layer][i + 1]);\n            }\n     \
    \       build(layer + 1, a, b);\n        }\n        // build btwn\n        int\
    \ b_cnt = 1 << (layer_lg[layer] / 2);\n        for (int i = 0; i < b_cnt; ++i)\
    \ {\n            T val = M::id;\n            for (int j = i; j < b_cnt; ++j) {\n\
    \                val = M::op(val, suf[layer][l + j * b_sz]);\n               \
    \ btwn[layer][l + i * b_cnt + j] = val;\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sqrt_tree.cpp
  requiredBy: []
  timestamp: '2020-11-04 00:40:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq.sqrt_tree.test.cpp
documentation_of: data-structure/sqrt_tree.cpp
layout: document
redirect_from:
- /library/data-structure/sqrt_tree.cpp
- /library/data-structure/sqrt_tree.cpp.html
title: Sqrt Tree
---
## Description

Sqrt tree は，モノイド $(T, \cdot, e)$ の静的な列の区間和を高速に計算するデータ構造である．平方分割を再帰的に行うことで $O(1)$ クエリを実現する．スパーステーブルと比べて前処理が高速でメモリ使用量が少ないという特徴がある．

ここでは実装していないが，$O(\sqrt{N})$ で要素の更新も可能である．

空間計算量: $O(n\lg\lg n)$

## Operations

- `SqrtTree(vector<T> vs)`
    - `vs` から sqrt tree を構築する
    - 時間計算量: $O(n\lg\lg n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ を fold する
    - 時間計算量: $O(1)$

## Reference

- [Sqrt-tree: answering queries in O(1) with O(NloglogN) preprocessing.](https://codeforces.com/blog/entry/57046)
- [Sqrt-tree (part 2): modifications in O(sqrtN), lazy propagation](https://codeforces.com/blog/entry/59092)
- [OPTIMAL PREPROCESSING FOR
ANSWERING ON-LINE PRODUCT QUERIES](https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.79.1554&rep=rep1&type=pdf)

## TODO

- update 実装
- 遅延伝搬
- 論文 読む