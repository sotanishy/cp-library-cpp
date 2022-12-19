#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1283"
#define ERROR 0.00001

#include "../../geometry/geometry.hpp"
#include "../../geometry/polygon.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<Vec> pts(n);
        for (auto& p : pts) cin >> p;

        double lb = 0, ub = 1e9;
        for (int k = 0; k < 100; ++k) {
            double m = (lb + ub) / 2;
            vector<pair<Vec, Vec>> hps;
            for (int i = 0; i < n; ++i) {
                auto d = pts[(i+1)%n] - pts[i];
                auto e = Vec(-d.imag(), d.real());
                auto q = pts[i] + e/abs(e)*m;
                hps.push_back({e, q});
            }
            if (halfplane_intersection(hps).empty()) {
                ub = m;
            } else {
                lb = m;
            }
        }
        cout << lb << "\n";
    }
}

