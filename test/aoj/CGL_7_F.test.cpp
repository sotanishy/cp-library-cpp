#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F"
#define ERROR 0.00001

#include "../../geometry/geometry.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    Vec p, c;
    T r;
    cin >> p >> c >> r;
    auto [p1, p2] = tangent_points(Circle(c, r), p);
    if (p1.real() > p2.real() || (p1.real() == p2.real() && p1.imag() > p2.imag())) swap(p1, p2);
    cout << p1.real() << " " << p1.imag() << endl;
    cout << p2.real() << " " << p2.imag() << endl;
}
