#pragma once
#include "geometry.hpp"

bool intersect(const Segment& s, const Vec& p) {
    Vec u = s.p1 - p, v = s.p2 - p;
    return eq(cross(u, v), 0) && leq(dot(u, v), 0);
}

// 0: outside
// 1: on the border
// 2: inside
int intersect(const Polygon& poly, const Vec& p) {
    const int n = poly.size();
    bool in = 0;
    for (int i = 0; i < n; ++i) {
        auto a = poly[i] - p, b = poly[(i+1)%n] - p;
        if (eq(cross(a, b), 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0))) return 1;
        if (a.imag() > b.imag()) std::swap(a, b);
        if (leq(a.imag(), 0) && lt(0, b.imag()) && lt(cross(a, b), 0)) in ^= 1;
    }
    return in ? 2 : 0;
}

bool intersect(const Segment& s, const Segment& t) {
    auto a = s.p1, b = s.p2;
    auto c = t.p1, d = t.p2;
    if (ccw(a, b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b)) return 2;
    if (intersect(s, c) || intersect(s, d) || intersect(t, a) || intersect(t, b)) return 1;
    return 0;
}

// true if they have positive area in common or touch on the border
bool intersect(const Polygon& poly1, const Polygon& poly2) {
    const int n = poly1.size();
    const int m = poly2.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (intersect(Segment(poly1[i], poly1[(i+1)%n]), Segment(poly2[j], poly2[(j+1)%n]))) {
                return true;
            }
        }
    }
    return intersect(poly1, poly2[0]) || intersect(poly2, poly1[0]);
}

// 0: inside
// 1: inscribe
// 2: intersect
// 3: circumscribe
// 4: outside
int intersect(const Circle& c1, const Circle& c2) {
    T d = std::abs(c1.c - c2.c);
    if (lt(d, std::abs(c2.r - c1.r))) return 0;
    if (eq(d, std::abs(c2.r - c1.r))) return 1;
    if (eq(c1.r + c2.r, d)) return 3;
    if (lt(c1.r + c2.r, d)) return 4;
    return 2;
}
