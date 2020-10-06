---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/geometry.cpp\"\n#include <bits/stdc++.h>\n\nconstexpr\
    \ double eps = 1e-12;\n\ninline bool eq(double a, double b) { return std::abs(a\
    \ - b) < eps; }\ninline bool lt(double a, double b) { return a < b - eps; }\n\
    inline bool leq(double a, double b) { return a < b + eps; }\n\nstruct Vec {\n\
    \    double x, y;\n\n    Vec() = default;\n    Vec(double x, double y) : x(x),\
    \ y(y) {}\n\n    Vec operator+(const Vec& other) const { return Vec(x + other.x,\
    \ y + other.y); }\n    Vec operator-(const Vec& other) const { return Vec(x -\
    \ other.x, y - other.y); }\n    Vec operator*(double k) const { return Vec(x *\
    \ k, y * k); }\n    Vec operator/(double k) const { return Vec(x / k, y / k);\
    \ }\n\n    double abs() const { return std::sqrt(x * x + y * y); }\n    double\
    \ dot(const Vec& other) const { return x * other.x + y * other.y; }\n    double\
    \ cross(const Vec& other) const { return x * other.y - y * other.x; }\n\n    Vec\
    \ rot(double ang) const {\n        double c = std::cos(ang), s = std::sin(ang);\n\
    \        return Vec(c * x - s * y, s * x + c * y);\n    }\n};\n\n// checks if\
    \ the three points are on the same line\nbool are_colinear(const Vec& p1, const\
    \ Vec& p2, const Vec& p3) {\n    return eq((p2 - p1).cross(p3 - p1), 0);\n}\n\n\
    // returns true if the segment ab intersects with the segment cd\nbool intersect(const\
    \ Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n    double ta = (c - d).cross(a\
    \ - c);\n    double tb = (c - d).cross(b - a);\n    double tc = (a - b).cross(c\
    \ - a);\n    double td = (a - b).cross(d - a);\n    return lt(ta * tb, 0) && lt(tc\
    \ * td, 0);\n}\n\n// checks if q is on the segment p1-p2\nbool on_segment(const\
    \ Vec& p1, const Vec& p2, const Vec& q) {\n    Vec v1 = p1 - q, v2 = p2 - q;\n\
    \    return eq(v1.cross(v2), 0) && eq(v1.dot(v2), 0);\n}\n\n// returns the intersection\
    \ of the lines p1-p2 and q1-q2\n// if the lines are parallel, returns nullopt\n\
    std::optional<Vec> intersection(const Vec& p1, const Vec& p2, const Vec& q1, const\
    \ Vec& q2) {\n    Vec p = p2 - p1;\n    Vec q = q2 - q1;\n    Vec r = q1 - p1;\n\
    \    // if parallel\n    if (eq(q.cross(p), 0)) return std::nullopt;\n    return\
    \ p1 + p * (q.cross(r) / q.cross(p));\n}\n\n// returns a list of the intersections\
    \ of two circles\nstd::vector<Vec> intersection_circles(const Vec& c1, double\
    \ r1, const Vec& c2, double r2) {\n    double d = (c1 - c2).abs();\n    // if\
    \ the circles are outside of each other\n    if (lt(r1 + r2, d)) return {};\n\
    \    // if one contains the other entirely\n    if (lt(d, std::abs(r2 - r1)))\
    \ return {};\n    double x = (r1*r1 - r2*r2 + d*d) / (2*d);\n    double y = std::sqrt(r1*r1\
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
    \    return (A*a + B*b + C*c) / (a + b + c);\n}\n\nstd::vector<Vec> convex_hull(const\
    \ std::vector<Vec>& points) {\n    int n = points.size();\n    std::sort(points.begin(),\
    \ points.end(), [](const Vec& v1, const Vec& v2) {\n        return std::make_pair(v1.x,\
    \ v1.y) < std::make_pair(v2.x, v2.y);\n    });\n    int k = 0; // the number of\
    \ vertices in the convex hull\n    std::vector<Vec> ch(2 * n);\n    // bottom\n\
    \    for (int i = 0; i < n; ++i) {\n        while (k > 1 && leq((ch[k-1] - ch[k-2]).cross(points[i]\
    \ - ch[k-1]), 0)) --k;\n        ch[k] = points[i];\n        ++k;\n    }\n    int\
    \ t = k;\n    // top\n    for (int i = n - 1; i >= 0; --i) {\n        while (k\
    \ > t && leq((ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]), 0)) --k;\n      \
    \  ch[k] = points[i];\n        ++k;\n    }\n    return std::vector<Vec>(ch.begin(),\
    \ ch.begin() + (k - 1));\n}\n"
  code: "#include <bits/stdc++.h>\n\nconstexpr double eps = 1e-12;\n\ninline bool\
    \ eq(double a, double b) { return std::abs(a - b) < eps; }\ninline bool lt(double\
    \ a, double b) { return a < b - eps; }\ninline bool leq(double a, double b) {\
    \ return a < b + eps; }\n\nstruct Vec {\n    double x, y;\n\n    Vec() = default;\n\
    \    Vec(double x, double y) : x(x), y(y) {}\n\n    Vec operator+(const Vec& other)\
    \ const { return Vec(x + other.x, y + other.y); }\n    Vec operator-(const Vec&\
    \ other) const { return Vec(x - other.x, y - other.y); }\n    Vec operator*(double\
    \ k) const { return Vec(x * k, y * k); }\n    Vec operator/(double k) const {\
    \ return Vec(x / k, y / k); }\n\n    double abs() const { return std::sqrt(x *\
    \ x + y * y); }\n    double dot(const Vec& other) const { return x * other.x +\
    \ y * other.y; }\n    double cross(const Vec& other) const { return x * other.y\
    \ - y * other.x; }\n\n    Vec rot(double ang) const {\n        double c = std::cos(ang),\
    \ s = std::sin(ang);\n        return Vec(c * x - s * y, s * x + c * y);\n    }\n\
    };\n\n// checks if the three points are on the same line\nbool are_colinear(const\
    \ Vec& p1, const Vec& p2, const Vec& p3) {\n    return eq((p2 - p1).cross(p3 -\
    \ p1), 0);\n}\n\n// returns true if the segment ab intersects with the segment\
    \ cd\nbool intersect(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n\
    \    double ta = (c - d).cross(a - c);\n    double tb = (c - d).cross(b - a);\n\
    \    double tc = (a - b).cross(c - a);\n    double td = (a - b).cross(d - a);\n\
    \    return lt(ta * tb, 0) && lt(tc * td, 0);\n}\n\n// checks if q is on the segment\
    \ p1-p2\nbool on_segment(const Vec& p1, const Vec& p2, const Vec& q) {\n    Vec\
    \ v1 = p1 - q, v2 = p2 - q;\n    return eq(v1.cross(v2), 0) && eq(v1.dot(v2),\
    \ 0);\n}\n\n// returns the intersection of the lines p1-p2 and q1-q2\n// if the\
    \ lines are parallel, returns nullopt\nstd::optional<Vec> intersection(const Vec&\
    \ p1, const Vec& p2, const Vec& q1, const Vec& q2) {\n    Vec p = p2 - p1;\n \
    \   Vec q = q2 - q1;\n    Vec r = q1 - p1;\n    // if parallel\n    if (eq(q.cross(p),\
    \ 0)) return std::nullopt;\n    return p1 + p * (q.cross(r) / q.cross(p));\n}\n\
    \n// returns a list of the intersections of two circles\nstd::vector<Vec> intersection_circles(const\
    \ Vec& c1, double r1, const Vec& c2, double r2) {\n    double d = (c1 - c2).abs();\n\
    \    // if the circles are outside of each other\n    if (lt(r1 + r2, d)) return\
    \ {};\n    // if one contains the other entirely\n    if (lt(d, std::abs(r2 -\
    \ r1))) return {};\n    double x = (r1*r1 - r2*r2 + d*d) / (2*d);\n    double\
    \ y = std::sqrt(r1*r1 - x*x);\n    Vec e1 = (c2 - c1) / (c2 - c1).abs();\n   \
    \ Vec e2 = Vec(-e1.y, e1.x);\n    Vec p1 = c1 + e1 * x + e2 * y;\n    Vec p2 =\
    \ c1 + e1 * x - e2 * y;\n    return {p1, p2};\n}\n\n// returns the distance between\
    \ the point q and the line p1-p2\ndouble point_line_dist(const Vec& p1, const\
    \ Vec& p2, const Vec& q) {\n    Vec p = p2 - p1;\n    return std::abs(q.cross(p)\
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
    \    return (A*a + B*b + C*c) / (a + b + c);\n}\n\nstd::vector<Vec> convex_hull(const\
    \ std::vector<Vec>& points) {\n    int n = points.size();\n    std::sort(points.begin(),\
    \ points.end(), [](const Vec& v1, const Vec& v2) {\n        return std::make_pair(v1.x,\
    \ v1.y) < std::make_pair(v2.x, v2.y);\n    });\n    int k = 0; // the number of\
    \ vertices in the convex hull\n    std::vector<Vec> ch(2 * n);\n    // bottom\n\
    \    for (int i = 0; i < n; ++i) {\n        while (k > 1 && leq((ch[k-1] - ch[k-2]).cross(points[i]\
    \ - ch[k-1]), 0)) --k;\n        ch[k] = points[i];\n        ++k;\n    }\n    int\
    \ t = k;\n    // top\n    for (int i = n - 1; i >= 0; --i) {\n        while (k\
    \ > t && leq((ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]), 0)) --k;\n      \
    \  ch[k] = points[i];\n        ++k;\n    }\n    return std::vector<Vec>(ch.begin(),\
    \ ch.begin() + (k - 1));\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/geometry.cpp
  requiredBy: []
  timestamp: '2020-10-06 11:51:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/geometry.cpp
layout: document
redirect_from:
- /library/math/geometry.cpp
- /library/math/geometry.cpp.html
title: math/geometry.cpp
---
