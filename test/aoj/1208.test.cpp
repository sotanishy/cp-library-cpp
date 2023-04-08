#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208"

#include "../../math/stern_brocot_tree.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    while (true) {
        int p, n;
        cin >> p >> n;
        if (p == 0 && n == 0) break;
        auto ans = stern_brocot_tree_search(n, [&](ll a, ll b) {
            return a * a < p * b * b;
        });
        auto [u, v] = ans.first;
        auto [x, y] = ans.second;
        cout << x << "/" << y << " " << u << "/" << v << endl;
    }
}
