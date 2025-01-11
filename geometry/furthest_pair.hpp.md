---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/convex_hull.hpp
    title: Convex Hull
  - icon: ':question:'
    path: geometry/geometry.hpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/furthest_pair.test.cpp
    title: test/yosupo/furthest_pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Furthest Pair
    links: []
  bundledCode: "#line 2 \"geometry/furthest_pair.hpp\"\n#include <algorithm>\n#include\
    \ <utility>\n#include <vector>\n\n#line 3 \"geometry/convex_hull.hpp\"\n\n#line\
    \ 3 \"geometry/geometry.hpp\"\n#include <cassert>\n#include <cmath>\n#include\
    \ <complex>\n#include <iostream>\n#include <numbers>\n#include <numeric>\n#line\
    \ 10 \"geometry/geometry.hpp\"\n\n// note that if T is of an integer type, std::abs\
    \ does not work\nusing T = double;\nusing Vec = std::complex<T>;\n\nstd::istream&\
    \ operator>>(std::istream& is, Vec& p) {\n    T x, y;\n    is >> x >> y;\n   \
    \ p = {x, y};\n    return is;\n}\n\nT dot(const Vec& a, const Vec& b) { return\
    \ (std::conj(a) * b).real(); }\n\nT cross(const Vec& a, const Vec& b) { return\
    \ (std::conj(a) * b).imag(); }\n\nconstexpr T PI = std::numbers::pi_v<T>;\nconstexpr\
    \ T eps = 1e-10;\ninline bool eq(T a, T b) { return std::abs(a - b) <= eps; }\n\
    inline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }\ninline bool lt(T\
    \ a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) { return a <= b +\
    \ eps; }\n\nstruct Line {\n    Vec p1, p2;\n    Line() = default;\n    Line(const\
    \ Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2\
    \ - p1; }\n};\n\nstruct Segment : Line {\n    using Line::Line;\n};\n\nstruct\
    \ Circle {\n    Vec c;\n    T r;\n    Circle() = default;\n    Circle(const Vec&\
    \ c, T r) : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\nVec rot(const\
    \ Vec& a, T ang) { return a * Vec(std::cos(ang), std::sin(ang)); }\n\nVec perp(const\
    \ Vec& a) { return Vec(-a.imag(), a.real()); }\n\nVec projection(const Line& l,\
    \ const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir()) * l.dir() / std::norm(l.dir());\n\
    }\n\nVec reflection(const Line& l, const Vec& p) {\n    return T(2) * projection(l,\
    \ p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n// -1: clockwise\nint\
    \ ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b - a, c -\
    \ a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0)) return -1;\n    return\
    \ 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n    std::ranges::sort(pts,\
    \ [&](auto& p, auto& q) {\n        if ((p.imag() < 0) != (q.imag() < 0)) return\
    \ (p.imag() < 0);\n        if (cross(p, q) == 0) {\n            if (p == Vec(0,\
    \ 0))\n                return !(q.imag() < 0 || (q.imag() == 0 && q.real() > 0));\n\
    \            if (q == Vec(0, 0))\n                return (p.imag() < 0 || (p.imag()\
    \ == 0 && p.real() > 0));\n            return (p.real() > q.real());\n       \
    \ }\n        return (cross(p, q) > 0);\n    });\n}\n#line 5 \"geometry/convex_hull.hpp\"\
    \n\nstd::vector<Vec> convex_hull(std::vector<Vec> pts, bool strict = true) {\n\
    \    std::ranges::sort(pts, {}, [](const Vec& v) {\n        return std::make_pair(v.imag(),\
    \ v.real());\n    });\n    pts.erase(std::ranges::unique(pts).begin(), pts.end());\n\
    \    const int n = pts.size();\n    if (n <= 1) return pts;\n    int k = 0;  //\
    \ the number of vertices in the convex hull\n    std::vector<Vec> ch(2 * n);\n\
    \    // right\n    for (int i = 0; i < n; ++i) {\n        while (k > 1 &&\n  \
    \             leq(cross(ch[k - 1] - ch[k - 2], pts[i] - ch[k - 1]), 0))\n    \
    \        --k;\n        ch[k++] = pts[i];\n    }\n    int t = k;\n    // left\n\
    \    for (int i = n - 2; i >= 0; --i) {\n        while (k > t &&\n           \
    \    leq(cross(ch[k - 1] - ch[k - 2], pts[i] - ch[k - 1]), 0))\n            --k;\n\
    \        ch[k++] = pts[i];\n    }\n    ch.resize(k - 1);\n    return ch;\n}\n\
    #line 8 \"geometry/furthest_pair.hpp\"\n\n/**\n * @brief Furthest Pair\n */\n\
    std::tuple<T, int, int> furthest_pair(const std::vector<Vec>& pts) {\n    assert(pts.size()\
    \ >= 2);\n    auto conv = convex_hull(pts);\n    const int n = conv.size();\n\
    \    if (n <= 1) {\n        return {0, 0, 1};\n    }\n    std::tuple<T, int, int>\
    \ furthest;\n    if (n == 2) {\n        furthest = {std::abs(conv[0] - conv[1]),\
    \ 0, 1};\n    } else {\n        int si = 0, sj = 0;\n        for (int k = 0; k\
    \ < n; ++k) {\n            if (lt(conv[k].real(), conv[si].real())) si = k;\n\
    \            if (lt(conv[sj].real(), conv[k].real())) sj = k;\n        }\n   \
    \     for (int i = si, j = sj; i != sj || j != si;) {\n            furthest =\
    \ std::max(furthest, {std::abs(conv[i] - conv[j]), i, j});\n            if (lt(cross(conv[(i\
    \ + 1) % n] - conv[i],\n                         conv[(j + 1) % n] - conv[j]),\n\
    \                   0)) {\n                i = (i + 1) % n;\n            } else\
    \ {\n                j = (j + 1) % n;\n            }\n        }\n    }\n    auto\
    \ [d, i0, j0] = furthest;\n    int i1 = -1, j1 = -1;\n    for (int k = 0; k <\
    \ (int)pts.size(); ++k) {\n        if (i1 == -1 && pts[k] == conv[i0]) i1 = k;\n\
    \        if (j1 == -1 && pts[k] == conv[j0]) j1 = k;\n    }\n    return {d, i1,\
    \ j1};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \n#include \"convex_hull.hpp\"\n#include \"geometry.hpp\"\n\n/**\n * @brief Furthest\
    \ Pair\n */\nstd::tuple<T, int, int> furthest_pair(const std::vector<Vec>& pts)\
    \ {\n    assert(pts.size() >= 2);\n    auto conv = convex_hull(pts);\n    const\
    \ int n = conv.size();\n    if (n <= 1) {\n        return {0, 0, 1};\n    }\n\
    \    std::tuple<T, int, int> furthest;\n    if (n == 2) {\n        furthest =\
    \ {std::abs(conv[0] - conv[1]), 0, 1};\n    } else {\n        int si = 0, sj =\
    \ 0;\n        for (int k = 0; k < n; ++k) {\n            if (lt(conv[k].real(),\
    \ conv[si].real())) si = k;\n            if (lt(conv[sj].real(), conv[k].real()))\
    \ sj = k;\n        }\n        for (int i = si, j = sj; i != sj || j != si;) {\n\
    \            furthest = std::max(furthest, {std::abs(conv[i] - conv[j]), i, j});\n\
    \            if (lt(cross(conv[(i + 1) % n] - conv[i],\n                     \
    \    conv[(j + 1) % n] - conv[j]),\n                   0)) {\n               \
    \ i = (i + 1) % n;\n            } else {\n                j = (j + 1) % n;\n \
    \           }\n        }\n    }\n    auto [d, i0, j0] = furthest;\n    int i1\
    \ = -1, j1 = -1;\n    for (int k = 0; k < (int)pts.size(); ++k) {\n        if\
    \ (i1 == -1 && pts[k] == conv[i0]) i1 = k;\n        if (j1 == -1 && pts[k] ==\
    \ conv[j0]) j1 = k;\n    }\n    return {d, i1, j1};\n}"
  dependsOn:
  - geometry/convex_hull.hpp
  - geometry/geometry.hpp
  isVerificationFile: false
  path: geometry/furthest_pair.hpp
  requiredBy: []
  timestamp: '2025-01-11 17:14:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/furthest_pair.test.cpp
documentation_of: geometry/furthest_pair.hpp
layout: document
redirect_from:
- /library/geometry/furthest_pair.hpp
- /library/geometry/furthest_pair.hpp.html
title: Furthest Pair
---
