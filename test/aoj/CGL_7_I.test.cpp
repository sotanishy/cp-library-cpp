#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_H"
#define ERROR 0.000001

#include "../../geometry/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    Vec c1, c2;
    T r1, r2;
    cin >> c1 >> r1 >> c2 >> r2;
    cout << area_intersection(Circle(c1, r1), Circle(c2, r2)) << endl;
}
