---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/dist.hpp
    title: geometry/dist.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: Geometry
  - icon: ':heavy_check_mark:'
    path: geometry/intersect.hpp
    title: geometry/intersect.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/intersection.hpp
    title: geometry/intersection.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1283.test.cpp
    title: test/aoj/1283.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A.test.cpp
    title: test/aoj/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/polygon.hpp\"\n#include <algorithm>\n#include <deque>\n\
    #include <utility>\n#include <vector>\n\n#line 3 \"geometry/geometry.hpp\"\n#include\
    \ <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n#line\
    \ 8 \"geometry/geometry.hpp\"\n\n// note that if T is of an integer type, std::abs\
    \ does not work\nusing T = double;\nusing Vec = std::complex<T>;\n\nstd::istream&\
    \ operator>>(std::istream& is, Vec& p) {\n    T x, y;\n    is >> x >> y;\n   \
    \ p = {x, y};\n    return is;\n}\n\nT dot(const Vec& a, const Vec& b) { return\
    \ (std::conj(a) * b).real(); }\n\nT cross(const Vec& a, const Vec& b) { return\
    \ (std::conj(a) * b).imag(); }\n\nconst T PI = std::acos(-1);\nconstexpr T eps\
    \ = 1e-10;\ninline bool eq(T a, T b) { return std::abs(a - b) <= eps; }\ninline\
    \ bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }\ninline bool lt(T a,\
    \ T b) { return a < b - eps; }\ninline bool leq(T a, T b) { return a <= b + eps;\
    \ }\n\nstruct Line {\n    Vec p1, p2;\n    Line() = default;\n    Line(const Vec&\
    \ p1, const Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2 - p1;\
    \ }\n};\n\nstruct Segment : Line {\n    using Line::Line;\n};\n\nstruct Circle\
    \ {\n    Vec c;\n    T r;\n    Circle() = default;\n    Circle(const Vec& c, T\
    \ r) : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\nVec rot(const\
    \ Vec& a, T ang) { return a * Vec(std::cos(ang), std::sin(ang)); }\n\nVec perp(const\
    \ Vec& a) { return Vec(-a.imag(), a.real()); }\n\nVec projection(const Line& l,\
    \ const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir()) * l.dir() / std::norm(l.dir());\n\
    }\n\nVec reflection(const Line& l, const Vec& p) {\n    return T(2) * projection(l,\
    \ p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n// -1: clockwise\nint\
    \ ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b - a, c -\
    \ a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0)) return -1;\n    return\
    \ 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n    std::sort(pts.begin(),\
    \ pts.end(), [&](auto& p, auto& q) {\n        if ((p.imag() < 0) != (q.imag()\
    \ < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0) {\n            if\
    \ (p == Vec(0, 0))\n                return !(q.imag() < 0 || (q.imag() == 0 &&\
    \ q.real() > 0));\n            if (q == Vec(0, 0))\n                return (p.imag()\
    \ < 0 || (p.imag() == 0 && p.real() > 0));\n            return (p.real() > q.real());\n\
    \        }\n        return (cross(p, q) > 0);\n    });\n}\n#line 3 \"geometry/intersect.hpp\"\
    \n\nbool intersect(const Segment& s, const Vec& p) {\n    Vec u = s.p1 - p, v\
    \ = s.p2 - p;\n    return eq(cross(u, v), 0) && leq(dot(u, v), 0);\n}\n\n// 0:\
    \ outside\n// 1: on the border\n// 2: inside\nint intersect(const Polygon& poly,\
    \ const Vec& p) {\n    const int n = poly.size();\n    bool in = 0;\n    for (int\
    \ i = 0; i < n; ++i) {\n        auto a = poly[i] - p, b = poly[(i + 1) % n] -\
    \ p;\n        if (eq(cross(a, b), 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0)))\n\
    \            return 1;\n        if (a.imag() > b.imag()) std::swap(a, b);\n  \
    \      if (leq(a.imag(), 0) && lt(0, b.imag()) && lt(cross(a, b), 0)) in ^= 1;\n\
    \    }\n    return in ? 2 : 0;\n}\n\nint intersect(const Segment& s, const Segment&\
    \ t) {\n    auto a = s.p1, b = s.p2;\n    auto c = t.p1, d = t.p2;\n    if (ccw(a,\
    \ b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b)) return 2;\n    if (intersect(s,\
    \ c) || intersect(s, d) || intersect(t, a) ||\n        intersect(t, b))\n    \
    \    return 1;\n    return 0;\n}\n\n// true if they have positive area in common\
    \ or touch on the border\nbool intersect(const Polygon& poly1, const Polygon&\
    \ poly2) {\n    const int n = poly1.size();\n    const int m = poly2.size();\n\
    \    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n  \
    \          if (intersect(Segment(poly1[i], poly1[(i + 1) % n]),\n            \
    \              Segment(poly2[j], poly2[(j + 1) % m]))) {\n                return\
    \ true;\n            }\n        }\n    }\n    return intersect(poly1, poly2[0])\
    \ || intersect(poly2, poly1[0]);\n}\n\n// 0: inside\n// 1: inscribe\n// 2: intersect\n\
    // 3: circumscribe\n// 4: outside\nint intersect(const Circle& c1, const Circle&\
    \ c2) {\n    T d = std::abs(c1.c - c2.c);\n    if (lt(d, std::abs(c2.r - c1.r)))\
    \ return 0;\n    if (eq(d, std::abs(c2.r - c1.r))) return 1;\n    if (eq(c1.r\
    \ + c2.r, d)) return 3;\n    if (lt(c1.r + c2.r, d)) return 4;\n    return 2;\n\
    }\n#line 4 \"geometry/dist.hpp\"\n\nT dist(const Line& l, const Vec& p) {\n  \
    \  return std::abs(cross(p - l.p1, l.dir())) / std::abs(l.dir());\n}\n\nT dist(const\
    \ Segment& s, const Vec& p) {\n    if (lt(dot(p - s.p1, s.dir()), 0)) return std::abs(p\
    \ - s.p1);\n    if (lt(dot(p - s.p2, -s.dir()), 0)) return std::abs(p - s.p2);\n\
    \    return std::abs(cross(p - s.p1, s.dir())) / std::abs(s.dir());\n}\n\nT dist(const\
    \ Segment& s, const Segment& t) {\n    if (intersect(s, t)) return T(0);\n   \
    \ return std::min({dist(s, t.p1), dist(s, t.p2), dist(t, s.p1), dist(t, s.p2)});\n\
    }\n#line 4 \"geometry/intersection.hpp\"\n\nVec intersection(const Line& l, const\
    \ Line& m) {\n    assert(!eq(cross(l.dir(), m.dir()), 0));  // not parallel\n\
    \    Vec r = m.p1 - l.p1;\n    return l.p1 + cross(m.dir(), r) / cross(m.dir(),\
    \ l.dir()) * l.dir();\n}\n\nstd::vector<Vec> intersection(const Circle& c, const\
    \ Line& l) {\n    T d = dist(l, c.c);\n    if (lt(c.r, d)) return {};  // no intersection\n\
    \    Vec e1 = l.dir() / std::abs(l.dir());\n    Vec e2 = perp(e1);\n    if (ccw(c.c,\
    \ l.p1, l.p2) == 1) e2 *= -1;\n    if (eq(c.r, d)) return {c.c + d * e2};  //\
    \ tangent\n    T t = std::sqrt(c.r * c.r - d * d);\n    return {c.c + d * e2 +\
    \ t * e1, c.c + d * e2 - t * e1};\n}\n\nstd::vector<Vec> intersection(const Circle&\
    \ c1, const Circle& c2) {\n    T d = std::abs(c1.c - c2.c);\n    if (lt(c1.r +\
    \ c2.r, d)) return {};  // outside\n    Vec e1 = (c2.c - c1.c) / std::abs(c2.c\
    \ - c1.c);\n    Vec e2 = perp(e1);\n    if (lt(d, std::abs(c2.r - c1.r))) return\
    \ {};                  // contain\n    if (eq(d, std::abs(c2.r - c1.r))) return\
    \ {c1.c + c1.r * e1};  // tangent\n    T x = (c1.r * c1.r - c2.r * c2.r + d *\
    \ d) / (2 * d);\n    T y = std::sqrt(c1.r * c1.r - x * x);\n    return {c1.c +\
    \ x * e1 + y * e2, c1.c + x * e1 - y * e2};\n}\n\nT area_intersection(const Circle&\
    \ c1, const Circle& c2) {\n    T d = std::abs(c2.c - c1.c);\n    if (leq(c1.r\
    \ + c2.r, d)) return 0;    // outside\n    if (leq(d, std::abs(c2.r - c1.r)))\
    \ {  // inside\n        T r = std::min(c1.r, c2.r);\n        return PI * r * r;\n\
    \    }\n    T ans = 0;\n    T a;\n    a = std::acos((c1.r * c1.r + d * d - c2.r\
    \ * c2.r) / (2 * c1.r * d));\n    ans += c1.r * c1.r * (a - std::sin(a) * std::cos(a));\n\
    \    a = std::acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));\n  \
    \  ans += c2.r * c2.r * (a - std::sin(a) * std::cos(a));\n    return ans;\n}\n\
    #line 9 \"geometry/polygon.hpp\"\n\nT area(const Polygon& poly) {\n    const int\
    \ n = poly.size();\n    T res = 0;\n    for (int i = 0; i < n; ++i) {\n      \
    \  res += cross(poly[i], poly[(i + 1) % n]);\n    }\n    return std::abs(res)\
    \ / T(2);\n}\n\nbool is_convex(const Polygon& poly) {\n    int n = poly.size();\n\
    \    for (int i = 0; i < n; ++i) {\n        if (lt(cross(poly[(i + 1) % n] - poly[i],\n\
    \                     poly[(i + 2) % n] - poly[(i + 1) % n]),\n              \
    \ 0)) {\n            return false;\n        }\n    }\n    return true;\n}\n\n\
    Polygon convex_cut(const Polygon& poly, const Line& l) {\n    const int n = poly.size();\n\
    \    Polygon res;\n    for (int i = 0; i < n; ++i) {\n        auto p = poly[i],\
    \ q = poly[(i + 1) % n];\n        if (ccw(l.p1, l.p2, p) != -1) {\n          \
    \  if (res.empty() || !eq(res.back(), p)) {\n                res.push_back(p);\n\
    \            }\n        }\n        if (ccw(l.p1, l.p2, p) * ccw(l.p1, l.p2, q)\
    \ < 0) {\n            auto c = intersection(Line(p, q), l);\n            if (res.empty()\
    \ || !eq(res.back(), c)) {\n                res.push_back(c);\n            }\n\
    \        }\n    }\n    return res;\n}\n\nPolygon halfplane_intersection(std::vector<std::pair<Vec,\
    \ Vec>> hps) {\n    using Hp = std::pair<Vec, Vec>;  // (normal vector, a point\
    \ on the border)\n\n    auto intersection = [&](const Hp& l1, const Hp& l2) ->\
    \ Vec {\n        auto d = l2.second - l1.second;\n        return l1.second +\n\
    \               (dot(d, l2.first) / cross(l1.first, l2.first)) * perp(l1.first);\n\
    \    };\n\n    // check if the halfplane h contains the point p\n    auto contains\
    \ = [&](const Hp& h, const Vec& p) -> bool {\n        return dot(p - h.second,\
    \ h.first) > 0;\n    };\n\n    constexpr T INF = 1e15;\n    hps.emplace_back(Vec(1,\
    \ 0), Vec(-INF, 0));  // -INF <= x\n    hps.emplace_back(Vec(-1, 0), Vec(INF,\
    \ 0));  // x <= INF\n    hps.emplace_back(Vec(0, 1), Vec(0, -INF));  // -INF <=\
    \ y\n    hps.emplace_back(Vec(0, -1), Vec(0, INF));  // y <= INF\n\n    std::sort(hps.begin(),\
    \ hps.end(), [&](const auto& h1, const auto& h2) {\n        return std::arg(h1.first)\
    \ < std::arg(h2.first);\n    });\n\n    std::deque<Hp> dq;\n    int len = 0;\n\
    \    for (auto& hp : hps) {\n        while (len > 1 &&\n               !contains(hp,\
    \ intersection(dq[len - 1], dq[len - 2]))) {\n            dq.pop_back();\n   \
    \         --len;\n        }\n\n        while (len > 1 && !contains(hp, intersection(dq[0],\
    \ dq[1]))) {\n            dq.pop_front();\n            --len;\n        }\n\n \
    \       // parallel\n        if (len > 0 && eq(cross(dq[len - 1].first, hp.first),\
    \ 0)) {\n            // opposite\n            if (lt(dot(dq[len - 1].first, hp.first),\
    \ 0)) {\n                return {};\n            }\n            // same\n    \
    \        if (!contains(hp, dq[len - 1].second)) {\n                dq.pop_back();\n\
    \                --len;\n            } else\n                continue;\n     \
    \   }\n\n        dq.push_back(hp);\n        ++len;\n    }\n\n    while (len >\
    \ 2 &&\n           !contains(dq[0], intersection(dq[len - 1], dq[len - 2]))) {\n\
    \        dq.pop_back();\n        --len;\n    }\n\n    while (len > 2 && !contains(dq[len\
    \ - 1], intersection(dq[0], dq[1]))) {\n        dq.pop_front();\n        --len;\n\
    \    }\n\n    if (len < 3) return {};\n\n    std::vector<Vec> poly(len);\n   \
    \ for (int i = 0; i < len - 1; ++i) {\n        poly[i] = intersection(dq[i], dq[i\
    \ + 1]);\n    }\n    poly[len - 1] = intersection(dq[len - 1], dq[0]);\n    return\
    \ poly;\n}\n\nclass PolygonContainment {\n   public:\n    explicit PolygonContainment(Polygon\
    \ poly) : poly(poly) {}\n\n    // 0: outside\n    // 1: on the border\n    //\
    \ 2: inside\n    int query(Vec pt) {\n        auto c1 = cross(poly[1] - poly[0],\
    \ pt - poly[0]);\n        auto c2 = cross(poly.back() - poly[0], pt - poly[0]);\n\
    \        if (lt(c1, 0) || lt(0, c2)) return 0;\n\n        int lb = 1, ub = (int)poly.size()\
    \ - 1;\n        while (ub - lb > 1) {\n            int m = (lb + ub) / 2;\n  \
    \          if (leq(0, cross(poly[m] - poly[0], pt - poly[0])))\n             \
    \   lb = m;\n            else\n                ub = m;\n        }\n        auto\
    \ c = cross(poly[lb] - pt, poly[ub] - pt);\n        if (lt(c, 0)) return 0;\n\
    \        if (eq(c, 0) || eq(c1, 0) || eq(c2, 0)) return 1;\n        return 2;\n\
    \    }\n\n   private:\n    Polygon poly;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <deque>\n#include <utility>\n\
    #include <vector>\n\n#include \"geometry.hpp\"\n#include \"intersection.hpp\"\n\
    \nT area(const Polygon& poly) {\n    const int n = poly.size();\n    T res = 0;\n\
    \    for (int i = 0; i < n; ++i) {\n        res += cross(poly[i], poly[(i + 1)\
    \ % n]);\n    }\n    return std::abs(res) / T(2);\n}\n\nbool is_convex(const Polygon&\
    \ poly) {\n    int n = poly.size();\n    for (int i = 0; i < n; ++i) {\n     \
    \   if (lt(cross(poly[(i + 1) % n] - poly[i],\n                     poly[(i +\
    \ 2) % n] - poly[(i + 1) % n]),\n               0)) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\n\nPolygon convex_cut(const Polygon& poly,\
    \ const Line& l) {\n    const int n = poly.size();\n    Polygon res;\n    for\
    \ (int i = 0; i < n; ++i) {\n        auto p = poly[i], q = poly[(i + 1) % n];\n\
    \        if (ccw(l.p1, l.p2, p) != -1) {\n            if (res.empty() || !eq(res.back(),\
    \ p)) {\n                res.push_back(p);\n            }\n        }\n       \
    \ if (ccw(l.p1, l.p2, p) * ccw(l.p1, l.p2, q) < 0) {\n            auto c = intersection(Line(p,\
    \ q), l);\n            if (res.empty() || !eq(res.back(), c)) {\n            \
    \    res.push_back(c);\n            }\n        }\n    }\n    return res;\n}\n\n\
    Polygon halfplane_intersection(std::vector<std::pair<Vec, Vec>> hps) {\n    using\
    \ Hp = std::pair<Vec, Vec>;  // (normal vector, a point on the border)\n\n   \
    \ auto intersection = [&](const Hp& l1, const Hp& l2) -> Vec {\n        auto d\
    \ = l2.second - l1.second;\n        return l1.second +\n               (dot(d,\
    \ l2.first) / cross(l1.first, l2.first)) * perp(l1.first);\n    };\n\n    // check\
    \ if the halfplane h contains the point p\n    auto contains = [&](const Hp& h,\
    \ const Vec& p) -> bool {\n        return dot(p - h.second, h.first) > 0;\n  \
    \  };\n\n    constexpr T INF = 1e15;\n    hps.emplace_back(Vec(1, 0), Vec(-INF,\
    \ 0));  // -INF <= x\n    hps.emplace_back(Vec(-1, 0), Vec(INF, 0));  // x <=\
    \ INF\n    hps.emplace_back(Vec(0, 1), Vec(0, -INF));  // -INF <= y\n    hps.emplace_back(Vec(0,\
    \ -1), Vec(0, INF));  // y <= INF\n\n    std::sort(hps.begin(), hps.end(), [&](const\
    \ auto& h1, const auto& h2) {\n        return std::arg(h1.first) < std::arg(h2.first);\n\
    \    });\n\n    std::deque<Hp> dq;\n    int len = 0;\n    for (auto& hp : hps)\
    \ {\n        while (len > 1 &&\n               !contains(hp, intersection(dq[len\
    \ - 1], dq[len - 2]))) {\n            dq.pop_back();\n            --len;\n   \
    \     }\n\n        while (len > 1 && !contains(hp, intersection(dq[0], dq[1])))\
    \ {\n            dq.pop_front();\n            --len;\n        }\n\n        //\
    \ parallel\n        if (len > 0 && eq(cross(dq[len - 1].first, hp.first), 0))\
    \ {\n            // opposite\n            if (lt(dot(dq[len - 1].first, hp.first),\
    \ 0)) {\n                return {};\n            }\n            // same\n    \
    \        if (!contains(hp, dq[len - 1].second)) {\n                dq.pop_back();\n\
    \                --len;\n            } else\n                continue;\n     \
    \   }\n\n        dq.push_back(hp);\n        ++len;\n    }\n\n    while (len >\
    \ 2 &&\n           !contains(dq[0], intersection(dq[len - 1], dq[len - 2]))) {\n\
    \        dq.pop_back();\n        --len;\n    }\n\n    while (len > 2 && !contains(dq[len\
    \ - 1], intersection(dq[0], dq[1]))) {\n        dq.pop_front();\n        --len;\n\
    \    }\n\n    if (len < 3) return {};\n\n    std::vector<Vec> poly(len);\n   \
    \ for (int i = 0; i < len - 1; ++i) {\n        poly[i] = intersection(dq[i], dq[i\
    \ + 1]);\n    }\n    poly[len - 1] = intersection(dq[len - 1], dq[0]);\n    return\
    \ poly;\n}\n\nclass PolygonContainment {\n   public:\n    explicit PolygonContainment(Polygon\
    \ poly) : poly(poly) {}\n\n    // 0: outside\n    // 1: on the border\n    //\
    \ 2: inside\n    int query(Vec pt) {\n        auto c1 = cross(poly[1] - poly[0],\
    \ pt - poly[0]);\n        auto c2 = cross(poly.back() - poly[0], pt - poly[0]);\n\
    \        if (lt(c1, 0) || lt(0, c2)) return 0;\n\n        int lb = 1, ub = (int)poly.size()\
    \ - 1;\n        while (ub - lb > 1) {\n            int m = (lb + ub) / 2;\n  \
    \          if (leq(0, cross(poly[m] - poly[0], pt - poly[0])))\n             \
    \   lb = m;\n            else\n                ub = m;\n        }\n        auto\
    \ c = cross(poly[lb] - pt, poly[ub] - pt);\n        if (lt(c, 0)) return 0;\n\
    \        if (eq(c, 0) || eq(c1, 0) || eq(c2, 0)) return 1;\n        return 2;\n\
    \    }\n\n   private:\n    Polygon poly;\n};"
  dependsOn:
  - geometry/geometry.hpp
  - geometry/intersection.hpp
  - geometry/dist.hpp
  - geometry/intersect.hpp
  isVerificationFile: false
  path: geometry/polygon.hpp
  requiredBy: []
  timestamp: '2023-05-14 13:38:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/1283.test.cpp
documentation_of: geometry/polygon.hpp
layout: document
redirect_from:
- /library/geometry/polygon.hpp
- /library/geometry/polygon.hpp.html
title: geometry/polygon.hpp
---
