---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/staticrmq.sqrt_tree.test.cpp
    title: test/yosupo/staticrmq.sqrt_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sqrt_tree.hpp\"\n#include <algorithm>\n#include\
    \ <bit>\n#include <vector>\n\ntemplate <typename S>\nclass SqrtTree {\n    using\
    \ T = S::T;\n\n   public:\n    SqrtTree() = default;\n    explicit SqrtTree(const\
    \ std::vector<T>& v) : v(v) {\n        const int n = v.size(), lg = std::bit_width(n);\n\
    \        on_layer.resize(lg + 1);\n        int n_layer = 0;\n        for (int\
    \ i = lg; i > 1; i = (i + 1) / 2) {\n            on_layer[i] = n_layer++;\n  \
    \          layer_lg.push_back(i);\n        }\n        for (int i = lg - 1; i >=\
    \ 0; --i)\n            on_layer[i] = std::max(on_layer[i], on_layer[i + 1]);\n\
    \        pref.resize(n_layer, std::vector<T>(n));\n        suf.resize(n_layer,\
    \ std::vector<T>(n));\n        btwn.resize(n_layer, std::vector<T>(1 << lg));\n\
    \n        for (int layer = 0; layer < n_layer; ++layer) {\n            int prev_b_sz\
    \ = 1 << layer_lg[layer];\n            int b_sz = 1 << ((layer_lg[layer] + 1)\
    \ / 2);\n            int b_cnt = 1 << (layer_lg[layer] / 2);\n\n            for\
    \ (int l = 0; l < n; l += prev_b_sz) {\n                int r = std::min(l + prev_b_sz,\
    \ n);\n\n                // calculate pref and suf\n                for (int a\
    \ = l; a < r; a += b_sz) {\n                    int b = std::min(a + b_sz, r);\n\
    \                    pref[layer][a] = v[a];\n                    for (int i =\
    \ a + 1; i < b; ++i) {\n                        pref[layer][i] = S::op(pref[layer][i\
    \ - 1], v[i]);\n                    }\n                    suf[layer][b - 1] =\
    \ v[b - 1];\n                    for (int i = b - 2; i >= a; --i) {\n        \
    \                suf[layer][i] = S::op(v[i], suf[layer][i + 1]);\n           \
    \         }\n                }\n                // calculate btwn\n          \
    \      for (int i = 0; i < b_cnt; ++i) {\n                    T val = suf[layer][l\
    \ + i * b_sz];\n                    btwn[layer][l + i * b_cnt + i] = val;\n  \
    \                  for (int j = i + 1; j < b_cnt; ++j) {\n                   \
    \     val = S::op(val, suf[layer][l + j * b_sz]);\n                        btwn[layer][l\
    \ + i * b_cnt + j] = val;\n                    }\n                }\n        \
    \    }\n        }\n    }\n\n    T fold(int l, int r) const {\n        --r;\n \
    \       if (l == r) return v[l];\n        if (l + 1 == r) return S::op(v[l], v[r]);\n\
    \        int layer = on_layer[std::bit_width((unsigned int)(l ^ r))];\n      \
    \  int b_sz = 1 << ((layer_lg[layer] + 1) / 2);\n        int b_cnt = 1 << (layer_lg[layer]\
    \ / 2);\n        int a = (l >> layer_lg[layer]) << layer_lg[layer];\n        int\
    \ lblock = (l - a) / b_sz + 1;\n        int rblock = (r - a) / b_sz - 1;\n   \
    \     T val = suf[layer][l];\n        if (lblock <= rblock)\n            val =\
    \ S::op(val, btwn[layer][a + lblock * b_cnt + rblock]);\n        val = S::op(val,\
    \ pref[layer][r]);\n        return val;\n    }\n\n   private:\n    std::vector<int>\
    \ layer_lg, on_layer;\n    std::vector<T> v;\n    std::vector<std::vector<T>>\
    \ pref, suf, btwn;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <vector>\n\n\
    template <typename S>\nclass SqrtTree {\n    using T = S::T;\n\n   public:\n \
    \   SqrtTree() = default;\n    explicit SqrtTree(const std::vector<T>& v) : v(v)\
    \ {\n        const int n = v.size(), lg = std::bit_width(n);\n        on_layer.resize(lg\
    \ + 1);\n        int n_layer = 0;\n        for (int i = lg; i > 1; i = (i + 1)\
    \ / 2) {\n            on_layer[i] = n_layer++;\n            layer_lg.push_back(i);\n\
    \        }\n        for (int i = lg - 1; i >= 0; --i)\n            on_layer[i]\
    \ = std::max(on_layer[i], on_layer[i + 1]);\n        pref.resize(n_layer, std::vector<T>(n));\n\
    \        suf.resize(n_layer, std::vector<T>(n));\n        btwn.resize(n_layer,\
    \ std::vector<T>(1 << lg));\n\n        for (int layer = 0; layer < n_layer; ++layer)\
    \ {\n            int prev_b_sz = 1 << layer_lg[layer];\n            int b_sz =\
    \ 1 << ((layer_lg[layer] + 1) / 2);\n            int b_cnt = 1 << (layer_lg[layer]\
    \ / 2);\n\n            for (int l = 0; l < n; l += prev_b_sz) {\n            \
    \    int r = std::min(l + prev_b_sz, n);\n\n                // calculate pref\
    \ and suf\n                for (int a = l; a < r; a += b_sz) {\n             \
    \       int b = std::min(a + b_sz, r);\n                    pref[layer][a] = v[a];\n\
    \                    for (int i = a + 1; i < b; ++i) {\n                     \
    \   pref[layer][i] = S::op(pref[layer][i - 1], v[i]);\n                    }\n\
    \                    suf[layer][b - 1] = v[b - 1];\n                    for (int\
    \ i = b - 2; i >= a; --i) {\n                        suf[layer][i] = S::op(v[i],\
    \ suf[layer][i + 1]);\n                    }\n                }\n            \
    \    // calculate btwn\n                for (int i = 0; i < b_cnt; ++i) {\n  \
    \                  T val = suf[layer][l + i * b_sz];\n                    btwn[layer][l\
    \ + i * b_cnt + i] = val;\n                    for (int j = i + 1; j < b_cnt;\
    \ ++j) {\n                        val = S::op(val, suf[layer][l + j * b_sz]);\n\
    \                        btwn[layer][l + i * b_cnt + j] = val;\n             \
    \       }\n                }\n            }\n        }\n    }\n\n    T fold(int\
    \ l, int r) const {\n        --r;\n        if (l == r) return v[l];\n        if\
    \ (l + 1 == r) return S::op(v[l], v[r]);\n        int layer = on_layer[std::bit_width((unsigned\
    \ int)(l ^ r))];\n        int b_sz = 1 << ((layer_lg[layer] + 1) / 2);\n     \
    \   int b_cnt = 1 << (layer_lg[layer] / 2);\n        int a = (l >> layer_lg[layer])\
    \ << layer_lg[layer];\n        int lblock = (l - a) / b_sz + 1;\n        int rblock\
    \ = (r - a) / b_sz - 1;\n        T val = suf[layer][l];\n        if (lblock <=\
    \ rblock)\n            val = S::op(val, btwn[layer][a + lblock * b_cnt + rblock]);\n\
    \        val = S::op(val, pref[layer][r]);\n        return val;\n    }\n\n   private:\n\
    \    std::vector<int> layer_lg, on_layer;\n    std::vector<T> v;\n    std::vector<std::vector<T>>\
    \ pref, suf, btwn;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sqrt_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/staticrmq.sqrt_tree.test.cpp
documentation_of: data-structure/sqrt_tree.hpp
layout: document
title: Sqrt Tree
---

## Description

Sqrt tree は，半群 $(T, \cdot)$ の静的な列の区間和を高速に計算するデータ構造である．平方分割を再帰的に行うことで木の高さを $O(\log\log n)$ にしている．Sparse table と比べて前処理が高速でメモリ使用量が少ないという特徴がある．

ここでは実装していないが，$O(\sqrt{N})$ で要素の更新も可能である．

空間計算量: $O(n\log\log n)$

## Operations

- `SqrtTree(vector<T> v)`
    - `v` から sqrt tree を構築する
    - 時間計算量: $O(n\log\log n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ を fold する
    - 時間計算量: $O(1)$

## Reference

- [Sqrt-tree: answering queries in O(1) with O(NloglogN) preprocessing.](https://codeforces.com/blog/entry/57046)
- [Sqrt-tree (part 2): modifications in O(sqrtN), lazy propagation](https://codeforces.com/blog/entry/59092)
- [OPTIMAL PREPROCESSING FOR ANSWERING ON-LINE PRODUCT QUERIES](https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.79.1554&rep=rep1&type=pdf)