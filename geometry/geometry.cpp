#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

// note that if T is of an integer type, std::abs does not work
using T = double;
using Vec = std::complex<T>;

constexpr T eps = 1e-12;
inline bool eq(T a, T b) { return std::abs(a - b) < eps; }
inline bool lt(T a, T b) { return a < b - eps; }
inline bool leq(T a, T b) { return a < b + eps; }

std::istream& operator>>(std::istream& is, Vec& p) {
    T x, y;
    is >> x >> y;
    p = {x, y};
    return is;
}

T dot(const Vec& a, const Vec& b) {
    return (std::conj(a) * b).real();
}

T cross(const Vec& a, const Vec& b) {
    return (std::conj(a) * b).imag();
}

Vec rot(const Vec& a, T ang) {
    return a * Vec(std::cos(ang), std::sin(ang));
}

Vec projection(const Vec& a, const Vec& b, const Vec& c) {
    return a + dot(b - a, c - a) * (b - a) / std::norm(b - a);
}

Vec reflection(const Vec& a, const Vec& b, const Vec& c) {
    return T(2) * projection(a, b, c) - c;
}

int ccw(const Vec& a, const Vec& b, const Vec& c) {
    if (eq(cross(b - a, c - a), 0)) return 0;  // collinear
    if (lt(cross(b - a, c - a), 0)) return -1;  // clockwise
    return 1;  // counter clockwise
}

bool on_segment(const Vec& a, const Vec& b, const Vec& c) {
    Vec u = a - c, v = b - c;
    return eq(cross(u, v), 0) && leq(dot(u, v), 0);
}

bool intersect_segments(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {
    if (ccw(a, c, d) != ccw(b, c, d) && ccw(a, b, c) != ccw(a, b, d)) return true;
    if (on_segment(a, b, c) || on_segment(c, d, a) || on_segment(c, d, a) || on_segment(c, d, b)) return true;
    return false;
}

T dist_line_point(const Vec& a, const Vec& b, const Vec& c) {
    return std::abs(cross(b - a, c - a)) / std::abs(b - a);
}

T dist_segment_point(const Vec& a, const Vec& b, const Vec& c) {
    if (lt(dot(b - a, c - a), 0)) return std::abs(c - a);
    if (lt(dot(a - b, c - b), 0)) return std::abs(c - b);
    return std::abs(cross(b - a, c - a)) / std::abs(b - a);
}

T dist_segments(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {
    if (intersect_segments(a, b, c, d)) return T(0);
    return std::min(
        std::min(dist_segment_point(a, b, c), dist_segment_point(a, b, d)),
        std::min(dist_segment_point(c, d, a), dist_segment_point(c, d, b))
    );
}

Vec intersection_lines(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {
    Vec p = b - a;
    Vec q = d - c;
    Vec r = c - a;
    assert(!eq(cross(q, p), 0)); // not parallel
    return a + cross(q, r) / cross(q, p) * p;
}

std::vector<Vec> intersection_circle_line(const Vec& c, T r, const Vec& a, const Vec& b) {
    T d = dist_line_point(a, b, c);
    if (lt(r, d)) return {};  // no intersection
    Vec e1 = (b - a) / std::abs(b - a);
    Vec e2 = Vec(-e1.imag(), e1.real());
    if (ccw(c, a, b) == 1) e2 *= -1;
    if (eq(r, d)) return {c + d*e2};  // tangent
    T t = std::sqrt(r*r - d*d);
    return {c + d*e2 + t*e1, c + d*e2 - t*e1};
}

std::vector<Vec> intersection_circles(const Vec& c1, T r1, const Vec& c2, T r2) {
    T d = std::abs(c1 - c2);
    if (lt(r1 + r2, d)) return {};  // outside
    Vec e1 = (c2 - c1) / std::abs(c2 - c1);
    Vec e2 = Vec(-e1.imag(), e1.real());
    if (lt(d, std::abs(r2 - r1))) return {};  // contain
    if (eq(d, std::abs(r2 - r1))) return {c1 + r1*e1};  // tangent
    T x = (r1*r1 - r2*r2 + d*d) / (2*d);
    T y = std::sqrt(r1*r1 - x*x);
    return {c1 + x*e1 + y*e2, c1 + x*e1 - y*e2};
}

T area(const std::vector<Vec>& pts) {
    int n = pts.size();
    T res = 0;
    for (int i = 0; i < n; ++i) {
        res += cross(pts[i], pts[(i + 1) % n]);
    }
    return std::abs(res) / T(2);
}

bool is_convex(const std::vector<Vec>& pts) {
    int n = pts.size();
    for (int i = 0; i < n; ++i) {
        if (lt(cross(pts[(i+1)%n] - pts[i], pts[(i+2)%n] - pts[(i+1)%n]), 0)) {
            return false;
        }
    }
    return true;
}

int contains(const std::vector<Vec>& pts, const Vec& q) {
    int n = pts.size();
    bool in = 0;
    for (int i = 0; i < n; ++i) {
        auto a = pts[i] - q, b = pts[(i+1)%n] - q;
        if (eq(cross(a, b), 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0))) return 1;
        if (a.imag() > b.imag()) std::swap(a, b);
        if (leq(a.imag(), 0) && lt(0, b.imag()) && lt(cross(a, b), 0)) in ^= 1;
    }
    return in ? 2 : 0;
}

Vec centroid(const Vec& A, const Vec& B, const Vec& C) {
    assert(ccw(A, B, C) != 0);
    return (A + B + C) / T(3);
}

Vec incenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(ccw(A, B, C) != 0);
    T a = std::abs(B - C);
    T b = std::abs(C - A);
    T c = std::abs(A - B);
    return (a*A + b*B + c*C) / (a + b + c);
}

Vec circumcenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(ccw(A, B, C) != 0);
    auto p = B - A, q = C - A;
    return A + intersection_lines(p/T(2), p/T(2) + Vec(-p.imag(), p.real()),
                                  q/T(2), q/T(2) + Vec(-q.imag(), q.real()));
}

// large error but beautiful
// Vec circumcenter(const Vec& A, const Vec& B, const Vec& C) {
//     assert(ccw(A, B, C) != 0);
//     Vec p = C - B, q = A - C, r = B - A;
//     T a = std::norm(p) * dot(q, r);
//     T b = std::norm(q) * dot(r, p);
//     T c = std::norm(r) * dot(p, q);
//     return (a*A + b*B + c*C) / (a + b + c);
// }

std::vector<Vec> convex_hull(std::vector<Vec>& pts) {
    int n = pts.size();
    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const Vec& v2) {
        return (v1.imag() != v2.imag()) ? (v1.imag() < v2.imag()) : (v1.real() < v2.real());
    });
    int k = 0; // the number of vertices in the convex hull
    std::vector<Vec> ch(2 * n);
    // right
    for (int i = 0; i < n; ++i) {
        while (k > 1 && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]), 0)) --k;
        ch[k++] = pts[i];
    }
    int t = k;
    // left
    for (int i = n - 2; i >= 0; --i) {
        while (k > t && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]), 0)) --k;
        ch[k++] = pts[i];
    }
    ch.resize(k - 1);
    return ch;
}

T closest_pair(std::vector<Vec>& pts) {
    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const Vec& v2) {
        return v1.real() < v2.real();
    });

    auto rec = [&](const auto& rec, int l, int r) -> T {
        if (r - l <= 1) return std::numeric_limits<T>::max();
        int m = (l + r) / 2;
        T x = pts[m].real();
        T d = std::min(rec(rec, l, m), rec(rec, m, r));
        std::inplace_merge(pts.begin() + l, pts.begin() + m, pts.begin() + r, [&](const Vec& v1, const Vec& v2) {
            return v1.imag() < v2.imag();
        });
        std::vector<Vec> b;
        for (int i = l; i < r; ++i) {
            if (leq(d, std::abs(pts[i].real() - x))) continue;
            for (int j = (int) b.size() - 1; j >= 0; --j) {
                if (leq(d, std::abs(pts[i].imag() - b[j].imag()))) break;
                d = std::min(d, std::abs(pts[i] - b[j]));
            }
            b.push_back(pts[i]);
        }
        return d;
    };

    return rec(rec, 0, pts.size());
}


/*
// for 3d geometry
// functions that will work without any modifications
// projection, reflection, dist_line_point, dist_segment_point, dist_segments,
// centroid, incenter

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

*/