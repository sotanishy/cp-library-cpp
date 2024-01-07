---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/kd_tree.hpp
    title: k-d Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
  bundledCode: "#line 1 \"test/aoj/DSL_2_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n\n#line 2 \"data-structure/kd_tree.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename T>\nclass KDTree {\n   public:\n    void add_point(int id,\
    \ T x, T y) { points.emplace_back(id, x, y); }\n\n    void build() { build(0,\
    \ points.size() - 1, 0); }\n\n    std::vector<int> search(T sx, T tx, T sy, T\
    \ ty) const {\n        Point s(std::min(sx, tx), std::min(sy, ty));\n        Point\
    \ t(std::max(sx, tx), std::max(sy, ty));\n        std::vector<int> res;\n    \
    \    search(s, t, res, 0, points.size() - 1, 0);\n        return res;\n    }\n\
    \n   private:\n    struct Point {\n        int id;\n        T x, y;\n        Point(T\
    \ x, T y) : x(x), y(y) {}\n        Point(int id, T x, T y) : id(id), x(x), y(y)\
    \ {}\n    };\n\n    std::vector<Point> points;\n\n    int check_position(const\
    \ Point& p, const Point& s, const Point& t,\n                       int axis)\
    \ const {\n        if (axis == 0) {\n            if (p.x < s.x) return -1;\n \
    \           if (t.x < p.x) return 1;\n            return 0;\n        } else {\n\
    \            if (p.y < s.y) return -1;\n            if (t.y < p.y) return 1;\n\
    \            return 0;\n        }\n    }\n\n    void build(int l, int r, int axis)\
    \ {\n        if (l > r) return;\n        std::ranges::sort(points.begin() + l,\
    \ points.begin() + r + 1, {},\n                          [&](auto& p) { return\
    \ axis == 0 ? p.x : p.y; });\n        int m = std::midpoint(l, r);\n        build(l,\
    \ m - 1, 1 - axis);\n        build(m + 1, r, 1 - axis);\n    }\n\n    void search(const\
    \ Point& s, const Point& t, std::vector<int>& res, int l,\n                int\
    \ r, int axis) const {\n        if (l > r) return;\n        int m = (l + r) /\
    \ 2;\n        bool contained = true;\n        for (int i = 0; i < 2; i++)\n  \
    \          contained &= check_position(points[m], s, t, i) == 0;\n        if (contained)\
    \ res.push_back(points[m].id);\n        if (l == r) return;\n        int pos =\
    \ check_position(points[m], s, t, axis);\n        if (pos != -1) search(s, t,\
    \ res, l, m - 1, 1 - axis);\n        if (pos != 1) search(s, t, res, m + 1, r,\
    \ 1 - axis);\n    }\n};\n#line 4 \"test/aoj/DSL_2_C.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    KDTree<int> kd_tree;\n    for\
    \ (int i = 0; i < n; i++) {\n        int x, y;\n        cin >> x >> y;\n     \
    \   kd_tree.add_point(i, x, y);\n    }\n    kd_tree.build();\n    int q;\n   \
    \ cin >> q;\n    for (int i = 0; i < q; i++) {\n        int sx, tx, sy, ty;\n\
    \        cin >> sx >> tx >> sy >> ty;\n        auto res = kd_tree.search(sx, tx,\
    \ sy, ty);\n        sort(res.begin(), res.end());\n        for (int j : res) cout\
    \ << j << \"\\n\";\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n\n#include \"../../data-structure/kd_tree.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    KDTree<int> kd_tree;\n    for\
    \ (int i = 0; i < n; i++) {\n        int x, y;\n        cin >> x >> y;\n     \
    \   kd_tree.add_point(i, x, y);\n    }\n    kd_tree.build();\n    int q;\n   \
    \ cin >> q;\n    for (int i = 0; i < q; i++) {\n        int sx, tx, sy, ty;\n\
    \        cin >> sx >> tx >> sy >> ty;\n        auto res = kd_tree.search(sx, tx,\
    \ sy, ty);\n        sort(res.begin(), res.end());\n        for (int j : res) cout\
    \ << j << \"\\n\";\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/kd_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_C.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_C.test.cpp
- /verify/test/aoj/DSL_2_C.test.cpp.html
title: test/aoj/DSL_2_C.test.cpp
---
