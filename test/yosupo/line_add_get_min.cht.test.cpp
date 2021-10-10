#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../../data-structure/cht/dynamic_convex_hull_trick.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    DynamicConvexHullTrick<ll> cht;
    for (int i = 0; i < N; ++i) {
        ll a, b;
        cin >> a >> b;
        cht.add(a, b);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            ll a, b;
            cin >> a >> b;
            cht.add(a, b);
        } else {
            int p;
            cin >> p;
            cout << cht.get(p) << "\n";
        }
    }
}