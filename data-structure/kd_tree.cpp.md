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
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/kd_tree.md
    document_title: k-d Tree
    links: []
  bundledCode: "#line 1 \"data-structure/kd_tree.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief k-d Tree\n * @docs docs/data-structure/kd_tree.md\n */\ntemplate\
    \ <typename T>\nclass KDTree {\npublic:\n    void add_point(int id, T x, T y)\
    \ {\n        points.emplace_back(id, x, y);\n    }\n\n    void build() {\n   \
    \     build(0, points.size() - 1, 0);\n    }\n\n    std::vector<int> search(T\
    \ sx, T tx, T sy, T ty) const {\n        Point s(std::min(sx, tx), std::min(sy,\
    \ ty));\n        Point t(std::max(sx, tx), std::max(sy, ty));\n        std::vector<int>\
    \ res;\n        search(s, t, res, 0, points.size() - 1, 0);\n        return res;\n\
    \    }\n\nprivate:\n    struct Point {\n        int id;\n        T x, y;\n   \
    \     Point(T x, T y) : x(x), y(y) {}\n        Point(int id, T x, T y) : id(id),\
    \ x(x), y(y) {}\n    };\n\n    std::vector<Point> points;\n\n    int check_position(const\
    \ Point& point, const Point& start, const Point& end, int axis) const {\n    \
    \    if (axis == 0) {\n            if (start.x <= point.x && point.x <= end.x)\
    \ return 0;\n            if (point.x < start.x) return -1;\n            return\
    \ 1;\n        } else {\n            if (start.y <= point.y && point.y <= end.y)\
    \ return 0;\n            if (point.y < start.y) return -1;\n            return\
    \ 1;\n        }\n    }\n\n    void build(int left, int right, int depth) {\n \
    \       if (left > right) return;\n\n        int axis = depth % 2;\n        if\
    \ (axis == 0) {\n            std::sort(points.begin() + left, points.begin() +\
    \ right + 1, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });\n  \
    \      } else {\n            std::sort(points.begin() + left, points.begin() +\
    \ right + 1, [](const auto& p1, const auto& p2) { return p1.y < p2.y; });\n  \
    \      }\n        int mid = (left + right) / 2;\n        build(left, mid - 1,\
    \ depth + 1);\n        build(mid + 1, right, depth + 1);\n    }\n\n    void search(const\
    \ Point& start, const Point& end, std::vector<int>& res, int left, int right,\
    \ int depth) const {\n        if (left > right) return;\n\n        int axis =\
    \ depth % 2;\n        int mid = (left + right) / 2;\n        bool contained =\
    \ true;\n        for (int i = 0; i < 2; i++) contained &= check_position(points[mid],\
    \ start, end, i) == 0;\n        if (contained) res.push_back(points[mid].id);\n\
    \        if (left == right) return;\n        int pos = check_position(points[mid],\
    \ start, end, axis);\n        if (pos != -1) search(start, end, res, left, mid\
    \ - 1, depth + 1);\n        if (pos != 1) search(start, end, res, mid + 1, right,\
    \ depth + 1);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief k-d Tree\n * @docs docs/data-structure/kd_tree.md\n\
    \ */\ntemplate <typename T>\nclass KDTree {\npublic:\n    void add_point(int id,\
    \ T x, T y) {\n        points.emplace_back(id, x, y);\n    }\n\n    void build()\
    \ {\n        build(0, points.size() - 1, 0);\n    }\n\n    std::vector<int> search(T\
    \ sx, T tx, T sy, T ty) const {\n        Point s(std::min(sx, tx), std::min(sy,\
    \ ty));\n        Point t(std::max(sx, tx), std::max(sy, ty));\n        std::vector<int>\
    \ res;\n        search(s, t, res, 0, points.size() - 1, 0);\n        return res;\n\
    \    }\n\nprivate:\n    struct Point {\n        int id;\n        T x, y;\n   \
    \     Point(T x, T y) : x(x), y(y) {}\n        Point(int id, T x, T y) : id(id),\
    \ x(x), y(y) {}\n    };\n\n    std::vector<Point> points;\n\n    int check_position(const\
    \ Point& point, const Point& start, const Point& end, int axis) const {\n    \
    \    if (axis == 0) {\n            if (start.x <= point.x && point.x <= end.x)\
    \ return 0;\n            if (point.x < start.x) return -1;\n            return\
    \ 1;\n        } else {\n            if (start.y <= point.y && point.y <= end.y)\
    \ return 0;\n            if (point.y < start.y) return -1;\n            return\
    \ 1;\n        }\n    }\n\n    void build(int left, int right, int depth) {\n \
    \       if (left > right) return;\n\n        int axis = depth % 2;\n        if\
    \ (axis == 0) {\n            std::sort(points.begin() + left, points.begin() +\
    \ right + 1, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });\n  \
    \      } else {\n            std::sort(points.begin() + left, points.begin() +\
    \ right + 1, [](const auto& p1, const auto& p2) { return p1.y < p2.y; });\n  \
    \      }\n        int mid = (left + right) / 2;\n        build(left, mid - 1,\
    \ depth + 1);\n        build(mid + 1, right, depth + 1);\n    }\n\n    void search(const\
    \ Point& start, const Point& end, std::vector<int>& res, int left, int right,\
    \ int depth) const {\n        if (left > right) return;\n\n        int axis =\
    \ depth % 2;\n        int mid = (left + right) / 2;\n        bool contained =\
    \ true;\n        for (int i = 0; i < 2; i++) contained &= check_position(points[mid],\
    \ start, end, i) == 0;\n        if (contained) res.push_back(points[mid].id);\n\
    \        if (left == right) return;\n        int pos = check_position(points[mid],\
    \ start, end, axis);\n        if (pos != -1) search(start, end, res, left, mid\
    \ - 1, depth + 1);\n        if (pos != 1) search(start, end, res, mid + 1, right,\
    \ depth + 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/kd_tree.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
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

この k-d 木は2次元空間の長方形領域の探索を実現する．

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