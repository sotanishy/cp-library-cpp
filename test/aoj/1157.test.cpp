#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1157"
#define ERROR 0.001

#include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        Vec s(sx, sy), e(ex, ey);
        double ans = 1e9;
        for (int i = 0; i < N; ++i)  {
            int x1, y1, x2, y2;
            double h;
            cin >> x1 >> y1 >> x2 >> y2 >> h;
            vector<Vec> pts = {
                Vec(x1, y1),
                Vec(x1, y2),
                Vec(x2, y2),
                Vec(x2, y1),
            };
            for (int j = 0; j < 4; ++j) {
                if (intersect(s, e, pts[j], pts[(j + 1) % 4])) {
                    ans = 0;
                    break;
                }
            }
            if (x1 < min(s.real(), e.real()) && max(s.real(), e.real()) < x2 && y1 < min(s.imag(), e.imag()) && max(s.imag(), e.imag()) < y2) {
                ans = 0;
            }
            for (auto& p : {s, e}) {
                if (x1 < p.real() && p.real() < x2) {
                    pts.push_back(Vec(p.real(), y1));
                    pts.push_back(Vec(p.real(), y2));
                }
                if (y1 < p.imag() && p.imag() < y2) {
                    pts.push_back(Vec(x1, p.imag()));
                    pts.push_back(Vec(x2, p.imag()));
                }
            }
            for (auto& p : pts) {
                double d = point_line_dist(s, e, p);
                if (lt(dot(e - s, p - s), 0)) {
                    d = std::abs(p - s);
                }
                if (lt(dot(s - e, p - e), 0)) {
                    d = std::abs(p - e);
                }
                if (h > d) {
                    ans = min(ans, d);
                } else {
                    ans = min(ans, (h*h + d*d) / (2*h));
                }
            }
        }
        cout << ans << "\n";
    }
}
