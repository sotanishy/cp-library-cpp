---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/geometry.cpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A
  bundledCode: "#line 1 \"test/aoj/CGL_5_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\"\
    \n#define ERROR 0.000001\n\n#line 2 \"geometry/geometry.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n\
    #include <vector>\n\n// note that if T is of an integer type, std::abs does not\
    \ work\nusing T = double;\nusing Vec = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\
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
    \ && lt(cross(a, b), 0)) in ^= 1;\n    }\n    return in ? 2 : 0;\n}\n\n// 0: not\
    \ intersect\n// 1: intersect at an end\n// 2: intersect\nint intersect(const Segment&\
    \ s, const Segment& t) {\n    auto a = s.p1, b = s.p2;\n    auto c = t.p1, d =\
    \ t.p2;\n    auto u = ccw(a, b, c) * ccw(a, b, d);\n    auto v = ccw(c, d, a)\
    \ * ccw(c, d, b);\n    if (u == 0 || v == 0) return 1;\n    if (u == -1 && v ==\
    \ -1) return 2;\n    return 0;\n}\n\n// 0: inside\n// 1: inscribe\n// 2: intersect\n\
    // 3: circumscribe\n// 4: outside\nint intersect(const Circle& c1, const Circle&\
    \ c2) {\n    T d = std::abs(c1.c - c2.c);\n    if (lt(d, std::abs(c2.r - c1.r)))\
    \ return 0;\n    if (eq(d, std::abs(c2.r - c1.r))) return 1;\n    if (eq(c1.r\
    \ + c2.r, d)) return 3;\n    if (lt(c1.r + c2.r, d)) return 4;\n    return 2;\n\
    }\n\nT dist(const Line& l, const Vec& p) {\n    return std::abs(cross(p - l.p1,\
    \ l.dir())) / std::abs(l.dir());\n}\n\nT dist(const Segment& s, const Vec& p)\
    \ {\n    if (lt(dot(p - s.p1, s.dir()), 0)) return std::abs(p - s.p1);\n    if\
    \ (lt(dot(p - s.p2, -s.dir()), 0)) return std::abs(p - s.p2);\n    return std::abs(cross(p\
    \ - s.p1, s.dir())) / std::abs(s.dir());\n}\n\nT dist(const Segment& s, const\
    \ Segment& t) {\n    if (intersect(s, t)) return T(0);\n    return std::min(\n\
    \        std::min(dist(s, t.p1), dist(s, t.p2)),\n        std::min(dist(t, s.p1),\
    \ dist(t, s.p2))\n    );\n}\n\nVec intersection(const Line& l, const Line& m)\
    \ {\n    Vec r = m.p1 - l.p1;\n    assert(!eq(cross(l.dir(), m.dir()), 0)); //\
    \ not parallel\n    return l.p1 + cross(m.dir(), r) / cross(m.dir(), l.dir())\
    \ * l.dir();\n}\n\nstd::vector<Vec> intersection(const Circle& c, const Line&\
    \ l) {\n    T d = dist(l, c.c);\n    if (lt(c.r, d)) return {};  // no intersection\n\
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
    \ poly[(i + 1) % n]);\n    }\n    return std::abs(res) / T(2);\n}\n\nT area_intersection_circles(const\
    \ Circle& c1, const Circle& c2) {\n    T d = std::abs(c2.c - c1.c);\n    if (leq(c1.r\
    \ + c2.r, d)) return 0;  // outside\n    if (leq(d, std::abs(c2.r - c1.r))) {\
    \  // contain\n        T r = std::min(c1.r, c2.r);\n        return PI * r * r;\n\
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
    \ q);\n//     return (a*A + b*B + c*C) / (a + b + c);\n// }\n\nstd::vector<Vec>\
    \ convex_hull(std::vector<Vec>& pts) {\n    int n = pts.size();\n    std::sort(pts.begin(),\
    \ pts.end(), [](const Vec& v1, const Vec& v2) {\n        return (v1.imag() !=\
    \ v2.imag()) ? (v1.imag() < v2.imag()) : (v1.real() < v2.real());\n    });\n \
    \   int k = 0; // the number of vertices in the convex hull\n    std::vector<Vec>\
    \ ch(2 * n);\n    // right\n    for (int i = 0; i < n; ++i) {\n        while (k\
    \ > 1 && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]), 0)) --k;\n        ch[k++]\
    \ = pts[i];\n    }\n    int t = k;\n    // left\n    for (int i = n - 2; i >=\
    \ 0; --i) {\n        while (k > t && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]),\
    \ 0)) --k;\n        ch[k++] = pts[i];\n    }\n    ch.resize(k - 1);\n    return\
    \ ch;\n}\n\nT closest_pair(std::vector<Vec>& pts) {\n    std::sort(pts.begin(),\
    \ pts.end(), [](const Vec& v1, const Vec& v2) {\n        return v1.real() < v2.real();\n\
    \    });\n\n    auto rec = [&](const auto& rec, int l, int r) -> T {\n       \
    \ if (r - l <= 1) return std::numeric_limits<T>::max();\n        int m = (l +\
    \ r) / 2;\n        T x = pts[m].real();\n        T d = std::min(rec(rec, l, m),\
    \ rec(rec, m, r));\n        std::inplace_merge(pts.begin() + l, pts.begin() +\
    \ m, pts.begin() + r, [&](const Vec& v1, const Vec& v2) {\n            return\
    \ v1.imag() < v2.imag();\n        });\n        std::vector<Vec> b;\n        for\
    \ (int i = l; i < r; ++i) {\n            if (leq(d, std::abs(pts[i].real() - x)))\
    \ continue;\n            for (int j = (int) b.size() - 1; j >= 0; --j) {\n   \
    \             if (leq(d, std::abs(pts[i].imag() - b[j].imag()))) break;\n    \
    \            d = std::min(d, std::abs(pts[i] - b[j]));\n            }\n      \
    \      b.push_back(pts[i]);\n        }\n        return d;\n    };\n\n    return\
    \ rec(rec, 0, pts.size());\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n \
    \   std::sort(pts.begin(), pts.end(), [&](auto& p, auto& q) {\n        if ((p.imag()\
    \ < 0) != (q.imag() < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0)\
    \ {\n            if (p == Vec(0, 0)) return !(q.imag() < 0 || (q.imag() == 0 &&\
    \ q.real() > 0));\n            if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag()\
    \ == 0 && p.real() > 0));\n            return (p.real() > q.real());\n       \
    \ }\n        return (cross(p, q) > 0);\n    });\n}\n\n/*\n// for 3d geometry\n\
    // functions that will work without any modifications\n// projection, reflection,\
    \ dist_line_point, dist_segment_point, dist_segments,\n// centroid, incenter\n\
    \nstruct Vec {\n    T x, y, z;\n    Vec() = default;\n    constexpr Vec(T x, T\
    \ y, T z) : x(x), y(y), z(z) {}\n    constexpr Vec& operator+=(const Vec& r) {\
    \ x += r.x; y += r.y; z += r.z; return *this; }\n    constexpr Vec& operator-=(const\
    \ Vec& r) { x -= r.x; y -= r.y; z -= r.z; return *this; }\n    constexpr Vec&\
    \ operator*=(T r) { x *= r; y *= r; z *= r; return *this; }\n    constexpr Vec&\
    \ operator/=(T r) { x /= r; y /= r; z /= r; return *this; }\n    constexpr Vec\
    \ operator-() const { return Vec(-x, -y, -z); }\n    constexpr Vec operator+(const\
    \ Vec& r) const { return Vec(*this) += r; }\n    constexpr Vec operator-(const\
    \ Vec& r) const { return Vec(*this) -= r; }\n    constexpr Vec operator*(T r)\
    \ const { return Vec(*this) *= r; }\n    constexpr Vec operator/(T r) const {\
    \ return Vec(*this) /= r; }\n    friend constexpr Vec operator*(T r, const Vec&\
    \ v) { return v * r; }\n};\n\nstd::istream& operator>>(std::istream& is, Vec&\
    \ p) {\n    T x, y, z;\n    is >> x >> y >> z;\n    p = {x, y, z};\n    return\
    \ is;\n}\n\nT dot(const Vec& a, const Vec& b) {\n    return a.x*b.x + a.y*b.y\
    \ + a.z*b.z;\n}\n\nVec cross(const Vec& a, const Vec& b) {\n    return Vec(a.y*b.z-a.z*b.y,\
    \ a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);\n}\n\nnamespace std {\nT norm(const Vec&\
    \ a) { return dot(a, a); }\nT abs(const Vec& a) { return std::sqrt(std::norm(a));\
    \ }\n}\n\n*/\n#line 5 \"test/aoj/CGL_5_A.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int n;\n\
    \    cin >> n;\n    vector<Vec> pts(n);\n    for (auto& p : pts) cin >> p;\n \
    \   cout << closest_pair(pts) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A\"\
    \n#define ERROR 0.000001\n\n#include \"../../geometry/geometry.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int n;\n\
    \    cin >> n;\n    vector<Vec> pts(n);\n    for (auto& p : pts) cin >> p;\n \
    \   cout << closest_pair(pts) << endl;\n}\n"
  dependsOn:
  - geometry/geometry.cpp
  isVerificationFile: true
  path: test/aoj/CGL_5_A.test.cpp
  requiredBy: []
  timestamp: '2022-05-05 20:41:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_5_A.test.cpp
- /verify/test/aoj/CGL_5_A.test.cpp.html
title: test/aoj/CGL_5_A.test.cpp
---
