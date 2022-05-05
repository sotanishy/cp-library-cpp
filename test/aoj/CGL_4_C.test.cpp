#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#define ERROR 0.00001

#include "../../geometry/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<Vec> poly(n);
    for (auto& x : poly) cin >> x;
    int q;
    cin >> q;
    while (q--) {
        Vec p1, p2;
        cin >> p1 >> p2;
        cout << area(convex_cut(poly, Line(p1, p2))) << "\n";
    }
}