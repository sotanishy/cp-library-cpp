#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Vec> points(n);
    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    auto ans = convex_hull(points);
    cout << ans.size() << endl;
    for (auto& p : ans) cout << p.real() << " " << p.imag() << "\n";
}
