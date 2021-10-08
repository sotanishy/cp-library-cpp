#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR 0.00000001

#include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int q;
    cin >> q;
    while (q--) {
        Vec p0, p1, p2, p3;
        cin >> p0 >> p1 >> p2 >> p3;
        cout << dist_segments(p0, p1, p2, p3) << "\n";
    }
}