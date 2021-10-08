---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B
  bundledCode: "#line 1 \"test/aoj/CGL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\
    \n#define ERROR 0.00000001\n\n#line 2 \"math/geometry.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n\
    #include <vector>\n\n// note that if T is of an integer type, std::abs does not\
    \ work\nusing T = double;\nusing Vec = std::complex<T>;\n\nconstexpr T eps = 1e-12;\n\
    inline bool eq(T a, T b) { return std::abs(a - b) < eps; }\ninline bool lt(T a,\
    \ T b) { return a < b - eps; }\ninline bool leq(T a, T b) { return a < b + eps;\
    \ }\n\nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y;\n   \
    \ is >> x >> y;\n    p = {x, y};\n    return is;\n}\n\nT dot(const Vec& a, const\
    \ Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\nT cross(const Vec& a,\
    \ const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nVec rot(const Vec&\
    \ a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n}\n\nVec projection(const\
    \ Vec& a, const Vec& b, const Vec& c) {\n    return a + dot(b - a, c - a) * (b\
    \ - a) / std::norm(b - a);\n}\n\nVec reflection(const Vec& a, const Vec& b, const\
    \ Vec& c) {\n    return T(2) * projection(a, b, c) - c;\n}\n\nint ccw(const Vec&\
    \ a, const Vec& b, const Vec& c) {\n    if (eq(cross(b - a, c - a), 0)) return\
    \ 0;  // collinear\n    if (lt(cross(b - a, c - a), 0)) return -1;  // clockwise\n\
    \    return 1;  // counter clockwise\n}\n\nbool on_segment(const Vec& a, const\
    \ Vec& b, const Vec& c) {\n    Vec u = a - c, v = b - c;\n    return eq(cross(u,\
    \ v), 0) && leq(dot(u, v), 0);\n}\n\nbool intersect_segments(const Vec& a, const\
    \ Vec& b, const Vec& c, const Vec& d) {\n    if (ccw(a, c, d) != ccw(b, c, d)\
    \ && ccw(a, b, c) != ccw(a, b, d)) return true;\n    if (on_segment(a, b, c) ||\
    \ on_segment(c, d, a) || on_segment(c, d, a) || on_segment(c, d, b)) return true;\n\
    \    return false;\n}\n\nT dist_line_point(const Vec& a, const Vec& b, const Vec&\
    \ c) {\n    return std::abs(cross(b - a, c - a)) / std::abs(b - a);\n}\n\nT dist_segment_point(const\
    \ Vec& a, const Vec& b, const Vec& c) {\n    if (lt(dot(b - a, c - a), 0)) return\
    \ std::abs(c - a);\n    if (lt(dot(a - b, c - b), 0)) return std::abs(c - b);\n\
    \    return std::abs(cross(b - a, c - a)) / std::abs(b - a);\n}\n\nT dist_segments(const\
    \ Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n    if (intersect_segments(a,\
    \ b, c, d)) return T(0);\n    return std::min(\n        std::min(dist_segment_point(a,\
    \ b, c), dist_segment_point(a, b, d)),\n        std::min(dist_segment_point(c,\
    \ d, a), dist_segment_point(c, d, b))\n    );\n}\n\nVec intersection_segments(const\
    \ Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n    Vec p = b - a;\n  \
    \  Vec q = d - c;\n    Vec r = c - a;\n    assert(!eq(cross(q, p), 0)); // not\
    \ parallel\n    return a + cross(q, r) / cross(q, p) * p;\n}\n\nstd::vector<Vec>\
    \ intersection_circles(const Vec& c1, T r1, const Vec& c2, T r2) {\n    T d =\
    \ std::abs(c1 - c2);\n    // if the circles are outside of each other\n    if\
    \ (lt(r1 + r2, d)) return {};\n    // if one contains the other entirely\n   \
    \ if (lt(d, std::abs(r2 - r1))) return {};\n    T x = (r1*r1 - r2*r2 + d*d) /\
    \ (2*d);\n    T y = std::sqrt(r1*r1 - x*x);\n    Vec e1 = (c2 - c1) / std::abs(c2\
    \ - c1);\n    Vec e2 = Vec(-e1.imag(), e1.real());\n    return {c1 + x*e1 + y*e2,\
    \ c1 + x*e1 - y*e2};\n}\n\nstd::vector<Vec> intersection_circle_line(const Vec&\
    \ c, T r, const Vec& p1, const Vec& p2) {\n    T d = dist_line_point(p1, p2, c);\n\
    \    // no intersection\n    if (lt(r, d)) return {};\n    Vec e1 = (p2 - p1)\
    \ / std::abs(p2 - p1);\n    Vec e2 = Vec(-e1.imag(), e1.real());\n    T t = std::sqrt(r*r\
    \ - d*d);\n    if (eq(d, 0)) return {c + t*e1, c - t*e1};\n    if (ccw(c, p1,\
    \ p2) == 1) e2 *= -1;\n    if (eq(r, d)) return {c + d*e2};\n    return {c + d*e2\
    \ + t*e1, c + d*e2 - t*e1};\n}\n\nT area(const std::vector<Vec>& pts) {\n    int\
    \ n = pts.size();\n    T res = 0;\n    for (int i = 0; i < n; ++i) {\n       \
    \ res += cross(pts[i], pts[(i + 1) % n]);\n    }\n    return std::abs(res) / T(2);\n\
    }\n\nbool is_convex(const std::vector<Vec>& pts) {\n    int n = pts.size();\n\
    \    for (int i = 0; i < n; ++i) {\n        if (lt(cross(pts[(i+1)%n] - pts[i],\
    \ pts[(i+2)%n] - pts[(i+1)%n]), 0)) {\n            return false;\n        }\n\
    \    }\n    return true;\n}\n\nint contains(const std::vector<Vec>& pts, const\
    \ Vec& q) {\n    int n = pts.size();\n    bool in = 0;\n    for (int i = 0; i\
    \ < n; ++i) {\n        auto a = pts[i] - q, b = pts[(i+1)%n] - q;\n        if\
    \ (eq(cross(a, b), 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0))) return 1;\n \
    \       if (a.imag() > b.imag()) std::swap(a, b);\n        if (leq(a.imag(), 0)\
    \ && lt(0, b.imag()) && lt(cross(a, b), 0)) in ^= 1;\n    }\n    return in ? 2\
    \ : 0;\n}\n\nVec centroid(const Vec& A, const Vec& B, const Vec& C) {\n    assert(ccw(A,\
    \ B, C) != 0);\n    return (A + B + C) / T(3);\n}\n\nVec circumcenter(const Vec&\
    \ A, const Vec& B, const Vec& C) {\n    assert(ccw(A, B, C) != 0);\n    T a =\
    \ std::abs(B - C);\n    T b = std::abs(C - A);\n    T c = std::abs(A - B);\n \
    \   T cosA = (b*b + c*c - a*a) / (2*b*c);\n    T cosB = (c*c + a*a - b*b) / (2*c*a);\n\
    \    T cosC = (a*a + b*b - c*c) / (2*a*b);\n    return (a*cosA*A + b*cosB*B +\
    \ c*cosC*C) / (a*cosA + b*cosB + c*cosC);\n}\n\nVec incenter(const Vec& A, const\
    \ Vec& B, const Vec& C) {\n    assert(ccw(A, B, C) != 0);\n    T a = std::abs(B\
    \ - C);\n    T b = std::abs(C - A);\n    T c = std::abs(A - B);\n    return (a*A\
    \ + b*B + c*C) / (a + b + c);\n}\n\nstd::vector<Vec> convex_hull(std::vector<Vec>&\
    \ pts) {\n    int n = pts.size();\n    std::sort(pts.begin(), pts.end(), [](const\
    \ Vec& v1, const Vec& v2) {\n        return (v1.imag() != v2.imag()) ? (v1.imag()\
    \ < v2.imag()) : (v1.real() < v2.real());\n    });\n    int k = 0; // the number\
    \ of vertices in the convex hull\n    std::vector<Vec> ch(2 * n);\n    // right\n\
    \    for (int i = 0; i < n; ++i) {\n        while (k > 1 && lt(cross(ch[k-1] -\
    \ ch[k-2], pts[i] - ch[k-1]), 0)) --k;\n        ch[k++] = pts[i];\n    }\n   \
    \ int t = k;\n    // left\n    for (int i = n - 2; i >= 0; --i) {\n        while\
    \ (k > t && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]), 0)) --k;\n        ch[k++]\
    \ = pts[i];\n    }\n    ch.resize(k - 1);\n    return ch;\n}\n#line 5 \"test/aoj/CGL_1_B.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    Vec p1,\
    \ p2;\n    cin >> p1 >> p2;\n    int q;\n    cin >> q;\n    while (q--) {\n  \
    \      Vec p;\n        cin >> p;\n        auto q = reflection(p1, p2, p);\n  \
    \      cout << q.real() << \" \" << q.imag() << endl;\n    }\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B\"\
    \n#define ERROR 0.00000001\n\n#include \"../../math/geometry.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    Vec p1,\
    \ p2;\n    cin >> p1 >> p2;\n    int q;\n    cin >> q;\n    while (q--) {\n  \
    \      Vec p;\n        cin >> p;\n        auto q = reflection(p1, p2, p);\n  \
    \      cout << q.real() << \" \" << q.imag() << endl;\n    }\n}\n\n"
  dependsOn:
  - math/geometry.cpp
  isVerificationFile: true
  path: test/aoj/CGL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-10-09 01:30:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_B.test.cpp
- /verify/test/aoj/CGL_1_B.test.cpp.html
title: test/aoj/CGL_1_B.test.cpp
---
