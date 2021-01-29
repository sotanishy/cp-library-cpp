---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1157.test.cpp
    title: test/aoj/1157.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/geometry.md
    document_title: Geometry
    links: []
  bundledCode: "#line 2 \"math/geometry.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <iostream>\n#include <optional>\n#include <vector>\n\
    \n/*\n * @brief Geometry\n * @docs docs/math/geometry.md\n */\n\nconstexpr double\
    \ eps = 1e-12;\n\ninline bool eq(double a, double b) { return std::abs(a - b)\
    \ < eps; }\ninline bool lt(double a, double b) { return a < b - eps; }\ninline\
    \ bool leq(double a, double b) { return a < b + eps; }\n\nstruct Vec {\n    double\
    \ x, y;\n\n    Vec() = default;\n    Vec(double x, double y) : x(x), y(y) {}\n\
    \n    Vec operator+(const Vec& other) const { return Vec(x + other.x, y + other.y);\
    \ }\n    Vec operator-(const Vec& other) const { return Vec(x - other.x, y - other.y);\
    \ }\n    Vec operator*(double k) const { return Vec(x * k, y * k); }\n    Vec\
    \ operator/(double k) const { return Vec(x / k, y / k); }\n\n    double abs()\
    \ const { return sqrt(x * x + y * y); }\n    double dot(const Vec& other) const\
    \ { return x * other.x + y * other.y; }\n    double cross(const Vec& other) const\
    \ { return x * other.y - y * other.x; }\n\n    Vec rot(double ang) const {\n \
    \       double c = cos(ang), s = sin(ang);\n        return Vec(c * x - s * y,\
    \ s * x + c * y);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Vec& v) {\n        return os << \"(\" << v.x << \", \" << v.y << \"\
    )\";\n    }\n};\n\n// checks if the three points are on the same line\nbool are_colinear(const\
    \ Vec& p1, const Vec& p2, const Vec& p3) {\n    return eq((p2 - p1).cross(p3 -\
    \ p1), 0);\n}\n\n// checks if a -> b -> c is counter clockwise\nbool ccw(const\
    \ Vec& a, const Vec& b, const Vec& c) {\n    return lt((b.y - a.y) * (c.x - a.x),\
    \ (c.y - a.y) * (b.x - a.x));\n}\n\n// checks if the segment ab intersects with\
    \ the segment cd\nbool intersect(const Vec& a, const Vec& b, const Vec& c, const\
    \ Vec& d) {\n    return ccw(a, c, d) != ccw(b, c, d) && ccw(a, b, c) != ccw(a,\
    \ b, d);\n}\n\n// checks if q is on the segment p1-p2\nbool on_segment(const Vec&\
    \ p1, const Vec& p2, const Vec& q) {\n    Vec v1 = p1 - q, v2 = p2 - q;\n    return\
    \ eq(v1.cross(v2), 0) && eq(v1.dot(v2), 0);\n}\n\n// returns the intersection\
    \ of the lines p1-p2 and q1-q2\n// if the lines are parallel, returns nullopt\n\
    std::optional<Vec> intersection(const Vec& p1, const Vec& p2, const Vec& q1, const\
    \ Vec& q2) {\n    Vec p = p2 - p1;\n    Vec q = q2 - q1;\n    Vec r = q1 - p1;\n\
    \    // if parallel\n    if (eq(q.cross(p), 0)) return std::nullopt;\n    return\
    \ p1 + p * (q.cross(r) / q.cross(p));\n}\n\n// returns a list of the intersections\
    \ of two circles\nstd::vector<Vec> intersection_circles(const Vec& c1, double\
    \ r1, const Vec& c2, double r2) {\n    double d = (c1 - c2).abs();\n    // if\
    \ the circles are outside of each other\n    if (lt(r1 + r2, d)) return {};\n\
    \    // if one contains the other entirely\n    if (lt(d, std::abs(r2 - r1)))\
    \ return {};\n    double x = (r1*r1 - r2*r2 + d*d) / (2*d);\n    double y = sqrt(r1*r1\
    \ - x*x);\n    Vec e1 = (c2 - c1) / (c2 - c1).abs();\n    Vec e2 = Vec(-e1.y,\
    \ e1.x);\n    Vec p1 = c1 + e1 * x + e2 * y;\n    Vec p2 = c1 + e1 * x - e2 *\
    \ y;\n    return {p1, p2};\n}\n\n// returns the distance between the point q and\
    \ the line p1-p2\ndouble point_line_dist(const Vec& p1, const Vec& p2, const Vec&\
    \ q) {\n    Vec p = p2 - p1;\n    return std::abs(q.cross(p) + p2.cross(p1)) /\
    \ p.abs();\n}\n\ndouble area(const Vec& A, const Vec& B, const Vec& C) {\n   \
    \ return std::abs((B - A).cross(C - A)) / 2;\n}\n\nVec centroid(const Vec& A,\
    \ const Vec& B, const Vec& C) {\n    assert(!are_colinear(A, B, C));\n    return\
    \ (A + B + C) / 3;\n}\n\nVec circumcenter(const Vec& A, const Vec& B, const Vec&\
    \ C) {\n    assert(!are_colinear(A, B, C));\n    double a = (B - C).abs();\n \
    \   double b = (C - A).abs();\n    double c = (A - B).abs();\n    double cosA\
    \ = (b*b + c*c - a*a) / (2*b*c);\n    double cosB = (c*c + a*a - b*b) / (2*c*a);\n\
    \    double cosC = (a*a + b*b - c*c) / (2*a*b);\n    return (A*(a*cosA) + B*(b*cosB)\
    \ + C*(c*cosC)) / (a*cosA + b*cosB + c*cosC);\n}\n\nVec incenter(const Vec& A,\
    \ const Vec& B, const Vec& C) {\n    assert(!are_colinear(A, B, C));\n    double\
    \ a = (B - C).abs();\n    double b = (C - A).abs();\n    double c = (A - B).abs();\n\
    \    return (A*a + B*b + C*c) / (a + b + c);\n}\n\nstd::vector<Vec> convex_hull(std::vector<Vec>&\
    \ points) {\n    int n = points.size();\n    std::sort(points.begin(), points.end(),\
    \ [](const Vec& v1, const Vec& v2) {\n        return std::make_pair(v1.x, v1.y)\
    \ < std::make_pair(v2.x, v2.y);\n    });\n    int k = 0; // the number of vertices\
    \ in the convex hull\n    std::vector<Vec> ch(2 * n);\n    // bottom\n    for\
    \ (int i = 0; i < n; ++i) {\n        while (k > 1 && leq((ch[k-1] - ch[k-2]).cross(points[i]\
    \ - ch[k-1]), 0)) --k;\n        ch[k] = points[i];\n        ++k;\n    }\n    int\
    \ t = k;\n    // top\n    for (int i = n - 1; i >= 0; --i) {\n        while (k\
    \ > t && leq((ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]), 0)) --k;\n      \
    \  ch[k] = points[i];\n        ++k;\n    }\n    return std::vector<Vec>(ch.begin(),\
    \ ch.begin() + (k - 1));\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <iostream>\n#include <optional>\n#include <vector>\n\n/*\n * @brief Geometry\n\
    \ * @docs docs/math/geometry.md\n */\n\nconstexpr double eps = 1e-12;\n\ninline\
    \ bool eq(double a, double b) { return std::abs(a - b) < eps; }\ninline bool lt(double\
    \ a, double b) { return a < b - eps; }\ninline bool leq(double a, double b) {\
    \ return a < b + eps; }\n\nstruct Vec {\n    double x, y;\n\n    Vec() = default;\n\
    \    Vec(double x, double y) : x(x), y(y) {}\n\n    Vec operator+(const Vec& other)\
    \ const { return Vec(x + other.x, y + other.y); }\n    Vec operator-(const Vec&\
    \ other) const { return Vec(x - other.x, y - other.y); }\n    Vec operator*(double\
    \ k) const { return Vec(x * k, y * k); }\n    Vec operator/(double k) const {\
    \ return Vec(x / k, y / k); }\n\n    double abs() const { return sqrt(x * x +\
    \ y * y); }\n    double dot(const Vec& other) const { return x * other.x + y *\
    \ other.y; }\n    double cross(const Vec& other) const { return x * other.y -\
    \ y * other.x; }\n\n    Vec rot(double ang) const {\n        double c = cos(ang),\
    \ s = sin(ang);\n        return Vec(c * x - s * y, s * x + c * y);\n    }\n\n\
    \    friend std::ostream& operator<<(std::ostream& os, const Vec& v) {\n     \
    \   return os << \"(\" << v.x << \", \" << v.y << \")\";\n    }\n};\n\n// checks\
    \ if the three points are on the same line\nbool are_colinear(const Vec& p1, const\
    \ Vec& p2, const Vec& p3) {\n    return eq((p2 - p1).cross(p3 - p1), 0);\n}\n\n\
    // checks if a -> b -> c is counter clockwise\nbool ccw(const Vec& a, const Vec&\
    \ b, const Vec& c) {\n    return lt((b.y - a.y) * (c.x - a.x), (c.y - a.y) * (b.x\
    \ - a.x));\n}\n\n// checks if the segment ab intersects with the segment cd\n\
    bool intersect(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n   \
    \ return ccw(a, c, d) != ccw(b, c, d) && ccw(a, b, c) != ccw(a, b, d);\n}\n\n\
    // checks if q is on the segment p1-p2\nbool on_segment(const Vec& p1, const Vec&\
    \ p2, const Vec& q) {\n    Vec v1 = p1 - q, v2 = p2 - q;\n    return eq(v1.cross(v2),\
    \ 0) && eq(v1.dot(v2), 0);\n}\n\n// returns the intersection of the lines p1-p2\
    \ and q1-q2\n// if the lines are parallel, returns nullopt\nstd::optional<Vec>\
    \ intersection(const Vec& p1, const Vec& p2, const Vec& q1, const Vec& q2) {\n\
    \    Vec p = p2 - p1;\n    Vec q = q2 - q1;\n    Vec r = q1 - p1;\n    // if parallel\n\
    \    if (eq(q.cross(p), 0)) return std::nullopt;\n    return p1 + p * (q.cross(r)\
    \ / q.cross(p));\n}\n\n// returns a list of the intersections of two circles\n\
    std::vector<Vec> intersection_circles(const Vec& c1, double r1, const Vec& c2,\
    \ double r2) {\n    double d = (c1 - c2).abs();\n    // if the circles are outside\
    \ of each other\n    if (lt(r1 + r2, d)) return {};\n    // if one contains the\
    \ other entirely\n    if (lt(d, std::abs(r2 - r1))) return {};\n    double x =\
    \ (r1*r1 - r2*r2 + d*d) / (2*d);\n    double y = sqrt(r1*r1 - x*x);\n    Vec e1\
    \ = (c2 - c1) / (c2 - c1).abs();\n    Vec e2 = Vec(-e1.y, e1.x);\n    Vec p1 =\
    \ c1 + e1 * x + e2 * y;\n    Vec p2 = c1 + e1 * x - e2 * y;\n    return {p1, p2};\n\
    }\n\n// returns the distance between the point q and the line p1-p2\ndouble point_line_dist(const\
    \ Vec& p1, const Vec& p2, const Vec& q) {\n    Vec p = p2 - p1;\n    return std::abs(q.cross(p)\
    \ + p2.cross(p1)) / p.abs();\n}\n\ndouble area(const Vec& A, const Vec& B, const\
    \ Vec& C) {\n    return std::abs((B - A).cross(C - A)) / 2;\n}\n\nVec centroid(const\
    \ Vec& A, const Vec& B, const Vec& C) {\n    assert(!are_colinear(A, B, C));\n\
    \    return (A + B + C) / 3;\n}\n\nVec circumcenter(const Vec& A, const Vec& B,\
    \ const Vec& C) {\n    assert(!are_colinear(A, B, C));\n    double a = (B - C).abs();\n\
    \    double b = (C - A).abs();\n    double c = (A - B).abs();\n    double cosA\
    \ = (b*b + c*c - a*a) / (2*b*c);\n    double cosB = (c*c + a*a - b*b) / (2*c*a);\n\
    \    double cosC = (a*a + b*b - c*c) / (2*a*b);\n    return (A*(a*cosA) + B*(b*cosB)\
    \ + C*(c*cosC)) / (a*cosA + b*cosB + c*cosC);\n}\n\nVec incenter(const Vec& A,\
    \ const Vec& B, const Vec& C) {\n    assert(!are_colinear(A, B, C));\n    double\
    \ a = (B - C).abs();\n    double b = (C - A).abs();\n    double c = (A - B).abs();\n\
    \    return (A*a + B*b + C*c) / (a + b + c);\n}\n\nstd::vector<Vec> convex_hull(std::vector<Vec>&\
    \ points) {\n    int n = points.size();\n    std::sort(points.begin(), points.end(),\
    \ [](const Vec& v1, const Vec& v2) {\n        return std::make_pair(v1.x, v1.y)\
    \ < std::make_pair(v2.x, v2.y);\n    });\n    int k = 0; // the number of vertices\
    \ in the convex hull\n    std::vector<Vec> ch(2 * n);\n    // bottom\n    for\
    \ (int i = 0; i < n; ++i) {\n        while (k > 1 && leq((ch[k-1] - ch[k-2]).cross(points[i]\
    \ - ch[k-1]), 0)) --k;\n        ch[k] = points[i];\n        ++k;\n    }\n    int\
    \ t = k;\n    // top\n    for (int i = n - 1; i >= 0; --i) {\n        while (k\
    \ > t && leq((ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]), 0)) --k;\n      \
    \  ch[k] = points[i];\n        ++k;\n    }\n    return std::vector<Vec>(ch.begin(),\
    \ ch.begin() + (k - 1));\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/geometry.cpp
  requiredBy: []
  timestamp: '2020-12-15 21:43:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1157.test.cpp
documentation_of: math/geometry.cpp
layout: document
redirect_from:
- /library/math/geometry.cpp
- /library/math/geometry.cpp.html
title: Geometry
---
## Description

幾何アルゴリズム詰め合わせ

大半は未 verify．

## Vector

- `struct Vector`
    - 2次元ベクトルを表す
    - メンバー変数: `x`, `y`
    - 演算子: ベクトル加減算，スカラー乗除算，標準出力
    - メンバー関数: 絶対値 `abs`，内積 `dot`，外積の $z$ 成分 `cross`，回転 `rot`

## Functions

時間計算量は明示しない限り $O(1)$．

- `bool are_colinear(Vec p1, Vec p2, Vec p3)`
    - 3点が共線か判定する
    - ***NOT VERIFIED***

- `bool ccw(Vec a, Vec b, Vec c)`
    - $a \rightarrow b \rightarrow c$ が反時計回りか判定する

- `bool intersect(Vec a, Vec b, Vec c, Vec d)`
    - 線分 $ab$ と線分 $cd$ が交差するか判定する

- `bool on_segment(Vec p1, Vec p2, Vec q)`
    - 点 $q$ が線分 $p_1 p_2$ 上にあるか判定する
    - ***NOT VERIFIED***

- `optional<Vec> intersection(Vec p1, Vec p2, Vec q1, Vec q2)`
    - 直線 $p_1 p_2$ と直線 $q_1 q_2$ の交点を返す．平行なら `nullopt` を返す
    - ***NOT VERIFIED***

- `vector<Vec> intersection_circles(Vec c1, double r1, Vec c2, double r2)`
    - 中心 $c_1$，半径 $r_1$ の円と中心 $c_2$，半径 $r_2$ の円の交点を返す
    - ***NOT VERIFIED***

 - `double point_line_dist(Vec p1, Vec p2, Vec q)`
    - 点 $q$ と直線 $p_1 p_2$ の距離を返す

- `double area(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の面積を返す
    - ***NOT VERIFIED***

- `Vec centroid(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の重心を返す
    - ***NOT VERIFIED***

- `Vec circumcenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の外心を返す
    - ***NOT VERIFIED***

- `Vec incenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の内心を返す
    - ***NOT VERIFIED***

- `vector<Vec> convex_hull(vector<Vec> points)`
    - 与えられた点の凸包を返す
    - 時間計算量: $O(n)$
    - ***NOT VERIFIED***