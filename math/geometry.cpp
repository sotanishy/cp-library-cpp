#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-12;

struct Vec {
    double x, y;

    Vec(double x, double y) : x(x), y(y) {}

    Vec operator+(const Vec& other) { return Vec(x + other.x, y + other.y); }

    Vec operator-(const Vec& other) { return Vec(x - other.x, y - other.y); }

    Vec operator*(double k) { return Vec(x * k, y * k); }

    Vec operator/(double k) { return Vec(x / k, y / k); }

    double abs() {
        return sqrt(x * x + y * y);
    }

    double dot(const Vec& other) {
        return x * other.x + y * other.y;
    }

    double cross(const Vec& other) {
        return x * other.y - y * other.x;
    }

    Vec rot(double ang) {
        double c = cos(ang), s = sin(ang);
        return Vec(c * x - s * y, s * x + c * y);
    }
};

double dist(Vec& p, Vec& q) {
    return (p - q).abs();
}

// checks if the three points are on the same line
bool are_colinear(Vec& p1, Vec& p2, Vec& p3) {
    return abs((p2 - p1).cross(p3 - p1)) < eps;
}

// returns true if the segment ab intersects with the segment cd
bool intersect(Vec& a, Vec& b, Vec& c, Vec& d) {
    double ta = (c - d).cross(a - c);
    double tb = (c - d).cross(b - a);
    double tc = (a - b).cross(c - a);
    double td = (a - b).cross(d - a);
    return ta * tb < 0 && tc * td < 0;
}

// checks if q is on the segment p1-p2
bool on_segment(Vec& p1, Vec& p2, Vec& q) {
    Vec v1 = p1 - q;
    Vec v2 = p2 - q;
    return abs(v1.cross(v2)) < eps && v1.dot(v2) < eps;
}

// returns the intersection of the lines p1-p2 and q1-q2
// if the lines are parallel, returns nullptr
Vec* intersection(Vec& p1, Vec& p2, Vec& q1, Vec& q2) {
    Vec p = p2 - p1;
    Vec q = q2 - q1;
    Vec r = q1 - p1;
    // if parallel
    if (abs(q.cross(p)) < eps) return nullptr;
    return &(p1 + p * (q.cross(r) / q.cross(p)));
}

// returns a list of the intersections of two circles
// if they are outside of each other or one contains the other entirely, returns an empty list
vector<Vec> itnersection_circles(Vec& c1, double r1, Vec& c2, double r2) {
    double d = (c1 - c2).abs();

    // if the circles are outside of each other
    if (r1 + r2 < d) return {};

    // if one contains the other entirely
    if (d < abs(r2 - r1)) return {};

    double x = (r1*r1 - r2*r2 + d*d) / (2*d);
    double y = sqrt(r1*r1 - x*x);
    Vec e1 = (c2 - c1) / (c2 - c1).abs();
    Vec e2 = Vec(-e1.y, e1.x);
    Vec p1 = c1 + e1 * x + e2 * y;
    Vec p2 = c1 + e1 * x - e2 * y;
    return {p1, p2};
}

// returns the distance between the point q and the line p1-p2
double point_line_dist(Vec& p1, Vec& p2, Vec& q) {
    Vec p = p2 - p1;
    return abs(q.cross(p) + p2.cross(p1)) / p.abs();
}

double area(Vec& a, Vec& b, Vec& c) {
    Vec ab = b - a;
    Vec ac = c - a;
    return abs(ab.cross(ac)) / 2;
}

Vec* centroid(Vec& a, Vec& b, Vec& c) {
    if (are_colinear(a, b, c)) return nullptr;
    return &((a + b + c) / 3);
}

Vec* circumcenter(Vec& A, Vec& B, Vec& C) {
    if (are_colinear(A, B, C)) return nullptr;
    double a = dist(B, C);
    double b = dist(C, A);
    double c = dist(A, B);
    double cosA = (b*b + c*c - a*a) / (2*b*c);
    double cosB = (c*c + a*a - b*b) / (2*c*a);
    double cosC = (a*a + b*b - c*c) / (2*a*b);
    return &((A*(a*cosA) + B*(b*cosB) + C*(c*cosC)) / (a*cosA + b*cosB + c*cosC));
}

Vec* incenter(Vec& A, Vec& B, Vec& C) {
    if (are_colinear(A, B, C)) return nullptr;
    double a = dist(B, C);
    double b = dist(C, A);
    double c = dist(A, B);
    return &((A*a + B*b + C*c) / (a+b+c));
}

vector<Vec> convex_hull(vector<Vec>& points) {
    int n = points.size();
    sort(points.begin(), points.end(), [](const Vec& v1, const Vec& v2) {
        return make_pair(v1.x, v1.y) < make_pair(v2.x, v2.y);
    });
    int k = 0; // the number of vertices in the convex hull
    vector<Vec> ch(2*n);
    // bottom
    for (int i = 0; i < n; i++) {
        while (k > 1 && (ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]) < eps) k--;
        ch[k] = points[i];
        k++;
    }
    int t = k;
    // top
    for (int i = n - 1; i >= 0; i--) {
        while (k > t && (ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]) < eps) k--;
        ch[k] = points[i];
        k++;
    }
    return vector<Vec>(ch.begin(), ch.begin() + (k-1));
}