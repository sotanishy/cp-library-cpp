---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/dist.hpp
    title: geometry/dist.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: Geometry
  - icon: ':heavy_check_mark:'
    path: geometry/intersect.hpp
    title: geometry/intersect.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/bisector.hpp
    title: geometry/bisector.hpp
  - icon: ':warning:'
    path: geometry/delaunay_diagram.hpp
    title: Delaunay Diagram
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
    path: test/aoj/1283.test.cpp
    title: test/aoj/1283.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C.test.cpp
    title: test/aoj/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A.test.cpp
    title: test/aoj/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
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
    \ <numbers>\n#include <numeric>\n#include <vector>\n\n// note that if T is of\
    \ an integer type, std::abs does not work\nusing T = double;\nusing Vec = std::complex<T>;\n\
    \nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y;\n    is >>\
    \ x >> y;\n    p = {x, y};\n    return is;\n}\n\nT dot(const Vec& a, const Vec&\
    \ b) { return (std::conj(a) * b).real(); }\n\nT cross(const Vec& a, const Vec&\
    \ b) { return (std::conj(a) * b).imag(); }\n\nconstexpr T PI = std::numbers::pi_v<T>;\n\
    constexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return std::abs(a - b) <=\
    \ eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }\ninline\
    \ bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) { return\
    \ a <= b + eps; }\n\nstruct Line {\n    Vec p1, p2;\n    Line() = default;\n \
    \   Line(const Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const\
    \ { return p2 - p1; }\n};\n\nstruct Segment : Line {\n    using Line::Line;\n\
    };\n\nstruct Circle {\n    Vec c;\n    T r;\n    Circle() = default;\n    Circle(const\
    \ Vec& c, T r) : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\nVec\
    \ rot(const Vec& a, T ang) { return a * Vec(std::cos(ang), std::sin(ang)); }\n\
    \nVec perp(const Vec& a) { return Vec(-a.imag(), a.real()); }\n\nVec projection(const\
    \ Line& l, const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir()) * l.dir()\
    \ / std::norm(l.dir());\n}\n\nVec reflection(const Line& l, const Vec& p) {\n\
    \    return T(2) * projection(l, p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n\
    // -1: clockwise\nint ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if\
    \ (eq(cross(b - a, c - a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0))\
    \ return -1;\n    return 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n\
    \    std::ranges::sort(pts, [&](auto& p, auto& q) {\n        if ((p.imag() < 0)\
    \ != (q.imag() < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0) {\n\
    \            if (p == Vec(0, 0))\n                return !(q.imag() < 0 || (q.imag()\
    \ == 0 && q.real() > 0));\n            if (q == Vec(0, 0))\n                return\
    \ (p.imag() < 0 || (p.imag() == 0 && p.real() > 0));\n            return (p.real()\
    \ > q.real());\n        }\n        return (cross(p, q) > 0);\n    });\n}\n#line\
    \ 3 \"geometry/intersect.hpp\"\n\nbool intersect(const Segment& s, const Vec&\
    \ p) {\n    Vec u = s.p1 - p, v = s.p2 - p;\n    return eq(cross(u, v), 0) &&\
    \ leq(dot(u, v), 0);\n}\n\n// 0: outside\n// 1: on the border\n// 2: inside\n\
    int intersect(const Polygon& poly, const Vec& p) {\n    const int n = poly.size();\n\
    \    bool in = 0;\n    for (int i = 0; i < n; ++i) {\n        auto a = poly[i]\
    \ - p, b = poly[(i + 1) % n] - p;\n        if (eq(cross(a, b), 0) && (lt(dot(a,\
    \ b), 0) || eq(dot(a, b), 0)))\n            return 1;\n        if (a.imag() >\
    \ b.imag()) std::swap(a, b);\n        if (leq(a.imag(), 0) && lt(0, b.imag())\
    \ && lt(cross(a, b), 0)) in ^= 1;\n    }\n    return in ? 2 : 0;\n}\n\nint intersect(const\
    \ Segment& s, const Segment& t) {\n    auto a = s.p1, b = s.p2;\n    auto c =\
    \ t.p1, d = t.p2;\n    if (ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c,\
    \ d, b)) return 2;\n    if (intersect(s, c) || intersect(s, d) || intersect(t,\
    \ a) ||\n        intersect(t, b))\n        return 1;\n    return 0;\n}\n\n// true\
    \ if they have positive area in common or touch on the border\nbool intersect(const\
    \ Polygon& poly1, const Polygon& poly2) {\n    const int n = poly1.size();\n \
    \   const int m = poly2.size();\n    for (int i = 0; i < n; ++i) {\n        for\
    \ (int j = 0; j < m; ++j) {\n            if (intersect(Segment(poly1[i], poly1[(i\
    \ + 1) % n]),\n                          Segment(poly2[j], poly2[(j + 1) % m])))\
    \ {\n                return true;\n            }\n        }\n    }\n    return\
    \ intersect(poly1, poly2[0]) || intersect(poly2, poly1[0]);\n}\n\n// 0: inside\n\
    // 1: inscribe\n// 2: intersect\n// 3: circumscribe\n// 4: outside\nint intersect(const\
    \ Circle& c1, const Circle& c2) {\n    T d = std::abs(c1.c - c2.c);\n    if (lt(d,\
    \ std::abs(c2.r - c1.r))) return 0;\n    if (eq(d, std::abs(c2.r - c1.r))) return\
    \ 1;\n    if (eq(c1.r + c2.r, d)) return 3;\n    if (lt(c1.r + c2.r, d)) return\
    \ 4;\n    return 2;\n}\n#line 4 \"geometry/dist.hpp\"\n\nT dist(const Line& l,\
    \ const Vec& p) {\n    return std::abs(cross(p - l.p1, l.dir())) / std::abs(l.dir());\n\
    }\n\nT dist(const Segment& s, const Vec& p) {\n    if (lt(dot(p - s.p1, s.dir()),\
    \ 0)) return std::abs(p - s.p1);\n    if (lt(dot(p - s.p2, -s.dir()), 0)) return\
    \ std::abs(p - s.p2);\n    return std::abs(cross(p - s.p1, s.dir())) / std::abs(s.dir());\n\
    }\n\nT dist(const Segment& s, const Segment& t) {\n    if (intersect(s, t)) return\
    \ T(0);\n    return std::min(\n        {dist(s, t.p1), dist(s, t.p2), dist(t,\
    \ s.p1), dist(t, s.p2)});\n}\n#line 4 \"geometry/intersection.hpp\"\n\nVec intersection(const\
    \ Line& l, const Line& m) {\n    assert(!eq(cross(l.dir(), m.dir()), 0));  //\
    \ not parallel\n    Vec r = m.p1 - l.p1;\n    return l.p1 + cross(m.dir(), r)\
    \ / cross(m.dir(), l.dir()) * l.dir();\n}\n\nstd::vector<Vec> intersection(const\
    \ Circle& c, const Line& l) {\n    T d = dist(l, c.c);\n    if (lt(c.r, d)) return\
    \ {};  // no intersection\n    Vec e1 = l.dir() / std::abs(l.dir());\n    Vec\
    \ e2 = perp(e1);\n    if (ccw(c.c, l.p1, l.p2) == 1) e2 *= -1;\n    if (eq(c.r,\
    \ d)) return {c.c + d * e2};  // tangent\n    T t = std::sqrt(c.r * c.r - d *\
    \ d);\n    return {c.c + d * e2 + t * e1, c.c + d * e2 - t * e1};\n}\n\nstd::vector<Vec>\
    \ intersection(const Circle& c1, const Circle& c2) {\n    T d = std::abs(c1.c\
    \ - c2.c);\n    if (lt(c1.r + c2.r, d)) return {};  // outside\n    Vec e1 = (c2.c\
    \ - c1.c) / std::abs(c2.c - c1.c);\n    Vec e2 = perp(e1);\n    if (lt(d, std::abs(c2.r\
    \ - c1.r))) return {};                  // contain\n    if (eq(d, std::abs(c2.r\
    \ - c1.r))) return {c1.c + c1.r * e1};  // tangent\n    T x = (c1.r * c1.r - c2.r\
    \ * c2.r + d * d) / (2 * d);\n    T y = std::sqrt(c1.r * c1.r - x * x);\n    return\
    \ {c1.c + x * e1 + y * e2, c1.c + x * e1 - y * e2};\n}\n\nT area_intersection(const\
    \ Circle& c1, const Circle& c2) {\n    T d = std::abs(c2.c - c1.c);\n    if (leq(c1.r\
    \ + c2.r, d)) return 0;    // outside\n    if (leq(d, std::abs(c2.r - c1.r)))\
    \ {  // inside\n        T r = std::min(c1.r, c2.r);\n        return PI * r * r;\n\
    \    }\n    T ans = 0;\n    T a;\n    a = std::acos((c1.r * c1.r + d * d - c2.r\
    \ * c2.r) / (2 * c1.r * d));\n    ans += c1.r * c1.r * (a - std::sin(a) * std::cos(a));\n\
    \    a = std::acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));\n  \
    \  ans += c2.r * c2.r * (a - std::sin(a) * std::cos(a));\n    return ans;\n}\n"
  code: "#pragma once\n#include \"dist.hpp\"\n#include \"geometry.hpp\"\n\nVec intersection(const\
    \ Line& l, const Line& m) {\n    assert(!eq(cross(l.dir(), m.dir()), 0));  //\
    \ not parallel\n    Vec r = m.p1 - l.p1;\n    return l.p1 + cross(m.dir(), r)\
    \ / cross(m.dir(), l.dir()) * l.dir();\n}\n\nstd::vector<Vec> intersection(const\
    \ Circle& c, const Line& l) {\n    T d = dist(l, c.c);\n    if (lt(c.r, d)) return\
    \ {};  // no intersection\n    Vec e1 = l.dir() / std::abs(l.dir());\n    Vec\
    \ e2 = perp(e1);\n    if (ccw(c.c, l.p1, l.p2) == 1) e2 *= -1;\n    if (eq(c.r,\
    \ d)) return {c.c + d * e2};  // tangent\n    T t = std::sqrt(c.r * c.r - d *\
    \ d);\n    return {c.c + d * e2 + t * e1, c.c + d * e2 - t * e1};\n}\n\nstd::vector<Vec>\
    \ intersection(const Circle& c1, const Circle& c2) {\n    T d = std::abs(c1.c\
    \ - c2.c);\n    if (lt(c1.r + c2.r, d)) return {};  // outside\n    Vec e1 = (c2.c\
    \ - c1.c) / std::abs(c2.c - c1.c);\n    Vec e2 = perp(e1);\n    if (lt(d, std::abs(c2.r\
    \ - c1.r))) return {};                  // contain\n    if (eq(d, std::abs(c2.r\
    \ - c1.r))) return {c1.c + c1.r * e1};  // tangent\n    T x = (c1.r * c1.r - c2.r\
    \ * c2.r + d * d) / (2 * d);\n    T y = std::sqrt(c1.r * c1.r - x * x);\n    return\
    \ {c1.c + x * e1 + y * e2, c1.c + x * e1 - y * e2};\n}\n\nT area_intersection(const\
    \ Circle& c1, const Circle& c2) {\n    T d = std::abs(c2.c - c1.c);\n    if (leq(c1.r\
    \ + c2.r, d)) return 0;    // outside\n    if (leq(d, std::abs(c2.r - c1.r)))\
    \ {  // inside\n        T r = std::min(c1.r, c2.r);\n        return PI * r * r;\n\
    \    }\n    T ans = 0;\n    T a;\n    a = std::acos((c1.r * c1.r + d * d - c2.r\
    \ * c2.r) / (2 * c1.r * d));\n    ans += c1.r * c1.r * (a - std::sin(a) * std::cos(a));\n\
    \    a = std::acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));\n  \
    \  ans += c2.r * c2.r * (a - std::sin(a) * std::cos(a));\n    return ans;\n}\n"
  dependsOn:
  - geometry/dist.hpp
  - geometry/geometry.hpp
  - geometry/intersect.hpp
  isVerificationFile: false
  path: geometry/intersection.hpp
  requiredBy:
  - geometry/minimum_bounding_circle.hpp
  - geometry/bisector.hpp
  - geometry/triangle.hpp
  - geometry/polygon.hpp
  - geometry/delaunay_diagram.hpp
  - geometry/tangent.hpp
  timestamp: '2024-01-08 01:08:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/1283.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_3_B.test.cpp
documentation_of: geometry/intersection.hpp
layout: document
redirect_from:
- /library/geometry/intersection.hpp
- /library/geometry/intersection.hpp.html
title: geometry/intersection.hpp
---
