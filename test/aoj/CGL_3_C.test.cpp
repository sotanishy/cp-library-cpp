#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"

#include "../../geometry/geometry.hpp"
#include "../../geometry/intersect.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;
    vector<Vec> pts(n);
    for (auto& x : pts) cin >> x;
    int q;
    cin >> q;
    while (q--) {
        Vec p;
        cin >> p;
        cout << intersect(pts, p) << "\n";
    }
}
