#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 0.00000001

#include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    Vec c;
    double r;
    cin >> c >> r;
    int q;
    cin >> q;
    while (q--) {
        Vec p1, p2;
        cin >> p1 >> p2;
        auto ans = intersection_circle_line(c, r, p1, p2);
        if (ans.size() == 1) {
            cout << ans[0].real() << " " << ans[0].imag() << " ";
            cout << ans[0].real() << " " << ans[0].imag() << "\n";
        } else {
            if (make_pair(ans[0].real(), ans[0].imag()) > make_pair(ans[1].real(), ans[1].imag())) swap(ans[0], ans[1]);
            cout << ans[0].real() << " " << ans[0].imag() << " ";
            cout << ans[1].real() << " " << ans[1].imag() << "\n";
        }
    }
}
