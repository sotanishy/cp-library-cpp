#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

// #include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

constexpr double eps = 1e-12;

inline bool eq(double a, double b) { return std::abs(a - b) < eps; }
inline bool lt(double a, double b) { return a < b - eps; }
inline bool leq(double a, double b) { return a < b + eps; }

struct Vec {
    double x, y;

    Vec() = default;
    Vec(double x, double y) : x(x), y(y) {}

    Vec operator+(const Vec& other) const { return Vec(x + other.x, y + other.y); }
    Vec operator-(const Vec& other) const { return Vec(x - other.x, y - other.y); }
    Vec operator*(double k) const { return Vec(x * k, y * k); }
    Vec operator/(double k) const { return Vec(x / k, y / k); }

    double abs() const { return sqrt(x * x + y * y); }
    double dot(const Vec& other) const { return x * other.x + y * other.y; }
    double cross(const Vec& other) const { return x * other.y - y * other.x; }

    Vec rot(double ang) const {
        double c = cos(ang), s = sin(ang);
        return Vec(c * x - s * y, s * x + c * y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }
};

std::vector<Vec> convex_hull(std::vector<Vec>& points) {
    int n = points.size();
    std::sort(points.begin(), points.end(), [](const Vec& v1, const Vec& v2) {
        return (v1.y != v2.y) ? (v1.y < v2.y) : (v1.x < v2.x);
    });
    int k = 0; // the number of vertices in the convex hull
    std::vector<Vec> ch(2 * n);
    // right
    for (int i = 0; i < n; ++i) {
        while (k > 1 && lt((ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]), 0)) --k;
        ch[k++] = points[i];
    }
    int t = k;
    // left
    for (int i = n - 2; i >= 0; --i) {
        while (k > t && lt((ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]), 0)) --k;
        ch[k++] = points[i];
    }
    ch.resize(k - 1);
    return ch;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Vec> points(n);
    for (auto& p : points) cin >> p.x >> p.y;
    auto ans = convex_hull(points);
    cout << ans.size() << endl;
    for (auto& p : ans) cout << p.x << " " << p.y << "\n";
}
