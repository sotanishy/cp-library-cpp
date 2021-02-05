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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 1 \"test/aoj/CGL_4_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n#line 2 \"math/geometry.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <iostream>\n#include <optional>\n\
    #include <vector>\n\nconstexpr double eps = 1e-12;\n\ninline bool eq(double a,\
    \ double b) { return std::abs(a - b) < eps; }\ninline bool lt(double a, double\
    \ b) { return a < b - eps; }\ninline bool leq(double a, double b) { return a <\
    \ b + eps; }\n\nusing Vec = std::complex<double>;\n\ndouble dot(const Vec& a,\
    \ const Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\ndouble cross(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nVec rot(const\
    \ Vec& a, double ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n}\n\
    \n// checks if the three points are on the same line\nbool are_colinear(const\
    \ Vec& p1, const Vec& p2, const Vec& p3) {\n    return eq(cross(p2 - p1, p3 -\
    \ p1), 0);\n}\n\n// checks if a -> b -> c is counter clockwise\nbool ccw(const\
    \ Vec& a, const Vec& b, const Vec& c) {\n    return !lt(std::arg((c - a) / (b\
    \ - a)), 0);\n}\n\n// checks if the segment ab intersects with the segment cd\n\
    bool intersect(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n   \
    \ return ccw(a, c, d) != ccw(b, c, d) && ccw(a, b, c) != ccw(a, b, d);\n}\n\n\
    // checks if q is on the segment p1-p2\nbool on_segment(const Vec& p1, const Vec&\
    \ p2, const Vec& q) {\n    Vec v1 = p1 - q, v2 = p2 - q;\n    return eq(cross(v1,\
    \ v2), 0) && eq(dot(v1, v2), 0);\n}\n\n// returns the intersection of the lines\
    \ p1-p2 and q1-q2\n// if the lines are parallel, returns nullopt\nstd::optional<Vec>\
    \ intersection(const Vec& p1, const Vec& p2, const Vec& q1, const Vec& q2) {\n\
    \    Vec p = p2 - p1;\n    Vec q = q2 - q1;\n    Vec r = q1 - p1;\n    // if parallel\n\
    \    if (eq(cross(q, p), 0)) return std::nullopt;\n    return p1 + cross(q, r)\
    \ / cross(q, p) * p;\n}\n\n// returns a list of the intersections of two circles\n\
    std::vector<Vec> intersection_circles(const Vec& c1, double r1, const Vec& c2,\
    \ double r2) {\n    double d = std::abs(c1 - c2);\n    // if the circles are outside\
    \ of each other\n    if (lt(r1 + r2, d)) return {};\n    // if one contains the\
    \ other entirely\n    if (lt(d, std::abs(r2 - r1))) return {};\n    double x =\
    \ (r1*r1 - r2*r2 + d*d) / (2*d);\n    double y = std::sqrt(r1*r1 - x*x);\n   \
    \ Vec e1 = (c2 - c1) / std::abs(c2 - c1);\n    Vec e2 = Vec(-e1.imag(), e1.real());\n\
    \    Vec p1 = c1 + e1 * x + e2 * y;\n    Vec p2 = c1 + e1 * x - e2 * y;\n    return\
    \ {p1, p2};\n}\n\n// returns the distance between the point q and the line p1-p2\n\
    double point_line_dist(const Vec& p1, const Vec& p2, const Vec& q) {\n    Vec\
    \ p = p2 - p1;\n    return std::abs(cross(q, p) + cross(p2, p1)) / std::abs(p);\n\
    }\n\ndouble area(const Vec& A, const Vec& B, const Vec& C) {\n    return std::abs(cross(B\
    \ - A, C - A)) / 2.0;\n}\n\nVec centroid(const Vec& A, const Vec& B, const Vec&\
    \ C) {\n    assert(!are_colinear(A, B, C));\n    return (A + B + C) / 3.0;\n}\n\
    \nVec circumcenter(const Vec& A, const Vec& B, const Vec& C) {\n    assert(!are_colinear(A,\
    \ B, C));\n    double a = std::abs(B - C);\n    double b = std::abs(C - A);\n\
    \    double c = std::abs(A - B);\n    double cosA = (b*b + c*c - a*a) / (2*b*c);\n\
    \    double cosB = (c*c + a*a - b*b) / (2*c*a);\n    double cosC = (a*a + b*b\
    \ - c*c) / (2*a*b);\n    return (a*cosA*A + b*cosB*B + c*cosC*C) / (a*cosA + b*cosB\
    \ + c*cosC);\n}\n\nVec incenter(const Vec& A, const Vec& B, const Vec& C) {\n\
    \    assert(!are_colinear(A, B, C));\n    double a = std::abs(B - C);\n    double\
    \ b = std::abs(C - A);\n    double c = std::abs(A - B);\n    return (a*A + b*B\
    \ + c*C) / (a + b + c);\n}\n\nstd::vector<Vec> convex_hull(std::vector<Vec>& points)\
    \ {\n    int n = points.size();\n    std::sort(points.begin(), points.end(), [](const\
    \ Vec& v1, const Vec& v2) {\n        return (v1.imag() != v2.imag()) ? (v1.imag()\
    \ < v2.imag()) : (v1.real() < v2.real());\n    });\n    int k = 0; // the number\
    \ of vertices in the convex hull\n    std::vector<Vec> ch(2 * n);\n    // right\n\
    \    for (int i = 0; i < n; ++i) {\n        while (k > 1 && lt(cross(ch[k-1] -\
    \ ch[k-2], points[i] - ch[k-1]), 0)) --k;\n        ch[k++] = points[i];\n    }\n\
    \    int t = k;\n    // left\n    for (int i = n - 2; i >= 0; --i) {\n       \
    \ while (k > t && lt(cross(ch[k-1] - ch[k-2], points[i] - ch[k-1]), 0)) --k;\n\
    \        ch[k++] = points[i];\n    }\n    ch.resize(k - 1);\n    return ch;\n\
    }\n#line 4 \"test/aoj/CGL_4_A.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n;\n    cin >> n;\n    vector<Vec> points(n);\n    for (int i = 0; i\
    \ < n; ++i) {\n        double x, y;\n        cin >> x >> y;\n        points[i]\
    \ = {x, y};\n    }\n    auto ans = convex_hull(points);\n    cout << ans.size()\
    \ << endl;\n    for (auto& p : ans) cout << p.real() << \" \" << p.imag() << \"\
    \\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n#include \"../../math/geometry.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int n;\n    cin >> n;\n    vector<Vec> points(n);\n    for (int i = 0; i\
    \ < n; ++i) {\n        double x, y;\n        cin >> x >> y;\n        points[i]\
    \ = {x, y};\n    }\n    auto ans = convex_hull(points);\n    cout << ans.size()\
    \ << endl;\n    for (auto& p : ans) cout << p.real() << \" \" << p.imag() << \"\
    \\n\";\n}\n"
  dependsOn:
  - math/geometry.cpp
  isVerificationFile: true
  path: test/aoj/CGL_4_A.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 01:44:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_4_A.test.cpp
- /verify/test/aoj/CGL_4_A.test.cpp.html
title: test/aoj/CGL_4_A.test.cpp
---
