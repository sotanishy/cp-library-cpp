#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#define ERROR 0.00000001

#include "../../geometry/geometry.cpp"

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
        auto q = intersection(Line(p0, p1), Line(p2, p3));
        cout << q.real() << " " << q.imag() << "\n";
    }
}