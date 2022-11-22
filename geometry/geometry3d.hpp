#pragma once
#include <cassert>
#include <cmath>
#include <iostream>

/**
 * @brief 3D Geometry
 */
// following structs and functions from the 2d library also work for 3d without any modification
// Line, Segment, Circle (should be renamed "Sphere" for 3D)
// projection, reflection, dist, centroid, incenter

using T = double;

struct Vec {
    T x, y, z;
    Vec() = default;
    constexpr Vec(T x, T y, T z) : x(x), y(y), z(z) {}
    constexpr Vec& operator+=(const Vec& r) { x += r.x; y += r.y; z += r.z; return *this; }
    constexpr Vec& operator-=(const Vec& r) { x -= r.x; y -= r.y; z -= r.z; return *this; }
    constexpr Vec& operator*=(T r) { x *= r; y *= r; z *= r; return *this; }
    constexpr Vec& operator/=(T r) { x /= r; y /= r; z /= r; return *this; }
    constexpr Vec operator-() const { return Vec(-x, -y, -z); }
    constexpr Vec operator+(const Vec& r) const { return Vec(*this) += r; }
    constexpr Vec operator-(const Vec& r) const { return Vec(*this) -= r; }
    constexpr Vec operator*(T r) const { return Vec(*this) *= r; }
    constexpr Vec operator/(T r) const { return Vec(*this) /= r; }
    friend constexpr Vec operator*(T r, const Vec& v) { return v * r; }
};

struct Quarternion {
    T x, y, z, w;
    Quarternion() = default;
    constexpr Quarternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
    constexpr Quarternion conj() const { return Quarternion(-x, -y, -z, w); }
    constexpr Quarternion& operator+=(const Quarternion& r) { x += r.x; y += r.y; z += r.z; w += r.w; return *this; }
    constexpr Quarternion& operator-=(const Quarternion& r) { x -= r.x; y -= r.y; z -= r.z; w -= r.w; return *this; }
    constexpr Quarternion& operator*=(const Quarternion& r) {
        *this = Quarternion(
             w*r.x - z*r.y + y*r.z + x*r.w,
             z*r.x + w*r.y - x*r.z + y*r.w,
            -y*r.x + x*r.y + w*r.z + z*r.w,
            -x*r.x - y*r.y - z*r.z + w*r.w
        );
        return *this;
    }
    constexpr Quarternion& operator*=(T r) { x *= r; y *= r; z *= r; w *= r; return *this; }
    constexpr Quarternion& operator/=(T r) { x /= r; y /= r; z /= r; w /= r; return *this; }
    constexpr Quarternion operator-() const { return Quarternion(-x, -y, -z, -w); }
    constexpr Quarternion operator+(const Quarternion& r) const { return Quarternion(*this) += r; }
    constexpr Quarternion operator-(const Quarternion& r) const { return Quarternion(*this) -= r; }
    constexpr Quarternion operator*(const Quarternion& r) const { return Quarternion(*this) *= r; }
    constexpr Quarternion operator*(T r) const { return Quarternion(*this) *= r; }
    constexpr Quarternion operator/(T r) const { return Quarternion(*this) /= r; }
};

std::istream& operator>>(std::istream& is, Vec& p) {
    T x, y, z;
    is >> x >> y >> z;
    p = {x, y, z};
    return is;
}

T dot(const Vec& a, const Vec& b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec cross(const Vec& a, const Vec& b) {
    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

Vec rot(const Vec& v, const Quarternion& q) {
    auto u = q * Quarternion(v.x, v.y, v.z, 0) * q.conj();
    return {u.x, u.y, u.z};
}

namespace std {
T norm(const Vec& a) { return dot(a, a); }
T abs(const Vec& a) { return std::sqrt(std::norm(a)); }
}

constexpr T eps = 1e-10;
inline bool eq(T a, T b) { return std::abs(a - b) <= eps; }
inline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }
inline bool lt(T a, T b) { return a < b - eps; }
inline bool leq(T a, T b) { return a <= b + eps; }

Quarternion get_rotation(const Vec& a, const Vec& b) {
    assert(eq(std::abs(a), 1));
    assert(eq(std::abs(b), 1));

    T theta = std::acos(dot(a, b));
    Vec n = cross(a, b);
    n /= std::abs(n);
    T c = std::cos(theta/2);
    T s = std::sin(theta/2);
    return Quarternion(s*n.x, s*n.y, s*n.z, c);
}