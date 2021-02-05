---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/geometry.cpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
  bundledCode: "#line 1 \"test/aoj/CGL_7_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\"\
    \n#define ERROR 0.00000001\n\n#line 2 \"math/geometry.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n\
    #include <vector>\n\nconstexpr double eps = 1e-12;\n\ninline bool eq(double a,\
    \ double b) { return std::abs(a - b) < eps; }\ninline bool lt(double a, double\
    \ b) { return a < b - eps; }\ninline bool leq(double a, double b) { return a <\
    \ b + eps; }\n\nusing Vec = std::complex<double>;\n\ndouble dot(const Vec& a,\
    \ const Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\ndouble cross(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nVec rot(const\
    \ Vec& a, double ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n}\n\
    \nbool are_colinear(const Vec& p1, const Vec& p2, const Vec& p3) {\n    return\
    \ eq(cross(p2 - p1, p3 - p1), 0);\n}\n\nbool ccw(const Vec& a, const Vec& b, const\
    \ Vec& c) {\n    return !lt(std::arg((c - a) / (b - a)), 0);\n}\n\nbool intersect(const\
    \ Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n    return ccw(a, c, d)\
    \ != ccw(b, c, d) && ccw(a, b, c) != ccw(a, b, d);\n}\n\nbool on_segment(const\
    \ Vec& p1, const Vec& p2, const Vec& q) {\n    Vec v1 = p1 - q, v2 = p2 - q;\n\
    \    return eq(cross(v1, v2), 0) && lt(dot(v1, v2), 0);\n}\n\ndouble line_point_dist(const\
    \ Vec& p1, const Vec& p2, const Vec& q) {\n    Vec p = p2 - p1;\n    return std::abs(cross(q,\
    \ p) + cross(p2, p1)) / std::abs(p);\n}\n\nVec intersection(const Vec& p1, const\
    \ Vec& p2, const Vec& q1, const Vec& q2) {\n    Vec p = p2 - p1;\n    Vec q =\
    \ q2 - q1;\n    Vec r = q1 - p1;\n    assert(!eq(cross(q, p), 0)); // not parallel\n\
    \    return p1 + cross(q, r) / cross(q, p) * p;\n}\n\n// returns a list of the\
    \ intersections of two circles\nstd::vector<Vec> intersection_circles(const Vec&\
    \ c1, double r1, const Vec& c2, double r2) {\n    double d = std::abs(c1 - c2);\n\
    \    // if the circles are outside of each other\n    if (lt(r1 + r2, d)) return\
    \ {};\n    // if one contains the other entirely\n    if (lt(d, std::abs(r2 -\
    \ r1))) return {};\n    double x = (r1*r1 - r2*r2 + d*d) / (2*d);\n    double\
    \ y = std::sqrt(r1*r1 - x*x);\n    Vec e1 = (c2 - c1) / std::abs(c2 - c1);\n \
    \   Vec e2 = Vec(-e1.imag(), e1.real());\n    return {c1 + x*e1 + y*e2, c1 + x*e1\
    \ - y*e2};\n}\n\n// returns a list of the intersections of a circle and a line\n\
    std::vector<Vec> intersection_circle_line(const Vec& c, double r, const Vec& p1,\
    \ const Vec& p2) {\n    double d = line_point_dist(p1, p2, c);\n    // no intersection\n\
    \    if (lt(r, d)) return {};\n    Vec e1 = (p2 - p1) / std::abs(p2 - p1);\n \
    \   Vec e2 = Vec(-e1.imag(), e1.real());\n    double t = std::sqrt(r*r - d*d);\n\
    \    if (eq(d, 0)) return {c + t*e1, c - t*e1};\n    if (ccw(c, p1, p2)) e2 *=\
    \ -1;\n    if (eq(r, d)) return {c + d*e2};\n    return {c + d*e2 + t*e1, c +\
    \ d*e2 - t*e1};\n}\n\ndouble area(const Vec& A, const Vec& B, const Vec& C) {\n\
    \    return std::abs(cross(B - A, C - A)) / 2.0;\n}\n\nVec centroid(const Vec&\
    \ A, const Vec& B, const Vec& C) {\n    assert(!are_colinear(A, B, C));\n    return\
    \ (A + B + C) / 3.0;\n}\n\nVec circumcenter(const Vec& A, const Vec& B, const\
    \ Vec& C) {\n    assert(!are_colinear(A, B, C));\n    double a = std::abs(B -\
    \ C);\n    double b = std::abs(C - A);\n    double c = std::abs(A - B);\n    double\
    \ cosA = (b*b + c*c - a*a) / (2*b*c);\n    double cosB = (c*c + a*a - b*b) / (2*c*a);\n\
    \    double cosC = (a*a + b*b - c*c) / (2*a*b);\n    return (a*cosA*A + b*cosB*B\
    \ + c*cosC*C) / (a*cosA + b*cosB + c*cosC);\n}\n\nVec incenter(const Vec& A, const\
    \ Vec& B, const Vec& C) {\n    assert(!are_colinear(A, B, C));\n    double a =\
    \ std::abs(B - C);\n    double b = std::abs(C - A);\n    double c = std::abs(A\
    \ - B);\n    return (a*A + b*B + c*C) / (a + b + c);\n}\n\nstd::vector<Vec> convex_hull(std::vector<Vec>&\
    \ points) {\n    int n = points.size();\n    std::sort(points.begin(), points.end(),\
    \ [](const Vec& v1, const Vec& v2) {\n        return (v1.imag() != v2.imag())\
    \ ? (v1.imag() < v2.imag()) : (v1.real() < v2.real());\n    });\n    int k = 0;\
    \ // the number of vertices in the convex hull\n    std::vector<Vec> ch(2 * n);\n\
    \    // right\n    for (int i = 0; i < n; ++i) {\n        while (k > 1 && lt(cross(ch[k-1]\
    \ - ch[k-2], points[i] - ch[k-1]), 0)) --k;\n        ch[k++] = points[i];\n  \
    \  }\n    int t = k;\n    // left\n    for (int i = n - 2; i >= 0; --i) {\n  \
    \      while (k > t && lt(cross(ch[k-1] - ch[k-2], points[i] - ch[k-1]), 0)) --k;\n\
    \        ch[k++] = points[i];\n    }\n    ch.resize(k - 1);\n    return ch;\n\
    }\n#line 5 \"test/aoj/CGL_7_D.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    cout << fixed << setprecision(10);\n\n    double cx, cy, r;\n    cin >> cx\
    \ >> cy >> r;\n    Vec c = {cx, cy};\n    int q;\n    cin >> q;\n    while (q--)\
    \ {\n        double x1, y1, x2, y2;\n        cin >> x1 >> y1 >> x2 >> y2;\n  \
    \      Vec p1 = {x1, y1}, p2 = {x2, y2};\n        auto ans = intersection_circle_line(c,\
    \ r, p1, p2);\n        if (ans.size() == 1) {\n            cout << ans[0].real()\
    \ << \" \" << ans[0].imag() << \" \";\n            cout << ans[0].real() << \"\
    \ \" << ans[0].imag() << endl;\n        } else {\n            if (make_pair(ans[0].real(),\
    \ ans[0].imag()) > make_pair(ans[1].real(), ans[1].imag())) swap(ans[0], ans[1]);\n\
    \            cout << ans[0].real() << \" \" << ans[0].imag() << \" \";\n     \
    \       cout << ans[1].real() << \" \" << ans[1].imag() << endl;\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\"\
    \n#define ERROR 0.00000001\n\n#include \"../../math/geometry.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(10);\n\n    double cx,\
    \ cy, r;\n    cin >> cx >> cy >> r;\n    Vec c = {cx, cy};\n    int q;\n    cin\
    \ >> q;\n    while (q--) {\n        double x1, y1, x2, y2;\n        cin >> x1\
    \ >> y1 >> x2 >> y2;\n        Vec p1 = {x1, y1}, p2 = {x2, y2};\n        auto\
    \ ans = intersection_circle_line(c, r, p1, p2);\n        if (ans.size() == 1)\
    \ {\n            cout << ans[0].real() << \" \" << ans[0].imag() << \" \";\n \
    \           cout << ans[0].real() << \" \" << ans[0].imag() << endl;\n       \
    \ } else {\n            if (make_pair(ans[0].real(), ans[0].imag()) > make_pair(ans[1].real(),\
    \ ans[1].imag())) swap(ans[0], ans[1]);\n            cout << ans[0].real() <<\
    \ \" \" << ans[0].imag() << \" \";\n            cout << ans[1].real() << \" \"\
    \ << ans[1].imag() << endl;\n        }\n    }\n}\n"
  dependsOn:
  - math/geometry.cpp
  isVerificationFile: true
  path: test/aoj/CGL_7_D.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 03:00:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_7_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_D.test.cpp
- /verify/test/aoj/CGL_7_D.test.cpp.html
title: test/aoj/CGL_7_D.test.cpp
---
