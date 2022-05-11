#pragma once
#include <random>
#include <vector>
#include "geometry.hpp"
#include "triangle.hpp"

Circle minimum_bounding_circle(std::vector<Vec> pts) {
    std::random_device rd;
    std::mt19937_64 rng(rd());
    std::shuffle(pts.begin(), pts.end(), rng);

    std::vector<Vec> boundary;

    auto trivial = [&]() {
        if (boundary.size() == 0) {
            return Circle(Vec(0, 0), 0);
        } else if (boundary.size() ==  1) {
            return Circle(boundary[0], 0);
        }
        Vec c;
        if (boundary.size() == 2) {
            c = (boundary[0] + boundary[1]) / T(2);
        } else {
            c = circumcenter(boundary[0], boundary[1], boundary[2]);
        }
        return Circle(c, std::abs(boundary[0] - c));
    };

    auto rec = [&](auto& rec, int n) -> Circle {
        if (n == 0 || boundary.size() == 3) {
            return trivial();
        }
        auto c = rec(rec, n - 1);
        auto p = pts[n - 1];
        if (leq(std::abs(p - c.c), c.r)) {
            return c;
        }
        boundary.push_back(p);
        c = rec(rec, n - 1);
        boundary.pop_back();
        return c;
    };

    return rec(rec, pts.size());
}