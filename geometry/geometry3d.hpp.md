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
    \ functions from the 2d library also work for 3d without\n// any modification:\n\
    // projection, reflection, dist, centroid, incenter\n\nusing T = double;\n\nstruct\
    \ Vec {\n    T x, y, z;\n    Vec() = default;\n    constexpr Vec(T x, T y, T z)\
    \ : x(x), y(y), z(z) {}\n    constexpr Vec& operator+=(const Vec& r) {\n     \
    \   x += r.x;\n        y += r.y;\n        z += r.z;\n        return *this;\n \
    \   }\n    constexpr Vec& operator-=(const Vec& r) {\n        x -= r.x;\n    \
    \    y -= r.y;\n        z -= r.z;\n        return *this;\n    }\n    constexpr\
    \ Vec& operator*=(T r) {\n        x *= r;\n        y *= r;\n        z *= r;\n\
    \        return *this;\n    }\n    constexpr Vec& operator/=(T r) {\n        x\
    \ /= r;\n        y /= r;\n        z /= r;\n        return *this;\n    }\n    constexpr\
    \ Vec operator-() const { return Vec(-x, -y, -z); }\n    constexpr Vec operator+(const\
    \ Vec& r) const { return Vec(*this) += r; }\n    constexpr Vec operator-(const\
    \ Vec& r) const { return Vec(*this) -= r; }\n    constexpr Vec operator*(T r)\
    \ const { return Vec(*this) *= r; }\n    constexpr Vec operator/(T r) const {\
    \ return Vec(*this) /= r; }\n    friend constexpr Vec operator*(T r, const Vec&\
    \ v) { return v * r; }\n};\n\n// rotation around n=(x,y,z) by theta: cos(theta/2)\
    \ + (xi+yj+zk) sin(theta/2)\nstruct Quarternion {\n    T x, y, z, w;\n    Quarternion()\
    \ = default;\n    constexpr Quarternion(T x, T y, T z, T w) : x(x), y(y), z(z),\
    \ w(w) {}\n    constexpr Quarternion conj() const { return Quarternion(-x, -y,\
    \ -z, w); }\n    constexpr Quarternion& operator+=(const Quarternion& r) {\n \
    \       x += r.x;\n        y += r.y;\n        z += r.z;\n        w += r.w;\n \
    \       return *this;\n    }\n    constexpr Quarternion& operator-=(const Quarternion&\
    \ r) {\n        x -= r.x;\n        y -= r.y;\n        z -= r.z;\n        w -=\
    \ r.w;\n        return *this;\n    }\n    constexpr Quarternion& operator*=(const\
    \ Quarternion& r) {\n        *this = Quarternion(w * r.x - z * r.y + y * r.z +\
    \ x * r.w,\n                            z * r.x + w * r.y - x * r.z + y * r.w,\n\
    \                            -y * r.x + x * r.y + w * r.z + z * r.w,\n       \
    \                     -x * r.x - y * r.y - z * r.z + w * r.w);\n        return\
    \ *this;\n    }\n    constexpr Quarternion& operator*=(T r) {\n        x *= r;\n\
    \        y *= r;\n        z *= r;\n        w *= r;\n        return *this;\n  \
    \  }\n    constexpr Quarternion& operator/=(T r) {\n        x /= r;\n        y\
    \ /= r;\n        z /= r;\n        w /= r;\n        return *this;\n    }\n    constexpr\
    \ Quarternion operator-() const {\n        return Quarternion(-x, -y, -z, -w);\n\
    \    }\n    constexpr Quarternion operator+(const Quarternion& r) const {\n  \
    \      return Quarternion(*this) += r;\n    }\n    constexpr Quarternion operator-(const\
    \ Quarternion& r) const {\n        return Quarternion(*this) -= r;\n    }\n  \
    \  constexpr Quarternion operator*(const Quarternion& r) const {\n        return\
    \ Quarternion(*this) *= r;\n    }\n    constexpr Quarternion operator*(T r) const\
    \ {\n        return Quarternion(*this) *= r;\n    }\n    constexpr Quarternion\
    \ operator/(T r) const {\n        return Quarternion(*this) /= r;\n    }\n};\n\
    \nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y, z;\n    is\
    \ >> x >> y >> z;\n    p = {x, y, z};\n    return is;\n}\n\nstd::ostream& operator<<(std::ostream&\
    \ os, const Vec& p) {\n    os << \"(\" << p.x << \", \" << p.y << \", \" << p.z\
    \ << \")\";\n    return os;\n}\n\nT dot(const Vec& a, const Vec& b) { return a.x\
    \ * b.x + a.y * b.y + a.z * b.z; }\n\nVec cross(const Vec& a, const Vec& b) {\n\
    \    return Vec(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,\n              \
    \ a.x * b.y - a.y * b.x);\n}\n\nnamespace std {\nT norm(const Vec& a) { return\
    \ dot(a, a); }\nT abs(const Vec& a) { return std::sqrt(std::norm(a)); }\n}  //\
    \ namespace std\n\nconstexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return\
    \ std::abs(a - b) <= eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a\
    \ - b) <= eps; }\ninline bool lt(T a, T b) { return a < b - eps; }\ninline bool\
    \ leq(T a, T b) { return a <= b + eps; }\n\nstruct Line {\n    Vec p1, p2;\n \
    \   Line() = default;\n    Line(const Vec& p1, const Vec& p2) : p1(p1), p2(p2)\
    \ {}\n    Vec dir() const { return p2 - p1; }\n};\n\nstruct Segment : Line {\n\
    \    using Line::Line;\n};\n\nstruct Plane {\n    Vec n, p;\n    Plane() = default;\n\
    \    Plane(const Vec& n, const Vec& p) : n(n), p(p) {}\n};\n\nstruct Sphere {\n\
    \    Vec c;\n    T r;\n    Sphere() = default;\n    Sphere(const Vec& c, T r)\
    \ : c(c), r(r) {}\n};\n\nVec rot(const Vec& v, const Quarternion& q) {\n    auto\
    \ u = q * Quarternion(v.x, v.y, v.z, 0) * q.conj();\n    return {u.x, u.y, u.z};\n\
    }\n\n// get the rotation that moves a to b\nQuarternion get_rotation(const Vec&\
    \ a, const Vec& b) {\n    assert(eq(std::abs(a), 1));\n    assert(eq(std::abs(b),\
    \ 1));\n\n    T theta = std::acos(dot(a, b));\n    Vec n = cross(a, b);\n    n\
    \ /= std::abs(n);\n    T c = std::cos(theta / 2);\n    T s = std::sin(theta /\
    \ 2);\n    return Quarternion(s * n.x, s * n.y, s * n.z, c);\n}\n\nbool are_collinear(const\
    \ Vec& p1, const Vec& p2, const Vec& p3) {\n    return eq(std::norm(cross(p2 -\
    \ p1, p3 - p1)), 0);\n}\n\nbool are_coplanar(const Vec& p1, const Vec& p2, const\
    \ Vec& p3, const Vec& p4) {\n    return eq(dot(cross(p2 - p1, p4 - p1), p3 - p1),\
    \ 0);\n}\n\n// --- intersect ---\n\n// 0: skew\n// 1: parallel\n// 2: intersect\n\
    int intersect(const Line& l, const Line& m) {\n    if (!are_coplanar(l.p1, l.p2,\
    \ m.p1, m.p2)) return 0;\n    if (eq(std::norm(cross(l.dir(), m.dir())), 0)) return\
    \ 1;\n    return 2;\n}\n\nbool intersect(const Plane& pl, const Line& l) {\n \
    \   return !eq(dot(pl.n, l.dir()), 0);\n}\n\n// --- intersection ---\n\nVec intersection(const\
    \ Line& l, const Line& m) {\n    assert(intersect(l, m) == 2);\n\n    auto r =\
    \ m.p1 - l.p1;\n    auto dlr = dot(l.dir(), r);\n    auto dmr = dot(m.dir(), r);\n\
    \    auto dlm = dot(l.dir(), m.dir());\n    auto dll = std::norm(l.dir());\n \
    \   auto dmm = std::norm(m.dir());\n\n    auto t = (dlr * dmm - dmr * dlm) / (dll\
    \ * dmm - dlm * dlm);\n    return l.p1 + t * l.dir();\n}\n\nVec intersection(const\
    \ Plane& pl, const Line& l) {\n    assert(intersect(pl, l));\n    auto dir = l.dir();\n\
    \    auto d = dot(pl.p - l.p1, pl.n) / dot(dir, pl.n);\n    return l.p1 + d *\
    \ dir;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n#include <iostream>\n\
    \n/**\n * @brief 3D Geometry\n */\n// following functions from the 2d library\
    \ also work for 3d without\n// any modification:\n// projection, reflection, dist,\
    \ centroid, incenter\n\nusing T = double;\n\nstruct Vec {\n    T x, y, z;\n  \
    \  Vec() = default;\n    constexpr Vec(T x, T y, T z) : x(x), y(y), z(z) {}\n\
    \    constexpr Vec& operator+=(const Vec& r) {\n        x += r.x;\n        y +=\
    \ r.y;\n        z += r.z;\n        return *this;\n    }\n    constexpr Vec& operator-=(const\
    \ Vec& r) {\n        x -= r.x;\n        y -= r.y;\n        z -= r.z;\n       \
    \ return *this;\n    }\n    constexpr Vec& operator*=(T r) {\n        x *= r;\n\
    \        y *= r;\n        z *= r;\n        return *this;\n    }\n    constexpr\
    \ Vec& operator/=(T r) {\n        x /= r;\n        y /= r;\n        z /= r;\n\
    \        return *this;\n    }\n    constexpr Vec operator-() const { return Vec(-x,\
    \ -y, -z); }\n    constexpr Vec operator+(const Vec& r) const { return Vec(*this)\
    \ += r; }\n    constexpr Vec operator-(const Vec& r) const { return Vec(*this)\
    \ -= r; }\n    constexpr Vec operator*(T r) const { return Vec(*this) *= r; }\n\
    \    constexpr Vec operator/(T r) const { return Vec(*this) /= r; }\n    friend\
    \ constexpr Vec operator*(T r, const Vec& v) { return v * r; }\n};\n\n// rotation\
    \ around n=(x,y,z) by theta: cos(theta/2) + (xi+yj+zk) sin(theta/2)\nstruct Quarternion\
    \ {\n    T x, y, z, w;\n    Quarternion() = default;\n    constexpr Quarternion(T\
    \ x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}\n    constexpr Quarternion conj()\
    \ const { return Quarternion(-x, -y, -z, w); }\n    constexpr Quarternion& operator+=(const\
    \ Quarternion& r) {\n        x += r.x;\n        y += r.y;\n        z += r.z;\n\
    \        w += r.w;\n        return *this;\n    }\n    constexpr Quarternion& operator-=(const\
    \ Quarternion& r) {\n        x -= r.x;\n        y -= r.y;\n        z -= r.z;\n\
    \        w -= r.w;\n        return *this;\n    }\n    constexpr Quarternion& operator*=(const\
    \ Quarternion& r) {\n        *this = Quarternion(w * r.x - z * r.y + y * r.z +\
    \ x * r.w,\n                            z * r.x + w * r.y - x * r.z + y * r.w,\n\
    \                            -y * r.x + x * r.y + w * r.z + z * r.w,\n       \
    \                     -x * r.x - y * r.y - z * r.z + w * r.w);\n        return\
    \ *this;\n    }\n    constexpr Quarternion& operator*=(T r) {\n        x *= r;\n\
    \        y *= r;\n        z *= r;\n        w *= r;\n        return *this;\n  \
    \  }\n    constexpr Quarternion& operator/=(T r) {\n        x /= r;\n        y\
    \ /= r;\n        z /= r;\n        w /= r;\n        return *this;\n    }\n    constexpr\
    \ Quarternion operator-() const {\n        return Quarternion(-x, -y, -z, -w);\n\
    \    }\n    constexpr Quarternion operator+(const Quarternion& r) const {\n  \
    \      return Quarternion(*this) += r;\n    }\n    constexpr Quarternion operator-(const\
    \ Quarternion& r) const {\n        return Quarternion(*this) -= r;\n    }\n  \
    \  constexpr Quarternion operator*(const Quarternion& r) const {\n        return\
    \ Quarternion(*this) *= r;\n    }\n    constexpr Quarternion operator*(T r) const\
    \ {\n        return Quarternion(*this) *= r;\n    }\n    constexpr Quarternion\
    \ operator/(T r) const {\n        return Quarternion(*this) /= r;\n    }\n};\n\
    \nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y, z;\n    is\
    \ >> x >> y >> z;\n    p = {x, y, z};\n    return is;\n}\n\nstd::ostream& operator<<(std::ostream&\
    \ os, const Vec& p) {\n    os << \"(\" << p.x << \", \" << p.y << \", \" << p.z\
    \ << \")\";\n    return os;\n}\n\nT dot(const Vec& a, const Vec& b) { return a.x\
    \ * b.x + a.y * b.y + a.z * b.z; }\n\nVec cross(const Vec& a, const Vec& b) {\n\
    \    return Vec(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,\n              \
    \ a.x * b.y - a.y * b.x);\n}\n\nnamespace std {\nT norm(const Vec& a) { return\
    \ dot(a, a); }\nT abs(const Vec& a) { return std::sqrt(std::norm(a)); }\n}  //\
    \ namespace std\n\nconstexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return\
    \ std::abs(a - b) <= eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a\
    \ - b) <= eps; }\ninline bool lt(T a, T b) { return a < b - eps; }\ninline bool\
    \ leq(T a, T b) { return a <= b + eps; }\n\nstruct Line {\n    Vec p1, p2;\n \
    \   Line() = default;\n    Line(const Vec& p1, const Vec& p2) : p1(p1), p2(p2)\
    \ {}\n    Vec dir() const { return p2 - p1; }\n};\n\nstruct Segment : Line {\n\
    \    using Line::Line;\n};\n\nstruct Plane {\n    Vec n, p;\n    Plane() = default;\n\
    \    Plane(const Vec& n, const Vec& p) : n(n), p(p) {}\n};\n\nstruct Sphere {\n\
    \    Vec c;\n    T r;\n    Sphere() = default;\n    Sphere(const Vec& c, T r)\
    \ : c(c), r(r) {}\n};\n\nVec rot(const Vec& v, const Quarternion& q) {\n    auto\
    \ u = q * Quarternion(v.x, v.y, v.z, 0) * q.conj();\n    return {u.x, u.y, u.z};\n\
    }\n\n// get the rotation that moves a to b\nQuarternion get_rotation(const Vec&\
    \ a, const Vec& b) {\n    assert(eq(std::abs(a), 1));\n    assert(eq(std::abs(b),\
    \ 1));\n\n    T theta = std::acos(dot(a, b));\n    Vec n = cross(a, b);\n    n\
    \ /= std::abs(n);\n    T c = std::cos(theta / 2);\n    T s = std::sin(theta /\
    \ 2);\n    return Quarternion(s * n.x, s * n.y, s * n.z, c);\n}\n\nbool are_collinear(const\
    \ Vec& p1, const Vec& p2, const Vec& p3) {\n    return eq(std::norm(cross(p2 -\
    \ p1, p3 - p1)), 0);\n}\n\nbool are_coplanar(const Vec& p1, const Vec& p2, const\
    \ Vec& p3, const Vec& p4) {\n    return eq(dot(cross(p2 - p1, p4 - p1), p3 - p1),\
    \ 0);\n}\n\n// --- intersect ---\n\n// 0: skew\n// 1: parallel\n// 2: intersect\n\
    int intersect(const Line& l, const Line& m) {\n    if (!are_coplanar(l.p1, l.p2,\
    \ m.p1, m.p2)) return 0;\n    if (eq(std::norm(cross(l.dir(), m.dir())), 0)) return\
    \ 1;\n    return 2;\n}\n\nbool intersect(const Plane& pl, const Line& l) {\n \
    \   return !eq(dot(pl.n, l.dir()), 0);\n}\n\n// --- intersection ---\n\nVec intersection(const\
    \ Line& l, const Line& m) {\n    assert(intersect(l, m) == 2);\n\n    auto r =\
    \ m.p1 - l.p1;\n    auto dlr = dot(l.dir(), r);\n    auto dmr = dot(m.dir(), r);\n\
    \    auto dlm = dot(l.dir(), m.dir());\n    auto dll = std::norm(l.dir());\n \
    \   auto dmm = std::norm(m.dir());\n\n    auto t = (dlr * dmm - dmr * dlm) / (dll\
    \ * dmm - dlm * dlm);\n    return l.p1 + t * l.dir();\n}\n\nVec intersection(const\
    \ Plane& pl, const Line& l) {\n    assert(intersect(pl, l));\n    auto dir = l.dir();\n\
    \    auto d = dot(pl.p - l.p1, pl.n) / dot(dir, pl.n);\n    return l.p1 + d *\
    \ dir;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry3d.hpp
  requiredBy: []
  timestamp: '2023-05-14 13:38:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry3d.hpp
layout: document
redirect_from:
- /library/geometry/geometry3d.hpp
- /library/geometry/geometry3d.hpp.html
title: 3D Geometry
---
