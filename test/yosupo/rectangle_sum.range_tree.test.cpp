#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <bits/stdc++.h>

#include "../../data-structure/range_tree.hpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<tuple<int, int, ll>> pts;
    for (int i = 0; i < N; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        pts.push_back({x, y, w});
    }
    RangeTree<int, int, ll> rt(pts);
    for (int i = 0; i < Q; ++i) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        cout << rt.fold(l, r, d, u) << "\n";
    }
}