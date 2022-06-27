#pragma once
#include "geometry.hpp"
#include "intersection.hpp"

Line bisector(const Segment& s) {
    auto m = (s.p1 + s.p2) / T(2);
    return Line(m, m + Vec(-s.dir().imag(), s.dir().real()));
}

std::pair<Line, Line> bisector(const Line& l, const Line& m) {
    // parallel
    if (eq(cross(l.dir(), m.dir()), 0)) {
        auto n = Line(l.p1, l.p1 + perp(l.dir()));
        auto p = intersection(n, m);
        auto m = (l.p1 + p) / T(2);
        return {Line(m, m + l.dir()), Line()};
    }
    auto p = intersection(l, m);
    T ang = (std::arg(l.dir()) + std::arg(m.dir())) / T(2);
    auto b1 = Line(p, p + std::polar(T(1), ang));
    auto b2 = Line(p, p + std::polar(T(1), ang + PI / T(2)));
    return {b1, b2};
}
