#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"

#include "../../geometry/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

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
        switch (ccw(p0, p1, p2)) {
            case 0:
            if (intersect(Segment(p0, p1), p2)) cout << "intersect\n";
            else if (intersect(Segment(p1, p2), p0)) cout << "ONLINE_BACK\n";
            else if (intersect(Segment(p2, p0), p1)) cout << "ONLINE_FRONT\n";
            break;

            case 1:
            cout << "COUNTER_CLOCKWISE\n";
            break;

            case -1:
            cout << "CLOCKWISE\n";
            break;
        }
    }
}

