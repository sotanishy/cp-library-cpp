#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
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
        double x0, y0, x1, y1, x2, y2, x3, y3;
        cin >>  x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Vec p0 = {x0, y0}, p1 = {x1, y1}, p2 = {x2, y2}, p3 = {x3, y3};
        auto q = intersection(p0, p1, p2, p3);
        cout << q.real() << " " << q.imag() << "\n";
    }
}


