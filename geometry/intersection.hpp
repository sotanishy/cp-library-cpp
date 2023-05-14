#pragma once
#include "dist.hpp"
#include "geometry.hpp"

Vec intersection(const Line& l, const Line& m) {
    assert(!eq(cross(l.dir(), m.dir()), 0));  // not parallel
    Vec r = m.p1 - l.p1;
    return l.p1 + cross(m.dir(), r) / cross(m.dir(), l.dir()) * l.dir();
}

std::vector<Vec> intersection(const Circle& c, const Line& l) {
    T d = dist(l, c.c);
    if (lt(c.r, d)) return {};  // no intersection
    Vec e1 = l.dir() / std::abs(l.dir());
    Vec e2 = perp(e1);
    if (ccw(c.c, l.p1, l.p2) == 1) e2 *= -1;
    if (eq(c.r, d)) return {c.c + d * e2};  // tangent
    T t = std::sqrt(c.r * c.r - d * d);
    return {c.c + d * e2 + t * e1, c.c + d * e2 - t * e1};
}

std::vector<Vec> intersection(const Circle& c1, const Circle& c2) {
    T d = std::abs(c1.c - c2.c);
    if (lt(c1.r + c2.r, d)) return {};  // outside
    Vec e1 = (c2.c - c1.c) / std::abs(c2.c - c1.c);
    Vec e2 = perp(e1);
    if (lt(d, std::abs(c2.r - c1.r))) return {};                  // contain
    if (eq(d, std::abs(c2.r - c1.r))) return {c1.c + c1.r * e1};  // tangent
    T x = (c1.r * c1.r - c2.r * c2.r + d * d) / (2 * d);
    T y = std::sqrt(c1.r * c1.r - x * x);
    return {c1.c + x * e1 + y * e2, c1.c + x * e1 - y * e2};
}

T area_intersection(const Circle& c1, const Circle& c2) {
    T d = std::abs(c2.c - c1.c);
    if (leq(c1.r + c2.r, d)) return 0;    // outside
    if (leq(d, std::abs(c2.r - c1.r))) {  // inside
        T r = std::min(c1.r, c2.r);
        return PI * r * r;
    }
    T ans = 0;
    T a;
    a = std::acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    ans += c1.r * c1.r * (a - std::sin(a) * std::cos(a));
    a = std::acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));
    ans += c2.r * c2.r * (a - std::sin(a) * std::cos(a));
    return ans;
}
