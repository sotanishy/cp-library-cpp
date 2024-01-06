---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geometry/dist.hpp
    title: geometry/dist.hpp
  - icon: ':x:'
    path: geometry/geometry.hpp
    title: Geometry
  - icon: ':x:'
    path: geometry/intersect.hpp
    title: geometry/intersect.hpp
  - icon: ':x:'
    path: geometry/intersection.hpp
    title: geometry/intersection.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E
  bundledCode: "#line 1 \"test/aoj/CGL_7_E.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\"\
    \n#define ERROR 0.00000001\n\n#line 2 \"geometry/geometry.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n\
    #include <vector>\n#include<numbers>\n\n// note that if T is of an integer type,\
    \ std::abs does not work\nusing T = double;\nusing Vec = std::complex<T>;\n\n\
    std::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y;\n    is >> x\
    \ >> y;\n    p = {x, y};\n    return is;\n}\n\nT dot(const Vec& a, const Vec&\
    \ b) { return (std::conj(a) * b).real(); }\n\nT cross(const Vec& a, const Vec&\
    \ b) { return (std::conj(a) * b).imag(); }\n\nconstexpr T PI = std::numbers::pi;\n\
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
    \    std::sort(pts.begin(), pts.end(), [&](auto& p, auto& q) {\n        if ((p.imag()\
    \ < 0) != (q.imag() < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0)\
    \ {\n            if (p == Vec(0, 0))\n                return !(q.imag() < 0 ||\
    \ (q.imag() == 0 && q.real() > 0));\n            if (q == Vec(0, 0))\n       \
    \         return (p.imag() < 0 || (p.imag() == 0 && p.real() > 0));\n        \
    \    return (p.real() > q.real());\n        }\n        return (cross(p, q) > 0);\n\
    \    });\n}\n#line 3 \"geometry/intersect.hpp\"\n\nbool intersect(const Segment&\
    \ s, const Vec& p) {\n    Vec u = s.p1 - p, v = s.p2 - p;\n    return eq(cross(u,\
    \ v), 0) && leq(dot(u, v), 0);\n}\n\n// 0: outside\n// 1: on the border\n// 2:\
    \ inside\nint intersect(const Polygon& poly, const Vec& p) {\n    const int n\
    \ = poly.size();\n    bool in = 0;\n    for (int i = 0; i < n; ++i) {\n      \
    \  auto a = poly[i] - p, b = poly[(i + 1) % n] - p;\n        if (eq(cross(a, b),\
    \ 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0)))\n            return 1;\n     \
    \   if (a.imag() > b.imag()) std::swap(a, b);\n        if (leq(a.imag(), 0) &&\
    \ lt(0, b.imag()) && lt(cross(a, b), 0)) in ^= 1;\n    }\n    return in ? 2 :\
    \ 0;\n}\n\nint intersect(const Segment& s, const Segment& t) {\n    auto a = s.p1,\
    \ b = s.p2;\n    auto c = t.p1, d = t.p2;\n    if (ccw(a, b, c) != ccw(a, b, d)\
    \ && ccw(c, d, a) != ccw(c, d, b)) return 2;\n    if (intersect(s, c) || intersect(s,\
    \ d) || intersect(t, a) ||\n        intersect(t, b))\n        return 1;\n    return\
    \ 0;\n}\n\n// true if they have positive area in common or touch on the border\n\
    bool intersect(const Polygon& poly1, const Polygon& poly2) {\n    const int n\
    \ = poly1.size();\n    const int m = poly2.size();\n    for (int i = 0; i < n;\
    \ ++i) {\n        for (int j = 0; j < m; ++j) {\n            if (intersect(Segment(poly1[i],\
    \ poly1[(i + 1) % n]),\n                          Segment(poly2[j], poly2[(j +\
    \ 1) % m]))) {\n                return true;\n            }\n        }\n    }\n\
    \    return intersect(poly1, poly2[0]) || intersect(poly2, poly1[0]);\n}\n\n//\
    \ 0: inside\n// 1: inscribe\n// 2: intersect\n// 3: circumscribe\n// 4: outside\n\
    int intersect(const Circle& c1, const Circle& c2) {\n    T d = std::abs(c1.c -\
    \ c2.c);\n    if (lt(d, std::abs(c2.r - c1.r))) return 0;\n    if (eq(d, std::abs(c2.r\
    \ - c1.r))) return 1;\n    if (eq(c1.r + c2.r, d)) return 3;\n    if (lt(c1.r\
    \ + c2.r, d)) return 4;\n    return 2;\n}\n#line 4 \"geometry/dist.hpp\"\n\nT\
    \ dist(const Line& l, const Vec& p) {\n    return std::abs(cross(p - l.p1, l.dir()))\
    \ / std::abs(l.dir());\n}\n\nT dist(const Segment& s, const Vec& p) {\n    if\
    \ (lt(dot(p - s.p1, s.dir()), 0)) return std::abs(p - s.p1);\n    if (lt(dot(p\
    \ - s.p2, -s.dir()), 0)) return std::abs(p - s.p2);\n    return std::abs(cross(p\
    \ - s.p1, s.dir())) / std::abs(s.dir());\n}\n\nT dist(const Segment& s, const\
    \ Segment& t) {\n    if (intersect(s, t)) return T(0);\n    return std::min({dist(s,\
    \ t.p1), dist(s, t.p2), dist(t, s.p1), dist(t, s.p2)});\n}\n#line 4 \"geometry/intersection.hpp\"\
    \n\nVec intersection(const Line& l, const Line& m) {\n    assert(!eq(cross(l.dir(),\
    \ m.dir()), 0));  // not parallel\n    Vec r = m.p1 - l.p1;\n    return l.p1 +\
    \ cross(m.dir(), r) / cross(m.dir(), l.dir()) * l.dir();\n}\n\nstd::vector<Vec>\
    \ intersection(const Circle& c, const Line& l) {\n    T d = dist(l, c.c);\n  \
    \  if (lt(c.r, d)) return {};  // no intersection\n    Vec e1 = l.dir() / std::abs(l.dir());\n\
    \    Vec e2 = perp(e1);\n    if (ccw(c.c, l.p1, l.p2) == 1) e2 *= -1;\n    if\
    \ (eq(c.r, d)) return {c.c + d * e2};  // tangent\n    T t = std::sqrt(c.r * c.r\
    \ - d * d);\n    return {c.c + d * e2 + t * e1, c.c + d * e2 - t * e1};\n}\n\n\
    std::vector<Vec> intersection(const Circle& c1, const Circle& c2) {\n    T d =\
    \ std::abs(c1.c - c2.c);\n    if (lt(c1.r + c2.r, d)) return {};  // outside\n\
    \    Vec e1 = (c2.c - c1.c) / std::abs(c2.c - c1.c);\n    Vec e2 = perp(e1);\n\
    \    if (lt(d, std::abs(c2.r - c1.r))) return {};                  // contain\n\
    \    if (eq(d, std::abs(c2.r - c1.r))) return {c1.c + c1.r * e1};  // tangent\n\
    \    T x = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d);\n    T y = std::sqrt(c1.r\
    \ * c1.r - x * x);\n    return {c1.c + x * e1 + y * e2, c1.c + x * e1 - y * e2};\n\
    }\n\nT area_intersection(const Circle& c1, const Circle& c2) {\n    T d = std::abs(c2.c\
    \ - c1.c);\n    if (leq(c1.r + c2.r, d)) return 0;    // outside\n    if (leq(d,\
    \ std::abs(c2.r - c1.r))) {  // inside\n        T r = std::min(c1.r, c2.r);\n\
    \        return PI * r * r;\n    }\n    T ans = 0;\n    T a;\n    a = std::acos((c1.r\
    \ * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));\n    ans += c1.r * c1.r * (a\
    \ - std::sin(a) * std::cos(a));\n    a = std::acos((c2.r * c2.r + d * d - c1.r\
    \ * c1.r) / (2 * c2.r * d));\n    ans += c2.r * c2.r * (a - std::sin(a) * std::cos(a));\n\
    \    return ans;\n}\n#line 6 \"test/aoj/CGL_7_E.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(10);\n\n    Vec p1,\
    \ p2;\n    double r1, r2;\n    cin >> p1 >> r1;\n    cin >> p2 >> r2;\n    auto\
    \ ans = intersection(Circle(p1, r1), Circle(p2, r2));\n    if (ans.size() == 1)\
    \ {\n        cout << ans[0].real() << \" \" << ans[0].imag() << \" \";\n     \
    \   cout << ans[0].real() << \" \" << ans[0].imag() << \"\\n\";\n    } else {\n\
    \        if (make_pair(ans[0].real(), ans[0].imag()) > make_pair(ans[1].real(),\
    \ ans[1].real())) swap(ans[0], ans[1]);\n        cout << ans[0].real() << \" \"\
    \ << ans[0].imag() << \" \";\n        cout << ans[1].real() << \" \" << ans[1].imag()\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E\"\
    \n#define ERROR 0.00000001\n\n#include \"../../geometry/geometry.hpp\"\n#include\
    \ \"../../geometry/intersection.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    cout << fixed << setprecision(10);\n\n    Vec p1, p2;\n    double r1, r2;\n\
    \    cin >> p1 >> r1;\n    cin >> p2 >> r2;\n    auto ans = intersection(Circle(p1,\
    \ r1), Circle(p2, r2));\n    if (ans.size() == 1) {\n        cout << ans[0].real()\
    \ << \" \" << ans[0].imag() << \" \";\n        cout << ans[0].real() << \" \"\
    \ << ans[0].imag() << \"\\n\";\n    } else {\n        if (make_pair(ans[0].real(),\
    \ ans[0].imag()) > make_pair(ans[1].real(), ans[1].real())) swap(ans[0], ans[1]);\n\
    \        cout << ans[0].real() << \" \" << ans[0].imag() << \" \";\n        cout\
    \ << ans[1].real() << \" \" << ans[1].imag() << \"\\n\";\n    }\n}"
  dependsOn:
  - geometry/geometry.hpp
  - geometry/intersection.hpp
  - geometry/dist.hpp
  - geometry/intersect.hpp
  isVerificationFile: true
  path: test/aoj/CGL_7_E.test.cpp
  requiredBy: []
  timestamp: '2024-01-06 20:26:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_7_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_E.test.cpp
- /verify/test/aoj/CGL_7_E.test.cpp.html
title: test/aoj/CGL_7_E.test.cpp
---
