#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

namespace geometry {

using T = double;
using Vec = std::complex<T>;

// note that if T is of an integer type, std::abs does not work

constexpr T eps = 1e-12;
inline bool eq(T a, T b) { return std::abs(a - b) < eps; }
inline bool lt(T a, T b) { return a < b - eps; }
inline bool leq(T a, T b) { return a < b + eps; }

inline bool eq(long long a, long long b) { return a == b; }
inline bool lt(long long a, long long b) { return a < b; }
inline bool leq(long long a, long long b) { return a <= b; }

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

bool are_colinear(const Vec& a, const Vec& b, const Vec& c) {
    return eq(cross(b - a, c - a), 0);
}

bool ccw(const Vec& a, const Vec& b, const Vec& c) {
    return lt(-cross(b - a, c - a), 0);
}

bool intersect(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {
    return ccw(a, c, d) != ccw(b, c, d) && ccw(a, b, c) != ccw(a, b, d);
}

bool on_segment(const Vec& a, const Vec& b, const Vec& p) {
    Vec u = a - p, v = b - p;
    return eq(cross(u, v), 0) && lt(dot(u, v), 0);
}

T line_point_dist(const Vec& a, const Vec& b, const Vec& p) {
    const T l2 = std::norm(b - a);
    const T t = dot(p - a, b - a) / l2;
    const Vec q = a + t * (b - a);
    return std::abs(p - q);
}

T segment_point_distance(const Vec& a, const Vec& b, const Vec& p) {
    const T l2 = std::norm(b - a);
    const T t = std::max(T(0), std::min(T(1), dot(p - a, b - a) / l2));
    const Vec q = a + t * (b - a);
    return std::abs(p - q);
}

Vec intersection(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {
    Vec p = b - a;
    Vec q = d - c;
    Vec r = c - a;
    assert(!eq(cross(q, p), 0)); // not parallel
    return a + cross(q, r) / cross(q, p) * p;
}

std::vector<Vec> intersection_circles(const Vec& c1, T r1, const Vec& c2, T r2) {
    T d = std::abs(c1 - c2);
    // if the circles are outside of each other
    if (lt(r1 + r2, d)) return {};
    // if one contains the other entirely
    if (lt(d, std::abs(r2 - r1))) return {};
    T x = (r1*r1 - r2*r2 + d*d) / (2*d);
    T y = std::sqrt(r1*r1 - x*x);
    Vec e1 = (c2 - c1) / std::abs(c2 - c1);
    Vec e2 = Vec(-e1.imag(), e1.real());
    return {c1 + x*e1 + y*e2, c1 + x*e1 - y*e2};
}

std::vector<Vec> intersection_circle_line(const Vec& c, T r, const Vec& p1, const Vec& p2) {
    T d = line_point_dist(p1, p2, c);
    // no intersection
    if (lt(r, d)) return {};
    Vec e1 = (p2 - p1) / std::abs(p2 - p1);
    Vec e2 = Vec(-e1.imag(), e1.real());
    T t = std::sqrt(r*r - d*d);
    if (eq(d, 0)) return {c + t*e1, c - t*e1};
    if (ccw(c, p1, p2)) e2 *= -1;
    if (eq(r, d)) return {c + d*e2};
    return {c + d*e2 + t*e1, c + d*e2 - t*e1};
}

T area(const Vec& A, const Vec& B, const Vec& C) {
    return std::abs(cross(B - A, C - A)) / T(2);
}

Vec centroid(const Vec& A, const Vec& B, const Vec& C) {
    assert(!are_colinear(A, B, C));
    return (A + B + C) / T(3);
}

Vec circumcenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(!are_colinear(A, B, C));
    T a = std::abs(B - C);
    T b = std::abs(C - A);
    T c = std::abs(A - B);
    T cosA = (b*b + c*c - a*a) / (2*b*c);
    T cosB = (c*c + a*a - b*b) / (2*c*a);
    T cosC = (a*a + b*b - c*c) / (2*a*b);
    return (a*cosA*A + b*cosB*B + c*cosC*C) / (a*cosA + b*cosB + c*cosC);
}

Vec incenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(!are_colinear(A, B, C));
    T a = std::abs(B - C);
    T b = std::abs(C - A);
    T c = std::abs(A - B);
    return (a*A + b*B + c*C) / (a + b + c);
}

std::vector<Vec> convex_hull(std::vector<Vec>& points) {
    int n = points.size();
    std::sort(points.begin(), points.end(), [](const Vec& v1, const Vec& v2) {
        return (v1.imag() != v2.imag()) ? (v1.imag() < v2.imag()) : (v1.real() < v2.real());
    });
    int k = 0; // the number of vertices in the convex hull
    std::vector<Vec> ch(2 * n);
    // right
    for (int i = 0; i < n; ++i) {
        while (k > 1 && lt(cross(ch[k-1] - ch[k-2], points[i] - ch[k-1]), 0)) --k;
        ch[k++] = points[i];
    }
    int t = k;
    // left
    for (int i = n - 2; i >= 0; --i) {
        while (k > t && lt(cross(ch[k-1] - ch[k-2], points[i] - ch[k-1]), 0)) --k;
        ch[k++] = points[i];
    }
    ch.resize(k - 1);
    return ch;
}

} // namespace geometry