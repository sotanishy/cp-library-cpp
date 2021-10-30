#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"

#include "../../geometry/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        Vec p0, p1, p2, p3;
        cin >> p0 >> p1 >> p2 >> p3;
        cout << intersect_segments(p0, p1, p2, p3) << "\n";
    }
}