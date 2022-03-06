---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/geometry.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n#include\
    \ <vector>\n\n// note that if T is of an integer type, std::abs does not work\n\
    using T = double;\nusing Vec = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\
    \nconstexpr T eps = 1e-12;\ninline bool eq(T a, T b) { return std::abs(a - b)\
    \ < eps; }\ninline bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T\
    \ a, T b) { return a < b + eps; }\n\nstd::istream& operator>>(std::istream& is,\
    \ Vec& p) {\n    T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n\
    }\n\nT dot(const Vec& a, const Vec& b) {\n    return (std::conj(a) * b).real();\n\
    }\n\nT cross(const Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n\
    }\n\nVec rot(const Vec& a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n\
    }\n\nVec projection(const Vec& a, const Vec& b, const Vec& c) {\n    return a\
    \ + dot(b - a, c - a) * (b - a) / std::norm(b - a);\n}\n\nVec reflection(const\
    \ Vec& a, const Vec& b, const Vec& c) {\n    return T(2) * projection(a, b, c)\
    \ - c;\n}\n\nint ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b\
    \ - a, c - a), 0)) return 0;  // collinear\n    if (lt(cross(b - a, c - a), 0))\
    \ return -1;  // clockwise\n    return 1;  // counter clockwise\n}\n\nbool on_segment(const\
    \ Vec& a, const Vec& b, const Vec& c) {\n    Vec u = a - c, v = b - c;\n    return\
    \ eq(cross(u, v), 0) && leq(dot(u, v), 0);\n}\n\nbool intersect_segments(const\
    \ Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n    if (ccw(a, c, d) !=\
    \ ccw(b, c, d) && ccw(a, b, c) != ccw(a, b, d)) return true;\n    if (on_segment(a,\
    \ b, c) || on_segment(c, d, a) || on_segment(c, d, a) || on_segment(c, d, b))\
    \ return true;\n    return false;\n}\n\nT dist_line_point(const Vec& a, const\
    \ Vec& b, const Vec& c) {\n    return std::abs(cross(b - a, c - a)) / std::abs(b\
    \ - a);\n}\n\nT dist_segment_point(const Vec& a, const Vec& b, const Vec& c) {\n\
    \    if (lt(dot(b - a, c - a), 0)) return std::abs(c - a);\n    if (lt(dot(a -\
    \ b, c - b), 0)) return std::abs(c - b);\n    return std::abs(cross(b - a, c -\
    \ a)) / std::abs(b - a);\n}\n\nT dist_segments(const Vec& a, const Vec& b, const\
    \ Vec& c, const Vec& d) {\n    if (intersect_segments(a, b, c, d)) return T(0);\n\
    \    return std::min(\n        std::min(dist_segment_point(a, b, c), dist_segment_point(a,\
    \ b, d)),\n        std::min(dist_segment_point(c, d, a), dist_segment_point(c,\
    \ d, b))\n    );\n}\n\nVec intersection_lines(const Vec& a, const Vec& b, const\
    \ Vec& c, const Vec& d) {\n    Vec p = b - a;\n    Vec q = d - c;\n    Vec r =\
    \ c - a;\n    assert(!eq(cross(q, p), 0)); // not parallel\n    return a + cross(q,\
    \ r) / cross(q, p) * p;\n}\n\nstd::vector<Vec> intersection_circle_line(const\
    \ Vec& c, T r, const Vec& a, const Vec& b) {\n    T d = dist_line_point(a, b,\
    \ c);\n    if (lt(r, d)) return {};  // no intersection\n    Vec e1 = (b - a)\
    \ / std::abs(b - a);\n    Vec e2 = Vec(-e1.imag(), e1.real());\n    if (ccw(c,\
    \ a, b) == 1) e2 *= -1;\n    if (eq(r, d)) return {c + d*e2};  // tangent\n  \
    \  T t = std::sqrt(r*r - d*d);\n    return {c + d*e2 + t*e1, c + d*e2 - t*e1};\n\
    }\n\nstd::vector<Vec> intersection_circles(const Vec& c1, T r1, const Vec& c2,\
    \ T r2) {\n    T d = std::abs(c1 - c2);\n    if (lt(r1 + r2, d)) return {};  //\
    \ outside\n    Vec e1 = (c2 - c1) / std::abs(c2 - c1);\n    Vec e2 = Vec(-e1.imag(),\
    \ e1.real());\n    if (lt(d, std::abs(r2 - r1))) return {};  // contain\n    if\
    \ (eq(d, std::abs(r2 - r1))) return {c1 + r1*e1};  // tangent\n    T x = (r1*r1\
    \ - r2*r2 + d*d) / (2*d);\n    T y = std::sqrt(r1*r1 - x*x);\n    return {c1 +\
    \ x*e1 + y*e2, c1 + x*e1 - y*e2};\n}\n\nT area(const std::vector<Vec>& pts) {\n\
    \    int n = pts.size();\n    T res = 0;\n    for (int i = 0; i < n; ++i) {\n\
    \        res += cross(pts[i], pts[(i + 1) % n]);\n    }\n    return std::abs(res)\
    \ / T(2);\n}\n\nT area_intersection_circles(const Vec& c1, T r1, const Vec& c2,\
    \ T r2) {\n    T d = std::abs(c2 - c1);\n    if (leq(r1 + r2, d)) return 0;  //\
    \ outside\n    if (leq(d, std::abs(r2 - r1))) {  // contain\n        T r = std::min(r1,\
    \ r2);\n        return PI * r * r;\n    }\n    T ans = 0;\n    T a;\n    a = std::acos((r1*r1+d*d-r2*r2)/(2*r1*d));\n\
    \    ans += r1*r1*(a - std::sin(a)*std::cos(a));\n    a = std::acos((r2*r2+d*d-r1*r1)/(2*r2*d));\n\
    \    ans += r2*r2*(a - std::sin(a)*std::cos(a));\n    return ans;\n}\n\nbool is_convex(const\
    \ std::vector<Vec>& pts) {\n    int n = pts.size();\n    for (int i = 0; i < n;\
    \ ++i) {\n        if (lt(cross(pts[(i+1)%n] - pts[i], pts[(i+2)%n] - pts[(i+1)%n]),\
    \ 0)) {\n            return false;\n        }\n    }\n    return true;\n}\n\n\
    int contains(const std::vector<Vec>& pts, const Vec& q) {\n    int n = pts.size();\n\
    \    bool in = 0;\n    for (int i = 0; i < n; ++i) {\n        auto a = pts[i]\
    \ - q, b = pts[(i+1)%n] - q;\n        if (eq(cross(a, b), 0) && (lt(dot(a, b),\
    \ 0) || eq(dot(a, b), 0))) return 1;\n        if (a.imag() > b.imag()) std::swap(a,\
    \ b);\n        if (leq(a.imag(), 0) && lt(0, b.imag()) && lt(cross(a, b), 0))\
    \ in ^= 1;\n    }\n    return in ? 2 : 0;\n}\n\nVec centroid(const Vec& A, const\
    \ Vec& B, const Vec& C) {\n    assert(ccw(A, B, C) != 0);\n    return (A + B +\
    \ C) / T(3);\n}\n\nVec incenter(const Vec& A, const Vec& B, const Vec& C) {\n\
    \    assert(ccw(A, B, C) != 0);\n    T a = std::abs(B - C);\n    T b = std::abs(C\
    \ - A);\n    T c = std::abs(A - B);\n    return (a*A + b*B + c*C) / (a + b + c);\n\
    }\n\nVec circumcenter(const Vec& A, const Vec& B, const Vec& C) {\n    assert(ccw(A,\
    \ B, C) != 0);\n    auto p = B - A, q = C - A;\n    return A + intersection_lines(p/T(2),\
    \ p/T(2) + Vec(-p.imag(), p.real()),\n                                  q/T(2),\
    \ q/T(2) + Vec(-q.imag(), q.real()));\n}\n\n// large error but beautiful\n// Vec\
    \ circumcenter(const Vec& A, const Vec& B, const Vec& C) {\n//     assert(ccw(A,\
    \ B, C) != 0);\n//     Vec p = C - B, q = A - C, r = B - A;\n//     T a = std::norm(p)\
    \ * dot(q, r);\n//     T b = std::norm(q) * dot(r, p);\n//     T c = std::norm(r)\
    \ * dot(p, q);\n//     return (a*A + b*B + c*C) / (a + b + c);\n// }\n\nstd::vector<Vec>\
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
    \ rec(rec, 0, pts.size());\n}\n\n\n/*\n// for 3d geometry\n// functions that will\
    \ work without any modifications\n// projection, reflection, dist_line_point,\
    \ dist_segment_point, dist_segments,\n// centroid, incenter\n\nstruct Vec {\n\
    \    T x, y, z;\n    Vec() = default;\n    constexpr Vec(T x, T y, T z) : x(x),\
    \ y(y), z(z) {}\n    constexpr Vec& operator+=(const Vec& r) { x += r.x; y +=\
    \ r.y; z += r.z; return *this; }\n    constexpr Vec& operator-=(const Vec& r)\
    \ { x -= r.x; y -= r.y; z -= r.z; return *this; }\n    constexpr Vec& operator*=(T\
    \ r) { x *= r; y *= r; z *= r; return *this; }\n    constexpr Vec& operator/=(T\
    \ r) { x /= r; y /= r; z /= r; return *this; }\n    constexpr Vec operator-()\
    \ const { return Vec(-x, -y, -z); }\n    constexpr Vec operator+(const Vec& r)\
    \ const { return Vec(*this) += r; }\n    constexpr Vec operator-(const Vec& r)\
    \ const { return Vec(*this) -= r; }\n    constexpr Vec operator*(T r) const {\
    \ return Vec(*this) *= r; }\n    constexpr Vec operator/(T r) const { return Vec(*this)\
    \ /= r; }\n    friend constexpr Vec operator*(T r, const Vec& v) { return v *\
    \ r; }\n};\n\nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y,\
    \ z;\n    is >> x >> y >> z;\n    p = {x, y, z};\n    return is;\n}\n\nT dot(const\
    \ Vec& a, const Vec& b) {\n    return a.x*b.x + a.y*b.y + a.z*b.z;\n}\n\nVec cross(const\
    \ Vec& a, const Vec& b) {\n    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);\n\
    }\n\nnamespace std {\nT norm(const Vec& a) { return dot(a, a); }\nT abs(const\
    \ Vec& a) { return std::sqrt(std::norm(a)); }\n}\n\n*/\n\n/*\n// for integer coordinates\n\
    // operations with no floating point error\n\nvoid sort_by_arg(std::vector<pair<Vec,\
    \ int>>& pts) {\n    auto top = [&](auto& a) {\n        return a.real() > 0 ||\
    \ (a.imag() == 0 && a.real() > 0);\n    };\n    auto cmp = [&](auto& p, auto&\
    \ q) {\n        auto a = p.first;\n        auto b = q.first;\n        bool ta\
    \ = top(a), tb = top(b);\n        if (ta != tb) return tb;\n        return cross(a,\
    \ b) > 0;\n    };\n    std::sort(pts.begin(), pts.end(), cmp);\n}\n\n// watch\
    \ out for overflow\nbool compare_angle(const Vec& a, const Vec& b, const Vec&\
    \ c, const Vec& d) {\n    Vec u(dot(a, b), std::abs(cross(a, b)));\n    Vec v(dot(c,\
    \ d), std::abs(cross(c, d)));\n    return cross(u, v) > 0;\n}\n\n*/\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <complex>\n#include <iostream>\n#include <vector>\n\n// note that if\
    \ T is of an integer type, std::abs does not work\nusing T = double;\nusing Vec\
    \ = std::complex<T>;\n\nconst T PI = std::acos(-1);\n\nconstexpr T eps = 1e-12;\n\
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
    \ d, a), dist_segment_point(c, d, b))\n    );\n}\n\nVec intersection_lines(const\
    \ Vec& a, const Vec& b, const Vec& c, const Vec& d) {\n    Vec p = b - a;\n  \
    \  Vec q = d - c;\n    Vec r = c - a;\n    assert(!eq(cross(q, p), 0)); // not\
    \ parallel\n    return a + cross(q, r) / cross(q, p) * p;\n}\n\nstd::vector<Vec>\
    \ intersection_circle_line(const Vec& c, T r, const Vec& a, const Vec& b) {\n\
    \    T d = dist_line_point(a, b, c);\n    if (lt(r, d)) return {};  // no intersection\n\
    \    Vec e1 = (b - a) / std::abs(b - a);\n    Vec e2 = Vec(-e1.imag(), e1.real());\n\
    \    if (ccw(c, a, b) == 1) e2 *= -1;\n    if (eq(r, d)) return {c + d*e2};  //\
    \ tangent\n    T t = std::sqrt(r*r - d*d);\n    return {c + d*e2 + t*e1, c + d*e2\
    \ - t*e1};\n}\n\nstd::vector<Vec> intersection_circles(const Vec& c1, T r1, const\
    \ Vec& c2, T r2) {\n    T d = std::abs(c1 - c2);\n    if (lt(r1 + r2, d)) return\
    \ {};  // outside\n    Vec e1 = (c2 - c1) / std::abs(c2 - c1);\n    Vec e2 = Vec(-e1.imag(),\
    \ e1.real());\n    if (lt(d, std::abs(r2 - r1))) return {};  // contain\n    if\
    \ (eq(d, std::abs(r2 - r1))) return {c1 + r1*e1};  // tangent\n    T x = (r1*r1\
    \ - r2*r2 + d*d) / (2*d);\n    T y = std::sqrt(r1*r1 - x*x);\n    return {c1 +\
    \ x*e1 + y*e2, c1 + x*e1 - y*e2};\n}\n\nT area(const std::vector<Vec>& pts) {\n\
    \    int n = pts.size();\n    T res = 0;\n    for (int i = 0; i < n; ++i) {\n\
    \        res += cross(pts[i], pts[(i + 1) % n]);\n    }\n    return std::abs(res)\
    \ / T(2);\n}\n\nT area_intersection_circles(const Vec& c1, T r1, const Vec& c2,\
    \ T r2) {\n    T d = std::abs(c2 - c1);\n    if (leq(r1 + r2, d)) return 0;  //\
    \ outside\n    if (leq(d, std::abs(r2 - r1))) {  // contain\n        T r = std::min(r1,\
    \ r2);\n        return PI * r * r;\n    }\n    T ans = 0;\n    T a;\n    a = std::acos((r1*r1+d*d-r2*r2)/(2*r1*d));\n\
    \    ans += r1*r1*(a - std::sin(a)*std::cos(a));\n    a = std::acos((r2*r2+d*d-r1*r1)/(2*r2*d));\n\
    \    ans += r2*r2*(a - std::sin(a)*std::cos(a));\n    return ans;\n}\n\nbool is_convex(const\
    \ std::vector<Vec>& pts) {\n    int n = pts.size();\n    for (int i = 0; i < n;\
    \ ++i) {\n        if (lt(cross(pts[(i+1)%n] - pts[i], pts[(i+2)%n] - pts[(i+1)%n]),\
    \ 0)) {\n            return false;\n        }\n    }\n    return true;\n}\n\n\
    int contains(const std::vector<Vec>& pts, const Vec& q) {\n    int n = pts.size();\n\
    \    bool in = 0;\n    for (int i = 0; i < n; ++i) {\n        auto a = pts[i]\
    \ - q, b = pts[(i+1)%n] - q;\n        if (eq(cross(a, b), 0) && (lt(dot(a, b),\
    \ 0) || eq(dot(a, b), 0))) return 1;\n        if (a.imag() > b.imag()) std::swap(a,\
    \ b);\n        if (leq(a.imag(), 0) && lt(0, b.imag()) && lt(cross(a, b), 0))\
    \ in ^= 1;\n    }\n    return in ? 2 : 0;\n}\n\nVec centroid(const Vec& A, const\
    \ Vec& B, const Vec& C) {\n    assert(ccw(A, B, C) != 0);\n    return (A + B +\
    \ C) / T(3);\n}\n\nVec incenter(const Vec& A, const Vec& B, const Vec& C) {\n\
    \    assert(ccw(A, B, C) != 0);\n    T a = std::abs(B - C);\n    T b = std::abs(C\
    \ - A);\n    T c = std::abs(A - B);\n    return (a*A + b*B + c*C) / (a + b + c);\n\
    }\n\nVec circumcenter(const Vec& A, const Vec& B, const Vec& C) {\n    assert(ccw(A,\
    \ B, C) != 0);\n    auto p = B - A, q = C - A;\n    return A + intersection_lines(p/T(2),\
    \ p/T(2) + Vec(-p.imag(), p.real()),\n                                  q/T(2),\
    \ q/T(2) + Vec(-q.imag(), q.real()));\n}\n\n// large error but beautiful\n// Vec\
    \ circumcenter(const Vec& A, const Vec& B, const Vec& C) {\n//     assert(ccw(A,\
    \ B, C) != 0);\n//     Vec p = C - B, q = A - C, r = B - A;\n//     T a = std::norm(p)\
    \ * dot(q, r);\n//     T b = std::norm(q) * dot(r, p);\n//     T c = std::norm(r)\
    \ * dot(p, q);\n//     return (a*A + b*B + c*C) / (a + b + c);\n// }\n\nstd::vector<Vec>\
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
    \ rec(rec, 0, pts.size());\n}\n\n\n/*\n// for 3d geometry\n// functions that will\
    \ work without any modifications\n// projection, reflection, dist_line_point,\
    \ dist_segment_point, dist_segments,\n// centroid, incenter\n\nstruct Vec {\n\
    \    T x, y, z;\n    Vec() = default;\n    constexpr Vec(T x, T y, T z) : x(x),\
    \ y(y), z(z) {}\n    constexpr Vec& operator+=(const Vec& r) { x += r.x; y +=\
    \ r.y; z += r.z; return *this; }\n    constexpr Vec& operator-=(const Vec& r)\
    \ { x -= r.x; y -= r.y; z -= r.z; return *this; }\n    constexpr Vec& operator*=(T\
    \ r) { x *= r; y *= r; z *= r; return *this; }\n    constexpr Vec& operator/=(T\
    \ r) { x /= r; y /= r; z /= r; return *this; }\n    constexpr Vec operator-()\
    \ const { return Vec(-x, -y, -z); }\n    constexpr Vec operator+(const Vec& r)\
    \ const { return Vec(*this) += r; }\n    constexpr Vec operator-(const Vec& r)\
    \ const { return Vec(*this) -= r; }\n    constexpr Vec operator*(T r) const {\
    \ return Vec(*this) *= r; }\n    constexpr Vec operator/(T r) const { return Vec(*this)\
    \ /= r; }\n    friend constexpr Vec operator*(T r, const Vec& v) { return v *\
    \ r; }\n};\n\nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y,\
    \ z;\n    is >> x >> y >> z;\n    p = {x, y, z};\n    return is;\n}\n\nT dot(const\
    \ Vec& a, const Vec& b) {\n    return a.x*b.x + a.y*b.y + a.z*b.z;\n}\n\nVec cross(const\
    \ Vec& a, const Vec& b) {\n    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);\n\
    }\n\nnamespace std {\nT norm(const Vec& a) { return dot(a, a); }\nT abs(const\
    \ Vec& a) { return std::sqrt(std::norm(a)); }\n}\n\n*/\n\n/*\n// for integer coordinates\n\
    // operations with no floating point error\n\nvoid sort_by_arg(std::vector<pair<Vec,\
    \ int>>& pts) {\n    auto top = [&](auto& a) {\n        return a.real() > 0 ||\
    \ (a.imag() == 0 && a.real() > 0);\n    };\n    auto cmp = [&](auto& p, auto&\
    \ q) {\n        auto a = p.first;\n        auto b = q.first;\n        bool ta\
    \ = top(a), tb = top(b);\n        if (ta != tb) return tb;\n        return cross(a,\
    \ b) > 0;\n    };\n    std::sort(pts.begin(), pts.end(), cmp);\n}\n\n// watch\
    \ out for overflow\nbool compare_angle(const Vec& a, const Vec& b, const Vec&\
    \ c, const Vec& d) {\n    Vec u(dot(a, b), std::abs(cross(a, b)));\n    Vec v(dot(c,\
    \ d), std::abs(cross(c, d)));\n    return cross(u, v) > 0;\n}\n\n*/"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.cpp
  requiredBy: []
  timestamp: '2021-12-04 19:51:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_3_C.test.cpp
documentation_of: geometry/geometry.cpp
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

- `Vec projection(Vec a, Vec b, Vec c)`
    - 点 $c$ の直線 $ab$ 上の射影を求める

- `Vec reflection(Vec a, Vec b, Vec c)`
    - 点 $c$ の直線 $ab$ に関して対称な点を求める

- `bool ccw(Vec a, Vec b, Vec c)`
    - $a,b,c$ が同一直線上にあるなら0, $a \rightarrow b \rightarrow c$ が反時計回りなら1，そうでなければ-1を返す

- `bool on_segment(Vec a, Vec b, Vec c)`
    - 点 $c$ が線分 $ab$ 上にあるか判定する

- `bool intersect_segments(Vec a, Vec b, Vec c, Vec d)`
    - 線分 $ab$ と線分 $cd$ が交差するか判定する

 - `T dist_line_point(Vec a, Vec b, Vec c)`
    - 直線 $ab$ と点 $c$ の距離を求める

 - `T dist_segment_point(Vec a, Vec b, Vec c)`
    - 線分 $ab$ と点 $c$ の距離を求める

 - `T dist_segments(Vec a, Vec b, Vec c, Vec d)`
    - 線分 $ab$ と線分 $cd$ の距離を求める

- `Vec intersection_lines(Vec a, Vec b, Vec c, Vec d)`
    - 直線 $ab$ と直線 $cd$ の交点を求める

- `vector<Vec> intersection_circle_line(Vec c, T r, Vec a, Vec b)`
    - 中心 $c$，半径 $r$ の円と直線 $ab$ の交点を求める

- `vector<Vec> intersection_circles(Vec c1, T r1, Vec c2, T r2)`
    - 中心 $c_1$，半径 $r_1$ の円と中心 $c_2$，半径 $r_2$ の円の交点を求める

- `T area(vector<Vec> pts)`
    - 多角形 $pts$ の面積を求める
    - 時間計算量: $O(n)$

- `T area(vector<Vec> pts)`
    - 多角形 $pts$ が凸か判定する．`pts` は反時計回りに与えられる必要がある
    - 時間計算量: $O(n)$

- `int contains(vector<Vec> pts, Vec q)`
    - 多角形 $pts$ が点 $q$ を含むか判定する．内部に含むなら2，境界に含むから1，外部に含むなら0を返す
    - 時間計算量: $O(n)$

- `Vec centroid(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の重心を返す
    - ***NOT VERIFIED***

- `Vec incenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の内心を返す

- `Vec circumcenter(Vec A, Vec B, Vec C)`
    - 三角形 $ABC$ の外心を返す

- `vector<Vec> convex_hull(vector<Vec> pts)`
    - 与えられた点の凸包を返す
    - 時間計算量: $O(n\log n)$

- `T closest_pair(vector<Vec> pts)`
    - 与えられた点のうち最も近い2点の距離を分割統治法で求める
    - 時間計算量: $O(n\log n)$