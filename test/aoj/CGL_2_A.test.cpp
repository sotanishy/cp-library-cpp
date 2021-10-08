#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A"

#include "../../math/geometry.cpp"

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
        auto p = p1 - p0, q = p3 - p2;
        if (eq(cross(p, q), 0)) {
            cout << 2 << "\n";
        } else if (eq(dot(p, q), 0)) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}