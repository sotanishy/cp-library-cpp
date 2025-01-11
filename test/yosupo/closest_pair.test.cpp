#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"

#include "../../geometry/closest_pair.hpp"

#include <bits/stdc++.h>

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
        auto [d, i, j] = closest_pair(pts);
        cout << i << " " << j << "\n";
    }
}
