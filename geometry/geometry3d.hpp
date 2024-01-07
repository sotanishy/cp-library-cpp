#pragma once
#include <cassert>
#include <cmath>
#include <iostream>

/**
 * @brief 3D Geometry
 */
// following functions from the 2d library also work for 3d without
// any modification:
// projection, reflection, dist, centroid, incenter

using T = double;

struct Vec {
    T x, y, z;
    Vec() = default;
    constexpr Vec(T x, T y, T z) : x(x), y(y), z(z) {}
    constexpr Vec& operator+=(const Vec& r) {
        x += r.x;
        y += r.y;
        z += r.z;
        return *this;
    }
    constexpr Vec& operator-=(const Vec& r) {
        x -= r.x;
        y -= r.y;
        z -= r.z;
        return *this;
    }
    constexpr Vec& operator*=(T r) {
        x *= r;
        y *= r;
        z *= r;
        return *this;
    }
    constexpr Vec& operator/=(T r) {
        x /= r;
        y /= r;
        z /= r;
        return *this;
    }
    constexpr Vec operator+() const { return *this; }
    constexpr Vec operator-() const { return Vec(-x, -y, -z); }
    constexpr Vec operator+(const Vec& r) const { return Vec(*this) += r; }
    constexpr Vec operator-(const Vec& r) const { return Vec(*this) -= r; }
    constexpr Vec operator*(T r) const { return Vec(*this) *= r; }
    constexpr Vec operator/(T r) const { return Vec(*this) /= r; }
    friend constexpr Vec operator*(T r, const Vec& v) { return v * r; }

    friend std::istream& operator>>(std::istream& is, Vec& p) {
        T x, y, z;
        is >> x >> y >> z;
        p = {x, y, z};
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec& p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    }
};

// rotation around n=(x,y,z) by theta: cos(theta/2) + (xi+yj+zk) sin(theta/2)
struct Quarternion {
    T x, y, z, w;
    Quarternion() = default;
    constexpr Quarternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
    constexpr Quarternion conj() const { return Quarternion(-x, -y, -z, w); }
    constexpr Quarternion& operator+=(const Quarternion& r) {
        x += r.x;
        y += r.y;
        z += r.z;
        w += r.w;
        return *this;
    }
    constexpr Quarternion& operator-=(const Quarternion& r) {
        x -= r.x;
        y -= r.y;
        z -= r.z;
        w -= r.w;
        return *this;
    }
    constexpr Quarternion& operator*=(const Quarternion& r) {
        *this = Quarternion(w * r.x - z * r.y + y * r.z + x * r.w,
                            z * r.x + w * r.y - x * r.z + y * r.w,
                            -y * r.x + x * r.y + w * r.z + z * r.w,
                            -x * r.x - y * r.y - z * r.z + w * r.w);
        return *this;
    }
    constexpr Quarternion& operator*=(T r) {
        x *= r;
        y *= r;
        z *= r;
        w *= r;
        return *this;
    }
    constexpr Quarternion& operator/=(T r) {
        x /= r;
        y /= r;
        z /= r;
        w /= r;
        return *this;
    }
    constexpr Quarternion operator+() const { return *this; }
    constexpr Quarternion operator-() const {
        return Quarternion(-x, -y, -z, -w);
    }
    constexpr Quarternion operator+(const Quarternion& r) const {
        return Quarternion(*this) += r;
    }
    constexpr Quarternion operator-(const Quarternion& r) const {
        return Quarternion(*this) -= r;
    }
    constexpr Quarternion operator*(const Quarternion& r) const {
        return Quarternion(*this) *= r;
    }
    constexpr Quarternion operator*(T r) const {
        return Quarternion(*this) *= r;
    }
    constexpr Quarternion operator/(T r) const {
        return Quarternion(*this) /= r;
    }
};

T dot(const Vec& a, const Vec& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

Vec cross(const Vec& a, const Vec& b) {
    return Vec(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
               a.x * b.y - a.y * b.x);
}

namespace std {
T norm(const Vec& a) { return dot(a, a); }
T abs(const Vec& a) { return std::sqrt(std::norm(a)); }
}  // namespace std

constexpr T eps = 1e-10;
inline bool eq(T a, T b) { return std::abs(a - b) <= eps; }
inline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }
inline bool lt(T a, T b) { return a < b - eps; }
inline bool leq(T a, T b) { return a <= b + eps; }

struct Line {
    Vec p1, p2;
    Line() = default;
    Line(const Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}
    Vec dir() const { return p2 - p1; }
};

struct Segment : Line {
    using Line::Line;
};

struct Plane {
    Vec n, p;
    Plane() = default;
    Plane(const Vec& n, const Vec& p) : n(n), p(p) {}
};

struct Sphere {
    Vec c;
    T r;
    Sphere() = default;
    Sphere(const Vec& c, T r) : c(c), r(r) {}
};

Vec rot(const Vec& v, const Quarternion& q) {
    auto u = q * Quarternion(v.x, v.y, v.z, 0) * q.conj();
    return {u.x, u.y, u.z};
}

// get the rotation that moves a to b
Quarternion get_rotation(const Vec& a, const Vec& b) {
    assert(eq(std::abs(a), 1));
    assert(eq(std::abs(b), 1));

    T theta = std::acos(dot(a, b));
    Vec n = cross(a, b);
    n /= std::abs(n);
    T c = std::cos(theta / 2);
    T s = std::sin(theta / 2);
    return Quarternion(s * n.x, s * n.y, s * n.z, c);
}

bool are_collinear(const Vec& p1, const Vec& p2, const Vec& p3) {
    return eq(std::norm(cross(p2 - p1, p3 - p1)), 0);
}

bool are_coplanar(const Vec& p1, const Vec& p2, const Vec& p3, const Vec& p4) {
    return eq(dot(cross(p2 - p1, p4 - p1), p3 - p1), 0);
}

// --- intersect ---

// 0: skew
// 1: parallel
// 2: intersect
int intersect(const Line& l, const Line& m) {
    if (!are_coplanar(l.p1, l.p2, m.p1, m.p2)) return 0;
    if (eq(std::norm(cross(l.dir(), m.dir())), 0)) return 1;
    return 2;
}

bool intersect(const Plane& pl, const Line& l) {
    return !eq(dot(pl.n, l.dir()), 0);
}

// --- intersection ---

Vec intersection(const Line& l, const Line& m) {
    assert(intersect(l, m) == 2);

    auto r = m.p1 - l.p1;
    auto dlr = dot(l.dir(), r);
    auto dmr = dot(m.dir(), r);
    auto dlm = dot(l.dir(), m.dir());
    auto dll = std::norm(l.dir());
    auto dmm = std::norm(m.dir());

    auto t = (dlr * dmm - dmr * dlm) / (dll * dmm - dlm * dlm);
    return l.p1 + t * l.dir();
}

Vec intersection(const Plane& pl, const Line& l) {
    assert(intersect(pl, l));
    auto dir = l.dir();
    auto d = dot(pl.p - l.p1, pl.n) / dot(dir, pl.n);
    return l.p1 + d * dir;
}