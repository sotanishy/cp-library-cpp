#pragma once
#include "geometry.hpp"
#include "intersect.hpp"
#include "intersection.hpp"

std::pair<Vec, Vec> tangent_points(const Circle& c, const Vec& p) {
    auto m = (p + c.c) / T(2);
    auto is = intersection(c, Circle(m, std::abs(p - m)));
    return {is[0], is[1]};
}

// for each l, l.p1 is a tangent point of c1
std::vector<Line> common_tangents(Circle c1, Circle c2) {
    assert(!eq(c1.c, c2.c) || !eq(c1.r, c2.r));
    int cnt = intersect(c1, c2);  // number of common tangents
    std::vector<Line> ret;
    if (cnt == 0) {
        return ret;
    }

    // external
    if (eq(c1.r, c2.r)) {
        auto d = c2.c - c1.c;
        Vec e(-d.imag(), d.real());
        e = e / std::abs(e) * c1.r;
        ret.push_back(Line(c1.c + e, c1.c + e + d));
        ret.push_back(Line(c1.c - e, c1.c - e + d));
    } else {
        auto p = (-c2.r * c1.c + c1.r * c2.c) / (c1.r - c2.r);
        if (cnt == 1) {
            Vec q(-p.imag(), p.real());
            return {Line(p, q)};
        } else {
            auto [a, b] = tangent_points(c1, p);
            ret.push_back(Line(a, p));
            ret.push_back(Line(b, p));
        }
    }

    // internal
    auto p = (c2.r * c1.c + c1.r * c2.c) / (c1.r + c2.r);
    if (cnt == 3) {
        Vec q(-p.imag(), p.real());
        ret.push_back(Line(p, q));
    } else if (cnt == 4) {
        auto [a, b] = tangent_points(c1, p);
        ret.push_back(Line(a, p));
        ret.push_back(Line(b, p));
    }

    return ret;
}
