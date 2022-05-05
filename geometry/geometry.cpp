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
// 2: clockwise
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
    return std::min({dist(s, t.p1), dist(s, t.p2), dist(t, s.p1), dist(t, s.p2)});
}

Vec intersection(const Line& l, const Line& m) {
    Vec r = m.p1 - l.p1;
    assert(!eq(cross(l.dir(), m.dir()), 0)); // not parallel
    return l.p1 + cross(m.dir(), r) / cross(m.dir(), l.dir()) * l.dir();
}

std::vector<Vec> intersection(const Circle& c, const Line& l) {
    T d = dist(l, c.c);
    if (lt(c.r, d)) return {};  // no intersection
    Vec e1 = l.dir() / std::abs(l.dir());
    Vec e2 = Vec(-e1.imag(), e1.real());
    if (ccw(c.c, l.p1, l.p2) == 1) e2 *= -1;
    if (eq(c.r, d)) return {c.c + d*e2};  // tangent
    T t = std::sqrt(c.r*c.r - d*d);
    return {c.c + d*e2 + t*e1, c.c + d*e2 - t*e1};
}

std::vector<Vec> intersection(const Circle& c1, const Circle& c2) {
    T d = std::abs(c1.c - c2.c);
    if (lt(c1.r + c2.r, d)) return {};  // outside
    Vec e1 = (c2.c - c1.c) / std::abs(c2.c - c1.c);
    Vec e2 = Vec(-e1.imag(), e1.real());
    if (lt(d, std::abs(c2.r - c1.r))) return {};  // contain
    if (eq(d, std::abs(c2.r - c1.r))) return {c1.c + c1.r*e1};  // tangent
    T x = (c1.r*c1.r - c2.r*c2.r + d*d) / (2*d);
    T y = std::sqrt(c1.r*c1.r - x*x);
    return {c1.c + x*e1 + y*e2, c1.c + x*e1 - y*e2};
}

T area(const Polygon& poly) {
    const int n = poly.size();
    T res = 0;
    for (int i = 0; i < n; ++i) {
        res += cross(poly[i], poly[(i + 1) % n]);
    }
    return std::abs(res) / T(2);
}

T area_intersection(const Circle& c1, const Circle& c2) {
    T d = std::abs(c2.c - c1.c);
    if (leq(c1.r + c2.r, d)) return 0;  // outside
    if (leq(d, std::abs(c2.r - c1.r))) {  // inside
        T r = std::min(c1.r, c2.r);
        return PI * r * r;
    }
    T ans = 0;
    T a;
    a = std::acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    ans += c1.r*c1.r*(a - std::sin(a)*std::cos(a));
    a = std::acos((c2.r*c2.r+d*d-c1.r*c1.r)/(2*c2.r*d));
    ans += c2.r*c2.r*(a - std::sin(a)*std::cos(a));
    return ans;
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
    return intersection(bisector(A, B), bisector(A, C));
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
        auto p = (-c2.r*c1.c + c1.r*c2.c) / (c1.r - c2.r);
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
    auto p = (c2.r*c1.c + c1.r*c2.c) / (c1.r + c2.r);
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

std::vector<Vec> convex_hull(std::vector<Vec>& pts) {
    int n = pts.size();
    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const Vec& v2) {
        return (v1.imag() != v2.imag()) ? (v1.imag() < v2.imag()) : (v1.real() < v2.real());
    });
    int k = 0; // the number of vertices in the convex hull
    std::vector<Vec> ch(2 * n);
    // right
    for (int i = 0; i < n; ++i) {
        while (k > 1 && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]), 0)) --k;
        ch[k++] = pts[i];
    }
    int t = k;
    // left
    for (int i = n - 2; i >= 0; --i) {
        while (k > t && lt(cross(ch[k-1] - ch[k-2], pts[i] - ch[k-1]), 0)) --k;
        ch[k++] = pts[i];
    }
    ch.resize(k - 1);
    return ch;
}

T closest_pair(std::vector<Vec>& pts) {
    std::sort(pts.begin(), pts.end(), [](const Vec& v1, const Vec& v2) {
        return v1.real() < v2.real();
    });

    auto rec = [&](const auto& rec, int l, int r) -> T {
        if (r - l <= 1) return std::numeric_limits<T>::max();
        int m = (l + r) / 2;
        T x = pts[m].real();
        T d = std::min(rec(rec, l, m), rec(rec, m, r));
        std::inplace_merge(pts.begin() + l, pts.begin() + m, pts.begin() + r, [&](const Vec& v1, const Vec& v2) {
            return v1.imag() < v2.imag();
        });
        std::vector<Vec> b;
        for (int i = l; i < r; ++i) {
            if (leq(d, std::abs(pts[i].real() - x))) continue;
            for (int j = (int) b.size() - 1; j >= 0; --j) {
                if (leq(d, std::abs(pts[i].imag() - b[j].imag()))) break;
                d = std::min(d, std::abs(pts[i] - b[j]));
            }
            b.push_back(pts[i]);
        }
        return d;
    };

    return rec(rec, 0, pts.size());
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

/*
// for 3d geometry
// functions that will work without any modifications
// projection, reflection, dist
// centroid, incenter

struct Vec {
    T x, y, z;
    Vec() = default;
    constexpr Vec(T x, T y, T z) : x(x), y(y), z(z) {}
    constexpr Vec& operator+=(const Vec& r) { x += r.x; y += r.y; z += r.z; return *this; }
    constexpr Vec& operator-=(const Vec& r) { x -= r.x; y -= r.y; z -= r.z; return *this; }
    constexpr Vec& operator*=(T r) { x *= r; y *= r; z *= r; return *this; }
    constexpr Vec& operator/=(T r) { x /= r; y /= r; z /= r; return *this; }
    constexpr Vec operator-() const { return Vec(-x, -y, -z); }
    constexpr Vec operator+(const Vec& r) const { return Vec(*this) += r; }
    constexpr Vec operator-(const Vec& r) const { return Vec(*this) -= r; }
    constexpr Vec operator*(T r) const { return Vec(*this) *= r; }
    constexpr Vec operator/(T r) const { return Vec(*this) /= r; }
    friend constexpr Vec operator*(T r, const Vec& v) { return v * r; }
};

std::istream& operator>>(std::istream& is, Vec& p) {
    T x, y, z;
    is >> x >> y >> z;
    p = {x, y, z};
    return is;
}

T dot(const Vec& a, const Vec& b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

Vec cross(const Vec& a, const Vec& b) {
    return Vec(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

namespace std {
T norm(const Vec& a) { return dot(a, a); }
T abs(const Vec& a) { return std::sqrt(std::norm(a)); }
}

*/
