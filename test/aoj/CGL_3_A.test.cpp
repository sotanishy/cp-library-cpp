#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"

#include "../../geometry/geometry.hpp"
#include "../../geometry/polygon.hpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    int n;
    cin >> n;
    vector<Vec> pts(n);
    for (auto& x : pts) cin >> x;
    cout << area(pts) << endl;
}