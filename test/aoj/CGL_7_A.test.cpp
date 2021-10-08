#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

// #include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

using T = double;
using Vec = std::complex<T>;

constexpr T eps = 1e-12;
inline bool eq(T a, T b) { return std::abs(a - b) < eps; }
inline bool lt(T a, T b) { return a < b - eps; }
inline bool leq(T a, T b) { return a < b + eps; }

std::istream& operator>>(std::istream& is, Vec& p) {
    T x, y;
    is >> x >> y;
    p = {x, y};
    return is;
}

T dot(const Vec& a, const Vec& b) {
    return (std::conj(a) * b).real();
}

T cross(const Vec& a, const Vec& b) {
    return (std::conj(a) * b).imag();
}

int ccw(const Vec& a, const Vec& b, const Vec& c) {
    if (eq(cross(b - a, c - a), 0)) return 0;  // collinear
    if (lt(cross(b - a, c - a), 0)) return -1;  // clockwise
    return 1;  // counter clockwise
}

std::vector<Vec> intersection_circles(const Vec& c1, T r1, const Vec& c2, T r2) {
    T d = std::abs(c1 - c2);
    // if the circles are outside of each other
    if (lt(r1 + r2, d)) return {};
    // if one contains the other entirely
    if (lt(d, std::abs(r2 - r1))) return {};
    T x = (r1*r1 - r2*r2 + d*d) / (2*d);
    T y = std::sqrt(r1*r1 - x*x);
    Vec e1 = (c2 - c1) / std::abs(c2 - c1);
    Vec e2 = Vec(-e1.imag(), e1.real());
    return {c1 + x*e1 + y*e2, c1 + x*e1 - y*e2};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<Vec> pts(n);
    for (auto& x : pts) cin >> x;
    int q;
    cin >> q;
    while (q--) {
        Vec p;
        cin >> p;
        cout << contains(pts, p) << "\n";
    }
}

