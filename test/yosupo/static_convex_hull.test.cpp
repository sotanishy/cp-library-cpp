#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include <bits/stdc++.h>

#include "../../geometry/convex_hull.hpp"
#include "../../geometry/geometry.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Vec> pts(N);
        for (auto& p : pts) cin >> p;
        auto conv = convex_hull(pts);
        cout << conv.size() << "\n";
        for (auto& p : conv)
            cout << (int)p.real() << " " << (int)p.imag() << "\n";
    }
}