---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum.range_tree.test.cpp
    title: test/yosupo/rectangle_sum.range_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/range_tree.cpp\"\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename X, typename Y, typename\
    \ T>\nclass RangeTree {\npublic:\n    RangeTree() = default;\n    explicit RangeTree(const\
    \ std::vector<std::tuple<X, Y, T>>& pts) {\n        for (auto& [x, y, v] : pts)\
    \ xs.push_back(x);\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n\n        int n = xs.size();\n        size = 1;\n   \
    \     while (size < n) size <<= 1;\n        node.resize(2 * size);\n        sum.resize(2\
    \ * size);\n\n        for (auto& [x, y, v] : pts) {\n            int i = std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n            node[size + i].emplace_back(y, v);\n\
    \        }\n\n        for (int i = 0; i < n; ++i) {\n            std::sort(node[size\
    \ + i].begin(), node[size + i].end());\n        }\n        for (int i = size -\
    \ 1; i > 0; --i) {\n            std::merge(node[2*i].begin(), node[2*i].end(),\
    \ node[2*i+1].begin(), node[2*i+1].end(), std::back_inserter(node[i]));\n    \
    \    }\n        for (int i = 0; i < size + n; ++i) {\n            sum[i].resize(node[i].size()\
    \ + 1);\n            for (int j = 0; j < (int) node[i].size(); ++j) {\n      \
    \          sum[i][j + 1] = sum[i][j] + node[i][j].second;\n            }\n   \
    \     }\n    }\n\n    T fold(X sx, X tx, Y sy, Y ty) const {\n        int l =\
    \ std::lower_bound(xs.begin(), xs.end(), sx) - xs.begin();\n        int r = std::lower_bound(xs.begin(),\
    \ xs.end(), tx) - xs.begin();\n        T ret = 0;\n        auto cmp = [&](const\
    \ std::pair<Y, T>& p, Y y) { return p.first < y; };\n        for (l += size, r\
    \ += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n            \
    \    int hi = std::lower_bound(node[l].begin(), node[l].end(), ty, cmp) - node[l].begin();\n\
    \                int lo = std::lower_bound(node[l].begin(), node[l].end(), sy,\
    \ cmp) - node[l].begin();\n                ret += sum[l][hi] - sum[l][lo];\n \
    \               ++l;\n            }\n            if (r & 1) {\n              \
    \  --r;\n                int hi = std::lower_bound(node[r].begin(), node[r].end(),\
    \ ty, cmp) - node[r].begin();\n                int lo = std::lower_bound(node[r].begin(),\
    \ node[r].end(), sy, cmp) - node[r].begin();\n                ret += sum[r][hi]\
    \ - sum[r][lo];\n            }\n        }\n        return ret;\n    }\n\n\nprivate:\n\
    \    int size;\n    std::vector<X> xs;\n    std::vector<std::vector<std::pair<Y,\
    \ T>>> node;\n    std::vector<std::vector<T>> sum;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename X, typename Y, typename T>\nclass RangeTree {\npublic:\n\
    \    RangeTree() = default;\n    explicit RangeTree(const std::vector<std::tuple<X,\
    \ Y, T>>& pts) {\n        for (auto& [x, y, v] : pts) xs.push_back(x);\n     \
    \   std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n\n        int n = xs.size();\n        size = 1;\n   \
    \     while (size < n) size <<= 1;\n        node.resize(2 * size);\n        sum.resize(2\
    \ * size);\n\n        for (auto& [x, y, v] : pts) {\n            int i = std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n            node[size + i].emplace_back(y, v);\n\
    \        }\n\n        for (int i = 0; i < n; ++i) {\n            std::sort(node[size\
    \ + i].begin(), node[size + i].end());\n        }\n        for (int i = size -\
    \ 1; i > 0; --i) {\n            std::merge(node[2*i].begin(), node[2*i].end(),\
    \ node[2*i+1].begin(), node[2*i+1].end(), std::back_inserter(node[i]));\n    \
    \    }\n        for (int i = 0; i < size + n; ++i) {\n            sum[i].resize(node[i].size()\
    \ + 1);\n            for (int j = 0; j < (int) node[i].size(); ++j) {\n      \
    \          sum[i][j + 1] = sum[i][j] + node[i][j].second;\n            }\n   \
    \     }\n    }\n\n    T fold(X sx, X tx, Y sy, Y ty) const {\n        int l =\
    \ std::lower_bound(xs.begin(), xs.end(), sx) - xs.begin();\n        int r = std::lower_bound(xs.begin(),\
    \ xs.end(), tx) - xs.begin();\n        T ret = 0;\n        auto cmp = [&](const\
    \ std::pair<Y, T>& p, Y y) { return p.first < y; };\n        for (l += size, r\
    \ += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n            \
    \    int hi = std::lower_bound(node[l].begin(), node[l].end(), ty, cmp) - node[l].begin();\n\
    \                int lo = std::lower_bound(node[l].begin(), node[l].end(), sy,\
    \ cmp) - node[l].begin();\n                ret += sum[l][hi] - sum[l][lo];\n \
    \               ++l;\n            }\n            if (r & 1) {\n              \
    \  --r;\n                int hi = std::lower_bound(node[r].begin(), node[r].end(),\
    \ ty, cmp) - node[r].begin();\n                int lo = std::lower_bound(node[r].begin(),\
    \ node[r].end(), sy, cmp) - node[r].begin();\n                ret += sum[r][hi]\
    \ - sum[r][lo];\n            }\n        }\n        return ret;\n    }\n\n\nprivate:\n\
    \    int size;\n    std::vector<X> xs;\n    std::vector<std::vector<std::pair<Y,\
    \ T>>> node;\n    std::vector<std::vector<T>> sum;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range_tree.cpp
  requiredBy: []
  timestamp: '2022-12-25 14:40:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rectangle_sum.range_tree.test.cpp
documentation_of: data-structure/range_tree.cpp
layout: document
title: Range Tree
---

## Description

領域木は，2次元平面の長方形領域内の点に対する値の総和クエリを扱うデータ構造である．

空間計算量: $O(n\log n)$

## Operations

- `RangeTree(vector<tuple<int, Y, T>>> pts)`
    - `pts` の点から領域木を構築する．点は $(x, y, v)$ の形式で与えられる．
    - 時間計算量: $O(n\log n)$
- `T fold(X sx, X tx, Y sy, Y ty)`
    - 長方形領域 $[sx, tx) \times [sy, ty)$ 内の点に対する値の総和を計算する
    - 時間計算量: $O((\log n)^2)$

## Reference

- [領域木の布教](https://mugen1337.hatenablog.com/entry/2021/05/22/224041)
