---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/range_tree.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nclass RangeTree {\npublic:\n    RangeTree() = default;\n\
    \    explicit RangeTree(int n) {\n        size = 1;\n        while (size < n)\
    \ size <<= 1;\n        node.resize(2 * size);\n    }\n\n    void add_point(int\
    \ x, int y) {\n        node[size + x].push_back(y);\n    }\n\n    void build()\
    \ {\n        for (int i = 0; i < size; ++i) {\n            sort(node[size + i].begin(),\
    \ node[size + i].end());\n        }\n        for (int i = size - 1; i > 0; --i)\
    \ {\n            std::merge(node[2*i].begin(), node[2*i].end(), node[2*i+1].begin(),\
    \ node[2*i+1].end(), std::back_inserter(node[i]));\n        }\n    }\n\n    int\
    \ count(int sx, int tx, int sy, int ty) const {\n        int cnt = 0;\n      \
    \  for (int l = size + sx, r = size + tx; l < r; l >>= 1, r >>= 1) {\n       \
    \     if (l & 1) {\n                auto hi = std::lower_bound(node[l].begin(),\
    \ node[l].end(), ty);\n                auto lo = std::lower_bound(node[l].begin(),\
    \ node[l].end(), sy);\n                cnt += hi - lo;\n                ++l;\n\
    \            }\n            if (r & 1) {\n                --r;\n             \
    \   auto hi = std::lower_bound(node[r].begin(), node[r].end(), ty);\n        \
    \        auto lo = std::lower_bound(node[r].begin(), node[r].end(), sy);\n   \
    \             cnt += hi - lo;\n            }\n        }\n        return cnt;\n\
    \    }\n\n\nprivate:\n    int size;\n    std::vector<std::vector<int>> node;\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nclass RangeTree\
    \ {\npublic:\n    RangeTree() = default;\n    explicit RangeTree(int n) {\n  \
    \      size = 1;\n        while (size < n) size <<= 1;\n        node.resize(2\
    \ * size);\n    }\n\n    void add_point(int x, int y) {\n        node[size + x].push_back(y);\n\
    \    }\n\n    void build() {\n        for (int i = 0; i < size; ++i) {\n     \
    \       sort(node[size + i].begin(), node[size + i].end());\n        }\n     \
    \   for (int i = size - 1; i > 0; --i) {\n            std::merge(node[2*i].begin(),\
    \ node[2*i].end(), node[2*i+1].begin(), node[2*i+1].end(), std::back_inserter(node[i]));\n\
    \        }\n    }\n\n    int count(int sx, int tx, int sy, int ty) const {\n \
    \       int cnt = 0;\n        for (int l = size + sx, r = size + tx; l < r; l\
    \ >>= 1, r >>= 1) {\n            if (l & 1) {\n                auto hi = std::lower_bound(node[l].begin(),\
    \ node[l].end(), ty);\n                auto lo = std::lower_bound(node[l].begin(),\
    \ node[l].end(), sy);\n                cnt += hi - lo;\n                ++l;\n\
    \            }\n            if (r & 1) {\n                --r;\n             \
    \   auto hi = std::lower_bound(node[r].begin(), node[r].end(), ty);\n        \
    \        auto lo = std::lower_bound(node[r].begin(), node[r].end(), sy);\n   \
    \             cnt += hi - lo;\n            }\n        }\n        return cnt;\n\
    \    }\n\n\nprivate:\n    int size;\n    std::vector<std::vector<int>> node;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range_tree.cpp
  requiredBy: []
  timestamp: '2021-07-29 21:53:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/range_tree.cpp
layout: document
title: Range Tree
---

## Description

領域木は，2次元平面の長方形領域内の点の個数を効率的に数えるデータ構造である．

空間計算量: $O(n\lg n)$

## Operations

- `void add_point(int x, int y)`
    - 点 $(x, y)$ を追加する
    - 時間計算量: $O(1)$
- `void build()`
    - 領域木を構築する
    - 点 $(x, y)$ を追加する
    - 時間計算量: $O(n\lg n)$
- `int count(int sx, int tx, int sy, int ty)`
    - 長方形領域 $[sx, tx) \times [sy, ty)$ 内の点の個数を返す
    - 時間計算量: $O(\lg^2 n)$

## Reference

- [領域木の布教](https://mugen1337.hatenablog.com/entry/2021/05/22/224041)
