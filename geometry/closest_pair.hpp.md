---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geometry/geometry.hpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/closest_pair.test.cpp
    title: test/yosupo/closest_pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Closest Pair
    links: []
  bundledCode: "#line 2 \"geometry/closest_pair.hpp\"\n#include <numeric>\n#include\
    \ <ranges>\n#include <vector>\n\n#line 2 \"geometry/geometry.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <complex>\n#include <iostream>\n\
    #include <numbers>\n#line 10 \"geometry/geometry.hpp\"\n\n// note that if T is\
    \ of an integer type, std::abs does not work\nusing T = double;\nusing Vec = std::complex<T>;\n\
    \nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y;\n    is >>\
    \ x >> y;\n    p = {x, y};\n    return is;\n}\n\nT dot(const Vec& a, const Vec&\
    \ b) { return (std::conj(a) * b).real(); }\n\nT cross(const Vec& a, const Vec&\
    \ b) { return (std::conj(a) * b).imag(); }\n\nconstexpr T PI = std::numbers::pi_v<T>;\n\
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
    \    std::ranges::sort(pts, [&](auto& p, auto& q) {\n        if ((p.imag() < 0)\
    \ != (q.imag() < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0) {\n\
    \            if (p == Vec(0, 0))\n                return !(q.imag() < 0 || (q.imag()\
    \ == 0 && q.real() > 0));\n            if (q == Vec(0, 0))\n                return\
    \ (p.imag() < 0 || (p.imag() == 0 && p.real() > 0));\n            return (p.real()\
    \ > q.real());\n        }\n        return (cross(p, q) > 0);\n    });\n}\n#line\
    \ 7 \"geometry/closest_pair.hpp\"\n\n/**\n * @brief Closest Pair\n */\nstd::tuple<T,\
    \ int, int> closest_pair(const std::vector<Vec>& pts_) {\n    std::vector<std::pair<Vec,\
    \ int>> pts;\n    for (int i = 0; i < (int)pts_.size(); ++i) pts.emplace_back(pts_[i],\
    \ i);\n    std::ranges::sort(pts, {}, [](const auto& v) { return v.first.real();\
    \ });\n\n    auto rec = [&](const auto& rec, int l, int r) -> std::tuple<T, int,\
    \ int> {\n        if (r - l <= 1) return {std::numeric_limits<T>::max(), -1, -1};\n\
    \        int m = std::midpoint(l, r);\n        T x = pts[m].first.real();\n  \
    \      auto closest = std::min(rec(rec, l, m), rec(rec, m, r));\n        std::ranges::inplace_merge(\n\
    \            pts.begin() + l, pts.begin() + m, pts.begin() + r, {},\n        \
    \    [](const auto& v) { return v.first.imag(); });\n        std::vector<std::pair<Vec,\
    \ int>> b;\n        for (int i = l; i < r; ++i) {\n            if (leq(std::get<0>(closest),\
    \ std::abs(pts[i].first.real() - x)))\n                continue;\n           \
    \ for (auto& p : b | std::views::reverse) {\n                if (leq(std::get<0>(closest),\n\
    \                        std::abs(pts[i].first.imag() - p.first.imag())))\n  \
    \                  break;\n                closest = std::min(closest, {std::abs(pts[i].first\
    \ - p.first),\n                                             pts[i].second, p.second});\n\
    \            }\n            b.push_back(pts[i]);\n        }\n        return closest;\n\
    \    };\n\n    return rec(rec, 0, pts.size());\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <ranges>\n#include <vector>\n\n\
    #include \"geometry.hpp\"\n\n/**\n * @brief Closest Pair\n */\nstd::tuple<T, int,\
    \ int> closest_pair(const std::vector<Vec>& pts_) {\n    std::vector<std::pair<Vec,\
    \ int>> pts;\n    for (int i = 0; i < (int)pts_.size(); ++i) pts.emplace_back(pts_[i],\
    \ i);\n    std::ranges::sort(pts, {}, [](const auto& v) { return v.first.real();\
    \ });\n\n    auto rec = [&](const auto& rec, int l, int r) -> std::tuple<T, int,\
    \ int> {\n        if (r - l <= 1) return {std::numeric_limits<T>::max(), -1, -1};\n\
    \        int m = std::midpoint(l, r);\n        T x = pts[m].first.real();\n  \
    \      auto closest = std::min(rec(rec, l, m), rec(rec, m, r));\n        std::ranges::inplace_merge(\n\
    \            pts.begin() + l, pts.begin() + m, pts.begin() + r, {},\n        \
    \    [](const auto& v) { return v.first.imag(); });\n        std::vector<std::pair<Vec,\
    \ int>> b;\n        for (int i = l; i < r; ++i) {\n            if (leq(std::get<0>(closest),\
    \ std::abs(pts[i].first.real() - x)))\n                continue;\n           \
    \ for (auto& p : b | std::views::reverse) {\n                if (leq(std::get<0>(closest),\n\
    \                        std::abs(pts[i].first.imag() - p.first.imag())))\n  \
    \                  break;\n                closest = std::min(closest, {std::abs(pts[i].first\
    \ - p.first),\n                                             pts[i].second, p.second});\n\
    \            }\n            b.push_back(pts[i]);\n        }\n        return closest;\n\
    \    };\n\n    return rec(rec, 0, pts.size());\n}"
  dependsOn:
  - geometry/geometry.hpp
  isVerificationFile: false
  path: geometry/closest_pair.hpp
  requiredBy: []
  timestamp: '2025-01-11 16:44:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/closest_pair.test.cpp
  - test/aoj/CGL_5_A.test.cpp
documentation_of: geometry/closest_pair.hpp
layout: document
redirect_from:
- /library/geometry/closest_pair.hpp
- /library/geometry/closest_pair.hpp.html
title: Closest Pair
---
