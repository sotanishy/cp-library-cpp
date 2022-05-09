#pragma once
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

namespace std {
T norm(const Vec& a) { return dot(a, a); }
T abs(const Vec& a) { return std::sqrt(std::norm(a)); }
}