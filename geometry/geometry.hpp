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

const T PI = std::acos(-1);

constexpr T eps = 1e-12;
inline bool eq(T a, T b) { return std::abs(a - b) < eps; }
inline bool eq(Vec a, Vec b) { return std::abs(a - b) < eps; }
inline bool lt(T a, T b) { return a < b - eps; }
inline bool leq(T a, T b) { return a < b + eps; }

std::istream& operator>>(std::istream& is, Vec& p) {
    T x, y;
    is >> x >> y;
    p = {x, y};
    return is;
}

struct Line {
    Vec p1, p2;
    Line() = default;
    Line(const Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}
    Vec dir() const { return p2 - p1; }
};

struct Segment {
    Vec p1, p2;
    Segment() = default;
    Segment(const Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}
    Vec dir() const { return p2 - p1; }
};

struct Circle {
    Vec c;
    T r;
    Circle() = default;
    Circle(const Vec& c, T r) : c(c), r(r) {}
};

using Polygon = std::vector<Vec>;

T dot(const Vec& a, const Vec& b) {
    return (std::conj(a) * b).real();
}

T cross(const Vec& a, const Vec& b) {
    return (std::conj(a) * b).imag();
}

Vec rot(const Vec& a, T ang) {
    return a * Vec(std::cos(ang), std::sin(ang));
}

Vec projection(const Line& l, const Vec& p) {
    return l.p1 + dot(p - l.p1, l.dir()) * l.dir() / std::norm(l.dir());
}

Vec reflection(const Line& l, const Vec& p) {
    return T(2) * projection(l, p) - p;
}

// 0: collinear
// 1: counter-clockwise
// -1: clockwise
int ccw(const Vec& a, const Vec& b, const Vec& c) {
    if (eq(cross(b - a, c - a), 0)) return 0;
    if (lt(cross(b - a, c - a), 0)) return -1;
    return 1;
}

Line bisector(const Vec& p, const Vec& q) {
    auto m = (p + q) / T(2);
    auto v = q - p;
    return Line(m, m + Vec(-v.imag(), v.real()));
}

void sort_by_arg(std::vector<Vec>& pts) {
    std::sort(pts.begin(), pts.end(), [&](auto& p, auto& q) {
        if ((p.imag() < 0) != (q.imag() < 0)) return (p.imag() < 0);
        if (cross(p, q) == 0) {
            if (p == Vec(0, 0)) return !(q.imag() < 0 || (q.imag() == 0 && q.real() > 0));
            if (q == Vec(0, 0)) return  (p.imag() < 0 || (p.imag() == 0 && p.real() > 0));
            return (p.real() > q.real());
        }
        return (cross(p, q) > 0);
    });
}