#pragma once
#include "geometry.hpp"
#include "intersection.hpp"
#include "bisector.hpp"

Vec centroid(const Vec& A, const Vec& B, const Vec& C) {
    assert(ccw(A, B, C) != 0);
    return (A + B + C) / T(3);
}

Vec incenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(ccw(A, B, C) != 0);
    T a = std::abs(B - C);
    T b = std::abs(C - A);
    T c = std::abs(A - B);
    return (a*A + b*B + c*C) / (a + b + c);
}

Vec circumcenter(const Vec& A, const Vec& B, const Vec& C) {
    assert(ccw(A, B, C) != 0);
    return intersection(bisector(Segment(A, B)), bisector(Segment(A, C)));
}

// large error but beautiful
// Vec circumcenter(const Vec& A, const Vec& B, const Vec& C) {
//     assert(ccw(A, B, C) != 0);
//     Vec p = C - B, q = A - C, r = B - A;
//     T a = std::norm(p) * dot(q, r);
//     T b = std::norm(q) * dot(r, p);
//     T c = std::norm(r) * dot(p, q);
//     return (a*A + b*B + c*C) / (a + b + c);
// }

