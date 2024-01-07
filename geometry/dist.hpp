#pragma once
#include "geometry.hpp"
#include "intersect.hpp"

T dist(const Line& l, const Vec& p) {
    return std::abs(cross(p - l.p1, l.dir())) / std::abs(l.dir());
}

T dist(const Segment& s, const Vec& p) {
    if (lt(dot(p - s.p1, s.dir()), 0)) return std::abs(p - s.p1);
    if (lt(dot(p - s.p2, -s.dir()), 0)) return std::abs(p - s.p2);
    return std::abs(cross(p - s.p1, s.dir())) / std::abs(s.dir());
}

T dist(const Segment& s, const Segment& t) {
    if (intersect(s, t)) return T(0);
    return std::min(
        {dist(s, t.p1), dist(s, t.p2), dist(t, s.p1), dist(t, s.p2)});
}
