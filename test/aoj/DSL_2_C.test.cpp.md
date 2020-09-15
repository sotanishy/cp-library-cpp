---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/kd_tree.cpp
    title: k-d Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
  bundledCode: "#line 1 \"test/aoj/DSL_2_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n\n#line 1 \"data-structure/kd_tree.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/*\n * @brief k-d Tree\n * @docs docs/data-structure/kd_tree.md\n */\n\
    template <typename T>\nstruct KDTree {\npublic:\n    void add_point(int id, T\
    \ x, T y) {\n        points.emplace_back(id, x, y);\n    }\n\n    void build()\
    \ {\n        build_rec(0, points.size() - 1, 0);\n    }\n\n    vector<int> search(T\
    \ sx, T tx, T sy, T ty) {\n        Point s(min(sx, tx), min(sy, ty));\n      \
    \  Point t(max(sx, tx), max(sy, ty));\n        vector<int> res;\n        search_rec(s,\
    \ t, res, 0, points.size() - 1, 0);\n        return res;\n    }\n\nprivate:\n\
    \    struct Point {\n        int id;\n        T x, y;\n        Point(T x, T y)\
    \ : x(x), y(y) {}\n        Point(int id, T x, T y) : id(id), x(x), y(y) {}\n \
    \   };\n\n    vector<Point> points;\n\n    int check_position(Point& point, Point&\
    \ start, Point& end, int axis) {\n        if (axis == 0) {\n            if (start.x\
    \ <= point.x && point.x <= end.x) return 0;\n            if (point.x < start.x)\
    \ return -1;\n            return 1;\n        } else {\n            if (start.y\
    \ <= point.y && point.y <= end.y) return 0;\n            if (point.y < start.y)\
    \ return -1;\n            return 1;\n        }\n    }\n\n    void build_rec(int\
    \ left, int right, int depth) {\n        if (left > right) return;\n\n       \
    \ int axis = depth % 2;\n        if (axis == 0) sort(points.begin() + left, points.begin()\
    \ + right + 1, [](const auto& p1, const auto& p2) { return p1.x < p2.x; });\n\
    \        else sort(points.begin() + left, points.begin() + right + 1, [](const\
    \ auto& p1, const auto& p2) { return p1.y < p2.y; });\n        int mid = (left\
    \ + right) / 2;\n        build_rec(left, mid - 1, depth + 1);\n        build_rec(mid\
    \ + 1, right, depth + 1);\n    }\n\n    void search_rec(Point& start, Point& end,\
    \ vector<int>& res, int left, int right, int depth) {\n        if (left > right)\
    \ return;\n\n        int axis = depth % 2;\n        int mid = (left + right) /\
    \ 2;\n        bool contained = true;\n        for (int i = 0; i < 2; i++) contained\
    \ &= check_position(points[mid], start, end, i) == 0;\n        if (contained)\
    \ res.push_back(points[mid].id);\n        if (left == right) return;\n       \
    \ int pos = check_position(points[mid], start, end, axis);\n        if (pos !=\
    \ -1) search_rec(start, end, res, left, mid - 1, depth + 1);\n        if (pos\
    \ != 1) search_rec(start, end, res, mid + 1, right, depth + 1);\n    }\n};\n#line\
    \ 4 \"test/aoj/DSL_2_C.test.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    KDTree<int> kd_tree;\n    for\
    \ (int i = 0; i < n; i++) {\n        int x, y;\n        cin >> x >> y;\n     \
    \   kd_tree.add_point(i, x, y);\n    }\n    kd_tree.build();\n    int q;\n   \
    \ cin >> q;\n    for (int i = 0; i < q; i++) {\n        int sx, tx, sy, ty;\n\
    \        cin >> sx >> tx >> sy >> ty;\n        auto res = kd_tree.search(sx, tx,\
    \ sy, ty);\n        sort(res.begin(), res.end());\n        for (int j : res) cout\
    \ << j << \"\\n\";\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n\n#include \"../../data-structure/kd_tree.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    KDTree<int> kd_tree;\n    for\
    \ (int i = 0; i < n; i++) {\n        int x, y;\n        cin >> x >> y;\n     \
    \   kd_tree.add_point(i, x, y);\n    }\n    kd_tree.build();\n    int q;\n   \
    \ cin >> q;\n    for (int i = 0; i < q; i++) {\n        int sx, tx, sy, ty;\n\
    \        cin >> sx >> tx >> sy >> ty;\n        auto res = kd_tree.search(sx, tx,\
    \ sy, ty);\n        sort(res.begin(), res.end());\n        for (int j : res) cout\
    \ << j << \"\\n\";\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/kd_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_C.test.cpp
  requiredBy: []
  timestamp: '2020-09-13 11:39:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_C.test.cpp
- /verify/test/aoj/DSL_2_C.test.cpp.html
title: test/aoj/DSL_2_C.test.cpp
---
