#define PROBLEM "https://judge.yosupo.jp/problem/furthest_pair"

#include "../../geometry/furthest_pair.hpp"

#include <bits/stdc++.h>

#include "../../geometry/geometry.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<Vec> pts(N);
        for (auto& p : pts) cin >> p;
        auto [d, i, j] = furthest_pair(pts);
        cout << i << " " << j << "\n";
    }
}