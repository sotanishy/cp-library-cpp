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
  bundledCode: "#line 2 \"geometry/geometry3d.hpp\"\n#include <cassert>\n#include\
    \ <cmath>\n#include <iostream>\n\n/**\n * @brief 3D Geometry\n */\n// following\
    \ structs and functions from the 2d library also work for 3d without any modification\n\
    // Line, Segment, Circle (should be renamed \"Sphere\" for 3D)\n// projection,\
    \ reflection, dist, centroid, incenter\n\nusing T = double;\n\nstruct Vec {\n\
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
    \ r; }\n};\n\nstruct Quarternion {\n    T x, y, z, w;\n    Quarternion() = default;\n\
    \    constexpr Quarternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}\n \
    \   constexpr Quarternion conj() const { return Quarternion(-x, -y, -z, w); }\n\
    \    constexpr Quarternion& operator+=(const Quarternion& r) { x += r.x; y +=\
    \ r.y; z += r.z; w += r.w; return *this; }\n    constexpr Quarternion& operator-=(const\
    \ Quarternion& r) { x -= r.x; y -= r.y; z -= r.z; w -= r.w; return *this; }\n\
    \    constexpr Quarternion& operator*=(const Quarternion& r) {\n        *this\
    \ = Quarternion(\n             w*r.x - z*r.y + y*r.z + x*r.w,\n             z*r.x\
    \ + w*r.y - x*r.z + y*r.w,\n            -y*r.x + x*r.y + w*r.z + z*r.w,\n    \
    \        -x*r.x - y*r.y - z*r.z + w*r.w\n        );\n        return *this;\n \
    \   }\n    constexpr Quarternion& operator*=(T r) { x *= r; y *= r; z *= r; w\
    \ *= r; return *this; }\n    constexpr Quarternion& operator/=(T r) { x /= r;\
    \ y /= r; z /= r; w /= r; return *this; }\n    constexpr Quarternion operator-()\
    \ const { return Quarternion(-x, -y, -z, -w); }\n    constexpr Quarternion operator+(const\
    \ Quarternion& r) const { return Quarternion(*this) += r; }\n    constexpr Quarternion\
    \ operator-(const Quarternion& r) const { return Quarternion(*this) -= r; }\n\
    \    constexpr Quarternion operator*(const Quarternion& r) const { return Quarternion(*this)\
    \ *= r; }\n    constexpr Quarternion operator*(T r) const { return Quarternion(*this)\
    \ *= r; }\n    constexpr Quarternion operator/(T r) const { return Quarternion(*this)\
    \ /= r; }\n};\n\nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x,\
    \ y, z;\n    is >> x >> y >> z;\n    p = {x, y, z};\n    return is;\n}\n\nT dot(const\
    \ Vec& a, const Vec& b) {\n    return a.x*b.x + a.y*b.y + a.z*b.z;\n}\n\nVec cross(const\
    \ Vec& a, const Vec& b) {\n    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);\n\
    }\n\nVec rot(const Vec& v, const Quarternion& q) {\n    auto u = q * Quarternion(v.x,\
    \ v.y, v.z, 0) * q.conj();\n    return {u.x, u.y, u.z};\n}\n\nnamespace std {\n\
    T norm(const Vec& a) { return dot(a, a); }\nT abs(const Vec& a) { return std::sqrt(std::norm(a));\
    \ }\n}\n\nconstexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return std::abs(a\
    \ - b) <= eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps;\
    \ }\ninline bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T\
    \ b) { return a <= b + eps; }\n\nQuarternion get_rotation(const Vec& a, const\
    \ Vec& b) {\n    assert(eq(std::abs(a), 1));\n    assert(eq(std::abs(b), 1));\n\
    \n    T theta = std::acos(dot(a, b));\n    Vec n = cross(a, b);\n    n /= std::abs(n);\n\
    \    T c = std::cos(theta/2);\n    T s = std::sin(theta/2);\n    return Quarternion(s*n.x,\
    \ s*n.y, s*n.z, c);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n#include <iostream>\n\
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
    \ const Vec& v) { return v * r; }\n};\n\nstruct Quarternion {\n    T x, y, z,\
    \ w;\n    Quarternion() = default;\n    constexpr Quarternion(T x, T y, T z, T\
    \ w) : x(x), y(y), z(z), w(w) {}\n    constexpr Quarternion conj() const { return\
    \ Quarternion(-x, -y, -z, w); }\n    constexpr Quarternion& operator+=(const Quarternion&\
    \ r) { x += r.x; y += r.y; z += r.z; w += r.w; return *this; }\n    constexpr\
    \ Quarternion& operator-=(const Quarternion& r) { x -= r.x; y -= r.y; z -= r.z;\
    \ w -= r.w; return *this; }\n    constexpr Quarternion& operator*=(const Quarternion&\
    \ r) {\n        *this = Quarternion(\n             w*r.x - z*r.y + y*r.z + x*r.w,\n\
    \             z*r.x + w*r.y - x*r.z + y*r.w,\n            -y*r.x + x*r.y + w*r.z\
    \ + z*r.w,\n            -x*r.x - y*r.y - z*r.z + w*r.w\n        );\n        return\
    \ *this;\n    }\n    constexpr Quarternion& operator*=(T r) { x *= r; y *= r;\
    \ z *= r; w *= r; return *this; }\n    constexpr Quarternion& operator/=(T r)\
    \ { x /= r; y /= r; z /= r; w /= r; return *this; }\n    constexpr Quarternion\
    \ operator-() const { return Quarternion(-x, -y, -z, -w); }\n    constexpr Quarternion\
    \ operator+(const Quarternion& r) const { return Quarternion(*this) += r; }\n\
    \    constexpr Quarternion operator-(const Quarternion& r) const { return Quarternion(*this)\
    \ -= r; }\n    constexpr Quarternion operator*(const Quarternion& r) const { return\
    \ Quarternion(*this) *= r; }\n    constexpr Quarternion operator*(T r) const {\
    \ return Quarternion(*this) *= r; }\n    constexpr Quarternion operator/(T r)\
    \ const { return Quarternion(*this) /= r; }\n};\n\nstd::istream& operator>>(std::istream&\
    \ is, Vec& p) {\n    T x, y, z;\n    is >> x >> y >> z;\n    p = {x, y, z};\n\
    \    return is;\n}\n\nT dot(const Vec& a, const Vec& b) {\n    return a.x*b.x\
    \ + a.y*b.y + a.z*b.z;\n}\n\nVec cross(const Vec& a, const Vec& b) {\n    return\
    \ Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);\n}\n\nVec rot(const\
    \ Vec& v, const Quarternion& q) {\n    auto u = q * Quarternion(v.x, v.y, v.z,\
    \ 0) * q.conj();\n    return {u.x, u.y, u.z};\n}\n\nnamespace std {\nT norm(const\
    \ Vec& a) { return dot(a, a); }\nT abs(const Vec& a) { return std::sqrt(std::norm(a));\
    \ }\n}\n\nconstexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return std::abs(a\
    \ - b) <= eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps;\
    \ }\ninline bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T\
    \ b) { return a <= b + eps; }\n\nQuarternion get_rotation(const Vec& a, const\
    \ Vec& b) {\n    assert(eq(std::abs(a), 1));\n    assert(eq(std::abs(b), 1));\n\
    \n    T theta = std::acos(dot(a, b));\n    Vec n = cross(a, b);\n    n /= std::abs(n);\n\
    \    T c = std::cos(theta/2);\n    T s = std::sin(theta/2);\n    return Quarternion(s*n.x,\
    \ s*n.y, s*n.z, c);\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry3d.hpp
  requiredBy: []
  timestamp: '2022-11-22 17:45:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry3d.hpp
layout: document
redirect_from:
- /library/geometry/geometry3d.hpp
- /library/geometry/geometry3d.hpp.html
title: 3D Geometry
---
