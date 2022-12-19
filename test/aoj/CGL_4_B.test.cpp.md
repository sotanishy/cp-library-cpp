---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/convex_hull.hpp
    title: Convex Hull
  - icon: ':question:'
    path: geometry/geometry.hpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
  bundledCode: "#line 1 \"test/aoj/CGL_4_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\"\
    \n#define ERROR 0.000001\n\n#line 2 \"geometry/geometry.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n\
    #include <vector>\n\n// note that if T is of an integer type, std::abs does not\
    \ work\nusing T = double;\nusing Vec = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\
    \nconstexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return std::abs(a - b)\
    \ <= eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }\n\
    inline bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) {\
    \ return a <= b + eps; }\n\nstd::istream& operator>>(std::istream& is, Vec& p)\
    \ {\n    T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n}\n\nstruct\
    \ Line {\n    Vec p1, p2;\n    Line() = default;\n    Line(const Vec& p1, const\
    \ Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2 - p1; }\n};\n\n\
    struct Segment : Line {\n    using Line::Line;\n};\n\nstruct Circle {\n    Vec\
    \ c;\n    T r;\n    Circle() = default;\n    Circle(const Vec& c, T r) : c(c),\
    \ r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\nT dot(const Vec& a, const\
    \ Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\nT cross(const Vec& a,\
    \ const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nVec rot(const Vec&\
    \ a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n}\n\nVec perp(const\
    \ Vec& a) {\n    return Vec(-a.imag(), a.real());\n}\n\nVec projection(const Line&\
    \ l, const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir()) * l.dir() / std::norm(l.dir());\n\
    }\n\nVec reflection(const Line& l, const Vec& p) {\n    return T(2) * projection(l,\
    \ p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n// -1: clockwise\nint\
    \ ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b - a, c -\
    \ a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0)) return -1;\n    return\
    \ 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n    std::sort(pts.begin(),\
    \ pts.end(), [&](auto& p, auto& q) {\n        if ((p.imag() < 0) != (q.imag()\
    \ < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0) {\n            if\
    \ (p == Vec(0, 0)) return !(q.imag() < 0 || (q.imag() == 0 && q.real() > 0));\n\
    \            if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag() == 0 && p.real()\
    \ > 0));\n            return (p.real() > q.real());\n        }\n        return\
    \ (cross(p, q) > 0);\n    });\n}\n#line 4 \"geometry/convex_hull.hpp\"\n\nstd::vector<Vec>\
    \ convex_hull(std::vector<Vec>& pts) {\n    int n = pts.size();\n    if (n ==\
    \ 1) return pts;\n    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const\
    \ Vec& v2) {\n        return (v1.imag() != v2.imag()) ? (v1.imag() < v2.imag())\
    \ : (v1.real() < v2.real());\n    });\n    int k = 0; // the number of vertices\
    \ in the convex hull\n    std::vector<Vec> ch(2 * n);\n    // right\n    for (int\
    \ i = 0; i < n; ++i) {\n        while (k > 1 && lt(cross(ch[k-1] - ch[k-2], pts[i]\
    \ - ch[k-1]), 0)) --k;\n        ch[k++] = pts[i];\n    }\n    int t = k;\n   \
    \ // left\n    for (int i = n - 2; i >= 0; --i) {\n        while (k > t && lt(cross(ch[k-1]\
    \ - ch[k-2], pts[i] - ch[k-1]), 0)) --k;\n        ch[k++] = pts[i];\n    }\n \
    \   ch.resize(k - 1);\n    return ch;\n}\n\n#line 6 \"test/aoj/CGL_4_B.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int n;\n\
    \    cin >> n;\n    vector<Vec> pts(n);\n    for (auto& x : pts) cin >> x;\n \
    \   auto ch = convex_hull(pts);\n    int j = 0;\n    T ans = 0;\n    for (int\
    \ i = 0; i < n; ++i) {\n        j = max(i, j);\n        while (lt(abs(ch[i]-ch[j%n]),\
    \ abs(ch[i]-ch[(j+1)%n]))) ++j;\n        ans = max(ans, abs(ch[j%n] - ch[i]));\n\
    \    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B\"\
    \n#define ERROR 0.000001\n\n#include \"../../geometry/geometry.hpp\"\n#include\
    \ \"../../geometry/convex_hull.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    cout << fixed << setprecision(15);\n\n    int n;\n    cin >> n;\n    vector<Vec>\
    \ pts(n);\n    for (auto& x : pts) cin >> x;\n    auto ch = convex_hull(pts);\n\
    \    int j = 0;\n    T ans = 0;\n    for (int i = 0; i < n; ++i) {\n        j\
    \ = max(i, j);\n        while (lt(abs(ch[i]-ch[j%n]), abs(ch[i]-ch[(j+1)%n])))\
    \ ++j;\n        ans = max(ans, abs(ch[j%n] - ch[i]));\n    }\n    cout << ans\
    \ << endl;\n}"
  dependsOn:
  - geometry/geometry.hpp
  - geometry/convex_hull.hpp
  isVerificationFile: true
  path: test/aoj/CGL_4_B.test.cpp
  requiredBy: []
  timestamp: '2022-12-19 16:08:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_4_B.test.cpp
- /verify/test/aoj/CGL_4_B.test.cpp.html
title: test/aoj/CGL_4_B.test.cpp
---
