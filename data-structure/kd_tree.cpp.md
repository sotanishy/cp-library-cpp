---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C.test.cpp
    title: test/aoj/DSL_2_C.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/kd_tree.md
    document_title: k-d Tree
    links: []
  bundledCode: "#line 2 \"data-structure/kd_tree.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\n/*\n * @brief k-d Tree\n * @docs docs/data-structure/kd_tree.md\n\
    \ */\ntemplate <typename T>\nclass KDTree {\npublic:\n    void add_point(int id,\
    \ T x, T y) {\n        points.emplace_back(id, x, y);\n    }\n\n    void build()\
    \ {\n        build(0, points.size() - 1, 0);\n    }\n\n    std::vector<int> search(T\
    \ sx, T tx, T sy, T ty) const {\n        Point s(std::min(sx, tx), std::min(sy,\
    \ ty));\n        Point t(std::max(sx, tx), std::max(sy, ty));\n        std::vector<int>\
    \ res;\n        search(s, t, res, 0, points.size() - 1, 0);\n        return res;\n\
    \    }\n\nprivate:\n    struct Point {\n        int id;\n        T x, y;\n   \
    \     Point(T x, T y) : x(x), y(y) {}\n        Point(int id, T x, T y) : id(id),\
    \ x(x), y(y) {}\n    };\n\n    std::vector<Point> points;\n\n    int check_position(const\
    \ Point& p, const Point& s, const Point& t, int axis) const {\n        if (axis\
    \ == 0) {\n            if (p.x < s.x) return -1;\n            if (t.x < p.x) return\
    \ 1;\n            return 0;\n        } else {\n            if (p.y < s.y) return\
    \ -1;\n            if (t.y < p.y) return 1;\n            return 0;\n        }\n\
    \    }\n\n    void build(int l, int r, int axis) {\n        if (l > r) return;\n\
    \        std::sort(points.begin() + l, points.begin() + r + 1, [&](const auto&\
    \ p1, const auto& p2) {\n            return axis == 0 ? p1.x < p2.x : p1.y < p2.y;\n\
    \        });\n        int m = (l + r) / 2;\n        build(l, m - 1, 1 - axis);\n\
    \        build(m + 1, r, 1 - axis);\n    }\n\n    void search(const Point& s,\
    \ const Point& t, std::vector<int>& res, int l, int r, int axis) const {\n   \
    \     if (l > r) return;\n        int m = (l + r) / 2;\n        bool contained\
    \ = true;\n        for (int i = 0; i < 2; i++) contained &= check_position(points[m],\
    \ s, t, i) == 0;\n        if (contained) res.push_back(points[m].id);\n      \
    \  if (l == r) return;\n        int pos = check_position(points[m], s, t, axis);\n\
    \        if (pos != -1) search(s, t, res, l, m - 1, 1 - axis);\n        if (pos\
    \ != 1) search(s, t, res, m + 1, r, 1 - axis);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n/*\n * @brief k-d\
    \ Tree\n * @docs docs/data-structure/kd_tree.md\n */\ntemplate <typename T>\n\
    class KDTree {\npublic:\n    void add_point(int id, T x, T y) {\n        points.emplace_back(id,\
    \ x, y);\n    }\n\n    void build() {\n        build(0, points.size() - 1, 0);\n\
    \    }\n\n    std::vector<int> search(T sx, T tx, T sy, T ty) const {\n      \
    \  Point s(std::min(sx, tx), std::min(sy, ty));\n        Point t(std::max(sx,\
    \ tx), std::max(sy, ty));\n        std::vector<int> res;\n        search(s, t,\
    \ res, 0, points.size() - 1, 0);\n        return res;\n    }\n\nprivate:\n   \
    \ struct Point {\n        int id;\n        T x, y;\n        Point(T x, T y) :\
    \ x(x), y(y) {}\n        Point(int id, T x, T y) : id(id), x(x), y(y) {}\n   \
    \ };\n\n    std::vector<Point> points;\n\n    int check_position(const Point&\
    \ p, const Point& s, const Point& t, int axis) const {\n        if (axis == 0)\
    \ {\n            if (p.x < s.x) return -1;\n            if (t.x < p.x) return\
    \ 1;\n            return 0;\n        } else {\n            if (p.y < s.y) return\
    \ -1;\n            if (t.y < p.y) return 1;\n            return 0;\n        }\n\
    \    }\n\n    void build(int l, int r, int axis) {\n        if (l > r) return;\n\
    \        std::sort(points.begin() + l, points.begin() + r + 1, [&](const auto&\
    \ p1, const auto& p2) {\n            return axis == 0 ? p1.x < p2.x : p1.y < p2.y;\n\
    \        });\n        int m = (l + r) / 2;\n        build(l, m - 1, 1 - axis);\n\
    \        build(m + 1, r, 1 - axis);\n    }\n\n    void search(const Point& s,\
    \ const Point& t, std::vector<int>& res, int l, int r, int axis) const {\n   \
    \     if (l > r) return;\n        int m = (l + r) / 2;\n        bool contained\
    \ = true;\n        for (int i = 0; i < 2; i++) contained &= check_position(points[m],\
    \ s, t, i) == 0;\n        if (contained) res.push_back(points[m].id);\n      \
    \  if (l == r) return;\n        int pos = check_position(points[m], s, t, axis);\n\
    \        if (pos != -1) search(s, t, res, l, m - 1, 1 - axis);\n        if (pos\
    \ != 1) search(s, t, res, m + 1, r, 1 - axis);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/kd_tree.cpp
  requiredBy: []
  timestamp: '2020-11-02 20:03:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_C.test.cpp
documentation_of: data-structure/kd_tree.cpp
layout: document
redirect_from:
- /library/data-structure/kd_tree.cpp
- /library/data-structure/kd_tree.cpp.html
title: k-d Tree
---
# k-d Tree

k-d 木は，$k$ 次元空間の点を保持し，効率的に範囲探索を行うデータ構造である．

この実装は2次元空間の長方形領域の探索を提供する．

空間計算量: $O(n)$

## Member functions

- `void add_point(int id, T x, T y)`
    - ラベル `id` の点 $(x, y)$ を追加する
    - 時間計算量: $O(1)$
- `void build()`
    - k-d 木を構築する
    - 時間計算量: $O(n\lg^2 n)$
- `vector<int> search(T sx, T tx, T sy, T ty)`
    -  $(sx, sy)$ から $(tx, ty)$ までの長方形領域内の点のラベルを返す
    - 時間計算量: $O(\sqrt{N} + m)$．$m$ は領域内の点の数

## Reference

- [kd木](https://ja.wikipedia.org/wiki/Kd%E6%9C%A8)

## TODO

- $k$ 次元への拡張
- 最近傍点探索
- `insert`, `erase` の実装
- 線形中央値探索による $O(n\lg n)$ での構築