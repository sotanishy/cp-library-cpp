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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
  bundledCode: "#line 1 \"test/aoj/CGL_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#line 2 \"math/geometry.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <complex>\n#include <iostream>\n#include <vector>\n\
    \nnamespace geometry {\n\n// note that if T is of an integer type, std::abs does\
    \ not work\nusing T = double;\nusing Vec = std::complex<T>;\n\nconstexpr T eps\
    \ = 1e-12;\ninline bool eq(T a, T b) { return std::abs(a - b) < eps; }\ninline\
    \ bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) { return\
    \ a < b + eps; }\n\nstd::istream& operator>>(std::istream& is, Vec& p) {\n   \
    \ T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n}\n\nT dot(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\nT cross(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nVec rot(const\
    \ Vec& a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n}\n\nbool\
    \ are_colinear(const Vec& a, const Vec& b, const Vec& c) {\n    return eq(cross(b\
    \ - a, c - a), 0);\n}\n\nbool ccw(const Vec& a, const Vec& b, const Vec& c) {\n\
    \    return lt(-cross(b - a, c - a), 0);\n}\n\nbool intersect(const Vec& a, const\
    \ Vec& b, const Vec& c, const Vec& d) {\n    return ccw(a, c, d) != ccw(b, c,\
    \ d) && ccw(a, b, c) != ccw(a, b, d);\n}\n\nbool on_segment(const Vec& a, const\
    \ Vec& b, const Vec& p) {\n    Vec u = a - p, v = b - p;\n    return eq(cross(u,\
    \ v), 0) && lt(dot(u, v), 0);\n}\n\nT line_point_dist(const Vec& a, const Vec&\
    \ b, const Vec& p) {\n    const T l2 = std::norm(b - a);\n    const T t = dot(p\
    \ - a, b - a) / l2;\n    const Vec q = a + t * (b - a);\n    return std::abs(p\
    \ - q);\n}\n\nT segment_point_distance(const Vec& a, const Vec& b, const Vec&\
    \ p) {\n    const T l2 = std::norm(b - a);\n    const T t = std::max(T(0), std::min(T(1),\
    \ dot(p - a, b - a) / l2));\n    const Vec q = a + t * (b - a);\n    return std::abs(p\
    \ - q);\n}\n\nVec intersection(const Vec& a, const Vec& b, const Vec& c, const\
    \ Vec& d) {\n    Vec p = b - a;\n    Vec q = d - c;\n    Vec r = c - a;\n    assert(!eq(cross(q,\
    \ p), 0)); // not parallel\n    return a + cross(q, r) / cross(q, p) * p;\n}\n\
    \nstd::vector<Vec> intersection_circles(const Vec& c1, T r1, const Vec& c2, T\
    \ r2) {\n    T d = std::abs(c1 - c2);\n    // if the circles are outside of each\
    \ other\n    if (lt(r1 + r2, d)) return {};\n    // if one contains the other\
    \ entirely\n    if (lt(d, std::abs(r2 - r1))) return {};\n    T x = (r1*r1 - r2*r2\
    \ + d*d) / (2*d);\n    T y = std::sqrt(r1*r1 - x*x);\n    Vec e1 = (c2 - c1) /\
    \ std::abs(c2 - c1);\n    Vec e2 = Vec(-e1.imag(), e1.real());\n    return {c1\
    \ + x*e1 + y*e2, c1 + x*e1 - y*e2};\n}\n\nstd::vector<Vec> intersection_circle_line(const\
    \ Vec& c, T r, const Vec& p1, const Vec& p2) {\n    T d = line_point_dist(p1,\
    \ p2, c);\n    // no intersection\n    if (lt(r, d)) return {};\n    Vec e1 =\
    \ (p2 - p1) / std::abs(p2 - p1);\n    Vec e2 = Vec(-e1.imag(), e1.real());\n \
    \   T t = std::sqrt(r*r - d*d);\n    if (eq(d, 0)) return {c + t*e1, c - t*e1};\n\
    \    if (ccw(c, p1, p2)) e2 *= -1;\n    if (eq(r, d)) return {c + d*e2};\n   \
    \ return {c + d*e2 + t*e1, c + d*e2 - t*e1};\n}\n\nT area(const Vec& A, const\
    \ Vec& B, const Vec& C) {\n    return std::abs(cross(B - A, C - A)) / T(2);\n\
    }\n\nVec centroid(const Vec& A, const Vec& B, const Vec& C) {\n    assert(!are_colinear(A,\
    \ B, C));\n    return (A + B + C) / T(3);\n}\n\nVec circumcenter(const Vec& A,\
    \ const Vec& B, const Vec& C) {\n    assert(!are_colinear(A, B, C));\n    T a\
    \ = std::abs(B - C);\n    T b = std::abs(C - A);\n    T c = std::abs(A - B);\n\
    \    T cosA = (b*b + c*c - a*a) / (2*b*c);\n    T cosB = (c*c + a*a - b*b) / (2*c*a);\n\
    \    T cosC = (a*a + b*b - c*c) / (2*a*b);\n    return (a*cosA*A + b*cosB*B +\
    \ c*cosC*C) / (a*cosA + b*cosB + c*cosC);\n}\n\nVec incenter(const Vec& A, const\
    \ Vec& B, const Vec& C) {\n    assert(!are_colinear(A, B, C));\n    T a = std::abs(B\
    \ - C);\n    T b = std::abs(C - A);\n    T c = std::abs(A - B);\n    return (a*A\
    \ + b*B + c*C) / (a + b + c);\n}\n\nstd::vector<Vec> convex_hull(std::vector<Vec>&\
    \ points) {\n    int n = points.size();\n    std::sort(points.begin(), points.end(),\
    \ [](const Vec& v1, const Vec& v2) {\n        return (v1.imag() != v2.imag())\
    \ ? (v1.imag() < v2.imag()) : (v1.real() < v2.real());\n    });\n    int k = 0;\
    \ // the number of vertices in the convex hull\n    std::vector<Vec> ch(2 * n);\n\
    \    // right\n    for (int i = 0; i < n; ++i) {\n        while (k > 1 && lt(cross(ch[k-1]\
    \ - ch[k-2], points[i] - ch[k-1]), 0)) --k;\n        ch[k++] = points[i];\n  \
    \  }\n    int t = k;\n    // left\n    for (int i = n - 2; i >= 0; --i) {\n  \
    \      while (k > t && lt(cross(ch[k-1] - ch[k-2], points[i] - ch[k-1]), 0)) --k;\n\
    \        ch[k++] = points[i];\n    }\n    ch.resize(k - 1);\n    return ch;\n\
    }\n\n} // namespace geometry\n#line 4 \"test/aoj/CGL_1_C.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing namespace geometry;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    Vec p0,\
    \ p1;\n    cin >> p0 >> p1;\n    int q;\n    cin >> q;\n    while (q--) {\n  \
    \      Vec p2;\n        cin >> p2;\n        if (p0 == p2 || p1 == p2 || on_segment(p0,\
    \ p1, p2)) cout << \"ON_SEGMENT\\n\";\n        else if (on_segment(p1, p2, p0))\
    \ cout << \"ONLINE_BACK\\n\";\n        else if (on_segment(p2, p0, p1)) cout <<\
    \ \"ONLINE_FRONT\\n\";\n        else if (ccw(p0, p1, p2)) cout << \"COUNTER_CLOCKWISE\\\
    n\";\n        else cout << \"CLOCKWISE\\n\";\n    }\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n\n#include \"../../math/geometry.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing namespace geometry;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    Vec p0, p1;\n    cin >> p0 >> p1;\n    int q;\n\
    \    cin >> q;\n    while (q--) {\n        Vec p2;\n        cin >> p2;\n     \
    \   if (p0 == p2 || p1 == p2 || on_segment(p0, p1, p2)) cout << \"ON_SEGMENT\\\
    n\";\n        else if (on_segment(p1, p2, p0)) cout << \"ONLINE_BACK\\n\";\n \
    \       else if (on_segment(p2, p0, p1)) cout << \"ONLINE_FRONT\\n\";\n      \
    \  else if (ccw(p0, p1, p2)) cout << \"COUNTER_CLOCKWISE\\n\";\n        else cout\
    \ << \"CLOCKWISE\\n\";\n    }\n}\n\n"
  dependsOn:
  - math/geometry.cpp
  isVerificationFile: true
  path: test/aoj/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '2021-10-07 13:13:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_C.test.cpp
- /verify/test/aoj/CGL_1_C.test.cpp.html
title: test/aoj/CGL_1_C.test.cpp
---
