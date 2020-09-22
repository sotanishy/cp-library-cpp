#include <bits/stdc++.h>

const double eps = 1e-12;

struct Vec {
    double x, y;
    
    Vec() = default;
    Vec(double x, double y) : x(x), y(y) {}

    Vec operator+(const Vec& other) const { return Vec(x + other.x, y + other.y); }
    Vec operator-(const Vec& other) const { return Vec(x - other.x, y - other.y); }
    Vec operator*(double k) const { return Vec(x * k, y * k); }
    Vec operator/(double k) const { return Vec(x / k, y / k); }

    double abs() const { return std::sqrt(x * x + y * y); }
    double dot(const Vec& other) const { return x * other.x + y * other.y; }
    double cross(const Vec& other) const { return x * other.y - y * other.x; }

    Vec rot(double ang) const {
        double c = std::cos(ang), s = std::sin(ang);
        return Vec(c * x - s * y, s * x + c * y);
    }
};

double dist(const Vec& p, const Vec& q) {
    return (p - q).abs();
}

// checks if the three points are on the same line
bool are_colinear(const Vec& p1, const Vec& p2, const Vec& p3) {
    return abs((p2 - p1).cross(p3 - p1)) < eps;
}

// returns true if the segment ab intersects with the segment cd
bool intersect(const Vec& a, const Vec& b, const Vec& c, const Vec& d) {
    double ta = (c - d).cross(a - c);
    double tb = (c - d).cross(b - a);
    double tc = (a - b).cross(c - a);
    double td = (a - b).cross(d - a);
    return ta * tb < 0 && tc * td < 0;
}

// checks if q is on the segment p1-p2
bool on_segment(const Vec& p1, const Vec& p2, const Vec& q) {
    Vec v1 = p1 - q, v2 = p2 - q;
    return abs(v1.cross(v2)) < eps && v1.dot(v2) < eps;
}

// returns the intersection of the lines p1-p2 and q1-q2
// if the lines are parallel, returns nullptr
Vec* intersection(const Vec& p1, const Vec& p2, const Vec& q1, const Vec& q2) {
    Vec p = p2 - p1;
    Vec q = q2 - q1;
    Vec r = q1 - p1;
    // if parallel
    if (std::abs(q.cross(p)) < eps) return nullptr;
    return &(p1 + p * (q.cross(r) / q.cross(p)));
}

// returns a list of the intersections of two circles
// if they are outside of each other or one contains the other entirely, returns an empty list
std::vector<Vec> intersection_circles(const Vec& c1, double r1, const Vec& c2, double r2) {
    double d = (c1 - c2).abs();
    // if the circles are outside of each other
    if (r1 + r2 < d) return {};
    // if one contains the other entirely
    if (d < std::abs(r2 - r1)) return {};
    double x = (r1*r1 - r2*r2 + d*d) / (2*d);
    double y = std::sqrt(r1*r1 - x*x);
    Vec e1 = (c2 - c1) / (c2 - c1).abs();
    Vec e2 = Vec(-e1.y, e1.x);
    Vec p1 = c1 + e1 * x + e2 * y;
    Vec p2 = c1 + e1 * x - e2 * y;
    return {p1, p2};
}

// returns the distance between the point q and the line p1-p2
double point_line_dist(const Vec& p1, const Vec& p2, const Vec& q) {
    Vec p = p2 - p1;
    return std::abs(q.cross(p) + p2.cross(p1)) / p.abs();
}

double area(const Vec& a, const Vec& b, const Vec& c) {
    return std::abs((b - a).cross(c - a)) / 2;
}

Vec* centroid(const Vec& a, const Vec& b, const Vec& c) {
    if (are_colinear(a, b, c)) return nullptr;
    return &((a + b + c) / 3);
}

Vec* circumcenter(const Vec& A, const Vec& B, const Vec& C) {
    if (are_colinear(A, B, C)) return nullptr;
    double a = dist(B, C);
    double b = dist(C, A);
    double c = dist(A, B);
    double cosA = (b*b + c*c - a*a) / (2*b*c);
    double cosB = (c*c + a*a - b*b) / (2*c*a);
    double cosC = (a*a + b*b - c*c) / (2*a*b);
    return &((A*(a*cosA) + B*(b*cosB) + C*(c*cosC)) / (a*cosA + b*cosB + c*cosC));
}

Vec* incenter(const Vec& A, const Vec& B, const Vec& C) {
    if (are_colinear(A, B, C)) return nullptr;
    double a = dist(B, C);
    double b = dist(C, A);
    double c = dist(A, B);
    return &((A*a + B*b + C*c) / (a + b + c));
}

std::vector<Vec> convex_hull(const std::vector<Vec>& points) {
    int n = points.size();
    std::sort(points.begin(), points.end(), [](const Vec& v1, const Vec& v2) {
        return std::make_pair(v1.x, v1.y) < std::make_pair(v2.x, v2.y);
    });
    int k = 0; // the number of vertices in the convex hull
    std::vector<Vec> ch(2 * n);
    // bottom
    for (int i = 0; i < n; ++i) {
        while (k > 1 && (ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]) < eps) --k;
        ch[k] = points[i];
        ++k;
    }
    int t = k;
    // top
    for (int i = n - 1; i >= 0; --i) {
        while (k > t && (ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]) < eps) --k;
        ch[k] = points[i];
        ++k;
    }
    return std::vector<Vec>(ch.begin(), ch.begin() + (k - 1));
}