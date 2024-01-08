---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum.range_tree.test.cpp
    title: test/yosupo/rectangle_sum.range_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/range_tree.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <utility>\n#include <vector>\n\ntemplate <typename X,\
    \ typename Y, typename T>\nclass RangeTree {\n   public:\n    RangeTree() = default;\n\
    \    explicit RangeTree(const std::vector<std::tuple<X, Y, T>>& pts) {\n     \
    \   for (auto& [x, y, v] : pts) xs.push_back(x);\n        std::ranges::sort(xs);\n\
    \        xs.erase(std::ranges::unique(xs).begin(), xs.end());\n\n        const\
    \ int n = xs.size();\n        size = std::bit_ceil((unsigned int)n);\n\n     \
    \   node.resize(2 * size);\n        sum.resize(2 * size);\n\n        for (auto&\
    \ [x, y, v] : pts) {\n            int i = std::ranges::lower_bound(xs, x) - xs.begin();\n\
    \            node[size + i].emplace_back(y, v);\n        }\n\n        for (int\
    \ i = 0; i < n; ++i) {\n            std::ranges::sort(node[size + i]);\n     \
    \   }\n        for (int i = size - 1; i > 0; --i) {\n            std::ranges::merge(node[2\
    \ * i], node[2 * i + 1],\n                               std::back_inserter(node[i]));\n\
    \        }\n        for (int i = 0; i < size + n; ++i) {\n            sum[i].resize(node[i].size()\
    \ + 1);\n            for (int j = 0; j < (int)node[i].size(); ++j) {\n       \
    \         sum[i][j + 1] = sum[i][j] + node[i][j].second;\n            }\n    \
    \    }\n    }\n\n    T fold(X sx, X tx, Y sy, Y ty) const {\n        int l = std::ranges::lower_bound(xs,\
    \ sx) - xs.begin();\n        int r = std::ranges::lower_bound(xs, tx) - xs.begin();\n\
    \        T ret = 0;\n        auto proj = [&](const auto& p) { return p.first;\
    \ };\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n        \
    \    if (l & 1) {\n                int hi = std::ranges::lower_bound(node[l],\
    \ ty, {}, proj) -\n                         node[l].begin();\n               \
    \ int lo = std::ranges::lower_bound(node[l], sy, {}, proj) -\n               \
    \          node[l].begin();\n                ret += sum[l][hi] - sum[l][lo];\n\
    \                ++l;\n            }\n            if (r & 1) {\n             \
    \   --r;\n                int hi = std::ranges::lower_bound(node[r], ty, {}, proj)\
    \ -\n                         node[r].begin();\n                int lo = std::ranges::lower_bound(node[r],\
    \ sy, {}, proj) -\n                         node[r].begin();\n               \
    \ ret += sum[r][hi] - sum[r][lo];\n            }\n        }\n        return ret;\n\
    \    }\n\n   private:\n    int size;\n    std::vector<X> xs;\n    std::vector<std::vector<std::pair<Y,\
    \ T>>> node;\n    std::vector<std::vector<T>> sum;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename X, typename Y, typename T>\nclass RangeTree\
    \ {\n   public:\n    RangeTree() = default;\n    explicit RangeTree(const std::vector<std::tuple<X,\
    \ Y, T>>& pts) {\n        for (auto& [x, y, v] : pts) xs.push_back(x);\n     \
    \   std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n\n        const int n = xs.size();\n        size = std::bit_ceil((unsigned\
    \ int)n);\n\n        node.resize(2 * size);\n        sum.resize(2 * size);\n\n\
    \        for (auto& [x, y, v] : pts) {\n            int i = std::ranges::lower_bound(xs,\
    \ x) - xs.begin();\n            node[size + i].emplace_back(y, v);\n        }\n\
    \n        for (int i = 0; i < n; ++i) {\n            std::ranges::sort(node[size\
    \ + i]);\n        }\n        for (int i = size - 1; i > 0; --i) {\n          \
    \  std::ranges::merge(node[2 * i], node[2 * i + 1],\n                        \
    \       std::back_inserter(node[i]));\n        }\n        for (int i = 0; i <\
    \ size + n; ++i) {\n            sum[i].resize(node[i].size() + 1);\n         \
    \   for (int j = 0; j < (int)node[i].size(); ++j) {\n                sum[i][j\
    \ + 1] = sum[i][j] + node[i][j].second;\n            }\n        }\n    }\n\n \
    \   T fold(X sx, X tx, Y sy, Y ty) const {\n        int l = std::ranges::lower_bound(xs,\
    \ sx) - xs.begin();\n        int r = std::ranges::lower_bound(xs, tx) - xs.begin();\n\
    \        T ret = 0;\n        auto proj = [&](const auto& p) { return p.first;\
    \ };\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n        \
    \    if (l & 1) {\n                int hi = std::ranges::lower_bound(node[l],\
    \ ty, {}, proj) -\n                         node[l].begin();\n               \
    \ int lo = std::ranges::lower_bound(node[l], sy, {}, proj) -\n               \
    \          node[l].begin();\n                ret += sum[l][hi] - sum[l][lo];\n\
    \                ++l;\n            }\n            if (r & 1) {\n             \
    \   --r;\n                int hi = std::ranges::lower_bound(node[r], ty, {}, proj)\
    \ -\n                         node[r].begin();\n                int lo = std::ranges::lower_bound(node[r],\
    \ sy, {}, proj) -\n                         node[r].begin();\n               \
    \ ret += sum[r][hi] - sum[r][lo];\n            }\n        }\n        return ret;\n\
    \    }\n\n   private:\n    int size;\n    std::vector<X> xs;\n    std::vector<std::vector<std::pair<Y,\
    \ T>>> node;\n    std::vector<std::vector<T>> sum;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 16:18:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rectangle_sum.range_tree.test.cpp
documentation_of: data-structure/range_tree.hpp
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
