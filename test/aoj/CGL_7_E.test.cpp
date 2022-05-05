#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR 0.00000001

#include "../../geometry/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    Vec p1, p2;
    double r1, r2;
    cin >> p1 >> r1;
    cin >> p2 >> r2;
    auto ans = intersection(Circle(p1, r1), Circle(p2, r2));
    if (ans.size() == 1) {
        cout << ans[0].real() << " " << ans[0].imag() << " ";
        cout << ans[0].real() << " " << ans[0].imag() << "\n";
    } else {
        if (make_pair(ans[0].real(), ans[0].imag()) > make_pair(ans[1].real(), ans[1].real())) swap(ans[0], ans[1]);
        cout << ans[0].real() << " " << ans[0].imag() << " ";
        cout << ans[1].real() << " " << ans[1].imag() << "\n";
    }
}