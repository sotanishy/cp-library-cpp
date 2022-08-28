---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/bisector.hpp
    title: geometry/bisector.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/closest_pair.hpp
    title: Closest Pair
  - icon: ':heavy_check_mark:'
    path: geometry/convex_hull.hpp
    title: Convex Hull
  - icon: ':warning:'
    path: geometry/delaunay_diagram.hpp
    title: Delaunay Diagram
  - icon: ':heavy_check_mark:'
    path: geometry/dist.hpp
    title: geometry/dist.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/intersect.hpp
    title: geometry/intersect.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/intersection.hpp
    title: geometry/intersection.hpp
  - icon: ':warning:'
    path: geometry/minimum_bounding_circle.hpp
    title: Minimum Bounding Circle
  - icon: ':heavy_check_mark:'
    path: geometry/polygon.hpp
    title: geometry/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/tangent.hpp
    title: geometry/tangent.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/triangle.hpp
    title: geometry/triangle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1298.test.cpp
    title: test/aoj/1298.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_C.test.cpp
    title: test/aoj/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_A.test.cpp
    title: test/aoj/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_B.test.cpp
    title: test/aoj/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C.test.cpp
    title: test/aoj/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D.test.cpp
    title: test/aoj/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A.test.cpp
    title: test/aoj/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_C.test.cpp
    title: test/aoj/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A.test.cpp
    title: test/aoj/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: test/aoj/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A.test.cpp
    title: test/aoj/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D.test.cpp
    title: test/aoj/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_E.test.cpp
    title: test/aoj/CGL_7_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_F.test.cpp
    title: test/aoj/CGL_7_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_G.test.cpp
    title: test/aoj/CGL_7_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_I.test.cpp
    title: test/aoj/CGL_7_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/geometry.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n#include\
    \ <vector>\n\n// note that if T is of an integer type, std::abs does not work\n\
    using T = double;\nusing Vec = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\
    \nconstexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return std::abs(a - b)\
    \ <= eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }\n\
    inline bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) {\
    \ return a <= b + eps; }\n\nstd::istream& operator>>(std::istream& is, Vec& p)\
    \ {\n    T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n}\n\nstruct\
    \ Line {\n    Vec p1, p2;\n    Line() = default;\n    Line(const Vec& p1, const\
    \ Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2 - p1; }\n};\n\n\
    struct Segment {\n    Vec p1, p2;\n    Segment() = default;\n    Segment(const\
    \ Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2\
    \ - p1; }\n};\n\nstruct Circle {\n    Vec c;\n    T r;\n    Circle() = default;\n\
    \    Circle(const Vec& c, T r) : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\
    \nT dot(const Vec& a, const Vec& b) {\n    return (std::conj(a) * b).real();\n\
    }\n\nT cross(const Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n\
    }\n\nVec rot(const Vec& a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n\
    }\n\nVec perp(const Vec& a) {\n    return Vec(-a.imag(), a.real());\n}\n\nVec\
    \ projection(const Line& l, const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir())\
    \ * l.dir() / std::norm(l.dir());\n}\n\nVec reflection(const Line& l, const Vec&\
    \ p) {\n    return T(2) * projection(l, p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n\
    // -1: clockwise\nint ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if\
    \ (eq(cross(b - a, c - a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0))\
    \ return -1;\n    return 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n\
    \    std::sort(pts.begin(), pts.end(), [&](auto& p, auto& q) {\n        if ((p.imag()\
    \ < 0) != (q.imag() < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0)\
    \ {\n            if (p == Vec(0, 0)) return !(q.imag() < 0 || (q.imag() == 0 &&\
    \ q.real() > 0));\n            if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag()\
    \ == 0 && p.real() > 0));\n            return (p.real() > q.real());\n       \
    \ }\n        return (cross(p, q) > 0);\n    });\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <iostream>\n#include <vector>\n\n// note that if\
    \ T is of an integer type, std::abs does not work\nusing T = double;\nusing Vec\
    \ = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\nconstexpr T eps = 1e-10;\n\
    inline bool eq(T a, T b) { return std::abs(a - b) <= eps; }\ninline bool eq(Vec\
    \ a, Vec b) { return std::abs(a - b) <= eps; }\ninline bool lt(T a, T b) { return\
    \ a < b - eps; }\ninline bool leq(T a, T b) { return a <= b + eps; }\n\nstd::istream&\
    \ operator>>(std::istream& is, Vec& p) {\n    T x, y;\n    is >> x >> y;\n   \
    \ p = {x, y};\n    return is;\n}\n\nstruct Line {\n    Vec p1, p2;\n    Line()\
    \ = default;\n    Line(const Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}\n   \
    \ Vec dir() const { return p2 - p1; }\n};\n\nstruct Segment {\n    Vec p1, p2;\n\
    \    Segment() = default;\n    Segment(const Vec& p1, const Vec& p2) : p1(p1),\
    \ p2(p2) {}\n    Vec dir() const { return p2 - p1; }\n};\n\nstruct Circle {\n\
    \    Vec c;\n    T r;\n    Circle() = default;\n    Circle(const Vec& c, T r)\
    \ : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\nT dot(const Vec&\
    \ a, const Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\nT cross(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nVec rot(const\
    \ Vec& a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n}\n\nVec\
    \ perp(const Vec& a) {\n    return Vec(-a.imag(), a.real());\n}\n\nVec projection(const\
    \ Line& l, const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir()) * l.dir()\
    \ / std::norm(l.dir());\n}\n\nVec reflection(const Line& l, const Vec& p) {\n\
    \    return T(2) * projection(l, p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n\
    // -1: clockwise\nint ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if\
    \ (eq(cross(b - a, c - a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0))\
    \ return -1;\n    return 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n\
    \    std::sort(pts.begin(), pts.end(), [&](auto& p, auto& q) {\n        if ((p.imag()\
    \ < 0) != (q.imag() < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0)\
    \ {\n            if (p == Vec(0, 0)) return !(q.imag() < 0 || (q.imag() == 0 &&\
    \ q.real() > 0));\n            if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag()\
    \ == 0 && p.real() > 0));\n            return (p.real() > q.real());\n       \
    \ }\n        return (cross(p, q) > 0);\n    });\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy:
  - geometry/minimum_bounding_circle.hpp
  - geometry/dist.hpp
  - geometry/intersection.hpp
  - geometry/polygon.hpp
  - geometry/tangent.hpp
  - geometry/delaunay_diagram.hpp
  - geometry/triangle.hpp
  - geometry/closest_pair.hpp
  - geometry/intersect.hpp
  - geometry/convex_hull.hpp
  - geometry/bisector.hpp
  timestamp: '2022-06-27 13:45:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/1298.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_1_C.test.cpp
documentation_of: geometry/geometry.hpp
layout: document
title: Geometry
---

## Description

幾何アルゴリズム詰め合わせ

`Vec` は `std::complex<T>` のエイリアスである．

できるだけ整数だけの計算も扱えるようにした

## Operations

時間計算量は明示しない限り $O(1)$．

### `geometry.hpp`

- `T dot(Vec a, Vec b)`
    - 内積を計算する

- `T cross(Vec a, Vec b)`
    - 外積の $z$ 座標を計算する

- `Vec rot(Vec a, T ang)`
    - $a$ を角 $ang$ だけ回転させる

- `Vec perp(Vec a)`
    - $a$ を角 $\pi/2$ だけ回転させる

- `Vec projection(Line l, Vec p)`
    - 点 $p$ の直線 $l$ 上の射影を求める

- `Vec reflection(Line l, Vec p)`
    - 点 $p$ の直線 $l$ に関して対称な点を求める

- `int ccw(Vec a, Vec b, Vec c)`
    - $a,b,c$ が同一直線上にあるなら0, $a \rightarrow b \rightarrow c$ が反時計回りなら1，そうでなければ-1を返す

- `void sort_by_arg(vector<Vec> pts)`
  - 与えられた点を偏角ソートする (ソート順は[この問題](https://judge.yosupo.jp/problem/sort_points_by_argument)に準拠)
  - 時間計算量: $O(n\log n)$

### `intersect.hpp`

- `bool intersect(Segment s, Vec p)`

  `int intersect(Polygon poly, Vec p)`

  `bool intersect(Segment s, Segment t)`

  `bool intersect(Polygon poly1, Polygon poly2)`

  `int intersect(Circle c1, Circle c2)`
    - 引数で与えられた2つの対象が交差するか判定する．詳細な仕様はコードのコメントを参照

### `dist.hpp`

 - `T dist(Line l, Vec p)`

   `T dist(Segment s, Vec p)`

   `T dist(Segment s, Segment t)`
    - 引数で与えられた2つの対象の距離を計算する

### `intersection.hpp`

- `Vec intersection(Line l, Line m)`

- `vector<Vec> intersection(Circle c, Line l)`

  `vector<Vec> intersection(Circle c1, Circle c2)`
    - 引数で与えられた2つの対象の交点を返す

- `T area_intersection(Circle c1, Circle c2)`
    - 円 $c_1,c_2$ の共通部分の面積を求める

### `bisector.hpp`

- `Line bisector(Segment s)`
    - 線分 $s$ の垂直二等分線を返す

- `pair<Line, Line> bisector(Line l, Line m)`
    - 直線 $l,m$ の角二等分線を返す．$l,m$ が平行なら，両者の中間の線を返す (つまり，$l,m$ から等距離にある点の集合を返す)

### `triangle.hpp`

- `Vec centroid(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の重心を返す
    - ***NOT VERIFIED***

- `Vec incenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の内心を返す

- `Vec circumcenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の外心を返す

### `tangent.hpp`

- `pair<Vec, Vec> tangent_ponints(Circle c, Vec p)`
    - 点 $p$ を通り円 $c$ に接する接線と $c$ の接点を返す

- `vector<Line> common_tangents(Circle c1, Circle c2)`
    - 円 $c_1,c_2$ の共通接線を返す

### `polygon.hpp`

- `T area(Polygon poly)`
    - 多角形 $poly$ の面積を求める
    - 時間計算量: $O(n)$

- `T is_convex(Polygon poly)`
    - 多角形 $poly$ が凸か判定する．`poly` は反時計回りに与えられる必要がある
    - 時間計算量: $O(n)$

- `vector<Vec> convex_cut(Polygon poly, Line l)`
    - 多角形 $poly$ を直線 $l$ で切断する．詳細な仕様は [凸多角形の切断](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C) を参照．
    - 時間計算量: $O(n)$

### `closest_pair.hpp`

- `T closest_pair(vector<Vec> pts)`
    - 与えられた点のうち最も近い2点の距離を分割統治法で求める
    - 時間計算量: $O(n\log n)$
