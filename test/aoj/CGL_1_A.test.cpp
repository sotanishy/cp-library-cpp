#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#define ERROR 0.00000001

#include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    Vec p1, p2;
    cin >> p1 >> p2;
    int q;
    cin >> q;
    while (q--) {
        Vec p;
        cin >> p;
        auto q = projection(p1, p2, p);
        cout << q.real() << " " << q.imag() << endl;
    }
}

