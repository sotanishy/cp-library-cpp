#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;
using namespace geometry;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Vec p0, p1;
    cin >> p0 >> p1;
    int q;
    cin >> q;
    while (q--) {
        Vec p2;
        cin >> p2;
        if (p0 == p2 || p1 == p2 || on_segment(p0, p1, p2)) cout << "ON_SEGMENT\n";
        else if (on_segment(p1, p2, p0)) cout << "ONLINE_BACK\n";
        else if (on_segment(p2, p0, p1)) cout << "ONLINE_FRONT\n";
        else if (ccw(p0, p1, p2)) cout << "COUNTER_CLOCKWISE\n";
        else cout << "CLOCKWISE\n";
    }
}

