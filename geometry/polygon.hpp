#pragma once
#include "geometry.hpp"
#include "intersection.hpp"

T area(const Polygon& poly) {
    const int n = poly.size();
    T res = 0;
    for (int i = 0; i < n; ++i) {
        res += cross(poly[i], poly[(i + 1) % n]);
    }
    return std::abs(res) / T(2);
}

bool is_convex(const Polygon& poly) {
    int n = poly.size();
    for (int i = 0; i < n; ++i) {
        if (lt(cross(poly[(i+1)%n] - poly[i], poly[(i+2)%n] - poly[(i+1)%n]), 0)) {
            return false;
        }
    }
    return true;
}

std::vector<Vec> convex_cut(const Polygon& poly, const Line& l) {
    const int n = poly.size();
    std::vector<Vec> res;
    for (int i = 0; i < n; ++i) {
        auto p = poly[i], q = poly[(i+1)%n];
        if (ccw(l.p1, l.p2, p) != -1) {
            if (res.empty() || !eq(res.back(), p)) {
                res.push_back(p);
            }
        }
        if (ccw(l.p1, l.p2, p) * ccw(l.p1, l.p2, q) < 0) {
            auto c = intersection(Line(p, q), l);
            if (res.empty() || !eq(res.back(), c)) {
                res.push_back(c);
            }
        }
    }
    return res;
}
