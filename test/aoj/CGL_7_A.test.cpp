#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A"

#include "../../geometry/geometry.hpp"
#include "../../geometry/intersect.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);


    Vec c1, c2;
    T r1, r2;
    cin >> c1 >> r1 >> c2 >> r2;
    cout << intersect(Circle(c1, r1), Circle(c2, r2)) << endl;
}