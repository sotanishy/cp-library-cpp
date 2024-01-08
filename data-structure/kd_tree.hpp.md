---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C.test.cpp
    title: test/aoj/DSL_2_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/kd_tree.hpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <vector>\n\ntemplate <typename T>\nclass KDTree {\n   public:\n\
    \    void add_point(int id, T x, T y) { points.emplace_back(id, x, y); }\n\n \
    \   void build() { build(0, points.size() - 1, 0); }\n\n    std::vector<int> search(T\
    \ sx, T tx, T sy, T ty) const {\n        Point s(std::min(sx, tx), std::min(sy,\
    \ ty));\n        Point t(std::max(sx, tx), std::max(sy, ty));\n        std::vector<int>\
    \ res;\n        search(s, t, res, 0, points.size() - 1, 0);\n        return res;\n\
    \    }\n\n   private:\n    struct Point {\n        int id;\n        T x, y;\n\
    \        Point(T x, T y) : x(x), y(y) {}\n        Point(int id, T x, T y) : id(id),\
    \ x(x), y(y) {}\n    };\n\n    std::vector<Point> points;\n\n    int check_position(const\
    \ Point& p, const Point& s, const Point& t,\n                       bool axis)\
    \ const {\n        if (axis == 0) {\n            if (p.x < s.x) return -1;\n \
    \           if (t.x < p.x) return 1;\n            return 0;\n        } else {\n\
    \            if (p.y < s.y) return -1;\n            if (t.y < p.y) return 1;\n\
    \            return 0;\n        }\n    }\n\n    void build(int l, int r, bool\
    \ axis) {\n        if (l > r) return;\n        std::ranges::sort(points.begin()\
    \ + l, points.begin() + r + 1, {},\n                          [&](auto& p) { return\
    \ axis == 0 ? p.x : p.y; });\n        int m = std::midpoint(l, r);\n        build(l,\
    \ m - 1, axis ^ 1);\n        build(m + 1, r, axis ^ 1);\n    }\n\n    void search(const\
    \ Point& s, const Point& t, std::vector<int>& res, int l,\n                int\
    \ r, bool axis) const {\n        if (l > r) return;\n        int m = std::midpoint(l,\
    \ r);\n        bool contained = true;\n        for (int i = 0; i < 2; i++)\n \
    \           contained &= check_position(points[m], s, t, i) == 0;\n        if\
    \ (contained) res.push_back(points[m].id);\n        if (l == r) return;\n    \
    \    int pos = check_position(points[m], s, t, axis);\n        if (pos != -1)\
    \ search(s, t, res, l, m - 1, axis ^ 1);\n        if (pos != 1) search(s, t, res,\
    \ m + 1, r, axis ^ 1);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    \ntemplate <typename T>\nclass KDTree {\n   public:\n    void add_point(int id,\
    \ T x, T y) { points.emplace_back(id, x, y); }\n\n    void build() { build(0,\
    \ points.size() - 1, 0); }\n\n    std::vector<int> search(T sx, T tx, T sy, T\
    \ ty) const {\n        Point s(std::min(sx, tx), std::min(sy, ty));\n        Point\
    \ t(std::max(sx, tx), std::max(sy, ty));\n        std::vector<int> res;\n    \
    \    search(s, t, res, 0, points.size() - 1, 0);\n        return res;\n    }\n\
    \n   private:\n    struct Point {\n        int id;\n        T x, y;\n        Point(T\
    \ x, T y) : x(x), y(y) {}\n        Point(int id, T x, T y) : id(id), x(x), y(y)\
    \ {}\n    };\n\n    std::vector<Point> points;\n\n    int check_position(const\
    \ Point& p, const Point& s, const Point& t,\n                       bool axis)\
    \ const {\n        if (axis == 0) {\n            if (p.x < s.x) return -1;\n \
    \           if (t.x < p.x) return 1;\n            return 0;\n        } else {\n\
    \            if (p.y < s.y) return -1;\n            if (t.y < p.y) return 1;\n\
    \            return 0;\n        }\n    }\n\n    void build(int l, int r, bool\
    \ axis) {\n        if (l > r) return;\n        std::ranges::sort(points.begin()\
    \ + l, points.begin() + r + 1, {},\n                          [&](auto& p) { return\
    \ axis == 0 ? p.x : p.y; });\n        int m = std::midpoint(l, r);\n        build(l,\
    \ m - 1, axis ^ 1);\n        build(m + 1, r, axis ^ 1);\n    }\n\n    void search(const\
    \ Point& s, const Point& t, std::vector<int>& res, int l,\n                int\
    \ r, bool axis) const {\n        if (l > r) return;\n        int m = std::midpoint(l,\
    \ r);\n        bool contained = true;\n        for (int i = 0; i < 2; i++)\n \
    \           contained &= check_position(points[m], s, t, i) == 0;\n        if\
    \ (contained) res.push_back(points[m].id);\n        if (l == r) return;\n    \
    \    int pos = check_position(points[m], s, t, axis);\n        if (pos != -1)\
    \ search(s, t, res, l, m - 1, axis ^ 1);\n        if (pos != 1) search(s, t, res,\
    \ m + 1, r, axis ^ 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/kd_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 11:43:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_C.test.cpp
documentation_of: data-structure/kd_tree.hpp
layout: document
title: k-d Tree
---

## Description

k-d 木は，$k$ 次元空間の点を保持し，効率的に範囲探索を行うデータ構造である．この実装は2次元空間の長方形領域の探索を提供する．

空間計算量: $O(n)$

## Operations

- `void add_point(int id, T x, T y)`
    - ラベル `id` の点 $(x, y)$ を追加する
    - 時間計算量: $O(1)$
- `void build()`
    - k-d 木を構築する
    - 時間計算量: $O(n\log^2 n)$
- `vector<int> search(T sx, T tx, T sy, T ty)`
    -  $(sx, sy)$ から $(tx, ty)$ までの長方形領域内の点のラベルを返す
    - 時間計算量: $O(\sqrt{N} + m)$．$m$ は領域内の点の数

## Reference

- [kd木](https://ja.wikipedia.org/wiki/Kd%E6%9C%A8)