---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Closest Pair
    links: []
  bundledCode: "#line 2 \"geometry/closest_pair.hpp\"\n#include <numeric>\n#include\
    \ <vector>\n#line 2 \"geometry/geometry.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n#line\
    \ 8 \"geometry/geometry.hpp\"\n\n// note that if T is of an integer type, std::abs\
    \ does not work\nusing T = double;\nusing Vec = std::complex<T>;\n\nconst T PI\
    \ = std::acos(-1);\n\nconstexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return\
    \ std::abs(a - b) <= eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a\
    \ - b) <= eps; }\ninline bool lt(T a, T b) { return a < b - eps; }\ninline bool\
    \ leq(T a, T b) { return a <= b + eps; }\n\nstd::istream& operator>>(std::istream&\
    \ is, Vec& p) {\n    T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n\
    }\n\nstruct Line {\n    Vec p1, p2;\n    Line() = default;\n    Line(const Vec&\
    \ p1, const Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2 - p1;\
    \ }\n};\n\nstruct Segment {\n    Vec p1, p2;\n    Segment() = default;\n    Segment(const\
    \ Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2\
    \ - p1; }\n};\n\nstruct Circle {\n    Vec c;\n    T r;\n    Circle() = default;\n\
    \    Circle(const Vec& c, T r) : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\
    \nT dot(const Vec& a, const Vec& b) {\n    return (std::conj(a) * b).real();\n\
    }\n\nT cross(const Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n\
    }\n\nVec rot(const Vec& a, T ang) {\n    return a * Vec(std::cos(ang), std::sin(ang));\n\
    }\n\nVec perp(const Vec& a) {\n    return Vec(-a.imag(), a.real());\n}\n\nVec\
    \ projection(const Line& l, const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir())\
    \ * l.dir() / std::norm(l.dir());\n}\n\nVec reflection(const Line& l, const Vec&\
    \ p) {\n    return T(2) * projection(l, p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n\
    // -1: clockwise\nint ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if\
    \ (eq(cross(b - a, c - a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0))\
    \ return -1;\n    return 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n\
    \    std::sort(pts.begin(), pts.end(), [&](auto& p, auto& q) {\n        if ((p.imag()\
    \ < 0) != (q.imag() < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0)\
    \ {\n            if (p == Vec(0, 0)) return !(q.imag() < 0 || (q.imag() == 0 &&\
    \ q.real() > 0));\n            if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag()\
    \ == 0 && p.real() > 0));\n            return (p.real() > q.real());\n       \
    \ }\n        return (cross(p, q) > 0);\n    });\n}\n#line 5 \"geometry/closest_pair.hpp\"\
    \n\n/**\n * @brief Closest Pair\n */\nT closest_pair(std::vector<Vec>& pts) {\n\
    \    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const Vec& v2) {\n  \
    \      return v1.real() < v2.real();\n    });\n\n    auto rec = [&](const auto&\
    \ rec, int l, int r) -> T {\n        if (r - l <= 1) return std::numeric_limits<T>::max();\n\
    \        int m = (l + r) / 2;\n        T x = pts[m].real();\n        T d = std::min(rec(rec,\
    \ l, m), rec(rec, m, r));\n        std::inplace_merge(pts.begin() + l, pts.begin()\
    \ + m, pts.begin() + r, [&](const Vec& v1, const Vec& v2) {\n            return\
    \ v1.imag() < v2.imag();\n        });\n        std::vector<Vec> b;\n        for\
    \ (int i = l; i < r; ++i) {\n            if (leq(d, std::abs(pts[i].real() - x)))\
    \ continue;\n            for (int j = (int) b.size() - 1; j >= 0; --j) {\n   \
    \             if (leq(d, std::abs(pts[i].imag() - b[j].imag()))) break;\n    \
    \            d = std::min(d, std::abs(pts[i] - b[j]));\n            }\n      \
    \      b.push_back(pts[i]);\n        }\n        return d;\n    };\n\n    return\
    \ rec(rec, 0, pts.size());\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"geometry.hpp\"\
    \n\n/**\n * @brief Closest Pair\n */\nT closest_pair(std::vector<Vec>& pts) {\n\
    \    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const Vec& v2) {\n  \
    \      return v1.real() < v2.real();\n    });\n\n    auto rec = [&](const auto&\
    \ rec, int l, int r) -> T {\n        if (r - l <= 1) return std::numeric_limits<T>::max();\n\
    \        int m = (l + r) / 2;\n        T x = pts[m].real();\n        T d = std::min(rec(rec,\
    \ l, m), rec(rec, m, r));\n        std::inplace_merge(pts.begin() + l, pts.begin()\
    \ + m, pts.begin() + r, [&](const Vec& v1, const Vec& v2) {\n            return\
    \ v1.imag() < v2.imag();\n        });\n        std::vector<Vec> b;\n        for\
    \ (int i = l; i < r; ++i) {\n            if (leq(d, std::abs(pts[i].real() - x)))\
    \ continue;\n            for (int j = (int) b.size() - 1; j >= 0; --j) {\n   \
    \             if (leq(d, std::abs(pts[i].imag() - b[j].imag()))) break;\n    \
    \            d = std::min(d, std::abs(pts[i] - b[j]));\n            }\n      \
    \      b.push_back(pts[i]);\n        }\n        return d;\n    };\n\n    return\
    \ rec(rec, 0, pts.size());\n}\n"
  dependsOn:
  - geometry/geometry.hpp
  isVerificationFile: false
  path: geometry/closest_pair.hpp
  requiredBy: []
  timestamp: '2022-06-27 13:45:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_5_A.test.cpp
documentation_of: geometry/closest_pair.hpp
layout: document
redirect_from:
- /library/geometry/closest_pair.hpp
- /library/geometry/closest_pair.hpp.html
title: Closest Pair
---
