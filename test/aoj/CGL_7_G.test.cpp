#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G"
#define ERROR 0.00001

#include "../../geometry/geometry.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    Vec c1, c2;
    T r1, r2;
    cin >> c1 >> r1 >> c2 >> r2;
    auto ls = common_tangents(Circle(c1, r1), Circle(c2, r2));
    vector<Vec> ps;
    for (auto& l : common_tangents(Circle(c1, r1), Circle(c2, r2))) {
        ps.push_back(l.p1);
    }
    sort(ps.begin(), ps.end(), [&](auto& p, auto& q) {
        if (eq(p.real(), q.real())) return lt(p.imag(), q.imag());
        return lt(p.real(), q.real());
    });
    for (auto& p : ps) {
        cout << p.real() << " " << p.imag() << endl;
    }
}
