#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

constexpr double eps = 1e-12;

inline bool eq(double a, double b) { return std::abs(a - b) < eps; }
inline bool lt(double a, double b) { return a < b - eps; }
inline bool leq(double a, double b) { return a < b + eps; }

using Vec = std::complex<double>;

double dot(const Vec& a, const Vec& b) {
    return (std::conj(a) * b).real();
}

double cross(const Vec& a, const Vec& b) {
    return (std::conj(a) * b).imag();
}

Vec rot(const Vec& a, double ang) {
    return a * Vec(std::cos(ang), std::sin(ang));
}

bool are_colinear(const Vec& p1, const Vec& p2, const Vec& p3) {
    return eq(cross(p2 - p1, p3 - p1), 0);
}

bool ccw(const Vec& a, const Vec& b, const Vec& c) {
    return !lt(std::arg((c - a) / (b - a)), 0);
}

bool intersect(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {
    return ccw(a, c, d) != ccw(b, c, d) && ccw(a, b, c) != ccw(a, b, d);
}

bool on_segment(const Vec& p1, const Vec& p2, const Vec& q) {
    Vec v1 = p1 - q, v2 = p2 - q;
    return eq(cross(v1, v2), 0) && lt(dot(v1, v2), 0);
}

double line_point_dist(const Vec& p1, const Vec& p2, const Vec& q) {
    Vec p = p2 - p1;
    return std::abs(cross(q, p) + cross(p2, p1)) / std::abs(p);
}

Vec intersection(const Vec& p1, const Vec& p2, const Vec& q1, const Vec& q2) {
    Vec p = p2 - p1;
    Vec q = q2 - q1;
    Vec r = q1 - p1;
    assert(!eq(cross(q, p), 0)); // not parallel
    return p1 + cross(q, r) / cross(q, p) * p;
}

// returns a list of the intersections of two circles
std::vector<Vec> intersection_circles(const Vec& c1, double r1, const Vec& c2, double r2) {
    double d = std::abs(c1 - c2);
    // if the circles are outside of each other
    if (lt(r1 + r2, d)) return {};
    // if one contains the other entirely
    if (lt(d, std::abs(r2 - r1))) return {};
    double x = (r1*r1 - r2*r2 + d*d) / (2*d);
    double y = std::sqrt(r1*r1 - x*x);
    Vec e1 = (c2 - c1) / std::abs(c2 - c1);
    Vec e2 = Vec(-e1.imag(), e1.real());
    return {c1 + x*e1 + y*e2, c1 + x*e1 - y*e2};
}

// returns a list of the intersections of a circle and a line
std::vector<Vec> intersection_circle_line(const Vec& c, double r, const Vec& p1, const Vec& p2) {
    double d = line_point_dist(p1, p2, c);
    // no intersection
    if (lt(r, d)) return {};
    Vec e1 = (p2 - p1) / std::abs(p2 - p1);
    Vec e2 = Vec(-e1.imag(), e1.real());
    double t = std::sqrt(r*r - d*d);
    if (eq(d, 0)) return {c + t*e1, c - t*e1};
    if (ccw(c, p1, p2)) e2 *= -1;
    if (eq(r, d)) return {c + d*e2};
    return {c + d*e2 + t*e1, c + d*e2 - t*e1};
}

double area(const Vec& A, const Vec& B, const Vec& C) {
    return std::abs(cross(B - A, C - A)) / 2.0;
}

Vec centroid(const Vec& A, const Vec& B, const Vec& C) {
    assert(!are_colinear(A, B, C));
    return (A + B + C) / 3.0;
}

Vec circumcenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(!are_colinear(A, B, C));
    double a = std::abs(B - C);
    double b = std::abs(C - A);
    double c = std::abs(A - B);
    double cosA = (b*b + c*c - a*a) / (2*b*c);
    double cosB = (c*c + a*a - b*b) / (2*c*a);
    double cosC = (a*a + b*b - c*c) / (2*a*b);
    return (a*cosA*A + b*cosB*B + c*cosC*C) / (a*cosA + b*cosB + c*cosC);
}

Vec incenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(!are_colinear(A, B, C));
    double a = std::abs(B - C);
    double b = std::abs(C - A);
    double c = std::abs(A - B);
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