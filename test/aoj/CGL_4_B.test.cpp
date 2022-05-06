#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B"
#define ERROR 0.000001

#include "../../geometry/geometry.hpp"

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
    auto ch = convex_hull(pts);
    int j = 0;
    T ans = 0;
    for (int i = 0; i < n; ++i) {
        j = max(i, j);
        while (lt(abs(ch[i]-ch[j%n]), abs(ch[i]-ch[(j+1)%n]))) ++j;
        ans = max(ans, abs(ch[j%n] - ch[i]));
    }
    cout << ans << endl;
}