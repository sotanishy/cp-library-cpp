#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR 0.00000001

#include "../../geometry/geometry.hpp"
#include "../../geometry/dist.hpp"

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
        cout << dist(Segment(p0, p1), Segment(p2, p3)) << "\n";
    }
}