#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1298"

#include "../../geometry/geometry.hpp"
#include "../../geometry/convex_hull.hpp"
#include "../../geometry/intersect.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<Vec> black(n), white(m);
        for (auto& p : black) cin >> p;
        for (auto& p : white) cin >> p;
        black = convex_hull(black);
        white = convex_hull(white);
        cout << (intersect(black, white) ? "NO" : "YES") << "\n";
    }
}