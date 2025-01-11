#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <bits/stdc++.h>

#include "../../geometry/convex_hull.hpp"
#include "../../geometry/geometry.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Vec> points(n);
    for (auto& p : points) cin >> p;
    auto ans = convex_hull(points, false);
    cout << ans.size() << endl;
    for (auto& p : ans) cout << p.real() << " " << p.imag() << "\n";
}
