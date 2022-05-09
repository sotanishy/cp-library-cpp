---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: 3D Geometry
    links: []
  bundledCode: "#line 2 \"geometry/geometry3d.hpp\"\n#include <cmath>\n#include <iostream>\n\
    \n/**\n * @brief 3D Geometry\n */\n// following structs and functions from the\
    \ 2d library also work for 3d without any modification\n// Line, Segment, Circle\
    \ (should be renamed \"Sphere\" for 3D)\n// projection, reflection, dist, centroid,\
    \ incenter\n\nusing T = double;\n\nstruct Vec {\n    T x, y, z;\n    Vec() = default;\n\
    \    constexpr Vec(T x, T y, T z) : x(x), y(y), z(z) {}\n    constexpr Vec& operator+=(const\
    \ Vec& r) { x += r.x; y += r.y; z += r.z; return *this; }\n    constexpr Vec&\
    \ operator-=(const Vec& r) { x -= r.x; y -= r.y; z -= r.z; return *this; }\n \
    \   constexpr Vec& operator*=(T r) { x *= r; y *= r; z *= r; return *this; }\n\
    \    constexpr Vec& operator/=(T r) { x /= r; y /= r; z /= r; return *this; }\n\
    \    constexpr Vec operator-() const { return Vec(-x, -y, -z); }\n    constexpr\
    \ Vec operator+(const Vec& r) const { return Vec(*this) += r; }\n    constexpr\
    \ Vec operator-(const Vec& r) const { return Vec(*this) -= r; }\n    constexpr\
    \ Vec operator*(T r) const { return Vec(*this) *= r; }\n    constexpr Vec operator/(T\
    \ r) const { return Vec(*this) /= r; }\n    friend constexpr Vec operator*(T r,\
    \ const Vec& v) { return v * r; }\n};\n\nstd::istream& operator>>(std::istream&\
    \ is, Vec& p) {\n    T x, y, z;\n    is >> x >> y >> z;\n    p = {x, y, z};\n\
    \    return is;\n}\n\nT dot(const Vec& a, const Vec& b) {\n    return a.x*b.x\
    \ + a.y*b.y + a.z*b.z;\n}\n\nVec cross(const Vec& a, const Vec& b) {\n    return\
    \ Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);\n}\n\nnamespace std\
    \ {\nT norm(const Vec& a) { return dot(a, a); }\nT abs(const Vec& a) { return\
    \ std::sqrt(std::norm(a)); }\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <iostream>\n\n/**\n * @brief 3D\
    \ Geometry\n */\n// following structs and functions from the 2d library also work\
    \ for 3d without any modification\n// Line, Segment, Circle (should be renamed\
    \ \"Sphere\" for 3D)\n// projection, reflection, dist, centroid, incenter\n\n\
    using T = double;\n\nstruct Vec {\n    T x, y, z;\n    Vec() = default;\n    constexpr\
    \ Vec(T x, T y, T z) : x(x), y(y), z(z) {}\n    constexpr Vec& operator+=(const\
    \ Vec& r) { x += r.x; y += r.y; z += r.z; return *this; }\n    constexpr Vec&\
    \ operator-=(const Vec& r) { x -= r.x; y -= r.y; z -= r.z; return *this; }\n \
    \   constexpr Vec& operator*=(T r) { x *= r; y *= r; z *= r; return *this; }\n\
    \    constexpr Vec& operator/=(T r) { x /= r; y /= r; z /= r; return *this; }\n\
    \    constexpr Vec operator-() const { return Vec(-x, -y, -z); }\n    constexpr\
    \ Vec operator+(const Vec& r) const { return Vec(*this) += r; }\n    constexpr\
    \ Vec operator-(const Vec& r) const { return Vec(*this) -= r; }\n    constexpr\
    \ Vec operator*(T r) const { return Vec(*this) *= r; }\n    constexpr Vec operator/(T\
    \ r) const { return Vec(*this) /= r; }\n    friend constexpr Vec operator*(T r,\
    \ const Vec& v) { return v * r; }\n};\n\nstd::istream& operator>>(std::istream&\
    \ is, Vec& p) {\n    T x, y, z;\n    is >> x >> y >> z;\n    p = {x, y, z};\n\
    \    return is;\n}\n\nT dot(const Vec& a, const Vec& b) {\n    return a.x*b.x\
    \ + a.y*b.y + a.z*b.z;\n}\n\nVec cross(const Vec& a, const Vec& b) {\n    return\
    \ Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);\n}\n\nnamespace std\
    \ {\nT norm(const Vec& a) { return dot(a, a); }\nT abs(const Vec& a) { return\
    \ std::sqrt(std::norm(a)); }\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry3d.hpp
  requiredBy: []
  timestamp: '2022-05-09 11:09:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry3d.hpp
layout: document
redirect_from:
- /library/geometry/geometry3d.hpp
- /library/geometry/geometry3d.hpp.html
title: 3D Geometry
---
