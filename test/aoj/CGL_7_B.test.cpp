#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B"
#define ERROR 0.000001

#include "../../geometry/geometry.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);


    Vec p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    auto c = incenter(p1, p2, p3);
    cout << c.real() << " " << c.imag() << " " << dist(Segment(p1, p2), c) << endl;
}