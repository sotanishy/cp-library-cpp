---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: Geometry
  - icon: ':heavy_check_mark:'
    path: geometry/intersect.hpp
    title: geometry/intersect.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
  bundledCode: "#line 1 \"test/aoj/CGL_7_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\
    \n\n#line 2 \"geometry/geometry.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <iostream>\n#include <vector>\n\
    \n// note that if T is of an integer type, std::abs does not work\nusing T = double;\n\
    using Vec = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\nconstexpr T eps\
    \ = 1e-12;\ninline bool eq(T a, T b) { return std::abs(a - b) < eps; }\ninline\
    \ bool eq(Vec a, Vec b) { return std::abs(a - b) < eps; }\ninline bool lt(T a,\
    \ T b) { return a < b - eps; }\ninline bool leq(T a, T b) { return a < b + eps;\
    \ }\n\nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y;\n   \
    \ is >> x >> y;\n    p = {x, y};\n    return is;\n}\n\nstruct Line {\n    Vec\
    \ p1, p2;\n    Line() = default;\n    Line(const Vec& p1, const Vec& p2) : p1(p1),\
    \ p2(p2) {}\n    Vec dir() const { return p2 - p1; }\n};\n\nstruct Segment {\n\
    \    Vec p1, p2;\n    Segment() = default;\n    Segment(const Vec& p1, const Vec&\
    \ p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2 - p1; }\n};\n\nstruct\
    \ Circle {\n    Vec c;\n    T r;\n    Circle() = default;\n    Circle(const Vec&\
    \ c, T r) : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\nT dot(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\nT cross(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nVec rot(const\
    \ Vec& a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n}\n\nVec\
    \ projection(const Line& l, const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir())\
    \ * l.dir() / std::norm(l.dir());\n}\n\nVec reflection(const Line& l, const Vec&\
    \ p) {\n    return T(2) * projection(l, p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n\
    // 2: clockwise\nint ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b\
    \ - a, c - a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0)) return -1;\n\
    \    return 1;\n}\n\nLine bisector(const Vec& p, const Vec& q) {\n    auto m =\
    \ (p + q) / T(2);\n    auto v = q - p;\n    return Line(m, m + Vec(-v.imag(),\
    \ v.real()));\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n    std::sort(pts.begin(),\
    \ pts.end(), [&](auto& p, auto& q) {\n        if ((p.imag() < 0) != (q.imag()\
    \ < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0) {\n            if\
    \ (p == Vec(0, 0)) return !(q.imag() < 0 || (q.imag() == 0 && q.real() > 0));\n\
    \            if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag() == 0 && p.real()\
    \ > 0));\n            return (p.real() > q.real());\n        }\n        return\
    \ (cross(p, q) > 0);\n    });\n}\n#line 3 \"geometry/intersect.hpp\"\n\nbool intersect(const\
    \ Segment& s, const Vec& p) {\n    Vec u = s.p1 - p, v = s.p2 - p;\n    return\
    \ eq(cross(u, v), 0) && leq(dot(u, v), 0);\n}\n\n// 0: outside\n// 1: on the border\n\
    // 2: inside\nint intersect(const Polygon& poly, const Vec& p) {\n    const int\
    \ n = poly.size();\n    bool in = 0;\n    for (int i = 0; i < n; ++i) {\n    \
    \    auto a = poly[i] - p, b = poly[(i+1)%n] - p;\n        if (eq(cross(a, b),\
    \ 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0))) return 1;\n        if (a.imag()\
    \ > b.imag()) std::swap(a, b);\n        if (leq(a.imag(), 0) && lt(0, b.imag())\
    \ && lt(cross(a, b), 0)) in ^= 1;\n    }\n    return in ? 2 : 0;\n}\n\nbool intersect(const\
    \ Segment& s, const Segment& t) {\n    auto a = s.p1, b = s.p2;\n    auto c =\
    \ t.p1, d = t.p2;\n    if (ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c,\
    \ d, b)) return 2;\n    if (intersect(s, c) || intersect(s, d) || intersect(t,\
    \ a) || intersect(t, b)) return 1;\n    return 0;\n}\n\n// true if they have positive\
    \ area in common or touch on the border\nbool intersect(const Polygon& poly1,\
    \ const Polygon& poly2) {\n    const int n = poly1.size();\n    const int m =\
    \ poly2.size();\n    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j\
    \ < m; ++j) {\n            if (intersect(Segment(poly1[i], poly1[(i+1)%n]), Segment(poly2[j],\
    \ poly2[(j+1)%n]))) {\n                return true;\n            }\n        }\n\
    \    }\n    return intersect(poly1, poly2[0]) || intersect(poly2, poly1[0]);\n\
    }\n\n// 0: inside\n// 1: inscribe\n// 2: intersect\n// 3: circumscribe\n// 4:\
    \ outside\nint intersect(const Circle& c1, const Circle& c2) {\n    T d = std::abs(c1.c\
    \ - c2.c);\n    if (lt(d, std::abs(c2.r - c1.r))) return 0;\n    if (eq(d, std::abs(c2.r\
    \ - c1.r))) return 1;\n    if (eq(c1.r + c2.r, d)) return 3;\n    if (lt(c1.r\
    \ + c2.r, d)) return 4;\n    return 2;\n}\n#line 5 \"test/aoj/CGL_7_A.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n\n    Vec c1,\
    \ c2;\n    T r1, r2;\n    cin >> c1 >> r1 >> c2 >> r2;\n    cout << intersect(Circle(c1,\
    \ r1), Circle(c2, r2)) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\
    \n\n#include \"../../geometry/geometry.hpp\"\n#include \"../../geometry/intersect.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n\n    Vec c1,\
    \ c2;\n    T r1, r2;\n    cin >> c1 >> r1 >> c2 >> r2;\n    cout << intersect(Circle(c1,\
    \ r1), Circle(c2, r2)) << endl;\n}"
  dependsOn:
  - geometry/geometry.hpp
  - geometry/intersect.hpp
  isVerificationFile: true
  path: test/aoj/CGL_7_A.test.cpp
  requiredBy: []
  timestamp: '2022-05-09 11:09:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_A.test.cpp
- /verify/test/aoj/CGL_7_A.test.cpp.html
title: test/aoj/CGL_7_A.test.cpp
---
