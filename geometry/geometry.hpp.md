---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geometry/closest_pair.hpp
    title: Closest Pair
  - icon: ':question:'
    path: geometry/convex_hull.hpp
    title: Convex Hull
  - icon: ':warning:'
    path: geometry/delaunay_diagram.hpp
    title: Delaunay Diagram
  _extendedVerifiedWith:
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
  - icon: ':x:'
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
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/geometry.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n#include\
    \ <vector>\n\n// note that if T is of an integer type, std::abs does not work\n\
    using T = double;\nusing Vec = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\
    \nconstexpr T eps = 1e-12;\ninline bool eq(T a, T b) { return std::abs(a - b)\
    \ < eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a - b) < eps; }\ninline\
    \ bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) { return\
    \ a < b + eps; }\n\nstd::istream& operator>>(std::istream& is, Vec& p) {\n   \
    \ T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n}\n\nstruct Line\
    \ {\n    Vec p1, p2;\n    Line() = default;\n    Line(const Vec& p1, const Vec&\
    \ p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2 - p1; }\n};\n\nstruct\
    \ Segment {\n    Vec p1, p2;\n    Segment() = default;\n    Segment(const Vec&\
    \ p1, const Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2 - p1;\
    \ }\n};\n\nstruct Circle {\n    Vec c;\n    T r;\n    Circle() = default;\n  \
    \  Circle(const Vec& c, T r) : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\
    \nT dot(const Vec& a, const Vec& b) {\n    return (std::conj(a) * b).real();\n\
    }\n\nT cross(const Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n\
    }\n\nVec rot(const Vec& a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n\
    }\n\nVec projection(const Line& l, const Vec& p) {\n    return l.p1 + dot(p -\
    \ l.p1, l.dir()) * l.dir() / std::norm(l.dir());\n}\n\nVec reflection(const Line&\
    \ l, const Vec& p) {\n    return T(2) * projection(l, p) - p;\n}\n\n// 0: collinear\n\
    // 1: counter-clockwise\n// 2: clockwise\nint ccw(const Vec& a, const Vec& b,\
    \ const Vec& c) {\n    if (eq(cross(b - a, c - a), 0)) return 0;\n    if (lt(cross(b\
    \ - a, c - a), 0)) return -1;\n    return 1;\n}\n\nLine bisector(const Vec& p,\
    \ const Vec& q) {\n    auto m = (p + q) / T(2);\n    auto v = q - p;\n    return\
    \ Line(m, m + Vec(-v.imag(), v.real()));\n}\n\nbool intersect(const Segment& s,\
    \ const Vec& p) {\n    Vec u = s.p1 - p, v = s.p2 - p;\n    return eq(cross(u,\
    \ v), 0) && leq(dot(u, v), 0);\n}\n\n// 0: outside\n// 1: on the border\n// 2:\
    \ inside\nint intersect(const Polygon& poly, const Vec& p) {\n    const int n\
    \ = poly.size();\n    bool in = 0;\n    for (int i = 0; i < n; ++i) {\n      \
    \  auto a = poly[i] - p, b = poly[(i+1)%n] - p;\n        if (eq(cross(a, b), 0)\
    \ && (lt(dot(a, b), 0) || eq(dot(a, b), 0))) return 1;\n        if (a.imag() >\
    \ b.imag()) std::swap(a, b);\n        if (leq(a.imag(), 0) && lt(0, b.imag())\
    \ && lt(cross(a, b), 0)) in ^= 1;\n    }\n    return in ? 2 : 0;\n}\n\nbool intersect(const\
    \ Segment& s, const Segment& t) {\n    auto a = s.p1, b = s.p2;\n    auto c =\
    \ t.p1, d = t.p2;\n    if (ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c,\
    \ d, b)) return 2;\n    if (intersect(s, c) || intersect(s, d) || intersect(t,\
    \ a) || intersect(t, b)) return 1;\n    return 0;\n}\n\n// 0: inside\n// 1: inscribe\n\
    // 2: intersect\n// 3: circumscribe\n// 4: outside\nint intersect(const Circle&\
    \ c1, const Circle& c2) {\n    T d = std::abs(c1.c - c2.c);\n    if (lt(d, std::abs(c2.r\
    \ - c1.r))) return 0;\n    if (eq(d, std::abs(c2.r - c1.r))) return 1;\n    if\
    \ (eq(c1.r + c2.r, d)) return 3;\n    if (lt(c1.r + c2.r, d)) return 4;\n    return\
    \ 2;\n}\n\nT dist(const Line& l, const Vec& p) {\n    return std::abs(cross(p\
    \ - l.p1, l.dir())) / std::abs(l.dir());\n}\n\nT dist(const Segment& s, const\
    \ Vec& p) {\n    if (lt(dot(p - s.p1, s.dir()), 0)) return std::abs(p - s.p1);\n\
    \    if (lt(dot(p - s.p2, -s.dir()), 0)) return std::abs(p - s.p2);\n    return\
    \ std::abs(cross(p - s.p1, s.dir())) / std::abs(s.dir());\n}\n\nT dist(const Segment&\
    \ s, const Segment& t) {\n    if (intersect(s, t)) return T(0);\n    return std::min({dist(s,\
    \ t.p1), dist(s, t.p2), dist(t, s.p1), dist(t, s.p2)});\n}\n\nVec intersection(const\
    \ Line& l, const Line& m) {\n    Vec r = m.p1 - l.p1;\n    assert(!eq(cross(l.dir(),\
    \ m.dir()), 0)); // not parallel\n    return l.p1 + cross(m.dir(), r) / cross(m.dir(),\
    \ l.dir()) * l.dir();\n}\n\nstd::vector<Vec> intersection(const Circle& c, const\
    \ Line& l) {\n    T d = dist(l, c.c);\n    if (lt(c.r, d)) return {};  // no intersection\n\
    \    Vec e1 = l.dir() / std::abs(l.dir());\n    Vec e2 = Vec(-e1.imag(), e1.real());\n\
    \    if (ccw(c.c, l.p1, l.p2) == 1) e2 *= -1;\n    if (eq(c.r, d)) return {c.c\
    \ + d*e2};  // tangent\n    T t = std::sqrt(c.r*c.r - d*d);\n    return {c.c +\
    \ d*e2 + t*e1, c.c + d*e2 - t*e1};\n}\n\nstd::vector<Vec> intersection(const Circle&\
    \ c1, const Circle& c2) {\n    T d = std::abs(c1.c - c2.c);\n    if (lt(c1.r +\
    \ c2.r, d)) return {};  // outside\n    Vec e1 = (c2.c - c1.c) / std::abs(c2.c\
    \ - c1.c);\n    Vec e2 = Vec(-e1.imag(), e1.real());\n    if (lt(d, std::abs(c2.r\
    \ - c1.r))) return {};  // contain\n    if (eq(d, std::abs(c2.r - c1.r))) return\
    \ {c1.c + c1.r*e1};  // tangent\n    T x = (c1.r*c1.r - c2.r*c2.r + d*d) / (2*d);\n\
    \    T y = std::sqrt(c1.r*c1.r - x*x);\n    return {c1.c + x*e1 + y*e2, c1.c +\
    \ x*e1 - y*e2};\n}\n\nT area(const Polygon& poly) {\n    const int n = poly.size();\n\
    \    T res = 0;\n    for (int i = 0; i < n; ++i) {\n        res += cross(poly[i],\
    \ poly[(i + 1) % n]);\n    }\n    return std::abs(res) / T(2);\n}\n\nT area_intersection(const\
    \ Circle& c1, const Circle& c2) {\n    T d = std::abs(c2.c - c1.c);\n    if (leq(c1.r\
    \ + c2.r, d)) return 0;  // outside\n    if (leq(d, std::abs(c2.r - c1.r))) {\
    \  // inside\n        T r = std::min(c1.r, c2.r);\n        return PI * r * r;\n\
    \    }\n    T ans = 0;\n    T a;\n    a = std::acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));\n\
    \    ans += c1.r*c1.r*(a - std::sin(a)*std::cos(a));\n    a = std::acos((c2.r*c2.r+d*d-c1.r*c1.r)/(2*c2.r*d));\n\
    \    ans += c2.r*c2.r*(a - std::sin(a)*std::cos(a));\n    return ans;\n}\n\nbool\
    \ is_convex(const Polygon& poly) {\n    int n = poly.size();\n    for (int i =\
    \ 0; i < n; ++i) {\n        if (lt(cross(poly[(i+1)%n] - poly[i], poly[(i+2)%n]\
    \ - poly[(i+1)%n]), 0)) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n\nstd::vector<Vec> convex_cut(const Polygon& poly, const Line& l)\
    \ {\n    const int n = poly.size();\n    std::vector<Vec> res;\n    for (int i\
    \ = 0; i < n; ++i) {\n        auto p = poly[i], q = poly[(i+1)%n];\n        if\
    \ (ccw(l.p1, l.p2, p) != -1) {\n            if (res.empty() || !eq(res.back(),\
    \ p)) {\n                res.push_back(p);\n            }\n        }\n       \
    \ if (ccw(l.p1, l.p2, p) * ccw(l.p1, l.p2, q) < 0) {\n            auto c = intersection(Line(p,\
    \ q), l);\n            if (res.empty() || !eq(res.back(), c)) {\n            \
    \    res.push_back(c);\n            }\n        }\n    }\n    return res;\n}\n\n\
    Vec centroid(const Vec& A, const Vec& B, const Vec& C) {\n    assert(ccw(A, B,\
    \ C) != 0);\n    return (A + B + C) / T(3);\n}\n\nVec incenter(const Vec& A, const\
    \ Vec& B, const Vec& C) {\n    assert(ccw(A, B, C) != 0);\n    T a = std::abs(B\
    \ - C);\n    T b = std::abs(C - A);\n    T c = std::abs(A - B);\n    return (a*A\
    \ + b*B + c*C) / (a + b + c);\n}\n\nVec circumcenter(const Vec& A, const Vec&\
    \ B, const Vec& C) {\n    assert(ccw(A, B, C) != 0);\n    return intersection(bisector(A,\
    \ B), bisector(A, C));\n}\n\n// large error but beautiful\n// Vec circumcenter(const\
    \ Vec& A, const Vec& B, const Vec& C) {\n//     assert(ccw(A, B, C) != 0);\n//\
    \     Vec p = C - B, q = A - C, r = B - A;\n//     T a = std::norm(p) * dot(q,\
    \ r);\n//     T b = std::norm(q) * dot(r, p);\n//     T c = std::norm(r) * dot(p,\
    \ q);\n//     return (a*A + b*B + c*C) / (a + b + c);\n// }\n\nstd::pair<Vec,\
    \ Vec> tangent_points(const Circle& c, const Vec& p) {\n    auto m = (p + c.c)\
    \ / T(2);\n    auto is = intersection(c, Circle(m, std::abs(p - m)));\n    return\
    \ {is[0], is[1]};\n}\n\n// for each l, l.p1 is a tangent point of c1\nstd::vector<Line>\
    \ common_tangents(Circle c1, Circle c2) {\n    assert(!eq(c1.c, c2.c) || !eq(c1.r,\
    \ c2.r));\n    int cnt = intersect(c1, c2);  // number of common tangents\n  \
    \  std::vector<Line> ret;\n    if (cnt == 0) {\n        return ret;\n    }\n\n\
    \    // external\n    if (eq(c1.r, c2.r)) {\n        auto d = c2.c - c1.c;\n \
    \       Vec e(-d.imag(), d.real());\n        e = e / std::abs(e) * c1.r;\n   \
    \     ret.push_back(Line(c1.c + e, c1.c + e + d));\n        ret.push_back(Line(c1.c\
    \ - e, c1.c - e + d));\n    } else {\n        auto p = (-c2.r*c1.c + c1.r*c2.c)\
    \ / (c1.r - c2.r);\n        if (cnt == 1) {\n            Vec q(-p.imag(), p.real());\n\
    \            return {Line(p, q)};\n        } else {\n            auto [a, b] =\
    \ tangent_points(c1, p);\n            ret.push_back(Line(a, p));\n           \
    \ ret.push_back(Line(b, p));\n        }\n    }\n\n    // internal\n    auto p\
    \ = (c2.r*c1.c + c1.r*c2.c) / (c1.r + c2.r);\n    if (cnt == 3) {\n        Vec\
    \ q(-p.imag(), p.real());\n        ret.push_back(Line(p, q));\n    } else if (cnt\
    \ == 4) {\n        auto [a, b] = tangent_points(c1, p);\n        ret.push_back(Line(a,\
    \ p));\n        ret.push_back(Line(b, p));\n    }\n\n    return ret;\n}\n\nvoid\
    \ sort_by_arg(std::vector<Vec>& pts) {\n    std::sort(pts.begin(), pts.end(),\
    \ [&](auto& p, auto& q) {\n        if ((p.imag() < 0) != (q.imag() < 0)) return\
    \ (p.imag() < 0);\n        if (cross(p, q) == 0) {\n            if (p == Vec(0,\
    \ 0)) return !(q.imag() < 0 || (q.imag() == 0 && q.real() > 0));\n           \
    \ if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag() == 0 && p.real() > 0));\n\
    \            return (p.real() > q.real());\n        }\n        return (cross(p,\
    \ q) > 0);\n    });\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <iostream>\n#include <vector>\n\n// note that if\
    \ T is of an integer type, std::abs does not work\nusing T = double;\nusing Vec\
    \ = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\nconstexpr T eps = 1e-12;\n\
    inline bool eq(T a, T b) { return std::abs(a - b) < eps; }\ninline bool eq(Vec\
    \ a, Vec b) { return std::abs(a - b) < eps; }\ninline bool lt(T a, T b) { return\
    \ a < b - eps; }\ninline bool leq(T a, T b) { return a < b + eps; }\n\nstd::istream&\
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
    \ projection(const Line& l, const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir())\
    \ * l.dir() / std::norm(l.dir());\n}\n\nVec reflection(const Line& l, const Vec&\
    \ p) {\n    return T(2) * projection(l, p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n\
    // 2: clockwise\nint ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b\
    \ - a, c - a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0)) return -1;\n\
    \    return 1;\n}\n\nLine bisector(const Vec& p, const Vec& q) {\n    auto m =\
    \ (p + q) / T(2);\n    auto v = q - p;\n    return Line(m, m + Vec(-v.imag(),\
    \ v.real()));\n}\n\nbool intersect(const Segment& s, const Vec& p) {\n    Vec\
    \ u = s.p1 - p, v = s.p2 - p;\n    return eq(cross(u, v), 0) && leq(dot(u, v),\
    \ 0);\n}\n\n// 0: outside\n// 1: on the border\n// 2: inside\nint intersect(const\
    \ Polygon& poly, const Vec& p) {\n    const int n = poly.size();\n    bool in\
    \ = 0;\n    for (int i = 0; i < n; ++i) {\n        auto a = poly[i] - p, b = poly[(i+1)%n]\
    \ - p;\n        if (eq(cross(a, b), 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0)))\
    \ return 1;\n        if (a.imag() > b.imag()) std::swap(a, b);\n        if (leq(a.imag(),\
    \ 0) && lt(0, b.imag()) && lt(cross(a, b), 0)) in ^= 1;\n    }\n    return in\
    \ ? 2 : 0;\n}\n\nbool intersect(const Segment& s, const Segment& t) {\n    auto\
    \ a = s.p1, b = s.p2;\n    auto c = t.p1, d = t.p2;\n    if (ccw(a, b, c) != ccw(a,\
    \ b, d) && ccw(c, d, a) != ccw(c, d, b)) return 2;\n    if (intersect(s, c) ||\
    \ intersect(s, d) || intersect(t, a) || intersect(t, b)) return 1;\n    return\
    \ 0;\n}\n\n// 0: inside\n// 1: inscribe\n// 2: intersect\n// 3: circumscribe\n\
    // 4: outside\nint intersect(const Circle& c1, const Circle& c2) {\n    T d =\
    \ std::abs(c1.c - c2.c);\n    if (lt(d, std::abs(c2.r - c1.r))) return 0;\n  \
    \  if (eq(d, std::abs(c2.r - c1.r))) return 1;\n    if (eq(c1.r + c2.r, d)) return\
    \ 3;\n    if (lt(c1.r + c2.r, d)) return 4;\n    return 2;\n}\n\nT dist(const\
    \ Line& l, const Vec& p) {\n    return std::abs(cross(p - l.p1, l.dir())) / std::abs(l.dir());\n\
    }\n\nT dist(const Segment& s, const Vec& p) {\n    if (lt(dot(p - s.p1, s.dir()),\
    \ 0)) return std::abs(p - s.p1);\n    if (lt(dot(p - s.p2, -s.dir()), 0)) return\
    \ std::abs(p - s.p2);\n    return std::abs(cross(p - s.p1, s.dir())) / std::abs(s.dir());\n\
    }\n\nT dist(const Segment& s, const Segment& t) {\n    if (intersect(s, t)) return\
    \ T(0);\n    return std::min({dist(s, t.p1), dist(s, t.p2), dist(t, s.p1), dist(t,\
    \ s.p2)});\n}\n\nVec intersection(const Line& l, const Line& m) {\n    Vec r =\
    \ m.p1 - l.p1;\n    assert(!eq(cross(l.dir(), m.dir()), 0)); // not parallel\n\
    \    return l.p1 + cross(m.dir(), r) / cross(m.dir(), l.dir()) * l.dir();\n}\n\
    \nstd::vector<Vec> intersection(const Circle& c, const Line& l) {\n    T d = dist(l,\
    \ c.c);\n    if (lt(c.r, d)) return {};  // no intersection\n    Vec e1 = l.dir()\
    \ / std::abs(l.dir());\n    Vec e2 = Vec(-e1.imag(), e1.real());\n    if (ccw(c.c,\
    \ l.p1, l.p2) == 1) e2 *= -1;\n    if (eq(c.r, d)) return {c.c + d*e2};  // tangent\n\
    \    T t = std::sqrt(c.r*c.r - d*d);\n    return {c.c + d*e2 + t*e1, c.c + d*e2\
    \ - t*e1};\n}\n\nstd::vector<Vec> intersection(const Circle& c1, const Circle&\
    \ c2) {\n    T d = std::abs(c1.c - c2.c);\n    if (lt(c1.r + c2.r, d)) return\
    \ {};  // outside\n    Vec e1 = (c2.c - c1.c) / std::abs(c2.c - c1.c);\n    Vec\
    \ e2 = Vec(-e1.imag(), e1.real());\n    if (lt(d, std::abs(c2.r - c1.r))) return\
    \ {};  // contain\n    if (eq(d, std::abs(c2.r - c1.r))) return {c1.c + c1.r*e1};\
    \  // tangent\n    T x = (c1.r*c1.r - c2.r*c2.r + d*d) / (2*d);\n    T y = std::sqrt(c1.r*c1.r\
    \ - x*x);\n    return {c1.c + x*e1 + y*e2, c1.c + x*e1 - y*e2};\n}\n\nT area(const\
    \ Polygon& poly) {\n    const int n = poly.size();\n    T res = 0;\n    for (int\
    \ i = 0; i < n; ++i) {\n        res += cross(poly[i], poly[(i + 1) % n]);\n  \
    \  }\n    return std::abs(res) / T(2);\n}\n\nT area_intersection(const Circle&\
    \ c1, const Circle& c2) {\n    T d = std::abs(c2.c - c1.c);\n    if (leq(c1.r\
    \ + c2.r, d)) return 0;  // outside\n    if (leq(d, std::abs(c2.r - c1.r))) {\
    \  // inside\n        T r = std::min(c1.r, c2.r);\n        return PI * r * r;\n\
    \    }\n    T ans = 0;\n    T a;\n    a = std::acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));\n\
    \    ans += c1.r*c1.r*(a - std::sin(a)*std::cos(a));\n    a = std::acos((c2.r*c2.r+d*d-c1.r*c1.r)/(2*c2.r*d));\n\
    \    ans += c2.r*c2.r*(a - std::sin(a)*std::cos(a));\n    return ans;\n}\n\nbool\
    \ is_convex(const Polygon& poly) {\n    int n = poly.size();\n    for (int i =\
    \ 0; i < n; ++i) {\n        if (lt(cross(poly[(i+1)%n] - poly[i], poly[(i+2)%n]\
    \ - poly[(i+1)%n]), 0)) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}\n\nstd::vector<Vec> convex_cut(const Polygon& poly, const Line& l)\
    \ {\n    const int n = poly.size();\n    std::vector<Vec> res;\n    for (int i\
    \ = 0; i < n; ++i) {\n        auto p = poly[i], q = poly[(i+1)%n];\n        if\
    \ (ccw(l.p1, l.p2, p) != -1) {\n            if (res.empty() || !eq(res.back(),\
    \ p)) {\n                res.push_back(p);\n            }\n        }\n       \
    \ if (ccw(l.p1, l.p2, p) * ccw(l.p1, l.p2, q) < 0) {\n            auto c = intersection(Line(p,\
    \ q), l);\n            if (res.empty() || !eq(res.back(), c)) {\n            \
    \    res.push_back(c);\n            }\n        }\n    }\n    return res;\n}\n\n\
    Vec centroid(const Vec& A, const Vec& B, const Vec& C) {\n    assert(ccw(A, B,\
    \ C) != 0);\n    return (A + B + C) / T(3);\n}\n\nVec incenter(const Vec& A, const\
    \ Vec& B, const Vec& C) {\n    assert(ccw(A, B, C) != 0);\n    T a = std::abs(B\
    \ - C);\n    T b = std::abs(C - A);\n    T c = std::abs(A - B);\n    return (a*A\
    \ + b*B + c*C) / (a + b + c);\n}\n\nVec circumcenter(const Vec& A, const Vec&\
    \ B, const Vec& C) {\n    assert(ccw(A, B, C) != 0);\n    return intersection(bisector(A,\
    \ B), bisector(A, C));\n}\n\n// large error but beautiful\n// Vec circumcenter(const\
    \ Vec& A, const Vec& B, const Vec& C) {\n//     assert(ccw(A, B, C) != 0);\n//\
    \     Vec p = C - B, q = A - C, r = B - A;\n//     T a = std::norm(p) * dot(q,\
    \ r);\n//     T b = std::norm(q) * dot(r, p);\n//     T c = std::norm(r) * dot(p,\
    \ q);\n//     return (a*A + b*B + c*C) / (a + b + c);\n// }\n\nstd::pair<Vec,\
    \ Vec> tangent_points(const Circle& c, const Vec& p) {\n    auto m = (p + c.c)\
    \ / T(2);\n    auto is = intersection(c, Circle(m, std::abs(p - m)));\n    return\
    \ {is[0], is[1]};\n}\n\n// for each l, l.p1 is a tangent point of c1\nstd::vector<Line>\
    \ common_tangents(Circle c1, Circle c2) {\n    assert(!eq(c1.c, c2.c) || !eq(c1.r,\
    \ c2.r));\n    int cnt = intersect(c1, c2);  // number of common tangents\n  \
    \  std::vector<Line> ret;\n    if (cnt == 0) {\n        return ret;\n    }\n\n\
    \    // external\n    if (eq(c1.r, c2.r)) {\n        auto d = c2.c - c1.c;\n \
    \       Vec e(-d.imag(), d.real());\n        e = e / std::abs(e) * c1.r;\n   \
    \     ret.push_back(Line(c1.c + e, c1.c + e + d));\n        ret.push_back(Line(c1.c\
    \ - e, c1.c - e + d));\n    } else {\n        auto p = (-c2.r*c1.c + c1.r*c2.c)\
    \ / (c1.r - c2.r);\n        if (cnt == 1) {\n            Vec q(-p.imag(), p.real());\n\
    \            return {Line(p, q)};\n        } else {\n            auto [a, b] =\
    \ tangent_points(c1, p);\n            ret.push_back(Line(a, p));\n           \
    \ ret.push_back(Line(b, p));\n        }\n    }\n\n    // internal\n    auto p\
    \ = (c2.r*c1.c + c1.r*c2.c) / (c1.r + c2.r);\n    if (cnt == 3) {\n        Vec\
    \ q(-p.imag(), p.real());\n        ret.push_back(Line(p, q));\n    } else if (cnt\
    \ == 4) {\n        auto [a, b] = tangent_points(c1, p);\n        ret.push_back(Line(a,\
    \ p));\n        ret.push_back(Line(b, p));\n    }\n\n    return ret;\n}\n\nvoid\
    \ sort_by_arg(std::vector<Vec>& pts) {\n    std::sort(pts.begin(), pts.end(),\
    \ [&](auto& p, auto& q) {\n        if ((p.imag() < 0) != (q.imag() < 0)) return\
    \ (p.imag() < 0);\n        if (cross(p, q) == 0) {\n            if (p == Vec(0,\
    \ 0)) return !(q.imag() < 0 || (q.imag() == 0 && q.real() > 0));\n           \
    \ if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag() == 0 && p.real() > 0));\n\
    \            return (p.real() > q.real());\n        }\n        return (cross(p,\
    \ q) > 0);\n    });\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy:
  - geometry/delaunay_diagram.hpp
  - geometry/convex_hull.hpp
  - geometry/closest_pair.hpp
  timestamp: '2022-05-06 13:09:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_7_G.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_4_C.test.cpp
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

- `T dot(Vec a, Vec b)`
    - 内積を計算する

- `T cross(Vec a, Vec b)`
    - 外積の $z$ 座標を計算する

- `Vec rot(Vec a, T ang)`
    - $a$ を角 $ang$ だけ回転させる
    - ***NOT VERIFIED***

- `Vec projection(Line l, Vec p)`
    - 点 $p$ の直線 $l$ 上の射影を求める

- `Vec reflection(Line l, Vec p)`
    - 点 $p$ の直線 $l$ に関して対称な点を求める

- `int ccw(Vec a, Vec b, Vec c)`
    - $a,b,c$ が同一直線上にあるなら0, $a \rightarrow b \rightarrow c$ が反時計回りなら1，そうでなければ-1を返す

- `Line bisector(Vec p, Vec q)`
    - 点 $p,q$ の垂直二等分線を返す

- `bool intersect(Segment s, Vec p)`

  `int intersect(Polygon poly, Vec p)`

  `int intersect(Segment s, Segment t)`

  `int intersect(Circle c1, Circle c2)`
    - 引数で与えられた2つの対象が交差するか判定する．詳細な仕様はコードのコメントを参照

 - `T dist(Line l, Vec p)`

   `T dist(Segment s, Vec p)`

   `T dist(Segment s, Segment t)`
    - 引数で与えられた2つの対象の距離を計算する

- `Vec intersection(Line l, Line m)`

- `vector<Vec> intersection(Circle c, Line l)`

  `vector<Vec> intersection(Circle c1, Circle c2)`
    - 引数で与えられた2つの対象の交点を返す

- `T area(Polygon poly)`
    - 多角形 $poly$ の面積を求める
    - 時間計算量: $O(n)$

- `T area_intersection(Circle c1, Circle c2)`
    - 円 $c_1,c_2$ の共通部分の面積を求める

- `T is_convex(Polygon poly)`
    - 多角形 $poly$ が凸か判定する．`poly` は反時計回りに与えられる必要がある
    - 時間計算量: $O(n)$

- `vector<Vec> convex_cut(Polygon poly, Line l)`
    - 多角形 $poly$ を直線 $l$ で切断する．詳細な仕様は [凸多角形の切断](https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C) を参照．
    - 時間計算量: $O(n)$

- `Vec centroid(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の重心を返す
    - ***NOT VERIFIED***

- `Vec incenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の内心を返す

- `Vec circumcenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の外心を返す

- `pair<Vec, Vec> tangent_ponints(Circle c, Vec p)`
    - 点 $p$ を通り円 $c$ に接する接線と $c$ の接点を返す

- `vector<Line> common_tangents(Circle c1, Circle c2)`
    - 円 $c_1,c_2$ の共通接線を返す

- `vector<Vec> convex_hull(vector<Vec> pts)`
    - 与えられた点の凸包を返す
    - 時間計算量: $O(n\log n)$

- `T closest_pair(vector<Vec> pts)`
    - 与えられた点のうち最も近い2点の距離を分割統治法で求める
    - 時間計算量: $O(n\log n)$

- `void sort_by_arg(vector<Vec> pts)`
  - 与えられた点を偏角ソートする (ソート順は[この問題](https://judge.yosupo.jp/problem/sort_points_by_argument)に準拠)
  - 時間計算量: $O(n\log n)$